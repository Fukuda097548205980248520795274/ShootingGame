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
	/// 操作する
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">前のキー</param>
	void Operation(const char* keys, const char* preKeys);

	/// <summary>
	/// 描画する
	/// </summary>
	void Draw() override;
};