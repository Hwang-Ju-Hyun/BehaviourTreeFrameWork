#include "Stdafx.h"
#include "D_Timer.h"
#include "TimerNodeData.h"
namespace BT
{
	void BT::D_Timer::OnInitial(NodeData* nodedata_ptr)
	{
		RepeaterNode::OnInitial(nodedata_ptr);
		nodedata_ptr->InitialLocalBlackBoard<TimerNodeData>();
	}

	Status BT::D_Timer::OnEnter(NodeData* nodedata_ptr)
	{
		return RepeaterNode::OnEnter(nodedata_ptr);
	}

	void BT::D_Timer::OnExit(NodeData* nodedata_ptr)
	{

		RepeaterNode::OnExit(nodedata_ptr);
	}

	Status BT::D_Timer::OnUpdate(float dt, NodeData* nodedata_ptr)
	{
		AgentBTData& agentdata = nodedata_ptr->GetAgentData();
		GameObject* self = agentdata.GetGameObject();
		TinyBlackBoard* tinybb = agentdata.GetLocalBlackBoard<TinyBlackBoard>();

		Status child_status = nodedata_ptr->GetChildStatus(0);
		TimerNodeData* timer=nodedata_ptr->GetLocalBlackBoard<TimerNodeData>();
		timer->acc_time += dt;

		if (child_status == BT_SUCCESS)
		{			
			if (timer->max_time <= timer->acc_time)
			{				
				tinybb->m_vStandBy.insert(self);
				return Status::BT_SUCCESS;
			}				
			return Status::BT_RUNNING;
		}
		
	}

	Status BT::D_Timer::OnSuspend(NodeData* nodedata_ptr)
	{
		return RepeaterNode::OnSuspend(nodedata_ptr);
	}
}