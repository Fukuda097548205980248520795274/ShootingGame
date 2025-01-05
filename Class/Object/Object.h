#pragma once
#include "Structure.h"
#include "./Function/Matrix/Matrix.h"

class Object
{
public:

	/// <summary>
	/// ローカル座標をスクリーン座標に変換する
	/// </summary>
	void LocalToScreen();

	// 図形
	struct Shape shape_;

	// 位置
	struct Pos2 pos_;

	// 移動速度
	struct Vec2 vel_;
};