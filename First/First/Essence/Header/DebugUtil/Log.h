#ifndef ESSENCE_DEBUGUTILITY_LOG_H
#define ESSENCE_DEBUGUTILITY_LOG_H
#include "../Common/Primitive/Base/IPrimitive.h"
#include "../Common/Base/IObject.h"
namespace essence{ namespace debug {

class CLog {
public:
	CLog() = delete;
	CLog(const CLog&) = delete;
	CLog(CLog&&) = delete;
	~CLog() = default;

public:
	/**
	* ログの出力先
	*/
	enum class EDestination
	{
		Console,
		Screen,
		All
	};

public:
	/**
	* プリミティブ型を引数とするデバッグ出力
	* param[in] 出力するプリミティブ型
	* param[in] 出力先タイプ
	*/
	static void Out(essence::primitive::IPrimitive*, EDestination);

	/**
	* オブジェクト型を引数とするデバッグ出力
	* param[in] 出力するオブジェクト型
	* param[in] 出力先タイプ
	*/
	static void Out(essence::base::IObject*, EDestination);
};
}}


#endif
