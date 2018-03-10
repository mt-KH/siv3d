#ifndef DEF_ESSENCE_IPRIMITIVE_H
#define DEF_ESSENCE_IPRIMITIVE_H

namespace essence {
	namespace primitive {

/// �v���~�e�B�u�^�C�v�̗�
enum class EType {
	Invalid = -1,  /// �s���Ȍ^
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