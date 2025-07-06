#include "stdafx.h"
#include "SceneMgr.h"
#include "TitleScene.h"
#include "SingleGame.h"
#include "MultiGame.h"

void SceneMgr::Init()
{
	/*scenes.push_back(new TitleScene());
	scenes.push_back(new SingleGame());
	scenes.push_back(new MultiGame());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();*/

	scenes.emplace(SceneIds::Title, new TitleScene());
	scenes.emplace(SceneIds::SingleGame, new SingleGame());
	scenes.emplace(SceneIds::MultiGame, new MultiGame());

	for (auto const& pair : scenes)
	{
		pair.second->Init();
	}

	currentScene = startScene;

	auto it = scenes.find(currentScene);
	if (it != scenes.end())
	{
		it->second->Enter();
	}
}

void SceneMgr::Release()
{
	/*for (auto scene : scenes)
	{
		if (scene->Id == currentScene)
		{
			scene->Exit();
		}
		scene->Release();
		delete scene;
	}
	scenes.clear();*/

	auto it = scenes.find(currentScene);
	if (it != scenes.end())
	{
		it->second->Exit();
	}
	for (auto const& pair : scenes)
	{
		pair.second->Release();
		delete pair.second;
	}
	scenes.clear();
}

Scene* SceneMgr::GetCurrentScene()
{
	auto it = scenes.find(currentScene);
	if (it != scenes.end()) {
		return it->second;
	}
	return nullptr;
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	/*if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}

	scenes[(int)currentScene]->Update(dt);*/

	if (nextScene != SceneIds::None)
	{
		auto currentIt = scenes.find(currentScene);
		if (currentIt != scenes.end()) {
			currentIt->second->Exit();
		}

		currentScene = nextScene;
		nextScene = SceneIds::None;

		auto newIt = scenes.find(currentScene);
		if (newIt != scenes.end()) {
			newIt->second->Enter();
		}
	}

	auto currentIt = scenes.find(currentScene);
	if (currentIt != scenes.end()) {
		currentIt->second->Update(dt);
	}
}


void SceneMgr::Draw(sf::RenderWindow& window)
{
	//scenes[(int)currentScene]->Draw(window);
	auto currentIt = scenes.find(currentScene);
	if (currentIt != scenes.end()) {
		currentIt->second->Draw(window);
	}

}
