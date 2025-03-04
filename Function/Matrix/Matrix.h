#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include "Structure.h"
#include "Constant.h"

/// <summary>
/// 拡大縮小行列を作る
/// </summary>
/// <param name="radius">半径</param>
/// <returns>拡大縮小行列を返却する</returns>
struct Matrix3x3 MakeScaleMatrix(float radius);

/// <summary>
/// 回転行列を作る
/// </summary>
/// <param name="theta">角度</param>
/// <returns>回転行列を返却する</returns>
struct Matrix3x3 MakeRotateMatrix(float theta);

/// <summary>
/// 平行移動行列を作る
/// </summary>
/// <param name="translate">移動</param>
/// <returns>平行移動行列を返却する</returns>
struct Matrix3x3 MakeTranslateMatrix(struct Vec2 translate);

/// <summary>
/// ベクトルと行列の積を求める
/// </summary>
/// <param name="vec">ベクトル</param>
/// <param name="m1">行列</param>
/// <returns>ベクトルと行列の積を返却する</returns>
struct Vec2 Transform(struct Vec2 vec, struct Matrix3x3 m1);

/// <summary>
/// 行列の積を求める
/// </summary>
/// <param name="m1">行列1</param>
/// <param name="m2">行列2</param>
/// <returns>行列の積を返却する</returns>
struct Matrix3x3 Multiply(struct Matrix3x3 m1, struct Matrix3x3 m2);

/// <summary>
/// ワールド行列を作る
/// </summary>
/// <param name="radius">半径</param>
/// <param name="theta">角度</param>
/// <param name="translate">移動</param>
/// <returns>ワールド行列を返却する</returns>
struct Matrix3x3 MakeWorldMatrix(float radius, float theta, struct Vec2 translate);

/// <summary>
/// 逆行列を作る
/// </summary>
/// <param name="m1">行列</param>
/// <returns>逆行列を返却する</returns>
struct Matrix3x3 MakeInverseMatrix(struct Matrix3x3 m1);

/// <summary>
/// 正射影行列を作る
/// </summary>
/// <param name="left">左</param>
/// <param name="top">上</param>
/// <param name="right">右</param>
/// <param name="bottom">下</param>
/// <returns>正射影行列を返却する</returns>
struct Matrix3x3 MakeOrthoMatrix(float left, float top, float right, float bottom);

/// <summary>
/// ビューポート行列を作る
/// </summary>
/// <param name="left">左</param>
/// <param name="top">上</param>
/// <param name="width">横幅</param>
/// <param name="height">縦幅</param>
/// <returns>ビューポート行列を返却する</returns>
struct Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);