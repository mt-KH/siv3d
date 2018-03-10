#include "../../../Header/Common/Primitive/String.h"
#include "../../../Header/Common/Primitive/StringUtil.h"
#include <string.h>
#include <stdio.h>

using namespace essence::primitive;
using namespace essence::primitive::utility;

namespace {
	/**
	* ������̒�����Ԃ��܂��B
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
* �������̕������������̕�����ɒu���������������Ԃ��B
*/
CString CString::Replace(const CString& oldStr, const CString& newStr) {
	if (oldStr.m_value == nullptr)
		return *this;

	return CStringUtil::Replace(*this, oldStr, newStr);
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
	return GetLength(m_value);
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

	*this = temp.m_value;
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

