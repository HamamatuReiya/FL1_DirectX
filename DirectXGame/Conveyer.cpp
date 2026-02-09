#include "Conveyer.h"
void Conveyer::Initialize() {
	upTexture_ = TextureManager::Load("Up.png");
	upSprite_ = Sprite::Create(upTexture_, {50, 50});
	upSprite_->SetSize({800.0f, 400.0f});

	downTexture_ = TextureManager::Load("Up.png");
	downSprite_ = Sprite::Create(downTexture_, {50, 50});
	downSprite_->SetSize({800.0f, 450.0f});

	rightTexture_ = TextureManager::Load("Up.png");
	rightSprite_ = Sprite::Create(rightTexture_, {50, 50});
	rightSprite_->SetSize({800.0f, 500.0f});

	leftTexture_ = TextureManager::Load("Up.png");
	leftSprite_ = Sprite::Create(leftTexture_, {50, 50});
	leftSprite_->SetSize({800.0f, 550.0f});

	
}
void Conveyer::Update() {

}
void Conveyer::Draw() { 
	//upSprite_->Draw();
	//downSprite_->Draw();
	//rightSprite_->Draw();
	//leftSprite_->Draw();
}