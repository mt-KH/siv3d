#ifndef ESSENCE_COMMON_PRIMITIVE_STRING_H
#define ESSENCE_COMMON_PRIMITIVE_STRING_H
#include "Base\IPrimitive.h"

namespace essence {
	namespace primitve {
class CString : public IPrimitive
{

public:
#if _UNICODE
	typedef wchar_t unitType;
#else
	typedef char unitType;
#endif


public:
	CString();
	CString( const CString& );
	CString( CString&& ) noexcept;
	CString( unitType* );
	CString( CString& );
	~CString();

	/**
	* �������̕������������̕�����ɒu���������������Ԃ��B
	*/
	CString Replace( const CString&, const CString& );

	/**
	* ���݂̒l��������̕�������폜�����������Ԃ�
	*/

	CString Substring( const CString& );

	/**
	* ������̒���
	*/
	int Length() const;

	/**
	* �l�̎擾
	*/
	unitType* Value()const;
public:
	/**
	* �I�y���[�^�[�̃I�[�o�[���[�h
	*/

	/**
	* �����̕�����Ƃ̓���������r
	*/
	bool operator == (unitType*);

	/**
	* �����̕�����Ƃ̓������Ȃ�����r
	*/
	bool operator != (unitType*);

	/**
	* �����̕�����Ƃ̓������Ȃ�����r
	*/
	bool operator == (CString&);

	/**
	* �����̕�����Ƃ̓������Ȃ�����r
	*/
	bool operator != (CString&);

	/**
	* ���
	*/
	CString& operator = (unitType*);

	/**
	* ���
	*/
	CString& operator = (CString&);


	/**
	* ������̘A��
	*/
	CString& operator += (unitType*);
	CString& operator += (CString&);
	CString operator + (unitType*);
	CString operator + (CString&);

private:
	unitType* m_value;
	int m_size;
};
}}
#endif
