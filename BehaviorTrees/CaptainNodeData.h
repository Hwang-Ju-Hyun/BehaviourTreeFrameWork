#pragma once
#include <BehaviorTrees/BehaviorTreesShared.h>
namespace BT
{
	struct CaptainNodeData :
		public NodeAbstractData
	{
	public:
		CaptainNodeData();
		~CaptainNodeData();
	private:
		GameObject* m_pCaptain=nullptr;
	public:		
		void SetCaptain(GameObject* _obj);
		GameObject* GetCaptain()const;		
	};
}
