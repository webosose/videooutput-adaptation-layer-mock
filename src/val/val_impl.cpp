// Copyright (c) 2017-2019 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include <fstream>
#include <iostream>
#include <sstream>

#include "val_impl.h"
#include "val_settings_impl.h"
#include "val_video_impl.h"

#include "logging.h"

static const char *const logContextName = "val-mock";
static const char *const logPrefix      = "[val-mock]";
PmLogContext valLogContext;

VAL *VAL::_instance = nullptr;

VAL *VAL::getInstance()
{
    if (!_instance)
        _instance = new val_impl();

    return _instance;
}

bool val_impl::initialize()
{

    // Setup logging context
    PmLogErr error = PmLogGetContext(logContextName, &valLogContext);
    if (error != kPmLogErr_None) {
        std::cerr << logPrefix << "Failed to setup up log context " << logContextName << std::endl;
    }

    video    = new val_video_impl();
    controls = new VAL_ControlSettings_Impl();

    return true;
}

bool val_impl::deinitialize()
{
    delete video;
    delete controls;
    return true;
}
