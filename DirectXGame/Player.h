#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Player 
{
public:
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();
	// 初期化
	void Initialize(uint32_t textureHandle);
	// 毎フレーム処理
	void Update();
	// 描画
	void Draw();

private:
	Input* input_ = nullptr;

	WorldTransform worldTransform_;

	Vector2 position_ = {0, 0};
	Vector2 size_ = {50, 50};

	Model* model_ = nullptr;
	Sprite* playerSprite_ = nullptr;
	uint32_t textureHandle_ = 0u;
	Player* player_ = nullptr;
};
