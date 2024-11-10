#include "Stdafx.h"
#include "LineUpNodeData.h"

namespace BT
{
	
	float LineUpNodeData::offset = 0.f;

	BT::LineUpNodeData::LineUpNodeData()
	{
	}

	BT::LineUpNodeData::~LineUpNodeData()
	{
	}

	void BT::LineUpNodeData::SetLineUpPos(D3DXVECTOR3 _pos)
	{
		m_vLineUpPos = _pos;
	}

	void BT::LineUpNodeData::AddLineUpPos(D3DXVECTOR3 _pos)
	{
		m_vLineUpPos += _pos;
	}

	D3DXVECTOR3 BT::LineUpNodeData::GetLineUpPos() const
	{
		return m_vLineUpPos;
	}
}