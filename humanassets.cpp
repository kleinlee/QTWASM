#include "humanassets.h"

HumanAssets* HumanAssets::instance_ = NULL;
HumanAssets::HumanAssets()
{
//    instance = NULL;
}

void HumanAssets::setUserImage(QByteArray& dataArray)
{
    m_user_img = QImage::fromData(dataArray);
    emit userImageChanged();
}
