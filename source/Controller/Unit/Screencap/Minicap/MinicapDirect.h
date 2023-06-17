#pragma once

#include "MinicapBase.h"

MAA_CTRL_UNIT_NS_BEGIN

class MinicapDirect : public MinicapBase
{
public:
    std::optional<cv::Mat> screencap();
};

MAA_CTRL_UNIT_NS_END