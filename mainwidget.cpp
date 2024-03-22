#include "mainwidget.h"


#include <QDebug>
#include <QVariant>
#include <QImage>


#ifdef Q_OS_WASM
#include <emscripten.h>
#include <emscripten/html5.h>


// 这个EM_JS是用来声明js函数的，声明之后就可以直接在c++里面调用了。
// 而且不仅可以在c++用，也可以在网页js里面用
// 而 EMSCRIPTEN_KEEPALIVE 声明的函数则可以在网页里面通过 Module.ccall来调用

extern "C"{
char * malloc_array = nullptr;
EMSCRIPTEN_KEEPALIVE
    char* mallocArray(size_t dataSize)
{
    qDebug() << "mallocArray" << dataSize;
    malloc_array = new char[dataSize];
    return malloc_array;
}

EMSCRIPTEN_KEEPALIVE
    void processFile(const char *data, size_t dataSize)
{
    qDebug() << "processFile";
    QByteArray dataArray(data, dataSize);
    HumanAssets* human_assets = HumanAssets::GetInstance();
    human_assets->setUserImage(dataArray);
    qDebug() << "dataArray Size: " << dataArray.size();
    delete[] malloc_array;
    malloc_array = nullptr;
}
}

#endif

MainWidget::MainWidget(QWidget *parent)
{
    m_human_assets = HumanAssets::GetInstance();
    connect(this->m_human_assets, SIGNAL(userImageChanged()), SLOT(setUserImage()));
    m_layout = new QVBoxLayout;
    m_label = new QLabel;
    m_layout->addWidget(m_label);
    setLayout(m_layout);
}
MainWidget::~MainWidget()
{

}
void MainWidget::setUserImage()
{
    m_label->setPixmap(QPixmap::fromImage(m_human_assets->m_user_img));
}
