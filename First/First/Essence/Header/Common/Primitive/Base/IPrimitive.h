#ifndef DEF_ESSENCE_IPRIMITIVE_H
#define DEF_ESSENCE_IPRIMITIVE_H

namespace essence {
	namespace primitive {

/// プリミティブタイプの列挙
enum class EType {
	Invalid = -1,  /// 不正な型
	Int32,
	Int64,
	Float32,
	Float64,
	String,
	Bool,
	Bit
};

class IPrimitive {

public:
	virtual ~IPrimitive() = default;

	virtual EType Type() = 0;
};

}}

#endif