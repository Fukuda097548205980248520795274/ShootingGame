#include "Player.h"

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
{
	// 図形
	shape_.radius = 8.0f;
	shape_.theta = 0.0f;
	shape_.translate = { static_cast<float>(kScreenWidth / 2) , static_cast<float>(kScreenHeight / 3)};

	// 位置
	pos_.local = { {-1.0f , 1.0f} , {1.0f , 1.0f} , {-1.0f , -1.0f} , {1.0f , -1.0f} };
	LocalToScreen();

	// ベクトル
	vec_ = { 0.0f , 0.0f };

	// 移動速度
	vel_ = { 4.0f , 4.0f };
}

/// <summary>
/// 操作する
/// </summary>
/// <param name="keys">キー</param>
/// <param name="preKeys">前のキー</param>
void Player::Operation(const char* keys, const char* preKeys)
{
	// null を探す
	if (keys == nullptr || preKeys == nullptr)
	{
		return;
	}


	/*   移動   */

	// ベクトルを初期化する
	vec_ = { 0.0f , 0.0f };

	// Wキーで、上に移動する
	if (keys[DIK_W])
	{
		if (shape_.translate.y + shape_.radius < static_cast<float>(kScreenHeight))
		{
			vec_.y = 1.0f;
		}
	}

	// Aキーで、左に移動する
	if (keys[DIK_A])
	{
		if (shape_.translate.x - shape_.radius > 0.0f)
		{
			vec_.x = -1.0f;
		}
	}

	// Sキーで、下に移動する
	if (keys[DIK_S])
	{
		if (shape_.translate.y - shape_.radius > 0.0f)
		{
			vec_.y = -1.0f;
		}
	}

	// Dキーで、右に移動する
	if (keys[DIK_D])
	{
		if (shape_.translate.x + shape_.radius < static_cast<float>(kScreenWidth))
		{
			vec_.x = 1.0f;
		}
	}

	// ベクトルを正規化する
	Normalize(&vec_);

	// 動かす
	shape_.translate.x += vec_.x * vel_.x;
	shape_.translate.y += vec_.y * vel_.y;
	LocalToScreen();
}

/// <summary>
/// 描画する
/// </summary>
void Player::Draw()
{
	int ghWhite = Novice::LoadTexture("./NoviceResources/white1x1.png");

	Novice::DrawQuad
	(
		static_cast<int>(pos_.screen.leftTop.x), static_cast<int>(pos_.screen.leftTop.y),
		static_cast<int>(pos_.screen.rightTop.x), static_cast<int>(pos_.screen.rightTop.y),
		static_cast<int>(pos_.screen.leftBottom.x), static_cast<int>(pos_.screen.leftBottom.y),
		static_cast<int>(pos_.screen.rightBottom.x), static_cast<int>(pos_.screen.rightBottom.y),
		0, 0, 1, 1, ghWhite, 0xFFFFFFFF
	);
}