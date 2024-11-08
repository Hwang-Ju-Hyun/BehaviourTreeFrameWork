#include "Stdafx.h"
#include "L_Is_Captain_Node.h"

namespace BT
{
	void BT::L_Is_Captain_Node::OnInitial(NodeData* nodedata_ptr)
	{

	}

	Status BT::L_Is_Captain_Node::OnEnter(NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();				

		if(tinybb->GetIsCaptain())
			return Status::BT_SUCCESS;
		return Status::BT_FAILURE;
	}

	void BT::L_Is_Captain_Node::OnExit(NodeData* nodedata_ptr)
	{
	}

	Status BT::L_Is_Captain_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);

		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();

		if (IsNear(self->GetBody().GetPos(), self->GetTargetPOS()))
			return Status::BT_SUCCESS;

		return Status::BT_RUNNING;
	}

	Status BT::L_Is_Captain_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return Status();
	}

}
