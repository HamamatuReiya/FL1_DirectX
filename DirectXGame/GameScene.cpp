#include "GameScene.h"
using namespace KamataEngine;

void GameScene::Initialize() {
	input_ = KamataEngine::Input::GetInstance();

	//テクスチャ
	uint32_t gameSprite = TextureManager::Load("Game.png");
	playSprite = Sprite::Create(gameSprite, { 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f });
	isPlaySceneEnd = false;
}

void GameScene::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		isPlaySceneEnd = true;
	}

}

void GameScene::Draw() {
	playSprite->Draw();
}
