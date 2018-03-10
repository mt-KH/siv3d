#include "String.h"
#include <string.h>
#include <stdio.h>
using namespace essence;
using namespace primitve;

namespace {
	/**
	* CString::Substringの実態
	*/
	CString ReplaceImpl(char* value, char* oldStr,char* newStr) {

		char* p = value;

		p = strstr(value, oldStr);

		if (p != nullptr) {

			*p = '\0';
			auto tailStr = p + strlen(oldStr);
			char* temp = new char[strlen(value) + strlen(newStr)+ strlen(tailStr) + 1];
			sprintf(temp, "%s%s%s", value, newStr, tailStr);

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
	m_size( strlen( value.m_value )) {

	m_value = new char[m_size + 1];
	sprintf(m_value, "%s", value.m_value);

}

CString::CString(CString&& value) noexcept :
	m_size( strlen( m_value ) ) {

	m_value = new char[m_size + 1];
	sprintf(m_value, "%s", value);
}

CString::CString(char* value) :
	m_size(strlen(value)) {

	m_value = new char[m_size + 1];
	sprintf(m_value, "%s", value);
}

CString::CString(CString& value) :
	m_size(strlen(value.m_value)) {

	m_value = new char[m_size + 1];
	sprintf(m_value, "%s", value.m_value);
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

	return ReplaceImpl(m_value, value.m_value, "");
}

char* CString::GetValue() const{
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
bool CString::operator == (char* value) {
	return (strcmp(m_value, value) == 0);
}

bool CString::operator == (CString& value) {
	return (strcmp(m_value, value.m_value) == 0);
}

/**
* 等しくないかの判断
*/

bool CString::operator != (char* value) {
	return !(*this == value);
}

bool CString::operator != (CString& value) {
	return !(*this == value);
}

/**
* 連結代入
*/
CString& CString::operator += (char* value) {
	m_size = (strlen(value) + m_size);
	char* temp = new char[m_size + 1];
	memset(temp, 0, sizeof(char) * m_size + 1);

	sprintf(temp, "%s%s", m_value, value);
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
CString CString::operator + (char* value) {
	int size = (strlen(value) + m_size);
	char* temp = new char[size + 1];
	memset(temp, 0, sizeof(char) * size + 1);

	sprintf(temp, "%s%s", m_value, value);
	return temp;
}

CString CString::operator + (CString& value) {
	return *this + value.m_value;
}

/**
* 代入
*/
CString& CString::operator = (char* value) {
	if (m_value != nullptr) {
		delete m_value;
	}
	m_size = strlen(value);
	m_value = new char[m_size + 1];
	sprintf(m_value, "%s", value);
	return *this;
}

CString& CString::operator = (CString& value) {
	*this = value.m_value;
	return *this;
}

