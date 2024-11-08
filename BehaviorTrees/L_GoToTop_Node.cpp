#include "Stdafx.h"
#include "L_GoToTop_Node.h"

namespace BT
{
	void BT::L_GoToTop_Node::OnInitial(NodeData* nodedata_ptr)
	{
		LeafNode::OnInitial(nodedata_ptr);
	}

	Status BT::L_GoToTop_Node::OnEnter(NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		tinybb->m_mouseClick = false;		
		self->SetTargetPOS({ 0.5f,0.0f,1.0f });
		self->SetSpeedStatus(TinySpeedStatus::TS_JOG);
		SetTinySpeed(self);
		return Status::BT_RUNNING;
	}

	void BT::L_GoToTop_Node::OnExit(NodeData* nodedata_ptr)
	{
	}

	Status BT::L_GoToTop_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);

		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();

		if (IsNear(self->GetBody().GetPos(), self->GetTargetPOS()))
			return Status::BT_SUCCESS;

		return Status::BT_RUNNING;
	}

	Status BT::L_GoToTop_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return Status();
	}

}