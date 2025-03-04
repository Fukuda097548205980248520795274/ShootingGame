#include "Vector.h"

/// <summary>
/// ベクトルを正規化する
/// </summary>
/// <param name="vec">ベクトル</param>
void Normalize(struct Vec2* vec)
{
	// null を探す
	if (vec == nullptr)
	{
		return;
	}

	// 距離
	float length = sqrtf(powf(vec->x, 2) + powf(vec->y, 2));

	if (length != 0.0f)
	{
		vec->x = vec->x / length;
		vec->y = vec->y / length;
	}
}