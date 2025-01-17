#include "MaaFramework/Task/MaaSyncContext.h"

#include "Buffer/ImageBuffer.hpp"
#include "Buffer/StringBuffer.hpp"
#include "Utils/Logger.h"

MaaBool MaaSyncContextRunTask(MaaSyncContextHandle sync_context, MaaStringView task, MaaStringView param)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(task) << VAR(param);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    return sync_context->run_task(task, param);
}

MaaBool MaaSyncContextRunRecognizer(MaaSyncContextHandle sync_context, MaaImageBufferHandle image, MaaStringView task,
                                    MaaStringView task_param, MaaRectHandle out_box, MaaStringBufferHandle detail_buff)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(image) << VAR(task) << VAR(task_param) << VAR(out_box)
            << VAR(detail_buff);

    if (!sync_context || !image) {
        LogError << "handle is null";
        return false;
    }

    cv::Rect cvbox {};
    std::string detail;

    bool ret = sync_context->run_recognizer(image->get(), task, task_param, cvbox, detail);

    if (out_box) {
        out_box->x = cvbox.x;
        out_box->y = cvbox.y;
        out_box->width = cvbox.width;
        out_box->height = cvbox.height;
    }
    if (detail_buff) {
        detail_buff->set(std::move(detail));
    }

    return ret;
}

MaaBool MaaSyncContextRunAction(MaaSyncContextHandle sync_context, MaaStringView task, MaaStringView task_param,
                                MaaRectHandle cur_box, MaaStringView cur_rec_detail)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(task) << VAR(task_param) << VAR(cur_box) << VAR(cur_rec_detail);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    cv::Rect cvbox {};
    if (cur_box) {
        cvbox.x = cur_box->x;
        cvbox.y = cur_box->y;
        cvbox.width = cur_box->width;
        cvbox.height = cur_box->height;
    }

    bool ret = sync_context->run_action(task, task_param, cvbox, cur_rec_detail);
    return ret;
}

MaaBool MaaSyncContextClick(MaaSyncContextHandle sync_context, int32_t x, int32_t y)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(x) << VAR(y);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    return sync_context->click(x, y);
}

MaaBool MaaSyncContextSwipe(MaaSyncContextHandle sync_context, int32_t x1, int32_t y1, int32_t x2, int32_t y2,
                            int32_t duration)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(x1) << VAR(y1) << VAR(x2) << VAR(y2) << VAR(duration);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    return sync_context->swipe(x1, y1, x2, y2, duration);
}

MaaBool MaaSyncContextPressKey(MaaSyncContextHandle sync_context, int32_t keycode)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(keycode);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    return sync_context->press_key(keycode);
}

MaaBool MaaSyncContextTouchDown(MaaSyncContextHandle sync_context, int32_t contact, int32_t x, int32_t y,
                                int32_t pressure)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(contact) << VAR(x) << VAR(y) << VAR(pressure);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    return sync_context->touch_down(contact, x, y, pressure);
}

MaaBool MaaSyncContextTouchMove(MaaSyncContextHandle sync_context, int32_t contact, int32_t x, int32_t y,
                                int32_t pressure)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(contact) << VAR(x) << VAR(y) << VAR(pressure);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    return sync_context->touch_move(contact, x, y, pressure);
}

MaaBool MaaSyncContextTouchUp(MaaSyncContextHandle sync_context, int32_t contact)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(contact);

    if (!sync_context) {
        LogError << "handle is null";
        return false;
    }

    return sync_context->touch_up(contact);
}

MaaBool MaaSyncContextScreencap(MaaSyncContextHandle sync_context, MaaImageBufferHandle buffer)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(buffer);

    if (!sync_context || !buffer) {
        LogError << "handle is null";
        return false;
    }

    auto img = sync_context->screencap();
    if (img.empty()) {
        LogError << "image is empty";
        return false;
    }

    buffer->set(std::move(img));
    return true;
}

MaaBool MaaSyncContextGetTaskResult(MaaSyncContextHandle sync_context, MaaStringView task, MaaStringBufferHandle buffer)
{
    LogFunc << VAR_VOIDP(sync_context) << VAR(task) << VAR(buffer);

    if (!sync_context || !buffer) {
        LogError << "handle is null";
        return false;
    }

    auto res = sync_context->task_result(task);
    if (res.empty()) {
        LogError << "res is empty";
        return false;
    }

    buffer->set(std::move(res));
    return true;
}
