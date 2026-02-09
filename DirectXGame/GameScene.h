#pragma once
#include "Player.h"
#include "Scene.h"
#include "Conveyer.h"
#include <KamataEngine.h>
#include "Goal.h"

using namespace KamataEngine;

//ゲームシーン
class GameScene 
{
public:
	// コンストラクタ
	GameScene();
	// デストラクタ
	~GameScene();
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();
	// シーンリセット
	void SceneReset();

	//シーン切り替え用
	bool isPlaySceneEnd = false;
	bool IsGameEnd() { return isPlaySceneEnd; }
	SceneType NextScene() { return SceneType::kResult; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	Sprite* playSprite = nullptr;
	
	std::unique_ptr<Model> model_ = nullptr;

	// プレイヤー
	Player* player_ = nullptr;
	// プレイヤーテスト用モデル
	Model* playerTestModel_ = nullptr;
	// プレイヤーテスト用テクスチャー
	uint32_t playerTexture_ = 0;

	// Goal
	Goal* goal_ = nullptr;
	uint32_t goalTexture_ = 0;

	// Conveyer
	Conveyer* conveyer_ = nullptr;
	uint32_t upTexture_ = 0;
	uint32_t upTexture2_ = 0;
	uint32_t upTexture3_ = 0;
	uint32_t downTexture_ = 0;
	uint32_t downTexture2_ = 0;
	uint32_t downTexture3_ = 0;
	uint32_t leftTexture_ = 0;
	uint32_t leftTexture2_ = 0;
	uint32_t rightTexture_ = 0;
	uint32_t rightTexture2_ = 0;
};
