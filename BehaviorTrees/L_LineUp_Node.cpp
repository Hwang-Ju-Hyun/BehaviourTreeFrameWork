#include "Stdafx.h"
#include "L_LineUp_Node.h"
#include "LineUpNodeData.h"
#include "CaptainNodeData.h"
namespace BT
{		
	float L_LineUp_Node::LineUpoffset = 0.f;

	void BT::L_LineUp_Node::OnInitial(NodeData* nodedata_ptr)
	{
		LeafNode::OnInitial(nodedata_ptr);
		nodedata_ptr->InitialLocalBlackBoard<CaptainNodeData>();	
		nodedata_ptr->InitialLocalBlackBoard<LineUpNodeData>();
	}

	Status BT::L_LineUp_Node::OnEnter(NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		tinybb->m_mouseClick = false;

		CaptainNodeData* captain_node_data = nodedata_ptr->GetLocalBlackBoard<CaptainNodeData>();
		LineUpNodeData* lineup_node_data   =nodedata_ptr->GetLocalBlackBoard<LineUpNodeData>();

		GameObject* captain = GetCaptainAgent();
		
		float offset = lineup_node_data->offset;
		
		D3DXVECTOR3 cap_pos=captain->GetTargetPOS();

		offset += 0.5f;
		self->SetTargetPOS({ 0.f,0.f + offset,0.f });
		self->SetSpeedStatus(TinySpeedStatus::TS_JOG);
		SetTinySpeed(self);
		return Status::BT_SUCCESS;
	}

	void BT::L_LineUp_Node::OnExit(NodeData* nodedata_ptr)
	{
	}

	Status BT::L_LineUp_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);

		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();

		if (IsNear(self->GetBody().GetPos(), self->GetTargetPOS()))
		{			
			return Status::BT_SUCCESS;
		}
			

		return Status::BT_RUNNING;
	}

	Status BT::L_LineUp_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return Status();
	}

}