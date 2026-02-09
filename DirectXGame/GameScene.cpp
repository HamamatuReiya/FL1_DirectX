#include "GameScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete player_;
	delete conveyer_;
}

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
	playerTexture_ = TextureManager::Load("player.png");
	player_->Initialize(playerTexture_);

	// Goal
	goalTexture_ = TextureManager::Load("goal.png"); // 任意のゴール画像
	goal_ = new Goal();
	goal_->Initialize(goalTexture_, {800, 350}); // 位置は自由

	//conveyer
	upTexture_ = TextureManager::Load("up.png");
	upTexture2_ = TextureManager::Load("up.png");
	upTexture3_ = TextureManager::Load("up.png");
	downTexture_ = TextureManager::Load("down.png");
	downTexture2_ = TextureManager::Load("down.png");
	downTexture3_ = TextureManager::Load("down.png");
	leftTexture_ = TextureManager::Load("left.png");
	leftTexture2_ = TextureManager::Load("left.png");
	leftTexture3_ = TextureManager::Load("left.png");
	rightTexture_ = TextureManager::Load("right.png");
	rightTexture2_ = TextureManager::Load("right.png");
	conveyer_ = new Conveyer();
	conveyer_->Initialize(
		upTexture_, {800, 400},
		upTexture2_, {800, 450},
		upTexture3_, {850, 350},
		downTexture_, {700, 300},
		downTexture_, {700, 350},
		downTexture_, {700, 400},
		leftTexture_, {750, 300},
		leftTexture2_, {800, 300}, 
		leftTexture3_, {850, 300},
		rightTexture_, {750, 450},
		rightTexture2_, {700, 450}
	);

}

void GameScene::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		//isPlaySceneEnd = true;
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
	// コンベア処理
	conveyer_->Update(player_);

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
	
	conveyer_->Draw();
	player_->Draw();

	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
}

void GameScene::SceneReset() {}
