#pragma once
#include "Player.h"
#include <KamataEngine.h>

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

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// プレイヤー
	Player* player_ = nullptr;
	// プレイヤーテスト用モデル
	Model* playerTestModel_ = nullptr;
	// プレイヤーテスト用テクスチャー
	uint32_t playerTexture_ = 0;
};
