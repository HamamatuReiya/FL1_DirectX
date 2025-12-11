#include "Goal.h"

void Goal::Initialize(uint32_t textureHandle, Vector2 pos) {
	position_ = pos;
	sprite_ = Sprite::Create(
	    textureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {0.0f, 0.0f}                                                         // アンカーポイント
	);

	sprite_->SetSize(size_);
}

void Goal::Update() {
	// 特に動かない場合は空
}

void Goal::Draw() { sprite_->Draw(); }
