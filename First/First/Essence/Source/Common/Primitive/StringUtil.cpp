#include "../../../Header/Common/Primitive/StringUtil.h"
#include <string.h>
#include <stdio.h>
using namespace essence::primitive::utility;
using namespace essence::primitive;

/**
* 第一引数の文字列に含まれる第二引数の文字列を第三引数の文字列に置き換えた文字列を返す。
*/
CString CStringUtil::Replace(const CString& refStr, const CString& oldStr, const CString& newStr) {

	if (oldStr.Value() == nullptr || Equal(oldStr,CString::Empty))
		return refStr;

	CString::unitType* p = refStr.Value();
#if _UNICODE
	p = wcsstr(refStr.Value(), oldStr.Value());
#else
	p = strstr(refStr.Value(), oldStr.Value());
#endif

	if (p != nullptr) {

		*p = '\0';
		CString::unitType* tailStr = ( p + Length(oldStr) );
		int size = Length(refStr) + Length(newStr) + Length(tailStr) + 1;
		CString::unitType* temp = new CString::unitType[size];

#if _UNICODE
		swprintf(temp, size + 1, L"%s%s%s", refStr.Value(), newStr.Value(), tailStr);
#else
		snprintf(temp, size + 1, "%s%s%s", refStr.Value(), newStr.Value(), tailStr);
#endif

		return Replace(temp, oldStr, newStr);
	}

	return refStr;
}

/**
* 現在の値から引数の文字列を削除した文字列を返す
*/

CString CStringUtil::Substring(const CString& refStr, const CString& removeStr) {
#if _UNICODE
	return Replace(refStr, removeStr, L"");
#else
	return Replace(refStr, removeStr, "");
#endif
}

/**
* 引数の文字列の長さを返す
*/
int CStringUtil::Length(const CString& refStr) {
#if _UNICODE
	return wcslen(refStr.Value());
#else
	return strlen(value.Value());
#endif
}

/**
* 文字列が等しいかの比較
*/
bool CStringUtil::Equal(const CString& str1, const CString& str2) {
#if _UNICODE
	return (wcscmp(str1.Value(), str2.Value()) == 0);
#else
	return (strcmp(str1.Value(), str2.Value()) == 0);
#endif
}

/**
* 文字列が等しいくないかの比較
*/
bool CStringUtil::NotEqual(const CString& str1, const CString& str2) {
	return ( !Equal(str1, str2) );
}

/**
* 文字列の連結を行います
*/
CString CStringUtil::Concatenation(const CString& str1, const CString& str2) {

	int size = (Length(str1) + Length(str2)) + 1;
	CString::unitType* temp = new CString::unitType[size];
	memset(temp, 0, sizeof(CString::unitType) * size);

#if _UNICODE
	swprintf(temp, size, L"%s%s", str1.Value(), str2.Value());
#else
	snprintf(temp, size, "%s%s", str1.Value(), str2.Value());
#endif

	return temp;
}