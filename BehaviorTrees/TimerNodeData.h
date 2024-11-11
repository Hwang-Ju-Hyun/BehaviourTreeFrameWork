#pragma once

#include <BehaviorTrees/BehaviorTreesShared.h>

namespace BT
{
	class TimerNodeData :
		public NodeAbstractData
	{		
	public:
		TimerNodeData();
		~TimerNodeData();
	public:
		float max_time = 3.f;
		float acc_time = 0.f;
	};
}


