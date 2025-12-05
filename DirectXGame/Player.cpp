#include "Player.h"
Player::Player() {}
Player::~Player() {}

void Player::Initialize(uint32_t textureHandle) {
	input_ = Input::GetInstance();
	playerSprite_ = Sprite::Create(textureHandle, {300, 360});
	playerSprite_->SetSize(size_);
	position_ = {300, 360};
}

void Player::Update() {
	const float kMoveSpeed = 3.0f;
	if (input_->PushKey(DIK_W)) {
		position_.y -= kMoveSpeed;
	}
	if (input_->PushKey(DIK_S)) {
		position_.y += kMoveSpeed;
	}
	if (input_->PushKey(DIK_A)) {
		position_.x -= kMoveSpeed;
	}
	if (input_->PushKey(DIK_D)) {
		position_.x += kMoveSpeed;
	}
}

void Player::Draw() { playerSprite_->Draw(); }