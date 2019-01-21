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

#pragma once

#include <pbnjson/cxx/JValue.h>
#include <val_api.h>

class val_video_impl : public VAL_Video
{
public:
    val_video_impl();
    ~val_video_impl() {}

    bool connect(VAL_VIDEO_WID_T wId, VAL_VSC_INPUT_SRC_INFO_T vscInput, VAL_VSC_OUTPUT_MODE_T outputmode,
                 unsigned int *planeId);
    bool disconnect(VAL_VIDEO_WID_T wId);
    bool applyScaling(VAL_VIDEO_WID_T wId, VAL_VIDEO_RECT_T srcInfo, bool adaptive, VAL_VIDEO_RECT_T inputRegion,
                      VAL_VIDEO_RECT_T outputRegion);
    bool setDualVideo(bool enable);
    bool setCompositionParams(std::vector<VAL_WINDOW_INFO_T> zOrder);
    bool setWindowBlanking(VAL_VIDEO_WID_T wId, bool blank, VAL_VIDEO_RECT_T inputRegion,
                           VAL_VIDEO_RECT_T outputRegion);

    bool setDisplayResolution(VAL_VIDEO_SIZE_T, uint8_t);
    std::vector<VAL_VIDEO_SIZE_T> getSupportedResolutions(uint8_t dispIndex = 0);
    VAL_VIDEO_RECT_T getDisplayResolution();
    bool getDeviceCapabilities(VAL_VIDEO_SIZE_T &minDownscaleSize, VAL_VIDEO_SIZE_T &maxUpscaleSize);
    std::vector<VAL_PLANE_T> getVideoPlanes();
    bool setParam(std::string control, pbnjson::JValue param);
    pbnjson::JValue getParam(std::string control, pbnjson::JValue param);
};
