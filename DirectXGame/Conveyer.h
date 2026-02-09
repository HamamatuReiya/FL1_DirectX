#pragma once
#include <KamataEngine.h>
#include "Player.h"
using namespace KamataEngine;
class Conveyer {
public:
	// 初期化
	void Initialize(
		uint32_t uptextureHandle, Vector2 uppos,
		uint32_t uptextureHandle2, Vector2 uppos2, 
		uint32_t uptextureHandle3, Vector2 uppos3,
		uint32_t downtextureHandle, Vector2 downpos,
	    uint32_t downtextureHandle2, Vector2 downpos2, 
		uint32_t downtextureHandle3, Vector2 downpos3,
		uint32_t lefttextureHandle, Vector2 leftpos, 
		uint32_t lefttextureHandle2, Vector2 leftpos2,
		uint32_t righttextureHandle, Vector2 rightpos,
		uint32_t righttextureHandle2, Vector2 rightpos2);
	// 更新処理
	void Update(Player* player);
	// 描画
	void Draw();

	// 当たり判定用に位置とサイズを返す
	Vector2 GetPos() { return position_; }
	Vector2 GetSize() { return size_; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Vector2 position_;
	Vector2 size_ = {50, 50};

	Sprite* upSprite_ = nullptr;
	Sprite* upSprite2_ = nullptr;
	Sprite* upSprite3_ = nullptr;

	Sprite* downSprite_ = nullptr;
	Sprite* downSprite2_ = nullptr;
	Sprite* downSprite3_ = nullptr;

	Sprite* leftSprite_ = nullptr;
	Sprite* leftSprite2_ = nullptr;

	Sprite* rightSprite_ = nullptr;
	Sprite* rightSprite2_ = nullptr;
};
