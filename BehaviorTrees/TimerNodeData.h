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
		float temp_time = 0.f;
	};
}


