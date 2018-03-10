#ifndef ESSENCE_DEBUGUTILITY_LOG_H
#define ESSENCE_DEBUGUTILITY_LOG_H
#include "../Common/Primitive/Base/IPrimitive.h"
#include "../Common/Base/IObject.h"
namespace essence{ namespace debug {

class CLog {
public:
	CLog() = delete;
	CLog(const CLog&) = delete;
	CLog(CLog&&) = delete;
	~CLog() = default;

public:
	/**
	* ���O�̏o�͐�
	*/
	enum class EDestination
	{
		Console,
		Screen,
		All
	};

public:
	/**
	* �v���~�e�B�u�^�������Ƃ���f�o�b�O�o��
	* param[in] �o�͂���v���~�e�B�u�^
	* param[in] �o�͐�^�C�v
	*/
	static void Out(essence::primitive::IPrimitive*, EDestination);

	/**
	* �I�u�W�F�N�g�^�������Ƃ���f�o�b�O�o��
	* param[in] �o�͂���I�u�W�F�N�g�^
	* param[in] �o�͐�^�C�v
	*/
	static void Out(essence::base::IObject*, EDestination);
};
}}


#endif
