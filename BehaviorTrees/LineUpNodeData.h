#pragma once
#include <BehaviorTrees/BehaviorTreesShared.h>
namespace BT
{
	struct LineUpNodeData :
		public NodeAbstractData
	{
	public:
		LineUpNodeData();
		~LineUpNodeData();
	private:
		D3DXVECTOR3 m_vLineUpPos = {};		
	public:
		void SetLineUpPos(D3DXVECTOR3 _pos);
		void AddLineUpPos(D3DXVECTOR3 _pos);
		D3DXVECTOR3 GetLineUpPos()const;
		static float offset;
	};
}
