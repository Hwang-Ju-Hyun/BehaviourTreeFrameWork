#include "Stdafx.h"
#include "L_Red_Node.h"

namespace BT
{
	void BT::L_Red_Node::OnInitial(NodeData* nodedata_ptr)
	{
		LeafNode::OnInitial(nodedata_ptr);
	}

	Status BT::L_Red_Node::OnEnter(NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		self->GetTiny().SetDiffuse(1.0f, 0.f, 0.f);
		
		return Status::BT_RUNNING;
	}

	void BT::L_Red_Node::OnExit(NodeData* nodedata_ptr)
	{
		LeafNode::OnExit(nodedata_ptr);
	}

	Status BT::L_Red_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);
		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();
		return Status::BT_SUCCESS;
	}

	Status BT::L_Red_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return LeafNode::OnSuspend(nodedata_ptr);
	}

}