
#pragma once
#include "IPrimitive.h"

namespace essence {
	namespace primitve {
class CString : public IPrimitive
{
public:
	CString();
	CString( const CString& );
	CString( CString&& ) noexcept;
	CString( char* );
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
	char* GetValue()const;
public:
	/**
	* �I�y���[�^�[�̃I�[�o�[���[�h
	*/

	/**
	* �����̕�����Ƃ̓���������r
	*/
	bool operator == (char*);

	/**
	* �����̕�����Ƃ̓������Ȃ�����r
	*/
	bool operator != (char*);

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
	CString& operator = (char*);

	/**
	* ���
	*/
	CString& operator = (CString&);


	/**
	* ������̘A��
	*/
	CString& operator += (char*);
	CString& operator += (CString&);
	CString operator + (char*);
	CString operator + (CString&);

private:
	char* m_value;
	int m_size;
};
}}


