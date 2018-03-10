#include "../../Header/DebugUtil/Log.h"
#include "../../Header/Common/Primitive/String.h"
#include <iostream>
using namespace essence::debug;
using namespace essence::primitive;
/**
* プリミティブ型を引数とするデバッグ出力
*/
void CLog::Out(essence::primitive::IPrimitive* arg, EDestination outDestination) {
	if (arg == nullptr)
	{
		/// TODO: デバッグ時は警告やら、エラーなどを出力する
		return;
	}

	switch (arg->Type())
	{
	case primitive::EType::String:
		std::cout << static_cast<CString*>(arg)->Value() << std::endl;
		break;

	default:
		break;
	}
}

/**
* オブジェクト型を引数とするデバッグ出力
*/
void CLog::Out(essence::base::IObject* object, EDestination outDestination) {
	/// TODO : 実装
}