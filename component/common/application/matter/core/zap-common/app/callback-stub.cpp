/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// THIS FILE IS GENERATED BY ZAP

#include <app-common/zap-generated/callback.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <lib/support/Span.h>
#include <protocols/interaction_model/Constants.h>

using namespace chip;

// Cluster Init Functions
void emberAfClusterInitCallback(EndpointId endpoint, ClusterId clusterId)
{
  // To prevent warning
  (void)endpoint;
  (void)clusterId;
}

void __attribute__((weak)) emberAfAddToCurrentAppTasksCallback(EmberAfApplicationTask tasks) {}

void __attribute__((weak)) emberAfRemoveFromCurrentAppTasksCallback(EmberAfApplicationTask tasks) {}

EmberAfAttributeWritePermission __attribute__((weak))
emberAfAllowNetworkWriteAttributeCallback(EndpointId endpoint, ClusterId clusterId, AttributeId attributeId,uint8_t * value, 
                                                        uint8_t type)
{
    return EMBER_ZCL_ATTRIBUTE_WRITE_PERMISSION_ALLOW_WRITE_NORMAL; // Default
}

bool __attribute__((weak)) emberAfAttributeReadAccessCallback(EndpointId endpoint, ClusterId clusterId, AttributeId attributeId)
{
    return true;
}

bool __attribute__((weak)) emberAfAttributeWriteAccessCallback(EndpointId endpoint, ClusterId clusterId, AttributeId attributeId)
{
    return true;
}

bool __attribute__((weak)) emberAfDefaultResponseCallback(ClusterId clusterId, CommandId commandId, EmberAfStatus status)
{
    return false;
}

bool __attribute__((weak)) emberAfPreMessageSendCallback(EmberAfMessageStruct * messageStruct, EmberStatus * status)
{
    return false;
}

bool __attribute__((weak)) emberAfMessageSentCallback(const MessageSendDestination & destination, EmberApsFrame * apsFrame,
                                                      uint16_t msgLen, uint8_t * message, EmberStatus status)
{
    return false;
}

uint32_t __attribute__((weak)) emberAfGetCurrentTimeCallback()
{
    return 0;
}

bool __attribute__((weak))
emberAfGetEndpointInfoCallback(EndpointId endpoint, uint8_t * returnNetworkIndex, EmberAfEndpointInfoStruct * returnEndpointInfo)
{
    return false;
}

void __attribute__((weak)) emberAfRegistrationAbortCallback() {}

EmberStatus __attribute__((weak))
emberAfInterpanSendMessageCallback(EmberAfInterpanHeader * header, uint16_t messageLength, uint8_t * message)
{
    return EMBER_LIBRARY_NOT_PRESENT;
}

bool __attribute__((weak)) emberAfStartMoveCallback()
{
    return false;
}
