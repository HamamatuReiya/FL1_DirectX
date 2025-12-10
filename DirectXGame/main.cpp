#include <Windows.h>
#include <KamataEngine.h>
#include "GameScene.h"
#include "TitleScene.h"
#include "ResultScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//最初に移すシーンの設定
	SceneType sceneNo = SceneType::kTitle;

	//エンジンの初期化
	KamataEngine::Initialize(L"FL1");

	TitleScene* titleScene = new TitleScene();
	titleScene->Initialize();

	//ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	//ゲームシーンの初期化
	gameScene->Initialize();

	ResultScene* resultScene = new ResultScene();
	resultScene->Initialize();

	//メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		//シーンごとの処理
		switch (sceneNo) {
		case SceneType::kTitle:
			titleScene->Update();
			if (titleScene->IsTitleEnd()) {
				//次のシーンの値を代入してシーン切り替え
				sceneNo = titleScene->NextScene();
				resultScene->Initialize();
			}
			break;
		case SceneType::kGamePlay:
			gameScene->Update();
			if (gameScene->IsGameEnd()) {
				//次のシーンの値を代入してシーン切り替え
				sceneNo = gameScene->NextScene();
				titleScene->Initialize();
			}
			break;
		case SceneType::kResult:
			resultScene->Update();
			if (resultScene->IsResultEnd()) {
				//次のシーンの値を代入してシーン切り替え
				sceneNo = resultScene->NextScene();
				gameScene->Initialize();
			}
			break;
		}

		//描画開始
		dxCommon->PreDraw();

		//ここに描画処理を記述する
		Sprite::PreDraw();
		switch (sceneNo) {
		case SceneType::kTitle:
			titleScene->Draw();
			break;
		case SceneType::kGamePlay:
			// GameScene 描画
			gameScene->Draw();
			break;
		case SceneType::kResult:
			resultScene->Draw();
			break;
		}

		// 描画終了
		dxCommon->PostDraw();
	}

	//ゲームシーンの解放
	delete gameScene;
	// nullptrの代入
	gameScene = nullptr;

	//エンジンの修了処理
	KamataEngine::Finalize();

	return 0;
}
