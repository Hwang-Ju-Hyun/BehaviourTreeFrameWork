/******************************************************************************/
/*!
\file		TinyBlackBoard.h
\project	CS380/CS580 AI Framework
\author		Chi-Hao Kuo
\summary	Local blackboard for tiny.

Copyright (C) 2016 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/

#pragma once

#include <BehaviorTrees/BehaviorTreesShared.h>

namespace BT
{
	// store tiny info
	struct TinyBlackBoard : public AgentAbstractData
	{
		/* variable */

		GameObject *m_npc;				// agent's game object pointer

		// for mouse click only, change later
		bool m_mouseClick;
		D3DXVECTOR3 m_mousePos;

		/* constructors/destructor */

		// Default constructor
		TinyBlackBoard();


		/* methods */

		// Handle messages
		virtual void OnMessage(void) override;


	public:
		GameObject* m_pCaptain = nullptr;
		D3DXVECTOR3 m_LineUpPOS;
		bool m_bIsCaptain = false;
		void SetCaptain(GameObject* _captain) { m_pCaptain = _captain; }
		GameObject* GetCaptain()const { return m_pCaptain; }
		void SetIsCaptain(bool _cap) { m_bIsCaptain = _cap; }
		bool GetIsCaptain()const { return m_bIsCaptain; }
		void SetLineUpPos(D3DXVECTOR3 _lineUpPos) { m_LineUpPOS = _lineUpPos; }
		D3DXVECTOR3 GetLineUpPos()const { return m_LineUpPOS; }
	};
}