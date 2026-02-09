#include "TitleScene.h"

void TitleScene::Initialize() {
	input_ = KamataEngine::Input::GetInstance();
	audio_ = Audio::GetInstance();
	//テクスチャ
	uint32_t titleSceneSprite = TextureManager::Load("Title.png");
	titleScene_ = Sprite::Create(titleSceneSprite, { 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f });

	uint32_t tutorialSprite = TextureManager::Load("tutorial.png");
	tutorial_ = Sprite::Create(tutorialSprite, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	
	// サウンド読み込み
	gameBgmHandle_ = audio_->LoadWave("gameplay.mp3");
	playGameBgm_ = audio_->PlayWave(gameBgmHandle_, true, 0.5f);
}

void TitleScene::Update() {
	if (input_->TriggerKey(DIK_SPACE) && isTutorial_ == true) {
		isTitleSceneEnd = true;
	}
	if (input_->TriggerKey(DIK_SPACE)) {
		isTutorial_ = true;
	}
}

void TitleScene::Draw() {
	titleScene_->Draw();
	if (isTutorial_ == true) {
		tutorial_->Draw();
	}
}

void TitleScene::SceneReset() {
	isTitleSceneEnd = false;
	isTutorial_ = false;
}