#pragma once

#include "../MaaDef.h"
#include "../MaaPort.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* SyncContext */

    MaaBool MAA_FRAMEWORK_API MaaSyncContextRunTask(MaaSyncContextHandle sync_context, MaaStringView task,
                                                    MaaStringView param);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextRunRecognizer(MaaSyncContextHandle sync_context, MaaImageBufferHandle image,
                                                          MaaStringView task, MaaStringView task_param,
                                                          /* out */ MaaRectHandle out_box,
                                                          /* out */ MaaStringBufferHandle detail_buff);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextRunAction(MaaSyncContextHandle sync_context, MaaStringView task,
                                                      MaaStringView task_param, MaaRectHandle cur_box,
                                                      MaaStringView cur_rec_detail);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextClick(MaaSyncContextHandle sync_context, int32_t x, int32_t y);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextSwipe(MaaSyncContextHandle sync_context, int32_t x1, int32_t y1, int32_t x2,
                                                  int32_t y2, int32_t duration);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextPressKey(MaaSyncContextHandle sync_context, int32_t keycode);

    MaaBool MAA_FRAMEWORK_API MaaSyncContextTouchDown(MaaSyncContextHandle sync_context, int32_t contact, int32_t x,
                                                      int32_t y, int32_t pressure);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextTouchMove(MaaSyncContextHandle sync_context, int32_t contact, int32_t x,
                                                      int32_t y, int32_t pressure);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextTouchUp(MaaSyncContextHandle sync_context, int32_t contact);

    MaaBool MAA_FRAMEWORK_API MaaSyncContextScreencap(MaaSyncContextHandle sync_context,
                                                      /* out */ MaaImageBufferHandle buffer);
    MaaBool MAA_FRAMEWORK_API MaaSyncContextGetTaskResult(MaaSyncContextHandle sync_context, MaaStringView task,
                                                          /* out */ MaaStringBufferHandle buffer);

#ifdef __cplusplus
}
#endif
