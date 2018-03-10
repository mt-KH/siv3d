#include "../../../Header/Common/Primitive/String.h"
#include "../../../Header/Common/Primitive/StringUtil.h"
#include <string.h>
#include <stdio.h>

using namespace essence::primitive;
using namespace essence::primitive::utility;

namespace {
	/**
	* 文字列の長さを返します。
	*/
	int GetLength(CString::unitType* val){
#if _UNICODE
		return wcslen(val);
#else
		return strlen(val);
#endif
	}
}

#if _UNICODE
const CString CString::Empty = L"";
#else
const CString CString::Empty = "";
#endif

CString::CString() :
	m_value(nullptr){

}
CString::CString(const CString& value) {

	*this = value.m_value;
}

CString::CString(unitType* value){
	*this = value;
}

CString::CString(CString&& value) noexcept {
	*this = value.m_value;
}


CString::~CString()
{
	delete m_value;
}


/**
* 第一引数の文字列を第二引数の文字列に置き換えた文字列を返す。
*/
CString CString::Replace(const CString& oldStr, const CString& newStr) {
	if (oldStr.m_value == nullptr)
		return *this;

	return CStringUtil::Replace(*this, oldStr, newStr);
}

/**
* 現在の値から引数の文字列を削除した文字列を返す
*/

CString CString::Substring(const CString& value) {

	if (value.m_value == nullptr)
		return *this;

	return CStringUtil::Substring(*this, value);
}

CString::unitType* CString::Value() const{
	return m_value;
}

/**
* 文字列の長さ
*/
int CString::Length() const {
	return GetLength(m_value);
}

/**
* タイプの取得
*/
EType CString::Type() {
	return EType::String;
}

/**
* 等しいかの判断
*/
bool CString::operator == (unitType* value) {
	return CStringUtil::Equal(*this, value);
}

bool CString::operator == (CString& value) {
	return CStringUtil::Equal(*this, value);
}

/**
* 等しくないかの判断
*/

bool CString::operator != (unitType* value) {
	return CStringUtil::NotEqual(*this, value);
}

bool CString::operator != (CString& value) {
	return CStringUtil::NotEqual(*this, value);
}

/**
* 連結代入
*/
CString& CString::operator += (unitType* value) {
	CString temp = CStringUtil::Concatenation(*this, value);
	delete m_value;

	*this = temp.m_value;
	return *this;
}

CString& CString::operator += ( CString& value ) {
	*this += value.m_value;
	return *this;
}


/**
* 連結
*/
CString CString::operator + (unitType* value) {

	return CStringUtil::Concatenation(*this, value);
}

CString CString::operator + (CString& value) {
	return CStringUtil::Concatenation(*this, value);
}

/**
* 代入
*/
CString& CString::operator = (unitType* value) {
	delete m_value;

	int size = GetLength(value);
	m_value = new unitType[size + 1];
#if _UNICODE
	swprintf(m_value, size + 1, L"%s", value);
#else
	snprintf(m_value, size + 1, "%s", value);
#endif

	return *this;
}

