/*
 * Copyright (c) 2018-2019, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PicoGamepad_H
#define PicoGamepad_H

#include "PluggableUSBHID.h"
#include "platform/Stream.h"
#include "PlatformMutex.h"

// values addresses
#define BTN0_7 0
#define X_AXIS_LSB 1
#define X_AXIS_MSB 2
#define Y_AXIS_LSB 3
#define Y_AXIS_MSB 4

namespace arduino
{
    class PicoGamepad : public USBHID
    {
    public:
        virtual ~PicoGamepad();

        bool send_inputs(uint8_t *values);

        void SetButton(int idx, bool val);
        void SetX(uint16_t val);
        void SetY(uint16_t val);

        bool send_update();

        virtual const uint8_t *report_desc();

    protected:
        virtual const uint8_t *configuration_desc(uint8_t index);

    private:
        uint8_t inputArray[35];

        uint8_t _configuration_descriptor[41];
        PlatformMutex _mutex;
    };
}

#endif
