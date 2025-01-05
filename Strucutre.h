#pragma once

// ベクトル
struct Vec2
{
	float x;
	float y;
};

// 行列
struct Matrix3x3
{
	float m[3][3];
};

// 図形
struct Shape
{
	// 半径
	float radius;

	// 角度
	float theta;

	// 移動
	struct Vec2 translate;
};