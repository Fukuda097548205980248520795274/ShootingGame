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

// 頂点
struct Vertex
{
	// 左上
	struct Vec2 leftTop;

	// 右上
	struct Vec2 rightTop;

	// 左下
	struct Vec2 leftBottom;

	// 右下
	struct Vec2 rightBottom;
};

// 位置
struct Pos2
{
	// ローカル座標
	struct Vertex local;

	// スクリーン座標
	struct Vertex screen;
};