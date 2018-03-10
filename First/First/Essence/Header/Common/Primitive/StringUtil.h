#ifndef ESSENCE_COMMON_PRIMITIVE_UTILITY_STRINGUTIL_H
#define ESSENCE_COMMON_PRIMITIVE_UTILITY_STRINGUTIL_H
#include "String.h"
namespace essence {
	namespace primitive {
		namespace utility {
class CStringUtil
{
public:
	CStringUtil() = delete;
	CStringUtil(const CStringUtil&) = delete;
	CStringUtil(CStringUtil&) = delete;
	CStringUtil(CStringUtil&&) = delete;
	~CStringUtil() = default;

public:
	/**
	* 第一引数の文字列に含まれる第二引数の文字列を第三引数の文字列に置き換えた文字列を返す。
	*/
	static CString Replace(const CString&, const CString&, const CString&);

	/**
	* 第一引数の文字列から第二引数の文字列を削除した文字列を返す
	*/

	static CString Substring(const CString&, const CString&);

	/**
	* 文字列が等しいかの比較
	*/
	static bool Equal(const CString&, const CString&);

	/**
	* 文字列が等しいくないかの比較
	*/
	static bool NotEqual(const CString&, const CString&);

	/**
	* 文字列の連結を行います
	*/
	static CString Concatenation(const CString&, const CString&);

	/**
	* 文字列の連結を行います
	*/
	static int Length(const CString& refStr);
};
}}}
#endif