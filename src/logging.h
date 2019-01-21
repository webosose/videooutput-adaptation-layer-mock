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

#ifndef LOGGING_H
#define LOGGING_H

#include <exception>
#include <string>

#include <PmLogLib.h>

extern PmLogContext valLogContext;
#define LOG_CRITICAL(msgid, kvcount, ...) PmLogCritical(valLogContext, msgid, kvcount, ##__VA_ARGS__)

#define LOG_ERROR(msgid, kvcount, ...) PmLogError(valLogContext, msgid, kvcount, ##__VA_ARGS__)

#define LOG_WARNING(msgid, kvcount, ...) PmLogWarning(valLogContext, msgid, kvcount, ##__VA_ARGS__)

#define LOG_INFO(msgid, kvcount, ...) PmLogInfo(valLogContext, msgid, kvcount, ##__VA_ARGS__)

#define LOG_DEBUG(fmt, ...) PmLogDebug(valLogContext, "%s:%s() " fmt, __FILE__, __FUNCTION__, ##__VA_ARGS__)

#define LOG_ESCAPED_ERRMSG(msgid, errmsg)                           \
    do {                                                            \
        gchar *escaped_errtext = g_strescape(errmsg, NULL);         \
        LOG_ERROR(msgid, 1, PMLOGKS("Error", escaped_errtext), ""); \
        g_free(escaped_errtext);                                    \
    } while (0)

class FatalException : public std::exception
{
public:
    FatalException(const char *file, int line, const char *format, ...) {}
    const char *what() const noexcept override;

private:
    std::string mMessage;
};

#define THROW_FATAL_EXCEPTION(...) throw FatalException(__FILE__, __LINE__, __VA_ARGS__)

#endif // LOGGING_H
