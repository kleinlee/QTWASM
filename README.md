"# QTWASM" 
使用QT webassembly 单线程版本，和网页原生html间的交互。
wasm存在一个限制因素：无法直接访问本机资源如图片等，因此常使用html加载本地图片并传输给wasm使用。
几个tips：
1、QT wasm编译后会出现QTWASM.js文件，里面的Module时wasm的接口。要把odule改为全局变量，以供外部JS调用。具体可以比较编译的QTWASM.js和此项目中的QTWASM.js的区别。
2、Qt中使用EMSCRIPTEN_KEEPALIVE，可以把函数接口暴露给JS以供调用。调用方式为Module._function（function改为具体函数）
1、Module._mallocArray