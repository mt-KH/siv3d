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
* �������̕������������̕�����ɒu���������������Ԃ��B
*/
CString CString::Replace(const CString& oldStr, const CString& newStr) {
	if (oldStr.m_value == nullptr)
		return *this;

	return CStringUtil::Replace(*this, oldStr.m_value, newStr.m_value);
}

/**
* ���݂̒l��������̕�������폜�����������Ԃ�
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
* ������̒���
*/
int CString::Length() const {
	return m_size;
}

/**
* �^�C�v�̎擾
*/
EType CString::Type() {
	return EType::String;
}

/**
* ���������̔��f
*/
bool CString::operator == (unitType* value) {
	return CStringUtil::Equal(*this, value);
}

bool CString::operator == (CString& value) {
	return CStringUtil::Equal(*this, value);
}

/**
* �������Ȃ����̔��f
*/

bool CString::operator != (unitType* value) {
	return CStringUtil::NotEqual(*this, value);
}

bool CString::operator != (CString& value) {
	return CStringUtil::NotEqual(*this, value);
}

/**
* �A�����
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
* �A��
*/
CString CString::operator + (unitType* value) {

	return CStringUtil::Concatenation(*this, value);
}

CString CString::operator + (CString& value) {
	return CStringUtil::Concatenation(*this, value);
}

/**
* ���
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

