#ifndef ESSENCE_COMMON_BASE_IOBJECT_H
#define ESSENCE_COMMON_BASE_IOBJECT_H

namespace essence {

	/// 前方宣言
namespace primitive {
	class CString;
}

namespace base {

class IObject {
public:
	virtual ~IObject() = default;

	/**
	* 文字列変換。派生先で実装。
	*/
	virtual primitive::CString ToString() = 0;
};
}}

#endif