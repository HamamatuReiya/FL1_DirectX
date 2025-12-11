#include "GameScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() { delete player_; }

void GameScene::Initialize() {
	input_ = KamataEngine::Input::GetInstance();
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	//テクスチャ
	uint32_t gameSprite = TextureManager::Load("Game.png");
	playSprite = Sprite::Create(gameSprite, { 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f });
	isPlaySceneEnd = false;

	player_ = new Player();
	playerTestModel_ = Model::Create();
	playerTexture_ = TextureManager::Load("uvChecker.png");
	player_->Initialize(playerTexture_);

	// Goal
	goalTexture_ = TextureManager::Load("goal.png"); // 任意のゴール画像
	goal_ = new Goal();
	goal_->Initialize(goalTexture_, {600, 360}); // 位置は自由
}

void GameScene::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		isPlaySceneEnd = true;
	}
	player_->Update();


	// Goal
	// プレイヤーとゴールの当たり判定
	Vector2 pPos = player_->GetPos();
	Vector2 pSize = player_->GetSize();

	Vector2 gPos = goal_->GetPos();
	Vector2 gSize = goal_->GetSize();

	// AABB collision
	bool hit = (pPos.x < gPos.x + gSize.x) && (pPos.x + pSize.x > gPos.x) && (pPos.y < gPos.y + gSize.y) && (pPos.y + pSize.y > gPos.y);

	if (hit) {
		isPlaySceneEnd = true;
	}


}

void GameScene::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる

	playSprite->Draw();
	
	// Goal
	goal_->Draw();

	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw();

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる

	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	
	player_->Draw();

	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
}

void GameScene::SceneReset() {}
