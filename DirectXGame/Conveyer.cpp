#include "Conveyer.h"
void Conveyer::Initialize(
    uint32_t uptextureHandle, Vector2 uppos, 
	uint32_t uptextureHandle2, Vector2 uppos2, 
	uint32_t uptextureHandle3, Vector2 uppos3,
	uint32_t downtextureHandle, Vector2 downpos,
    uint32_t downtextureHandle2, Vector2 downpos2,
	uint32_t downtextureHandle3, Vector2 downpos3,
	uint32_t lefttextureHandle, Vector2 leftpos,
	uint32_t lefttextureHandle2, Vector2 leftpos2,
    uint32_t righttextureHandle, Vector2 rightpos,
	uint32_t righttextureHandle2, Vector2 rightpos2)
{
	position_ = uppos;
	upSprite_ = Sprite::Create(
	    uptextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                         // アンカーポイント
	);
	position_ = uppos2;
	upSprite2_ = Sprite::Create(
	    uptextureHandle2, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                           // アンカーポイント
	);
	position_ = uppos3;
	upSprite3_ = Sprite::Create(
	    uptextureHandle3, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                            // アンカーポイント
	);
	position_ = downpos;
	downSprite_ = Sprite::Create(
	    downtextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                         // アンカーポイント
	);
	position_ = downpos2;
	downSprite2_ = Sprite::Create(
	    downtextureHandle2, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                             // アンカーポイント
	);
	position_ = downpos3;
	downSprite3_ = Sprite::Create(
	    downtextureHandle3, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                             // アンカーポイント
	);
	position_ = leftpos;
	leftSprite_ = Sprite::Create(
	    lefttextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                         // アンカーポイント
	);
	position_ = leftpos2;
	leftSprite2_ = Sprite::Create(
	    lefttextureHandle2, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                             // アンカーポイント
	);
	position_ = rightpos;
	rightSprite_ = Sprite::Create(
	    righttextureHandle, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                              // アンカーポイント
	);
	position_ = rightpos2;
	rightSprite2_ = Sprite::Create(
	    righttextureHandle2, {position_.x, position_.y}, {1.0f, 1.0f, 1.0f, 1.0f}, // 色
	    {1.0f, 1.0f}                                                              // アンカーポイント
	);
	upSprite_->SetSize(size_);
	upSprite2_->SetSize(size_);
	upSprite3_->SetSize(size_);
	downSprite_->SetSize(size_);
	downSprite2_->SetSize(size_);
	downSprite3_->SetSize(size_);
	leftSprite_->SetSize(size_);
	leftSprite2_->SetSize(size_);
	rightSprite_->SetSize(size_);
	rightSprite2_->SetSize(size_);
	
}
void Conveyer::Update(Player* player) {

	Vector2 pPos = player->GetPos();
	Vector2 pSize = player->GetSize();

	// 共通当たり判定
	auto check = [&](Sprite* s, Vector2 move) {
		if (!s)
			return;

		Vector2 cPos = s->GetPosition();

		bool hit = (pPos.x < cPos.x + size_.x) && (pPos.x + pSize.x > cPos.x) && (pPos.y < cPos.y + size_.y) && (pPos.y + pSize.y > cPos.y);

		// 乗っている間ずっと移動
		if (hit) {
			player->AddPos(move);
		}
	};

	// 上コンベア
	check(upSprite_, {0.0f, -1.0f});
	check(upSprite2_, {0.0f, -1.0f});
	check(upSprite3_, {0.0f, -1.0f});

	// 下コンベア
	check(downSprite_, {0.0f, 1.0f});
	check(downSprite2_, {0.0f, 1.0f});
	check(downSprite3_, {0.0f, 1.0f});

	// 左コンベア
	check(leftSprite_, {-1.0f, 0.0f});
	check(leftSprite2_, {-1.0f, 0.0f});

	// 右コンベア
	check(rightSprite_, {1.0f, 0.0f});
	check(rightSprite2_, {1.0f, 0.0f});
}

void Conveyer::Draw() { 
	if (upSprite_) {
		upSprite_->Draw();
	}
	if (upSprite2_) {
		upSprite2_->Draw();
	}
	if (upSprite3_) {
		upSprite3_->Draw();
	}

	if (downSprite_) {
		downSprite_->Draw();
	}
	if (downSprite2_) {
		downSprite2_->Draw();
	}
	if (downSprite3_) {
		downSprite3_->Draw();
	}

	if (leftSprite_) {
		leftSprite_->Draw();
	}
	if (leftSprite2_) {
		leftSprite2_->Draw();
	}

	if (rightSprite_) {
		rightSprite_->Draw();
	}
	if (rightSprite2_) {
		rightSprite2_->Draw();
	}
}