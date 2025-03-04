#include "Matrix.h"

/// <summary>
/// 拡大縮小行列を作る
/// </summary>
/// <param name="radius">半径</param>
/// <returns>拡大縮小行列を返却する</returns>
struct Matrix3x3 MakeScaleMatrix(float radius)
{
	// 拡大縮小行列
	struct Matrix3x3 scaleMatrix;

	scaleMatrix.m[0][0] = radius;
	scaleMatrix.m[0][1] = 0.0f;
	scaleMatrix.m[0][2] = 0.0f;

	scaleMatrix.m[1][0] = 0.0f;
	scaleMatrix.m[1][1] = radius;
	scaleMatrix.m[1][2] = 0.0f;

	scaleMatrix.m[2][0] = 0.0f;
	scaleMatrix.m[2][1] = 0.0f;
	scaleMatrix.m[2][2] = 1.0f;

	return scaleMatrix;
}

/// <summary>
/// 回転行列を作る
/// </summary>
/// <param name="theta">角度</param>
/// <returns>回転行列を返却する</returns>
struct Matrix3x3 MakeRotateMatrix(float theta)
{
	// 回転行列
	struct Matrix3x3 rotateMatrix;

	rotateMatrix.m[0][0] = cosf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[0][1] = sinf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[0][2] = 0.0f;

	rotateMatrix.m[1][0] = -sinf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[1][1] = cosf((theta / 180.0f) * float(M_PI));
	rotateMatrix.m[1][2] = 0.0f;

	rotateMatrix.m[2][0] = 0.0f;
	rotateMatrix.m[2][1] = 0.0f;
	rotateMatrix.m[2][2] = 1.0f;

	return rotateMatrix;
}

/// <summary>
/// 平行移動行列を作る
/// </summary>
/// <param name="translate">移動</param>
/// <returns>平行移動行列を返却する</returns>
struct Matrix3x3 MakeTranslateMatrix(struct Vec2 translate)
{
	// 平行移動行列
	struct Matrix3x3 translateMatrix;

	translateMatrix.m[0][0] = 1.0f;
	translateMatrix.m[0][1] = 0.0f;
	translateMatrix.m[0][2] = 0.0f;

	translateMatrix.m[1][0] = 0.0f;
	translateMatrix.m[1][1] = 1.0f;
	translateMatrix.m[1][2] = 0.0f;
	
	translateMatrix.m[2][0] = translate.x;
	translateMatrix.m[2][1] = translate.y;
	translateMatrix.m[2][2] = 1.0f;

	return translateMatrix;
}

/// <summary>
/// ベクトルと行列の積を求める
/// </summary>
/// <param name="vec">ベクトル</param>
/// <param name="m1">行列</param>
/// <returns>ベクトルと行列の積を返却する</returns>
struct Vec2 Transform(struct Vec2 vec, struct Matrix3x3 m1)
{
	// ベクトルと行列の積
	struct Vec2 transform;

	transform.x = vec.x * m1.m[0][0] + vec.y * m1.m[1][0] + 1.0f * m1.m[2][0];
	transform.y = vec.x * m1.m[0][1] + vec.y * m1.m[1][1] + 1.0f * m1.m[2][1];
	float w = vec.x * m1.m[0][2] + vec.y * m1.m[1][2] + 1.0f * m1.m[2][2];

	assert(w != 0.0f);

	transform.x /= w;
	transform.y /= w;

	return transform;
}

/// <summary>
/// 行列の積を求める
/// </summary>
/// <param name="m1">行列1</param>
/// <param name="m2">行列2</param>
/// <returns>行列の積を返却する</returns>
struct Matrix3x3 Multiply(struct Matrix3x3 m1, struct Matrix3x3 m2)
{
	// 行列の積
	struct Matrix3x3 multiply;

	multiply.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0];
	multiply.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1];
	multiply.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2];

	multiply.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0];
	multiply.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1];
	multiply.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2];

	multiply.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0];
	multiply.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1];
	multiply.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2];

	return multiply;
}

/// <summary>
/// ワールド行列を作る
/// </summary>
/// <param name="radius">半径</param>
/// <param name="theta">角度</param>
/// <param name="translate">移動</param>
/// <returns>ワールド行列を返却する</returns>
struct Matrix3x3 MakeWorldMatrix(float radius, float theta, struct Vec2 translate)
{
	// ワールド行列
	struct Matrix3x3 worldMatrix;

