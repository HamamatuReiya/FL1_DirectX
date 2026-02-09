#include "Conveyer.h"
void Conveyer::Initialize(
    uint32_t uptextureHandle, Vector2 uppos, uint32_t downtextureHandle, Vector2 downpos, uint32_t lefttextureHandle, Vector2 leftpos, uint32_t righttextureHandle, Vector2 rightpos) {
	position_ = uppos;
	upSprite_ = Sprite::Create(
	    uptextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                         // アンカーポイント
	);
	position_ = downpos;
	downSprite_ = Sprite::Create(
	    downtextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                         // アンカーポイント
	);
	position_ = rightpos;
	rightSprite_ = Sprite::Create(
	    righttextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                         // アンカーポイント
	);
	position_ = leftpos;
	leftSprite_ = Sprite::Create(
	    lefttextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                         // アンカーポイント
	);
	upSprite_->SetSize(size_);
	downSprite_->SetSize(size_);
	rightSprite_->SetSize(size_);
	leftSprite_->SetSize(size_);


	/*upTexture_ = TextureManager::Load("Up.png");
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
	leftSprite_->SetSize({800.0f, 550.0f});*/

	
}
void Conveyer::Update() {

}
void Conveyer::Draw() { 
	if (upSprite_) {
		upSprite_->Draw();
	}
	if (downSprite_) {
		downSprite_->Draw();
	}
	if (rightSprite_) {
		rightSprite_->Draw();
	}
	if (leftSprite_) {
		leftSprite_->Draw();
	}
	//upSprite_->Draw();
	//downSprite_->Draw();
	//rightSprite_->Draw();
	//leftSprite_->Draw();
}