#include <Stdafx.h>
#include "L_New_Node.h"

namespace BT
{
	void BT::L_NewNode::OnInitial(NodeData* nodedata_ptr)
	{
		LeafNode::OnInitial(nodedata_ptr);
	}

	Status L_NewNode::OnEnter(NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		tinybb->m_mouseClick = false;

		self->SetTargetPOS({ -1.0f,0.0f,0.0f });
		self->SetSpeedStatus(TinySpeedStatus::TS_JOG);
		SetTinySpeed(self);

		return Status::BT_RUNNING;		
	}

	void L_NewNode::OnExit(NodeData* nodedata_ptr)
	{
		LeafNode::OnExit(nodedata_ptr);
	}

	Status L_NewNode::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);

		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();

		if (IsNear(self->GetBody().GetPos(), self->GetTargetPOS()))
			return Status::BT_SUCCESS;

		return Status::BT_RUNNING;
	}

	Status L_NewNode::OnSuspend(NodeData* nodedata_ptr)
	{
		return Status::BT_SUSPEND;
	}
}