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
	Sprite* up_ = nullptr;
	Sprite* down_ = nullptr;
	Sprite* left_ = nullptr;
	Sprite* right_ = nullptr;
};
