#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;
class Conveyer {
public:
	// 初期化
	void Initialize();
	// 更新処理
	void Update();
	// 描画
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	uint32_t upTexture_ = 0;
	Sprite* upSprite_ = nullptr;

	uint32_t downTexture_ = 0;
	Sprite* downSprite_ = nullptr;

	uint32_t rightTexture_ = 0;
	Sprite* leftSprite_ = nullptr;

	uint32_t leftTexture_ = 0;
	Sprite* rightSprite_ = nullptr;
};
