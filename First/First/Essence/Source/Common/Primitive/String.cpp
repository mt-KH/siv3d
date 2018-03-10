#include "../../../Header/Common/Primitive/String.h"
#include <string.h>
#include <stdio.h>
using namespace essence;
using namespace primitve;

namespace {

	int GetStringLength(const CString::unitType* value) {
#if _UNICODE
		return wcslen(value);
#else
		return strlen(value);
#endif
	}

	/**
	* CString::Substringの実態
	*/
	CString ReplaceImpl(CString::unitType* value, CString::unitType* oldStr, CString::unitType* newStr) {

		CString::unitType* p = value;
#if _UNICODE
		p = wcsstr(value, oldStr);
#else
		p = strstr(value, oldStr);
#endif

		if (p != nullptr) {

			*p = '\0';
			auto tailStr = p + GetStringLength(oldStr);
			int size = GetStringLength(value) + GetStringLength(newStr) + GetStringLength(tailStr) + 1;
			CString::unitType* temp = new CString::unitType[size];

#if _UNICODE
			swprintf(temp, size + 1, L"%s%s%s", value, newStr, tailStr);
#else
			snprintf(temp, size + 1, "%s%s%s", value, newStr, tailStr);
#endif

			return ReplaceImpl(temp, oldStr, newStr);
		}

		return value;
	}
}

CString::CString() :
	m_value(nullptr),
	m_size(0){

}
CString::CString(const CString& value) :
	m_size(GetStringLength( value.m_value )) {

	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value.m_value);
#else
	snprintf(m_value, m_size + 1, "%s", value.m_value);
#endif

}

CString::CString(CString&& value) noexcept :
	m_size( GetStringLength( m_value ) ) {

	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value.m_value);
#else
	snprintf(m_value, m_size + 1, "%s", value.m_value);
#endif
}

CString::CString(unitType* value) :
	m_size(GetStringLength(value)) {

	m_value = new unitType[m_size + 1];
#if _UNICODE
	swprintf(m_value, m_size + 1, L"%s", value);
#else
	snprintf(m_value, m_size + 1, "%s", value);
#endif
}

CString::CString(CString& value) :
	m_size(GetStringLength(value.m_value)) {

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

	return ReplaceImpl(m_value, oldStr.m_value, newStr.m_value);
}

/**
* 現在の値から引数の文字列を削除した文字列を返す
*/

CString CString::Substring(const CString& value) {

	if (value.m_value == nullptr)
		return *this;

#if _UNICODE
	return ReplaceImpl(m_value, value.m_value, L"");
#else
	return ReplaceImpl(m_value, value.m_value, "");
#endif
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
* 等しいかの判断
*/
bool CString::operator == (unitType* value) {
#if _UNICODE
	return (wcscmp(m_value, value) == 0);
#else
	return (strcmp(m_value, value) == 0);
#endif
}

bool CString::operator == (CString& value) {
#if _UNICODE
	return (wcscmp(m_value, value.m_value) == 0);
#else
	return (strcmp(m_value, value.m_value) == 0);
#endif
}

/**
* 等しくないかの判断
*/

bool CString::operator != (unitType* value) {
	return !(*this == value);
}

bool CString::operator != (CString& value) {
	return !(*this == value);
}

/**
* 連結代入
*/
CString& CString::operator += (unitType* value) {
	m_size = (GetStringLength(value) + m_size);
	unitType* temp = new unitType[m_size + 1];
	memset(temp, 0, sizeof(unitType) * m_size + 1);

#if _UNICODE
	swprintf(temp, m_size + 1, L"%s%s", m_value, value);
#else
	snprintf(temp, m_size + 1, "%s%s", m_value, value);
#endif
	delete m_value;

	this->m_value = temp;
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
	int size = (GetStringLength(value) + m_size);
	unitType* temp = new unitType[size + 1];
	memset(temp, 0, sizeof(unitType) * size + 1);

#if _UNICODE
	swprintf(temp, size + 1, L"%s%s", m_value, value);
#else
	snprintf(temp, size + 1, "%s%s", m_value, value);
#endif
	return temp;
}

CString CString::operator + (CString& value) {
	return *this + value.m_value;
}

/**
* 代入
*/
CString& CString::operator = (unitType* value) {
	if (m_value != nullptr) {
		delete m_value;
	}
	m_size = GetStringLength(value);
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

