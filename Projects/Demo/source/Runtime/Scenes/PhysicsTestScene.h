#pragma once
#include <EtCore/Helper/Hash.h>
#include <EtCore/Content/AssetPointer.h>

#include <EtFramework/SceneGraph/AbstractScene.h>


class TexPBRMaterial;
class EmissiveMaterial;
class SpriteFont;
class btCollisionShape;
class AudioSourceComponent;
class LightComponent;


class PhysicsTestScene : public AbstractScene
{
public:
	PhysicsTestScene();
	virtual ~PhysicsTestScene();
private:
	void Initialize();
	void Update();
	void Draw();
	void DrawForward() {}
	void PostDraw() {}
private:
	TexPBRMaterial* m_pFloorMat = nullptr;
	TexPBRMaterial* m_pBallMat = nullptr;
	TexPBRMaterial* m_pBlockMat = nullptr;

	EmissiveMaterial* m_pLightMat = nullptr;

	btCollisionShape* m_pSphereShape = nullptr;
	float m_SphereSize = 0.2f;
	float m_SphereForce = 30;
	float m_SphereMass = 3;

	float m_BlockMass = 0.2f;

	std::vector<T_Hash> m_AudioIdPlaylist;
	size_t m_CurrentTrack = 0u;
	AudioSourceComponent* m_Source;
	LightComponent* m_Light = nullptr;
	vec3 m_LightCentralPos = vec3(0);
	float m_LightRotDistance = 1.f;

	AssetPtr<SpriteFont> m_DebugFont;
};