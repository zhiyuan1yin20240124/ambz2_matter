#include "matter_ota.h"
#include "app/clusters/ota-requestor/DefaultOTARequestorStorage.h"
#include <app/clusters/ota-requestor/BDXDownloader.h>
#include <app/clusters/ota-requestor/DefaultOTARequestor.h>
#include <app/clusters/ota-requestor/DefaultOTARequestorDriver.h>
#include <platform/Ameba/AmebaOTAImageProcessor.h>

using namespace chip;
using namespace chip::DeviceLayer;

namespace {
DefaultOTARequestor gRequestorCore;
DefaultOTARequestorStorage gRequestorStorage;
DefaultOTARequestorDriver gRequestorUser;
BDXDownloader gDownloader;
AmebaOTAImageProcessor gImageProcessor;
} // namespace

extern "C" void amebaQueryImageCmdHandler()
{
    ChipLogProgress(DeviceLayer, "Calling amebaQueryImageCmdHandler");
    PlatformMgr().ScheduleWork([](intptr_t) { GetRequestorInstance()->TriggerImmediateQuery(); });
}

extern "C" void amebaApplyUpdateCmdHandler()
{
    ChipLogProgress(DeviceLayer, "Calling amebaApplyUpdateCmdHandler");
    PlatformMgr().ScheduleWork([](intptr_t) { GetRequestorInstance()->ApplyUpdate(); });
}

void matter_ota_init()
{
    SetRequestorInstance(&gRequestorCore);
    gRequestorStorage.Init(chip::Server::GetInstance().GetPersistentStorage());
    // Set server instance used for session establishment
    gRequestorCore.Init(chip::Server::GetInstance(), gRequestorStorage, gRequestorUser, gDownloader);
    gImageProcessor.SetOTADownloader(&gDownloader);
    // Connect the Downloader and Image Processor objects
    gDownloader.SetImageProcessorDelegate(&gImageProcessor);
    gRequestorUser.Init(&gRequestorCore, &gImageProcessor);
}
