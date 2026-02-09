#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;
class Conveyer {
public:
	// 初期化
	void Initialize(
		uint32_t uptextureHandle, Vector2 uppos, 
		uint32_t downtextureHandle, Vector2 downpos, 
		uint32_t lefttextureHandle, Vector2 leftpos, 
		uint32_t righttextureHandle, Vector2 rightpos);
	// 更新処理
	void Update();
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

	Sprite* downSprite_ = nullptr;

	Sprite* leftSprite_ = nullptr;

	Sprite* rightSprite_ = nullptr;
};
