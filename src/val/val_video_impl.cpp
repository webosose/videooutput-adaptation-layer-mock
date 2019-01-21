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

#include <string>

#include "val_video_impl.h"

using namespace pbnjson;

VAL_VIDEO_RECT_T val_video_impl::getDisplayResolution() { return VAL_VIDEO_RECT_T{0, 0, 0, 0}; }

val_video_impl::val_video_impl() {}

bool val_video_impl::getDeviceCapabilities(VAL_VIDEO_SIZE_T &minDownscaleSize, VAL_VIDEO_SIZE_T &maxUpscaleSize)
{
    return true;
}

bool val_video_impl::connect(VAL_VIDEO_WID_T wId, VAL_VSC_INPUT_SRC_INFO_T vscInput, VAL_VSC_OUTPUT_MODE_T outputmode,
                             unsigned int *planeId)
{
    return true;
}

bool val_video_impl::disconnect(VAL_VIDEO_WID_T wId) { return true; }

bool val_video_impl::applyScaling(VAL_VIDEO_WID_T wId, VAL_VIDEO_RECT_T srcInfo, bool adaptive,
                                  VAL_VIDEO_RECT_T inputRegion, VAL_VIDEO_RECT_T outputRegion)
{
    return true;
}

bool val_video_impl::setDualVideo(bool enable) { return true; }

bool val_video_impl::setCompositionParams(std::vector<VAL_WINDOW_INFO_T> zOrder) { return true; }

bool val_video_impl::setWindowBlanking(VAL_VIDEO_WID_T wId, bool blank, VAL_VIDEO_RECT_T inputRegion,
                                       VAL_VIDEO_RECT_T outputRegion)
{
    return true;
}

bool val_video_impl::setDisplayResolution(VAL_VIDEO_SIZE_T win, uint8_t display_path) { return true; }
std::vector<VAL_PLANE_T> val_video_impl::getVideoPlanes() { return std::vector<VAL_PLANE_T>(); }
std::vector<VAL_VIDEO_SIZE_T> val_video_impl::getSupportedResolutions(uint8_t dispIndex) { return std::vector<VAL_VIDEO_SIZE_T>(); }

bool val_video_impl::setParam(std::string control, pbnjson::JValue param) { return true; }

pbnjson::JValue val_video_impl::getParam(std::string control, pbnjson::JValue param) { return JValue(); }
