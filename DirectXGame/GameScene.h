#pragma once
#include "KamataEngine.h"
#include "Scene.h"
using namespace KamataEngine;

//ゲームシーン
class GameScene 
{
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	//シーン切り替え用
	bool isPlaySceneEnd = false;
	bool IsGameEnd() { return isPlaySceneEnd; }
	SceneType NextScene() { return SceneType::kResult; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Sprite* playSprite = nullptr;
};
