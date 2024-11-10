#include "Stdafx.h"
#include "CaptainNodeData.h"

namespace BT
{
	BT::CaptainNodeData::CaptainNodeData()
	{
	}

	BT::CaptainNodeData::~CaptainNodeData()
	{
	}

	void BT::CaptainNodeData::SetCaptain(GameObject* _obj)
	{
		m_pCaptain = _obj;
	}

	GameObject* BT::CaptainNodeData::GetCaptain() const
	{
		return m_pCaptain;
	}

}