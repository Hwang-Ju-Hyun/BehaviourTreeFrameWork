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
	}

	Status BT::L_LineUp_Node::OnEnter(NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();		
		objectID cap_id=g_database.GetIDByName("BTAgent0");		
		TinyBlackBoard* capbb=g_trees.GetAgentData("BTAgent0").GetLocalBlackBoard<TinyBlackBoard>();
		
		if(!capbb->m_bArrived)
			return Status::BT_READY;

		if (tinybb->m_vAllLineUpReadyVec.insert(self).second)
		{
			tinybb->m_mouseClick = false;
			tinybb->m_iIndex = self->GetID() - 2;
			int each_index = tinybb->m_iIndex;
			int elements = 10;
			float each_obj_pos = 0.f + (((1.0f - 0.f) / float(elements + 1)) * float(each_index + 1));

			self->SetTargetPOS({ each_obj_pos,0.f,0.f });
			self->SetSpeedStatus(TinySpeedStatus::TS_JOG);
			SetTinySpeed(self);
		}
		if (tinybb->m_vAllLineUpReadyVec.size() >= 9)
		{
			return Status::BT_RUNNING;
		}
		else
		{
			return Status::BT_READY;
		}
	}

	void BT::L_LineUp_Node::OnExit(NodeData* nodedata_ptr)
	{
		LeafNode::OnExit(nodedata_ptr);
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
		return LeafNode::OnSuspend(nodedata_ptr);
	}

}