	worldMatrix = Multiply(MakeScaleMatrix(radius), MakeRotateMatrix(theta));
	worldMatrix = Multiply(worldMatrix, MakeTranslateMatrix(translate));

	return worldMatrix;
}

/// <summary>
/// 逆行列を作る
/// </summary>
/// <param name="m1">行列</param>
/// <returns>逆行列を返却する</returns>
struct Matrix3x3 MakeInverseMatrix(struct Matrix3x3 m1)
{
	// 行列式
	float determinant = m1.m[0][0] * m1.m[1][1] * m1.m[2][2] + m1.m[0][1] * m1.m[1][2] * m1.m[2][0] + m1.m[0][2] * m1.m[1][0] * m1.m[2][1] -
		m1.m[0][2] * m1.m[1][1] * m1.m[2][0] - m1.m[0][1] * m1.m[1][0] * m1.m[2][2] - m1.m[0][0] * m1.m[1][2] * m1.m[2][1];

	// 余因子行列
	struct Matrix3x3 adjugateMatrix;

	adjugateMatrix.m[0][0] = m1.m[1][1] * m1.m[2][2] - m1.m[1][2] * m1.m[2][1];
	adjugateMatrix.m[0][1] = -(m1.m[0][1] * m1.m[2][2] - m1.m[0][2] * m1.m[2][1]);
	adjugateMatrix.m[0][2] = m1.m[0][1] * m1.m[1][2] - m1.m[0][2] * m1.m[1][1];

	adjugateMatrix.m[1][0] = -(m1.m[1][0] * m1.m[2][2] - m1.m[1][2] * m1.m[2][0]);
	adjugateMatrix.m[1][1] = m1.m[0][0] * m1.m[2][2] - m1.m[0][2] * m1.m[2][0];
	adjugateMatrix.m[1][2] = -(m1.m[0][0] * m1.m[1][2] - m1.m[0][2] * m1.m[1][0]);

	adjugateMatrix.m[2][0] = m1.m[1][0] * m1.m[2][1] - m1.m[1][1] * m1.m[2][0];
	adjugateMatrix.m[2][1] = -(m1.m[0][0] * m1.m[2][1] - m1.m[0][1] * m1.m[2][0]);
	adjugateMatrix.m[2][2] = m1.m[0][0] * m1.m[1][1] - m1.m[0][1] * m1.m[1][0];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			adjugateMatrix.m[i][j] *= (1.0f / determinant);
		}
	}

	return adjugateMatrix;
}

/// <summary>
/// 正射影行列を作る
/// </summary>
/// <param name="left">左</param>
/// <param name="top">上</param>
/// <param name="right">右</param>
/// <param name="bottom">下</param>
/// <returns>正射影行列を返却する</returns>
struct Matrix3x3 MakeOrthoMatrix(float left, float top, float right, float bottom)
{
	// 正射影行列
	struct Matrix3x3 orthoMatrix;

	orthoMatrix.m[0][0] = 2.0f / (right - left);
	orthoMatrix.m[0][1] = 0.0f;
	orthoMatrix.m[0][2] = 0.0f;

	orthoMatrix.m[1][0] = 0.0f;
	orthoMatrix.m[1][1] = 2.0f / (top - bottom);
	orthoMatrix.m[1][2] = 0.0f;

	orthoMatrix.m[2][0] = (left + right) / (left - right);
	orthoMatrix.m[2][1] = (top + bottom) / (bottom - top);
	orthoMatrix.m[2][2] = 1.0f;

	return orthoMatrix;
}

/// <summary>
/// ビューポート行列を作る
/// </summary>
/// <param name="left">左</param>
/// <param name="top">上</param>
/// <param name="width">横幅</param>
/// <param name="height">縦幅</param>
/// <returns>ビューポート行列を返却する</returns>
struct Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height)
{
	// ビューポート行列
	struct Matrix3x3 viewportMatrix;

	viewportMatrix.m[0][0] = width / 2.0f;
	viewportMatrix.m[0][1] = 0.0f;
	viewportMatrix.m[0][2] = 0.0f;

	viewportMatrix.m[1][0] = 0.0f;
	viewportMatrix.m[1][1] = -(height / 2.0f);
	viewportMatrix.m[1][2] = 0.0f;

	viewportMatrix.m[2][0] = left + (width / 2.0f);
	viewportMatrix.m[2][1] = top + (height / 2.0f);
	viewportMatrix.m[2][2] = 1.0f;

	return viewportMatrix;
}