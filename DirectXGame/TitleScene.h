#pragma once
#include "Scene.h"
#include "KamataEngine.h"
using namespace KamataEngine;

class TitleScene{
public:

	//初期化
	void Initialize();
	//更新処理
	void Update();
	//描画
	void Draw();
	// シーンリセット
	void SceneReset();

	//シーン切り替え用
	bool isTitleSceneEnd = false;
	bool IsTitleEnd() { return isTitleSceneEnd; }
	SceneType NextScene() { return SceneType::kGamePlay; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	Sprite* titleScene_ = nullptr;
	Sprite* tutorial_ = nullptr;
	bool isTutorial_ = false;

	// 音
	uint32_t gameBgmHandle_;
	uint32_t playGameBgm_;
};

