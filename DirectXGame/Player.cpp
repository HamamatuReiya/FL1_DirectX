#include "Player.h"
Player::Player() {}
Player::~Player() {}

void Player::Initialize(uint32_t textureHandle) {
	input_ = Input::GetInstance();
	playerSprite_ = Sprite::Create(textureHandle, {300, 360});
	playerSprite_->SetSize(size_);
	position_ = {300, 360};
	worldTransform_.Initialize();
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
	if (position_.x <= size_.x / 2) {
		position_.x = size_.x / 2;
	}
	if (position_.x >= 1280 - size_.x / 2) {
		position_.x = 1280 - size_.x / 2;
	}
	if (position_.y <= size_.x / 2) {
		position_.y = size_.x / 2;
	}
	if (position_.y >= 720 - size_.x / 2) {
		position_.y = 720 - size_.x / 2;
	}
	playerSprite_->SetPosition({position_.x - 48.0f, position_.y - 48.0f});
}

void Player::Draw() { 
	playerSprite_->Draw();
	}