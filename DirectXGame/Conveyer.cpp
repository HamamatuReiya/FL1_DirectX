#include "Conveyer.h"
void Conveyer::Initialize() {
	input_ = KamataEngine::Input::GetInstance();
	uint32_t upSprite = TextureManager::Load("Up.png");
	up = Sprite::Create(upSprite, {800.0f, 400.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	uint32_t downSprite = TextureManager::Load("Down.png");
	down = Sprite::Create(downSprite, {800.0f, 450.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	uint32_t rightSprite = TextureManager::Load("Right.png");
	right = Sprite::Create(rightSprite, {800.0f, 500.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	uint32_t leftSprite = TextureManager::Load("Left.png");
	left = Sprite::Create(leftSprite, {800.0f, 550.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	
}
void Conveyer::Update() {

}
void Conveyer::Up() {

}
void Conveyer::Down() {

}
void Conveyer::Left() {

}
void Conveyer::Right() {

}
void Conveyer::Draw() { 
	//up->Draw();
	//down->Draw();
	//right->Draw();
	//left->Draw();
}