#pragma once
#include "KamataEngine.h"
#include "Scene.h"
using namespace KamataEngine;
#include "Player.h"

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

	//シーン切り替え用
	bool isPlaySceneEnd = false;
	bool IsGameEnd() { return isPlaySceneEnd; }
	SceneType NextScene() { return SceneType::kResult; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Sprite* playSprite = nullptr;
	// シーンリセット
	void SceneReset();
	Audio* audio_ = nullptr;
	std::unique_ptr<Model> model_ = nullptr;

	// プレイヤー
	Player* player_ = nullptr;
	// プレイヤーテスト用モデル
	Model* playerTestModel_ = nullptr;
	// プレイヤーテスト用テクスチャー
	uint32_t playerTexture_ = 0;
};
