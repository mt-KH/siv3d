#ifndef ESSENCE_COMMON_PRIMITIVE_UTILITY_STRINGUTIL_H
#define ESSENCE_COMMON_PRIMITIVE_UTILITY_STRINGUTIL_H
#include "String.h"
namespace essence {
	namespace primitive {
		namespace utility {
class CStringUtil
{
public:
	CStringUtil() = delete;
	CStringUtil(const CStringUtil&) = delete;
	CStringUtil(CStringUtil&) = delete;
	CStringUtil(CStringUtil&&) = delete;
	~CStringUtil() = default;

public:
	/**
	* �������̕�����Ɋ܂܂��������̕�������O�����̕�����ɒu���������������Ԃ��B
	*/
	static CString Replace(const CString&, const CString&, const CString&);

	/**
	* �������̕����񂩂�������̕�������폜�����������Ԃ�
	*/

	static CString Substring(const CString&, const CString&);

	/**
	* �����񂪓��������̔�r
	*/
	static bool Equal(const CString&, const CString&);

	/**
	* �����񂪓��������Ȃ����̔�r
	*/
	static bool NotEqual(const CString&, const CString&);

	/**
	* ������̘A�����s���܂�
	*/
	static CString Concatenation(const CString&, const CString&);

	/**
	* ������̘A�����s���܂�
	*/
	static int Length(const CString& refStr);
};
}}}
#endif