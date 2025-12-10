#include "ResultScene.h"
void ResultScene::Initialize() {
	input_ = KamataEngine::Input::GetInstance();
	//テクスチャ
	uint32_t resultSceneSprite = TextureManager::Load("Result.png");
	resultScene = Sprite::Create(resultSceneSprite, { 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f });

	isResultSceneEnd = false;


}

void ResultScene::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		isResultSceneEnd = true;
	}
}

void ResultScene::Draw() {
	resultScene->Draw();
}