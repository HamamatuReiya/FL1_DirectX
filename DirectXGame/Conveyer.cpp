#include "Conveyer.h"
void Conveyer::Initialize() {
	uint32_t upSprite = TextureManager::Load("Up.png");
	up_ = Sprite::Create(upSprite, {800.0f, 400.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	uint32_t downSprite = TextureManager::Load("Down.png");
	down_ = Sprite::Create(downSprite, {800.0f, 450.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	uint32_t rightSprite = TextureManager::Load("Right.png");
	right_ = Sprite::Create(rightSprite, {800.0f, 500.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	uint32_t leftSprite = TextureManager::Load("Left.png");
	left_ = Sprite::Create(leftSprite, {800.0f, 550.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	
}
void Conveyer::Update() {

}
void Conveyer::Draw() { 
	//up_->Draw();
	//down_->Draw();
	//right_->Draw();
	//left_->Draw();
}