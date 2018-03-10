#ifndef ESSENCE_COMMON_BASE_IOBJECT_H
#define ESSENCE_COMMON_BASE_IOBJECT_H

namespace essence {

	/// �O���錾
namespace primitive {
	class CString;
}

namespace base {

class IObject {
public:
	virtual ~IObject() = default;

	/**
	* ������ϊ��B�h����Ŏ����B
	*/
	virtual primitive::CString ToString() = 0;
};
}}

#endif