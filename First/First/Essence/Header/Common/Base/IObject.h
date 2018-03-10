#ifndef ESSENCE_COMMON_BASE_IOBJECT_H
#define ESSENCE_COMMON_BASE_IOBJECT_H

namespace essence {

	/// ‘O•ûéŒ¾
namespace primitive {
	class CString;
}

namespace base {

class IObject {
public:
	virtual ~IObject() = default;

	/**
	* •¶š—ñ•ÏŠ·B”h¶æ‚ÅÀ‘•B
	*/
	virtual primitive::CString ToString() = 0;
};
}}

#endif