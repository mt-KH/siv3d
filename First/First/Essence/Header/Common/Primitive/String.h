#ifndef ESSENCE_COMMON_PRIMITIVE_STRING_H
#define ESSENCE_COMMON_PRIMITIVE_STRING_H
#include "Base\IPrimitive.h"

namespace essence { namespace primitive {

class CString : public IPrimitive
{

public:
#if _UNICODE
	typedef wchar_t unitType;
#else
	typedef char unitType;
#endif

public:
	static const CString Empty;
public:
	CString();
	CString( const CString& );
	CString(unitType*);
	CString( CString&& ) noexcept;
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

	/**
	* �^�C�v�̎擾
	*/
	EType Type()override;

	/**
	* ��NULL���̊m�F�֐�
	* ��NULL�Ȃ�true��Ԃ�
	*/
	bool CheckNullOrEmpty();

public:
	/**
	* �I�y���[�^�[�̃I�[�o�[���[�h
	*/

	/**
	* �����̕�����Ƃ̓���������r
	*/
	bool operator == (unitType*);
	bool operator == (CString&);
	bool operator == (const CString&);

	/**
	* �����̕�����Ƃ̓������Ȃ�����r
	*/
	bool operator != (unitType*);
	bool operator != (CString&);
	bool operator != (const CString&);

	/**
	* ���
	*/
	CString& operator = (unitType*);

	/**
	* ������̘A��
	*/
	CString& operator += (unitType*);
	CString& operator += (CString&);
	CString operator + (unitType*);
	CString operator + (CString&);

private:
	unitType* m_value;
};

/**
* �����̕�����Ƃ̓���������r
*/
bool operator == (CString::unitType*, const CString&);
bool operator == (CString::unitType*, CString&);

/**
* �����̕�����Ƃ̓������Ȃ�����r
*/
bool operator != (CString::unitType*, const CString&);
bool operator != (CString::unitType* ,CString&);

}}
#endif
