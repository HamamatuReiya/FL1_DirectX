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
	void Up();
	void Down();
	void Left();
	void Right();
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Sprite* up = nullptr;
	Sprite* down = nullptr;
	Sprite* left = nullptr;
	Sprite* right = nullptr;
};
