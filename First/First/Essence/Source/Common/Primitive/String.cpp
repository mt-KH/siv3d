#include "../../../Header/Common/Primitive/String.h"
#include "../../../Header/Common/Primitive/StringUtil.h"
#include <string.h>
#include <stdio.h>

using namespace essence::primitive;
using namespace essence::primitive::utility;

#if _UNICODE
const CString CString::Empty = L"";
#else
const CString CString::Empty = "";
#endif

CString::CString() :
	m_value(nullptr),
	m_size(0){

}
CString::CString(const CString& value) :
	m_size(CStringUtil::Length( value )) {

	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value.m_value);
#else
	snprintf(m_value, m_size + 1, "%s", value.m_value);
#endif

}

CString::CString(CString&& value) noexcept :
	m_size(CStringUtil::Length( m_value ) ) {

	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value.m_value);
#else
	snprintf(m_value, m_size + 1, "%s", value.m_value);
#endif
}

CString::CString(unitType* value) :
	m_size(CStringUtil::Length( value )) {

	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value);
#else
	snprintf(m_value, m_size + 1, "%s", value);
#endif
}

CString::CString(CString& value) :
	m_size(CStringUtil::Length( value )) {

	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value.m_value);
#else
	snprintf(m_value, m_size + 1, "%s", value.m_value);
#endif
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

	return CStringUtil::Replace(*this, oldStr.m_value, newStr.m_value);
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
	return m_size;
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

	*this = temp;
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
	if (m_value != nullptr) {
		delete m_value;
	}

	m_size = CStringUtil::Length(value);
	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value);
#else
	snprintf(m_value, m_size + 1, "%s", value);
#endif

	return *this;
}

CString& CString::operator = (CString& value) {
	*this = value.m_value;
	return *this;
}

