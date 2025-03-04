#pragma once
#include <Novice.h>
#include "Structure.h"
#include "./Function/Matrix/Matrix.h"
#include "./Function/Vector/Vector.h"

class Object
{
public:

	/// <summary>
	/// ローカル座標をスクリーン座標に変換する
	/// </summary>
	void LocalToScreen();

	/// <summary>
	/// 描画する
	/// </summary>
	virtual void Draw();

	// 図形
	struct Shape shape_;

	// 位置
	struct Pos2 pos_;

	// ベクトル
	struct Vec2 vec_;

	// 移動速度
	struct Vec2 vel_;
};