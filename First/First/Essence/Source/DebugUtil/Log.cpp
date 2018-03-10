#include "../../Header/DebugUtil/Log.h"
#include "../../Header/Common/Primitive/String.h"
#include <iostream>
using namespace essence::debug;
using namespace essence::primitive;
/**
* �v���~�e�B�u�^�������Ƃ���f�o�b�O�o��
*/
void CLog::Out(essence::primitive::IPrimitive* arg, EDestination outDestination) {
	if (arg == nullptr)
	{
		/// TODO: �f�o�b�O���͌x�����A�G���[�Ȃǂ��o�͂���
		return;
	}

	switch (arg->Type())
	{
	case primitive::EType::String:
		std::cout << static_cast<CString*>(arg)->Value() << std::endl;
		break;

	default:
		break;
	}
}

/**
* �I�u�W�F�N�g�^�������Ƃ���f�o�b�O�o��
*/
void CLog::Out(essence::base::IObject* object, EDestination outDestination) {
	/// TODO : ����
}