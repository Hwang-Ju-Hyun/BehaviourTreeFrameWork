#include "Stdafx.h"
#include "L_TurnBack_Node.h"
#include "CaptainNodeData.h"

namespace BT
{
	void BT::L_TurnBack_Node::OnInitial(NodeData* nodedata_ptr)
	{
		LeafNode::OnInitial(nodedata_ptr);
	}

	Status BT::L_TurnBack_Node::OnEnter(NodeData* nodedata_ptr)
	{
		LeafNode::OnEnter(nodedata_ptr);

		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		D3DXVECTOR3 objs_dir = {0.0f,0.f,1.0f };
		D3DXVECTOR3 cap_dir = { 0.0f,0.f,-1.0f };
		if (strcmp(self->GetName(),"BTAgent0")==0)
		{
			tinybb->m_bAmICap=true;
			self->GetBody().SetDir(cap_dir);
		}
		else
		{
			self->GetBody().SetDir(objs_dir);			
		}		
		
		tinybb->m_vTurnBack.insert(self);
					
		return Status::BT_RUNNING;		
	}

	void BT::L_TurnBack_Node::OnExit(NodeData* nodedata_ptr)
	{
		LeafNode::OnExit(nodedata_ptr);
	}

	Status BT::L_TurnBack_Node::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		LeafNode::OnUpdate(dt, nodedata_ptr);
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();
		if (tinybb->m_vTurnBack.size() >= 10)
		{
			// 내가 캡틴이고, 모든 타이니들이 turn back을 헀을 경우,
			// 공용 타이머를 시작한다.
			if (tinybb->m_bAmICap)
			{
				tinybb->AccTime += dt;
			}

			if (tinybb->AccTime >= 3.f)
			{
				return Status::BT_SUCCESS;
			}
		}
		else
		{
			if (tinybb->m_bAmICap)
				tinybb->AccTime = 0.0f;
		}

		return Status::BT_RUNNING;
	}

	Status BT::L_TurnBack_Node::OnSuspend(NodeData* nodedata_ptr)
	{
		return LeafNode::OnSuspend(nodedata_ptr);
	}

}