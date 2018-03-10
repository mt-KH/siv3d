#include "String.h"
#include <string.h>
#include <stdio.h>
using namespace essence;
using namespace primitve;

namespace {
	/**
	* CString::Substring�̎���
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
* �������̕������������̕�����ɒu���������������Ԃ��B
*/
CString CString::Replace(const CString& oldStr, const CString& newStr) {
	if (oldStr.m_value == nullptr)
		return *this;

	return ReplaceImpl(m_value, oldStr.m_value, newStr.m_value);
}

/**
* ���݂̒l��������̕�������폜�����������Ԃ�
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
* ������̒���
*/
int CString::Length() const {
	return m_size;
}

/**
* ���������̔��f
*/
bool CString::operator == (char* value) {
	return (strcmp(m_value, value) == 0);
}

bool CString::operator == (CString& value) {
	return (strcmp(m_value, value.m_value) == 0);
}

/**
* �������Ȃ����̔��f
*/

bool CString::operator != (char* value) {
	return !(*this == value);
}

bool CString::operator != (CString& value) {
	return !(*this == value);
}

/**
* �A�����
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
* �A��
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
* ���
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

