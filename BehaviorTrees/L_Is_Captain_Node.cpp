#include "Stdafx.h"
#include "CaptainNodeData.h"
#include "L_Is_Captain_Node.h"
#include "TimerNodeData.h"

namespace BT
{
	void BT::L_Is_Captain_Node::OnInitial(NodeData* nodedata_ptr)
	{		
		LeafNode::OnInitial(nodedata_ptr);
		nodedata_ptr->InitialLocalBlackBoard<CaptainNodeData>();	
		
	}

	Status BT::L_Is_Captain_Node::OnEnter(NodeData* nodedata_ptr)
	{
		LeafNode::OnEnter(nodedata_ptr);

		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		CaptainNodeData* captain_node_data = nodedata_ptr->GetLocalBlackBoard<CaptainNodeData>();
		GameObject* captain_obj = nodedata_ptr->GetAgentData().GetGameObject();

		if (strcmp(captain_obj->GetName(), "BTAgent0") == 0)
		{
			captain_node_data->SetCaptain(captain_obj);
		}
		
		if(captain_node_data ->GetCaptain()!=nullptr)
			return Status::BT_SUCCESS;
		return Status::BT_FAILURE;
	}

	void BT::L_Is_Captain_Node::OnExit(NodeData* nodedata_ptr)
	{
		LeafNode::OnExit(nodedata_ptr);
	}

	Status BT::L_Is_Captain_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);

		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();

		return Status::BT_SUCCESS;
	}

	Status BT::L_Is_Captain_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return LeafNode::OnSuspend(nodedata_ptr);
	}

}
