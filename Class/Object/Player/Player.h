#pragma once
#include "./Class/Object/Object.h"

class Player : public Object
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};

