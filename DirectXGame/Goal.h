#pragma once
#include <KamataEngine.h>
using namespace KamataEngine;

class Goal {
public:
	void Initialize(uint32_t textureHandle, Vector2 pos);
	void Update();
	void Draw();

	// 当たり判定用に位置とサイズを返す
	Vector2 GetPos() { return position_; }
	Vector2 GetSize() { return size_; }

private:
	Sprite* sprite_ = nullptr;
	Vector2 position_;
	Vector2 size_ = {50, 50}; // ゴールの大きさ（変更可）
};
