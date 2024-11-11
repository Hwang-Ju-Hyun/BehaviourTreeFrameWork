#include "Stdafx.h"
#include "L_TurnAroundRandomly_Node.h"

namespace BT
{
	void BT::L_TurnAroundRandomly_Node::OnInitial(NodeData* nodedata_ptr)
	{
		LeafNode::OnInitial(nodedata_ptr);
	}

	Status BT::L_TurnAroundRandomly_Node::OnEnter(NodeData* nodedata_ptr)
	{
		LeafNode::OnEnter(nodedata_ptr);
		
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		int random_dir = g_random.RangeInt(0, 4);

		D3DXVECTOR3 front, back, right, left;

		front = { 1.f,0.f,0.f };
		back = { -1.0f,0.f,0.f };
		right = { 0.0f,0.f,1.f };
		left = { 0.f,0.f,-1.f };
		switch (random_dir)
		{
		case 0:
			self->GetBody().SetDir(front);
			break;
		case 1:
			self->GetBody().SetDir(back);
			break;
		case 2:
			self->GetBody().SetDir(right);
			break;
		case 3:
			self->GetBody().SetDir(left);
			break;
		}
				
		if (tinybb->m_bAmICap)
		{
			tinybb->AccTime = 0.f;
			tinybb->cap_dir = self->GetBody().GetDir();
		}		

		return Status::BT_RUNNING;
	}

	void BT::L_TurnAroundRandomly_Node::OnExit(NodeData* nodedata_ptr)
	{
		//nodedata_ptr->GetAgentData().GetGameObject()->GetTiny().SetDiffuse(0.f, 0.f, 0.f);
		LeafNode::OnExit(nodedata_ptr);
	}

	Status BT::L_TurnAroundRandomly_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);
		GameObject* self = nodedata_ptr->GetAgentData().GetGameObject();
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();
		
		if (tinybb->m_bAmICap)
			tinybb->AccTime += dt;
		
		if (!tinybb->m_bAmICap&&self->GetBody().GetDir() != tinybb->cap_dir)
		{
			if (!tinybb->m_bInCorrectDir)
			{
				tinybb->m_bInCorrectDir = true;
				tinybb->m_iIncorectCount++;
			}
		}
		
		
		//타이머를 사용해서 쫌 있다가 success
		if (tinybb->AccTime >= 0.5f)
		{
			if (tinybb->m_bInCorrectDir)
			{
				tinybb->AccTime = 0.f;
				self->GetBody().SetScale(0.f);				
				tinybb->m_iIncorectCount--;
				return Status::BT_SUCCESS;
			}
			if (tinybb->m_bAmICap && tinybb->m_iIncorectCount == 0)
			{
				return Status::BT_SUCCESS;
			}
		}	

		

		return Status::BT_RUNNING;
		
	}

	Status BT::L_TurnAroundRandomly_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return LeafNode::OnSuspend(nodedata_ptr);
	}

}