#include "Stdafx.h"
#include "L_LineUp_Node.h"

namespace BT
{
	void BT::L_LineUp_Node::OnInitial(NodeData* nodedata_ptr)
	{
		LeafNode::OnInitial(nodedata_ptr);
	}

	Status BT::L_LineUp_Node::OnEnter(NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		tinybb->m_mouseClick = false;
		//D3DXVECTOR3 lineup_pos = self->GetLineUpPos();
		self->SetTargetPOS({ 1.0f,0.f,0.f });
		self->SetSpeedStatus(TinySpeedStatus::TS_JOG);
		SetTinySpeed(self);

		return Status::BT_RUNNING;
	}

	void BT::L_LineUp_Node::OnExit(NodeData* nodedata_ptr)
	{
	}

	Status BT::L_LineUp_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);

		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();

		if (IsNear(self->GetBody().GetPos(), self->GetTargetPOS()))
			return Status::BT_SUCCESS;

		return Status::BT_RUNNING;
	}

	Status BT::L_LineUp_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return Status();
	}

}