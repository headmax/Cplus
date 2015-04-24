#pragma once


//   typedef eastl::allocator eastl_arena_allocator;
#define EASTLDummyAllocatorType
namespace eastl
{
	template<typename T> class BasicArray
	{
	public:
		T* mpBegin;
	};
}

template<typename T> class Array : eastl::BasicArray<T>
{

};

template<typename T> class WeakToken
{
public:
	T* m_RealPtr; //0x0000
};//Size=0x0008

template<typename T> class ConstWeakPtr
{
public:
	WeakToken<T>* m_Token; //0x0000

	T* Get()
	{
		if (m_Token && m_Token->m_RealPtr)
		{
			DWORD_PTR realPtr = (DWORD_PTR)m_Token->m_RealPtr;
			return (T*)(realPtr - sizeof(DWORD_PTR));
		}
		return NULL;
	}
};//Size=0x0008

template<typename T> class WeakPtr : public ConstWeakPtr<T>
{
};//Size=0x0008

	template<typename T> class Array : public eastl::BasicArray<T>
	{
	};//Size=0x0008

		struct Guid
		{
			unsigned long m_Data1; //0x0000
			unsigned short m_Data2; //0x0004
			unsigned short m_Data3; //0x0006
			unsigned char m_Data4[8]; //0x0008
		};//Size=0x0010

		struct Color32
		{
			union
			{
				struct
				{
					unsigned char m_R; //0x0000
					unsigned char m_G; //0x0001
					unsigned char m_B; //0x0002
					unsigned char m_A; //0x0003
				};

				unsigned int m_Data; //0x0000
			};

			Color32(unsigned char r1, unsigned char g1, unsigned char b1, unsigned char a1);
			Color32(unsigned int col);
		};//Size=0x0004

		template<class T> class Tuple2
		{
		public:
			T m_Element1;
			T m_Element2;

			Tuple2(T element1, T element2)
			{
				m_Element1 = element1;
				m_Element2 = element2;
			}
		};//Size=2*T

//#include "FrostbiteGeneral.h"
#include "FrostbiteEnumDump.h"


namespace fb
{
class DataContainer;
class Asset;
class WebBrowserLocalURLAsset;
class LevelDescriptionComponent;
class SystemSettings;
class GameDataContainer;
class DataBusPeer;
class GameObjectData;
class ComponentData;
class EntityData;
class WaterEffectSetup;
class EntityBusPeer;
class Entity;
class Component;
class SpatialEntity;
class PhysicsComponent;
class ComponentEntity;
class WaterInteractTurbulenceDisturbEntity;
class VoipEntityData;
class VoipEntity;
class ToolData;
class GameComponentData;
class WeaponModifierBase;
class WeaponSwayData;
class GunSwayModifierData;
class CameraRecoilData;
class WeaponLagEntityData;
class WeaponStateData1p;
class SoldierWeaponBlueprintPipelineSettings;
class ExplosionPackTrigger;
class SpatialEntityData;
class SharedBundleBaseAsset;
class SocketObjectDataBase;
class WeaponSocketObjectData;
class WeaponSkinnedSocketObjectData;
class CustomWeaponTypeModifier;
class WeaponZoomLevelModifier;
class WeaponZoomModifier;
class WeaponClassModifier;
class WeaponAnimatedFireTypeModifier;
class WeaponAnimTypeModifier;
class WeaponAnimationConfigurationModifier;
class ComponentEntityData;
class GameComponentEntityData;
class GamePhysicsEntityData;
class WeaponData;
class SupplyUnitSphereData;
class HealingSupplyUnitSphereData;
class AmmoSupplyUnitSphereData;
class WeaponAimingSimulationModifier;
class SoldierAimingSimulationData;
class ZoomLevelData;
class SoldierAimAssistData;
class ThrowAtTargetWeaponData;
class MeleeWeaponData;
class FlashlightWeaponData;
class DefibrillatorWeaponData;
class PowerToolWeaponData;
class RepairToolWeaponData;
class MedicBagHealingSphereWeaponData;
class MedkitWeaponData;
class DetonatedWeaponData;
class ProjectileEntityData;
class HealthComponentData;
class PhysicsComponentData;
class MeshProjectileEntityData;
class ExplosionPackRemoteDetonatorTrigger;
class ExplosionPackInfantryTrigger;
class ExplosionPackVehicleRayTrigger;
class ExplosionPackVehicleProximityTrigger;
class ExplosionPackTripwireTrigger;
class GameHealthComponentData;
class GamePhysicsComponentData;
class WeaponEntityData;
class WeaponZoomLevelData;
class WeaponOverrideData;
class SoldierWeaponData;
class SoldierWeaponsComponentData;
class FirstPersonCameraData;
class WeaponLagSpringEffectData;
class WeaponSpeedData;
class WeaponOffsetData;
class AimerModifierData;
class DataContainerPolicyAsset;
class UnlockAssetBase;
class UnlockUserDataBase;
class TriggerEntityData;
class TriggerEventEntityData;
class CustomizeBaseEntityData;
class SoldierSpawnAppearanceTemplateData;
class SoldierSpawnKitTemplateData;
class SoldierWeaponSwitchingData;
class ControllableHealthComponentData;
class ControllablePhysicsComponentData;
class CustomizeCharacterData;
class SoldierSettings;
class ControllableEntityData;
class SoldierHealthModuleData;
class BreathControlData;
class CollisionData;
class SoldierWeaponOverrideData;
class SoldierSprintSettingsData;
class SoldierHeadCollisionData;
class SoldierAutoAimData;
class CharacterSoundData;
class SoldierAimingConstraintsData;
class PickupPhysicsComponentData;
class PickupEntityData;
class PickupEntityAsset;
class KitPickupEntityData;
class WeaponUnlockPickupEntityData;
class DynamicWeaponPickupEntityData;
class WeaponStateEntityData;
class StateEventGateEntityData;
class CoverPrepareFireEntityData;
class PlayerLookAtEntityData;
class HitReactionComponentData;
class BlockAimAssistEntityData;
class CharacterCustomizationAsset;
class SoldierWeaponSocketObjectData;
class CoverPeekEntityData;
class BlockAimAssistComponentData;
class EntryAimAssistTargetOptionsComponentData;
class AimAssistNodeSnapPointComponentData;
class AimAssistNodeComponentData;
class SoldierBreathControlComponentData;
class CharacterCustomizationComponentData;
class CharacterSocketListAsset;
class SocketData;
class WeaponRegularSocketObjectData;
class MovementComponentData;
class CharacterCameraComponentData;
class SoldierBodyComponentData;
class BoneCollisionComponentData;
class EntryComponentData;
class DataBusData;
class EntityBusData;
class Blueprint;
class ObjectBlueprint;
class GameComponent;
class ClientGamePhysicsComponent;
class HealthComponent;
class ClientGameComponent;
class ClientCharacterCameraComponent;
class TargetCameraCallback;
class ClientSoldierBreathControlComponent;
class ClientSoldierBodyComponent;
class ClientRagdollComponent;
class ClientPickupPhysicsComponent;
class ClientPhantomComponent;
class ClientMovementComponent;
class ClientHitReactionComponent;
class ClientFaceposerComponent;
class ClientBoneCollisionComponent;
class ClientBlockAimAssistComponent;
class ClientEntryAimAssistTargetOptionsComponent;
class ClientAimAssistNodeSnapPointComponent;
class ClientAimAssistNodeComponent;
class ClientWeaponLagEntity;
class ClientCoverPeekEntity;
class Tool;
class GameComponentEntity;
class ClientSoldierGripComponent;
class ClientAnimationTurretRotationComponent;
class ClientGameComponentEntity;
class ClientPhysicsEntity;
class ClientProjectileEntity;
class ClientGhostProjectileEntity;
class ClientGrenadeEntity;
class ClientFlareEntity;
class ClientExplosionPackEntity;
class ClientMissilePhysicsComponent;
class ClientExplosionPackPhysicsComponent;
class ClientEntryComponent;
class ClientRemoteEntryComponent;
class ClientWeaponZeroingComponent;
class ServerGameComponent;
class ServerEntryComponent;
class ServerWeaponZeroingComponent;
class ServerSoldierWeaponsComponent;
class ServerGamePhysicsComponent;
class ServerGameHealthComponent;
class ServerCharacterCustomizationComponent;
class ServerSoldierCameraComponent;
class ServerSoldierBodyComponent;
class ServerRagdollComponent;
class ServerPickupPhysicsComponent;
class ServerMovementComponent;
class ServerHitReactionComponent;
class ServerBoneCollisionComponent;
class ServerStateEventGateEntity;
class ServerCustomizeSoldierEntity;
class ServerGameComponentEntity;
class ServerPhysicsEntity;
class ServerPickupEntity;
class Weapon;
class ServerSoldierWeapon;
class ServerSoldierGripComponent;
class ServerAnimationTurretRotationComponent;
class ServerProjectileEntity;
class ServerGhostProjectileEntity;
class ServerMissilePhysicsComponent;
class ServerMissileHealthComponent;
class ServerExplosionPackPhysicsComponent;
class ServerExplosionPackHealthComponent;
class ClientWeaponStateEntity;
class ClientPlayerLookAtEntity;
class ClientTripwireEntity;
class ClientControllableEntity;
class ClientPickupEntity;
class ClientBlockAimAssistEntity;
class ServerTriggerEntity;
class ServerCharacterStateTriggerEntity;
class ServerWeaponStateEntity;
class WaypointData;
class RailRideHeliSegmentData;
class RailRideNodeHeliData;
class RailRideNodePointToData;
class RailRideHeliData;
class RailRideHeliSegment;
class ServerRailRideHeliEntity;
class ClientRailRideHeliEntity;
class OriginSettings;
class PresenceRequestParameters;
class PresenceGetNativeDataByInviteTokenRequestParameters;
class PresenceGetUserIdRequestParameters;
class PresenceSetPlaygroupMemberAttributesRequestParameters;
class PresenceLookupPlaygroupsByIdRequestParameters;
class PresenceViewInviteRequestParameters;
class PresenceKickFromPlaygroupRequestParameters;
class PresenceSendInviteRequestParameters;
class PresenceJoinGameByOnlineNativeDataRequestParameters;
class PresenceGetLeaderboardRequestParameters;
class PresenceDownloadStatisticsRequestParameters;
class PresenceSetPlaygroupJoinabilityRequestParameters;
class PresenceSetPlaygroupAttributeRequestParameters;
class PresenceDisbandPlaygroupRequestParameters;
class PresenceLeavePlaygroupRequestParameters;
class PresenceJoinPlaygroupByInviteTokenRequestParameters;
class PresenceJoinPlaygroupByOnlineNativeDataRequestParameters;
class PresenceJoinPlaygroupByUsernameRequestParameters;
class PresenceJoinPlaygroupRequestParameters;
class PresenceCreatePlaygroupRequestParameters;
class PresenceHttpPostRequestParameters;
class PresenceHttpGetRequestParameters;
class PresenceGetBlockListRequestParameters;
class PresenceRemoveFriendRequestParameters;
class PresenceInviteFriendRequestParameters;
class PresenceDownloadBlobRequestParameters;
class PresenceUpdateAchievementsRequestParameters;
class PresenceUnlockAchievementsRequestParameters;
class PresenceEvent;
class OnlineStatusEvent;
class FirstPartyNetworkStatusEvent;
class ActiveControllerUpdatedEvent;
class PlaygroupUpdatedEvent;
class FriendUpdatedEvent;
class PresenceBackend;
class BlazePresenceBackend;
class PresenceDownloadUpdateRequestParameters;
class BlockListEvent;
class OnlineSettings;
class OnlineServicesAsset;
class PresenceServiceData;
class PresenceUserIdServiceData;
class PresenceStatisticsServiceData;
class PresencePlaygroupServiceData;
class PresenceLeaderboardServiceData;
class PresenceFriendsServiceData;
class PresenceAchievementServiceData;
class PresencePrivilegeServiceData;
class OnlineProviderAsset;
class OnlineRichPresenceLevelDescriptionComponent;
class ServerBackendData;
class LanServerBackendData;
class LocalServerBackendData;
class BlazeServerBackendData;
class PresenceBackendData;
class Ps4PresenceBackendData;
class XenonPresenceBackendData;
class Ps3PresenceBackendData;
class Ps3ParentalLockAgeSettingsOverrides;
class LanPresenceBackendData;
class DirtySockPresenceBackendData;
class BlazePresenceBackendData;
class DurangoPresenceBackendData;
class MatchmakingSession;
class MatchmakingModifier;
class MatchmakingPlayerCapacityModifier;
class LicenseConfiguration;
class GameParametersData;
class GameRoleInformation;
class DirtySockPresenceBackend;
class GameParameters;
class NickelServiceData;
class NickelPresenceBackendData;
class PresenceOfferPlayStationPlusRequestParameters;
class PresenceRedeemCodeRequestParameters;
class PresenceConsumeRequestParameters;
class PresenceCheckoutRequestParameters;
class PresenceGetDetailedDescriptionRequestParameters;
class PresenceGetBasicDescriptionRequestParameters;
class PresenceLoadConfigurationFileRequestParameters;
class NickelPresenceBackend;
class LuaRunnerSharedVarsEntity;
class LuaRunnerScriptEntity;
class CompiledLuaResource;
class LuaRunnerSharedVarsEntityData;
class LuaRunnerScriptEntityData;
class LuaRunnerCompiledLua;
class UITextDatabase;
class LocalizationAsset;
class GroundHeightEntity;
class DynamicEnvmapEntity;
class DynamicEnlightenEntity;
class MeshEntityBase;
class LocalWindForceEntity;
class EnlightenProbeSet;
class EnlightenStaticDatabase;
class EnlightenShaderDatabase;
class EnlightenDatabase;
class EnlightenCubeMap;
class ClientVisibleAreaEntity;
class StaticEnlightenEntity;
class RigidMeshEntity;
class CompositeMeshEntity;
class RadiosityModifierEntity;
class RadiosityMaterialEntity;
class LocalLightEntity;
class PointLightEntity;
class SpotLightEntity;
class PlanarReflectionLocatorEntity;
class OccluderVolumeEntity;
class OccluderMeshEntity;
class MeshProxyEntity;
class RenderVolumeEntity;
class DecalVolumeEntity;
class MaskVolumeEntity;
class LightProbeVolumeEntity;
class LensFlareEntity;
class IndirectCubeMapEntity;
class WorldRenderSettingsBase;
class WorldRenderSettings;
class VisualEnvironmentSettings;
class SunFlareEffectState;
class SkyEffectState;
class FogEffectState;
class OutdoorLightEffectState;
class VisualEnvironmentComponentData;
class MotionBlurComponentData;
class CharacterLightingComponentData;
class DamageEffectComponentData;
class ScreenEffectComponentData;
class CameraParamsComponentData;
class ShaderParamsComponentData;
class EnlightenComponentData;
class SubSurfaceScatteringComponentData;
class DynamicAOComponentData;
class SunFlareComponentData;
class WindComponentData;
class DynamicEnvmapComponentData;
class PlanarReflectionComponentData;
class SkyComponentData;
class FogComponentData;
class OutdoorLightComponentData;
class TimelineTrackData;
class RenderFramesKeyframe;
class OcclusionSettings;
class MeshProxyEntityData;
class OccluderMeshEntityData;
class IndirectCubeMapData;
class LightProbeVolumeData;
class LocalLightEntityData;
class PointLightEntityData;
class SpotLightEntityData;
class LensFlareEntityData;
class GroundHeightEntityData;
class PlanarReflectionLocatorEntityData;
class DynamicEnvmapEntityData;
class RadiosityModifierEntityData;
class RadiosityMaterialEntityData;
class EnlightenEntityData;
class DynamicEnlightenEntityData;
class StaticEnlightenEntityData;
class RadiosityEntityData;
class RenderVolumeEntityData;
class DecalVolumeEntityData;
class MaskVolumeEntityData;
class OccluderVolumeEntityData;
class LocalWindForceEntityBaseData;
class EnlightenState;
class EnlightenRuntimeConfig;
class EnlightenRuntimeSettings;
class DestructionVolumeComponentData;
class DestructionVolumeData;
class DestructionVolumeAsset;
class DestructionVolumeSettings;
class TimelineTrack;
class OccluderMesh;
class PathfindingObjectCategoryAsset;
class VegetationSystemSettings;
class VegetationBaseEntityData;
class VegetationTreeEntityData;
class VegetationTreeEntity;
class ServerVegetationTreeEntity;
class ClientVegetationTreeEntity;
class ISwfMovie;
class SwfMovie;
class UIGraphEntityData;
class UINodeData;
class ScreenVisibilityNode;
class JumpNode;
class StateNode;
class GlobalNode;
class ScreenOutputEventNode;
class ScreenInputEventNode;
class InstanceOutputNode;
class InstanceInputNode;
class InstanceNode;
class ActionNode;
class OperandLogicNode;
class ComparisonLogicNode;
class BinaryLogicNode;
class MovieNavigationNode;
class DataBindingNode;
class RefreshNode;
class DataStepNode;
class DataIncrementNode;
class DataToggleNode;
class DataSetNode;
class DataGetNode;
class WidgetNode;
class DialogNode;
class UIAsset;
class UIGraphAsset;
class UIViewBaseAsset;
class UIViewAsset;
class UIDataBinding;
class UIDynamicDataBinding;
class UIScreenAsset;
class SplitterNode;
class UINodeConnection;
class UINodePort;
class UIInputEventNodePort;
class UIInterruptFlow;
class UIAudioEventAsset;
class UIEventAsset;
class UIActionData;
class UIGraphPipelineSettings;
class UIResourceTable;
class UIColor;
class UIFontMappingCollection;
class UIFontAsset;
class UIBundlesAsset;
class UIActionscriptLibraryAsset;
class UIWidgetAsset;
class FsLocalizationAsset;
class FsUITextDatabase;
class UIStateAsset;
class UIComponentData;
class TerrainTextureTree;
class MeshScatteringTree;
class VisualTerrainEntity;
class VisualTerrainSettings;
class VisualTerrainEntityData;
class ITerrain;
class TerrainLayerCombinations;
class TerrainDecals;
class IVisualTerrain;
class TerrainStreamingTree;
class Terrain;
class VisualTerrain;
class WaterAsset;
class TerrainStreamingSettings;
class BaseShapeData;
class TerrainQuadDecalAtlasTileTemplateData;
class VectorShapeData;
class VisualVectorShapeData;
class RibbonData;
class RoadData;
class RiverData;
class TerrainQuadDecalData;
class TerrainSettings;
class TerrainLayerCombinationsData;
class TerrainStreamingTreeAsset;
class RasterTreeAsset;
class DestructionDepthTreeAsset;
class TerrainMaterialTreeAsset;
class TerrainColorTreeAsset;
class TerrainMaskTreeAsset;
class HeightfieldTreeAsset;
class EnlightenAlbedoTreeAsset;
class TerrainData;
class TerrainMaterialMapAsset;
class WaterData;
class TerrainSubLayerData;
class TerrainLayerData;
class SingleTerrainLayerData;
class TerrainUndergrowthType;
class TerrainMeshScatteringType;
class TerrainHeightfieldData;
class RasterCoverageData;
class RasterQuadtreeData;
class PhysicsMaterialsRasterData;
class ByteRasterData;
class RGBRasterData;
class HeightfieldRasterData;
class VirtualRasterQuadtreeData;
class DestructionDepthRasterData;
class RasterQuadtreeNodeData;
class IShaderDatabase;
class IRenderResource;
class MantleShaderProgramDatabase;
class IRenderRwBufferView;
class IRenderTargetView;
class IRenderBuffer;
class ITexture;
class DxShaderProgramDatabase;
class DxRenderRwBufferView;
class IRenderTargetSet;
class DxRenderTargetView;
class DxRenderBuffer;
class ShaderDatabase;
class MantleShaderDatabase;
class RenderTestSettings;
class PerfOverlaySettings;
class TextureCompressSettings;
class ShaderSystemSettings;
class TerrainShaderParameterEntityData;
class ShaderParameterEntityData;
class SurfaceShaderBaseAsset;
class SurfaceShaderInstanceData;
class ShaderGraph;
class TessellationShaderFragmentAsset;
class VertexShaderFragmentAsset;
class ShaderDatabaseAsset;
class ViewFxData;
class GlobalPostProcessSettings;
class DebugComponentData;
class LensScopeComponentData;
class FilmGrainComponentData;
class VignetteComponentData;
class DofComponentData;
class ColorCorrectionComponentData;
class TonemapComponentData;
class MeshStreamingSettings;
class MeshSettings;
class AnimatedPointCloudAsset;
class MeshVariationEntry;
class RadiosityMaterial;
class MeshVariationDatabase;
class MeshMaterialVariation;
class MeshMaterial;
class MeshAsset;
class SkinnedMeshAsset;
class RigidMeshAsset;
class CompositeMeshAsset;
class ProceduralAnimationTypeSimple;
class ProceduralAnimationTypeWiggle;
class ProceduralAnimationTypeWind;
class MeshLodGroup;
class MeshSet;
class AnimatedPointCloud;
class GenericRenderTargetSet;
class MantleRenderRwBufferView;
class DxRenderTargetSet;
class MantleRenderTargetView;
class MantleRenderBuffer;
class DxTexture;
class AtlasTexture;
class EnlightenShaderDatabaseAsset;
class StaticEnlightenData;
class EnlightenDataAsset;
class DecalTemplateData;
class DecalSettings;
class TextureAtlasAsset;
class TextureBaseAsset;
class AtlasTextureAsset;
class TextureAsset;
class TextureArrayAsset;
class RenderTextureAsset;
class StateRenderSettings;
class DynamicTextureAtlasSettings;
class TextureSettings;
class TextureStreamingSettings;
class MantleDisplaySettings;
class DxDisplaySettings;
class DxShaderDatabase;
class MantleTexture;
class PhysicsConstraint;
class PhysicsHingeConstraint;
class HavokHingeConstraint;
class HavokPhysicsData;
class PhysicsEntityBase;
class DestructionInfo;
class ServerDestructionInfo;
class ClientDestructionInfo;
class TerrainPhysicsEntity;
class PhysicsEntity;
class SimplePhysicsEntity;
class PhysicsSimpleShapeEntity;
class BreakablePhysicsEntity;
class StaticPhysicsEntity;
class PhantomPhysicsEntity;
class GroupPhysicsEntity;
class DynamicPhysicsEntity;
class CompositePhysicsEntity;
class CharacterPhysicsEntity;
class RigidBody;
class ServerControllablePhysicsComponent;
class ShockwaveCollisionInfo;
class ClientShockwaveCollisionInfo;
class ServerShockwaveCollisionInfo;
class FakeCollisionInfo;
class ClientFakeCollisionInfo;
class ServerFakeCollisionInfo;
class CollisionInfo;
class ClientGameHealthComponent;
class DamageInfo;
class ServerDamageInfo;
class ClientDamageInfo;
class ForceComponent;
class RigidBodyConstraint;
class PhysicsRagdollConstraint;
class HavokLimitedHingeConstraint;
class HavokRagdollConstraint;
class IglooSubsystem;
class HavokClothPhysicsData;
class FloatPhysicsData;
class BoxFloatPhysicsData;
class PhysicsConstraintData;
class PhysicsBallAndSocketConstraintData;
class PhysicsHingeConstraintData;
class PhysicsRagdollContraintData;
class RigidBodyData;
class PhysicsDebugSettings;
class PhysicsSettings;
class PhysicsRenderSettings;
class WaterInteractEntityData;
class ForceComponentData;
class MissileHealthComponentData;
class ExplosionPackPhysicsComponentData;
class MaterialRelationPropertyData;
class PhysicsEntityData;
class ProximityData;
class RagdollAsset;
class HavokAsset;
class GroupHavokAsset;
class VehicleSpawnStateEntityData;
class MovingBodyData;
class RotationBodyData;
class ExtendedConstraintsData;
class LinearMovingBodyData;
class LoosePartPhysicsData;
class CameraLoosePartPhysicsData;
class WheelConfigData;
class WheelConfigMotorbikeData;
class EngineConfigData;
class PropellerEngineConfigData;
class RotorParameters;
class CombustionEngineConfigData;
class JetEngineConfigData;
class GearboxConfigData;
class VehicleInputTweakData;
class MotionDampingData;
class StabilizerData;
class WingPhysicsData;
class Curve2D;
class LandingFlapData;
class AeroDynamicPhysicsData;
class HullFloatPhysicsData;
class BoatFloatPhysicsData;
class HovercraftFloatPhysicsData;
class VehicleConfigData;
class MotorbikeData;
class AntiRollBar;
class CharacterPhysicsData;
class CharacterStateData;
class SwimmingStateData;
class JumpStateData;
class ClimbingStateData;
class FallingStateData;
class InAirStateData;
class OnGroundStateData;
class SlidingStateData;
class AnimationControlledStateData;
class ParachuteStateData;
class CharacterSprintData;
class CharacterStatePoseInfo;
class CharacterPoseData;
class HavokDestructionPhysicsData;
class RagdollResource;
class RagdollEntity;
class WaterPhysicsEntity;
class EdgeModelLightMapData;
class DestructionControllerComponentData;
class DestructionEdgeModelComponentData;
class DestructionPartComponentData;
class FakePhysicsData;
class FakeSpringData;
class FakeHingeData;
class ClothAsset;
class FollowObjectEntityData;
class FollowWaypointsEntityData;
class PathFollowingComponentData;
class PathfindingStreamEntityData;
class InterpolationManagerSettings;
class MovieTextureAsset;
class AntAnimatableEntityData;
class AntAnimatableComponentData;
class AntEnumeration;
class GameAIWeaponData;
class GameAIEntryData;
class SchematicPinTrackData;
class LinkTrackData;
class RecordTrackBaseData;
class ANTLayerData;
class TimelineKeyframeData;
class PoseTransitionBase;
class BlendedPoseTransition;
class AnimatedPoseTransition;
class CutPoseTransition;
class PoseDefinition;
class PosesGlobalAsset;
class NetworkReplayTrackData;
class NetworkReplayKeyframe;
class TransformLayerData;
class FadeTrackData;
class FadeTrackKeyframe;
class CameraTrackBaseData;
class CameraDirectorTrackData;
class CameraDirectorKeyframe;
class CameraAttachTransformLayerData;
class AttachTransformLayerData;
class ANTTrajectoryTransformLayerData;
class GunSwayData;
class FOVTransitionData;
class WeaponDispersionModifier;
class WeaponCrosshairTypeModifier;
class WeaponMagazineModifier;
class WeaponShotModifier;
class WeaponProjectileModifier;
class WeaponSoundModifier;
class WeaponFiringEffectsModifier;
class WeaponFiringDataModifier;
class WeaponMiscModifier;
class BoneFakePhysicsData;
class WeaponZeroingModifier;
class LockingWeaponData;
class LaserDesignatorData;
class LaserPainterData;
class ArtilleryStrikeWeaponData;
class MortarStrikeWeaponData;
class ZeroingWeaponData;
class SupplySphereWeaponData;
class GameDataContainerAsset;
class WeaponFiringData;
class WeaponSuppressionData;
class FiringFunctionData;
class GhostedProjectileEntityData;
class LockingControllerData;
class BulletEntityData;
class GrenadeEntityData;
class FlareEntityData;
class ProjectilePhysicsComponentData;
class ExplosionPackEntityData;
class VehicleWaypointData;
class WaypointsShapeData;
class RailRideHeliWaypointData;
class CannedScenarioEntityData;
class WarpAnimationEntityData;
class WarpAnimationComponentData;
class WarningSystemComponentData;
class RawFileData;
class EffectEntityData;
class ReferenceObjectData;
class VisualEnvironmentReferenceObjectData;
class LogicVisualEnvironmentEntityData;
class VisualEnvironmentBlueprint;
class VisualEnvironmentEntityData;
class LensFlareComponentData;
class LightComponentData;
class VersionData;
class VehicleEntryListenerComponentData;
class VehicleEntityData;
class AnimatedDriverEntityData;
class VehicleSoundData;
class VehicleHealthComponentData;
class VehiclePhysicsComponentData;
class IKComponentData;
class PartComponentData;
class ChassisComponentData;
class CameraRelativeControlData;
class LandingGearLogicData;
class VehicleWaterEffectData;
class VehicleExitPointComponentData;
class WeaponInputRouterComponentData;
class CameraComponentData;
class AnimationTurretRotationComponentData;
class SoldierGripComponentData;
class BoneComponentData;
class AlignmentData;
class RotorComponentData;
class MeshComponentData;
class TrackComponentData;
class FlapComponentData;
class WingComponentData;
class WheelComponentData;
class TrackWheelComponentData;
class StanceFilterComponentData;
class EngineComponentData;
class WeaponComponentData;
class ChildComponentData;
class ValueUnlockAsset;
class UnlockValuePair;
class IntUnlockValuePair;
class FloatUnlockValuePair;
class BoolUnlockValuePair;
class UnlockAsset;
class MultiUnlockAsset;
class VisualUnlockAsset;
class WeaponUnlockAsset;
class MeshAndVariationPair;
class SoldierWeaponUnlockAsset;
class SoldierWeaponMultiUnlock;
class UISettings;
class UIWidgetEntityData;
class UICppScreenData;
class CreateUIWidgetParams;
class UIDebugScreenData;
class UIFlowCppScreenData;
class LogicReferenceObjectData;
class UIIMSettingsAsset;
class UIElementWidgetReferenceEntityData;
class UIElementEntityData;
class UIElementDummyEntityData;
class UIElementCustomEntityData;
class UIElementVideoEntityData;
class UIElementBitmapEntityData;
class UIElementButtonEntityData;
class UIElementTrigger;
class UIElementAction;
class UIElementEvent;
class UIElementEditBoxEntityData;
class UIElementTextFieldEntityData;
class UIElementFillEntityData;
class UIDebugWidgetData;
class UIElementLayerEntityData;
class UIElementStyle;
class UIElementTableStyle;
class UIElementScrollbarStyle;
class UIElementGenericStyle;
class UIElementButtonStyle;
class UIElementEditBoxStyle;
class UIElementFillData;
class UIElementSlice9FillData;
class UIElementFontStyle;
class UIElementFontDefinition;
class UIElementTextFilter;
class UIElementTextFilterDropShadow;
class UIElementTextFilterBlur;
class UIElementTextFilterGlow;
class UITextureMappingAsset;
class UIWidgetBlueprint;
class UIWidgetMovieCompData;
class CharacterLookAtTriggerEntityData;
class UnderFireTriggerEntityData;
class PlayerInputTriggerEntityData;
class CameraEnterAreaTriggerEntityData;
class ObjectEnterAreaTriggerEntityData;
class PlayerTakeOverTriggerEntityData;
class DamageAreaTriggerEntityData;
class ClearAreaTriggerEntityData;
class VehicleStateTriggerEntityData;
class DelayTriggerEntityData;
class MultipleTriggerEntityData;
class LookAtTriggerEntityData;
class CombatActionTriggerEntityData;
class AreaTriggerEntityData;
class GeometryTriggerEntityData;
class CharacterStateTriggerEntityData;
class JointValidationEntityData;
class ClientPlayerInputPlaybackEntityData;
class ClientPlayerInputRecorderEntityData;
class LoggingEntityData;
class DestructionCommandEntityData;
class TestPointEntityData;
class MovementActionData;
class RecordedInputData;
class InputRecorderData;
class SimpleMovementActionBaseData;
class CameraActionData;
class SimpleMovementActionData;
class MovementActionRandomizerData;
class MovementActionGroupData;
class MovementActionRoot;
class SoldierMovementSequenceData;
class AssertEntityData;
class LinkDebugEntityData;
class PropertyDebugEntityData;
class PrintDebugTextEntityData;
class TestCaseEntityData;
class DebugMenuItemEntityData;
class DebugMenuSubMenuEntityData;
class ConsoleCommandTriggerEntityData;
class ConsoleCommandEntityData;
class DebugTextEntityData;
class WaterPhysicsComponentData;
class TerrainPhysicsComponentData;
class WaterEntityData;
class TerrainEntityData;
class SequenceEntityData;
class SubViewData;
class StaticModelHealthComponentData;
class StaticModelPhysicsComponentData;
class StaticModelEntityData;
class FenceModelEntityData;
class LadderEntityData;
class InteractableStaticModelEntityData;
class SpawnReferenceObjectData;
class CharacterSpawnReferenceObjectData;
class CharacterSpawnTemplateData;
class AlternateSpawnEntityData;
class GameBehaviourTemplateData;
class GameSensingTemplateData;
class AnimationSpawnTemplate;
class VehicleSpawnReferenceObjectData;
class ExtraSpawnData;
class SlowMotionEntityData;
class DriverComponentData;
class DriverStaticObjectComponentData;
class DriverSettings;
class RegulatedSteering;
class DifficultyIndexEntityData;
class DifficultyDatas;
class DifficultyData;
class GameAIDifficultyData;
class CustomizeSoldierData;
class VehicleCustomizationAsset;
class SoldierCustomizationAsset;
class CustomizationUnlockParts;
class CustomizationTable;
class VehicleVisualCustomizationAsset;
class TextUnlockPartData;
class ShaderCustomizationUnlockPartCollection;
class ShaderColorUnlockPartCollection;
class ShaderTextureUnlockPartCollection;
class UnlockableTextureSliceCollection;
class UnlockableTextureCollection;
class UnlockableColorCollection;
class UnlockableShaderParameterValueCollection;
class TextureSliceUnlockPartData;
class TextureAssetUnlockPartData;
class TextureUnlockPartData;
class TextureReference;
class ColorUnlockPartData;
class ColorReference;
class AreaImmunityComponentData;
class CharacterHealthComponentData;
class ExplosionPackHealthComponentData;
class WaterDepthComponentData;
class CharacterMasterPhysicsComponentData;
class WaterInteractPhysicsComponentData;
class CharacterEntryComponentData;
class AnimatedPointCloudComponentData;
class LadderComponentData;
class AlternateCameraViewData;
class UnlockComponentData;
class EffectComponentData;
class CameraComponentSoundData;
class SoldierCustomizationComponentData;
class ShaderParameterComponentData;
class ChildMovingBodyData;
class ChildRotationBodyData;
class RadioComponentData;
class RagdollComponentData;
class SkeletonCollisionData;
class AimAssistCollisionBoneData;
class PhantomComponentData;
class RemoteEntryComponentData;
class PlayerEntryComponentData;
class SoldierEntryComponentData;
class EntryComponentSoundData;
class GroupComponentData;
class ChildBarrelComponentData;
class PartBoneData;
class VehicleComponentData;
class PartLinkData;
class NetworkableLoosePartPhysicsData;
class HealthStateData;
class BangerSpawnImpulseParams;
class SoundSettings;
class ClientSettings;
class CharacterEntityData;
class SoldierSoundData;
class SoldierPhysicsComponentData;
class PhysicsDrivenComponentData;
class SoldierHealthComponentData;
class AntDrivenComponentData;
class CharacterPhysicsComponentData;
class CharacterInputDrivenCameraComponentData;
class SoldierCameraComponentData;
class CameraTrackData;
class CameraEntityBaseData;
class TargetCameraEntityData;
class CameraEntityData;
class LookAtCameraEntityData;
class PlayerCameraEntityData;
class CameraData;
class AnimatedCameraData;
class TargetCameraData;
class ChaseCameraData;
class FPSCameraData;
class VehicleCameraData;
class StaticCameraData;
class CharacterBlueprint;
class VehicleBlueprint;
class ProjectileBlueprint;
class SoldierBlueprint;
class VehicleAsset;
class BlueprintBundleCollectionEntityData;
class BlueprintBundleEntityData;
class BlueprintBundleCollection;
class BlueprintBundle;
class BangerHealthComponentData;
class BangerPhysicsComponentData;
class DynamicGamePhysicsEntityData;
class CustomSequenceTrackData;
class AntTrackItemData;
class ANTSignalTrackData;
class PropertyTrackBaseData;
class FloatTrackData;
class BoolTrackData;
class AntEventEntityData;
class ANTControlTrackData;
class DefaultANTLayerData;
class PoseTrackData;
class ANTClipKeyframeTrackData;
class ANTBlendKeyframeTrackData;
class ANTBlendKeyframe;
class ANTClipKeyframe;
class PrefabBlueprint;
class LevelDataComponent;
class CameraTransition;
class CameraModeAsset;
class GameAISystem;
class PathfindingBlobAsset;
class PathfindingSystemEntityData;
class FaceAnimationWaveMappings;
class BigWorldSettingsAsset;
class BigWorldSetting;
class LevelReportingAsset;
class LevelDescriptionAsset;
class MemoryLevelDescriptionComponent;
class WaterLevelDescriptionComponent;
class InputModifierEntityData;
class InputActionMappingData;
class EntryInputActionMappingData;
class InputActionMappingsData;
class InputActionData;
class AxesInputActionData;
class KeyboardInputActionData;
class MotionControllerInputActionData;
class PadInputActionData;
class MouseInputActionData;
class InputCurveData;
class InputConfigurationAsset;
class EditableAction;
class OneOptionButtonEditableAction;
class OneOptionAxisEditableAction;
class EntryInputActionMapsData;
class EntryInputActionBindingsData;
class InputActionMapData;
class EntryInputActionMapData;
class InputActionsData;
class MessageInputActionData;
class UIWorldIconBehavior;
class UICombatAreaAsset;
class UIPartData;
class LockingTypeAsset;
class CrosshairTypeAsset;
class UIPartPropertyList;
class StaticModelGroupHealthComponentData;
class StaticModelGroupPhysicsComponentData;
class StaticModelGroupEntityData;
class GameSplineEntityData;
class CustomSplineData;
class GameAnimationSettings;
class DemoSettings;
class WindowSettings;
class PerformanceTrackerSettings;
class GameTimeSettings;
class SyncedGameSettings;
class GameSettings;
class GameSettingsComponent;
class DecalEntityData;
class ClientEffectMaskVolumeEntityData;
class DestructionMaskVolumeEntityData;
class InteractionEntityData;
class PredestructionEntityData;
class ExplosionEntityData;
class SoldierEntityData;
class BangerEntityData;
class SoundAreaEntityData;
class VoiceOverConversationEntityData;
class VoiceOverEventEntityData;
class PlayAnimationEntityData;
class PlayAnimationData;
class FbProxyControllerEntityData;
class FaceposerComponentData;
class EventSyncEntityData;
class EntitlementQuery;
class DynamicModelHealthComponentData;
class DynamicModelPhysicsComponentData;
class DynamicModelEntityData;
class DynamicFireEntityData;
class DynamicFireCellFXAsset;
class CellFX;
class DynamicAvoidanceEntityData;
class ServerSettings;
class AnimatedPointCloudEntityData;
class ModelAnimationEntityData;
class CharacterAnimationSpaceEntityData;
class AnimationEnumerationChoiceEntityData;
class AnimationEnumerationEntityData;
class AnimationSignalEntityData;
class CharacterAnimationEntityData;
class AnimatedTransformEntityData;
class RawFileAsset;
class RawFileResourceAsset;
class RawFileDataAsset;
class ProfileOptionData;
class ProfileOptionDataString;
class ProfileOptionDataBool;
class ProfileOptionDataEnum;
class ProfileOptionDataFloat;
class ProfileOptionDataInt;
class ProfileOptionDataBinary;
class ProfileOptionsAsset;
class ProceduralAwarenessTargetEntityData;
class ProceduralAwarenessComponentData;
class SpectatorSubViewData;
class PlayerViewData;
class PlayerData;
class PlayAnimationVisualizerEntityData;
class PhysicsDrivenAnimationEntityData;
class PersistenceStatGroup;
class PersistenceStatTable;
class AbstractPersistenceData;
class AbstractLeaderboardData;
class PersistenceGameData;
class RichPresenceData;
class RichPresenceContext;
class RichPresenceContextValue;
class RichPresenceContextValueWithKey;
class RichPresencePresenceString;
class PersistenceData;
class PersistenceRetentionPolicy;
class AbstractPersistentStatRef;
class PersistentValueTemplateStatRef;
class PersistentValueTemplate;
class PathfindingDebugSettings;
class PathfindingTypeAsset;
class NetworkSettings;
class GuideTrackData;
class MovieTrackKeyframe;
class CharacterInVehicleScenarioEntityData;
class MultipleActorScenarioEntityData;
class WaterDepthEntityData;
class TransformSnapToGroundEntityData;
class PhysicsMaterialRelationPropertyData;
class MaterialRelationVehicleData;
class PhysicsPropertyRelationPropertyData;
class MaterialRelationDamageData;
class MaterialRelationTerrainDestructionData;
class MaterialRelationSoundData;
class MaterialRelationDynamicFireData;
class MaterialRelationEffectData;
class MaterialPropertyImpulseData;
class MaterialPropertyHealthData;
class MaterialPropertyTerrainData;
class MaterialRelationDecalData;
class MaterialPropertyEffectData;
class MaterialPropertySoundData;
class MaterialSoldierSoundSettings;
class LocalPlayerEventEntityData;
class PlayerIteratorEntityData;
class EventQueueEntityData;
class InclusionSettingEntityData;
class TeleportEntityData;
class StreamingGateEntityData;
class SpectatorReplayEntityData;
class CustomizeCharacterEntityData;
class CustomizeSoldierEntityData;
class PlayerFilterEntityData;
class AreaQueryEntityData;
class AreaProximityEntityData;
class InputRestrictionEntityData;
class EventIfSwitchEntityData;
class TeamFilterEntityData;
class PlatformSplitterEntityData;
class EventSplitterEntityData;
class EventMemoryEntityData;
class SpeedEventGateEntityData;
class EventCompareGateEntityData;
class HudEntityData;
class SaveGameLoadedEntityData;
class SaveEntityData;
class StartPointEntityData;
class StartEntityData;
class MapMarkerEntityData;
class MessageEntityData;
class MessageEntityInfo;
class TacticalObjectiveEntityData;
class LevelControlEntityData;
class ObjectiveEntityData;
class MissionObjectiveHudData;
class MovieEntityData;
class PlayVideoEntityData;
class FadeEntityData;
class GameInteractionEntityData;
class KillAllEntityData;
class WaypointTriggerEntityData;
class CombatAreaTriggerEntityData;
class SurroundingGeometryEntityData;
class UIMinimapVolumeEntityData;
class UICombatAreaEntityData;
class AllowedVehiclesData;
class DeathAreaTriggerEntityData;
class HumanPlayerProxyEntityData;
class HumanPlayerEntityData;
class TeamEntityData;
class TeamAsset;
class TeamData;
class LightEffectEntityData;
class ServerWarpAnimationEntity;
class PhysicsDrivenAnimationEntity;
class ServerCannedScenarioEntity;
class LinkTrack;
class RecordTrackBase;
class ServerRecordEntryInputTrack;
class ServerPlayAnimationEntity;
class ServerMultipleActorScenarioEntity;
class ModelAnimationEntity;
class ServerFbProxyControllerEntity;
class ServerCharacterInVehicleScenarioEntity;
class CharacterAnimationEntity;
class ANTSignalTrack;
class ANTControlTrack;
class ServerAntAnimatableEntity;
class ServerAnimationEnumerationChoiceEntity;
class ServerAnimationEnumerationEntity;
class ServerClearAreaTriggerEntity;
class ServerAreaTriggerEntity;
class ServerSpawnEntity;
class ServerVehicleSpawnEntity;
class ServerCharacterSpawnEntity;
class ServerTeleportEntity;
class ServerTeamFilterEntity;
class ServerTeamEntity;
class ServerTacticalObjectiveEntity;
class SequenceEntity;
class ServerSpeedEventGateEntity;
class ServerSaveGameLoadedEntity;
class ServerSaveEntity;
class PlayerIteratorEntity;
class ServerPlayerFilterEntity;
class ServerObjectiveEntity;
class ServerMapMarkerEntity;
class ServerLevelControlEntity;
class ServerInputRestrictionEntity;
class ServerTerrainEntity;
class ServerStaticModelGroupEntity;
class ServerStaticModelEntity;
class ServerLadderEntity;
class ServerInteractableStaticModelEntity;
class ServerBangerEntity;
class ServerWaterPhysicsComponent;
class ServerTerrainPhysicsComponent;
class ServerStaticModelPhysicsComponent;
class ServerStaticModelHealthComponent;
class ServerStaticModelGroupPhysicsComponent;
class ServerStaticModelGroupHealthComponent;
class ServerPartComponent;
class ServerWaterInteractPhysicsComponent;
class ServerControllableHealthComponent;
class ServerPlayerEntryComponent;
class ServerCharacterEntryComponent;
class ServerDriverStaticObjectComponent;
class ServerDriverComponent;
class ServerCharacterMasterPhysicsComponent;
class ServerCharacterHealthComponent;
class ServerSoldierEntryComponent;
class ServerControllableEntity;
class ServerWarpAnimationComponent;
class ServerVehicleEntryListenerComponent;
class ServerPhysicsDrivenComponent;
class ServerCharacterCameraComponent;
class ServerCharacterPhysicsComponent;
class ServerSoldierPhysicsComponent;
class ServerSoldierHealthComponent;
class ServerSoldierCustomizationComponent;
class ServerInputDrivenCharacterCameraComponent;
class ServerAntDrivenComponent;
class ServerAntAnimatableComponent;
class ServerVehicleStateTriggerEntity;
class ServerUnderFireTriggerEntity;
class ServerCharacterLookAtTriggerEntity;
class ServerLookAtTriggerEntity;
class ServerPlayerTakeOverTriggerEntity;
class ServerPlayerInputTriggerEntity;
class ServerMultipleTriggerEntity;
class ServerKillAllEntity;
class ServerDelayTriggerEntity;
class ServerDeathAreaTriggerEntity;
class ServerDamageAreaTriggerEntity;
class ServerCombatAreaTriggerEntity;
class ServerCombatActionTriggerEntity;
class ServerSyncedFloatEntity;
class ServerSyncedBoolEntity;
class SubLevelEntity;
class ServerStartPointEntity;
class ServerWaterInteractEntity;
class ServerGroupComponent;
class ServerGhostEntityOwnerWrapperEntity;
class ServerCharacterEntity;
class ServerEventSyncEntity;
class ServerPlaceHolderEntity;
class ServerRemoteEntryComponent;
class ServerBlueprintEntity;
class ServerCameraComponent;
class ServerExplosionPackEntity;
class ServerMissileEntity;
class ServerGrenadeEntity;
class ServerBulletEntity;
class ServerGameSplineEntity;
class ServerAreaImmunityComponent;
class ServerDynamicFireEntity;
class ServerSoldierEntity;
class ServerWarningSystemComponent;
class ServerUnlockComponent;
class ServerRadioComponent;
class BangerHealthModuleData;
class ServerWaterEntity;
class ServerVehicleEntity;
class ServerBoneComponent;
class ServerWheelComponent;
class ServerWeaponInputRouterComponent;
class ServerWeaponComponent;
class ServerVehiclePhysicsComponent;
class ServerVehicleHealthComponent;
class ServerTrackWheelComponent;
class ServerMeshComponent;
class ServerStanceFilterComponent;
class ServerRotorComponent;
class ServerTrackComponent;
class ServerFlapComponent;
class ServerEngineComponent;
class ServerChildComponent;
class ServerChildBarrelComponent;
class ServerChassisComponent;
class ServerHumanPlayerProxyEntity;
class ServerHumanPlayerEntity;
class ServerHudEntity;
class ServerEventMemoryEntity;
class ServerEventIfSwitchEntity;
class ServerCustomizeCharacterEntity;
class ServerAreaQueryEntity;
class EntityEvent;
class ServerPlayerEvent;
class ServerDamageGiverEvent;
class ServerSphereCollisionEntity;
class ServerPredestructionEntity;
class ServerOBBCollisionEntity;
class ServerLadderComponent;
class ServerExplosionEntity;
class ServerDynamicAvoidanceEntity;
class ServerWeapon;
class ServerWingComponent;
class ServerBangerPhysicsComponent;
class ServerBangerHealthModule;
class ServerBangerHealthComponent;
class SubView;
class ServerSubView;
class ServerSpectatorSubViewBase;
class GameView;
class ServerSyncedTransformEntity;
class ServerSyncedIntEntity;
class ServerModelAnimationEntity;
class ServerCharacterAnimationEntity;
class ServerANTSignalTrack;
class ServerANTControlTrack;
class ServerPhysicsDrivenAnimationEntity;
class ClientSoldierCameraCallback;
class Camera;
class TargetCamera;
class AreaProximityEntity;
class WaypointParameterEvent;
class TransformParameterEvent;
class MoveParameterEvent;
class IntParameterEvent;
class FloatParameterEvent;
class EntityParameterEvent;
class ComponentParameterEvent;
class CollisionEvent;
class SlowMotionEntity;
class DifficultyIndexEntity;
class CameraEnterAreaTriggerEntity;
class ServerPlayerIteratorEntity;
class PlatformSplitterEntity;
class WaterDepthEntity;
class TransformSnapToGroundEntity;
class InclusionSettingEntity;
class EventSplitterEntity;
class EventCompareGateEntity;
class ClientWeapon;
class ServerZeroingWeapon;
class ServerSpectatorSubView;
class ServerGameView;
class LoggingEntity;
class ConsoleCommandTriggerEntity;
class ConsoleCommandEntity;
class ServerTripwireEntity;
class ClientCharacterCustomizationComponent;
class BlueprintBundleEntity;
class BlueprintBundleCollectionEntity;
class ClientControllableHealthComponent;
class ClientBoneComponent;
class ClientMeshComponent;
class ClientStanceFilterComponent;
class ClientRotorComponent;
class ClientTrackComponent;
class ClientIKComponent;
class ClientFlapComponent;
class ClientEngineComponent;
class ClientChildComponent;
class ClientChildBarrelComponent;
class ClientPartComponent;
class ClientCameraComponent;
class ClientComponentTargetCameraCallback;
class VoiceOverEventEntity;
class VoiceOverConversationEntity;
class SoundArea;
class ClientTeamEntity;
class ClientSphereCollisionEntity;
class ClientOBBCollisionEntity;
class ClientLadderComponent;
class ClientExplosionEntity;
class ClientDynamicAvoidanceEntity;
class ClientZeroingWeapon;
class ClientVehicleEntity;
class ClientAnimatedDriverEntity;
class ClientWingComponent;
class ClientWheelComponent;
class ClientWeaponInputRouterComponent;
class ClientWeaponComponent;
class ClientWaterDepthComponent;
class ClientControllablePhysicsComponent;
class ClientPhysicsEntityWithPoseProvider;
class ClientWaterInteractEntity;
class ClientGroupComponent;
class ClientProxyProjectileEntity;
class ClientEventSyncEntity;
class ClientSoldierWeaponsComponent;
class ClientBlueprintEntity;
class ClientPlaceHolderEntity;
class ChaseCamera;
class CameraTrackBase;
class ClientPlayAnimationEntity;
class ClientMultipleActorScenarioEntity;
class ClientModelAnimationEntity;
class ClientJointValidationEntity;
class ClientFbProxyControllerEntity;
class ClientCharacterInVehicleScenarioEntity;
class ClientCharacterAnimationSpaceEntity;
class ClientCharacterAnimationEntity;
class ClientANTSignalTrack;
class ClientAntEventEntity;
class DebugComponent;
class DamageEffectComponent;
class EmitterParamComponent;
class MotionBlurComponent;
class CharacterLightingComponent;
class ScreenEffectComponent;
class CameraParamsComponent;
class ShaderParamsComponent;
class LensScopeComponent;
class FilmGrainComponent;
class VignetteComponent;
class DofComponent;
class SubSurfaceScatteringComponent;
class DynamicAOComponent;
class SunFlareComponent;
class DynamicEnvmapComponent;
class PlanarReflectionComponent;
class WindComponent;
class FogComponent;
class SkyComponent;
class ColorCorrectionComponent;
class TonemapComponent;
class EnlightenComponent;
class OutdoorLightComponent;
class LogicVisualEnvironmentEntity;
class EffectEntity;
class DestructionVolumeComponent;
class ClientWaterPhysicsComponent;
class ClientTerrainPhysicsComponent;
class ClientStaticModelPhysicsComponent;
class ClientStaticModelHealthComponent;
class ClientStaticModelGroupPhysicsComponent;
class ClientStaticModelGroupHealthComponent;
class ClientChassisComponent;
class ClientLightComponent;
class ClientLensFlareComponent;
class ClientWaterInteractPhysicsComponent;
class ClientAntAnimatableComponent;
class ClientWarpAnimationEntity;
class ClientPhysicsDrivenAnimationEntity;
class ClientCannedScenarioEntity;
class VehicleCamera;
class StaticCamera;
class FreeCamera;
class FPSCamera;
class DemoRecorderCamera;
class ClientCameraEntityBase;
class ClientCameraTrack;
class ClientTargetCameraEntity;
class ClientCameraEntity;
class ClientLookAtCameraEntity;
class ClientPlayerCameraEntity;
class ClientCameraDirectorTrack;
class EntityTrackBase;
class ClientWaterEntity;
class ClientTerrainEntity;
class ClientStaticModelGroupEntity;
class InternalDestroyMeshEntity;
class ClientStaticModelEntity;
class ClientLadderEntity;
class ClientDynamicModelEntity;
class ClientDecalEntity;
class ClientBangerEntity;
class VisualEnvironmentEntity;
class VisualEnvironmentEffectEntity;
class ClientPlayerInputTriggerEntity;
class ClientCombatAreaTriggerEntity;
class ClientClearAreaTriggerEntity;
class ClientSpawnEntity;
class ClientVehicleSpawnEntity;
class ClientCharacterSpawnEntity;
class ClientTeamFilterEntity;
class ClientSyncedSequenceEntity;
class ClientStreamingGateEntity;
class ClientWarningSystemComponent;
class ClientUnlockComponent;
class ClientRadioComponent;
class ClientPlayerEntryComponent;
class ClientSoldierEntryComponent;
class ClientCharacterMasterPhysicsComponent;
class ClientCharacterHealthComponent;
class ClientCharacterEntity;
class ClientWarpAnimationComponent;
class ClientVehicleEntryListenerComponent;
class ClientPhysicsDrivenComponent;
class ClientInputDrivenCharacterCameraComponent;
class ClientCharacterPhysicsComponent;
class ClientSoldierPhysicsComponent;
class ClientSoldierHealthComponent;
class ClientSoldierCustomizationComponent;
class ClientSoldierCameraComponent;
class CharacterTargetCameraCallback;
class ClientAntDrivenComponent;
class ClientProxyGrenadeEntity;
class ClientProxyMissileEntity;
class ClientSupplySphereEntity;
class ClientMissileEntity;
class ClientMedicBagHealingSphereEntity;
class ClientBulletEntity;
class ClientMovieTrack;
class ClientMovieEntity;
class ClientGameSplineEntity;
class ClientAreaImmunityComponent;
class ClientDynamicFireEntity;
class ClientSoldierEntity;
class ClientVehicleHealthComponent;
class ClientEffectComponent;
class ClientDynamicModelPhysicsComponent;
class ClientDynamicModelHealthComponent;
class ClientTrackWheelComponent;
class ClientBangerPhysicsComponent;
class ClientBangerHealthComponent;
class ClientAnimatedPointCloudComponent;
class LocalWindForceComponent;
class LocalWindForceConeComponent;
class LocalWindForceSphereComponent;
class LocalWindForceBaked3DAs2x2DTexComponent;
class ClientSubView;
class ClientSpectatorSubView;
class UIWidgetEntity;
class UIElementLayerEntity;
class UIElementWidgetReferenceEntity;
class UIElementEntity;
class UIElementDummyEntity;
class UIElementCustomEntity;
class UIElementVideoEntity;
class UIElementBitmapEntity;
class UIElementButtonEntity;
class UIElementEditBoxEntity;
class UIElementTextFieldEntity;
class UIElementFillEntity;
class UIDebugWidget;
class ClientUIGraphEntity;
class ClientPlayVideoEntity;
class IUISystem;
class UISystem;
class ClientUIScreenRenderEntity;
class ClientUISetValueEntity;
class ClientUIGetValueEntity;
class ClientUICompareDataKeyEntity;
class ClientUIActionEntity;
class ClientTerrainShaderParameterEntity;
class ClientShaderParameterEntity;
class ClientShaderParameterComponent;
class ClientSpectatorReplayEntity;
class ClientPlayerIteratorEntity;
class ClientPlayerFilterEntity;
class ClientObjectiveEntity;
class ClientMessageEntity;
class ClientMapMarkerEntity;
class ClientLocalPlayerEventEntity;
class ClientEventMemoryEntity;
class ClientFadeTrack;
class ClientFadeEntity;
class ClientPlayerEvent;
class ClientDoublePlayerEvent;
class LocalWindForceComponentBaseData;
class UIActionEntityData;
class UICompareDataKeyEntityData;
class UIGetValueEntityData;
class UISetValueData;
class GameRenderSettings;
class ClientANTControlTrack;
class ClientAntAnimatableEntity;
class ClientAnimationSignalEntity;
class ClientAnimationEnumerationChoiceEntity;
class ClientAnimationEnumerationEntity;
class ClientAnimatedPointCloudEntity;
class ClientSyncedTransformEntity;
class ClientSyncedIntEntity;
class ClientSyncedFloatEntity;
class ClientSyncedBoolEntity;
class ClientSubLevelEntity;
class GroupTrack;
class SchematicEventTrack;
class ServerRecordVehicleTrack;
class ServerRecordRootTransformTrack;
class IPropertyTrack;
class LayeredTransformTrack;
class EntityTrack;
class ProxyEntityTrack;
class TemplatedProxyEntityTrack;
class DummyEntityTrack;
class ClientANTCameraTrack;
class TransformLayer;
class SimpleTransformLayer;
class Vec4TrackData;
class Vec3TrackData;
class Vec2TrackData;
class GroupTrackData;
class RecordTrackChildrenData;
class RecordRootTransformTrackData;
class RecordVehicleTrackData;
class IntTrackData;
class RecordEntryInputTrackData;
class LayeredTransformTrackData;
class ANTIntTrackData;
class ANTFloatTrackData;
class EventTrackData;
class EntityTrackBaseData;
class EntityTrackData;
class ProxyEntityTrackData;
class TemplatedProxyEntityTrackData;
class DummyEntityTrackData;
class ANTCameraTrackData;
class CurveData;
class CurveDataKeyframe;
class ColorTrackData;
class ANTBoolTrackData;
class GroundAttachTransformLayerData;
class StartingLocationTransformLayerData;
class ScaleTransformLayerData;
class SubWorldInclusion;
class SubWorldInclusionCriterion;
class SubWorldInclusionSetting;
class SubWorldInclusionSettings;
class DynamicDataContainer;
class WorldObjectListData;
class WorldPartReferenceObjectData;
class SubWorldReferenceObjectData;
class SpatialPrefabBlueprint;
class SubWorldData;
class SubWorldDataComponent;
class WorldPartData;
class WorldPartInclusionSettings;
class WorldPartInclusionSetting;
class WorldPartInclusion;
class WorldPartInclusionCriterion;
class HighlightEntityData;
class TextSequenceEntityData;
class TextSequenceItem;
class TreeBase;
class TreeNodeBase;
class LightEffectEntity;
class ClientSoldierWeapon;
class ClientVehiclePhysicsComponent;
class CompareIntRangeEntity;
class CompareFloatRangeEntity;
class CompareStringEntity;
class CompareFloatEntity;
class CompareIntEntity;
class CompareBoolEntity;
class RenderFramesTrack;
class TimelineEntity;
class Timeline;
class TrajectoryEntity;
class AnimTrackData;
class ServerSyncedSequenceEntity;
class LocalWindForceSphereEntity;
class LocalWindForceSamplerEntity;
class LocalWindForceBaked3DAs2x2DTexEntity;
class LocalWindForceConeEntity;
class ClientProxyExplosionPackEntity;
class ServerDoublePlayerEvent;
class KeyedTransformLayerData;
class GroupTransformLayerData;
class PropertyTrackData;
class SimplePropertyTrackData;
class Vec3PropertyTrackData;
class Vec2PropertyTrackData;
class TransformPropertyTrackData;
class IntPropertyTrackData;
class FloatPropertyTrackData;
class BoolPropertyTrackData;
class Vec4PropertyTrackData;
class SequenceData;
class TrajectoryEntityData;
class SyncedSequenceEntityData;
class AntTrackData;
class CustomSequenceTrackPropertyMapping;
class CustomSequenceTrackEventMapping;
class CustomSequenceTrackLinkMapping;
class TransformPartPropertyTrackData;
class BaseMaterialDataPair;
class MaterialGridData;
class MaterialRelationPenetrationData;
class MaterialPropertyPhysicsData;
class MaterialPropertyFireData;
class ForceManagerSettings;
class LocalWindForceConeComponentData;
class LocalWindForceConeEntityData;
class LocalWindForceSphereComponentData;
class LocalWindForceSphereEntityData;
class LocalWindForceSamplerEntityData;
class LocalWindForceBaked3DAs2x2DTexComponentData;
class LocalWindForceBaked3DAs2x2DTexEntityData;
class HighlightEntity;
class TextSequenceEntity;
class ServerSubLevelEntity;
class FloatCacheEntity;
class StringEntity;
class Vector3Entity;
class TransformEntity;
class FloatEntity;
class IntEntity;
class BoolEntity;
class WaterHeightEntity;
class ScriptEntity;
class FloatCacheEntityData;
class StringEntityData;
class TransformEntityData;
class Vector3EntityData;
class FloatEntityData;
class IntEntityData;
class SyncedTransformEntityData;
class SyncedIntEntityData;
class SyncedFloatEntityData;
class SyncedBoolEntityData;
class BoolEntityData;
class MasterSkeletonAsset;
class BaseSkeletonAsset;
class SkeletonAsset;
class SoldierWeaponBlueprintBundle;
class ZoneVectorShapeData;
class VolumeVectorShapeData;
class GameSplineData;
class TerrainFillDecalData;
class OBBData;
class AABBData;
class SphereData;
class LakeData;
class VisibleAreaEntityData;
class FloatSelectEntityData;
class FloatCurveEntityData;
class TransformSelectorEntityData;
class SettingEntityData;
class IntegratorOrDifferentiatorEntityData;
class ProfileEntityData;
class CompareEntityData;
class RunningAverageEntityData;
class AbsEntityData;
class VectorMathOpEntityData;
class MathOpEntityData;
class PropertyCastEntityData;
class BoolToEventEntityData;
class SwitchPropertyStringEntityData;
class PropertyGateEntityData;
class EventGateEntityData;
class StopWatchEntityData;
class TransformToRotationEntityData;
class TransformModifierEntityData;
class RotationTransformBuilderEntityData;
class ScaleTransformBuilderEntityData;
class TransformBuilderEntityData;
class VecBuilderEntityData;
class VecSplitterEntityData;
class EulerTransformEntityData;
class EulerTransformSplitterEntityData;
class TransformSplitterEntityData;
class TransformBlendEntityData;
class TransformMultiplierEntityData;
class TransformHubEntityData;
class FloatHubEntityData;
class IntHubEntityData;
class BoolHubEntityData;
class SimpleDofParamConverterEntityData;
class SpriteDofParamConverterEntityData;
class ObjectVariationMultiSwitchEntityData;
class ObjectVariationSwitchEntityData;
class RandomDelayEntityData;
class DelayEntityData;
class EventAndGateEntityData;
class SelectEventEntityData;
class EventSwitchEntityData;
class UniqueIdEntityData;
class RandomIntEntityData;
class RandomFloatEntityData;
class RandomMultiEventEntityData;
class RandomEventEntityData;
class LocatorEntityData;
class CountDownEntityData;
class Or4EntityData;
class XorEntityData;
class OrEntityData;
class AndEntityData;
class NotEntityData;
class EntitySettings;
class WeaponFiringDataAsset;
class DataContainerAsset;
class SoldierWeaponCustomizationAsset;
class EmitterParamComponentData;
class WeaponZeroingComponentData;
class MissilePhysicsComponentData;
class SupplySphereEntityData;
class TripwireEntityData;
class ScriptEntityData;
class WaterHeightEntityData;
class WaterInteractWaveEntityData;
class WaterInteractTurbulenceDisturbEntityData;
class SchematicChannelEntityData;
class SchematicChannelAsset;
class UIScreenRenderEntityData;
class SpatialReferenceObjectData;
class LogicVisualEnvironmentReferenceObjectData;
class ObjectVariation;
class DataContainerCollectionBlueprint;
class LogicPrefabBlueprint;
class WorldData;
class LevelData;
class SoldierWeaponBlueprint;
class SoldierAsset;
class SoldierWeaponAsset;
class InterfaceDescriptorData;
class EffectSystemSettings;
class EffectBlueprint;
class EffectSystemComponent;
class EffectParameterList;
class EffectParameter;
class VisualEnvironmentEffectEntityData;
class EffectReferenceObjectData;
class EffectAsset;
class CompareIntRangeEntityData;
class CompareFloatRangeEntityData;
class CompareStringEntityData;
class CompareFloatEntityData;
class CompareIntEntityData;
class CompareBoolEntityData;
class OBBCollisionEntityData;
class SphereCollisionEntityData;
class NetworkRegistryAsset;
class MovieTrackData;
class RenderFramesTrackData;
class TimelineExtraData;
class TimelineTrackDataConditionsBase;
class PoseTrackKeyframe;
class TimelineEntityData;
class TimelineData;
class ServerVisibleAreaEntity;
class FloatSelectEntity;
class FloatCurveEntity;
class SettingEntity;
class IntegratorOrDifferentiatorEntity;
class ProfileEntity;
class CompareEntity;
class RunningAverageEntity;
class AbsEntity;
class VectorMathOpEntity;
class MathOpEntity;
class PropertyCastEntity;
class BoolToEventEntity;
class SwitchPropertyStringEntity;
class PropertyGateEntity;
class EventGateEntity;
class StopWatchEntity;
class TransformToRotationEntity;
class TransformModifierEntity;
class RotationTransformBuilderEntity;
class ScaleTransformBuilderEntity;
class TransformBuilderEntity;
class VecBuilderEntity;
class VecSplitterEntity;
class EulerTransformEntity;
class EulerTransformSplitterEntity;
class TransformSplitterEntity;
class TransformSelectorEntity;
class TransformBlendEntity;
class SimpleDofParamConverterEntity;
class SpriteDofParamConverterEntity;
class TransformMultiplierEntity;
class TransformHubEntity;
class FloatHubEntity;
class IntHubEntity;
class BoolHubEntity;
class ObjectVariationSwitchEntity;
class ObjectVariationMultiSwitchEntity;
class RandomDelayEntity;
class DelayEntity;
class SelectEventEntity;
class EventAndGateEntity;
class EventSwitchEntity;
class UniqueIdEntity;
class RandomIntEntity;
class RandomFloatEntity;
class RandomMultiEventEntity;
class RandomEventEntity;
class LocatorEntity;
class CountDownEntity;
class Or4Entity;
class XorEntity;
class OrEntity;
class AndEntity;
class NotEntity;
class WaterInteractWaveEntity;
class EmitterSystemSettings;
class EmitterEntityData;
class EmitterAsset;
class EmitterDocument;
class FlatEmitterDocument;
class EmitterTemplateData;
class ProcessorData;
class EvaluatorData;
class EmitterSystemComponent;
class EmitterExclusionVolumeData;
class ScalableEmitterDocument;
class UpdateQuadBendingAngleData;
class UpdateLinearVelocityData;
class UpdateOrientationData;
class UpdateClipScaleData;
class UpdateShaderParam01Data;
class UpdateShaderParam11Data;
class UpdateShaderParam10Data;
class UpdateShaderParam09Data;
class UpdateShaderParam08Data;
class UpdateShaderParam07Data;
class UpdateShaderParam06Data;
class UpdateShaderParam05Data;
class UpdateShaderParam04Data;
class UpdateShaderParam03Data;
class UpdateShaderParam02Data;
class UpdateShaderParam12Data;
class UpdateCollisionData;
class UpdateCameraProximityData;
class UpdateAlphaLevelScaleData;
class UpdateAlphaLevelMaxData;
class UpdateAlphaLevelMinData;
class UpdateRibbonTextureData;
class UpdateRibbonFadeData;
class UpdateTransparencyData;
class UpdateColorData;
class UpdateSizeZData;
class UpdateSizeYData;
class UpdateSizeXData;
class UpdateSizeData;
class UpdateRotationData;
class UpdateTextureCoordsData;
class EmitterData;
class TurbulanceData;
class AirResistanceData;
class WorldForcesData;
class WorldWindData;
class LocalForceData;
class GravityData;
class UpdateAgeData;
class SpawnColorRandomData;
class SpawnRotationSpeedData;
class SpawnOrientationData;
class SpawnRotationData;
class SpawnAnimationFrameData;
class SpawnAnimationData;
class SpawnPositionData;
class SpawnSizeData;
class SpawnSpeedData;
class SpawnDirectionData;
class SpawnPointCloudData;
class PreRollData;
class SpawnRibbonRateData;
class SpawnRateData;
class BaseEmitterData;
class PolynomialColorInterpData;
class ConstantEvaluatorData;
class CameraProximityEvaluatorData;
class SuperSphereEvaluatorData;
class SphereEvaluatorData;
class BoxEvaluatorData;
class RandomXYZEvaluatorData;
class RandomEvaluatorData;
class RotateVectorData;
class SampleTextureData;
class SplineData;
class PolynomialOperatorData;
class PolynomialData;
class DefaultEvaluatorData;
class EmitterEntity;
class ConnectivityEntityData;
class BreakableModelHealthComponentData;
class BreakableModelPhysicsComponentData;
class AnimatedDestructionComponentData;
class BreakableModelEntityData;
class EdgeModelComponentData;
class BreakableControllerComponentData;
class BreakablePartComponentData;
class ServerConnectivityEntity;
class ServerBreakableModelEntity;
class ServerBreakablePartComponent;
class ServerBreakableModelPhysicsComponent;
class ServerBreakableModelHealthComponent;
class ServerBreakableControllerComponent;
class ClientBreakableModelEntity;
class EdgeModelComponent;
class ClientBreakablePartComponent;
class ClientBreakableModelPhysicsComponent;
class ClientBreakableModelHealthComponent;
class ClientBreakableControllerComponent;
class DebrisClusterData;
class DebrisSystemSettings;
class DebrisSystemAsset;
class DebrisCluster;
class DebrisSpawnEvent;
class ServerDebrisCluster;
class ClientDebrisCluster;
class ClothSystemComponent;
class ClothSystemSettings;
class ClothRendererSettings;
class ClothInteractionComponentData;
class ClothComponentData;
class ClothAssetInstance;
class ClothObjectBlueprint;
class ClothEntityData;
class ClothEntity;
class ClothInteractionComponent;
class ClothComponent;
class ClothEntityManager;
class VoiceOverConversationGroupEntity;
class SoundScopeSetupEntity;
class SoundPauseEntity;
class SoundMasterEntity;
class SoundHdrEntity;
class SoundEntity;
class SoundEffectEntity;
class SoundDataEntity;
class IrReverbEntity;
class AudioGuideTrack;
class MixerEntity;
class AudioSettings;
class SoundAsset;
class SoundTestAsset;
class SoundTestSuite;
class SoundTestSpec;
class SoundTestTask;
class SoundTestTaskSpec;
class SoundTestEventTask;
class SoundTestParamTask;
class SoundTestTaskParam;
class SoundTestTransformTask;
class AudioSystemAsset;
class StreamPoolMapping;
class StreamPoolPreset;
class AudioLanguagesDependancyObject;
class AudioLanguageSetting;
class SoundMasterPatchAsset;
class SoundGraphAsset;
class SoundPatchAsset;
class AudioMaterialDefinitions;
class SoundDataAsset;
class StreamPoolAsset;
class StreamPoolSetup;
class SoundWaveAsset;
class ImpulseResponseAsset;
class SoundPatchConfigurationAsset;
class MixerEntityData;
class MixerSystemAsset;
class MixerAsset;
class AudioGraphData;
class MixerPreset;
class MixGroup;
class AudioGraphNodeData;
class AudioGraphNodeConfigData;
class MixerReceiveNodeConfigData;
class MixerEntryConfig;
class MixerSendNodeData;
class AudioGraphNodePortGroup;
class MixerReceiveNodeData;
class MixerReceiveEntry;
class MixerSetPropertyNodeData;
class MixerSetPropertyEntry;
class MixerSimplePresetNodeData;
class MixerOutputNodeData;
class MixerOutputEntry;
class MixerInputNodeData;
class MixerInputEntry;
class AudioGraphParameterConfigData;
class AudioGraphAssetParameterConfigData;
class AudioGraphValueParameterConfigData;
class MixerSendNodeConfigData;
class MixerGraphData;
class MixerValueNodeData;
class MixerSendEntry;
class AudioGraphParameter;
class AudioGraphEvent;
class AudioGraphAssetParameter;
class ParameterRouterNodeData;
class ParameterRouterEntry;
class KeepAliveNodeData;
class EventSequencerNodeData;
class EventSequencerOutEvent;
class ValueSelectorNodeData;
class ValueSelectorEntry;
class TimerNodeData;
class SwitcherNodeData;
class SwitcherEntry;
class SimpleValueSelectorNodeData;
class MultipleTransformNodeData;
class MultipleTransformEntry;
class SimpleTransformNodeData;
class SequenceGeneratorNodeData;
class SendNodeData;
class SendEntry;
class ScaleClampNodeData;
class ReceiveNodeData;
class ReceiveEntry;
class RangeMapperNodeData;
class ParameterFilterLinearNodeData;
class ParameterFilterLpNodeData;
class NumberGeneratorNodeData;
class MultiCrossfaderNodeData;
class MultiCrossfaderGroup;
class MinMaxValueSelectorNodeData;
class MinMaxValueSelectorEntry;
class MinMaxNodeData;
class LogicalExpressionNodeData;
class LogicalExpressionEntry;
class LinkSendNodeData;
class LinkSendNodeEntry;
class LinkReceiveNodeData;
class LinkReceiveNodeEntry;
class LinearTransformNodeData;
class LfoNodeData;
class FollowEnvelopeNodeData;
class EventSwitcherNodeData;
class EventSwitcherEntry;
class EventGateNodeData;
class DeMuxNodeData;
class DeMuxOutput;
class DeltaNodeData;
class DeltaGroup;
class EventDebugNodeData;
class DebugEventInput;
class ValueDebugNodeData;
class DebugValueInput;
class Crossfader2NodeData;
class ConditionNodeData;
class ConditionGroup;
class AdsrNodeData;
class VoiceOverSystemAsset;
class VoiceOverPronunciation;
class VoiceOverConversationQueueGroup;
class VoiceOverManuscriptAsset;
class FinalDraftLineInfo;
class FinalDraftManuscriptAsset;
class VoiceOverLanguageRoot;
class VoiceOverLogicAsset;
class VoiceOverGroup;
class VoiceOverLogicFlowConfigData;
class VoiceOverLogicFlow;
class VoiceOverNodeConfigData;
class VoiceOverNode;
class VoiceOverTriggerParameter;
class VoiceOverEventNodeConfigData;
class VoiceOverStructureNode;
class VoiceOverConversationNodeConfigData;
class VoiceOverConversationNode;
class VoiceOverDialogGroup;
class VoiceOverDialogTrack;
class VoiceOverDialogClip;
class VoiceOverDialogClipEvents;
class VoiceOverContainerNodeConfigData;
class VoiceOverContainerNode;
class VoiceOverTriggerNode;
class VoiceOverVariableNodeConfigData;
class VoiceOverExpressionNode;
class VoiceOverProbabilityNodeConfigData;
class VoiceOverProbabilityNode;
class VoiceOverLabelNodeConfigData;
class VoiceOverLabelNode;
class VoiceOverLabelSource;
class VoiceOverIntervalNodeConfigData;
class VoiceOverIntervalNode;
class VoiceOverInfoNodeConfigData;
class VoiceOverInfoNode;
class VoiceOverGlobalNodeConfigData;
class VoiceOverGlobalNode;
class VoiceOverDistanceNodeConfigData;
class VoiceOverDistanceNode;
class VoiceOverConstantNodeConfigData;
class VoiceOverConstantNode;
class VoiceOverConstantValue;
class VoiceOverConstantGlobalValue;
class VoiceOverConstantFloatValue;
class VoiceOverConstantIntegerValue;
class VoiceOverConstantBooleanValue;
class VoiceOverGlobalConstantValue;
class VoiceOverConstantVectorValue;
class VoiceOverCompareNodeConfigData;
class VoiceOverCompareNode;
class VoiceOverArithmeticNodeConfigData;
class VoiceOverArithmeticNode;
class VoiceOverStructureConnection;
class VoiceOverRelationshipInput;
class VoiceOverVariableNode;
class EntityVoiceOverInfo;
class VoiceOverInterval;
class VoiceOverLabel;
class VoiceOverValueRedirect;
class VoiceOverTriggerNodeConfigData;
class VoiceOverEventNode;
class VoiceOverEvent;
class VoiceOverValue;
class VoiceOverNamedValue;
class VoiceOverObject;
class MusicPlayerNodeData;
class MusicPlayerEntry;
class MusicFadeData;
class MusicBaseAsset;
class MusicPlaylistSelector;
class MusicAsset;
class MusicPlaylistAsset;
class MusicTransition;
class MusicSelector;
class OverlayControl;
class MusicInterfaceAsset;
class MusicPlayableData;
class MusicStreamableData;
class MusicSegmentData;
class MusicPhraseData;
class MusicOverlayData;
class MusicInputData;
class MusicEventData;
class MusicParameterData;
class SoundPauseEntityData;
class SoundHdrEntityData;
class IrReverbEntityData;
class VoiceOverConversationGroupEntityData;
class SoundScopeSetupEntityData;
class SoundDataEntityData;
class SoundMasterEntityData;
class SoundEntityData;
class SoundEffectEntityData;
class AudioGuideTrackData;
class AudioGuideKeyframe;
class SoundScopeStageData;
class DuplicateSpawnScopeStageData;
class MaxInstancesScopeStageData;
class SoundScopeSetupData;
class SoundScopeStrategyData;
class PropertySortScopeStageData;
class SoundScopeData;
class SoundWaveVariation;
class SoundDataPolicy;
class EqualizerSettings;
class CompressorSettings;
class MasterUnitSettings;
class HdrSetting;
class SoundGraphData;
class SoundBusData;
class PointEnvelope;
class AudioLanguage;
class VuMeterNodeData;
class VibratoNodeData;
class WaveSwitcherNodeConfigData;
class WaveSwitcherNodeData;
class UserMusicControllerNodeData;
class UserMusicArbiterNodeData;
class TimeStretchNodeData;
class SamplerNodeData;
class RouteNodeData;
class RouteEntry;
class IrReverbControllerNodeData;
class IrReverbNodeData;
class PhysicsNodeData;
class Pan2dNodeData;
class PhysicsEntry;
class PeakingIir2NodeData;
class OrientationNodeData;
class OutputNodeConfigData;
class OutputNodeData;
class FlatOutputNodeConfigData;
class FlatOutputNodeData;
class DirectOutputNodeData;
class ConeOutputNodeConfigData;
class ConeOutputNodeData;
class MixerNodeData;
class MixerEntry;
class MatrixPannerNodeData;
class MasterUnitNodeData;
class LowShelfIir2NodeData;
class LowPassIir2NodeData;
class LowPassFir64NodeData;
class LowPassButterworthNodeData;
class LimiterNodeData;
class HighShelfIir2NodeData;
class HighPassIir2NodeData;
class HighPassFir64NodeData;
class HighPassButterworthNodeData;
class GainFaderNodeData;
class GainNodeData;
class FrequencyShiftSsbNodeData;
class FlangerNodeData;
class DivisibleLoopPlayerNodeData;
class ExpanderNodeData;
class DistortionClipNodeData;
class DialogSamplerNodeData;
class DelayNodeData;
class DacNodeData;
class CrossfaderNodeData;
class CompressorNodeData;
class ChorusNodeData;
class BusNodeData;
class BandPassIir2NodeData;
class BandPassFir64NodeData;
class AiffWriterNodeData;
class AssetBank;
class Animatable;
class AntMemorySettings;
class AntSettings;
class AntAnimationSetAsset;
class ProceduralAwarenessAntRefs;
class AntProjectAsset;
class AntStateAsset;
class SceneOpMatrix;
class ThreadSettings;
class ResourceManagerSettings;
class CharacterAsset;
class AssemblyDescriptorData;
class SettingsBundleAsset;
class WebBrowserSettings;
class MedicBagHealingSphereEntityData;
class MissileEntityData;
class WebBrowserBundleAsset;
class TimingViewSettings;
class PerfJournalSettings;
class ChunkOnlyResourceType;
class ProxyResourceObject;
class WaterInteractSettings;
class DebugRenderSettings;
class UIImageDataBinding;
class UIPageHeaderBinding;
class UINumberDataBinding;
class UICompassDataBinding;
class UIBarDataBinding;
class UITextDataBinding;
class UICrosshairDataBinding;
class UIWidgetPathBinding;
class UIHUDMessageBinding;
class UIButtonDataBinding;
class UINestedListDataBinding;
class UIListDataBinding;
class LoadingMusicEntityData;
class UICustomize3DModelEntityData;
class UICustomizeStateEntityData;
class PLMStoreGameStateData;
class PLMRestoreGameStateData;
class UINPXTooltipEntityData;
class UINPXLine;
class UINPXPaddingLine;
class UINPXTextLine;
class UINPXConceptTooltipLine;
class UINPXMenuTooltipLine;
class UINPXTooltipLine;
class UINPXImageLine;
class UITooltipEntityData;
class UIButtonsTextureAtlasAsset;
class UICreditsAsset;
class UIMinimapIconTextureAtlasAsset;
class UIMinimapIconTextureCategory;
class UIItemDescriptionAsset;
class UIDistanceFieldAsset;
class UIItemDescription;
class UIAnimatedTextureAsset;
class UIMessageTriggerData;
class StaticConfigAsset;
class HudConfigAsset;
class MenuConfigAsset;
class SoldierSuppressionComponentData;
class SuppressionSettings;
class StoreAsset;
class StatCategoriesBaseTree;
class StatCategoriesTree;
class CriteriaData;
class CriteriaGateList;
class StatCategoryTreeCollection;
class StatsCategoryBaseData;
class StatsCategoryData;
class StatCategoriesGuidTree;
class StatsCategoryGuidData;
class StatCategoriesScoringBucketTree;
class StatsCategoryScoringBucketData;
class StatCategoriesVehicleStateTypeTree;
class StatsCategoryVehicleStateTypeData;
class StatCategoriesScoreboardPositionTree;
class StatsCategoryScoreboardPositionData;
class StatCategoriesPlayerRoleTree;
class StatsCategoryPlayerRoleData;
class StatCategoriesKitTree;
class StatsCategoryKitData;
class StatCategoriesWeaponAccessoryTree;
class StatsCategoryWeaponAccessoryData;
class StatCategoriesAwardTree;
class StatsCategoryAwardData;
class StatCategoriesDifficultyTree;
class StatsCategoryDifficultyData;
class StatCategoriesLevelTree;
class StatsCategoryLevelData;
class StatCategoriesVehicleTree;
class StatsCategoryVehicleData;
class StatCategoriesWeaponTree;
class StatsCategoryWeaponData;
class StatCategoriesRankTree;
class StatsCategoryRankData;
class SpottingTargetComponentData;
class SpottingComponentData;
class SpectatorAreaEntityData;
class SpectatorEntityData;
class EsportsSpectatorEntityData;
class SpectatorViewData;
class SpectatorViewComponentData;
class FreeCameraSpectatorViewComponentData;
class TargetCameraSpectatorViewComponentData;
class CollidableFreeCameraData;
class ControllableChaseCameraData;
class SoldierSteeringComponentData;
class ScoringHandlerData;
class FieldUpgradeScoringHandlerData;
class SuppressionScoringHandlerData;
class SpottingScoringHandlerData;
class OrderBonusScoringHandlerData;
class NotifyClientScoringHandlerData;
class OnLevelScoringHandlerData;
class LockingScoringHandlerData;
class KillFromVehicleScoringHandlerData;
class DestroyAllInSquadScoringHandlerData;
class DamageScoringHandlerData;
class CapturePointScoringHandlerData;
class AvengerScoringHandlerData;
class CTFScoringHandlerData;
class ScoringTypeData;
class ScoringData;
class ScoringBucketData;
class RSPSettings;
class RankParamsAsset;
class RankLevelData;
class PremiumAsset;
class PointSystemParamsAsset;
class PlayerTypeProfile;
class StatSpamSettings;
class StaticUnlockList;
class SkillLevelParameters;
class PersistenceSettings;
class PersistenceConfiguration;
class UISpecializationMetaData;
class PS3StoreImageHD1080;
class PS3StoreImageSD;
class UILicenseDescription;
class UIGenericItemDescription;
class UILevelLocationDescription;
class UIMatchmakingDescription;
class UILevelDescription;
class UIVehicleUnlockDescription;
class UIWeaponAccessoryDescription;
class UIVehicleWeaponDescription;
class UIVehicleDescription;
class UISoldierAppearanceDescription;
class UIBoostDescription;
class UIBattlepackItemDescription;
class UIKitItemDescription;
class UIWeaponDescription;
class UIModDescription;
class UIGameModeDescription;
class UIRankDescription;
class UIBattlepackDescription;
class UIDogTagDescription;
class UIAwardDescription;
class BFUIWidgetEntityData;
class UISquadDeployListWidgetData;
class UIBadConnectionWidgetData;
class UIPremiumGlowWidgetData;
class UIPremiumIconWidgetData;
class UIPauseTransitionWidgetData;
class UICustomEmblemWidgetData;
class UIAwardPresentationWidgetData;
class UIGameModeEventWidgetData;
class UICustomizeItemListWidgetData;
class UITabBarWidgetData;
class UICustomizeSlotsWidgetData;
class UICreditsWidgetData;
class UILoadingProgressWidgetData;
class UIKillCardBarWidgetData;
class UICommanderPresenceWidgetData;
class UIVoipStatusWidgetData;
class UISPFriendsLeaderboardWidgetData;
class UIPerformanceTestWidgetData;
class UITextEntryListWidgetData;
class UIVoiceCommandsListWidgetData;
class UIDynamicGamertagWidgetData;
class UIOptionsManagerWidgetData;
class UISpectatorWidgetData;
class UISoldierStatusWidgetData;
class UISpectatorPlayerInfoWidgetData;
class UISpectatorPlayerCardWidgetData;
class UICustomizationDisplayAsset;
class UICustomizationCategoryOrdering;
class UIHighlightWidgetData;
class UISpectatorSquadBoxWidgetData;
class UISpectatorPlayerNameWidgetData;
class UISpectatorViewInputWidgetData;
class UISpectatorSquadsWidgetData;
class UISpectatorCameraBarWidgetData;
class UISpectatorPlayerBarWidgetData;
class UISpectatorSelectorBarWidgetData;
class UISpectatorRootWidgetData;
class UISpectatorScoreBarWidgetData;
class BFUICppScreenData;
class UISpectatorTableTopScreenData;
class UISpectatorScreenData;
class UIKillerInfoWidgetData;
class UIRevivalScreenWidgetData;
class UIRevivalScreenData;
class UIBatteryMeterWidgetData;
class UICommanderStatusWidgetData;
class UITitanScoringInfoWidgetData;
class UISpChapterIntrodutionWidgetData;
class UIMenuHintWidgetData;
class UITopStoryPopupWidgetData;
class WidgetMovieData;
class UIMainMenuFriendsWidgetData;
class UIMainMenuCommerceWidgetData;
class UIMainMenuPersistenceWidgetData;
class UIEmergencyTickerWidgetData;
class UIMainMenuGamerWidgetData;
class UIMainMenuTopStoryWidgetData;
class UIMainMenuOverlayWidgetData;
class UISpectatorSquadPlayerWidgetData;
class UICalibrateTVScreenWidgetData;
class UIGadgetInfoWidgetData;
class UIServerBrowserWidgetData;
class UIAirRadarWidgetData;
class UIBigMapWidgetData;
class UIServerBrowserFiltersWidgetData;
class UIPreRoundInfoWidgetData;
class UIPreRoundRootWidgetData;
class UIManageServerRootWidgetData;
class UIMyServersWidgetData;
class UITextListWidgetData;
class UITwoLinerWidgetData;
class UIManagePlayersWidgetData;
class UIIngameMapRotationWidgetData;
class UIServerInfoWidgetData;
class UIOptionsScreenAdjustScreenData;
class UISpectatorOptionsManagerWidgetData;
class UIOptionsKeybindingsWidgetData;
class UIOptionsListWidgetData;
class UIOptionsConsoleControlsWidgetData;
class UIOptionControlTextFieldMapping;
class UIOptionControlTextFieldMapping_UnaryChanging;
class UIOptionControlTextFieldMapping_NonChanging;
class UIOptionControlTextFieldMapping_BothChanging;
class UIOptionsVideoWidgetData;
class CustomOptionData;
class SquadDeployQuickmatchData;
class UIPageChildWidgetData;
class UICustomizeVehiclesTabBarWidgetData;
class BFUIWorldIconBehavior;
class BFUIElementColorizedFillEntityData;
class BFUIElementColorizedBitmapEntityData;
class BFUIElementColorizedTextFieldEntityData;
class BFUIElementButtonBarButtonEntityData;
class BFUIElementButtonBarPressAndReleaseButtonEntityData;
class BFUIButtonBarData;
class UIElementStatbarBaseEntityData;
class BFUIElement3SliceStatbarStyle;
class BFUIElement3SliceStatbarAlignedStyle;
class UIElementStatbarEntityData;
class BFUIElement3SliceStatbarEntityData;
class UIElementStatbarStyle;
class BFUIIMSettingsAsset;
class UINametagConfiguration;
class UIWebViewWidgetData;
class UIIngameBoostsWidgetData;
class UIIngameMenuWidgetData;
class UIObliterationBombWidgetData;
class UIKillScreenWidgetData;
class UISPProgressionWidgetData;
class UISPProgressionDataWidgetData;
class UISPLoadingWidgetData;
class UIMPLoadingWidgetData;
class UIDeployZoomWidgetData;
class UISoldierProgressionGridWidgetData;
class UIWeaponSelectorGridWidgetData;
class UIWeaponSelectorSlotDisplayData;
class UIDeployButtonWidgetData;
class UISubtitlesWidgetData;
class UICommanderSquadStatusWidgetData;
class UICommanderAssetStatusWidgetData;
class UIObjectiveStatusBarWidgetData;
class UIEventLogWidgetData;
class UIPlayerFrustumWidgetData;
class UINotificationMessageWidgetData;
class UIObjectiveHintWidgetData;
class UITurretRotationWidgetData;
class UIAltitudeMeterWidgetData;
class UIBankAngleWidgetData;
class UIPitchLadderWidgetData;
class UIVehicleCompassWidgetData;
class UICompassWidgetData;
class UIBuildInfoWidgetData;
class UIPassengerListWidgetData;
class UIProgressionBarWidgetData;
class UISquadBarWidgetData;
class UICommanderBarWidgetData;
class UISquadListWidgetData;
class UIVehicleLoadoutSlotWidgetData;
class UIKitLoadoutSlotWidgetData;
class UIKitLoadoutSlotHandlerWidgetData;
class UIReceiveDamageIndicatorWidgetData;
class UILockWarningIndicatorWidgetData;
class UISensingIndicatorWidgetData;
class UIHitIndicatorWidgetData;
class UIObjectiveWidgetBaseData;
class UIMinimapObjectiveWidgetData;
class UIObjectiveWidgetData;
class UIButtonBarWidgetData;
class UICCTVWidgetData;
class UIScoringWidgetData;
class UICommanderVehicleWidgetData;
class UIDeployScreenData;
class UIChatWidgetData;
class UIJavelinIndicatorWidgetData;
class UIInteractionWidgetData;
class UIHudInventoryWidgetData;
class UIBattledashCreateChallengeConfirmWidgetData;
class UIBattledashCreateChallengeInvitesWidgetData;
class UIBattledashCreateChallengeWidgetData;
class UIBattledashChallengesPageWidgetData;
class UIBattledashFriendsPageWidgetData;
class UIBattledashListBlockWidgetData;
class UIBattledashHListWidgetData;
class UIBattledashAutoListWidgetData;
class UIBattledashChallengeDetailsWidgetData;
class UIBattledashFriendDetailsWidgetData;
class UIBattledashHomeWidgetData;
class UIBattledashPlaygroupPageWidgetData;
class UIBattledashWidgetData;
class UIBasicLoadingIndicatorWidgetData;
class UIMinimapUAVWidgetData;
class UIMinimapOrdersWidgetData;
class UIMinimapLineStyle;
class UIMinimapColorStyle;
class UIIndirectFireIconsWidgetData;
class UICommanderMinimapIconsWidgetData;
class UIMinimapIconsWidgetData;
class UINuiImageFeedbackWidgetData;
class UINuiSkeletonFeedbackWidgetData;
class UINuiSpeechFeedbackWidgetData;
class UINuiFeedbackWidgetData;
class UINPXTooltipWidgetData;
class UITooltipWidgetData;
class UICustomizeProgressionWidgetData;
class UIUnlockRequirementWidgetData;
class UIWeaponAccessoryInfoWidgetData;
class UIWeaponCompareWidgetData;
class UIEquipmentSwitchWidgetData;
class UIMinimapVisualWidgetData;
class UIScoreboardWidgetData;
class UIScoreboardRootWidgetData;
class UISpectatorSoldierStatusWidgetData;
class UIHudFloodFillWidgetData;
class UIHudBackgroundWidgetData;
class UICommoRoseWidgetData;
class UIDataKeyBitmapWidgetData;
class UIBattlepackOpeningWidgetData;
class UIStepperWidgetData;
class UIBattlepacksMenuWidgetData;
class UIVideoPlayerWidgetData;
class UIDiscSwapBackgroundWidgetData;
class UIGenericWidgetData;
class UICrosshairWidgetData;
class UIInputDebuggingWidgetData;
class UIBattlescreenUIWidgetData;
class UIBattlescreenUIScreenData;
class UIServerSettingsScreenData;
class UIBattledashRootWidgetData;
class UIOptionSelectorWidgetData;
class UIKillScreenData;
class UILoadingScreenData;
class UIInputDebuggingScreenData;
class UINuiFeedbackScreenData;
class UICommoRoseScreenData;
class UIIngameMenuBackgroundScreenData;
class UICommanderVehicleScreenData;
class UIJavelinWidgetData;
class UIJavelinScreenData;
class UIWorldIconsScreenData;
class UIMinimapScreenData;
class UIHudScreenData;
class UICurrentCommanderWidgetData;
class UIAvailableSquadsWidgetData;
class UITeamSetupWidgetData;
class UITeamSetupScreenData;
class UIGenericScreenData;
class UISquadDeployMembersWidgetData;
class UISpectatorOptionsScreenData;
class SyncedBFSettings;
class BFDedicatedServerSettings;
class BFServerConfiguration;
class BFServerSettings;
class BFPersistenceData;
class ConsumableUnlockSetup;
class ConsumableUnlock;
class PersistentCriteriaStatRef;
class PersistentAwardDataStatRef;
class PresencePartyManagerServiceData;
class PresenceAuthenticationServiceData;
class PresenceFriendsStatsServiceData;
class PresenceStoreServiceData;
class PresenceXPromoServiceData;
class PresenceDownloadServiceData;
class PresenceCalendarServiceData;
class PresenceGameConfigurationServiceData;
class PresenceRspServiceData;
class PresenceConsoleNewsServiceData;
class PresenceChallengesServiceData;
class PresenceServerBrowserServiceData;
class PresenceEntitlementServiceData;
class PresencePushNotificationServiceData;
class PresenceBattlelogServiceData;
class PresenceBlobServiceData;
class PlaygroundServerBackendData;
class PeerServerBackendData;
class NucleusPresenceBackendData;
class OriginPresenceBackendData;
class WebPresenceBackendData;
class BFBlazeServerBackendData;
class BattlelogConfigData;
class BFGameParametersData;
class CalendarBattlepacksAsset;
class CalendarBattlepackDrop;
class BoostData;
class BattlepackPool;
class BattlepackPoolList;
class BattlepackRow;
class BattlepackSlot;
class BattlepackSet;
class BattlepackSetList;
class BattlepackGroup;
class BattlepackTable;
class UnlockGroup;
class UnlockTable;
class BattlepackAsset;
class BattlepackData;
class AwardableTreeBase;
class AwardDataTree;
class AbstractAwardData;
class AwardData;
class AwardStarNameData;
class AwardAchievementData;
class AwardHeaderData;
class AwardStarData;
class CriteriaStarData;
class CriteriaStarCategoryData;
class AIStateEntityData;
class BFWaypointsShapeData;
class AILocoComponentData;
class AbstractLocoWaypointData;
class VaultWaypointData;
class CoverWaypointData;
class ScenarioWaypointData;
class StandardMoveWaypointData;
class AdvertisementComponentData;
class AdvertisementLevelDescriptionComponent;
class XdpExportAsset;
class XdpStatListAsset;
class CamoUnlockAsset;
class BFUnlockAsset;
class VeniceUnlockUserData;
class DeploySettings;
class MinimapSettings;
class VeniceUISettings;
class VeniceUIConfiguration;
class UIFlagCounterCompData;
class UISoldierInfoCompData;
class UIPlmCompData;
class UISocialStatisticsCompData;
class UIBoostCompData;
class UIPackCompData;
class UIEliminationPreEorCompData;
class UIPurchaseServerCompData;
class UINewStoreCompData;
class UICommerceCompData;
class UIConsoleNewsCompData;
class UIPremiumCompData;
class UIDeployCompData;
class UIMatchCompData;
class UIMatchesListCompData;
class UICreditsCompData;
class UIInstallHDContentCompData;
class UIMySoldierAssignmentsCompData;
class UIAssignmentsCompData;
class UIManageMapsCompData;
class UIManagePlayersCompData;
class UILocalizeCompData;
class UIManageServerPresetsCompData;
class UIOnDemandFontComponentData;
class UISetupServerWizardCompData;
class UITrainingCompData;
class UITextureStreamingComponentData;
class UISpectatorCompData;
class UIKillCounterCompData;
class UICampaignCompData;
class UISpawnLogicCompData;
class UIBattleLogChallengesCompData;
class UIBattledashCompData;
class UIBattleLogCompData;
class UIPlaygroupCompData;
class UIConnectionCompData;
class UIPersistenceCompData;
class UIIngameMenuCompData;
class UISettingsCompData;
class UIEndOfRoundCompData;
class MenuIdAsset;
class UIHardcoreCompData;
class UIMemCardCompData;
class UIPopupCompData;
class UIVoiceCompData;
class UIFriendsCompData;
class UIChatCompData;
class UIAwardsScreenCompData;
class UIQueuedEventsCompData;
class UIScoreboardCompData;
class UILeaderboardCompData;
class UIIMCompData;
class UIVehicleCompData;
class UILifeCounterCompData;
class UIUnlocksCompData;
class UIKillCardCompData;
class UIDetailedServerInfoCompData;
class UIGameQueueCompData;
class UIServerListFilterBarCompData;
class UIServerListCompData;
class UICommanderCompData;
class UISquadCompData;
class UICombatAreaCompData;
class UISoldierCompData;
class UIDamageIndicatorCompData;
class UICustomizationCompData;
class UIWidgetEventCompData;
class UITicketCounterCompData;
class UIWeaponCompData;
class UITeamCompData;
class UISpawnPointCompData;
class UILevelCompData;
class FrontEndComponentData;
class DiscComponentData;
class UserComponentData;
class UILightExposureComponentData;
class UIObjectivesCompData;
class UIPresenceCompData;
class UIPostProcessComponentData;
class UIDirectAccessCompData;
class UIScreenEventCompData;
class UIDataInterfaceCompData;
class UISessionDataComponentData;
class UIVehicleLockingCompData;
class UIWorldIconCompData;
class UIMinimap2DCompData;
class PlayerInteractionViewData;
class SpawnSubViewData;
class BFNamedCharacterSpawnTemplateData;
class BFSoldierPhysicsComponentData;
class BFSoldierHealthComponentData;
class VeniceSoldierHealthModuleData;
class VeniceOnlineSettings;
class BFLockingTypeAsset;
class BFCrosshairTypeAsset;
class VeniceUICombatAreaAsset;
class TitanGameStatsEntityData;
class ClientPausedEntityData;
class ClientEnteredIngameEntityData;
class PlayerLogoEntityData;
class FlagCounterEntityData;
class TeamLogoMapping;
class AwardListenerEntityData;
class RoundOverEntityData;
class PreRoundEntityData;
class EliminationPreRoundEntityData;
class Minimap2DEntityData;
class Minimap2DTextureAsset;
class PlayerAliveFilterEntityData;
class SoldierTestEntityData;
class CapturePointEntityData;
class TicketCounterEntityData;
class VehicleCriticalHitTriggerEntityData;
class StatEventTriggerEntityData;
class PlayerUtilEntityData;
class AutoTeamEntityData;
class ControlInputEntityData;
class BFTeamEntityData;
class AutoSquadEntityData;
class ConsumableTriggerEntityData;
class VeniceVehicleCustomizationAsset;
class VeniceSoldierWeaponCustomizationAsset;
class BFClassSpecialization;
class VeniceSoldierCustomizationAsset;
class PlayerLogoComponentData;
class SoldierEmoteComponentData;
class SoldierEmoteNetworkedMessageMapping;
class PerfHudSettings;
class XBoneSystemCommandStatusEntityData;
class InputMessageTriggerEntityData;
class NuiSpeechTriggerEntityData;
class GrammarStateEntityData;
class NuiSpeechSetupEntityData;
class NuiSpeechPhrase;
class NuiSpeechComplexPhrase;
class NuiSpeechPhraseComponent;
class NuiSpeechSquadNames;
class NuiSpeechListPhraseComponent;
class NuiSpeechListElement;
class NuiSpeechSquadNameComponent;
class NuiSpeechDataSetPhrase;
class NuiSpeechInputActionPhrase;
class NuiSpeechDirectPhrase;
class NuiSpeechEntityPhrase;
class NuiSpeechFocusPointPhrase;
class NuiSpeechCommorosePhrase;
class NuiSpeechCommanderComplexPhrase;
class NuiSpeechConfidencePolicy;
class NuiSpeechConfidencePlatformSetupEntry;
class NuiSpeechDefaultConfidencePlatformSetup;
class NuiSpeechGen4aConfidencePlatformSetup;
class NuiSpeechConfidencePlatformSetup;
class NuiSpeechConfidenceDialectPolicy;
class NuiSpeechConfidencePlatformPolicy;
class NuiSpeechConfidencePolicySetup;
class NuiSpeechGrammarBundleAsset;
class NuiSpeechGrammarAsset;
class NuiSpeechCompiledGrammar;
class NuiSpeechPhraseVariation;
class NuiSpeechLevelConfiguration;
class NuiSpeechSettings;
class NuiSpeechDialect;
class ManualDataAsset;
class LookAtEntityData;
class BFTimeNudgeBiasEntityData;
class FactionEntityData;
class TeamIdToIntEntityData;
class BFBoolEventEntityData;
class UIEndOfRoundEntityData;
class InspectEntityData;
class LiveServerProxySettings;
class LevelProgressEntityData;
class LevelDescriptionOverrideEntityData;
class BFOnlineLevelDescriptionComponent;
class BFPersistenceConfigurationLevelDescriptionComponent;
class VeniceMatchmakingLevelDescriptionComponent;
class VeniceGameplayLevelDescriptionComponent;
class UICoopLevelDescription;
class UILevelDescriptionComponent;
class UILevelLoadData;
class GeographicalLevelDescriptionComponent;
class GeographicalData;
class SoldierLeaningComponentData;
class GameTipAsset;
class GameModeSettings;
class GameModeConfiguration;
class FriendlyFireEntityData;
class FreeStreamingChunksSettings;
class ExplosivesTrackingComponentData;
class ExplosivesTrackerEntityData;
class EmblemSettings;
class DogTagsAsset;
class DogTagData;
class BasicDogTagData;
class AdvancedDogTagData;
class DirectionHintEntityData;
class CommanderMapInfoEntityData;
class CommanderEntityData;
class CommanderAssetData;
class CommanderActionBaseData;
class SquadWipeProtectionActionData;
class ReinforceSquadActionData;
class HighValueTargetActionData;
class ProxyAttackActionData;
class GunshipDeployActionData;
class SatelliteEMPActionData;
class RadarScanActionData;
class InfantryScanActionData;
class EarlyWarningActionData;
class VehicleScanActionData;
class LaunchTomahawkActionData;
class PromoteSquadActionData;
class DefenseDropActionData;
class VehicleSpawnActionData;
class SupplyDropActionData;
class OrderActionData;
class SectorJamActionData;
class SectorScanActionData;
class ParaDropActionData;
class ChatSettings;
class ServerPathfindingStreamEntity;
class ServerNavPowerSystemEntity;
class ServerWaypointTriggerEntity;
class ServerPathFollowingComponent;
class ServerFollowWaypointsEntity;
class ServerFollowObjectEntity;
class ServerBFOrderEntityBase;
class ServerBFFollowWaypointsOrder;
class ServerBFCancelOrder;
class ServerBFParameterEntity;
class ServerBFTacticEntity;
class ServerBFShootAtTargetsEntity;
class ServerBFUseWaypointsEntity;
class ServerBFUseCoverEntity;
class ServerBFWeaponOverrideEntity;
class ServerBFVehicleBehaviorEntity;
class ServerBFSensingParameterEntity;
class ServerBFIdleBehaviorEntity;
class ServerBFCombatBehaviorEntity;
class ServerBFParameterWithShapeEntity;
class ServerBFForbiddenAreaEntity;
class ServerBFFriendlyAreaEntity;
class ServerBFFlankingCorridorEntity;
class ServerBFDefendAreaEntity;
class ServerBFFollowAreaEntity;
class ServerBFCombatGroupEntity;
class ServerBFKillCounterEntity;
class ServerBFAI2SystemEntity;
class BFConcealmentVolumeEntity;
class ConcealmentEntity;
class ServerBFCoverEntity;
class ServerBFCoverGroupEntity;
class ServerBFBrainComponent;
class ServerBFAIScopeGlintComponent;
class SensingTemplateData;
class AIDifficultyData;
class SensingSettings;
class SensingComponentData;
class AIWeaponData;
class MobilityData;
class ArmamentData;
class TurretData;
class AIAimingConstraintsData;
class AIEntryData;
class AIVehicleTypes;
class UrgencyUserData;
class AIVehicleBehaviourData;
class BehaviourData;
class UrgencySetData;
class GameTweakData;
class FiringPatternCollectionData;
class BFVehicleCombatEntityData;
class VehicleCombatSettings;
class BFSoldierSpawnTemplateData;
class SoldierTactics;
class SquadEngageSettings;
class SquadMovementSettings;
class CloseCombatSettings;
class FleeSettings;
class HideSettings;
class AttackSettings;
class ChargeSettings;
class VehicleSettings;
class ProjectileSettings;
class PoseSettings;
class CoverControlSettings;
class MoveSettings;
class StartStopSettings;
class SprintSettings;
class WalkSettings;
class BFSpawnData;
class BFParameterEntityData;
class BFTacticEntityData;
class BFShootAtTargetsEntityData;
class AI2PointTargetData;
class BFUseWaypointsEntityData;
class BFUseCoverEntityData;
class BFWeaponOverrideEntityData;
class BFVehicleBehaviorEntityData;
class BFCombatBehaviorEntityData;
class BFParameterWithShapeEntityData;
class BFFollowAreaEntityData;
class BFFriendlyAreaEntityData;
class BFFlankingCorridorEntityData;
class BFDefendAreaEntityData;
class BFSensingParameterEntityData;
class BFIdleBehaviorEntityData;
class BFForbiddenAreaEntityData;
class BFCombatGroupEntityData;
class BFOrderEntityBaseData;
class BFFollowWaypointsOrderEntityData;
class BFCancelOrderEntityData;
class BFKillCounterData;
class BFCoverEntityData;
class BFCoverGroupEntityData;
class CoverQueryData;
class CoverQueryScoreBase;
class CoverQuerySpatialBase;
class CoverQuerySpatialWithinRestrictedArea;
class CoverQuerySpatialWithinRadius;
class CoverQuerySpatialWithinWeaponRange;
class BFCoverConstantData;
class BFCoverZoneDefinition;
class BFConcealmentVolumeEntityData;
class BFConcealmentEntityData;
class BFBrainComponentData;
class BFAIWeaponData;
class WeaponHitProbability;
class SpecialBehavior;
class PreferredRange;
class WeaponRestrictions;
class DamageModifier;
class SuppressedBehavior;
class VehicleInaccuracySettings;
class TargetModifier;
class FlashlightModifier;
class HearingModifier;
class VisionModifier;
class SprayPattern;
class BurstIntervalPattern;
class FiringIntervalPattern;
class VehicleAimerSettings;
class BFAIScopeGlintComponentData;
class BFAIProjectileComponentData;
class BFAIDebugProxyData;
class BFAIActionEntityData;
class BFAI2SystemEntityData;
class BFAI2SystemData;
class BFAI2SpottingComponentData;
class ServerBFVehicleCombatEntity;
class ServerBFAIDebugProxy;
class ServerBFAIActionEntity;
class ServerBFAISpottingComponent;
class ServerBFAIProjectileComponent;
class ClientBFAISpottingComponent;
class ClientBFAIProjectileComponent;
class BFUIWidgetEntity;
class UICreditsWidget;
class UICalibrateTVScreenWidget;
class UIVideoPlayerWidget;
class UITwoLinerWidget;
class UITextListWidget;
class UIBattledashRootWidget;
class UIBattledashPlaygroupPageWidget;
class UIBattledashListBlockWidget;
class UIBattledashHomeWidget;
class UIBattledashHListWidget;
class UIBattledashFriendsPageWidget;
class UIBattledashFriendDetailsWidget;
class UIBattledashCreateChallengeWidget;
class UIBattledashCreateChallengeInvitesWidget;
class UIBattledashCreateChallengeConfirmWidget;
class UIBattledashChallengesPageWidget;
class UIBattledashChallengeDetailsWidget;
class UIBattledashAutoListWidget;
class UIGameModeEventWidget;
class UIGadgetInfoWidget;
class UIEventLogWidget;
class UIEquipmentSwitchWidget;
class UIEmergencyTickerWidget;
class UIDynamicGamertagWidget;
class UIDiscSwapBackgroundWidget;
class UIDeployZoomWidget;
class UIDeployButtonWidget;
class UIDataKeyBitmapWidget;
class UITabBarWidget;
class UICustomizeSlotsWidget;
class UICustomizeProgressionWidget;
class UICustomizeItemListWidget;
class UICustomEmblemWidget;
class UICurrentCommanderWidget;
class UICrosshairWidget;
class UICompassWidget;
class UICommoRoseWidget;
class UICommanderStatusWidget;
class UICommanderSquadStatusWidget;
class UICommanderPresenceWidget;
class UICommanderMinimapIconsWidget;
class UICommanderBarWidget;
class UICommanderAssetStatusWidget;
class UIChatWidget;
class UICCTVWidget;
class UIButtonBarWidget;
class UIBuildInfoWidget;
class UIBigMapWidget;
class UIBattlepacksMenuWidget;
class UIBattlepackOpeningWidget;
class UIBattledashWidget;
class UIBadConnectionWidget;
class UIAwardPresentationWidget;
class UIAvailableSquadsWidget;
class UIAirRadarWidget;
class UITitanScoringInfoWidget;
class UIBatteryMeterWidget;
class UIMenuHintWidget;
class UILockWarningIndicatorWidget;
class UILoadingProgressWidget;
class UIKitLoadoutSlotWidget;
class UIKitLoadoutSlotHandlerWidget;
class UIKillScreenWidget;
class UIKillerInfoWidget;
class UIKillCardBarWidget;
class UIJavelinWidget;
class UIJavelinIndicatorWidget;
class UIInteractionWidget;
class UIIngameMenuWidget;
class UIIngameBoostsWidget;
class UIIndirectFireIconsWidget;
class UIHudInventoryWidget;
class UIHudFloodFillWidget;
class UIHudBackgroundWidget;
class UIHitIndicatorWidget;
class UIHighlightWidget;
class UIGenericWidget;
class UISPLoadingWidget;
class UISPFriendsLeaderboardWidget;
class UISpChapterIntrodutionWidget;
class UISoldierStatusWidget;
class UISoldierProgressionGridWidget;
class UIServerBrowserWidget;
class UIServerBrowserFiltersWidget;
class UISensingIndicatorWidget;
class UIScoringWidget;
class UIScoreboardWidget;
class UIScoreboardRootWidget;
class UIRevivalScreenWidget;
class UIReceiveDamageIndicatorWidget;
class UIPreRoundRootWidget;
class UIPreRoundInfoWidget;
class UIPremiumIconWidget;
class UIPremiumGlowWidget;
class UIPlayerFrustumWidget;
class UIPerformanceTestWidget;
class UIPauseTransitionWidget;
class UIPassengerListWidget;
class UIPageChildWidget;
class UIOptionSelectorWidget;
class UIObliterationBombWidget;
class UIObjectiveWidgetBase;
class UIObjectiveWidget;
class UIObjectiveStatusBarWidget;
class UIObjectiveHintWidget;
class UINuiSpeechFeedbackWidget;
class UINuiSkeletonFeedbackWidget;
class UINuiImageFeedbackWidget;
class UINuiFeedbackWidget;
class UINPXTooltipWidget;
class UINotificationMessageWidget;
class UIMPLoadingWidget;
class UIMinimapVisualWidget;
class UIMinimapUAVWidget;
class UIMinimapOrdersWidget;
class UIMinimapObjectiveWidget;
class UIMinimapIconsWidget;
class UISpectatorWidgetBase;
class UIOptionsManagerWidget;
class UISpectatorCameraBarWidget;
class UISPProgressionWidget;
class UISPProgressionDataWidget;
class UIVoiceCommandsListWidget;
class UIOptionsListWidget;
class UISpectatorOptionsManagerWidget;
class UIOptionsVideoWidget;
class UIOptionsKeybindingsWidget;
class UIOptionsConsoleControlsWidget;
class UITopStoryPopupWidget;
class UIMainMenuPlateWidget;
class UIMainMenuCommerceWidget;
class UIMainMenuPersistenceWidget;
class UIMainMenuOverlayWidget;
class UIMainMenuGamerWidget;
class UIMainMenuFriendsWidget;
class UIVehicleCompassWidget;
class UITurretRotationWidget;
class UIPitchLadderWidget;
class UICommanderVehicleWidget;
class UIBankAngleWidget;
class UIAltitudeMeterWidget;
class UISpectatorPlayerBarWidget;
class UISpectatorViewInputWidget;
class UISpectatorSquadsWidget;
class UISpectatorSquadPlayerWidget;
class UISpectatorSquadBoxWidget;
class UISpectatorSoldierStatusWidget;
class UISpectatorSelectorBarWidget;
class UISpectatorScoreBarWidget;
class UISpectatorRootWidget;
class UISpectatorPlayerNameWidget;
class UISpectatorPlayerInfoWidget;
class UISpectatorPlayerCardWidget;
class UIBasicLoadingIndicatorWidget;
class UIServerInfoWidget;
class UIMyServersWidget;
class UIManageServerRootWidget;
class UIManagePlayersWidget;
class UIIngameMapRotationWidget;
class BFBlazePresenceBackend;
class UIInputDebuggingWidget;
class UIBattlescreenUIWidget;
class UIWebViewWidget;
class UIWeaponSelectorSlotDisplay;
class UIWeaponSelectorGridWidget;
class UIWeaponCompareWidget;
class UIWeaponAccessoryInfoWidget;
class UIVoipStatusWidget;
class UIVehicleLoadoutSlotWidget;
class UIUnlockRequirementWidget;
class UITooltipWidget;
class UITextEntryListWidget;
class UITeamSetupWidget;
class UICustomizeVehiclesTabBarWidget;
class UISubtitlesWidget;
class UIStepperWidget;
class UISquadListWidget;
class UISquadDeployMembersWidget;
class UISquadDeployListWidget;
class UISquadBarWidget;
class PresenceGetAuthCodeRequestParameters;
class PresenceGetAuthTokenRequestParameters;
class PresenceDownloadFriendsStatsRequestParameters;
class PresenceSetUserInfoAttributeRequestParameters;
class PresenceDownloadPromoItemRequestParameters;
class PresenceUploadProgressionRequestParameters;
class PresenceResetStatisticsRequestParameters;
class PresenceReportPlayerEmblemRequestParameters;
class PresenceReportServerBannerRequestParameters;
class PresenceRspGetPingSitesRequestParameters;
class PresenceRspRestartServerRequestParameters;
class PresenceRspGetConfigRequestParameters;
class PresenceRspUpdateVipUserRequestParameters;
class PresenceRspUpdateBannedUserRequestParameters;
class PresenceRspUpdateAdminUserRequestParameters;
class PresenceRspUpdateMapRotationRequestParameters;
class PresenceRspUpdatePresetRequestParameters;
class PresenceRspUpdateServerSettingsRequestParameters;
class PresenceRspGetServerDetailsRequestParameters;
class PresenceRspGetServersRequestParameters;
class PresenceGetDetailedServerInfoRequestParameters;
class PresenceGetGamesByGameIDRequestParameters;
class PresenceGetGamesWithFriendsRequestParameters;
class PresenceGetServerBrowserSnapshotRequestParameters;
class PresenceVerifyGrantEntitlementRequestParameters;
class PresenceGrantEntitlementRequestParameters;
class PresenceUploadUserSettingsRequestParameters;
class PresenceDownloadUserSettingsRequestParameters;
class PresenceBattlelogHttpPostRequestParameters;
class PresenceBattlelogHttpGetRequestParameters;
class OriginPresenceBackend;
class ServerVehicleCriticalHitTriggerEntity;
class ServerStatEventTriggerEntity;
class ServerConsumableTriggerEntity;
class ServerCollisionTriggerEntity;
class UnlockEntity;
class ServerTopPlayersEntity;
class ServerTitanGameStatsEntity;
class ServerTicketCounterEntity;
class ServerSpottingEntity;
class ServerSharedDataEntity;
class ServerRoundOverEntity;
class ServerPreRoundEntity;
class ServerPlayerUtilEntity;
class ServerPersistentValueEntity;
class ServerLifeCounterEntity;
class ServerLevolutionMessageEntity;
class ServerKillCounterEntity;
class ServerFriendlyFireEntity;
class ServerShieldControllerComponent;
class ServerShieldComponent;
class ServerRadarSweepComponent;
class ServerMissileSurfaceAdaptionComponent;
class ServerLockingTargetComponent;
class ServerLocatorComponent;
class ServerFlagComponent;
class ServerEntityInteractionComponent;
class ServerDropWeaponComponent;
class ServerDOTReceiverComponent;
class ServerDOTGiverComponent;
class ServerClimbLadderComponent;
class ServerBlockSpottingComponent;
class ServerAILocoComponent;
class ServerAdvertisementComponent;
class ServerFlagCounterEntity;
class ServerEliminationPreRoundEntity;
class ServerControlInputEntity;
class ServerCommanderMapInfoEntity;
class ServerCommanderAsset;
class ServerCommanderEntity;
class ServerAutoTeamEntity;
class ServerAutoSquadEntity;
class BFServerTeamEntity;
class BFServerObjectiveEntity;
class ServerLevelProgressEntity;
class ServerVaultComponent;
class ServerTimedFuseComponent;
class ServerSupportedShootingComponent;
class ServerSupplySphereComponent;
class ServerSpecialMovesComponent;
class ServerSoldierParachuteComponent;
class ServerSimpleAnimationControlComponent;
class ServerShieldPhysicsComponent;
class BFClientInputRestrictionEntity;
class ClientVideoRecorderEntity;
class ClientDVRMomentsEntity;
class ClientVaultComponent;
class ClientTimedFuseComponent;
class ClientTargetCameraComponent;
class ClientSupportedShootingComponent;
class ClientSpecialMovesComponent;
class ClientSoldierSoundComponent;
class ClientSoldierParachuteComponent;
class ClientSoldierEmoteComponent;
class ClientSoldierDecalComponent;
class ClientSimpleAnimationControlComponent;
class ClientShieldPhysicsComponent;
class ClientShieldControllerComponent;
class ClientShieldComponent;
class ClientRadarSweepComponent;
class ClientPlayerLogoComponent;
class ClientLockingTargetComponent;
class ClientUIMinimapVolumeEntity;
class ClientUIMessageTriggerEntity;
class ClientUICustomizeStateEntity;
class ClientUICustomize3DModelEntity;
class ClientNUICommanderEntity;
class ClientLoadingMusicEntity;
class ClientInputMessageTriggerEntity;
class ClientFirstPartyUIEntity;
class ClientDirectionHintEntity;
class ClientPLMStoreGameStateEntity;
class ClientPLMRestoreGameStateEntity;
class ClientSkeletonInputEntity;
class ClientXBoneSystemCommandStatusEntity;
class ClientNuiSpeechTriggerEntity;
class ClientNuiSpeechSetupEntity;
class ClientGrammarStateEntity;
class ClientYawPitchRelativeToTransformEntity;
class ClientUnlockEntity;
class ClientUIEndOfRoundEntity;
class ClientTicketCounterEntity;
class ClientSpectatorEntity;
class ClientSpectatorAreaEntity;
class ClientSharedDataEntity;
class ClientRoundOverEntity;
class ClientPreRoundEntity;
class ClientLifeCounterEntity;
class ClientKillCounterEntity;
class ClientFlagCounterEntity;
class ClientEsportsSpectatorEntity;
class ClientEliminationPreRoundEntity;
class ClientDeathExperienceEntity;
class ClientCommanderAsset;
class ClientCommanderEntity;
class ClientCharacterUtilEntity;
class ClientCameraDistanceEntity;
class ClientAutoTeamEntity;
class BFClientTimeNudgeBiasEntity;
class BFClientTeamEntity;
class BFClientObjectiveEntity;
class BFServerSpectatorSubView;
class ServerMobileSpawnComponent;
class ServerAimingComponent;
class ServerSpawnSubView;
class ServerCapturePointEntity;
class ServerSoldierSuppressionComponent;
class ServerSoldierSteeringComponent;
class ServerSoldierLeaningComponent;
class ServerMeleeTriggerEntity;
class ServerMeleeEntity;
class ServerCoverPrepareFireEntity;
class ServerAIStateEntity;
class ServerAIProximityReactionsComponent;
class BFServerSoldierPhysicsComponent;
class BFServerSoldierHealthComponent;
class BFBoolEventEntity;
class BFServerFakeCollisionInfo;
class BFClientFakeCollisionInfo;
class ServerCommanderAction;
class ServerSquadWipeProtectionAction;
class ServerReinforceSquadAction;
class ServerHighValueTargetAction;
class ServerProxyAttackAction;
class ServerGunshipDeployAction;
class ServerSatelliteEMPAction;
class ServerRadarScanAction;
class ServerInfantryScanAction;
class ServerEarlyWarningAction;
class ServerVehicleScanAction;
class ServerLaunchTomahawkAction;
class ServerPromoteSquadAction;
class ServerDefenseDropAction;
class ServerVehicleSpawnAction;
class ServerSupplyDropAction;
class ServerOrderAction;
class ServerSectorJamAction;
class ServerSectorScanAction;
class ServerParaDropAction;
class VeniceFPSCamera;
class UavCamera;
class ClientLockingWeapon;
class ClientLaserPainterWeapon;
class ClientLaserDesignatorWeapon;
class ClientIndirectFireWeapon;
class ClientFlashlightWeapon;
class ClientDetonatedWeapon;
class ClientDefibrillatorWeapon;
class ClientBomberWeapon;
class ClientArtilleryStrikeWeapon;
class ThisTargetCameraCallback2;
class ClientAirburstWeapon;
class ClientSpectatorViewComponent;
class SpectatorClientComponentTargetCameraCallback;
class SpectatorClientPhysicsEntityCameraCallback;
class SpectatorClientCharacterCameraTargetCameraCallback;
class VeniceClientSoldierCameraCallback;
class ClientTargetCameraSpectatorViewComponent;
class ClientFallbackSpectatorViewComponent;
class ClientFreeCameraSpectatorViewComponent;
class BFClientSpectatorSubView;
class ClientMobileSpawnComponent;
class UIMainMenuTopStoryWidget;
class BFUIElementButtonBarButtonEntity;
class BFUIElementButtonBarPressAndReleaseButtonEntity;
class BFUIElementColorizedFillEntity;
class BFUIElementColorizedBitmapEntity;
class BFUIElementColorizedTextFieldEntity;
class UIElementStatbarBaseEntity;
class UIElementStatbarEntity;
class BFUIElement3SliceStatbarEntity;
class ClientSpawnSubView;
class ClientCapturePointEntity;
class VeniceClientSoldierCameraComponent;
class SpectatorVeniceClientSoldierCameraCallback;
class ClientSoldierSuppressionComponent;
class ClientSoldierLeaningComponent;
class ClientSoldierFootplantEffectComponent;
class ClientMeleeEntity;
class ClientLookAtEntity;
class ClientAIStateEntity;
class ClientAIProximityReactionsComponent;
class ClientAimingConstraintsEntity;
class BFClientSoldierPhysicsComponent;
class BFClientSoldierHealthComponent;
class BFClientPlayerFilterEntity;
class BFClientLocalPlayerEventGate;
class ClientAwardListenerEntity;
class WebPresenceBackend;
class ClientMinimap2DEntity;
class ClientWaypointTriggerEntity;
class ClientSpottingTargetComponent;
class ClientSpottingComponent;
class VeniceClientMissileEntity;
class VeniceClientExplosionEntity;
class VeniceClientBulletEntity;
class ClientPropertyOptimizationCheckEntity;
class ClientPropertyProfileEntity;
class ClientTrackPlayerEntity;
class ClientSpottingDistanceScaleEntity;
class ClientRetargetTransformEntity;
class ClientPlayerLogoEntity;
class ClientPausedEntity;
class ClientInterpolateTransformEntity;
class ClientInteractionEntity;
class ClientExplosivesTrackingComponent;
class ClientExplosivesTrackerEntity;
class ClientEnteredIngameEntity;
class BlockSpottingEntity;
class ClientAwarenessTargetEntity;
class ClientUITooltipEntity;
class ClientUINPXTooltipEntity;
class ClientPlayerInteractionView;
class ClientVehicleDeployWeapon;
class ClientThrowAtTargetWeapon;
class ClientRemoteControlledWeapon;
class ClientPowerToolWeapon;
class ClientMultipleTargetPainterWeapon;
class ClientMortarStrikeWeapon;
class ClientMeleeWeapon;
class ClientMedkitWeapon;
class ClientLocatorComponent;
class ClientFlagComponent;
class ClientEMPTargetComponent;
class ClientDropWeaponComponent;
class ClientClimbLadderComponent;
class ClientBlockSpottingComponent;
class ClientAwarenessComponent;
class ClientAILocoComponent;
class ControllableChaseCamera;
class CollidableFreeCamera;
class ClientVoiceOverGameStateWriterEntity;
class ClientAdvertisementComponent;
class ServerSpottingTargetComponent;
class ServerSpottingComponent;
class VeniceServerMissileEntity;
class VeniceServerExplosionEntity;
class VeniceServerBulletEntity;
class ServerTrackPlayerEntity;
class ServerTeleportAreaEntity;
class ServerRetargetTransformEntity;
class ServerPlayerAliveFilterEntity;
class ServerInterpolateTransformEntity;
class ServerInteractionEntity;
class ServerFriendZoneEntity;
class ServerBlockSpottingEntity;
class ServerArtilleryStrikeEntity;
class BFServerSetPlayerView;
class BFServerPlayerFilterEntity;
class ServerMultipleTargetPainterWeapon;
class ServerMortarStrikeWeapon;
class ServerMeleeWeapon;
class ServerMedkitWeapon;
class ServerMedicBagHealingSphereWeapon;
class ServerLockingWeapon;
class ServerLaserPainterWeapon;
class ServerLaserDesignatorWeapon;
class ServerIndirectFireWeapon;
class ServerFlashlightWeapon;
class ServerDetonatedWeapon;
class ServerDefibrillatorWeapon;
class ServerBomberWeapon;
class ServerArtilleryStrikeWeapon;
class ServerAirburstWeapon;
class ServerVehicleProjectileEntity;
class ServerSupplySphereEntity;
class ServerMedicBagHealingSphereEntity;
class ServerFlareEntity;
class ServerMetricsSettings;
class MetricEvent;
class ReceivedAwardSurveyEvent;
class StatSurveyEvent;
class SpawnSurveyEvent;
class EnterVehicleSurveyEvent;
class DebugSurveyEvent;
class SurveyEvent;
class MetricState;
class PerformanceProfileState;
class FramerateHistogramPerformanceEvent;
class NetworkPerformanceEvent;
class PerformanceEvent;
class ServerPerformanceEvent;
class MetricAggregate;
class VehicleState;
class KitState;
class KitStateEvent;
class PlayerState;
class SpawnState;
class DamageToVehicleEvent;
class RoundOverEvent;
class DeathEvent;
class KillEvent;
class SpawnEvent;
class TickEvent;
class RoundEvent;
class ScoreAggregate;
class ClientJuiceState;
class MetricReport;
class SurveySuppressedEvent;
class TabletCommanderEntityData;
class LevolutionMessageEntityData;
class VehicleProjectileEntityData;
class RemoteControlledWeaponData;
class TargetCameraComponentData;
class TimedFuseComponentData;
class BomberWeaponData;
class AirburstWeaponData;
class IndirectFireWeaponData;
class VehicleDeployWeaponData;
class MultipleTargetPainterWeaponData;
class BFSetPlayerViewData;
class BFLocalPlayerEventGateData;
class BFPlayerFilterEntityData;
class PropertyInterpolatorEntityData;
class FloatInterpolatorEntityData;
class SpottingDistanceScaleEntityData;
class BlockSpottingEntityData;
class VoiceOverGameStateWriterEntityData;
class StackedSpawnData;
class DeathExperienceEntityData;
class UnlockEntityData;
class PersistentValueEntityData;
class TeleportAreaEntityData;
class FloatRangeConverterEntityData;
class CameraDistanceEntityData;
class BFInputRestrictionEntityData;
class BFObjectiveEntityData;
class EventLogMessageEntityInfo;
class CommanderActionMessageEntityInfo;
class CommanderObjectiveEventMessageEntityInfo;
class NotificationMessageEntityInfo;
class OutOfBoundsMessageEntityInfo;
class FailStateMessageEntityInfo;
class SubtitleMessageEntityInfo;
class LogLinesMessageEntityInfo;
class TooltipMessageEntityInfo;
class TextMessageEntityInfo;
class ArtilleryStrikeEntityData;
class SpottingEntityData;
class TelemetryTriggerEntityData;
class CoopLobbyEntityData;
class TopPlayersEntityData;
class AimingConstraintEntityData;
class AimingConstraintEntityCommonData;
class MeleeTriggerEntityData;
class MeleeEntityData;
class MeleeEntityCommonData;
class TrackPlayerEntityData;
class VeniceExplosionEntityData;
class TargetEntityData;
class DebugTestEntityData;
class FriendZoneDebugRenderEntityData;
class FriendZoneEntityData;
class KillCounterEntityData;
class LifeCounterEntityData;
class SharedDataEntityData;
class RetargetTransformEntityData;
class InterpolateTransformEntityData;
class MessageReceivedEvent;
class GameBrowserUpdateEvent;
class BFGameParameters;
class PresenceListEntitlementsRequestParameters;
class TelemetryTriggerEntity;
class PropertyEventTriggerEntity;
class LevelDescriptionOverrideEntity;
class FloatRangeConverterEntity;
class EventQueueEntity;
class ClientBlockSpottingEntity;
class ServerUnlockEntity;
class TeamIdToIntEntity;
class FloatInterpolatorEntity;
class FactionEntity;
class PropertyOptimizationCheckEntityData;
class PropertyProfileEntityData;
class PropertyEventTriggerEntityData;
class CollisionTriggerEntityData;
class YawPitchRelativeToTransformEntityData;
class BlockSpottingComponentData;
class FlagComponentData;
class DOTReceiverComponentData;
class DOTGiverComponentData;
class MissileSurfaceAdaptionComponentData;
class ShieldPhysicsComponentData;
class ShieldComponentData;
class ShieldControllerComponentData;
class EMPTargetComponentData;
class SupplySphereComponentData;
class AimingComponentData;
class MobileSpawnComponentData;
class SoldierSoundComponentData;
class SoldierFootplantEffectComponentData;
class AIProximityReactionsComponentData;
class WaypointComponentData;
class EntityInteractionComponentData;
class InteractionData;
class InteractionEntityInteractionData;
class ExplosionPackInteractionData;
class DeployedVehicleInteractionData;
class WeaponPickupInteractionData;
class SoldierInteractionData;
class SoldierManDownInteractionData;
class AmmoPickupInteractionData;
class SoldierWeaponInteractionData;
class EnterVehicleInteractionData;
class SoldierDecalComponentData;
class DropWeaponComponentData;
class ClimbLadderComponentData;
class LocatorComponentData;
class RadarSweepComponentData;
class SimpleAnimationControlComponentData;
class SoldierParachuteComponentData;
class SupportedShootingComponentData;
class SupportedShootingCommonData;
class SpecialMovesComponentData;
class LockingTargetComponentData;
class JammingComponentData;
class VaultComponentData;
class AwarenessTargetEntityData;
class AwarenessComponentData;
class VeniceFPSCameraData;
class UavCameraData;
class ClientMetricsSettings;
class NUICommanderEntityData;
class FirstPartyUIEntityData;
class SkeletonInputEntityData;
class ClientCharacterUtilData;
class VideoRecorderEntityData;
class DVRMomentsEntityData;
class DVRMomentEvent;
class PadRumbleNodeData;
class CameraShakeNodeData;
class ServerPlayerInteractionView;
class ServerVehicleDeployWeapon;
class ServerThrowAtTargetWeapon;
class ServerTargetEntity;
class ServerSupplySphereWeaponEffects;
class ServerSupplySphereWeapon;
class ServerPowerToolWeapon;
class ServerRemoteControlledWeapon;
class ServerRepairToolWeapon;

////////////////////////////////////////
// RuntimeId: 09721
// TypeInfo:  0x00000001427F9860
struct WaterEntityClipInfo
{
	bool m_Enable; //0x0000
	bool m_ClipFaceNorth; //0x0001
	bool m_ClipFaceSouth; //0x0002
	bool m_ClipFaceEast; //0x0003
	bool m_ClipFaceWest; //0x0004
};//Size=0x0005

////////////////////////////////////////
// RuntimeId: 09717
// TypeInfo:  0x00000001427F98A0
struct WaterAmbientFoamEffectSpawner
{
	EffectBlueprint* m_Effect; //0x0000
	float m_Threshold; //0x0008
	float m_Randomness; //0x000C
	float m_CoolDownTime; //0x0010
	float m_NearDistance; //0x0014
	float m_FarDistance; //0x0018
	float m_VerticalVelocityScale; //0x001C
	float m_HorizontalVelocityScale; //0x0020
	char _0x0024[4];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03554
// TypeInfo:  0x00000001420DC810
struct Vec4
{
	float m_x; //0x0000
	float m_y; //0x0004
	float m_z; //0x0008
	float m_w; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09706
// TypeInfo:  0x00000001427F8F48
struct VoipInboundTalkersMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09696
// TypeInfo:  0x00000001427F8BD8
struct WeaponZeroingEntry
{
	float m_Distance; //0x0000
	float m_Angle; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09692
// TypeInfo:  0x00000001427F8BF8
struct GunSwayModifierUnlock
{
	Guid m_UnlockAssetGuid; //0x0000
	char _0x0000[16];
	GunSwayModifierData* m_Modifier; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09668
// TypeInfo:  0x00000001427F8B98
struct GunSwayDispersionModData
{
	float m_MinAngleModifier; //0x0000
	float m_MaxAngleModifier; //0x0004
	float m_IncreasePerShotModifier; //0x0008
	float m_DecreasePerSecondModifier; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09666
// TypeInfo:  0x00000001427F8BB8
struct GunSwayDispersionData
{
	float m_MinAngle; //0x0000
	float m_MaxAngle; //0x0004
	float m_IncreasePerShot; //0x0008
	float m_DecreasePerSecond; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09674
// TypeInfo:  0x00000001427F8B58
struct GunSwayRecoilData
{
	float m_RecoilAmplitudeMax; //0x0000
	float m_RecoilAmplitudeIncPerShot; //0x0004
	float m_HorizontalRecoilAmplitudeIncPerShotMin; //0x0008
	float m_HorizontalRecoilAmplitudeIncPerShotMax; //0x000C
	float m_HorizontalRecoilAmplitudeMax; //0x0010
	float m_RecoilAmplitudeDecreaseFactor; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09670
// TypeInfo:  0x00000001427F8B78
struct GunSwayLagData
{
	float m_MoveStrafeModifier; //0x0000
	float m_MoveForwardModifier; //0x0004
	float m_RotateYawModifier; //0x0008
	float m_RotatePitchModifier; //0x000C
	float m_ReleaseModifier; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 09680
// TypeInfo:  0x00000001427F8B18
struct GunSwayBaseMoveData
{
	GunSwayDispersionData m_BaseValue; //0x0000
	GunSwayDispersionData m_Moving; //0x0010
	GunSwayRecoilData m_Recoil; //0x0020
	GunSwayLagData m_GunSwayLag; //0x0038
};//Size=0x004C

////////////////////////////////////////
// RuntimeId: 09678
// TypeInfo:  0x00000001427F8C18
struct GunSwayBaseData
{
	GunSwayDispersionData m_BaseValue; //0x0000
	GunSwayRecoilData m_Recoil; //0x0010
	GunSwayLagData m_GunSwayLag; //0x0028
};//Size=0x003C

////////////////////////////////////////
// RuntimeId: 09676
// TypeInfo:  0x00000001427F8B38
struct GunSwayStanceTransition
{
	GunSwayDispersionData m_MaxPenaltyValue; //0x0000
	float m_CoolDown; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 09682
// TypeInfo:  0x00000001427F8AF8
struct GunSwayBaseMoveJumpData
{
	GunSwayDispersionData m_BaseValue; //0x0000
	GunSwayDispersionData m_Moving; //0x0010
	GunSwayDispersionData m_Jumping; //0x0020
	GunSwayDispersionData m_Sprinting; //0x0030
	GunSwayDispersionData m_VaultingSmallObject; //0x0040
	GunSwayDispersionData m_VaultingMediumObject; //0x0050
	GunSwayRecoilData m_Recoil; //0x0060
	GunSwayLagData m_GunSwayLag; //0x0078
};//Size=0x008C

////////////////////////////////////////
// RuntimeId: 09684
// TypeInfo:  0x00000001427F8AD8
struct GunSwayStandData
{
	GunSwayBaseMoveJumpData m_NoZoom; //0x0000
	GunSwayBaseMoveJumpData m_Zoom; //0x008C
};//Size=0x0118

////////////////////////////////////////
// RuntimeId: 09688
// TypeInfo:  0x00000001427F8A98
struct GunSwayStanceZoomModifierData
{
	GunSwayDispersionModData m_DispersionMod; //0x0000
	GunSwayDispersionModData m_MovingDispersionMod; //0x0010
	GunSwayDispersionModData m_SprintingDispersionMod; //0x0020
	float m_RecoilMagnitudeMod; //0x0030
	float m_RecoilAngleMod; //0x0034
	float m_FirstShotRecoilMod; //0x0038
	float m_LagYawMod; //0x003C
	float m_LagPitchMod; //0x0040
};//Size=0x0044

////////////////////////////////////////
// RuntimeId: 09686
// TypeInfo:  0x00000001427F8AB8
struct GunSwayCrouchProneData
{
	GunSwayBaseMoveData m_NoZoom; //0x0000
	GunSwayBaseMoveData m_Zoom; //0x004C
};//Size=0x0098

////////////////////////////////////////
// RuntimeId: 03702
// TypeInfo:  0x000000014276DC40
struct AntRef
{
	Guid m_AssetGuid; //0x0000
	char _0x0000[16];
	__int32 m_ProjectId; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 09658
// TypeInfo:  0x00000001427F56B8
struct WeaponMesh1p
{
	SkinnedMeshAsset* m_Mesh; //0x0000
	SkinnedMeshAsset* m_MeshZoom; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09642
// TypeInfo:  0x00000001427F56D8
struct WeaponModifierData
{
	Guid m_UnlockAssetGuid; //0x0000
	char _0x0000[16];
	Array<WeaponModifierBase*> m_Modifiers; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09640
// TypeInfo:  0x00000001427F56F8
struct WeaponModifier
{
	char _0x0000[144];
	__int32 m_Dummy2ToMakeFrostEDcompile; //0x0090
	char _0x0094[140];
};//Size=0x0120

////////////////////////////////////////
// RuntimeId: 09612
// TypeInfo:  0x00000001427F5198
struct SupplyData
{
	HealingSupplyUnitSphereData* m_Healing; //0x0000
	AmmoSupplyUnitSphereData* m_Ammo; //0x0008
	float m_ExclusionTimeout; //0x0010
	bool m_SupplySoldiers; //0x0014
	bool m_SupplyVehicles; //0x0015
	bool m_TeamSpecific; //0x0016
	bool m_ExcludeSelf; //0x0017
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09596
// TypeInfo:  0x00000001427F5718
struct PlatformAimAssistData
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	SoldierAimAssistData* m_AimAssistData; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09586
// TypeInfo:  0x00000001427F51B8
struct NetworkDefibrillatorReviveMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 09583
// TypeInfo:  0x00000001427F51D8
struct DefibrillatorUpgradeWeaponData
{
	ValueUnlockAsset* m_UpgradeUnlock; //0x0000
	float m_AttackTime; //0x0008
	float m_FullHealthTime; //0x000C
	float m_InitialStartHealth; //0x0010
	float m_DefibActionCooldownTime; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09549
// TypeInfo:  0x00000001427F51F8
struct SoldierDetonationData
{
	float m_Angle; //0x0000
	float m_Radius; //0x0004
	float m_SoldierDetonationActivationDelay; //0x0008
	float m_MinSpeedForActivation; //0x000C
	bool m_HasSoldierDetonation; //0x0010
	bool m_UseAngle; //0x0011
	char _0x0012[2];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 09547
// TypeInfo:  0x00000001427F5218
struct NetworkSetCustomizationWeaponSlotMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 09546
// TypeInfo:  0x00000001427F5238
struct NetworkSetActiveWeaponSlotMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 09545
// TypeInfo:  0x00000001427F5258
struct BulletToCharacterComponentsHitMessage
{
	char _0x0000[128];
};//Size=0x0080

////////////////////////////////////////
// RuntimeId: 03552
// TypeInfo:  0x00000001420DC7F0
struct Vec3
{
	float m_x; //0x0000
	float m_y; //0x0004
	float m_z; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09540
// TypeInfo:  0x00000001427F5278
struct CustomizationAccessoryPivots
{
	Vec3 m_BasePivotPos; //0x0000
	Vec3 m_OpticPivotPos; //0x0010
	Vec3 m_BarrelPivotPos; //0x0020
	Vec3 m_AccessoryPivotPos; //0x0030
	Vec3 m_UnderBarrelPivotPos; //0x0040
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 09536
// TypeInfo:  0x00000001427F5298
struct WeaponAnimationSettingsData
{
	float m_KickbackFactor; //0x0000
	float m_KickbackSpeedFactor; //0x0004
	float m_WeaponOffsetX; //0x0008
	float m_WeaponOffsetY; //0x000C
	float m_WeaponOffsetZ; //0x0010
	float m_ZoomOutSpeed; //0x0014
	float m_ZoomInSpeed; //0x0018
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 09530
// TypeInfo:  0x00000001427F5758
struct WeaponOverrideValue
{
	WeaponOverrideValueType m_ValueType; //0x0000
	float m_Value; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09520
// TypeInfo:  0x00000001427F52B8
struct PickupSettingsData
{
	Vec3 m_MeshRenderOffset; //0x0000
	Vec3 m_MeshRenderRotation; //0x0010
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03560
// TypeInfo:  0x00000001420DC850
struct LinearTransform
{
	Vec3 m_right; //0x0000
	Vec3 m_up; //0x0010
	Vec3 m_forward; //0x0020
	Vec3 m_trans; //0x0030
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 09512
// TypeInfo:  0x00000001427F5798
struct RigidMeshSocketTransform
{
	LinearTransform m_Transform; //0x0000
	WeaponRegularSocketObjectData* m_SocketObject; //0x0040
	char _0x0048[8];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 09510
// TypeInfo:  0x00000001427F57B8
struct AnimationConfigurationShootModuleData
{
	float m_ZoomedKickbackFactor; //0x0000
	float m_ZoomedKickbackSpeedFactor; //0x0004
	float m_KickbackFactor; //0x0008
	float m_KickbackSpeedFactor; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09500
// TypeInfo:  0x00000001427F52D8
struct WeaponLagEffectForceData
{
	Vec3 m_OffsetForce; //0x0000
	Vec3 m_RotationForce; //0x0010
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09496
// TypeInfo:  0x00000001427F5318
struct WeaponLagEffectSpringData
{
	float m_Constant; //0x0000
	float m_Damping; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09498
// TypeInfo:  0x00000001427F52F8
struct WeaponLagEffectSpringVector
{
	WeaponLagEffectSpringData m_SpringX; //0x0000
	WeaponLagEffectSpringData m_SpringY; //0x0008
	WeaponLagEffectSpringData m_SpringZ; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09490
// TypeInfo:  0x00000001427F57D8
struct ZoomLevelSpecificTransitionTime
{
	__int32 m_FromZoomLevel; //0x0000
	__int32 m_ToZoomLevel; //0x0004
	float m_ZoomTransitionTime; //0x0008
	float m_FovTransitionTime; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09488
// TypeInfo:  0x00000001427F5338
struct AimingPoseData
{
	float m_MinimumPitch; //0x0000
	float m_MaximumPitch; //0x0004
	float m_TargetingFov; //0x0008
	float m_AimSteadiness; //0x000C
	float m_SpeedMultiplier; //0x0010
	float m_RecoilMultiplier; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09482
// TypeInfo:  0x00000001427F5358
struct UnlockWeaponAndSlot
{
	SoldierWeaponUnlockAsset* m_Weapon; //0x0000
	WeaponSlot m_Slot; //0x0008
	char _0x000C[4];
	Array<UnlockAssetBase*> m_CustomizationUnlockAssets; //0x0010
	Array<UnlockAssetBase*> m_UnlockAssets; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09478
// TypeInfo:  0x00000001427F57F8
struct UnlockToBlueprintBundle
{
	Guid m_UnlockAssetGuid; //0x0000
	char _0x0000[16];
	char* m_BundleName; //0x0010
	bool m_IsFirstPersonOnly; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09476
// TypeInfo:  0x00000001427F5378
struct StoredWeaponData
{
	__int32 m_WeaponClass; //0x0000
	__int32 m_MagCount; //0x0004
	__int32 m_MagCapacity; //0x0008
	bool m_SwitchToPrimaryWhenOutOfAmmo; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09460
// TypeInfo:  0x00000001427F5818
struct DirectWeaponSwitchingMapData
{
	__int32 m_Action; //0x0000
	float m_MaxHoldTime; //0x0004
	WeaponSwitchingEnum m_ToWeapon; //0x0008
	float m_SwitchBackToPrevMaxTimePressed; //0x000C
	float m_PreventMeleeRepeatTime; //0x0010
	bool m_FireAndSwitchBackToPrev; //0x0014
	bool m_UseQuickSwitch; //0x0015
	char _0x0016[2];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09458
// TypeInfo:  0x00000001427F5838
struct WeaponSwitchingMapData
{
	WeaponSwitchingEnum m_FromWeapon; //0x0000
	__int32 m_Action; //0x0004
	float m_MaxHoldTime; //0x0008
	char _0x000C[4];
	Array<WeaponSwitchingEnum> m_ToWeapon; //0x0010
	bool m_FireAndSwitchBackToPrev; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09448
// TypeInfo:  0x00000001427F5858
struct DamageEntryData
{
	float m_Damage; //0x0000
	float m_Timeout; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09440
// TypeInfo:  0x00000001427F53D8
struct SoldierToComponentsOnClearSpottingMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09439
// TypeInfo:  0x00000001427F53F8
struct ClientSoldierToComponentsOnHandleDamageMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 09438
// TypeInfo:  0x00000001427F5418
struct ClientSoldierToComponentsOnImpulseMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09437
// TypeInfo:  0x00000001427F5438
struct SoldierToComponentsOnActionStateChangedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09436
// TypeInfo:  0x00000001427F5458
struct SoldierToComponentsOnIncapableMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 09435
// TypeInfo:  0x00000001427F5478
struct SoldierToComponentsOnCustomizeSoldierMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09434
// TypeInfo:  0x00000001427F5498
struct SoldierToComponentsInitializedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09425
// TypeInfo:  0x00000001427F5878
struct ValueAtX
{
	float m_X; //0x0000
	float m_Value; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09417
// TypeInfo:  0x00000001427F5898
struct HidableSoldierMeshWeaponPart
{
	SkinnedMeshAsset* m_WeaponMesh; //0x0000
	ObjectBlueprint* m_WeaponMeshBlueprint; //0x0008
	char* m_BoneName; //0x0010
	bool m_HideAlways; //0x0018
	bool m_HideInVehicleEntries; //0x0019
	char _0x001A[6];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09413
// TypeInfo:  0x00000001427F58B8
struct SoldierHeadCollisionPoseData
{
	Vec3 m_IdleOffset; //0x0000
	Vec3 m_MovingForwardOffset; //0x0010
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09409
// TypeInfo:  0x00000001427F58D8
struct AutoAimData
{
	Vec3 m_AutoAimOuterBoxOffset; //0x0000
	Vec3 m_AutoAimOuterBoxExtends; //0x0010
	Vec3 m_AutoAimInnerBoxOffset; //0x0020
	Vec3 m_AutoAimInnerBoxExtends; //0x0030
	CharacterPoseType m_PoseType; //0x0040
	char _0x0044[12];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 09407
// TypeInfo:  0x00000001427F58F8
struct FootStepTrigger
{
	float m_Time; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 09399
// TypeInfo:  0x00000001427F54D8
struct NetworkPickupWeaponFromKitMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 09396
// TypeInfo:  0x00000001427F5918
struct DynamicWeaponPickupSlotData
{
	unsigned __int32 m_WeaponSlot; //0x0000
	__int32 m_AltWeaponSlot; //0x0004
	__int32 m_LinkedToWeaponSlot; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 09388
// TypeInfo:  0x00000001427F5938
struct WeaponUnlockPickupData
{
	UnlockWeaponAndSlot m_UnlockWeaponAndSlot; //0x0000
	__int32 m_AltWeaponSlot; //0x0020
	__int32 m_LinkedToWeaponSlot; //0x0024
	unsigned __int32 m_MinAmmo; //0x0028
	unsigned __int32 m_MaxAmmo; //0x002C
	bool m_UnlimitedAmmoPickup; //0x0030
	char _0x0031[7];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09370
// TypeInfo:  0x00000001427F54F8
struct HitReactionComponentBinding
{
	AntRef m_Hit; //0x0000
	AntRef m_HitByAIPlayer; //0x0014
	AntRef m_AllowKillFromAnimation; //0x0028
	AntRef m_Direction; //0x003C
	AntRef m_FiringDistance; //0x0050
	AntRef m_BoneType; //0x0064
	AntRef m_ImpactType; //0x0078
	AntRef m_Immortal; //0x008C
	AntRef m_RandomAnimationIndex; //0x00A0
};//Size=0x00B4

////////////////////////////////////////
// RuntimeId: 09364
// TypeInfo:  0x00000001427F5538
struct BlockAimAssistData
{
	float m_BlockingRadius; //0x0000
	float m_LifeTime; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09358
// TypeInfo:  0x00000001427F5558
struct NetworkPlayerSelectedWeaponMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 09355
// TypeInfo:  0x00000001427F5578
struct CoverPeekBinding
{
	AntRef m_CoverHeight1p; //0x0000
	AntRef m_CanCoverPeek; //0x0014
	AntRef m_CanPeekOver; //0x0028
	AntRef m_CanPeekLeft; //0x003C
	AntRef m_CanPeekRight; //0x0050
};//Size=0x0064

////////////////////////////////////////
// RuntimeId: 09331
// TypeInfo:  0x00000001427F5598
struct MovementComponentBinding
{
	AntRef m_AnimationControlled; //0x0000
	AntRef m_FeedbackCollisions; //0x0014
	AntRef m_DisableAnimationControlledCamera; //0x0028
	AntRef m_DisableAnimationControlExitVelocity; //0x003C
	AntRef m_ForceVelocityMode; //0x0050
};//Size=0x0064

////////////////////////////////////////
// RuntimeId: 09327
// TypeInfo:  0x00000001427F55B8
struct CameraCommonBinding
{
	AntRef m_FirstPersonCameraHeight; //0x0000
	AntRef m_AnimatedCameraBlendTime; //0x0014
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09325
// TypeInfo:  0x00000001427F55D8
struct Camera1pBinding
{
	AntRef m_Render1pInBackground; //0x0000
	AntRef m_ForceRender1pInForeground; //0x0014
	AntRef m_ForceAnimatedCamera; //0x0028
};//Size=0x003C

////////////////////////////////////////
// RuntimeId: 09317
// TypeInfo:  0x00000001427F55F8
struct AimingWorldSpaceLockEfficiencyData
{
	float m_EfficiencyYaw; //0x0000
	float m_EfficiencyPitch; //0x0004
	float m_EfficiencyYawZoom; //0x0008
	float m_EfficiencyPitchZoom; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09307
// TypeInfo:  0x00000001427F5958
struct SoldierHealthModuleBinding
{
	AntRef m_HeadShot; //0x0000
	AntRef m_LeftArmHit; //0x0014
	AntRef m_RightArmHit; //0x0028
	AntRef m_LeftLegHit; //0x003C
	AntRef m_RightLegHit; //0x0050
	AntRef m_OnGround; //0x0064
	AntRef m_DeathAnimationTriggered; //0x0078
	AntRef m_RandomAnimationIndex; //0x008C
	AntRef m_Sprinting; //0x00A0
	AntRef m_HitLeft; //0x00B4
	AntRef m_HitRight; //0x00C8
	AntRef m_HitFront; //0x00DC
	AntRef m_HitBack; //0x00F0
	AntRef m_DeathHitDirection; //0x0104
	AntRef m_Explosion; //0x0118
	AntRef m_Dead; //0x012C
	AntRef m_Revived; //0x0140
	AntRef m_RandomValue; //0x0154
	AntRef m_Pose; //0x0168
	AntRef m_RightSpeed; //0x017C
	AntRef m_ForwardSpeed; //0x0190
	AntRef m_CriticallyHit; //0x01A4
	AntRef m_InteractiveManDown; //0x01B8
	AntRef m_Health; //0x01CC
};//Size=0x01E0

////////////////////////////////////////
// RuntimeId: 09303
// TypeInfo:  0x00000001427F5638
struct AnimatedWeaponBinding
{
	AntRef m_Deploy; //0x0000
	AntRef m_AltDeploy; //0x0014
	AntRef m_Undeploy; //0x0028
	AntRef m_QuickSwitch; //0x003C
	AntRef m_Reload; //0x0050
	AntRef m_ReloadStage; //0x0064
	AntRef m_ReloadShotgun; //0x0078
	AntRef m_Fire; //0x008C
	AntRef m_FireSingle; //0x00A0
	AntRef m_FireHoldAndRelease; //0x00B4
	AntRef m_FireSimple; //0x00C8
	AntRef m_FirstShotSpawned; //0x00DC
	AntRef m_BoltAction; //0x00F0
	AntRef m_PumpAction; //0x0104
	AntRef m_MeleeAttack; //0x0118
	AntRef m_QuickThrow; //0x012C
	AntRef m_QuickThrowType; //0x0140
	AntRef m_AimBody; //0x0154
	AntRef m_AlwaysAimHead; //0x0168
	AntRef m_OneHanded; //0x017C
	AntRef m_OneHandedAiming; //0x0190
	AntRef m_AimingEnabled; //0x01A4
	AntRef m_LowerGun; //0x01B8
	AntRef m_BreathControl; //0x01CC
	AntRef m_RflType; //0x01E0
	AntRef m_PstlType; //0x01F4
	AntRef m_HgrType; //0x0208
	AntRef m_ATType; //0x021C
	AntRef m_ShgType; //0x0230
	AntRef m_LMGType; //0x0244
	AntRef m_BagType; //0x0258
	AntRef m_SnpType; //0x026C
	AntRef m_Zoom; //0x0280
	AntRef m_CantedZoom; //0x0294
	AntRef m_MagnifierSightToggle; //0x02A8
	AntRef m_AimBodyWeight; //0x02BC
	AntRef m_DisableZoomToggleWeight; //0x02D0
	AntRef m_ZoomParameter; //0x02E4
	AntRef m_ZoomScaleFactor; //0x02F8
	AntRef m_Dispersion; //0x030C
	AntRef m_AimTargetPosBody; //0x0320
	AntRef m_ZoomOutSpeed; //0x0334
	AntRef m_ZoomInSpeed; //0x0348
	AntRef m_UnDeploySpeed; //0x035C
	AntRef m_DeploySpeed; //0x0370
	AntRef m_LightEnabled; //0x0384
	AntRef m_FireModeChanged; //0x0398
	AntRef m_AnimType; //0x03AC
	AntRef m_GunDown; //0x03C0
	AntRef m_AllowSwitchingToWeaponInWater; //0x03D4
	AntRef m_NumberOfBulletsLeftInGun; //0x03E8
	AntRef m_BulletsLeftInGun; //0x03FC
	AntRef m_AbortVehicleDeploy; //0x0410
	AntRef m_CustomizeWeapon; //0x0424
	AntRef m_CustomizeWeaponSwitch; //0x0438
	AntRef m_WeaponActionESIG; //0x044C
	AntRef m_IsSprinting; //0x0460
	AntRef m_PreparingToBash; //0x0474
	AntRef m_JustStartedSprinting; //0x0488
	AntRef m_KickbackMagnitudeFactor; //0x049C
	AntRef m_KickbackSpeedFactor; //0x04B0
	AntRef m_ZoomingTime; //0x04C4
	AntRef m_TriggerZoomGunTwitch; //0x04D8
	AntRef m_WeaponChooserSignal; //0x04EC
	AntRef m_WeaponClassSignal; //0x0500
	AntRef m_OffsetX; //0x0514
	AntRef m_OffsetY; //0x0528
	AntRef m_OffsetZ; //0x053C
	AntRef m_AIAllowFire; //0x0550
	AntRef m_AIAltFireFromAnt; //0x0564
};//Size=0x0578

////////////////////////////////////////
// RuntimeId: 09301
// TypeInfo:  0x00000001427F5658
struct Animated3pOnlyWeaponBinding
{
	AntRef m_Deploy3P; //0x0000
	AntRef m_HideWeapon3p; //0x0014
	AntRef m_WeaponAssembled3p; //0x0028
};//Size=0x003C

////////////////////////////////////////
// RuntimeId: 09299
// TypeInfo:  0x00000001427F5678
struct Animated1pOnlyWeaponBinding
{
	AntRef m_UndeployFinished; //0x0000
	AntRef m_CameraFreeWeight; //0x0014
	AntRef m_Deploy1P; //0x0028
	AntRef m_HideWeapon1p; //0x003C
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 09223
// TypeInfo:  0x00000001427EDC18
struct ServerSoldierSelfHealMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09222
// TypeInfo:  0x00000001427EDC38
struct ServerSoldierManDownMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09221
// TypeInfo:  0x00000001427EDC58
struct ServerSoldierOnInitMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09220
// TypeInfo:  0x00000001427EDC78
struct ServerSoldierChangingWeaponMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09219
// TypeInfo:  0x00000001427EDC98
struct ServerSoldierFiringMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09218
// TypeInfo:  0x00000001427EDCB8
struct ServerSoldierDamagedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09217
// TypeInfo:  0x00000001427EDCD8
struct ServerProjectileMissileDestroyedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09216
// TypeInfo:  0x00000001427EDCF8
struct ServerProjectileMissileDamagedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09215
// TypeInfo:  0x00000001427EDD18
struct ClientSoldierChangeCoverStateMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09214
// TypeInfo:  0x00000001427EDD38
struct ClientSoldierOnLandMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09213
// TypeInfo:  0x00000001427EDD58
struct ClientSoldierOnJumpMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09190
// TypeInfo:  0x00000001427ED200
struct OriginResponseMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09189
// TypeInfo:  0x00000001427ED220
struct OriginRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09126
// TypeInfo:  0x00000001427EAF20
struct OnlineProviderConfiguration
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	char* m_ServiceName; //0x0008
	char* m_Client; //0x0010
	char* m_SKU; //0x0018
	char* m_Version; //0x0020
	unsigned __int32 m_ServerSocketPacketSize; //0x0028
	bool m_IsServer; //0x002C
	char _0x002D[3];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09124
// TypeInfo:  0x00000001427EAF40
struct OnlinePlatformConfiguration
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	OnlineServicesAsset* m_Services; //0x0008
	Array<PresenceBackendData*> m_ClientBackends; //0x0010
	Array<ServerBackendData*> m_ServerBackends; //0x0018
	bool m_IsFallback; //0x0020
	char _0x0021[7];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09114
// TypeInfo:  0x00000001427EAF80
struct OnlineEnvironmentUrlData
{
	char* m_Url; //0x0000
	OnlineEnvironment m_Environment; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09116
// TypeInfo:  0x00000001427EA9C0
struct OnlineEnvironmentUrl
{
	Array<OnlineEnvironmentUrlData> m_Urls; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09118
// TypeInfo:  0x00000001427EAF60
struct OnlineEnvironmentConsoleUrlData
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	OnlineEnvironmentUrl m_Url; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09120
// TypeInfo:  0x00000001427EA9A0
struct OnlineEnvironmentConsoleUrl
{
	Array<OnlineEnvironmentConsoleUrlData> m_Urls; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09108
// TypeInfo:  0x00000001427EA9E0
struct BlazeCreateGameParameters
{
	GameParametersData* m_Base; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09094
// TypeInfo:  0x00000001427EAFA0
struct Ps4CountryAgeOverrides
{
	char* m_CountryCode; //0x0000
	__int32 m_AgeRequirement; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09096
// TypeInfo:  0x00000001427EAA00
struct Ps4AgeSettings
{
	__int32 m_DefaultAgeRequirement; //0x0000
	char _0x0004[4];
	Array<Ps4CountryAgeOverrides> m_AgeOverrides; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09092
// TypeInfo:  0x00000001427EAA20
struct Ps4TitleData
{
	char* m_TitleId; //0x0000
	char* m_TitleSecret; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09084
// TypeInfo:  0x00000001427EAA40
struct Ps3ServiceId
{
	char* m_SPID; //0x0000
	char* m_ProductCode; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09086
// TypeInfo:  0x00000001427EAFC0
struct Ps3ServiceSettings
{
	char* m_Region; //0x0000
	char* m_ProductCode; //0x0008
	char* m_PrimaryProductCode; //0x0010
	Ps3ServiceId m_TicketingService; //0x0018
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09076
// TypeInfo:  0x00000001427EAA60
struct Ps3AgeLevels
{
	__int32 m_AgeLevel7; //0x0000
	__int32 m_AgeLevel8; //0x0004
	__int32 m_AgeLevel9; //0x0008
	__int32 m_AgeLevel10; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09078
// TypeInfo:  0x00000001427EB000
struct Ps3ParentalLockAgeSettingsForCountry
{
	char* m_CountryCode; //0x0000
	Ps3AgeLevels m_AgeLevels; //0x0008
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09082
// TypeInfo:  0x00000001427EAFE0
struct Ps3ParentalLockAgeSettings
{
	char* m_Region; //0x0000
	Ps3AgeLevels m_AgeLevels; //0x0008
	Ps3ParentalLockAgeSettingsOverrides* m_CountryOverrides; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09034
// TypeInfo:  0x00000001427EB0A0
struct MatchmakingSizeConfiguration
{
	MatchmakingPlatform m_Platform; //0x0000
	char _0x0004[4];
	Array<char*> m_Settings; //0x0008
	unsigned __int32 m_DesiredPlayerCount; //0x0010
	unsigned __int32 m_MinPlayerCount; //0x0014
	unsigned __int32 m_MaxPlayerCapacity; //0x0018
	char _0x001C[4];
	char* m_MinFitThreshold; //0x0020
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09056
// TypeInfo:  0x00000001427EAAA0
struct MatchmakingFreePlayerSlotsRule
{
	unsigned __int32 m_MaxFreePlayerSlots; //0x0000
	unsigned __int32 m_MinFreePlayerSlots; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09054
// TypeInfo:  0x00000001427EAAC0
struct MatchmakingSlotUtilizationRule
{
	unsigned __int32 m_PreferredPercentage; //0x0000
	unsigned __int32 m_MinPercentage; //0x0004
	unsigned __int32 m_MaxPercentage; //0x0008
	char _0x000C[4];
	char* m_RangeOffsetListName; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 09050
// TypeInfo:  0x00000001427EB020
struct MatchmakingMod
{
	Array<char*> m_Licenses; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09052
// TypeInfo:  0x00000001427EAAE0
struct MatchmakingModRule
{
	Array<MatchmakingMod> m_Mods; //0x0000
	char* m_MinFitThresholdListName; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09048
// TypeInfo:  0x00000001427EB040
struct MatchmakingUserExtendedDataRule
{
	char* m_Rule; //0x0000
	char* m_MinFitThresHold; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09044
// TypeInfo:  0x00000001427EB080
struct MatchmakingRuleString
{
	char* m_Value; //0x0000
	MatchmakingPlatform m_Platform; //0x0008
	char _0x000C[4];
	Array<char*> m_Licenses; //0x0010
	bool m_UseOnlyIfEmpty; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 09046
// TypeInfo:  0x00000001427EB060
struct MatchmakingGenericRule
{
	char* m_Rule; //0x0000
	char* m_MinFitThresHold; //0x0008
	char* m_Setting; //0x0010
	Array<MatchmakingRuleString> m_DesiredValues; //0x0018
	bool m_IgnoreIfDefault; //0x0020
	bool m_MergeValues; //0x0021
	bool m_SortValues; //0x0022
	char _0x0023[5];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09042
// TypeInfo:  0x00000001427EAB00
struct MatchmakingRankedRule
{
	char* m_MinFitThreshold; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09040
// TypeInfo:  0x00000001427EAB20
struct MatchmakingPingSiteRule
{
	char* m_MinFitThreshold; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 09036
// TypeInfo:  0x00000001427EAB60
struct MatchmakingSizeRule
{
	char* m_Setting; //0x0000
	Array<MatchmakingSizeConfiguration> m_Configurations; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09032
// TypeInfo:  0x00000001427EAB80
struct MatchmakingVirtualizedRule
{
	char* m_MinFitThreshold; //0x0000
	MatchmakingVirtualizationMode m_VirtualizationMode; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09058
// TypeInfo:  0x00000001427EAA80
struct MatchmakingCriteria
{
	MatchmakingSizeRule m_SizeRule; //0x0000
	MatchmakingPingSiteRule m_PingSiteRule; //0x0010
	MatchmakingRankedRule m_RankedRule; //0x0018
	Array<MatchmakingGenericRule> m_GenericRules; //0x0020
	MatchmakingVirtualizedRule m_VirtualizedRule; //0x0028
	Array<MatchmakingUserExtendedDataRule> m_UEDRules; //0x0038
	MatchmakingModRule m_ModRule; //0x0040
	MatchmakingSlotUtilizationRule m_SlotUtilizationRule; //0x0050
	MatchmakingFreePlayerSlotsRule m_FreePlayerSlotsRule; //0x0068
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 09026
// TypeInfo:  0x00000001427EABA0
struct ServerBackendEjectHostMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09025
// TypeInfo:  0x00000001427EABC0
struct ServerBackendStatsDownloadFailMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09024
// TypeInfo:  0x00000001427EABE0
struct ServerGameManagerAvailableMapsChangedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09023
// TypeInfo:  0x00000001427EAC00
struct ServerGameManagerKickPlayerMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09022
// TypeInfo:  0x00000001427EAC20
struct ServerGameManagerAddQueuedPlayerMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 09021
// TypeInfo:  0x00000001427EAC40
struct ServerGameManagerValidateBannerResponseMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09020
// TypeInfo:  0x00000001427EAC60
struct ServerGameManagerValidateBannerRequestMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 09019
// TypeInfo:  0x00000001427EAC80
struct ServerGameManagerAddGameBanResponseMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09018
// TypeInfo:  0x00000001427EACA0
struct ServerGameManagerAddGameBanRequestMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09017
// TypeInfo:  0x00000001427EACC0
struct ServerGameManagerGetGameDataMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09016
// TypeInfo:  0x00000001427EACE0
struct ServerGameManagerRestartLevelRequestMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09015
// TypeInfo:  0x00000001427EAD00
struct ServerGameManagerGameDestructingMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09014
// TypeInfo:  0x00000001427EAD20
struct ServerGameManagerPlayerRemovedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09013
// TypeInfo:  0x00000001427EAD40
struct ServerGameManagerPlayerJoiningQueueMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 09012
// TypeInfo:  0x00000001427EAD60
struct ServerGameManagerCheckPlayerStatusMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 09011
// TypeInfo:  0x00000001427EAD80
struct ServerGameManagerPlayerJoiningMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09010
// TypeInfo:  0x00000001427EADA0
struct ServerGameManagerUpdateCapacityMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09009
// TypeInfo:  0x00000001427EADC0
struct ServerGameManagerGameParametersChangedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09008
// TypeInfo:  0x00000001427EADE0
struct ServerGameManagerChangeGameParametersMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09007
// TypeInfo:  0x00000001427EAE00
struct ServerGameManagerReconfigurableGameCreatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09006
// TypeInfo:  0x00000001427EAE20
struct ServerGameManagerCreatingReconfigurableGameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09005
// TypeInfo:  0x00000001427EAE40
struct ServerGameManagerGameResetMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09004
// TypeInfo:  0x00000001427EAE60
struct ServerGameManagerGameCreatedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09003
// TypeInfo:  0x00000001427EAE80
struct ServerGameManagerCreatingGameMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09002
// TypeInfo:  0x00000001427EAEA0
struct ServerBackendFinalizingMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 09001
// TypeInfo:  0x00000001427EAEC0
struct ServerBackendDownloadCompleteMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08998
// TypeInfo:  0x00000001427EB0C0
struct LicenseInfo
{
	char* m_Name; //0x0000
	bool m_ClientOnly; //0x0008
	char _0x0009[7];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08988
// TypeInfo:  0x00000001427EB0E0
struct GameAttributeData
{
	char* m_Attribute; //0x0000
	char* m_Value; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08982
// TypeInfo:  0x00000001427E8630
struct PresenceUserIdRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08981
// TypeInfo:  0x00000001427E8650
struct PresenceUserIdMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08980
// TypeInfo:  0x00000001427E8670
struct PresenceStorageRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08979
// TypeInfo:  0x00000001427E8690
struct PresenceStorageMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08978
// TypeInfo:  0x00000001427E86B0
struct PresenceProfileInfoRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08977
// TypeInfo:  0x00000001427E86D0
struct PresenceProfileInfoMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08976
// TypeInfo:  0x00000001427E86F0
struct PresencePrivilegeRequestResultMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08975
// TypeInfo:  0x00000001427E8710
struct PresencePrivilegeRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08974
// TypeInfo:  0x00000001427E8730
struct PresencePlaygroupRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08973
// TypeInfo:  0x00000001427E8750
struct PresencePlaygroupAttributesMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08972
// TypeInfo:  0x00000001427E8770
struct PresencePlaygroupMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08971
// TypeInfo:  0x00000001427E8790
struct PresenceMatchmakerMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08970
// TypeInfo:  0x00000001427E87B0
struct PresenceLivePartyMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08969
// TypeInfo:  0x00000001427E87D0
struct PresenceLicenseMetricMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08968
// TypeInfo:  0x00000001427E87F0
struct PresenceLicenseRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08967
// TypeInfo:  0x00000001427E8810
struct PresenceLicenseMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08966
// TypeInfo:  0x00000001427E8830
struct PresenceJoinResultMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08965
// TypeInfo:  0x00000001427E8850
struct PresenceGameRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08964
// TypeInfo:  0x00000001427E8870
struct PresenceGameQueueMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08963
// TypeInfo:  0x00000001427E8890
struct PresenceGameMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08962
// TypeInfo:  0x00000001427E88B0
struct PresenceFriendsListManagerSettingsMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08961
// TypeInfo:  0x00000001427E88D0
struct PresenceFriendRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08960
// TypeInfo:  0x00000001427E88F0
struct PresenceFriendMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08959
// TypeInfo:  0x00000001427E8910
struct PresenceConnectionRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08958
// TypeInfo:  0x00000001427E8930
struct PresenceConnectionMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08957
// TypeInfo:  0x00000001427E8950
struct PresenceBrowserRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08956
// TypeInfo:  0x00000001427E8970
struct PresenceBlockListRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08955
// TypeInfo:  0x00000001427E8990
struct PresenceBlockListMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08954
// TypeInfo:  0x00000001427E89B0
struct PresenceBlobRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08953
// TypeInfo:  0x00000001427E89D0
struct PresenceBlobMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08952
// TypeInfo:  0x00000001427E89F0
struct PresenceAchievementRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08951
// TypeInfo:  0x00000001427E8A10
struct OnlineInternalGameMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08946
// TypeInfo:  0x00000001427E7C40
struct PresenceNickelRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08945
// TypeInfo:  0x00000001427E7C60
struct PresenceNickelMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08870
// TypeInfo:  0x00000001427E4788
struct SkyCloudLayer
{
	Vec3 m_Color; //0x0000
	float m_Altitude; //0x0010
	float m_TileFactor; //0x0014
	float m_Rotation; //0x0018
	float m_Speed; //0x001C
	float m_SunLightIntensity; //0x0020
	float m_SunLightPower; //0x0024
	float m_AmbientLightIntensity; //0x0028
	float m_AlphaMul; //0x002C
	TextureAsset* m_Texture; //0x0030
	char _0x0038[8];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 03550
// TypeInfo:  0x00000001420DC7D0
struct Vec2
{
	float m_x; //0x0000
	float m_y; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 08796
// TypeInfo:  0x00000001427E47A8
struct GroundHeightData
{
	float m_WorldSize; //0x0000
	Vec2 m_HeightSpan; //0x0004
	char _0x000C[4];
	Array<unsigned __int16> m_Data; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 08744
// TypeInfo:  0x00000001427E2830
struct VegetationEffectSlot
{
	EffectBlueprint* m_Effect; //0x0000
	float m_StrengthMin; //0x0008
	float m_StrengthMax; //0x000C
	float m_SizeMin; //0x0010
	float m_SizeMax; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 08735
// TypeInfo:  0x00000001427E0718
struct UIPremiumContentUpdateMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08734
// TypeInfo:  0x00000001427E0738
struct UIComponentDeferActionMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08733
// TypeInfo:  0x00000001427E0758
struct UIComponentOnItemChangedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08732
// TypeInfo:  0x00000001427E0778
struct UIComponentChangeCameraViewPointMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 08731
// TypeInfo:  0x00000001427E0798
struct UIComponentSetSettingMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 08730
// TypeInfo:  0x00000001427E07B8
struct UIComponentLoadCompleteMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08729
// TypeInfo:  0x00000001427E07D8
struct UIReadyForUnloadMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08728
// TypeInfo:  0x00000001427E07F8
struct UISoldierChangeMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08725
// TypeInfo:  0x00000001427E0838
struct UIAssetChangedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08724
// TypeInfo:  0x00000001427E0858
struct UIInputPressedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08723
// TypeInfo:  0x00000001427E0878
struct UIGraphExitedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08722
// TypeInfo:  0x00000001427E0898
struct UIScreenLoadedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08721
// TypeInfo:  0x00000001427E08B8
struct UIFirstPartyUIMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08720
// TypeInfo:  0x00000001427E08D8
struct UITransitionEffectStopMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08719
// TypeInfo:  0x00000001427E08F8
struct UITransitionEffectStartMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08718
// TypeInfo:  0x00000001427E0918
struct UIExitToMenuReasonMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08717
// TypeInfo:  0x00000001427E0938
struct UISpawnAllowedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08716
// TypeInfo:  0x00000001427E0958
struct UIVehicleHitUpdatedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 08715
// TypeInfo:  0x00000001427E0978
struct UISquadStatusChangedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08714
// TypeInfo:  0x00000001427E0998
struct UISoldierHitUpdatedMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 08713
// TypeInfo:  0x00000001427E09B8
struct UIReturnMouseToUIMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08712
// TypeInfo:  0x00000001427E09D8
struct UIPlayerVehicleHealthChangeMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08711
// TypeInfo:  0x00000001427E09F8
struct UILevelWarmUpTimerMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08710
// TypeInfo:  0x00000001427E0A18
struct UIInputStatusChangedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08709
// TypeInfo:  0x00000001427E0A38
struct UIHudWarningMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08708
// TypeInfo:  0x00000001427E0A58
struct UIHudUpdateCrosshairMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08707
// TypeInfo:  0x00000001427E0A78
struct UIHudToggleMapZoomMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08706
// TypeInfo:  0x00000001427E0A98
struct UIHudShowVoteResultsMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08705
// TypeInfo:  0x00000001427E0AB8
struct UIHudShowVoteMenuMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08704
// TypeInfo:  0x00000001427E0AD8
struct UIHudOutputStaticMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08703
// TypeInfo:  0x00000001427E0AF8
struct UIHudDistortHudMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08702
// TypeInfo:  0x00000001427E0B18
struct UIHudDebugPauseMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08701
// TypeInfo:  0x00000001427E0B38
struct UIHudChatMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 08700
// TypeInfo:  0x00000001427E0B58
struct UIHudChangeInventoryWeaponMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08699
// TypeInfo:  0x00000001427E0B78
struct UIHasSuppressedEnemyMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08698
// TypeInfo:  0x00000001427E0B98
struct UIDamageGivenToEnemyMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08697
// TypeInfo:  0x00000001427E0BB8
struct UICycleRadioChannelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08696
// TypeInfo:  0x00000001427E0BD8
struct UIMatchImagesRetrievedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08695
// TypeInfo:  0x00000001427E0BF8
struct UIRequestMatchImagesMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08694
// TypeInfo:  0x00000001427E0C18
struct UIVKBDInputDoneMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 08693
// TypeInfo:  0x00000001427E0C38
struct UISubtitleMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 08692
// TypeInfo:  0x00000001427E0C58
struct UIMessageEntityMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 08691
// TypeInfo:  0x00000001427E0C78
struct UIScreenCountChangeMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08690
// TypeInfo:  0x00000001427E0C98
struct UIControllerDisconnectedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08689
// TypeInfo:  0x00000001427E0CB8
struct UIControllerConnectedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08688
// TypeInfo:  0x00000001427E0CD8
struct UIUserDisconnectedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08687
// TypeInfo:  0x00000001427E0CF8
struct UIUserConnectedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08686
// TypeInfo:  0x00000001427E0D18
struct UIUserNotificationMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08685
// TypeInfo:  0x00000001427E0D38
struct UIUserSkippedLoginMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08684
// TypeInfo:  0x00000001427E0D58
struct MemoryCardBootCheckMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08683
// TypeInfo:  0x00000001427E0D78
struct MemoryCardFindEntriesDoneMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08682
// TypeInfo:  0x00000001427E0D98
struct MemoryCardFindEntriesMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08681
// TypeInfo:  0x00000001427E0DB8
struct MemoryCardSaveDoneMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08680
// TypeInfo:  0x00000001427E0DD8
struct MemoryCardSaveMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08679
// TypeInfo:  0x00000001427E0DF8
struct MemoryCardLoadDoneMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08678
// TypeInfo:  0x00000001427E0E18
struct MemoryCardLoadMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08677
// TypeInfo:  0x00000001427E0E38
struct MemoryCardDestroyedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08676
// TypeInfo:  0x00000001427E0E58
struct MemoryCardInitializedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08675
// TypeInfo:  0x00000001427E0E78
struct MemoryCardCreatedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08674
// TypeInfo:  0x00000001427E0E98
struct MemoryCardPopupHideMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08673
// TypeInfo:  0x00000001427E0EB8
struct MemoryCardPopupResponseMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08672
// TypeInfo:  0x00000001427E0ED8
struct MemoryCardPopupRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08657
// TypeInfo:  0x00000001427E1038
struct UIPopupButton
{
	UIInputAction m_InputConcept; //0x0000
	char _0x0004[4];
	char* m_Label; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08609
// TypeInfo:  0x00000001427E1058
struct WidgetEventQueryPair
{
	char* m_Name; //0x0000
	UIWidgetEventID m_Query; //0x0008
	char _0x000C[4];
	char* m_InstanceName; //0x0010
	bool m_IsOutput; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 08599
// TypeInfo:  0x00000001427E1078
struct UIDataSourceInfo
{
	char* m_DataName; //0x0000
	UIComponentData* m_DataCategory; //0x0008
	__int32 m_DataKey; //0x0010
	bool m_UseDirectAccess; //0x0014
	bool m_UpdateOnInitialize; //0x0015
	char _0x0016[2];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 08597
// TypeInfo:  0x00000001427E0EF8
struct UISimpleDataSource
{
	UIComponentData* m_DataCategory; //0x0000
	__int32 m_DataKey; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08593
// TypeInfo:  0x00000001427E1098
struct UIWidgetProperty
{
	char* m_Name; //0x0000
	char* m_Value; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08579
// TypeInfo:  0x00000001427E10B8
struct InterruptFlow
{
	UIInterruptID m_interruptEnum; //0x0000
	char _0x0004[4];
	UIGraphAsset* m_interruptFlow; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08575
// TypeInfo:  0x00000001427E10D8
struct UIAudioEventMapping
{
	char* m_EventName; //0x0000
	SoundAsset* m_SoundAsset; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08555
// TypeInfo:  0x00000001427E10F8
struct UIResourceTableEntry
{
	// unhandled basic type ResourceRef m_Resource; //0x0000
	char _0x0000[8];
	unsigned __int32 m_Hash; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08547
// TypeInfo:  0x00000001427E1118
struct UIFontMapping
{
	Array<char*> m_ScaleformFontName; //0x0000
	char* m_FontLongName; //0x0008
	bool m_Bold; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 08541
// TypeInfo:  0x00000001427E1138
struct FontCollectionLookupEntry
{
	char* m_CollectionBasePath; //0x0000
	LanguageFormat m_Language; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08539
// TypeInfo:  0x00000001427E1158
struct UIBundleAssetState
{
	char* m_StateName; //0x0000
	UIState m_UIState; //0x0008
	char _0x000C[4];
	char* m_ResourceBundleName; //0x0010
	char* m_StatePath; //0x0018
	char* m_BundlePath; //0x0020
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08479
// TypeInfo:  0x00000001427DC290
struct TerrainQuadDecalAtlasTile
{
	unsigned __int32 m_TileIndexX; //0x0000
	unsigned __int32 m_TileIndexY; //0x0004
	unsigned __int32 m_TileCountX; //0x0008
	unsigned __int32 m_TileCountY; //0x000C
	bool m_FlipX; //0x0010
	bool m_FlipY; //0x0011
	char _0x0012[2];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 08467
// TypeInfo:  0x00000001427DC450
struct RibbonPointData
{
	Vec4 m_UserMaskLeft; //0x0000
	Vec4 m_UserMaskRight; //0x0010
	float m_Left; //0x0020
	float m_Right; //0x0024
	char _0x0028[8];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08459
// TypeInfo:  0x00000001427DC470
struct TerrainLayerShaderData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08457
// TypeInfo:  0x00000001427DC490
struct MeshScatteringSpawnData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08443
// TypeInfo:  0x00000001427DC4B0
struct TerrainLayerMaskData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08431
// TypeInfo:  0x00000001427DC4D0
struct TerrainLayerCombinationDrawData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08429
// TypeInfo:  0x00000001427DC4F0
struct Surface3dDrawMethodData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08427
// TypeInfo:  0x00000001427DC510
struct MeshScatteringMaskScaleDrawMethodData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08425
// TypeInfo:  0x00000001427DC530
struct Surface2dDrawMethodData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08423
// TypeInfo:  0x00000001427DC550
struct Surface2dDrawPassData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08421
// TypeInfo:  0x00000001427DC570
struct TerrainLayerCombinationDrawPassData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08405
// TypeInfo:  0x00000001427DC590
struct TerrainLayerProceduralMask
{
	float m_AltitudeMin; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 08403
// TypeInfo:  0x00000001427DC5B0
struct TerrainGeoTexture
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08359
// TypeInfo:  0x00000001427DC5D0
struct RectangularCoverageData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 08343
// TypeInfo:  0x00000001427D8F08
struct PerformanceClientMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08342
// TypeInfo:  0x00000001427D8F28
struct PerformanceShaderMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 08293
// TypeInfo:  0x00000001427D94C8
struct TerrainShaderParameter
{
	unsigned __int32 m_ParameterHandle; //0x0000
	TerrainShaderParameterDataType m_ParameterType; //0x0004
	char* m_ParameterName; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08241
// TypeInfo:  0x00000001427D9548
struct BoolShaderParameter
{
	char* m_ParameterName; //0x0000
	bool m_Value; //0x0008
	char _0x0009[7];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08247
// TypeInfo:  0x00000001427D94E8
struct VectorArrayShaderParameter
{
	char* m_ParameterName; //0x0000
	ShaderParameterType m_ParameterType; //0x0008
	char _0x000C[4];
	Array<Vec4> m_Values; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 08245
// TypeInfo:  0x00000001427D9508
struct TextureShaderParameter
{
	char* m_ParameterName; //0x0000
	TextureBaseAsset* m_Value; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08243
// TypeInfo:  0x00000001427D9528
struct VectorShaderParameter
{
	Vec4 m_Value; //0x0000
	char* m_ParameterName; //0x0010
	ShaderParameterType m_ParameterType; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 08253
// TypeInfo:  0x00000001427D9388
struct SurfaceShaderInstanceDataStruct
{
	SurfaceShaderBaseAsset* m_Shader; //0x0000
	Array<BoolShaderParameter> m_BoolParameters; //0x0008
	Array<VectorShaderParameter> m_VectorParameters; //0x0010
	Array<VectorArrayShaderParameter> m_VectorArrayParameters; //0x0018
	Array<TextureShaderParameter> m_TextureParameters; //0x0020
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 08225
// TypeInfo:  0x00000001427D93C8
struct PoissonRadialBlurData
{
	float m_BlendFactor; //0x0000
	Vec2 m_PoissonDiscScale; //0x0004
	float m_RadialScale; //0x000C
	float m_RadialExponent; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 08223
// TypeInfo:  0x00000001427D93E8
struct ColorTintData
{
	Vec3 m_Contrast; //0x0000
	Vec3 m_Brightness; //0x0010
	Vec3 m_Saturation; //0x0020
	float m_Hue; //0x0030
	char _0x0034[12];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 08171
// TypeInfo:  0x00000001427D9568
struct AnimatedPointCloudAttributeDesc
{
	PointCloudAttributeUsage m_Usage; //0x0000
	PointCloudAttributeQuantization m_IFrameQuantization; //0x0004
	PointCloudAttributeQuantization m_DFrameQuantization; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 08169
// TypeInfo:  0x00000001427D9588
struct VariationLink
{
	unsigned __int64 m_VariationKey; //0x0000
	unsigned __int32 m_ObjectVariationHash; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08161
// TypeInfo:  0x00000001427D95A8
struct MeshVariationDatabaseRedirectEntry
{
	MeshAsset* m_Mesh; //0x0000
	unsigned __int32 m_VariationAssetNameHash; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 08157
// TypeInfo:  0x00000001427D95E8
struct MeshVariationDatabaseMaterial
{
	MeshMaterial* m_Material; //0x0000
	MeshMaterialVariation* m_MaterialVariation; //0x0008
	Array<TextureShaderParameter> m_TextureParameters; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 08159
// TypeInfo:  0x00000001427D95C8
struct MeshVariationDatabaseEntry
{
	MeshAsset* m_Mesh; //0x0000
	unsigned __int32 m_VariationAssetNameHash; //0x0008
	char _0x000C[4];
	Array<MeshVariationDatabaseMaterial> m_Materials; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 08110
// TypeInfo:  0x00000001427D5A38
struct DecalAtlasTile
{
	float m_TileIndexX; //0x0000
	float m_TileIndexY; //0x0004
	float m_TileCountX; //0x0008
	float m_TileCountY; //0x000C
	bool m_FlipX; //0x0010
	bool m_FlipY; //0x0011
	char _0x0012[2];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03564
// TypeInfo:  0x00000001420DC890
struct AxisAlignedBox
{
	Vec3 m_min; //0x0000
	Vec3 m_max; //0x0010
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07965
// TypeInfo:  0x00000001427D1C98
struct PhysicsComponentOnImpulseMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07964
// TypeInfo:  0x00000001427D1CB8
struct PhysicsComponentOnDamageMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07943
// TypeInfo:  0x00000001427D1E18
struct AssetAabbs
{
	Array<AxisAlignedBox> m_PartAabb; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07935
// TypeInfo:  0x00000001427D1CD8
struct EndPointData
{
	float m_Pos; //0x0000
	float m_EndDamping; //0x0004
	float m_SpringLength; //0x0008
	float m_SpringAcceleration; //0x000C
	float m_SpringDamping; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 07919
// TypeInfo:  0x00000001427D1E38
struct FrictionScaleAtVelocity
{
	float m_FrictionScale; //0x0000
	float m_Velocity; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07917
// TypeInfo:  0x00000001427D1E58
struct SensitivityAtVelocity
{
	float m_SteeringSensitivity; //0x0000
	float m_Velocity; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07915
// TypeInfo:  0x00000001427D1CF8
struct SpringData
{
	float m_Length; //0x0000
	float m_Stiffness; //0x0004
	float m_Damping; //0x0008
	float m_ProgressiveStartRatio; //0x000C
	float m_ProgressiveExponent; //0x0010
	float m_VisualClipOffset; //0x0014
	float m_AttachOffsetY; //0x0018
	float m_DisabledStrenghModifier; //0x001C
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07913
// TypeInfo:  0x00000001427D1D18
struct SphereCollisionData
{
	float m_ExtraRadius; //0x0000
	float m_CounterNormalBrakeForceMod; //0x0004
	bool m_Enabled; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 07897
// TypeInfo:  0x00000001427D1D38
struct Boost
{
	float m_ForwardStrength; //0x0000
	float m_ReverseStrength; //0x0004
	float m_DissipationTime; //0x0008
	float m_RecoveryTime; //0x000C
	float m_CrawlStrength; //0x0010
	float m_AccelerationScale; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07865
// TypeInfo:  0x00000001427D1D58
struct InputThrottle
{
	float m_ForwardSpeedSupressionAmount; //0x0000
	float m_BackwardSpeedSupressionAmount; //0x0004
	float m_SideSpeedSupressionAmount; //0x0008
	float m_IgnoreBrakeSpeedThreshold; //0x000C
	bool m_Enabled; //0x0010
	char _0x0011[3];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 07863
// TypeInfo:  0x00000001427D1E78
struct ConstantForceData
{
	Vec3 m_Value; //0x0000
	ForceCondition m_Condition; //0x0010
	ForceType m_TypeOfForce; //0x0014
	SpaceType m_Space; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07855
// TypeInfo:  0x00000001427D1E98
struct StabilizerSettings
{
	StabilizerProperty m_Property; //0x0000
	float m_Strength; //0x0004
	float m_Radius; //0x0008
	bool m_Advanced; //0x000C
	bool m_Use2DRadiusTest; //0x000D
	bool m_UseInputOverride; //0x000E
	char _0x000F[1];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07853
// TypeInfo:  0x00000001427D1D78
struct AntiRollBars
{
	AntiRollBar* m_Front; //0x0000
	AntiRollBar* m_Rear; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07849
// TypeInfo:  0x00000001427D1D98
struct VehicleInputData
{
	float m_ThrottleDeadzone; //0x0000
	float m_BrakeDeadzone; //0x0004
	float m_YawDeadzone; //0x0008
	float m_PitchDeadzone; //0x000C
	float m_RollDeadzone; //0x0010
	float m_ThrottleInertiaOutDuration; //0x0014
	float m_ThrottleInertiaInDuration; //0x0018
	float m_ThrottleInertiaMinRatio; //0x001C
	float m_BrakeInertiaOutDuration; //0x0020
	float m_BrakeInertiaInDuration; //0x0024
	float m_BrakeInertiaMinRatio; //0x0028
	float m_YawInertiaOutDuration; //0x002C
	float m_YawInertiaInDuration; //0x0030
	float m_YawInertiaMinRatio; //0x0034
	float m_PitchInertiaOutDuration; //0x0038
	float m_PitchInertiaInDuration; //0x003C
	float m_PitchInertiaMinRatio; //0x0040
	float m_RollInertiaOutDuration; //0x0044
	float m_RollInertiaInDuration; //0x0048
	float m_RollInertiaMinRatio; //0x004C
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 07817
// TypeInfo:  0x00000001427D1DB8
struct SpeedModifierData
{
	float m_ForwardConstant; //0x0000
	float m_BackwardConstant; //0x0004
	float m_LeftConstant; //0x0008
	float m_RightConstant; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07813
// TypeInfo:  0x00000001427D1EB8
struct PoseTransitionTime
{
	CharacterPoseType m_ToPose; //0x0000
	float m_TransitionTime; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07807
// TypeInfo:  0x00000001427D1ED8
struct CharacterPoseConstraintsData
{
	bool m_StandPose; //0x0000
	bool m_CrouchPose; //0x0001
	bool m_PronePose; //0x0002
};//Size=0x0003

////////////////////////////////////////
// RuntimeId: 07805
// TypeInfo:  0x00000001427D1DD8
struct LookConstraintsData
{
	float m_MinLookYaw; //0x0000
	float m_MaxLookYaw; //0x0004
	float m_MinLookPitch; //0x0008
	float m_MaxLookPitch; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07793
// TypeInfo:  0x00000001427CF1E0
struct EdgeModelInstance
{
	LinearTransform m_Transform; //0x0000
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 07777
// TypeInfo:  0x00000001427CF220
struct ClothStateSetupTransitionLookup
{
	unsigned __int32 m_FirstTransitionableLodIndex; //0x0000
	unsigned __int32 m_TransitionableLodCount; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07779
// TypeInfo:  0x00000001427CF200
struct ClothStateSetupTransition
{
	unsigned __int32 m_TransitionLodIndex; //0x0000
	unsigned __int32 m_TransitionLodStateIndex; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07781
// TypeInfo:  0x00000001427CF1C0
struct ClothStatesSetup
{
	Array<unsigned __int32> m_States; //0x0000
	Array<ClothStateSetupTransitionLookup> m_StatesTransitionLookups; //0x0008
	Array<ClothStateSetupTransition> m_StatesTransitions; //0x0010
	unsigned __int32 m_EmptyState; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07775
// TypeInfo:  0x00000001427CF240
struct ClothBoneTableEntry
{
	char* m_BoneName; //0x0000
	unsigned __int32 m_TransformIndex; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07773
// TypeInfo:  0x00000001427CF260
struct ClothSectionMapping
{
	char* m_ClothMeshName; //0x0000
	Array<unsigned __int32> m_SubsetIds; //0x0008
	unsigned __int32 m_LodIndex; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07761
// TypeInfo:  0x00000001427CE8F8
struct SpikeInternalMessagePartMessage
{
	char _0x0000[120];
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 07760
// TypeInfo:  0x00000001427CE918
struct SpikeInternalMessageWrapperMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 07755
// TypeInfo:  0x00000001427CE820
struct CoreDemoStatusMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07752
// TypeInfo:  0x00000001427CE6A0
struct MovieAsyncUnloadMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07747
// TypeInfo:  0x00000001427CDB70
struct AntAnimatableComponentMeshData
{
	AntAnimatableComponentMeshRenderType m_MeshRenderType; //0x0000
	AntAnimatableComponentMeshRenderContext m_MeshRenderContext; //0x0004
	MeshAsset* m_Mesh; //0x0008
	float m_CameraRelativeScaleX; //0x0010
	float m_CameraRelativeScaleY; //0x0014
	float m_CameraRelativeScaleZ; //0x0018
	float m_CameraRelativeOffsetX; //0x001C
	float m_CameraRelativeOffsetY; //0x0020
	float m_CameraRelativeOffsetZ; //0x0024
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03716
// TypeInfo:  0x000000014276DCA0
struct AntAnimatableData
{
	AntRef m_Actor; //0x0000
	AntRef m_SceneOpMatrix; //0x0014
	ProceduralAwarenessAntRefs* m_ProceduralAwareness; //0x0028
	AntRef m_RightHandEffectorDisableOverride; //0x0030
	AntRef m_LeftHandEffectorDisableOverride; //0x0044
	MasterSkeletonAsset* m_MasterSkeletonAsset; //0x0058
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 07733
// TypeInfo:  0x00000001427CDB10
struct LodBinding
{
	AntRef m_DisableControllerUpdate; //0x0000
	AntRef m_DisablePoseUpdate; //0x0014
	AntRef m_DistanceFromCamera; //0x0028
	AntRef m_AnimatableInstanceId; //0x003C
	AntRef m_ResetController; //0x0050
};//Size=0x0064

////////////////////////////////////////
// RuntimeId: 07725
// TypeInfo:  0x00000001427CDB90
struct PoseConstraintsData
{
	bool m_StandPose; //0x0000
	bool m_CrouchPose; //0x0001
	bool m_PronePose; //0x0002
};//Size=0x0003

////////////////////////////////////////
// RuntimeId: 07723
// TypeInfo:  0x00000001427CDBB0
struct AimingConstraintsData
{
	float m_MinYaw; //0x0000
	float m_MaxYaw; //0x0004
	float m_MinPitch; //0x0008
	float m_MaxPitch; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07671
// TypeInfo:  0x00000001427CDBD0
struct DataVisualizerValue
{
	char* m_Value; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07655
// TypeInfo:  0x00000001427CBC10
struct WeaponModifierCore
{
	__int32 m_DummyToMakeFrostEDcompile; //0x0000
	char _0x0004[140];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 07637
// TypeInfo:  0x00000001427CBC30
struct WeaponMiscModifierSettings
{
	bool m_EnableBreathControl; //0x0000
	bool m_CanBeInSupportedShooting; //0x0001
	bool m_UnZoomOnBoltAction; //0x0002
	bool m_HoldBoltActionUntilZoomRelease; //0x0003
	bool m_IsSilenced; //0x0004
};//Size=0x0005

////////////////////////////////////////
// RuntimeId: 07621
// TypeInfo:  0x00000001427CB970
struct ArtilleryDispersionData
{
	float m_MaxDispersion; //0x0000
	float m_DispersionAimMove; //0x0004
	float m_DispersionAimMoveThreshold; //0x0008
	float m_DispersionFiring; //0x000C
	float m_DispersionDeployment; //0x0010
	float m_DecreasePerSecond; //0x0014
	bool m_DispersionActive; //0x0018
	char _0x0019[3];
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 07603
// TypeInfo:  0x00000001427CB9B0
struct RumbleFiringData
{
	float m_LowRumble; //0x0000
	float m_HighRumble; //0x0004
	float m_RumbleDuration; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 07593
// TypeInfo:  0x00000001427CBA30
struct FiringDispersionData
{
	float m_MinAngle; //0x0000
	float m_MaxAngle; //0x0004
	float m_IncreasePerShot; //0x0008
	float m_DecreasePerSecond; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07595
// TypeInfo:  0x00000001427CBA10
struct FireEffectData
{
	Vec3 m_Offset; //0x0000
	Vec3 m_Rotation; //0x0010
	Vec3 m_ZoomOffset; //0x0020
	Vec3 m_ZoomRotation; //0x0030
	EffectBlueprint* m_Effect; //0x0040
	bool m_UseZoomOffset; //0x0048
	bool m_UseZoomRotation; //0x0049
	bool m_DisableDuringZoom; //0x004A
	bool m_UpdateTransform; //0x004B
	bool m_StopLoopingEffects; //0x004C
	char _0x004D[3];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 07597
// TypeInfo:  0x00000001427CB9F0
struct OverHeatData
{
	FireEffectData m_OverHeatEffect; //0x0000
	float m_HeatPerBullet; //0x0050
	float m_HeatDropPerSecond; //0x0054
	float m_OverHeatPenaltyTime; //0x0058
	float m_OverHeatThreshold; //0x005C
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 07599
// TypeInfo:  0x00000001427CB9D0
struct WeaponDispersion
{
	FiringDispersionData m_StandDispersion; //0x0000
	FiringDispersionData m_CrouchDispersion; //0x0010
	FiringDispersionData m_ProneDispersion; //0x0020
	float m_JumpDispersionAngle; //0x0030
	float m_ProneTransitionDispersionAngle; //0x0034
	float m_MoveDispersionAngle; //0x0038
	float m_MoveZoomedDispersionAngle; //0x003C
	float m_DecreasePerSecond; //0x0040
};//Size=0x0044

////////////////////////////////////////
// RuntimeId: 07579
// TypeInfo:  0x00000001427CBAB0
struct HoldAndReleaseData
{
	float m_MaxHoldTime; //0x0000
	float m_MinPowerModifier; //0x0004
	float m_MaxPowerModifier; //0x0008
	float m_PowerIncreasePerSecond; //0x000C
	float m_Delay; //0x0010
	float m_KilledHoldingPowerModifier; //0x0014
	bool m_ForceFireWhenKilledHolding; //0x0018
	char _0x0019[3];
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 07589
// TypeInfo:  0x00000001427CBA70
struct RecoilData
{
	float m_MaxRecoilAngleX; //0x0000
	float m_MinRecoilAngleX; //0x0004
	float m_MaxRecoilAngleY; //0x0008
	float m_MinRecoilAngleY; //0x000C
	float m_MaxRecoilAngleZ; //0x0010
	float m_MinRecoilAngleZ; //0x0014
	float m_MaxRecoilFov; //0x0018
	float m_MinRecoilFov; //0x001C
	bool m_RecoilFollowsDispersion; //0x0020
	char _0x0021[3];
};//Size=0x0024

////////////////////////////////////////
// RuntimeId: 07581
// TypeInfo:  0x00000001427CBA90
struct BoltActionData
{
	float m_BoltActionDelay; //0x0000
	float m_BoltActionTime; //0x0004
	bool m_HoldBoltActionUntilFireRelease; //0x0008
	bool m_HoldBoltActionUntilZoomRelease; //0x0009
	bool m_ForceBoltActionOnFireTrigger; //0x000A
	bool m_UnZoomOnBoltAction; //0x000B
	bool m_ReturnToZoomAfterBoltAction; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07591
// TypeInfo:  0x00000001427CBA50
struct FireLogicData
{
	HoldAndReleaseData m_HoldAndRelease; //0x0000
	BoltActionData m_BoltAction; //0x001C
	RecoilData m_Recoil; //0x002C
	__int32 m_FireInputAction; //0x0050
	__int32 m_ReloadInputAction; //0x0054
	__int32 m_CycleFireModeInputAction; //0x0058
	float m_TriggerPullWeight; //0x005C
	float m_RateOfFire; //0x0060
	float m_RateOfFireForBurst; //0x0064
	float m_ClientFireRateMultiplier; //0x0068
	float m_ReloadDelay; //0x006C
	float m_ReloadTime; //0x0070
	char _0x0074[4];
	Array<float> m_ReloadTimerArray; //0x0078
	float m_ReloadTimeBulletsLeft; //0x0080
	float m_ReloadThreshold; //0x0084
	float m_PreFireDelay; //0x0088
	float m_AutomaticDelay; //0x008C
	ReloadLogic m_ReloadLogic; //0x0090
	ReloadType m_ReloadType; //0x0094
	FireLogicType m_FireLogicType; //0x0098
	char _0x009C[4];
	Array<FireLogicType> m_FireLogicTypeArray; //0x00A0
	bool m_HoldOffReloadUntilFireRelease; //0x00A8
	bool m_HoldOffReloadUntilZoomRelease; //0x00A9
	bool m_ForceReloadActionOnFireTrigger; //0x00AA
	bool m_AlwaysAutoReload; //0x00AB
	char _0x00AC[4];
};//Size=0x00B0

////////////////////////////////////////
// RuntimeId: 07573
// TypeInfo:  0x00000001427CBC70
struct InitialDirectionScaleByPitchData
{
	Vec3 m_InitialDirectionScale; //0x0000
	float m_Pitch; //0x0010
	char _0x0014[12];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07575
// TypeInfo:  0x00000001427CBC50
struct InitialSpeedScaleByPitchData
{
	Vec3 m_InitialSpeedScale; //0x0000
	float m_Pitch; //0x0010
	char _0x0014[12];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07577
// TypeInfo:  0x00000001427CBAD0
struct ShotConfigData
{
	Vec3 m_InitialPosition; //0x0000
	Vec3 m_InitialDirection; //0x0010
	Vec3 m_InitialSpeed; //0x0020
	Array<InitialDirectionScaleByPitchData> m_InitialDirectionScaleByPitch; //0x0030
	Array<InitialSpeedScaleByPitchData> m_InitialSpeedScaleByPitch; //0x0038
	float m_InheritWeaponSpeedAmount; //0x0040
	char _0x0044[4];
	ExplosionEntityData* m_MuzzleExplosion; //0x0048
	ProjectileEntityData* m_ProjectileData; //0x0050
	ProjectileEntityData* m_SecondaryProjectileData; //0x0058
	ProjectileBlueprint* m_Projectile; //0x0060
	ProjectileBlueprint* m_SecondaryProjectile; //0x0068
	float m_SpawnDelay; //0x0070
	unsigned __int32 m_NumberOfBulletsPerShell; //0x0074
	unsigned __int32 m_NumberOfBulletsPerShot; //0x0078
	unsigned __int32 m_NumberOfBulletsPerBurst; //0x007C
	bool m_RelativeTargetAiming; //0x0080
	bool m_ForceSpawnToCamera; //0x0081
	bool m_SpawnVisualAtWeaponBone; //0x0082
	bool m_ActiveForceSpawnToCamera; //0x0083
	char _0x0084[12];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 07571
// TypeInfo:  0x00000001427CBC90
struct HealingSphereData
{
	float m_Radius; //0x0000
	float m_HealthIncSpeed; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07567
// TypeInfo:  0x00000001427CBAF0
struct NearTargetDetonationData
{
	float m_DetonationRadius; //0x0000
	float m_MaxDetonationDelay; //0x0004
	float m_MinDetonationDelay; //0x0008
	bool m_DetonateNearTarget; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07565
// TypeInfo:  0x00000001427CBB10
struct MissileUnguidedData
{
	Vec2 m_StaticPosition; //0x0000
	Vec2 m_TargetPositionOffset; //0x0008
	bool m_UseStaticPosition; //0x0010
	bool m_UseTargetPosition; //0x0011
	char _0x0012[2];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 07563
// TypeInfo:  0x00000001427CBB30
struct MissileLockableInfoData
{
	float m_HeatSignature; //0x0000
	float m_RadarSignature; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07559
// TypeInfo:  0x00000001427CBB50
struct LockingAndHomingData
{
	WarnTarget m_WarnLock; //0x0000
	bool m_IsHoming; //0x0004
	bool m_IsGuided; //0x0005
	bool m_IsGuidedWhenZoomed; //0x0006
	bool m_IsGuidedHoming; //0x0007
	bool m_FireOnlyWhenLockedOn; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 07557
// TypeInfo:  0x00000001427CBCB0
struct ZoomLevelLockData
{
	float m_OutlineTaggedDistance; //0x0000
	LockType m_LockType; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07541
// TypeInfo:  0x00000001427CBB70
struct AmmoConfigData
{
	__int32 m_MagazineCapacity; //0x0000
	__int32 m_NumberOfMagazines; //0x0004
	unsigned __int32 m_TraceFrequency; //0x0008
	unsigned __int32 m_AmmoPickupMinAmount; //0x000C
	unsigned __int32 m_AmmoPickupMaxAmount; //0x0010
	float m_AutoReplenishDelay; //0x0014
	float m_AmmoBagPickupDelayMultiplier; //0x0018
	__int32 m_AmmoBagPickupAmount; //0x001C
	bool m_AutoReplenishMagazine; //0x0020
	char _0x0021[3];
};//Size=0x0024

////////////////////////////////////////
// RuntimeId: 07523
// TypeInfo:  0x00000001427CBBD0
struct CannedAnimationBinding
{
	AntRef m_LevelIndex; //0x0000
	AntRef m_ScenarioIndex; //0x0014
	AntRef m_ActorIndex; //0x0028
	AntRef m_PartIndex; //0x003C
	AntRef m_TriggerCannedAnimation; //0x0050
	AntRef m_ExitCannedAnimation; //0x0064
	AntRef m_ExternalTime; //0x0078
	AntRef m_BlendValue; //0x008C
	AntRef m_AdvanceScenario; //0x00A0
	AntRef m_EnteredLoop; //0x00B4
	AntRef m_AlmostFinished; //0x00C8
};//Size=0x00DC

////////////////////////////////////////
// RuntimeId: 07521
// TypeInfo:  0x00000001427CBBF0
struct WarpAnimationBinding
{
	AntRef m_ConnectJointGroup; //0x0000
	AntRef m_ConnectJointWeight; //0x0014
	AntRef m_EnableAlign; //0x0028
	AntRef m_DisableCulling; //0x003C
	AntRef m_TranslationYWarpTolerance; //0x0050
	AntRef m_AttachToAnimatableInstanceId; //0x0064
	AntRef m_JoinAttachment; //0x0078
};//Size=0x008C

////////////////////////////////////////
// RuntimeId: 07494
// TypeInfo:  0x00000001427C5C20
struct VehicleCameraControlBinding
{
	AntRef m_EnableAnimatedVehicleCamera; //0x0000
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 07492
// TypeInfo:  0x00000001427C5C40
struct VehicleEntryListenerBinding
{
	AntRef m_InVehicle; //0x0000
	AntRef m_InOpenEntry; //0x0014
	AntRef m_VehicleEntryFire; //0x0028
	AntRef m_VehicleEntryYaw; //0x003C
	AntRef m_VehicleEntryRelativeYaw; //0x0050
	AntRef m_VehicleEntryPitch; //0x0064
	AntRef m_VehicleEntryRoll; //0x0078
	AntRef m_VehicleEntryRotation; //0x008C
	AntRef m_VehicleEntryForceX; //0x00A0
	AntRef m_VehicleEntryForceY; //0x00B4
	AntRef m_VehicleEntryForceZ; //0x00C8
	AntRef m_VehicleEntryIndex; //0x00DC
	AntRef m_VehicleEntryIndexUpdated; //0x00F0
	AntRef m_VehicleOpenEntryIndex; //0x0104
	AntRef m_InVehicleRetrigger; //0x0118
	AntRef m_VehicleEntryChooserIndex; //0x012C
};//Size=0x0140

////////////////////////////////////////
// RuntimeId: 07490
// TypeInfo:  0x00000001427C5C60
struct ClientCameraToComponentsInitMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07489
// TypeInfo:  0x00000001427C5C80
struct VehicleToComponentsStartDisabledDamagedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 07488
// TypeInfo:  0x00000001427C5CA0
struct ClientVehicleToComponentsHealthChangedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07483
// TypeInfo:  0x00000001427C5CC0
struct NormalizeSettings
{
	float m_Minimum; //0x0000
	float m_Maximum; //0x0004
	float m_Lower; //0x0008
	float m_Upper; //0x000C
	float m_Velocity; //0x0010
	bool m_Normalize; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07479
// TypeInfo:  0x00000001427C5CE0
struct VehicleLockableInfoData
{
	float m_HeatSignature; //0x0000
	float m_RadarSignature; //0x0004
	float m_LowAltitudeHeight; //0x0008
	float m_LowAltitudeHeatSignature; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07477
// TypeInfo:  0x00000001427C5D00
struct AngleOfImpactData
{
	float m_Zone12Delimiter; //0x0000
	float m_Zone23Delimiter; //0x0004
	float m_Zone1Multiplier; //0x0008
	float m_Zone2Multiplier; //0x000C
	float m_Zone3Multiplier; //0x0010
	bool m_Enabled; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07475
// TypeInfo:  0x00000001427C5D20
struct MPModeData
{
	__int32 m_VehiclePoints; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 07473
// TypeInfo:  0x00000001427C5D40
struct VehicleHealthZoneData
{
	float m_MaxHealth; //0x0000
	float m_MaxShieldHealth; //0x0004
	float m_MinDamageAngle; //0x0008
	float m_DamageAngleMultiplier; //0x000C
	Curve2D* m_DamageAngleMultiplierCurve; //0x0010
	float m_VerticalFactor; //0x0018
	bool m_UseDamageAngleCalculation; //0x001C
	char _0x001D[3];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07471
// TypeInfo:  0x00000001427C5D60
struct VehicleHudData
{
	Vec3 m_CustomizationOffset; //0x0000
	VehicleCustomizationAsset* m_Customization; //0x0010
	UIHudIcon m_MinimapIcon; //0x0018
	char _0x001C[4];
	char* m_IconName; //0x0020
	TextureAsset* m_Texture; //0x0028
	unsigned __int32 m_VehicleItemHash; //0x0030
	bool m_RotateInMap; //0x0034
	bool m_ShowHealth; //0x0035
	char _0x0036[10];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05167
// TypeInfo:  0x000000014278FA08
struct MaterialDecl
{
	unsigned __int32 m_Packed; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 07455
// TypeInfo:  0x00000001427C60C0
struct CameraRelativeControlPerSpeedData
{
	float m_SpeedThreshold; //0x0000
	float m_WorldSpaceLockEfficiency; //0x0004
	float m_WorldSpaceLockEfficiencyAway; //0x0008
	float m_ThrottleForSteeringHelp; //0x000C
	float m_ThrottleForSteeringHelpStrength; //0x0010
	float m_ThrottleHold; //0x0014
	float m_MinInputMagnitude; //0x0018
	float m_ThrottleExponent; //0x001C
	float m_TurningExponent; //0x0020
	float m_FullTurningThreshold; //0x0024
	float m_FullTurningBlending; //0x0028
	float m_ExtraForwardZoneAngle; //0x002C
	float m_AngularYawConstraint; //0x0030
	bool m_UseInForwardAndNeutralGears; //0x0034
	bool m_UseInReverseGear; //0x0035
	bool m_UseInBoost; //0x0036
	bool m_UseNotInBoost; //0x0037
	bool m_InvertExtraForwardZoneIfBackwards; //0x0038
	bool m_InvertExtraForwardZoneOnSideFacingCamera; //0x0039
	char _0x003A[2];
};//Size=0x003C

////////////////////////////////////////
// RuntimeId: 07449
// TypeInfo:  0x00000001427C5D80
struct LandingGearConditionData
{
	float m_Height; //0x0000
	float m_Velocity; //0x0004
	float m_Angle; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 07437
// TypeInfo:  0x00000001427C60E0
struct TurretRotationInfo
{
	RotationAxis m_RotationAxis; //0x0000
	RotationChannel m_Channel; //0x0004
	float m_MaxRotation; //0x0008
	float m_MinRotation; //0x000C
	float m_PhaseOffset; //0x0010
	bool m_NormalizeRotation; //0x0014
	bool m_InvertRotation; //0x0015
	char _0x0016[2];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07425
// TypeInfo:  0x00000001427C5DA0
struct RotorModelData
{
	float m_RotationRpm; //0x0000
	unsigned __int32 m_PartIndex; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07401
// TypeInfo:  0x00000001427C6100
struct UnlockIdTable
{
	Array<unsigned __int32> m_Identifiers; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07399
// TypeInfo:  0x00000001427C6120
struct BasicUnlockInfo
{
	Guid m_UnlockGuid; //0x0000
	char _0x0000[16];
	unsigned __int32 m_Identifier; //0x0010
	unsigned __int32 m_UnlockScore; //0x0014
	Array<char*> m_Licenses; //0x0018
	Array<char*> m_AdditionalLicenses; //0x0020
	char* m_StringId; //0x0028
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07387
// TypeInfo:  0x00000001427C6140
struct UnlockAssetPair
{
	UnlockAssetBase* m_Second; //0x0000
	UnlockAssetBase* m_Result; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07347
// TypeInfo:  0x00000001427C5DE0
struct UIAutoScrollTextSettings
{
	float m_NoScrollWaitTime; //0x0000
	float m_FullyScrolledWaitTime; //0x0004
	float m_MaxScrollTime; //0x0008
	float m_PixelsPerSecond; //0x000C
	float m_ScrollbackMultiplier; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 07253
// TypeInfo:  0x00000001427C5F40
struct UIElementColor
{
	Vec3 m_Rgb; //0x0000
	float m_Alpha; //0x0010
	char _0x0014[4];
	char* m_PropertyName; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07313
// TypeInfo:  0x00000001427C5E20
struct UIElementInclusionSettings
{
	Array<char*> m_CustomInclusionCritera; //0x0000
	bool m_IsSingleplayerLayer; //0x0008
	bool m_IsMultiplayerLayer; //0x0009
	bool m_IsWin32Layer; //0x000A
	bool m_IsXenonLayer; //0x000B
	bool m_IsPs3Layer; //0x000C
	bool m_IsGen4aLayer; //0x000D
	bool m_IsGen4bLayer; //0x000E
	bool m_IsSDLayer; //0x000F
	bool m_IsHDLayer; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07311
// TypeInfo:  0x00000001427C6160
struct UIElementEditorSettings
{
	float m_Opacity; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 07291
// TypeInfo:  0x00000001427C5E40
struct UIElementGradient
{
	UIElementColor m_TopLeftColor; //0x0000
	UIElementColor m_TopRightColor; //0x0020
	UIElementColor m_BottomLeftColor; //0x0040
	UIElementColor m_BottomRightColor; //0x0060
};//Size=0x0080

////////////////////////////////////////
// RuntimeId: 07249
// TypeInfo:  0x00000001427C5F80
struct UIDataSource
{
	UIComponentData* m_DataCategory; //0x0000
	__int32 m_DataKey; //0x0008
	char _0x000C[4];
	char* m_SchematicsProperty; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07287
// TypeInfo:  0x00000001427C5E80
struct UIElementTransform
{
	Vec3 m_Rotation; //0x0000
	Vec3 m_RotationPivot; //0x0010
	float m_Z; //0x0020
	char _0x0024[4];
	char* m_PropertyName; //0x0028
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07285
// TypeInfo:  0x00000001427C5EA0
struct UIElementAnchor
{
	float m_X; //0x0000
	float m_Y; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07283
// TypeInfo:  0x00000001427C5EC0
struct UIElementSize
{
	float m_X; //0x0000
	float m_Y; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07281
// TypeInfo:  0x00000001427C5EE0
struct UIElementOffset
{
	float m_X; //0x0000
	float m_Y; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07279
// TypeInfo:  0x00000001427C5F00
struct UIElementRectExpansion
{
	float m_X; //0x0000
	float m_Y; //0x0004
	float m_Width; //0x0008
	float m_Height; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07277
// TypeInfo:  0x00000001427C6180
struct UIElementRect
{
	float m_X; //0x0000
	float m_Y; //0x0004
	float m_Width; //0x0008
	float m_Height; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07273
// TypeInfo:  0x00000001427C61A0
struct UIElementTextEntry
{
	UITextEntryType m_TextType; //0x0000
	char _0x0004[4];
	char* m_Text; //0x0008
	char* m_FloatFormat; //0x0010
	UIDataSource m_DataSource; //0x0018
	bool m_UseLocalization; //0x0030
	char _0x0031[7];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 07257
// TypeInfo:  0x00000001427C5F20
struct UIElementFont
{
	char* m_ScaleformFontName; //0x0000
	float m_FontSize; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07255
// TypeInfo:  0x00000001427C61C0
struct UIElementLineStyle
{
	UIElementColor m_Color; //0x0000
	float m_Width; //0x0020
	char _0x0024[12];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07333
// TypeInfo:  0x00000001427C5E00
struct UIElementBitmapDistanceFieldParams
{
	UIElementColor m_OutlineColor; //0x0000
	float m_AlphaThreshold; //0x0020
	float m_DistanceScale; //0x0024
	float m_OutlineInner; //0x0028
	float m_OutlineOuter; //0x002C
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07251
// TypeInfo:  0x00000001427C5F60
struct UICompareDataSource
{
	UIComponentData* m_DataCategory; //0x0000
	__int32 m_DataKey; //0x0008
	char _0x000C[4];
	char* m_SchematicsProperty; //0x0010
	char* m_CompareValue; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07289
// TypeInfo:  0x00000001427C5E60
struct UIElementText
{
	char* m_Sid; //0x0000
	Array<UIElementTextEntry> m_Entries; //0x0008
	UIElementAlignment m_VerticalAlignment; //0x0010
	UIElementAlignment m_HorizonalAlignment; //0x0014
	bool m_Multiline; //0x0018
	bool m_Wordwrap; //0x0019
	char _0x001A[6];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07241
// TypeInfo:  0x00000001427C61E0
struct UITextureMapping
{
	char* m_Id; //0x0000
	TextureAsset* m_Texture; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07239
// TypeInfo:  0x00000001427C6200
struct UITextureMappingOutputEntry
{
	char* m_Id; //0x0000
	TextureAsset* m_Texture; //0x0008
	Vec2 m_Min; //0x0010
	Vec2 m_Max; //0x0018
	bool m_Streaming; //0x0020
	char _0x0021[7];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 07235
// TypeInfo:  0x00000001427C5FA0
struct UIFlowDialogNodeReachedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 07234
// TypeInfo:  0x00000001427C5FC0
struct UIDialogScreenPushedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 07177
// TypeInfo:  0x00000001427C6220
struct InputRecorderTrackData
{
	char* m_Name; //0x0000
	__int32 m_InputAction; //0x0008
	char _0x000C[4];
	FloatPropertyTrackData* m_PropertyTrack; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 07167
// TypeInfo:  0x00000001427C6000
struct SimpleMovementActionTimeData
{
	float m_Time; //0x0000
	float m_MaxVariation; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07107
// TypeInfo:  0x00000001427C6040
struct IndexRange
{
	unsigned __int32 m_First; //0x0000
	unsigned __int32 m_Last; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07109
// TypeInfo:  0x00000001427C6240
struct ChildStaticModelNetworkInfo
{
	IndexRange m_NetworkRange; //0x0000
	unsigned __int32 m_ParentPartComponentIndex; //0x0008
	unsigned __int32 m_ParentHealthStateIndex; //0x000C
	unsigned __int32 m_InstanceIndex; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 07111
// TypeInfo:  0x00000001427C6020
struct StaticModelNetworkInfo
{
	Array<IndexRange> m_PartNetworkIdRanges; //0x0000
	unsigned __int32 m_NetworkIdCount; //0x0008
	char _0x000C[4];
	Array<ChildStaticModelNetworkInfo> m_ChildNetworkInfos; //0x0010
	unsigned __int32 m_ChildNetworkIdCount; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 07105
// TypeInfo:  0x00000001427C6260
struct PhysicsPartInfo
{
	unsigned __int32 m_PartComponentIndex; //0x0000
	unsigned __int32 m_HealthStateIndex; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07099
// TypeInfo:  0x00000001427C6060
struct CharacterToComponentsSpawnTemplateMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 07070
// TypeInfo:  0x00000001427BDB50
struct PID
{
	float m_P; //0x0000
	float m_I; //0x0004
	float m_D; //0x0008
	float m_MaxError; //0x000C
	float m_MaxPTerm; //0x0010
	float m_MaxITerm; //0x0014
	float m_MaxSumError; //0x0018
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 07048
// TypeInfo:  0x00000001427BDED0
struct CustomizeVisual
{
	Array<UnlockAsset*> m_Visual; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07046
// TypeInfo:  0x00000001427BDBF0
struct NetworkPlayerSelectedUnlockAssetsMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 07045
// TypeInfo:  0x00000001427BDEF0
struct CamoUnlockSelection
{
	__int32 m_Category; //0x0000
	char _0x0004[4];
	UnlockAssetBase* m_Asset; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07025
// TypeInfo:  0x00000001427BDF10
struct CustomizedMeshMaterialsData
{
	ObjectBlueprint* m_MeshBlueprint; //0x0000
	Array<char*> m_MaterialNames; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06977
// TypeInfo:  0x00000001427BDC70
struct EntityToComponentsResetMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06974
// TypeInfo:  0x00000001427BDC90
struct UnlockComponentEnabledMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06969
// TypeInfo:  0x00000001427BDF30
struct SoldierAnimatedCameraData
{
	float m_CameraTransitionTime; //0x0000
	bool m_EnableFeature; //0x0004
	char _0x0005[3];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06959
// TypeInfo:  0x00000001427BDF50
struct ShaderParameterVector
{
	Vec4 m_Value; //0x0000
	char* m_ParameterName; //0x0010
	char _0x0018[8];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 06957
// TypeInfo:  0x00000001427BDF70
struct CameraBinding
{
	AntRef m_Render1pInBackground; //0x0000
	AntRef m_ForceRender1pInForeground; //0x0014
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06917
// TypeInfo:  0x00000001427BE010
struct ActionSuppressor
{
	__int32 m_ActionToSuppress; //0x0000
	float m_SuppressingValue; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06953
// TypeInfo:  0x00000001427BDCD0
struct InputSuppressionData
{
	Array<ActionSuppressor> m_SuppressVehicleInput; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06941
// TypeInfo:  0x00000001427BDFB0
struct BuoyantPartsData
{
	BuoyantParts m_PartName; //0x0000
	float m_Buoyancy; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06925
// TypeInfo:  0x00000001427BDD50
struct PitchModifier
{
	Vec3 m_Offset; //0x0000
	float m_PitchVal; //0x0010
	float m_PitchAngle; //0x0014
	char _0x0018[8];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 06929
// TypeInfo:  0x00000001427BDD30
struct AimAssistCollisionBonePrioritiesData
{
	__int32 m_StartPriority; //0x0000
	__int32 m_MidPriority; //0x0004
	__int32 m_EndPriority; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 06931
// TypeInfo:  0x00000001427BDD10
struct AimAssistCollisionBoneSnapAimData
{
	float m_Bounding_LengthScale; //0x0000
	float m_Bounding_RadiusScale; //0x0004
	float m_Point_LengthScale; //0x0008
	AimAssistCollisionBonePrioritiesData m_Point_Priorities; //0x000C
	AimAssistCollisionBonePrioritiesData m_Point_Priorities_BoneUnderReticle; //0x0018
};//Size=0x0024

////////////////////////////////////////
// RuntimeId: 06935
// TypeInfo:  0x00000001427BDFD0
struct BoneCollisionData
{
	Vec4 m_DebugDrawColor; //0x0000
	Vec3 m_CapsuleOffset; //0x0010
	PitchModifier m_MaxPitch; //0x0020
	PitchModifier m_MinPitch; //0x0040
	char* m_BoneName; //0x0060
	HitReactionType m_AnimationHitReactionType; //0x0068
	MaterialDecl m_MaterialPair; //0x006C
	__int32 m_BoneAxis; //0x0070
	float m_CapsuleLength; //0x0074
	float m_CapsuleRadius; //0x0078
	char _0x007C[4];
	AimAssistCollisionBoneData* m_AimAssistTarget; //0x0080
	bool m_ValidInHiLod; //0x0088
	bool m_ValidInLowLod; //0x0089
	bool m_DeactivateIfBehindWall; //0x008A
	bool m_UsePhysicsRotation; //0x008B
	char _0x008C[4];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 06923
// TypeInfo:  0x00000001427BDFF0
struct HIKData
{
	float m_ReachT; //0x0000
	float m_ReachR; //0x0004
	float m_Pull; //0x0008
	float m_Resist; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06921
// TypeInfo:  0x00000001427BDD70
struct RagdollBinding
{
	AntRef m_RagdollOnBack; //0x0000
	AntRef m_RagdollBlend; //0x0014
	AntRef m_RagdollBlendEarly; //0x0028
	AntRef m_RagdollForceBlendDisabled; //0x003C
	AntRef m_RagdollActiveTime; //0x0050
	AntRef m_RagdollFullyBlendedIn; //0x0064
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 06955
// TypeInfo:  0x00000001427BDF90
struct RegularCameraViewData
{
	Vec3 m_MeshOffset; //0x0000
	InputSuppressionData m_InputSuppression; //0x0010
	float m_FieldOfView; //0x0018
	char _0x001C[4];
	RigidMeshAsset* m_Mesh; //0x0020
	ObjectBlueprint* m_MaskMeshBlueprint; //0x0028
	float m_ScreenExposureAreaScale; //0x0030
	bool m_FLIREnabled; //0x0034
	bool m_AllowFieldOfViewScaling; //0x0035
	bool m_LockMeshToRenderView; //0x0036
	char _0x0037[9];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06915
// TypeInfo:  0x00000001427BE030
struct StanceCameraData
{
	Array<__int32> m_ValidStances; //0x0000
	Array<__int32> m_DefaultCameraForStances; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06907
// TypeInfo:  0x00000001427BDD90
struct EntryComponentStanceChangedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06902
// TypeInfo:  0x00000001427BE050
struct StanceSwitchSoundData
{
	SoundAsset* m_StanceSwitchSound; //0x0000
	Array<__int32> m_ValidStances; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06898
// TypeInfo:  0x00000001427BDDB0
struct EntryComponentHudData
{
	__int32 m_Index; //0x0000
	EntrySeatType m_SeatType; //0x0004
	bool m_Frustum; //0x0008
	bool m_Visible; //0x0009
	bool m_MaximizeMiniMapOnEntry; //0x000A
	char _0x000B[1];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 06872
// TypeInfo:  0x00000001427BDDF0
struct CharacterToComponentsOnKilledMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06865
// TypeInfo:  0x00000001427BDE10
struct CharacterToComponentsOnTeleportedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06832
// TypeInfo:  0x00000001427BE070
struct CameraLeapData
{
	LinearTransform m_Transform; //0x0000
	float m_Time; //0x0040
	float m_FovModifier; //0x0044
	char _0x0048[8];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 06820
// TypeInfo:  0x00000001427BE090
struct HudImpactData
{
	float m_MinHealth; //0x0000
	float m_MaxHealth; //0x0004
	float m_MinTimeVisible; //0x0008
	float m_MaxTimeVisible; //0x000C
	bool m_Enable; //0x0010
	char _0x0011[3];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 06816
// TypeInfo:  0x00000001427BDE30
struct BlurEffectData
{
	float m_DispersionStrength; //0x0000
	float m_DispersionThreshhold; //0x0004
	float m_ExplosionStrength; //0x0008
	float m_BulletStrength; //0x000C
	float m_ExplosionFalloffSpeed; //0x0010
	float m_BulletFalloffSpeed; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 06814
// TypeInfo:  0x00000001427BDE50
struct TurnEffectData
{
	float m_MaxRollAngle; //0x0000
	float m_MaxPitchAngle; //0x0004
	float m_YawVelocityThreshhold; //0x0008
	float m_VelocityThreshhold; //0x000C
	float m_SafeTime; //0x0010
	float m_BeginTime; //0x0014
	float m_HoldTime; //0x0018
	float m_EndTime; //0x001C
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 06812
// TypeInfo:  0x00000001427BE0B0
struct CameraSineCurveData
{
	float m_Frequency; //0x0000
	float m_Amplitude; //0x0004
	float m_PhaseShift; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 04833
// TypeInfo:  0x000000014278B768
struct BundleHeapInfo
{
	BundleHeapType m_HeapType; //0x0000
	unsigned __int32 m_InitialSize; //0x0004
	bool m_AllowGrow; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 06790
// TypeInfo:  0x00000001427BDE90
struct BlueprintBundleSettings
{
	BundleHeapInfo m_Heap; //0x0000
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 04873
// TypeInfo:  0x000000014278B5C8
struct EventSpec
{
	__int32 m_Id; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 06738
// TypeInfo:  0x00000001427B7E50
struct SubLevelPreloadInfo
{
	char* m_SubLevelBundlePath; //0x0000
	Array<char*> m_PreloadedBlueprintBundles; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06740
// TypeInfo:  0x00000001427B7C30
struct LevelPreloadInfo
{
	Array<char*> m_PreloadedBlueprintBundles; //0x0000
	Array<SubLevelPreloadInfo> m_SubLevelPreloadInfoMap; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06728
// TypeInfo:  0x00000001427B7E70
struct PathfindingBlob
{
	Guid m_BlobId; //0x0000
	char _0x0000[16];
	unsigned __int32 m_BlobSize; //0x0010
	char _0x0014[4];
	Array<unsigned __int32> m_ChunkSizes; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 06722
// TypeInfo:  0x00000001427B7E90
struct FaceAnimationWaveMapping
{
	__int32 m_WaveNameHash; //0x0000
	__int32 m_AntEnumValue; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06712
// TypeInfo:  0x00000001427B7EB0
struct LevelStartPoint
{
	char* m_Name; //0x0000
	Array<char*> m_AutoloadSublevels; //0x0008
	bool m_IsDefault; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 06710
// TypeInfo:  0x00000001427B7ED0
struct LevelBundleLoad
{
	char* m_Name; //0x0000
	bool m_TryKeepBetweenLevels; //0x0008
	char _0x0009[7];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06708
// TypeInfo:  0x00000001427B7EF0
struct LevelDescriptionInclusionCategory
{
	char* m_Category; //0x0000
	Array<char*> m_Mode; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06704
// TypeInfo:  0x00000001427B7C50
struct LevelDescription
{
	char* m_Name; //0x0000
	char* m_Description; //0x0008
	Array<LevelDescriptionComponent*> m_Components; //0x0010
	bool m_IsMultiplayer; //0x0018
	bool m_IsCoop; //0x0019
	bool m_IsMenu; //0x001A
	bool m_IsEpilogue; //0x001B
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 06700
// TypeInfo:  0x00000001427B7C70
struct InputMessagesSingleInputEventMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06657
// TypeInfo:  0x00000001427B7C90
struct EditableActions
{
	Array<EditableAction*> m_Actions; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06659
// TypeInfo:  0x00000001427B7F10
struct EditableActionMap
{
	char* m_Id; //0x0000
	char* m_NameId; //0x0008
	EntryInputActionMapsData* m_ActionMap; //0x0010
	EditableActions m_ConfigurationLayout; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 06643
// TypeInfo:  0x00000001427B7F30
struct EntryInputActionBinding
{
	__int32 m_Action; //0x0000
	__int32 m_Alias; //0x0004
	EntryInputActionType m_ActionType; //0x0008
	bool m_Networked; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06619
// TypeInfo:  0x00000001427B7F50
struct HudData
{
	float m_CrosshairScaleMin; //0x0000
	float m_CrosshairScaleMax; //0x0004
	float m_CrosshairOpacityMin; //0x0008
	float m_CrosshairOpacityMax; //0x000C
	float m_CrosshairOpacityModifier; //0x0010
	char _0x0014[4];
	char* m_CrosshairTypeId; //0x0018
	CrosshairTypeAsset* m_CrosshairType; //0x0020
	LockingTypeAsset* m_LockingType; //0x0028
	char* m_WeaponClass; //0x0030
	float m_LowAmmoWarning; //0x0038
	float m_ReloadPrompt; //0x003C
	__int32 m_RenderTargetIndex; //0x0040
	char _0x0044[4];
	UIPartPropertyList* m_HudPropertyList; //0x0048
	float m_SeaLevelAltFreq; //0x0050
	float m_CameraShakeModifier; //0x0054
	char* m_HudIcon; //0x0058
	bool m_ShowMinimap; //0x0060
	bool m_HideAmmo; //0x0061
	bool m_InfiniteAmmo; //0x0062
	bool m_HideCrosshairWhenAimOnFriend; //0x0063
	bool m_UseRenderTarget; //0x0064
	bool m_UseRangeMeter; //0x0065
	bool m_UseAimWarning; //0x0066
	bool m_UsePredictedSight; //0x0067
	bool m_UseWeaponOrientations; //0x0068
	bool m_UseVelocityVectorMarker; //0x0069
	bool m_UseLockingController; //0x006A
	bool m_UseThrust; //0x006B
	bool m_UseGForce; //0x006C
	bool m_UseSkidSlip; //0x006D
	bool m_UseClimbRate; //0x006E
	char _0x006F[1];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 06611
// TypeInfo:  0x00000001427B7F70
struct UIPartProperties
{
	UIPartIdentifier m_Identifier; //0x0000
	float m_Range; //0x0004
	float m_Frequency; //0x0008
	bool m_CompensateFreelook; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06597
// TypeInfo:  0x00000001427B7F90
struct StaticModelGroupMemberData
{
	Array<LinearTransform> m_InstanceTransforms; //0x0000
	Array<unsigned __int32> m_InstanceObjectVariation; //0x0008
	Array<bool> m_InstanceCastSunShadow; //0x0010
	Array<bool> m_InstanceCastReflection; //0x0018
	Array<RadiosityTypeOverride> m_InstanceRadiosityTypeOverride; //0x0020
	Array<bool> m_InstanceTerrainShaderNodesEnable; //0x0028
	GamePhysicsEntityData* m_MemberType; //0x0030
	MeshAsset* m_MeshAsset; //0x0038
	unsigned __int32 m_InstanceCount; //0x0040
	unsigned __int32 m_HealthStateEntityManagerId; //0x0044
	IndexRange m_PhysicsPartRange; //0x0048
	unsigned __int32 m_PhysicsPartCountPerInstance; //0x0050
	IndexRange m_NetworkIdRange; //0x0054
	unsigned __int32 m_NetworkIdCountPerInstance; //0x005C
	unsigned __int32 m_PartComponentCount; //0x0060
	char _0x0064[4];
};//Size=0x0068

////////////////////////////////////////
// RuntimeId: 06555
// TypeInfo:  0x00000001427B7D50
struct ServerControllableToComponentsPlayerExitMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06554
// TypeInfo:  0x00000001427B7D70
struct ServerControllableToComponentsPlayerEnteredMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06553
// TypeInfo:  0x00000001427B7D90
struct ClientControllableToComponentsPlayerExitMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06552
// TypeInfo:  0x00000001427B7DB0
struct ClientControllableToComponentsPlayerEnteredMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06543
// TypeInfo:  0x00000001427B7FB0
struct VoiceOverConversationEntityTrackInfo
{
	unsigned __int32 m_TakeControlId; //0x0000
	unsigned __int32 m_SourceId; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06533
// TypeInfo:  0x00000001427B7DD0
struct FbProxyControllerEntityBinding
{
	AntRef m_Trigger; //0x0000
	AntRef m_Stop; //0x0014
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06527
// TypeInfo:  0x00000001427B7E10
struct EventSyncReachedClientMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 06522
// TypeInfo:  0x00000001427B7FD0
struct EntitlementData
{
	char* m_License; //0x0000
	char* m_EntitlementTag; //0x0008
	char* m_GroupName; //0x0010
	char* m_ProductId; //0x0018
	char* m_ProjectId; //0x0020
	EntitlementType m_UsageType; //0x0028
	bool m_VerifyOwnership; //0x002C
	char _0x002D[3];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06520
// TypeInfo:  0x00000001427B7FF0
struct PlatformProjectId
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	char* m_ProjectId; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06518
// TypeInfo:  0x00000001427B8010
struct EntitlementPlatformType
{
	GamePlatform m_Platform; //0x0000
	EntitlementType m_EntitlementType; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06498
// TypeInfo:  0x00000001427B7E30
struct AntDynamicAvoidanceBinding
{
	AntRef m_TimeUntilCollision; //0x0000
	AntRef m_DistanceUntilCollision; //0x0014
	AntRef m_NormalizedVelocity; //0x0028
	AntRef m_Speed; //0x003C
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 06458
// TypeInfo:  0x00000001427B2100
struct ProfileOptionDataEnumItem
{
	char* m_DisplayName; //0x0000
	bool m_Default; //0x0008
	char _0x0009[7];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06448
// TypeInfo:  0x00000001427B2120
struct BinaryOption
{
	char* m_Name; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06446
// TypeInfo:  0x00000001427B2140
struct StringOption
{
	char* m_Name; //0x0000
	char* m_Value; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06444
// TypeInfo:  0x00000001427B2160
struct IntOption
{
	char* m_Name; //0x0000
	__int32 m_Value; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06442
// TypeInfo:  0x00000001427B2180
struct FloatOption
{
	char* m_Name; //0x0000
	float m_Value; //0x0008
	float m_Min; //0x000C
	float m_Max; //0x0010
	float m_Step; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 06434
// TypeInfo:  0x00000001427B2000
struct ProceduralAwarenessComponentBinding
{
	AntRef m_StrengthScale; //0x0000
	AntRef m_UseTargetOverride; //0x0014
	AntRef m_TargetOverride; //0x0028
	AntRef m_NewTargetChosen; //0x003C
	AntRef m_DoRandomBlendOut; //0x0050
};//Size=0x0064

////////////////////////////////////////
// RuntimeId: 06422
// TypeInfo:  0x00000001427B2020
struct PhysicsDrivenAnimationEntityBinding
{
	AntRef m_PhysicsMotionTarget; //0x0000
	AntRef m_AimLeftRight; //0x0014
	AntRef m_AimUpDown; //0x0028
	AntRef m_Crouch; //0x003C
	AntRef m_ForceSetTrajectory; //0x0050
	AntRef m_InAir; //0x0064
	AntRef m_Skydive; //0x0078
	AntRef m_Parachute; //0x008C
	AntRef m_Swim; //0x00A0
	AntRef m_InputBackward; //0x00B4
	AntRef m_InputForward; //0x00C8
	AntRef m_InputLeft; //0x00DC
	AntRef m_InputRight; //0x00F0
	AntRef m_IsEnemy; //0x0104
	AntRef m_Jump; //0x0118
	AntRef m_LeanLeftRight; //0x012C
	AntRef m_Prone; //0x0140
	AntRef m_Sprint; //0x0154
	AntRef m_GroundSupported; //0x0168
	AntRef m_GroundNormal; //0x017C
	AntRef m_GroundDistance; //0x0190
	AntRef m_GroundAngleZ; //0x01A4
	AntRef m_GroundAngleX; //0x01B8
	AntRef m_GroundAngleFromNormal; //0x01CC
	AntRef m_IsClientAnimatable; //0x01E0
	AntRef m_CustomizationScreen; //0x01F4
	AntRef m_Minimal3pServer; //0x0208
	AntRef m_VerticalImpact; //0x021C
	AntRef m_VerticalImpactSpeed; //0x0230
	AntRef m_FalseSignal; //0x0244
	AntRef m_LockArmsToCameraWeight; //0x0258
	AntRef m_WindDirection; //0x026C
	AntRef m_WindStrength; //0x0280
	AntRef m_WaterDepth; //0x0294
	AntRef m_EyeWaterDepth; //0x02A8
};//Size=0x02BC

////////////////////////////////////////
// RuntimeId: 06406
// TypeInfo:  0x00000001427B21A0
struct RichPresenceProperty
{
	char* m_Name; //0x0000
	RichPresencePropertyType m_PropertyType; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06402
// TypeInfo:  0x00000001427B21C0
struct RichPresenceContextSetting
{
	RichPresenceContext* m_Context; //0x0000
	RichPresenceContextValue* m_Value; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06390
// TypeInfo:  0x00000001427B21E0
struct PersistenceConsumableMapping
{
	ConsumableGroup m_Group; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 06376
// TypeInfo:  0x00000001427B2080
struct PersistentValueTemplateData
{
	char* m_Name; //0x0000
	char* m_DefaultValue; //0x0008
	float m_DefaultFloatValue; //0x0010
	PersistentValueType m_ValueType; //0x0014
	PersistentValueDataType m_DataType; //0x0018
	PersistentValueHistoryType m_HistoryType; //0x001C
	bool m_ClubStat; //0x0020
	char _0x0021[7];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06320
// TypeInfo:  0x00000001427B2200
struct EffectWithSpeedRange
{
	EffectBlueprint* m_Effect; //0x0000
	float m_MinSpeed; //0x0008
	float m_MaxSpeed; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 06087
// TypeInfo:  0x00000001427A85F8
struct ServerProjectileOnSpawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06086
// TypeInfo:  0x00000001427A8618
struct ServerAdministrationRestartRequiredMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06085
// TypeInfo:  0x00000001427A8638
struct AIDirectorStateMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06084
// TypeInfo:  0x00000001427A8658
struct AISpawnBotMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06083
// TypeInfo:  0x00000001427A8678
struct AIPlayerEnableAsTargetMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06082
// TypeInfo:  0x00000001427A8698
struct ServerPeerLoadLevelMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06081
// TypeInfo:  0x00000001427A86B8
struct ServerPeerInitializedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06080
// TypeInfo:  0x00000001427A86D8
struct ServerMissionObjectiveCompletedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06079
// TypeInfo:  0x00000001427A86F8
struct ServerSubLevelOnStreamedInMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06078
// TypeInfo:  0x00000001427A8718
struct ServerLevelCompletedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06077
// TypeInfo:  0x00000001427A8738
struct ServerLevelStartedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06076
// TypeInfo:  0x00000001427A8758
struct ServerLevelSpawnEntitiesEndMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06075
// TypeInfo:  0x00000001427A8778
struct ServerLevelSpawnEntitiesBeginMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06074
// TypeInfo:  0x00000001427A8798
struct ServerRoundInterruptedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06073
// TypeInfo:  0x00000001427A87B8
struct ServerRoundOverMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06072
// TypeInfo:  0x00000001427A87D8
struct ServerRoundResetMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06071
// TypeInfo:  0x00000001427A87F8
struct ServerGameplayCheckpointActivatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06070
// TypeInfo:  0x00000001427A8818
struct ServerGameplayCheckpointTriggeredMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06069
// TypeInfo:  0x00000001427A8838
struct ServerGameModeResetMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06068
// TypeInfo:  0x00000001427A8858
struct ServerGameplaySetPostRoundLogicMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06067
// TypeInfo:  0x00000001427A8878
struct ServerGameplaySetPreRoundLogicMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06066
// TypeInfo:  0x00000001427A8898
struct ServerGameplayGameModeResetMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 06065
// TypeInfo:  0x00000001427A88B8
struct ServerGameplayServerPlayerMenuCancelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06064
// TypeInfo:  0x00000001427A88D8
struct ServerGameplayServerPlayerMenuOkMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06063
// TypeInfo:  0x00000001427A88F8
struct ServerGameplayPreviousWeatherStateMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06062
// TypeInfo:  0x00000001427A8918
struct ServerGameplayFightHarderMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06061
// TypeInfo:  0x00000001427A8938
struct ServerGameplayDeserterReturnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06060
// TypeInfo:  0x00000001427A8958
struct ServerGameplayDeserterMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06059
// TypeInfo:  0x00000001427A8978
struct ServerGameplayPlayerMenuCancelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06058
// TypeInfo:  0x00000001427A8998
struct ServerGameplayPlayerMenuOkMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06057
// TypeInfo:  0x00000001427A89B8
struct ServerGameplayVoiceOverFinishedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06056
// TypeInfo:  0x00000001427A89D8
struct ServerStaticModelDamagedPartByPlayerMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 06055
// TypeInfo:  0x00000001427A89F8
struct ServerStaticModelDestroyedPartMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 06054
// TypeInfo:  0x00000001427A8A18
struct ServerStaticModelGroupDestroyedPartMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 06053
// TypeInfo:  0x00000001427A8A38
struct ServerStaticModelDestroyedAllCollapsablePartsMessage
{
	char _0x0000[160];
};//Size=0x00A0

////////////////////////////////////////
// RuntimeId: 06052
// TypeInfo:  0x00000001427A8A58
struct ServerStaticModelSpawnMessage
{
	char _0x0000[144];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 06051
// TypeInfo:  0x00000001427A8A78
struct ServerSoundVoiceOverFinishedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06050
// TypeInfo:  0x00000001427A8A98
struct ServerInputDeactivateInputRestrictionMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06049
// TypeInfo:  0x00000001427A8AB8
struct ServerInputReactivateInputRestrictionMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06048
// TypeInfo:  0x00000001427A8AD8
struct ServerCollisionExplosionPackDestroyedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06047
// TypeInfo:  0x00000001427A8AF8
struct ServerCollisionExplosionPackPlacedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06046
// TypeInfo:  0x00000001427A8B18
struct ServerCollisionExplosionUnSpawnMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06045
// TypeInfo:  0x00000001427A8B38
struct ServerCollisionExplosionDamageMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 06044
// TypeInfo:  0x00000001427A8B58
struct ServerCollisionExplosionSpawnMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 06043
// TypeInfo:  0x00000001427A8B78
struct ServerCollisionProjectileTimeoutMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 06042
// TypeInfo:  0x00000001427A8B98
struct ServerCollisionProjectileImpactMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 06041
// TypeInfo:  0x00000001427A8BB8
struct ServerCollisionProjectileFireMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06040
// TypeInfo:  0x00000001427A8BD8
struct ServerCollisionGrenadeCollisionMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 06039
// TypeInfo:  0x00000001427A8BF8
struct ServerCollisionGrenadeThrowMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 06038
// TypeInfo:  0x00000001427A8C18
struct ServerComponentEntryComponentProcessedInputMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06037
// TypeInfo:  0x00000001427A8C38
struct ServerComponentEntryOnPlayerExitsMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06036
// TypeInfo:  0x00000001427A8C58
struct ServerComponentEntryOnPlayerEntersMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06035
// TypeInfo:  0x00000001427A8C78
struct ServerComponentEntryOnUnspawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06034
// TypeInfo:  0x00000001427A8C98
struct ServerComponentWeaponOnUnspawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06033
// TypeInfo:  0x00000001427A8CB8
struct ServerComponentWeaponOnSpawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06032
// TypeInfo:  0x00000001427A8CD8
struct ServerEntityPickupOnUnspawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06031
// TypeInfo:  0x00000001427A8CF8
struct ServerEntityPickupOnSpawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06030
// TypeInfo:  0x00000001427A8D18
struct ServerEntityBangerEntityOnUnspawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06029
// TypeInfo:  0x00000001427A8D38
struct ServerEntityBangerEntityOnSpawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06028
// TypeInfo:  0x00000001427A8D58
struct ServerClubMemberDeletedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06027
// TypeInfo:  0x00000001427A8D78
struct ServerClubMemberCreatedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06026
// TypeInfo:  0x00000001427A8D98
struct ServerControllableUnspawnDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06025
// TypeInfo:  0x00000001427A8DB8
struct ServerControllableSpawnDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06024
// TypeInfo:  0x00000001427A8DD8
struct ServerConnectionExitMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06023
// TypeInfo:  0x00000001427A8DF8
struct ServerConnectionInitMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06022
// TypeInfo:  0x00000001427A8E18
struct ServerWeaponReplacedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06021
// TypeInfo:  0x00000001427A8E38
struct ServerWeaponWeaponComponentActivateMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06020
// TypeInfo:  0x00000001427A8E58
struct ServerWeaponWeaponComponentReloadMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06019
// TypeInfo:  0x00000001427A8E78
struct ServerWeaponPlayerResupplyMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06018
// TypeInfo:  0x00000001427A8E98
struct ServerWeaponPlayerReloadMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 06017
// TypeInfo:  0x00000001427A8EB8
struct ServerWeaponPlayerWeaponRemovedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06016
// TypeInfo:  0x00000001427A8ED8
struct ServerWeaponPlayerWeaponReloadEndMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06015
// TypeInfo:  0x00000001427A8EF8
struct ServerWeaponPlayerPrimaryFireShotSpawnedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06014
// TypeInfo:  0x00000001427A8F18
struct ServerWeaponPlayerPrimaryOutOfAmmoMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06013
// TypeInfo:  0x00000001427A8F38
struct ServerWeaponArtilleryFiredMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06012
// TypeInfo:  0x00000001427A8F58
struct ServerWeaponLaserDesignatorMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06011
// TypeInfo:  0x00000001427A8F78
struct ServerWeaponMortarStrikeMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06010
// TypeInfo:  0x00000001427A8F98
struct ServerVehicleLockableMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 06009
// TypeInfo:  0x00000001427A8FB8
struct ServerVehicleExitMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06008
// TypeInfo:  0x00000001427A8FD8
struct ServerVehicleEnterMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06007
// TypeInfo:  0x00000001427A8FF8
struct ServerVehicleDisabledMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06006
// TypeInfo:  0x00000001427A9018
struct ServerVehicleDamageMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 06005
// TypeInfo:  0x00000001427A9038
struct ServerVehicleEnterRestrictionMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 06004
// TypeInfo:  0x00000001427A9058
struct ServerVehicleUnspawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06003
// TypeInfo:  0x00000001427A9078
struct ServerVehicleSpawnDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06002
// TypeInfo:  0x00000001427A9098
struct ServerVehicleForceArmamentReturnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06001
// TypeInfo:  0x00000001427A90B8
struct ServerVehicleSwitchTeamMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 06000
// TypeInfo:  0x00000001427A90D8
struct ServerVehicleDestroyedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05999
// TypeInfo:  0x00000001427A90F8
struct ServerPlayerDisconnectMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05998
// TypeInfo:  0x00000001427A9118
struct ServerPlayerStartedFireMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05997
// TypeInfo:  0x00000001427A9138
struct ServerPlayerInteractionEntityInRangeChangedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05996
// TypeInfo:  0x00000001427A9158
struct ServerPlayerOnPickupMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05993
// TypeInfo:  0x00000001427A9198
struct ServerPlayerChatMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05992
// TypeInfo:  0x00000001427A91B8
struct ServerPlayerTickMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05991
// TypeInfo:  0x00000001427A91D8
struct ServerPlayerExitEntryMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05990
// TypeInfo:  0x00000001427A91F8
struct ServerPlayerEnterEntryMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05989
// TypeInfo:  0x00000001427A9218
struct ServerPlayerAboutToClearCharacterMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05988
// TypeInfo:  0x00000001427A9238
struct ServerPlayerInstantSuicideMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05987
// TypeInfo:  0x00000001427A9258
struct ServerPlayerKilledMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 05986
// TypeInfo:  0x00000001427A9278
struct ServerPlayerManuallySelectedSpawnPointMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05985
// TypeInfo:  0x00000001427A9298
struct ServerPlayerChangeChatChannelMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05984
// TypeInfo:  0x00000001427A92B8
struct ServerPlayerSwitchTeamMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05983
// TypeInfo:  0x00000001427A92D8
struct ServerPlayerKitPickedupMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05982
// TypeInfo:  0x00000001427A92F8
struct ServerPlayerKitReplacedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05981
// TypeInfo:  0x00000001427A9318
struct ServerPlayerChangedCharacterMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05980
// TypeInfo:  0x00000001427A9338
struct ServerPlayerReviveRefusedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05979
// TypeInfo:  0x00000001427A9358
struct ServerPlayerReviveAcceptedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05978
// TypeInfo:  0x00000001427A9378
struct ServerPlayerReviveMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05977
// TypeInfo:  0x00000001427A9398
struct ServerPlayerLeftLevelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05976
// TypeInfo:  0x00000001427A93B8
struct ServerPlayerReleasingLevelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05975
// TypeInfo:  0x00000001427A93D8
struct ServerPlayerEnteredLevelMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05974
// TypeInfo:  0x00000001427A93F8
struct ServerPlayerLevelLoadedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05973
// TypeInfo:  0x00000001427A9418
struct ServerPlayerDebugFriendZoneSpawnMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 05972
// TypeInfo:  0x00000001427A9438
struct ServerPlayerRespawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05971
// TypeInfo:  0x00000001427A9458
struct ServerPlayerDestroyMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05970
// TypeInfo:  0x00000001427A9478
struct ServerPlayerCreatedForConnectionMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05969
// TypeInfo:  0x00000001427A9498
struct ServerPlayerCreateMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 05968
// TypeInfo:  0x00000001427A94B8
struct ServerPlayerAboutToCreateForConnectionMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05967
// TypeInfo:  0x00000001427A94D8
struct ServerCharacterCharacterDamageMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05966
// TypeInfo:  0x00000001427A94F8
struct ServerCharacterKilledMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05965
// TypeInfo:  0x00000001427A9518
struct ServerMetricsDetonateExplosionMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05964
// TypeInfo:  0x00000001427A9538
struct ServerMetricsObjectiveSuccessMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05963
// TypeInfo:  0x00000001427A9558
struct ServerMetricsSaveGameSavedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05962
// TypeInfo:  0x00000001427A9578
struct ServerMetricsSaveGameLoadedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05961
// TypeInfo:  0x00000001427A9598
struct ServerPlayerAccessLockedVisualContentMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05960
// TypeInfo:  0x00000001427A95B8
struct ServerClientConnectionRemovedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05959
// TypeInfo:  0x00000001427A95D8
struct ServerClientConnectionConnectedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05958
// TypeInfo:  0x00000001427A95F8
struct ServerAdminBanPlayerMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05957
// TypeInfo:  0x00000001427A9618
struct ServerAdminSetServerNameMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05956
// TypeInfo:  0x00000001427A9638
struct ServerScriptTickMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05955
// TypeInfo:  0x00000001427A9658
struct ServerStopMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05954
// TypeInfo:  0x00000001427A9678
struct ServerLoadLevelMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05953
// TypeInfo:  0x00000001427A9698
struct ServerLevelUnloadedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05952
// TypeInfo:  0x00000001427A96B8
struct ServerUnloadLevelMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05951
// TypeInfo:  0x00000001427A96D8
struct ServerLevelLoadedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05950
// TypeInfo:  0x00000001427A96F8
struct ServerStoppedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05949
// TypeInfo:  0x00000001427A9718
struct ServerApplyConfigurationMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05948
// TypeInfo:  0x00000001427A9738
struct ServerResetConfigurationMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05947
// TypeInfo:  0x00000001427A9758
struct ServerStartedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05946
// TypeInfo:  0x00000001427A9778
struct ServerDoneLoadGameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05945
// TypeInfo:  0x00000001427A9798
struct ServerLoadGameMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 05944
// TypeInfo:  0x00000001427A97B8
struct SaveGameSaveMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05943
// TypeInfo:  0x00000001427A97D8
struct StatDisableMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05942
// TypeInfo:  0x00000001427A97F8
struct StatEnableMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05877
// TypeInfo:  0x00000001427A4148
struct PlayerScore
{
	__int32 m_Rank; //0x0000
	unsigned __int32 m_Kills; //0x0004
	unsigned __int32 m_Deaths; //0x0008
	unsigned __int32 m_ScoreMultiplier; //0x000C
	__int32 m_Score; //0x0010
	__int32 m_GlobalScoreOriginal; //0x0014
	__int32 m_GlobalScoreUpdated; //0x0018
	float m_Time; //0x001C
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 05875
// TypeInfo:  0x00000001427A3768
struct UINetworkCheckLevelInstalledMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05874
// TypeInfo:  0x00000001427A3788
struct UINetworkCoopPlayerMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 05871
// TypeInfo:  0x00000001427A37C8
struct UINetworkCoopGameMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05870
// TypeInfo:  0x00000001427A37E8
struct UINetworkSetCoopServerLobbyGameTypeMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05869
// TypeInfo:  0x00000001427A3808
struct UINetworkSquadWipeInstigatorMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05868
// TypeInfo:  0x00000001427A3828
struct UINetworkSquadWipeMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05867
// TypeInfo:  0x00000001427A3848
struct UINetworkRoundWarningMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05866
// TypeInfo:  0x00000001427A3868
struct UINetworkRollCreditsMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05865
// TypeInfo:  0x00000001427A3888
struct UINetworkKilledOtherPlayerMessage
{
	char _0x0000[120];
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 05864
// TypeInfo:  0x00000001427A38A8
struct UINetworkOwnPlayerKilledMessage
{
	char _0x0000[152];
};//Size=0x0098

////////////////////////////////////////
// RuntimeId: 05861
// TypeInfo:  0x00000001427A38E8
struct UINetworkStealBodyMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05860
// TypeInfo:  0x00000001427A3908
struct UINetworkEndOfRoundBonusMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 05859
// TypeInfo:  0x00000001427A3928
struct UINetworkMenuResponseMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05858
// TypeInfo:  0x00000001427A3948
struct UINetworkFieldUpgradeScoringMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05857
// TypeInfo:  0x00000001427A3968
struct UINetworkHudScoringMessage
{
	char _0x0000[144];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 05856
// TypeInfo:  0x00000001427A3988
struct UINetworkPlayerRankUpMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 05855
// TypeInfo:  0x00000001427A39A8
struct UINetworkVoiceOverSubtitleTextMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 05854
// TypeInfo:  0x00000001427A39C8
struct UINetworkPlayerCollectibleTextMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05853
// TypeInfo:  0x00000001427A39E8
struct UINetworkPlayerTutorialInstructionsTextMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05852
// TypeInfo:  0x00000001427A3A08
struct UINetworkPlayerMissionObjectiveTextMessage
{
	char _0x0000[104];
};//Size=0x0068

////////////////////////////////////////
// RuntimeId: 05851
// TypeInfo:  0x00000001427A3A28
struct UINetworkVideoDoneMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05850
// TypeInfo:  0x00000001427A3A48
struct UINetworkAllowSkipVideoMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05849
// TypeInfo:  0x00000001427A3A68
struct UINetworkSkipVideoMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05848
// TypeInfo:  0x00000001427A3A88
struct UINetworkStopVideoMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05847
// TypeInfo:  0x00000001427A3AA8
struct UINetworkPauseVideoMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05846
// TypeInfo:  0x00000001427A3AC8
struct UINetworkPlayVideoMessage
{
	char _0x0000[136];
};//Size=0x0088

////////////////////////////////////////
// RuntimeId: 05845
// TypeInfo:  0x00000001427A3AE8
struct UINetworkPlayerKillsTextMessage
{
	char _0x0000[136];
};//Size=0x0088

////////////////////////////////////////
// RuntimeId: 05844
// TypeInfo:  0x00000001427A3B08
struct UINetworkPlayerDisconnectMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05843
// TypeInfo:  0x00000001427A3B28
struct UINetworkPlayerConnectMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05842
// TypeInfo:  0x00000001427A3B48
struct UINetworkPlayerDeserterTextMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05841
// TypeInfo:  0x00000001427A3B68
struct UINetworkAdminYellMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05840
// TypeInfo:  0x00000001427A3B88
struct UINetworkPlayerTextMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05839
// TypeInfo:  0x00000001427A4168
struct UINetworkTextInfo
{
	char* m_StringId; //0x0000
	float m_DisplayTime; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 05837
// TypeInfo:  0x00000001427A3BA8
struct UINetworkHudTextMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 05836
// TypeInfo:  0x00000001427A3BC8
struct UINetworkHudTooltipMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 05835
// TypeInfo:  0x00000001427A3BE8
struct UINetworkEnableHudMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05828
// TypeInfo:  0x00000001427A3C68
struct NetworkLevelInstalledMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05827
// TypeInfo:  0x00000001427A3C88
struct NetworkSynchronizeInternetSimulationStateMessage
{
	char _0x0000[168];
};//Size=0x00A8

////////////////////////////////////////
// RuntimeId: 05826
// TypeInfo:  0x00000001427A3CA8
struct NetworkMatchReadyStatusChangedMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 05825
// TypeInfo:  0x00000001427A3CC8
struct ServerRestartTimerMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05824
// TypeInfo:  0x00000001427A3CE8
struct NetworkMetricsLevelCompleteMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05823
// TypeInfo:  0x00000001427A3D08
struct NetworkMetricsLevelProgressMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05822
// TypeInfo:  0x00000001427A3D28
struct NetworkMetricsSaveGameSavedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05821
// TypeInfo:  0x00000001427A3D48
struct NetworkSetPlayerViewMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05820
// TypeInfo:  0x00000001427A3D68
struct NetworkSuicideMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05819
// TypeInfo:  0x00000001427A3D88
struct NetworkGameplayContinueMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05818
// TypeInfo:  0x00000001427A3DA8
struct PerformanceLogMessage
{
	char _0x0000[256];
};//Size=0x0100

////////////////////////////////////////
// RuntimeId: 05817
// TypeInfo:  0x00000001427A4188
struct PerformanceFpsHistogram
{
	float m_Below5; //0x0000
	float m_Below10; //0x0004
	float m_Below15; //0x0008
	float m_Below20; //0x000C
	float m_Below25; //0x0010
	float m_Below30; //0x0014
	float m_Below35; //0x0018
	float m_Below40; //0x001C
	float m_Below45; //0x0020
	float m_Below50; //0x0024
	float m_Below55; //0x0028
	float m_Below60; //0x002C
	float m_Above60; //0x0030
};//Size=0x0034

////////////////////////////////////////
// RuntimeId: 05815
// TypeInfo:  0x00000001427A3DC8
struct NetworkFirstPlayerEnteredMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05814
// TypeInfo:  0x00000001427A3DE8
struct NetworkDifficultyChangedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05813
// TypeInfo:  0x00000001427A3E08
struct NetworkSettingsMessage
{
	char _0x0000[120];
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 05812
// TypeInfo:  0x00000001427A3E28
struct DebugSpawnGameEntityMessage
{
	char _0x0000[144];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 05811
// TypeInfo:  0x00000001427A3E48
struct NetworkCreatePlayerMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05810
// TypeInfo:  0x00000001427A3E68
struct NetworkCameraReplayMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05809
// TypeInfo:  0x00000001427A3E88
struct NetworkCameraFreeCameraMessage
{
	char _0x0000[128];
};//Size=0x0080

////////////////////////////////////////
// RuntimeId: 05808
// TypeInfo:  0x00000001427A3EA8
struct NetworkMovePlayerMessage
{
	char _0x0000[144];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 05807
// TypeInfo:  0x00000001427A3EC8
struct NetworkJuiceSessionMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05806
// TypeInfo:  0x00000001427A3EE8
struct NetworkSelectTeamMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05805
// TypeInfo:  0x00000001427A3F08
struct NetworkOnPlayerSpawnedMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05804
// TypeInfo:  0x00000001427A3F28
struct NetworkSelectSpawnGroupMessage
{
	char _0x0000[104];
};//Size=0x0068

////////////////////////////////////////
// RuntimeId: 05803
// TypeInfo:  0x00000001427A3F48
struct NetworkSpawnVehicleCustomizationMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05802
// TypeInfo:  0x00000001427A3F68
struct NetworkUnSpawnCustomizationMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05801
// TypeInfo:  0x00000001427A3F88
struct NetworkSpawnCustomizationMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05800
// TypeInfo:  0x00000001427A3FA8
struct NetworkSpawnOnSelectedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05799
// TypeInfo:  0x00000001427A3FC8
struct NetworkSpawnHereMessage
{
	char _0x0000[144];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 05798
// TypeInfo:  0x00000001427A3FE8
struct NetworkSpawnMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 05797
// TypeInfo:  0x00000001427A4008
struct NetworkRequestLoadLevelMessage
{
	char _0x0000[120];
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 05796
// TypeInfo:  0x00000001427A4028
struct NetworkScreenFadeMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05795
// TypeInfo:  0x00000001427A4048
struct NetworkChangeGameSettingMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05792
// TypeInfo:  0x00000001427A4088
struct LevelConsoleSetActiveHealthStateMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05791
// TypeInfo:  0x00000001427A40A8
struct NetworkTimeSyncMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05790
// TypeInfo:  0x00000001427A40C8
struct NetworkLoadLevelMessage
{
	char _0x0000[136];
};//Size=0x0088

////////////////////////////////////////
// RuntimeId: 05789
// TypeInfo:  0x00000001427A40E8
struct NetworkLevelLoadedAckMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 05788
// TypeInfo:  0x00000001427A4108
struct NetworkTinyEventMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05787
// TypeInfo:  0x00000001427A4128
struct NetworkPerformanceProfileMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 05265
// TypeInfo:  0x0000000142792740
struct LevelSetupOption
{
	char* m_Criterion; //0x0000
	char* m_Value; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 05784
// TypeInfo:  0x00000001427A41C8
struct BlueprintBundlePreloadInfo
{
	char* m_Name; //0x0000
	__int32 m_Compartment; //0x0008
	__int32 m_ParentCompartment; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 05772
// TypeInfo:  0x00000001427A1688
struct SyncedSequenceStateChangeMessageBase
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05771
// TypeInfo:  0x00000001427A16A8
struct JuiceSoldierRagdollDeactivateMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05770
// TypeInfo:  0x00000001427A16C8
struct JuiceSoldierRagdollActivateMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05769
// TypeInfo:  0x00000001427A16E8
struct CoreReadSaveGameDoneMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05768
// TypeInfo:  0x00000001427A1708
struct CoreWriteSaveGameDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05767
// TypeInfo:  0x00000001427A1728
struct CoreWriteProfileGameMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 05766
// TypeInfo:  0x00000001427A1748
struct CoreWriteSaveGameMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05765
// TypeInfo:  0x00000001427A1768
struct StatisticsEventMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05764
// TypeInfo:  0x00000001427A1788
struct BlueprintBundleStreamedInMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05763
// TypeInfo:  0x00000001427A17A8
struct LoadGameBeginLoadMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05762
// TypeInfo:  0x00000001427A17C8
struct SaveGameBeginSaveMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05761
// TypeInfo:  0x00000001427A17E8
struct SessionPlayerJoinedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05760
// TypeInfo:  0x00000001427A1808
struct SessionPlayerAuthenticatedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05759
// TypeInfo:  0x00000001427A1828
struct SessionPlayerLeftMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05758
// TypeInfo:  0x00000001427A1848
struct CoreGameTimerMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05757
// TypeInfo:  0x00000001427A1868
struct CoreExitIngameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05756
// TypeInfo:  0x00000001427A1888
struct CoreEnteredIngameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05755
// TypeInfo:  0x00000001427A18A8
struct PerformanceClientNetworkMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05754
// TypeInfo:  0x00000001427A18C8
struct PerformanceServerNetworkMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05753
// TypeInfo:  0x00000001427A18E8
struct PerformanceServerMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05752
// TypeInfo:  0x00000001427A1908
struct ProfileOptionsSettingsSavedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05751
// TypeInfo:  0x00000001427A1928
struct ProfileOptionsSettingsPreSaveMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05750
// TypeInfo:  0x00000001427A1948
struct ProfileOptionsSettingsLoadedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05749
// TypeInfo:  0x00000001427A1968
struct ProfileOptionsApplyMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05746
// TypeInfo:  0x00000001427A19A8
struct NetworkDisconnectedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05745
// TypeInfo:  0x00000001427A19C8
struct NetworkConnectedMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 05744
// TypeInfo:  0x00000001427A19E8
struct AIClientBridgeDynamicModelEntityOnUnspawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05743
// TypeInfo:  0x00000001427A1A08
struct AIClientBridgeDynamicModelEntityOnSpawnMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05740
// TypeInfo:  0x00000001427A1A48
struct BundleManagerBundleUnloadMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05739
// TypeInfo:  0x00000001427A1A68
struct CoreReadSaveGameDataDoneMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05738
// TypeInfo:  0x00000001427A1A88
struct CoreDebugReadProfileGameDataMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05737
// TypeInfo:  0x00000001427A1AA8
struct CoreDebugReadSaveGameDataMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05736
// TypeInfo:  0x00000001427A1AC8
struct NetworkLogicFireDoublePlayerEventMessageBase
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05735
// TypeInfo:  0x00000001427A1AE8
struct NetworkLogicFirePlayerEventMessageBase
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05734
// TypeInfo:  0x00000001427A1B08
struct NetworkLogicFireEventMessageBase
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05733
// TypeInfo:  0x00000001427A1B28
struct SubLevelFromClientSubLevelLoadedMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05732
// TypeInfo:  0x00000001427A1B48
struct SubLevelFromClientRequestBundleBaselineMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05731
// TypeInfo:  0x00000001427A1B68
struct SubLevelToClientDropBundleBaselineMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05730
// TypeInfo:  0x00000001427A1B88
struct SubLevelToClientUnloadRequestsMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05729
// TypeInfo:  0x00000001427A1BA8
struct SubLevelToClientLoadRequestsMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05728
// TypeInfo:  0x00000001427A1CC8
struct SubLevelBundleInfo
{
	__int32 m_CompartmentIndex; //0x0000
	BundleHeapInfo m_HeapInfo; //0x0004
	char* m_Name; //0x0010
	unsigned __int16 m_SubLevelNameInx; //0x0018
	unsigned __int16 m_SubLevelId; //0x001A
	unsigned __int16 m_ParentSubLevelId; //0x001C
	unsigned __int8 m_Priority; //0x001E
	bool m_IsBlueprintBundle; //0x001F
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 05726
// TypeInfo:  0x00000001427A1BC8
struct SubLevelToClientSubLevelNameMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05725
// TypeInfo:  0x00000001427A1CE8
struct BundleNameAndIndex
{
	char* m_Name; //0x0000
	unsigned __int16 m_Index; //0x0008
	char _0x000A[6];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 05719
// TypeInfo:  0x00000001427A1C28
struct ServerAdministrationPasswordMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05718
// TypeInfo:  0x00000001427A1C48
struct ServerAdministrationEventsEnabledMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05717
// TypeInfo:  0x00000001427A1C68
struct ServerAdministrationQuitMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05716
// TypeInfo:  0x00000001427A1C88
struct ServerAdministrationLoginMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05715
// TypeInfo:  0x00000001427A1CA8
struct ServerAdministrationPacketMessageBase
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05594
// TypeInfo:  0x000000014279B228
struct ClientWeaponDispersionUpdatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05593
// TypeInfo:  0x000000014279B248
struct ClientWeaponPlayerPrimaryOutOfAmmoMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05592
// TypeInfo:  0x000000014279B268
struct ClientWeaponPlayerWeaponReloadEndMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05591
// TypeInfo:  0x000000014279B288
struct ClientWeaponPlayerWeaponReloadBeginMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05590
// TypeInfo:  0x000000014279B2A8
struct ClientWeaponPlayerPrimaryWeaponFireMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05589
// TypeInfo:  0x000000014279B2C8
struct ClientWeaponPlayerWeaponChangeMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05588
// TypeInfo:  0x000000014279B2E8
struct ClientPlayerReviveRefusedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05587
// TypeInfo:  0x000000014279B308
struct ClientPlayerReviveAcceptedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05586
// TypeInfo:  0x000000014279B328
struct ClientPlayerReviveMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05585
// TypeInfo:  0x000000014279B348
struct ClientPlayerInteractionEntityInRangeChangedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05584
// TypeInfo:  0x000000014279B368
struct ClientPlayerOnWeaponUndeployFinishedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05583
// TypeInfo:  0x000000014279B388
struct ClientPlayerSelectedUnlocksMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05582
// TypeInfo:  0x000000014279B3A8
struct ClientPlayerDeletedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05581
// TypeInfo:  0x000000014279B3C8
struct ClientPlayerConnectMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05580
// TypeInfo:  0x000000014279B3E8
struct ClientPlayerLocalSetMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05579
// TypeInfo:  0x000000014279B408
struct ClientPlayerChangedPlayerViewMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05578
// TypeInfo:  0x000000014279B428
struct ClientPlayerSwitchTeamMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05577
// TypeInfo:  0x000000014279B448
struct ClientPlayerManDownMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05576
// TypeInfo:  0x000000014279B468
struct ClientPlayerWeaponPickupMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05575
// TypeInfo:  0x000000014279B488
struct ClientPlayerAmmoPickupMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05574
// TypeInfo:  0x000000014279B4A8
struct ClientPlayerShowKillCameraMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05573
// TypeInfo:  0x000000014279B4C8
struct ClientPlayerKilledMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05572
// TypeInfo:  0x000000014279B4E8
struct ClientPlayerEnterEntryMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05571
// TypeInfo:  0x000000014279B508
struct ClientPlayerEnterExitVehicleMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05570
// TypeInfo:  0x000000014279B528
struct ClientPlayerRequestCameraChangeMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05569
// TypeInfo:  0x000000014279B548
struct ClientPlayerUpdateCameraComponentMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05568
// TypeInfo:  0x000000014279B568
struct ClientMetricsPauseGameMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05567
// TypeInfo:  0x000000014279B588
struct ClientMetricsUIActionMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05566
// TypeInfo:  0x000000014279B5A8
struct ClientMetricsPopUIScreenMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05565
// TypeInfo:  0x000000014279B5C8
struct ClientMetricsPushUIScreenMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05564
// TypeInfo:  0x000000014279B5E8
struct ClientSetServerPasswordMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05563
// TypeInfo:  0x000000014279B608
struct ClientWantFullscreenMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05562
// TypeInfo:  0x000000014279B628
struct ClientLeftRemoteServerMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05561
// TypeInfo:  0x000000014279B648
struct ClientDisconnectedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05560
// TypeInfo:  0x000000014279B668
struct ClientConnectedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05559
// TypeInfo:  0x000000014279B688
struct ClientAbortCutsceneMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05558
// TypeInfo:  0x000000014279B6A8
struct ClientLevelLoadedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05557
// TypeInfo:  0x000000014279B6C8
struct ClientLevelLoadProgressMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05556
// TypeInfo:  0x000000014279B6E8
struct ClientLevelDescriptionLoadedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05555
// TypeInfo:  0x000000014279B708
struct ClientLevelUnloadedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05554
// TypeInfo:  0x000000014279B728
struct ClientLoadLevelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05553
// TypeInfo:  0x000000014279B748
struct ClientLoadLevelRequestedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05552
// TypeInfo:  0x000000014279B768
struct ClientEnteredIngameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05551
// TypeInfo:  0x000000014279B788
struct ClientEnterHudIngameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05550
// TypeInfo:  0x000000014279B7A8
struct ClientExitGameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05549
// TypeInfo:  0x000000014279B7C8
struct ClientExitToMenuMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05548
// TypeInfo:  0x000000014279B7E8
struct ClientReturnToMenuMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05547
// TypeInfo:  0x000000014279B808
struct ClientStartMultiplayerMessage
{
	char _0x0000[104];
};//Size=0x0068

////////////////////////////////////////
// RuntimeId: 05546
// TypeInfo:  0x000000014279B828
struct ClientContinueSingleplayerMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05545
// TypeInfo:  0x000000014279B848
struct ClientStartedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05544
// TypeInfo:  0x000000014279B868
struct ClientJoinServerJobMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05543
// TypeInfo:  0x000000014279B888
struct ClientPeerNetworkRemovedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05542
// TypeInfo:  0x000000014279B8A8
struct ClientJoinMultiplayerMessageBase
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05541
// TypeInfo:  0x000000014279B8C8
struct ClientRestartSingleplayerMessageBase
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05540
// TypeInfo:  0x000000014279B8E8
struct ClientStartSingleplayerMessageBase
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 05431
// TypeInfo:  0x0000000142795E00
struct UserGamerpicBufferReceivedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05422
// TypeInfo:  0x0000000142795E20
struct UIBundleUnloadedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05421
// TypeInfo:  0x0000000142795E40
struct UIBundleLoadedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05416
// TypeInfo:  0x0000000142795E80
struct ClientCommanderPlayerChangedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05415
// TypeInfo:  0x0000000142795EA0
struct ClientConnectionUnloadLevelMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05414
// TypeInfo:  0x0000000142795EC0
struct ClientConnectionLinkLevelMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05413
// TypeInfo:  0x0000000142795EE0
struct ClientConnectionLoadLevelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05412
// TypeInfo:  0x0000000142795F00
struct ClientConnectionInitializedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05411
// TypeInfo:  0x0000000142795F20
struct ClientStateChangingStateMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05410
// TypeInfo:  0x0000000142795F40
struct ClientLevelFinalizedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05409
// TypeInfo:  0x0000000142795F60
struct ClientLevelSpawnEntitiesEndMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05408
// TypeInfo:  0x0000000142795F80
struct ClientLevelSpawnDebugEntitiesMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05407
// TypeInfo:  0x0000000142795FA0
struct ClientGameplaySoldierHealthRequestMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05406
// TypeInfo:  0x0000000142795FC0
struct ClientGameplayControllableLowHealthMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05405
// TypeInfo:  0x0000000142795FE0
struct ClientGameplaySoldierHitMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05404
// TypeInfo:  0x0000000142796000
struct ClientCameraShowKillerMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05403
// TypeInfo:  0x0000000142796020
struct ClientCollisionProjectileImpactMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05402
// TypeInfo:  0x0000000142796040
struct ClientCollisionSpawnExplosionMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 05401
// TypeInfo:  0x0000000142796060
struct ClientCollisionExplosionPackDetonatedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05400
// TypeInfo:  0x0000000142796080
struct ClientCollisionExplosionPackPlacedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05399
// TypeInfo:  0x00000001427960A0
struct ClientCollisionGrenadeCollisionMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 05398
// TypeInfo:  0x00000001427960C0
struct ClientSoundVoiceOverFinishedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05397
// TypeInfo:  0x00000001427960E0
struct ClientVehicleCriticalDamageMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05396
// TypeInfo:  0x0000000142796100
struct ClientEntityDummyToGetTheClientEntityMessageCategoryMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05395
// TypeInfo:  0x0000000142796120
struct ClientCharacterSpawnDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05394
// TypeInfo:  0x0000000142796140
struct ClientCharacterLocalPlayerDeletedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 05393
// TypeInfo:  0x0000000142796160
struct ClientCharacterLocalPlayerSetMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05392
// TypeInfo:  0x0000000142796180
struct ClientSpawnSpawnedOrUnSpawnedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05391
// TypeInfo:  0x00000001427961A0
struct ClientControllableUnspawnDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05390
// TypeInfo:  0x00000001427961C0
struct ClientControllableSpawnDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05389
// TypeInfo:  0x00000001427961E0
struct ClientInputUnchangedInputMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05388
// TypeInfo:  0x0000000142796200
struct ClientInputSettingsRefreshMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05337
// TypeInfo:  0x0000000142793B58
struct EventKeyframe
{
	float m_Time; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 05313
// TypeInfo:  0x0000000142793B78
struct ColorKeyframe
{
	Vec4 m_RGBColor; //0x0000
	float m_Time; //0x0010
	char _0x0014[12];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 05309
// TypeInfo:  0x0000000142793B98
struct BoolKeyframe
{
	float m_Time; //0x0000
	bool m_Value; //0x0004
	char _0x0005[3];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 05267
// TypeInfo:  0x0000000142792720
struct LevelSetup
{
	char* m_Name; //0x0000
	Array<LevelSetupOption> m_InclusionOptions; //0x0008
	unsigned __int32 m_DifficultyIndex; //0x0010
	char _0x0014[4];
	Array<char*> m_SubLevelNames; //0x0018
	char* m_StartPoint; //0x0020
	Array<__int32> m_SubLevelStates; //0x0028
	bool m_IsSaveGame; //0x0030
	bool m_ForceReloadResources; //0x0031
	char _0x0032[6];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 05786
// TypeInfo:  0x00000001427A41A8
struct LoadLevelInfo
{
	LevelSetup m_Setup; //0x0000
	Array<BlueprintBundlePreloadInfo> m_BlueprintBundlePreloads; //0x0038
	unsigned __int32 m_LevelSequenceNumber; //0x0040
	char _0x0044[4];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 05225
// TypeInfo:  0x000000014278FA28
struct TransformPartPropertyKey
{
	float m_Value; //0x0000
	AnimTangentType m_InAnimTangentType; //0x0004
	float m_InAngle; //0x0008
	float m_InWeight; //0x000C
	AnimTangentType m_OutAnimTangentType; //0x0010
	float m_OutAngle; //0x0014
	float m_OutWeight; //0x0018
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 05183
// TypeInfo:  0x000000014278FA48
struct SequenceEventData
{
	EventSpec m_Event; //0x0000
	__int32 m_Time; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 05175
// TypeInfo:  0x000000014278FA88
struct MaterialRelationPropertyPair
{
	Array<PhysicsMaterialRelationPropertyData*> m_PhysicsMaterialProperties; //0x0000
	Array<PhysicsPropertyRelationPropertyData*> m_PhysicsPropertyProperties; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 05177
// TypeInfo:  0x000000014278FA68
struct MaterialInteractionGridRow
{
	Array<MaterialRelationPropertyPair> m_Items; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 07459
// TypeInfo:  0x00000001427C60A0
struct OnImpulseModifierData
{
	MaterialDecl m_MaterialPair; //0x0000
	float m_MagnitudeScale; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 05137
// TypeInfo:  0x000000014278B528
struct SubLevelDestroyedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05136
// TypeInfo:  0x000000014278B548
struct SubLevelEntitiesCreatedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 05111
// TypeInfo:  0x000000014278B608
struct SubSkeleton
{
	SkeletonAsset* m_Skeleton; //0x0000
	Array<__int32> m_BoneMap; //0x0008
	Array<LinearTransform> m_TransformMap; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 05105
// TypeInfo:  0x000000014278B628
struct GameplayBone
{
	char* m_Name; //0x0000
	GameplayBones m_Bone; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 04963
// TypeInfo:  0x000000014278B648
struct EntityStableUid
{
	unsigned __int32 m_Id; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 04961
// TypeInfo:  0x000000014278B668
struct EntityOwnerUid
{
	unsigned __int32 m_Id; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 04959
// TypeInfo:  0x000000014278B688
struct EntityUid
{
	unsigned __int32 m_Id; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 04915
// TypeInfo:  0x000000014278B6A8
struct PropertyChannel
{
	Realm m_Realm; //0x0000
	__int32 m_Id; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04913
// TypeInfo:  0x000000014278B6C8
struct EventChannel
{
	Realm m_Realm; //0x0000
	__int32 m_Id; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04911
// TypeInfo:  0x000000014278B6E8
struct LinkChannel
{
	Realm m_Realm; //0x0000
	__int32 m_Id; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04881
// TypeInfo:  0x000000014278B708
struct DynamicLink
{
	__int32 m_Id; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 04879
// TypeInfo:  0x000000014278B728
struct DynamicEvent
{
	__int32 m_Id; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 04877
// TypeInfo:  0x000000014278B748
struct EventConnection
{
	DataContainer* m_Source; //0x0000
	DataContainer* m_Target; //0x0008
	EventSpec m_SourceEvent; //0x0010
	EventSpec m_TargetEvent; //0x0014
	EventConnectionTargetType m_TargetType; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 06768
// TypeInfo:  0x00000001427BE0D0
struct AntEventData
{
	__int32 m_TagId; //0x0000
	EventSpec m_Event; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 06794
// TypeInfo:  0x00000001427BDE70
struct BlueprintBundleReference
{
	char* m_Name; //0x0000
	BlueprintBundleSettings m_Settings; //0x0008
	unsigned __int32 m_BaseBundleHash; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 04728
// TypeInfo:  0x00000001427829E8
struct EmitterExclusionVolumeBoundingSphereSoA
{
	Vec4 m_PosX; //0x0000
	Vec4 m_PosY; //0x0010
	Vec4 m_PosZ; //0x0020
	Vec4 m_RadiusSqr; //0x0030
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 04726
// TypeInfo:  0x0000000142782A08
struct EmitterExclusionVolume
{
	Vec4 m_Left; //0x0000
	Vec4 m_Up; //0x0010
	Vec4 m_Forward; //0x0020
	Vec4 m_HalfExtents; //0x0030
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 04578
// TypeInfo:  0x0000000142782970
struct PolynomialTempData
{
	Vec4 m_Coefficients; //0x0000
	float m_ScaleValue; //0x0010
	float m_MinClamp; //0x0014
	float m_MaxClamp; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 04569
// TypeInfo:  0x00000001427802E0
struct BreakablePartToStaticEntityPart
{
	unsigned __int32 m_BreakablePartIndex; //0x0000
	unsigned __int32 m_StaticModelPartIndex; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04567
// TypeInfo:  0x0000000142780300
struct StaticModelToBreakableParts
{
	unsigned __int32 m_StaticModelIndex; //0x0000
	unsigned __int32 m_BreakablePartStartIndex; //0x0004
	unsigned __int32 m_BreakablePartCount; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 04559
// TypeInfo:  0x0000000142780260
struct BreakableModelToComponentsSpawnPartObjectsOnCollapseMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 04558
// TypeInfo:  0x0000000142780280
struct BreakableModelToComponentsCollapseMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 04531
// TypeInfo:  0x000000014277F2A8
struct DebrisClusterPartInfoData
{
	Vec3 m_LinearVelocity; //0x0000
	Vec3 m_AngularVelocity; //0x0010
	__int32 m_PartIndex; //0x0020
	__int32 m_NumberOfChildren; //0x0024
	float m_SplitSpeedThreshold; //0x0028
	bool m_SyncRestPosition; //0x002C
	bool m_SyncContinous; //0x002D
	bool m_InEffectWorldOnly; //0x002E
	char _0x002F[1];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 04525
// TypeInfo:  0x000000014277F2C8
struct DebrisHavokInfo
{
	HavokAsset* m_HavokAsset; //0x0000
	__int32 m_ReserveCount; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 04523
// TypeInfo:  0x000000014277F2E8
struct DebrisSystemMetrics
{
	__int32 m_HavokParticleCount; //0x0000
	__int32 m_HavokParticlePartCount; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04450
// TypeInfo:  0x00000001427772B0
struct AudioLanguageMapping
{
	AudioLanguage* m_Source; //0x0000
	AudioLanguage* m_Target; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 04442
// TypeInfo:  0x00000001427772D0
struct SoundPatchPublicNode
{
	AudioGraphNodeData* m_Node; //0x0000
	unsigned __int32 m_Id; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 04424
// TypeInfo:  0x00000001427772F0
struct SoundWaveLocalizationInfo
{
	AudioLanguage* m_Language; //0x0000
	unsigned __int16 m_FirstVariationIndex; //0x0008
	unsigned __int16 m_VariationCount; //0x000A
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 04418
// TypeInfo:  0x0000000142777310
struct SoundDataReference
{
	DataContainer* m_DataOwner; //0x0000
	SoundDataAsset* m_SoundData; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 04406
// TypeInfo:  0x0000000142777330
struct MixerInputInfo
{
	MixerValueAccumulateMode m_Mode; //0x0000
	bool m_KeepValue; //0x0004
	char _0x0005[3];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04400
// TypeInfo:  0x0000000142777350
struct MixerPresetNodeData
{
	AudioGraphNodeData* m_Node; //0x0000
	float m_Value; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 04396
// TypeInfo:  0x0000000142777390
struct MixGroupPropertyValue
{
	unsigned __int32 m_Property; //0x0000
	float m_Value; //0x0004
	bool m_Controlled; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 04398
// TypeInfo:  0x0000000142777370
struct MixerPresetGroupData
{
	MixGroup* m_Group; //0x0000
	MixGroupState m_State; //0x0008
	float m_AttackTime; //0x000C
	float m_ReleaseTime; //0x0010
	__int32 m_Priority; //0x0014
	Array<MixGroupPropertyValue> m_Properties; //0x0018
	bool m_IsDominant; //0x0020
	bool m_IsAdditive; //0x0021
	char _0x0022[6];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 04390
// TypeInfo:  0x00000001427773B0
struct MixGroupPropertyParameters
{
	unsigned __int32 m_Property; //0x0000
	float m_MinOffset; //0x0004
	float m_MaxOffset; //0x0008
	float m_DefaultValue; //0x000C
	bool m_EnableOffsetMinMax; //0x0010
	bool m_OverrideDefaultValue; //0x0011
	char _0x0012[2];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 04336
// TypeInfo:  0x0000000142777130
struct AudioGraphNodePort
{
	float m_UnconnectedValue; //0x0000
	unsigned __int16 m_ValueIndex; //0x0004
	bool m_IsConnected; //0x0006
	char _0x0007[1];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04278
// TypeInfo:  0x00000001427773D0
struct RangeMapperEntry
{
	float m_RangeStart; //0x0000
	float m_RangeEnd; //0x0004
	float m_OutputValue; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 04180
// TypeInfo:  0x00000001427773F0
struct VoiceOverManuscriptLanguageColumns
{
	AudioLanguage* m_Language; //0x0000
	char* m_TextColumn; //0x0008
	char* m_SubtitleOffsetColumn; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 04152
// TypeInfo:  0x0000000142777150
struct VoiceOverConversationInfo
{
	Array<VoiceOverDialogGroup*> m_Groups; //0x0000
	Array<VoiceOverDialogTrack*> m_Tracks; //0x0008
	Array<VoiceOverPronunciation*> m_Pronunciations; //0x0010
	VoiceOverConversationInterruptMode m_InterruptMode; //0x0018
	__int32 m_Priority; //0x001C
	VoiceOverConversationQueueMode m_QueueMode; //0x0020
	float m_Relevancy; //0x0024
	unsigned __int8 m_LastSequenceIndex; //0x0028
	char _0x0029[7];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 04140
// TypeInfo:  0x0000000142777410
struct VoiceOverDialogTakeMapping
{
	float m_TakeControlMin; //0x0000
	float m_TakeControlMax; //0x0004
	unsigned __int8 m_TakeIndex; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 04134
// TypeInfo:  0x0000000142777430
struct VoiceOverDialogTake
{
	SoundWaveAsset* m_Wave; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04054
// TypeInfo:  0x0000000142777170
struct VoiceOverValueConnection
{
	VoiceOverExpressionNode* m_TargetNode; //0x0000
	VoiceOverValue* m_TargetValue; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03884
// TypeInfo:  0x0000000142777250
struct SoundGraphPluginRef
{
	bool m_IsValid; //0x0000
	unsigned __int8 m_VoiceIndex; //0x0001
	unsigned __int8 m_PluginIndex; //0x0002
};//Size=0x0003

////////////////////////////////////////
// RuntimeId: 03992
// TypeInfo:  0x0000000142777470
struct MusicOverlayVariation
{
	float m_MinimumTimeRemaining; //0x0000
	char _0x0004[4];
	SoundWaveAsset* m_Wave; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03940
// TypeInfo:  0x0000000142777490
struct SoundScopeStrategyMapping
{
	SoundScopeData* m_Scope; //0x0000
	SoundScopeStrategyData* m_Strategy; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03932
// TypeInfo:  0x00000001427774B0
struct SoundWaveRuntimeVariation
{
	unsigned __int32 m_PersistentDataSize; //0x0000
	unsigned __int16 m_FirstSegmentIndex; //0x0004
	unsigned __int8 m_FirstSubtitleIndex; //0x0006
	unsigned __int8 m_SubtitleCount; //0x0007
	unsigned __int8 m_SegmentCount; //0x0008
	unsigned __int8 m_ChunkIndex; //0x0009
	unsigned __int8 m_FirstLoopSegmentIndex; //0x000A
	unsigned __int8 m_LastLoopSegmentIndex; //0x000B
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 03928
// TypeInfo:  0x00000001427774D0
struct SoundWaveSubtitle
{
	float m_Time; //0x0000
	unsigned __int8 m_StringIndex; //0x0004
	char _0x0005[3];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03926
// TypeInfo:  0x00000001427774F0
struct SoundWaveVariationSegment
{
	unsigned __int32 m_SamplesOffset; //0x0000
	unsigned __int32 m_SeekTableOffset; //0x0004
	float m_SegmentLength; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 03912
// TypeInfo:  0x0000000142777510
struct SoundDataChunk
{
	Guid m_ChunkId; //0x0000
	char _0x0000[16];
	unsigned __int32 m_ChunkSize; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03886
// TypeInfo:  0x0000000142777570
struct SoundGraphPluginInfo
{
	unsigned __int32 m_Id; //0x0000
	unsigned __int32 m_EnableAttributeReadMask; //0x0004
	unsigned __int8 m_ConnectionIndex; //0x0008
	unsigned __int8 m_OutputChannelCount; //0x0009
	unsigned __int8 m_ConstructParamsIndex; //0x000A
	unsigned __int8 m_ConstructParamCount; //0x000B
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 03890
// TypeInfo:  0x0000000142777530
struct SoundGraphVoiceInfo
{
	Array<SoundGraphPluginInfo> m_Plugins; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03888
// TypeInfo:  0x0000000142777550
struct SoundGraphLinkedPluginAttribute
{
	float m_UnconnectedValue; //0x0000
	unsigned __int16 m_ValueIndex; //0x0004
	unsigned __int16 m_NodeIndexAndFlags; //0x0006
	unsigned __int8 m_VoiceIndex; //0x0008
	unsigned __int8 m_PluginIndex; //0x0009
	unsigned __int8 m_AttributeIndex; //0x000A
	char _0x000B[1];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 03876
// TypeInfo:  0x00000001427775D0
struct SoundGraphPluginConnectionParam
{
	__int32 m_Value; //0x0000
	unsigned __int8 m_Index; //0x0004
	char _0x0005[3];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 04024
// TypeInfo:  0x0000000142777450
struct MusicPlayerPlugins
{
	SoundGraphPluginRef m_SndPlayer; //0x0000
	SoundGraphPluginRef m_Rechannel; //0x0003
	SoundGraphPluginRef m_Resample; //0x0006
	SoundGraphPluginRef m_Pause; //0x0009
	SoundGraphPluginRef m_Gain; //0x000C
};//Size=0x000F

////////////////////////////////////////
// RuntimeId: 03882
// TypeInfo:  0x0000000142777590
struct SoundGraphPluginConstructParam
{
	float m_Value; //0x0000
	unsigned __int8 m_Index; //0x0004
	char _0x0005[3];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03880
// TypeInfo:  0x00000001427775B0
struct SoundGraphPluginConnection
{
	SoundGraphPluginConnectionType m_ConnectionType; //0x0000
	char _0x0004[4];
	SoundBusData* m_Bus; //0x0008
	Array<SoundGraphPluginConnectionParam> m_Parameters; //0x0010
	unsigned __int8 m_VoiceIndex; //0x0018
	unsigned __int8 m_PluginIndex; //0x0019
	unsigned __int8 m_SignalIndex; //0x001A
	char _0x001B[5];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03892
// TypeInfo:  0x0000000142777230
struct SoundGraphInfo
{
	Array<SoundGraphVoiceInfo> m_Voices; //0x0000
	Array<SoundGraphLinkedPluginAttribute> m_LinkedPluginAttributes; //0x0008
	Array<SoundGraphPluginConnection> m_Connections; //0x0010
	Array<SoundGraphPluginConstructParam> m_ConstructParams; //0x0018
	unsigned __int32 m_PluginsParamCount; //0x0020
	unsigned __int32 m_PluginCount; //0x0024
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03870
// TypeInfo:  0x00000001427775F0
struct PointEnvelopePoint
{
	float m_X; //0x0000
	float m_Y; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03842
// TypeInfo:  0x0000000142777610
struct SamplerPlugins
{
	SoundGraphPluginRef m_SndPlayer; //0x0000
	SoundGraphPluginRef m_Resample; //0x0003
	SoundGraphPluginRef m_Pause; //0x0006
	SoundGraphPluginRef m_Gain; //0x0009
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 03756
// TypeInfo:  0x0000000142777630
struct DivisibleLoopPlayerPlugins
{
	SoundGraphPluginRef m_SndPlayer; //0x0000
	SoundGraphPluginRef m_Pause; //0x0003
	SoundGraphPluginRef m_Gain; //0x0006
	SoundGraphPluginRef m_GainFader; //0x0009
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 07735
// TypeInfo:  0x00000001427CDAF0
struct AntAnimationHandlerData
{
	AntAnimatableData m_Animatable; //0x0000
	AntRef m_RootController; //0x0060
	LodBinding m_LodBinding; //0x0074
	Array<__int32> m_JointOutputFieldHashes; //0x00D8
	Array<__int32> m_JointEnabledFieldHashes; //0x00E0
	AntControllerComplexity m_ControllerComplexity; //0x00E8
	bool m_ReportBackFromAnt; //0x00EC
	bool m_EnableMasterSlaveCopy; //0x00ED
	bool m_IsProp; //0x00EE
	char _0x00EF[1];
};//Size=0x00F0

////////////////////////////////////////
// RuntimeId: 03708
// TypeInfo:  0x000000014276DCC0
struct AntScenario
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 03706
// TypeInfo:  0x000000014276DCE0
struct AntRefInfo
{
	Guid m_FrostbitePartition; //0x0000
	char _0x0000[16];
	AntRef m_AntRef; //0x0010
};//Size=0x0024

////////////////////////////////////////
// RuntimeId: 09662
// TypeInfo:  0x00000001427F5178
struct WeaponLagBinding
{
	AntRef m_EntityPitch; //0x0000
	AntRef m_EntityYaw; //0x0014
	AntRef m_PitchResult; //0x0028
	AntRef m_YawResult; //0x003C
	AntRef m_RollResult; //0x0050
};//Size=0x0064

////////////////////////////////////////
// RuntimeId: 03693
// TypeInfo:  0x000000014276D108
struct CoreSettings
{
	char* m_Host; //0x0000
	char* m_HostUser; //0x0008
	char* m_HostUserDomain; //0x0010
	char* m_InitSeed; //0x0018
	CoreLogLevel m_LogLevel; //0x0020
	CoreLogLevel m_DialogLevel; //0x0024
	unsigned __int32 m_DebugOutputMode; //0x0028
	__int32 m_RandomTimeSeed; //0x002C
	__int32 m_RandomTickSeed; //0x0030
	__int32 m_RandomSessionId; //0x0034
	char* m_GameConfigurationName; //0x0038
	HardwareProfile m_HardwareProfile; //0x0040
	float m_HardwareCpuBias; //0x0044
	float m_HardwareGpuBias; //0x0048
	char _0x004C[4];
	char* m_ProfileDirectoryName; //0x0050
	float m_ScatterJobYieldGranularity; //0x0058
	char _0x005C[4];
	char* m_AvailableLanguages; //0x0060
	bool m_LiveEditingEnable; //0x0068
	bool m_UserLogEnabled; //0x0069
	bool m_DisplayAsserts; //0x006A
	bool m_CrashOnFatalErrors; //0x006B
	bool m_UseStorageServer; //0x006C
	bool m_EnableLocalization; //0x006D
	bool m_EnableSpikePacketBuffering; //0x006E
	char _0x006F[1];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 03685
// TypeInfo:  0x000000014276D128
struct PlatformScalableBool
{
	bool m_Default; //0x0000
	bool m_Xenon; //0x0001
	bool m_Ps3; //0x0002
	bool m_Gen4a; //0x0003
	bool m_Gen4b; //0x0004
};//Size=0x0005

////////////////////////////////////////
// RuntimeId: 03683
// TypeInfo:  0x000000014276D148
struct PlatformScalableFloat
{
	float m_Default; //0x0000
	float m_Xenon; //0x0004
	float m_Ps3; //0x0008
	float m_Gen4a; //0x000C
	float m_Gen4b; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03681
// TypeInfo:  0x000000014276D168
struct PlatformScalableInt
{
	__int32 m_Default; //0x0000
	__int32 m_Xenon; //0x0004
	__int32 m_Ps3; //0x0008
	__int32 m_Gen4a; //0x000C
	__int32 m_Gen4b; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03677
// TypeInfo:  0x000000014276D188
struct QualityScalableBool
{
	bool m_Low; //0x0000
	bool m_Medium; //0x0001
	bool m_High; //0x0002
	bool m_Ultra; //0x0003
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 03675
// TypeInfo:  0x000000014276D1A8
struct QualityScalableFloat
{
	float m_Low; //0x0000
	float m_Medium; //0x0004
	float m_High; //0x0008
	float m_Ultra; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03673
// TypeInfo:  0x000000014276D1C8
struct QualityScalableInt
{
	__int32 m_Low; //0x0000
	__int32 m_Medium; //0x0004
	__int32 m_High; //0x0008
	__int32 m_Ultra; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03663
// TypeInfo:  0x000000014276D1E8
struct DataField
{
	char* m_Value; //0x0000
	DataContainer* m_ValueRef; //0x0008
	__int32 m_Id; //0x0010
	FieldAccessType m_AccessType; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03659
// TypeInfo:  0x000000014276D208
struct LinkConnection
{
	DataContainer* m_Source; //0x0000
	DataContainer* m_Target; //0x0008
	__int32 m_SourceFieldId; //0x0010
	__int32 m_TargetFieldId; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03657
// TypeInfo:  0x000000014276D228
struct PropertyConnection
{
	DataContainer* m_Source; //0x0000
	DataContainer* m_Target; //0x0008
	__int32 m_SourceFieldId; //0x0010
	__int32 m_TargetFieldId; //0x0014
	bool m_ShouldNetworkValue; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03637
// TypeInfo:  0x000000014276D248
struct InternetSimulationState
{
	float m_ReorderRatio; //0x0000
	float m_LatencyMin; //0x0004
	float m_LatencyMax; //0x0008
	float m_DuplicateRatio; //0x000C
	float m_DropRatio; //0x0010
	float m_CorruptRatio; //0x0014
	float m_SizeRatio; //0x0018
	float m_SpikeDurationMin; //0x001C
	float m_SpikeDurationMax; //0x0020
	float m_SpikeCooldownMin; //0x0024
	float m_SpikeCooldownMax; //0x0028
	bool m_Enabled; //0x002C
	char _0x002D[3];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 03635
// TypeInfo:  0x000000014276CF28
struct StreamInstallGameInstalledMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03634
// TypeInfo:  0x000000014276CF48
struct StreamInstallRequestResumeMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03633
// TypeInfo:  0x000000014276CF68
struct StreamInstallRequestSuspendMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03632
// TypeInfo:  0x000000014276CF88
struct StreamInstallInstallDoneMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 03631
// TypeInfo:  0x000000014276CFA8
struct StreamInstallChunkInstalledMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 03630
// TypeInfo:  0x000000014276CFC8
struct StreamInstallInstallProgressMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 03629
// TypeInfo:  0x000000014276CFE8
struct StreamInstallInstallingMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03628
// TypeInfo:  0x000000014276D008
struct CoreCleanupMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03627
// TypeInfo:  0x000000014276D028
struct CoreSublevelStartStreamOutMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03626
// TypeInfo:  0x000000014276D048
struct CorePanicMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03625
// TypeInfo:  0x000000014276D068
struct CoreQuitMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03624
// TypeInfo:  0x000000014276D088
struct CoreUpdateClipboardMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 03623
// TypeInfo:  0x000000014276D0A8
struct CoreMainThreadInitMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03622
// TypeInfo:  0x000000014276D0C8
struct CoreHibernateMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03621
// TypeInfo:  0x000000014276D0E8
struct CoreQuittingInitiatedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 03614
// TypeInfo:  0x000000014276BDC8
struct SplineCurve
{
	Vec4 m_XValues0; //0x0000
	Vec4 m_XValues1; //0x0010
	Vec4 m_XValues2; //0x0020
	Vec4 m_YValues0; //0x0030
	Vec4 m_YValues1; //0x0040
	Vec4 m_YValues2; //0x0050
	Vec4 m_YValues3; //0x0060
	Vec4 m_GValues0; //0x0070
	Vec4 m_GValues1; //0x0080
	Vec4 m_GValues2; //0x0090
	Vec4 m_GValues3; //0x00A0
	Vec4 m_GValues4; //0x00B0
	Vec4 m_GValues5; //0x00C0
	SplineType m_SplineType; //0x00D0
	char _0x00D4[12];
};//Size=0x00E0

////////////////////////////////////////
// RuntimeId: 03606
// TypeInfo:  0x000000014276BE08
struct AudioCurvePoint
{
	float m_X; //0x0000
	float m_Y; //0x0004
	float m_K; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 03610
// TypeInfo:  0x000000014276BDE8
struct AudioCurve
{
	Array<AudioCurvePoint> m_Points; //0x0000
	AudioCurveType m_CurveType; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 07983
// TypeInfo:  0x00000001427D1DF8
struct PartInfoData
{
	AxisAlignedBox m_Aabb; //0x0000
	Vec3 m_Translation; //0x0020
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 03562
// TypeInfo:  0x00000001420DC870
struct Mat4
{
	float m_m11; //0x0000
	float m_m12; //0x0004
	float m_m13; //0x0008
	float m_m14; //0x000C
	float m_m21; //0x0010
	float m_m22; //0x0014
	float m_m23; //0x0018
	float m_m24; //0x001C
	float m_m31; //0x0020
	float m_m32; //0x0024
	float m_m33; //0x0028
	float m_m34; //0x002C
	float m_m41; //0x0030
	float m_m42; //0x0034
	float m_m43; //0x0038
	float m_m44; //0x003C
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 09514
// TypeInfo:  0x00000001427F5778
struct WeaponStateData
{
	Array<unsigned __int32> m_ReferencedAssetHashes; //0x0000
	Array<BoneFakePhysicsData*> m_BoneFakePhysics; //0x0008
	ObjectBlueprint* m_WeaponMesh3p; //0x0010
	SkinnedMeshAsset* m_Mesh3p; //0x0018
	AntRef m_Weapon; //0x0020
	AntRef m_Weapon3p; //0x0034
	float m_ZoomMeshTransitionFactor; //0x0048
	float m_ZoomScaleFactor; //0x004C
	Array<float> m_ZoomInOutMeshTransitionFactors; //0x0050
	float m_KeepAimingTime; //0x0058
	AnimatedFireEnum m_AnimatedFireType; //0x005C
	AnimatedAimingEnum m_AnimatedAimingType; //0x0060
	float m_HideProjectileAfterFireTime; //0x0064
	char* m_ProjectileBoneName; //0x0068
	float m_UnDeploySpeed; //0x0070
	float m_DeploySpeed; //0x0074
	Array<LinearTransform> m_Mesh3pTransforms; //0x0078
	bool m_AlwaysAimHead; //0x0080
	bool m_IsOneHanded; //0x0081
	bool m_PlayDeployAfterFire; //0x0082
	bool m_SkipDeployAnimation; //0x0083
	bool m_SkipReloadAnimation; //0x0084
	bool m_SkipFireAnimation; //0x0085
	char _0x0086[2];
};//Size=0x0088

////////////////////////////////////////
// RuntimeId: 03558
// TypeInfo:  0x00000001420DC8B0
struct Plane
{
	float m_x; //0x0000
	float m_y; //0x0004
	float m_z; //0x0008
	float m_w; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03556
// TypeInfo:  0x00000001420DC830
struct Quat
{
	float m_x; //0x0000
	float m_y; //0x0004
	float m_z; //0x0008
	float m_w; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 09715
// TypeInfo:  0x00000001427F9880
struct AmbientWaveSettings
{
	SplineCurve m_WindDistribution; //0x0000
	float m_WaveAmplitude; //0x00E0
	float m_WindSpeed; //0x00E4
	float m_WindAngle; //0x00E8
	float m_MinWavelength; //0x00EC
	float m_LargeWaveReduction; //0x00F0
	float m_FoamHalfLife; //0x00F4
	float m_FoamThreshold; //0x00F8
	float m_FoamMaxValue; //0x00FC
};//Size=0x0100

////////////////////////////////////////
// RuntimeId: 09544
// TypeInfo:  0x00000001427F5738
struct BulletHitInfo
{
	Vec3 m_Direction; //0x0000
	Vec3 m_SpawnPosition; //0x0010
	Vec3 m_HitPosition; //0x0020
	UnlockAssetBase* m_WeaponUnlockAsset; //0x0030
	AntHitReactionWeaponType m_WeaponType; //0x0038
	__int32 m_BoneType; //0x003C
	__int32 m_ShooterPlayerId; //0x0040
	bool m_ShooterIsAIPlayer; //0x0044
	char _0x0045[11];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 08800
// TypeInfo:  0x00000001427E47C8
struct LensFlareElement
{
	Vec4 m_SizeOccluderCurve; //0x0000
	Vec4 m_SizeScreenPosCurve; //0x0010
	Vec4 m_SizeAngleCurve; //0x0020
	Vec4 m_SizeCamDistCurve; //0x0030
	Vec4 m_AlphaOccluderCurve; //0x0040
	Vec4 m_AlphaScreenPosCurve; //0x0050
	Vec4 m_AlphaAngleCurve; //0x0060
	Vec4 m_AlphaCamDistCurve; //0x0070
	Vec4 m_RotationDistCurve; //0x0080
	SurfaceShaderBaseAsset* m_Shader; //0x0090
	float m_RayDistance; //0x0098
	Vec2 m_Size; //0x009C
	float m_SizeCamDistMax; //0x00A4
	float m_AlphaCamDistMax; //0x00A8
	float m_RotationLocal; //0x00AC
	float m_RotationDistMultiplier; //0x00B0
	bool m_RotationAlignedToRay; //0x00B4
	char _0x00B5[11];
};//Size=0x00C0

////////////////////////////////////////
// RuntimeId: 03548
// TypeInfo:  0x0000000142767FB0
struct UIPopupUpdateMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 03547
// TypeInfo:  0x0000000142767FD0
struct UIPopupHideMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 03546
// TypeInfo:  0x0000000142767FF0
struct UIPopupShowMessage
{
	char _0x0000[104];
};//Size=0x0068

////////////////////////////////////////
// RuntimeId: 03545
// TypeInfo:  0x0000000142768010
struct UITriggerPopupHideMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03544
// TypeInfo:  0x0000000142768030
struct UITriggerPopupShowMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 03543
// TypeInfo:  0x00000001427681F0
struct UIPopupTextInput
{
	char* m_Id; //0x0000
	char* m_Label; //0x0008
	char* m_DefaultValue; //0x0010
	bool m_IsPassword; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03531
// TypeInfo:  0x0000000142768210
struct UILevelSpecificPageHeader
{
	char* m_LevelNameSID; //0x0000
	char* m_Header; //0x0008
	char* m_SubHeader; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03511
// TypeInfo:  0x0000000142768230
struct UIButton
{
	char* m_ButtonLabel; //0x0000
	char* m_ButtonId; //0x0008
	bool m_IsPremium; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03513
// TypeInfo:  0x0000000142768070
struct UIButtonSet
{
	Array<UIButton> m_Buttons; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03493
// TypeInfo:  0x0000000142768090
struct DefaultSelectionItem
{
	UIDataSourceInfo m_DefaultSelectionQuery; //0x0000
	__int32 m_DefaultSelectionIndex; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03503
// TypeInfo:  0x0000000142768270
struct StaticListItem
{
	char* m_ItemName; //0x0000
	char* m_ItemIndex; //0x0008
	UISimpleDataSource m_DynamicDisable; //0x0010
	UISimpleDataSource m_DynamicNewContent; //0x0020
	bool m_AppendPlatformToSID; //0x0030
	bool m_ExcludeInRetail; //0x0031
	char _0x0032[6];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 03507
// TypeInfo:  0x0000000142768250
struct NestedList
{
	char* m_Label; //0x0000
	char* m_Index; //0x0008
	UIDataSourceInfo m_ListDataSource; //0x0010
	UIDataSourceInfo m_DynamicShowList; //0x0028
	Array<char*> m_StaticItems; //0x0040
	DefaultSelectionItem m_DefaultHighlighted; //0x0048
	UIListRowType m_RowType; //0x0068
	bool m_UseAsNormalListRows; //0x006C
	bool m_HiddenOnPC; //0x006D
	bool m_HiddenOnXenon; //0x006E
	bool m_HighLightOnUpdate; //0x006F
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 03477
// TypeInfo:  0x0000000142768290
struct HudCameraShakeParams
{
	float m_WeaponDispersionMin; //0x0000
	float m_WeaponDispersionMax; //0x0004
	float m_WeaponDispersionScale; //0x0008
	unsigned __int32 m_WeaponDispersionFilterSize; //0x000C
	float m_JumpEffectDurationMin; //0x0010
	float m_JumpEffectDurationMax; //0x0014
	float m_JumpEffectMin; //0x0018
	float m_JumpEffectMax; //0x001C
	float m_LandEffectDurationMin; //0x0020
	float m_LandEffectDurationMax; //0x0024
	float m_LandEffectMin; //0x0028
	float m_LandEffectMax; //0x002C
	unsigned __int32 m_JumpAndLandEffectFilterSize; //0x0030
	float m_CameraShakeMinAngle; //0x0034
	float m_CameraShakeMaxAngle; //0x0038
	float m_CameraShakeXScale; //0x003C
	float m_CameraShakeYScale; //0x0040
	unsigned __int32 m_CameraShakeFilterSize; //0x0044
	float m_WeaponLagXScale; //0x0048
	float m_WeaponLagYScale; //0x004C
	unsigned __int32 m_LagFilterSize; //0x0050
	float m_DisplacementPivotZ; //0x0054
	float m_MaxDisplacementAngle; //0x0058
	float m_MaxDisplacementZ; //0x005C
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 03457
// TypeInfo:  0x00000001427682B0
struct UITooltipLine
{
	__int32 m_InputAction; //0x0000
	UIInputActionAxisDisplay m_Axis; //0x0004
	char* m_Description; //0x0008
	bool m_HideWhenMissingIcon; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03451
// TypeInfo:  0x00000001427682D0
struct UIMouseButtonsGroup
{
	bool m_IsWin32; //0x0000
	bool m_IsXenon; //0x0001
	bool m_IsPS3; //0x0002
	bool m_IsDurango; //0x0003
	bool m_IsOrbis; //0x0004
};//Size=0x0005

////////////////////////////////////////
// RuntimeId: 03401
// TypeInfo:  0x00000001427680D0
struct UITextureAtlasInfo
{
	Vec2 m_MinUv; //0x0000
	Vec2 m_MaxUv; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03447
// TypeInfo:  0x0000000142768310
struct UIKeysButtonsGroup
{
	bool m_IsWin32; //0x0000
	bool m_IsXenon; //0x0001
	bool m_IsPS3; //0x0002
	bool m_IsDurango; //0x0003
	bool m_IsOrbis; //0x0004
};//Size=0x0005

////////////////////////////////////////
// RuntimeId: 03445
// TypeInfo:  0x0000000142768330
struct UIKeysButtonTexture
{
	InputDeviceKeys m_Key; //0x0000
	UITextureAtlasInfo m_AtlasInfo; //0x0004
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03443
// TypeInfo:  0x0000000142768350
struct UIPadButtonsGroup
{
	bool m_IsWin32; //0x0000
	bool m_IsXenon; //0x0001
	bool m_IsPS3; //0x0002
	bool m_IsDurango; //0x0003
	bool m_IsOrbis; //0x0004
};//Size=0x0005

////////////////////////////////////////
// RuntimeId: 03441
// TypeInfo:  0x0000000142768370
struct UIPadButtonTexture
{
	InputDevicePadButtons m_PadButton; //0x0000
	UITextureAtlasInfo m_AtlasInfo; //0x0004
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03439
// TypeInfo:  0x0000000142768390
struct UIAxesButtonsGroup
{
	bool m_IsWin32; //0x0000
	bool m_IsXenon; //0x0001
	bool m_IsPS3; //0x0002
	bool m_IsDurango; //0x0003
	bool m_IsOrbis; //0x0004
};//Size=0x0005

////////////////////////////////////////
// RuntimeId: 03437
// TypeInfo:  0x00000001427683B0
struct UIAxesButtonTexture
{
	InputDeviceAxes m_Axis; //0x0000
	UITextureAtlasInfo m_AtlasInfo; //0x0004
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03431
// TypeInfo:  0x00000001427683F0
struct UICreditsColumn
{
	char* m_Text; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03433
// TypeInfo:  0x00000001427683D0
struct UICreditsRow
{
	UICreditsTextType m_TextType; //0x0000
	char _0x0004[4];
	Array<UICreditsColumn> m_Columns; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03427
// TypeInfo:  0x0000000142768410
struct UIMinimapData
{
	float m_WorldRotation; //0x0000
	float m_AirRadarRange; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03425
// TypeInfo:  0x0000000142768430
struct UIMinimapDistanceFieldParams
{
	Vec4 m_ColorTint; //0x0000
	Vec4 m_OutlineColor; //0x0010
	UIDistanceFieldAsset* m_DistanceField; //0x0020
	float m_AlphaThreshold; //0x0028
	float m_DistanceScale; //0x002C
	float m_OutlineInner; //0x0030
	float m_OutlineOuter; //0x0034
	char _0x0038[8];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 03415
// TypeInfo:  0x0000000142768490
struct UIMinimapIconUv
{
	Vec2 m_MinUv; //0x0000
	Vec2 m_MaxUv; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03417
// TypeInfo:  0x0000000142768470
struct UIMinimapIconTextureState
{
	UIIconMode m_Mode; //0x0000
	UIIconState m_State; //0x0004
	float m_FrameRate; //0x0008
	char _0x000C[4];
	Array<UIMinimapIconUv> m_TextureInfos; //0x0010
	bool m_ShouldRotate; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03419
// TypeInfo:  0x0000000142768450
struct UIMinimapIconTexture
{
	UIHudIcon m_IconType; //0x0000
	char _0x0004[4];
	char* m_Name; //0x0008
	Array<UIMinimapIconTextureState> m_States; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03449
// TypeInfo:  0x00000001427682F0
struct UIMouseButtonTexture
{
	InputDeviceMouseButtons m_MouseButton; //0x0000
	UITextureAtlasInfo m_AtlasInfo; //0x0004
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 03389
// TypeInfo:  0x00000001427680F0
struct SuppressionReactionData
{
	float m_SuppressionHighThreshold; //0x0000
	float m_SuppressionLowThreshold; //0x0004
	float m_SuppressionUIThreshold; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 03249
// TypeInfo:  0x00000001427684B0
struct ScoringBucketModifierData
{
	ScoringBucket m_Bucket; //0x0000
	float m_Modifier; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03247
// TypeInfo:  0x00000001427684D0
struct ScoringBucketUnlockData
{
	unsigned __int32 m_PointsNeeded; //0x0000
	char _0x0004[4];
	BasicUnlockInfo m_UnlockInfo; //0x0008
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 03237
// TypeInfo:  0x0000000142768510
struct MapRotationEntry
{
	char* m_ShortGameModeName; //0x0000
	char* m_FullGameModeName; //0x0008
	char* m_MapName; //0x0010
	char* m_FullMapName; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03239
// TypeInfo:  0x00000001427684F0
struct MapRotationConfig
{
	__int32 m_MapRotationId; //0x0000
	char _0x0004[4];
	Array<GamePlatform> m_Platforms; //0x0008
	char* m_NameSid; //0x0010
	char* m_DescSid; //0x0018
	char* m_Mod; //0x0020
	char* m_Key; //0x0028
	Array<MapRotationEntry> m_MapRotation; //0x0030
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 03235
// TypeInfo:  0x0000000142768530
struct SettingCategory
{
	unsigned __int32 m_CategoryId; //0x0000
	char _0x0004[4];
	char* m_NameSid; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03229
// TypeInfo:  0x0000000142768590
struct SettingRange
{
	char* m_Key; //0x0000
	unsigned __int32 m_Min; //0x0008
	unsigned __int32 m_Max; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03231
// TypeInfo:  0x0000000142768570
struct RSPPlatformSettingRange
{
	Array<GamePlatform> m_Platforms; //0x0000
	Array<SettingRange> m_Ranges; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03233
// TypeInfo:  0x0000000142768550
struct SettingsRangeConfig
{
	char* m_Key; //0x0000
	Array<SettingRange> m_Ranges; //0x0008
	Array<RSPPlatformSettingRange> m_PlatformRanges; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03223
// TypeInfo:  0x00000001427685F0
struct LockedSettingConfig
{
	char* m_Key; //0x0000
	unsigned __int32 m_Value; //0x0008
	bool m_ValidateSetting; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03225
// TypeInfo:  0x00000001427685D0
struct RSPPlatformSetting
{
	Array<GamePlatform> m_Platforms; //0x0000
	Array<LockedSettingConfig> m_LockedSettings; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03227
// TypeInfo:  0x00000001427685B0
struct PresetTypeConfig
{
	__int32 m_PresetId; //0x0000
	char _0x0004[4];
	char* m_Key; //0x0008
	char* m_NameSid; //0x0010
	char* m_DescSid; //0x0018
	char* m_ServerType; //0x0020
	Array<LockedSettingConfig> m_LockedSettings; //0x0028
	Array<RSPPlatformSetting> m_PlatformSettings; //0x0030
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 03221
// TypeInfo:  0x0000000142768610
struct SettingConfig
{
	char* m_Key; //0x0000
	char* m_NameSid; //0x0008
	char* m_DescSid; //0x0010
	unsigned __int32 m_CategoryId; //0x0018
	char _0x001C[4];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 03205
// TypeInfo:  0x0000000142768630
struct StatSpamSetting
{
	StatEvent m_Event; //0x0000
	unsigned __int32 m_AmountLimit; //0x0004
	float m_TimeLimit; //0x0008
	bool m_PlayerToPlayer; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03199
// TypeInfo:  0x00000001427681D0
struct SkillLevelComponent
{
	float m_MaxValue; //0x0000
	float m_Weight; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03181
// TypeInfo:  0x000000014275C228
struct UILevelLocation
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 03153
// TypeInfo:  0x000000014275C248
struct GameModeVariation
{
	char* m_Identifier; //0x0000
	char* m_Name; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03139
// TypeInfo:  0x000000014275C268
struct SquadIcon
{
	char* m_Black; //0x0000
	char* m_White; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 03103
// TypeInfo:  0x000000014275C288
struct UIPerformanceMetricSettings
{
	UIPerformanceMetric m_MetricType; //0x0000
	float m_HighThreshold; //0x0004
	float m_LowThreshold; //0x0008
	char _0x000C[4];
	char* m_GoodSid; //0x0010
	char* m_MediumSid; //0x0018
	char* m_BadSid; //0x0020
	char* m_GoodHeaderSid; //0x0028
	char* m_MediumHeaderSid; //0x0030
	char* m_BadHeaderSid; //0x0038
	bool m_LessIsBetter; //0x0040
	char _0x0041[7];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 03081
// TypeInfo:  0x000000014275BD28
struct UICustomizationDisplay
{
	Array<UICustomizationCategoryOrdering*> m_CategoryOrdering; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 03039
// TypeInfo:  0x000000014275C2A8
struct TitanScoringInfoState
{
	char* m_ShipBarOutlineTexture; //0x0000
	char* m_ShipBarFillTexture; //0x0008
	float m_PulseInterval; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 03029
// TypeInfo:  0x000000014275C2C8
struct OverrideVideoData
{
	MovieTextureAsset* m_Video; //0x0000
	GamePlatform m_Platform; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02999
// TypeInfo:  0x000000014275C2E8
struct CellTemplateData
{
	char* m_MappingID; //0x0000
	UIWidgetBlueprint* m_WidgetTemplate; //0x0008
	UIServerFilterType m_FilterMapping; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02971
// TypeInfo:  0x000000014275C328
struct UIInputConceptFilterData
{
	InputConceptIdentifiers m_First; //0x0000
	InputConceptIdentifiers m_Last; //0x0004
	bool m_IncludeThisRange; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 02973
// TypeInfo:  0x000000014275C308
struct UIOptionKeyBindingsType
{
	char* m_ActivatorEventName; //0x0000
	char* m_ID; //0x0008
	Array<UIInputConceptFilterData> m_Filters; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02969
// TypeInfo:  0x000000014275C348
struct UIOptionTableColumn
{
	float m_widthMin; //0x0000
	float m_expandWeight; //0x0004
	bool m_rightSpacing; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 02961
// TypeInfo:  0x000000014275BD48
struct UIOptionsConsoleControlsTextFieldMappings
{
	Array<UIOptionControlTextFieldMapping_NonChanging*> m_NonChanging; //0x0000
	Array<UIOptionControlTextFieldMapping_UnaryChanging*> m_UnaryChanging; //0x0008
	Array<UIOptionControlTextFieldMapping_BothChanging*> m_BothChanging; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02949
// TypeInfo:  0x000000014275C368
struct UIOptionsOption
{
	ProfileOptionData* m_OptionData; //0x0000
	char* m_PlayerShownName; //0x0008
	char* m_Description; //0x0010
	UIElementInclusionSettings m_Inclusion; //0x0018
	char* m_VisibilityPropertyName; //0x0030
	UIOptionsSpecialCase m_SpecialCase; //0x0038
	char _0x003C[4];
	char* m_OnLabel; //0x0040
	char* m_OffLabel; //0x0048
	char* m_EventName; //0x0050
	UIOptionsSliderDisplay m_SliderDisplayMode; //0x0058
	char _0x005C[4];
	CustomOptionData* m_CustomData; //0x0060
	bool m_IsButton; //0x0068
	bool m_ApplyOnChange; //0x0069
	char _0x006A[6];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 02943
// TypeInfo:  0x000000014275C3A8
struct SquadDeployGameModeData
{
	SquadDeployGameMode m_GameMode; //0x0000
	char _0x0004[4];
	char* m_Experience; //0x0008
	__int32 m_CommanderCount; //0x0010
	bool m_Disabled; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02945
// TypeInfo:  0x000000014275C388
struct SquadDeployMapPackData
{
	SquadDeployMapPack m_MapPack; //0x0000
	char _0x0004[4];
	char* m_License; //0x0008
	Array<SquadDeployGameModeData> m_SupportedGameModes; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02927
// TypeInfo:  0x000000014275C3C8
struct UITabBarButton
{
	char* m_Sid; //0x0000
	char* m_OnSelectedOutputEvent; //0x0008
	char* m_VisibleProperty; //0x0010
	char* m_SelectableProperty; //0x0018
	char* m_NewContentProperty; //0x0020
	bool m_ButtonSelectable; //0x0028
	char _0x0029[7];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 02921
// TypeInfo:  0x000000014275BD88
struct UIWorldIconZoneFloats
{
	float m_Interaction; //0x0000
	float m_Critical; //0x0004
	float m_Close; //0x0008
	float m_Far; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02923
// TypeInfo:  0x000000014275BD68
struct UIWorldIconFadeConfiguration
{
	UIWorldIconZoneFloats m_ZoneFadeValues; //0x0000
	UIWorldIconZoneFloats m_ZoneLookAtFadeValues; //0x0010
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 02901
// TypeInfo:  0x000000014275BDA8
struct BFUIColorizationData
{
	BFUIColorizationMode m_ColorizationMode; //0x0000
	UIIconState m_IconState; //0x0004
	UIIconState m_SpectatorIconState; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 02889
// TypeInfo:  0x000000014275BDC8
struct UIAirRadarConfiguration
{
	float m_RadarSensitivity; //0x0000
	float m_HeatSensitivity; //0x0004
	bool m_TrackLaserPaintedObjects; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 02887
// TypeInfo:  0x000000014275BDE8
struct UIChatConfiguration
{
	UICppScreenData* m_ChatScreenData; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 02885
// TypeInfo:  0x000000014275BE08
struct UIMinimapIconConfiguration
{
	UIElementColor m_BgCol; //0x0000
	UIElementFontStyle* m_SmallFont; //0x0020
	char _0x0028[8];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 02883
// TypeInfo:  0x000000014275BE28
struct UIDeployConfiguration
{
	UIElementFontStyle* m_SpawnLabelFont; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 02873
// TypeInfo:  0x000000014275BEA8
struct UILockingConfiguration
{
	UIElementColor m_TextColor; //0x0000
	UIElementFontStyle* m_Font; //0x0020
	float m_TextScale; //0x0028
	float m_TextOffset; //0x002C
	float m_DistanceScale; //0x0030
	float m_DistanceMaxScaleMod; //0x0034
	char* m_DefaultTargetIcon; //0x0038
	char* m_DefaultChevronIcon; //0x0040
	__int32 m_LockingQuadSpacingStart; //0x0048
	__int32 m_LockedQuadSpacing; //0x004C
	__int32 m_LockTextOffset; //0x0050
	char _0x0054[4];
	char* m_LockedText; //0x0058
	char* m_LockedGuidingText; //0x0060
	char* m_NotLockedGuidingText; //0x0068
	__int32 m_DistanceTextOffset; //0x0070
	float m_LockingBlinkRate; //0x0074
	__int32 m_PulseTargetChevronSpacing; //0x0078
	float m_PulseDuration; //0x007C
	float m_UnavalibleAlpha; //0x0080
	char _0x0084[12];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 02879
// TypeInfo:  0x000000014275BE68
struct UIWorldZoneDistanceConfiguration
{
	float m_CriticalDistance; //0x0000
	float m_CloseDistance; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 02875
// TypeInfo:  0x000000014275BE88
struct UIShieldIconConfiguration
{
	float m_BlinkRate; //0x0000
	char _0x0004[4];
	char* m_PortableGadgetIcon; //0x0008
	char* m_PortableShieldIcon; //0x0010
	char* m_VehicleShieldIcon; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 02871
// TypeInfo:  0x000000014275BEC8
struct UIColorConfiguration
{
	UIElementColor m_Neutral; //0x0000
	UIElementColor m_Team; //0x0020
	UIElementColor m_Squad; //0x0040
	UIElementColor m_Enemy; //0x0060
	UIElementColor m_Team1; //0x0080
	UIElementColor m_Team2; //0x00A0
	UIElementColor m_Team3; //0x00C0
	UIElementColor m_Team4; //0x00E0
	UIElementColor m_Commander; //0x0100
	UIElementColor m_Spectator; //0x0120
};//Size=0x0140

////////////////////////////////////////
// RuntimeId: 02861
// TypeInfo:  0x000000014275BF48
struct UIGrenadeConfiguration
{
	float m_IconVerticalOffset; //0x0000
	float m_FadeStartDist; //0x0004
	float m_DisappearDist; //0x0008
	float m_WarningFadeStartDist; //0x000C
	float m_WarningDisappearDist; //0x0010
	float m_MaxScaleAtDist; //0x0014
	float m_MinScaleAtDist; //0x0018
	float m_MaxScale; //0x001C
	float m_MinScale; //0x0020
	float m_MagneticEdgeOffsetMultiplierNear; //0x0024
	float m_MagneticEdgeOffsetMultiplierFar; //0x0028
	float m_MagneticEdgeNearDist; //0x002C
	float m_MagneticEdgeFarDist; //0x0030
};//Size=0x0034

////////////////////////////////////////
// RuntimeId: 02863
// TypeInfo:  0x000000014275BF28
struct UINametagVisibilityValues
{
	bool m_VisibleClose; //0x0000
	bool m_VisibleFar; //0x0001
};//Size=0x0002

////////////////////////////////////////
// RuntimeId: 02865
// TypeInfo:  0x000000014275BF08
struct UINametagVisibilityConfiguration
{
	UINametagVisibilityValues m_LookAtVisibility; //0x0000
	UINametagVisibilityValues m_Visibility; //0x0002
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 02867
// TypeInfo:  0x000000014275BEE8
struct UINametagBehavior
{
	float m_CloseDistance; //0x0000
	bool m_MagneticToScreen; //0x0004
	UINametagVisibilityConfiguration m_IconVisibility; //0x0005
	UINametagVisibilityConfiguration m_NameVisibility; //0x0009
	UINametagVisibilityConfiguration m_HealthVisibility; //0x000D
	UINametagVisibilityConfiguration m_DistanceVisibility; //0x0011
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02881
// TypeInfo:  0x000000014275BE48
struct UIWorldIconConfiguration
{
	UILockingConfiguration m_LockingCfg; //0x0000
	UIColorConfiguration m_StdColors; //0x0090
	UINametagConfiguration* m_NametagCfg; //0x01D0
	UINametagConfiguration* m_SPNametagCfg; //0x01D8
	UINametagConfiguration* m_HardcoreNametagCfg; //0x01E0
	UIShieldIconConfiguration m_ShieldIconCfg; //0x01E8
	Array<UIColorConfiguration> m_ColorBlindModes; //0x0208
	UIWorldZoneDistanceConfiguration m_ZoneDistanceCfg; //0x0210
	float m_RequestIconBlinkRate; //0x0218
	UIGrenadeConfiguration m_GrenadeCfg; //0x021C
	UIElementFontStyle* m_MapFont; //0x0250
	UIElementFontStyle* m_HudFont; //0x0258
};//Size=0x0260

////////////////////////////////////////
// RuntimeId: 02835
// TypeInfo:  0x000000014275BF68
struct UIGridStepperConfig
{
	UIElementScrollbarStyle* m_ScrollBarStyle; //0x0000
	unsigned __int32 m_ScrollbarWidth; //0x0008
	unsigned __int32 m_ScrollbarMargin; //0x000C
	__int32 m_ScrollbarTopOffset; //0x0010
	__int32 m_ScrollbarBottomOffset; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02735
// TypeInfo:  0x000000014275C3E8
struct UIBattledashHorisontalListData
{
	unsigned __int32 m_Index; //0x0000
	char _0x0004[4];
	char* m_Name; //0x0008
	char* m_TextureId; //0x0010
	char* m_IdString; //0x0018
	char* m_Description; //0x0020
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 02731
// TypeInfo:  0x000000014275C408
struct UIAutoListCategoryData
{
	UIAutoListType m_listtype; //0x0000
	char _0x0004[4];
	char* m_idString; //0x0008
	char* m_displayTitle; //0x0010
	char* m_EmptyListDescription; //0x0018
	bool m_showEmptyCategory; //0x0020
	char _0x0021[7];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 02723
// TypeInfo:  0x000000014275C428
struct UIBattledashDetailPane
{
	char* m_title; //0x0000
	char* m_value; //0x0008
	char* m_textureId; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02715
// TypeInfo:  0x000000014275C448
struct UIBattledashIndicatorData
{
	char* m_Name; //0x0000
	char* m_TextureId; //0x0008
	float m_IndicatorFadeTime; //0x0010
	float m_OverrideIconSize; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02687
// TypeInfo:  0x000000014275C468
struct UINPXTooltipWidgetLayout
{
	UILayoutMode m_LayoutMode; //0x0000
	UIElementOffset m_Offset; //0x0004
	UIElementAnchor m_Anchor; //0x000C
	UIElementOffset m_Position; //0x0014
	UIElementRectExpansion m_Expansion; //0x001C
};//Size=0x002C

////////////////////////////////////////
// RuntimeId: 02669
// TypeInfo:  0x000000014275BF88
struct UIScoreboardColumnStyle
{
	float m_Width; //0x0000
	UIElementAlignment m_TextAlignment; //0x0004
	float m_TextOffset; //0x0008
	bool m_HasLine; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02657
// TypeInfo:  0x000000014275C488
struct UICommoRoseButtonInfo
{
	char* m_ButtonId; //0x0000
	char* m_ButtonText; //0x0008
	char* m_ChatText; //0x0010
	ChatChannelType m_ChatChannel; //0x0018
	char _0x001C[4];
	UIElementAction* m_Action; //0x0020
	char* m_IconTextureId; //0x0028
	UICommoRoseTextAlignment m_TextAlignment; //0x0030
	UIElementRect m_InactiveRect; //0x0034
	UIElementRect m_ActiveRect; //0x0044
	char _0x0054[4];
	UIElementFontStyle* m_InactiveFontStyle; //0x0058
	UIElementFontStyle* m_ActiveFontStyle; //0x0060
	bool m_UseLocalRect; //0x0068
	bool m_IsSelectable; //0x0069
	char _0x006A[6];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 02611
// TypeInfo:  0x000000014275BFA8
struct UIDeactivateCameraMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 02610
// TypeInfo:  0x000000014275BFC8
struct UIDeployScreenUpdateCameraMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 02609
// TypeInfo:  0x000000014275BFE8
struct UIMapWidgetHelperData
{
	Vec4 m_MapFocusMargins; //0x0000
	UIVisualWidgetType m_VisualWidgetType; //0x0010
	char _0x0014[12];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 02569
// TypeInfo:  0x000000014275C008
struct BFServerConfigurationData
{
	unsigned __int32 m_ScoreMultiplier; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 02571
// TypeInfo:  0x000000014275C4A8
struct BFServerConfigurationSchedule
{
	Array<char*> m_Licenses; //0x0000
	Array<char*> m_Levels; //0x0008
	BFServerConfigurationData m_Data; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02539
// TypeInfo:  0x000000014275C4C8
struct GameConfigurationContentMapping
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	char* m_License; //0x0008
	Array<char*> m_Content; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02515
// TypeInfo:  0x000000014275C048
struct PeerCreateGameParameters
{
	GameParametersData* m_Base; //0x0000
	unsigned __int32 m_PlayerCapacity; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02511
// TypeInfo:  0x000000014275C4E8
struct NucleusPlatformConfiguration
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	char* m_ClientId; //0x0008
	char* m_ClientSecret; //0x0010
	char* m_LoginScope; //0x0018
	char* m_ClientRedirectUrl; //0x0020
	char* m_DisplayType; //0x0028
	char* m_BlazeServerClientId; //0x0030
	char* m_BlazeServerRedirectUrl; //0x0038
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 02509
// TypeInfo:  0x000000014275C508
struct NucleusEnvironmentConfiguration
{
	NucleusEnvironment m_Env; //0x0000
	char _0x0004[4];
	char* m_BaseUrl; //0x0008
	char* m_NucleusClientId; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02455
// TypeInfo:  0x000000014275C528
struct PCAchievementSettings
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 02453
// TypeInfo:  0x000000014275C068
struct DurangoAchievementSettings
{
	unsigned __int32 m_CompletionValue; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 02447
// TypeInfo:  0x000000014275C548
struct AwardStarNameInstance
{
	char* m_Name; //0x0000
	StatsCategoryBaseData* m_Category; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02439
// TypeInfo:  0x000000014275C568
struct EventScaleData
{
	StatEvent m_Event; //0x0000
	float m_Scale; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 02437
// TypeInfo:  0x000000014275C588
struct CriteriaAward
{
	AwardData* m_Award; //0x0000
	unsigned __int32 m_Count; //0x0008
	char _0x000C[4];
	char* m_Sid; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02431
// TypeInfo:  0x000000014275C5A8
struct CriteriaStarCategoryInstance
{
	char* m_Name; //0x0000
	StatsCategoryBaseData* m_ParamX; //0x0008
	StatsCategoryBaseData* m_ParamY; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02413
// TypeInfo:  0x000000014275C5C8
struct AIProximityReactionsBinding
{
	AntRef m_AIReaction; //0x0000
	AntRef m_AIExplosionReaction; //0x0014
	AntRef m_AIExplosionForce; //0x0028
	AntRef m_AIStunReaction; //0x003C
	AntRef m_AIStunReactionRandomFactor; //0x0050
	AntRef m_AIReactionDirection; //0x0064
	AntRef m_IsPanicking; //0x0078
	AntRef m_FireNearby; //0x008C
	AntRef m_AimUpAndDown; //0x00A0
	AntRef m_FocusAimScale; //0x00B4
	AntRef m_FocusAiming; //0x00C8
	AntRef m_EnableProceduralHeadAim; //0x00DC
	AntRef m_KillFromAnimation; //0x00F0
	AntRef m_PlayerAnimationKill; //0x0104
	AntRef m_PlayerInitiatedRagdoll; //0x0118
	AntRef m_AISuppressed; //0x012C
	AntRef m_HumanAwareness; //0x0140
	AntRef m_HumanIsClose; //0x0154
	AntRef m_HumanTargetYaw; //0x0168
	AntRef m_LookAtHuman; //0x017C
	AntRef m_RetriggerIdle; //0x0190
	AntRef m_HasWantedPrecision; //0x01A4
	AntRef m_TargetVisible; //0x01B8
	AntRef m_TargetSpotted; //0x01CC
	AntRef m_TargetDistance; //0x01E0
	AntRef m_CruiseSpeedLevel; //0x01F4
	AntRef m_DrasticAimYawChange; //0x0208
};//Size=0x021C

////////////////////////////////////////
// RuntimeId: 02395
// TypeInfo:  0x000000014275C108
struct ScenarioTaskData
{
	Vec3 m_StartPoint; //0x0000
	Vec3 m_EndPointWorldOffset; //0x0010
	PlayAnimationData* m_PlayAnimation; //0x0020
	float m_WorldAngle; //0x0028
	__int32 m_ScenarioId; //0x002C
	__int32 m_ActorId; //0x0030
	__int32 m_PartId; //0x0034
	__int32 m_LevelId; //0x0038
	char _0x003C[4];
	Array<LinearTransform> m_ConnectTransforms; //0x0040
	float m_StartTurnDistance; //0x0048
	float m_StartTimerDistance; //0x004C
	float m_TriggerScenarioDelay; //0x0050
	bool m_TriggerScenario; //0x0054
	bool m_UseClientPosition; //0x0055
	bool m_ForceWaitForAnimation; //0x0056
	bool m_OvershootWaypoint; //0x0057
	char _0x0058[8];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 02393
// TypeInfo:  0x000000014275C128
struct AILocoCoverTaskData
{
	Vec3 m_WantedPos; //0x0000
	Vec3 m_ThreatPosition; //0x0010
	AntCoverEnum m_CoverType; //0x0020
	AntPoseEnum m_CoverPose; //0x0024
	float m_WaitTime; //0x0028
	float m_WorldAngle; //0x002C
	CoverPeekType m_PeekOut; //0x0030
	CoverIdleType m_IdleBehavior; //0x0034
	AntPoseEnum m_ExitPose; //0x0038
	float m_OffsetLength; //0x003C
	CoverEnterStrategy m_EnterStrategy; //0x0040
	float m_ExitAngle; //0x0044
	float m_DistanceToNextWaypoint; //0x0048
	float m_AlignOffsetAlong; //0x004C
	float m_AlignOffsetPerpendicular; //0x0050
	CoverExitStyle m_ExitStyle; //0x0054
	CoverFireType m_PrepareFireType; //0x0058
	bool m_ForceExitCover; //0x005C
	bool m_UseClientPosition; //0x005D
	char _0x005E[2];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 02379
// TypeInfo:  0x000000014275C168
struct AILocoBaseTaskData
{
	AntPoseEnum m_PoseChangeMovingTowards; //0x0000
	AntAttentionStateEnum m_AttentionChangeMovingTowards; //0x0004
	AntSpeedLevel m_SpeedChangeMovingTowards; //0x0008
	AntPoseEnum m_PoseChange; //0x000C
	AntAttentionStateEnum m_AttentionStateChange; //0x0010
	AntSpeedLevel m_SpeedLevelChange; //0x0014
	float m_Radius; //0x0018
	bool m_IsScripted; //0x001C
	char _0x001D[3];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 02377
// TypeInfo:  0x000000014275C188
struct AILocoMoveTaskData
{
	Vec3 m_WantedPos; //0x0000
	float m_WaitTime; //0x0010
	float m_WorldAngle; //0x0014
	AntPoseEnum m_EnterPose; //0x0018
	AntPoseEnum m_ExitPose; //0x001C
	float m_AlmostFinishedDistance; //0x0020
	bool m_OverrideAngle; //0x0024
	bool m_UseClientPosition; //0x0025
	bool m_OnlySignalAlmostFinishedWhenMovingTowardsWaypoint; //0x0026
	char _0x0027[9];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 02375
// TypeInfo:  0x000000014275C1A8
struct AILocoVaultTaskData
{
	Vec3 m_StartPoint; //0x0000
	float m_DistanceBeforeVault; //0x0010
	float m_HeightBeforeVault; //0x0014
	float m_LengthOfVaultableObject; //0x0018
	float m_HeightAfterVault; //0x001C
	float m_DistanceAfterVault; //0x0020
	float m_WorldAngle; //0x0024
	WaypointVaultType m_VaultType; //0x0028
	bool m_UseClientPosition; //0x002C
	char _0x002D[3];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 02365
// TypeInfo:  0x000000014275C1C8
struct AILocoCoverBinding
{
	AntRef m_PrepareFire; //0x0000
	AntRef m_PrepareChangedToTrue; //0x0014
	AntRef m_ThrowGrenade; //0x0028
	AntRef m_PeekOut; //0x003C
	AntRef m_IdleBehindCover; //0x0050
	AntRef m_PeekType; //0x0064
	AntRef m_IdleTypePrevious; //0x0078
	AntRef m_IdleType; //0x008C
	AntRef m_IdleTypeChanged; //0x00A0
	AntRef m_CoverTypeEnum; //0x00B4
	AntRef m_CoverFireStyle; //0x00C8
	AntRef m_EnterCover; //0x00DC
	AntRef m_ExitCover; //0x00F0
	AntRef m_CoverDistanceSmall; //0x0104
	AntRef m_CoverDistanceMedium; //0x0118
	AntRef m_DistanceScale; //0x012C
	AntRef m_AbsoluteDistance; //0x0140
	AntRef m_AngleToNormal; //0x0154
	AntRef m_DirectionToCoverVsAITrajectory; //0x0168
	AntRef m_CoverNormalVsAITrajectory; //0x017C
	AntRef m_OutAngle; //0x0190
	AntRef m_ExitCoverDistance; //0x01A4
	AntRef m_ThreatAngle; //0x01B8
	AntRef m_StopExitCoverOutAround; //0x01CC
	AntRef m_EnterStrategy; //0x01E0
	AntRef m_ExitStyle; //0x01F4
};//Size=0x0208

////////////////////////////////////////
// RuntimeId: 02363
// TypeInfo:  0x000000014275C1E8
struct AILocoVaultBinding
{
	AntRef m_Vault; //0x0000
	AntRef m_DistanceBeforeVault; //0x0014
	AntRef m_HeightBeforeVault; //0x0028
	AntRef m_LengthOfVaultableObject; //0x003C
	AntRef m_HeightAfterVault; //0x0050
	AntRef m_DistanceAfterVault; //0x0064
	AntRef m_VaultType; //0x0078
};//Size=0x008C

////////////////////////////////////////
// RuntimeId: 02361
// TypeInfo:  0x000000014275C208
struct AILocoBinding
{
	AntRef m_LocoTarget; //0x0000
	AntRef m_AttentionState; //0x0014
	AntRef m_EndPoseEnum; //0x0028
	AntRef m_CurrentPoseEnum; //0x003C
	AntRef m_EnterExitPoseEnum; //0x0050
	AntRef m_RunStyle; //0x0064
	AntRef m_TargetWaypointPosition; //0x0078
	AntRef m_TargetWaypointRadius; //0x008C
	AntRef m_TargetSpeedLevel; //0x00A0
	AntRef m_CruiseSpeedLevel; //0x00B4
	AntRef m_EnableProceduralHeadAim; //0x00C8
};//Size=0x00DC

////////////////////////////////////////
// RuntimeId: 02355
// TypeInfo:  0x000000014275C5E8
struct AdvertisementZoneMember
{
	char* m_Identifier; //0x0000
	char* m_Filename; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02351
// TypeInfo:  0x000000014274EA20
struct XdpChallengeData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 02349
// TypeInfo:  0x000000014274EA40
struct XdpHeroStatData
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 02347
// TypeInfo:  0x000000014274EA60
struct XdpStatCodeData
{
	char* m_XdpCode; //0x0000
	char* m_StorageCode; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02343
// TypeInfo:  0x000000014274EA80
struct XdpStatExport
{
	char _0x0000[1];
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 02245
// TypeInfo:  0x000000014274EAC0
struct IngameMenuElementData
{
	char* m_Sid; //0x0000
	char* m_Identifier; //0x0008
	char* m_EnabledFunc; //0x0010
	char* m_VisibleFunc; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 02249
// TypeInfo:  0x000000014274EAA0
struct IngameMenuCategory
{
	IngameMenuCategoryType m_CategoryType; //0x0000
	char _0x0004[4];
	Array<IngameMenuElementData> m_Elements; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02237
// TypeInfo:  0x000000014274EB20
struct UISettingsItem
{
	char* m_NameSid; //0x0000
	UISettingSymbols m_StartEndSymbols; //0x0008
	char _0x000C[4];
	ProfileOptionData* m_Setting; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02239
// TypeInfo:  0x000000014274EB00
struct UISettingsGroup
{
	char* m_NameSid; //0x0000
	__int32 m_ScreenColumn; //0x0008
	char _0x000C[4];
	Array<UISettingsItem> m_SettingsItems; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02241
// TypeInfo:  0x000000014274EAE0
struct UISettingsPage
{
	char* m_NameSid; //0x0000
	Array<UISettingsGroup> m_SettingsGroups; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02227
// TypeInfo:  0x000000014274EB40
struct ScreenshotInfo
{
	char* m_Name; //0x0000
	unsigned __int32 m_CropImageX1; //0x0008
	unsigned __int32 m_CropImageX2; //0x000C
	unsigned __int32 m_CropImageY1; //0x0010
	unsigned __int32 m_CropImageY2; //0x0014
	unsigned __int32 m_ResizeOutputImageWidth; //0x0018
	unsigned __int32 m_ResizeOutputImageHeight; //0x001C
	bool m_CropImage; //0x0020
	bool m_ResizeOutputImage; //0x0021
	char _0x0022[6];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 02205
// TypeInfo:  0x000000014274EB60
struct UILeaderboardData
{
	char* m_Name; //0x0000
	char* m_Description; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02191
// TypeInfo:  0x000000014274EB80
struct ServerInfoSetting
{
	char* m_Key; //0x0000
	char* m_Name; //0x0008
	bool m_IsBool; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02185
// TypeInfo:  0x000000014274EBA0
struct SlotRange
{
	__int32 m_Min; //0x0000
	__int32 m_Max; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 02169
// TypeInfo:  0x000000014274EBC0
struct DataSource
{
	UIComponentData* m_Category; //0x0000
	__int32 m_Value; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 02151
// TypeInfo:  0x000000014274EBE0
struct UIStreamInstallGroup
{
	char* m_MainMenuSid; //0x0000
	char* m_GroupId; //0x0008
	bool m_DisableIfIncomplete; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02111
// TypeInfo:  0x000000014274E9A0
struct SoldierToComponentsReviveMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 02108
// TypeInfo:  0x000000014274E9C0
struct RotateToHitData
{
	float m_RotationSpeedFactor; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 02096
// TypeInfo:  0x000000014274EC00
struct MinimapData
{
	Vec3 m_OverlayColor; //0x0000
	Vec3 m_CameraPosition; //0x0010
	Vec2 m_Position; //0x0020
	float m_AnchorPosHorizontal; //0x0028
	float m_AnchorPosVertical; //0x002C
	Vec2 m_Size; //0x0030
	float m_CameraFov; //0x0038
	float m_CameraDistance; //0x003C
	float m_CameraLookDistance; //0x0040
	float m_OverlayAlpha; //0x0044
	float m_CameraRotation; //0x0048
	__int32 m_InnerZoomFactor; //0x004C
	__int32 m_MaxZoomLevels; //0x0050
	__int32 m_StartZoomLevel; //0x0054
	bool m_RotationFromPlayer; //0x0058
	bool m_PositionFromPlayer; //0x0059
	bool m_CenterOnCombatArea; //0x005A
	char _0x005B[5];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 02078
// TypeInfo:  0x000000014274E9E0
struct ClientRoundOverMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 02069
// TypeInfo:  0x000000014274EC20
struct Minimap2DTile
{
	TextureAsset* m_Texture; //0x0000
	__int32 m_ChildIndex0; //0x0008
	__int32 m_ChildIndex1; //0x000C
	__int32 m_ChildIndex2; //0x0010
	__int32 m_ChildIndex3; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 02057
// TypeInfo:  0x000000014274EC40
struct AreaValueTeam
{
	__int32 m_AreaValue; //0x0000
	TeamId m_Team; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 02053
// TypeInfo:  0x000000014274EC60
struct TicketCountPercentage
{
	__int32 m_MaxPercentOfTicketsLeft; //0x0000
	__int32 m_TicketLossPerMin; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 02009
// TypeInfo:  0x000000014274EC80
struct SimpleAnimationControlBinding
{
	AntRef m_LocoTarget; //0x0000
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 02007
// TypeInfo:  0x000000014274ECA0
struct SupportedShootingBinding
{
	AntRef m_Supported; //0x0000
	AntRef m_SupportedPos; //0x0014
	AntRef m_ForwardVector; //0x0028
	AntRef m_Yaw; //0x003C
	AntRef m_Pitch; //0x0050
	AntRef m_DistToObject; //0x0064
	AntRef m_HeightOfObject; //0x0078
	AntRef m_Undeploying; //0x008C
	AntRef m_AnimatedCamera; //0x00A0
};//Size=0x00B4

////////////////////////////////////////
// RuntimeId: 02005
// TypeInfo:  0x000000014274ECC0
struct SpecialMovesBinding
{
	AntRef m_UseNewVault; //0x0000
	AntRef m_TriggerHighVault; //0x0014
	AntRef m_TriggerUpVault; //0x0028
	AntRef m_TriggerLowVault; //0x003C
	AntRef m_TriggerSlideIntoProne; //0x0050
	AntRef m_TriggerSpecialAnimation; //0x0064
	AntRef m_SpecialAnimationIndex; //0x0078
	AntRef m_ObjectHeight; //0x008C
	AntRef m_ObjectDistance; //0x00A0
	AntRef m_ObjectThickness; //0x00B4
	AntRef m_StartObjectDistanceTimer; //0x00C8
	AntRef m_VaultObjectPositionX; //0x00DC
	AntRef m_VaultObjectPositionZ; //0x00F0
	AntRef m_CancelAnimation; //0x0104
};//Size=0x0118

////////////////////////////////////////
// RuntimeId: 02003
// TypeInfo:  0x000000014274ECE0
struct SoldierParachuteBinding
{
	AntRef m_Enabled; //0x0000
	AntRef m_SteerLeftRight; //0x0014
	AntRef m_AccelerateBrake; //0x0028
	AntRef m_Pitch; //0x003C
	AntRef m_Roll; //0x0050
};//Size=0x0064

////////////////////////////////////////
// RuntimeId: 02001
// TypeInfo:  0x000000014274EA00
struct SoldierEmoteBinding
{
	AntRef m_Speak; //0x0000
	AntRef m_IsSquadLeader; //0x0014
	AntRef m_EmoteSpot; //0x0028
	AntRef m_EmoteOk; //0x003C
	AntRef m_EmoteNeedARide; //0x0050
	AntRef m_EmoteGoGoGo; //0x0064
	AntRef m_EmoteNeedBackup; //0x0078
	AntRef m_EmoteThanks; //0x008C
	AntRef m_EmoteNeedMedic; //0x00A0
	AntRef m_EmoteFollowMe; //0x00B4
	AntRef m_EmoteNeedAmmo; //0x00C8
	AntRef m_EmoteSorry; //0x00DC
	AntRef m_EmoteNo; //0x00F0
	AntRef m_EmoteDefendCapturePoint; //0x0104
	AntRef m_EmoteAttackCapturePoint; //0x0118
	AntRef m_EmoteMoveToPosition; //0x012C
};//Size=0x0140

////////////////////////////////////////
// RuntimeId: 01999
// TypeInfo:  0x000000014274ED00
struct ClimbLadderBinding
{
	AntRef m_ClimbLadderPhase; //0x0000
	AntRef m_ClimbLadderConnectPhase; //0x0014
	AntRef m_ClimbLadderTransitionPhase; //0x0028
	AntRef m_OnLadder; //0x003C
	AntRef m_LadderTopTransition; //0x0050
	AntRef m_FallHigh; //0x0064
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 01995
// TypeInfo:  0x0000000142748060
struct UIScreenActionInputEventMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 01908
// TypeInfo:  0x00000001427482A0
struct ManualDataEntry
{
	GamePlatform m_Platform; //0x0000
	LanguageFormat m_Language; //0x0004
	Array<TextureAsset*> m_Textures; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01890
// TypeInfo:  0x00000001427482E0
struct InspectAnimationTriggerData
{
	AntRef m_Animation; //0x0000
	float m_Probability; //0x0014
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 01892
// TypeInfo:  0x00000001427482C0
struct InspectViewPointData
{
	char* m_ViewPointID; //0x0000
	Array<InspectAnimationTriggerData> m_AnimationTriggers; //0x0008
	Array<AntRef> m_ContinuousAnimationSignal; //0x0010
	float m_LookAtHeight; //0x0018
	float m_Yaw; //0x001C
	float m_Pitch; //0x0020
	float m_Distance; //0x0024
	float m_FovOffset; //0x0028
	float m_AdjustmentYaw; //0x002C
	bool m_Fixed; //0x0030
	char _0x0031[7];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 01870
// TypeInfo:  0x0000000142748080
struct UIMapNavigationData
{
	float m_NearestZoomRange; //0x0000
	Vec2 m_ManualViewCenter; //0x0004
	float m_ManualViewRange; //0x000C
	float m_PanSpeed; //0x0010
	bool m_UseAutoView; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 01864
// TypeInfo:  0x0000000142748320
struct UILevelLoadIconData
{
	char* m_Label; //0x0000
	char* m_IconName; //0x0008
	Vec2 m_Pos; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 01866
// TypeInfo:  0x0000000142748300
struct UILevelLoadGameModeData
{
	char* m_GameModeIdentifier; //0x0000
	unsigned __int32 m_PackageIdentifier; //0x0008
	char _0x000C[4];
	Array<char*> m_BackgroundImagesPath; //0x0010
	Array<UILevelLoadIconData> m_IconData; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 01862
// TypeInfo:  0x00000001427480A0
struct UIGPSPosition
{
	double m_Latitude; //0x0000
	double m_Longitude; //0x0008
	double m_SeaLevelOffset; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 01860
// TypeInfo:  0x00000001427480C0
struct UILevelStatData
{
	char* m_StatEasy; //0x0000
	char* m_StatMedium; //0x0008
	char* m_StatHard; //0x0010
	char* m_StatHardcore; //0x0018
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 01854
// TypeInfo:  0x00000001427480E0
struct UIGeoLongitude
{
	__int32 m_Degrees; //0x0000
	__int32 m_Minuites; //0x0004
	__int32 m_Seconds; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01852
// TypeInfo:  0x0000000142748100
struct UIGeoLatitude
{
	__int32 m_Degrees; //0x0000
	__int32 m_Minuites; //0x0004
	__int32 m_Seconds; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01848
// TypeInfo:  0x0000000142748120
struct SoldierLeaningBinding
{
	AntRef m_Lean; //0x0000
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 01844
// TypeInfo:  0x0000000142748340
struct GameTipData
{
	char* m_Text; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01834
// TypeInfo:  0x0000000142748380
struct GameModeTeamSize
{
	unsigned __int32 m_PlayerCount; //0x0000
	unsigned __int32 m_SquadSize; //0x0004
	unsigned __int32 m_SquadAutoFillLimit; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01836
// TypeInfo:  0x0000000142748140
struct GameModeSize
{
	char* m_Name; //0x0000
	char* m_ShortName; //0x0008
	char* m_MetaIdentifier; //0x0010
	unsigned __int32 m_PlayerCount; //0x0018
	unsigned __int32 m_CommanderCount; //0x001C
	Array<GameModeTeamSize> m_Teams; //0x0020
	unsigned __int32 m_RoundsPerMap; //0x0028
	bool m_ForceSquad; //0x002C
	char _0x002D[3];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 01838
// TypeInfo:  0x0000000142748360
struct GameModeInformation
{
	GamePlatform m_Platform; //0x0000
	char _0x0004[4];
	Array<GameModeSize> m_Sizes; //0x0008
	GameModeSize m_DefaultSize; //0x0010
	bool m_AllowFallbackToDefault; //0x0040
	char _0x0041[7];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 01828
// TypeInfo:  0x00000001427483A0
struct FreeStreamingChunksLoadInfo
{
	char* m_Name; //0x0000
	__int32 m_NumPartitions; //0x0008
	bool m_IsLocalized; //0x000C
	bool m_IsOptional; //0x000D
	char _0x000E[2];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01808
// TypeInfo:  0x00000001427483C0
struct CounterHelper
{
	bool m_dummy; //0x0000
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 01736
// TypeInfo:  0x0000000142748280
struct AntiSpamConfig
{
	float m_DetectionInterval; //0x0000
	unsigned __int32 m_DetectionIntervalMaxMessageCount; //0x0004
	unsigned __int32 m_ServerSideMessageCountTolerance; //0x0008
	unsigned __int32 m_SecondsBlocked; //0x000C
	unsigned __int32 m_ServerSideSecondsBlockedTolerance; //0x0010
	char _0x0014[4];
	char* m_NotificationSid; //0x0018
	char* m_StillBlockedSid; //0x0020
	SoundWaveAsset* m_WarningSound; //0x0028
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 01668
// TypeInfo:  0x0000000142741600
struct GameTweakBlindedBehavior
{
	float m_BlindedTime; //0x0000
	float m_BlindedRadius; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01666
// TypeInfo:  0x0000000142741560
struct GameTweakPanicBehavior
{
	float m_PrePanicTime; //0x0000
	float m_TotalPanicTime; //0x0004
	float m_PanicBlastRadiusPercentage; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01664
// TypeInfo:  0x0000000142741680
struct GameTweakSniper
{
	float m_GlintToShotFiredDelay; //0x0000
	float m_HideAfterShotDelay; //0x0004
	float m_TimeUpBeforeScopeGlint; //0x0008
	float m_TimeHidden; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01662
// TypeInfo:  0x00000001427416E0
struct GameTweakAIDamage
{
	float m_DamageBucketSizeHumanSquad; //0x0000
	float m_DamageBucketSizeFriendlies; //0x0004
	float m_DamageBucketSizeEnemies; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01656
// TypeInfo:  0x00000001427416C0
struct EvasiveBucketTimeSettings
{
	Array<float> m_SprintDamageBucketTimes; //0x0000
	Array<float> m_CrouchDamageBucketTimes; //0x0008
	Array<float> m_ProneDamageBucketTimes; //0x0010
	Array<float> m_MovingVehicleDamageBucketTimes; //0x0018
	Array<float> m_VehicleStillDamageBucketTimes; //0x0020
	float m_SprintSpeed; //0x0028
	float m_MovingVehicleSpeed; //0x002C
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 01650
// TypeInfo:  0x0000000142741700
struct TinyPiecewiseLinearCurve
{
	float m_X0; //0x0000
	float m_Y0; //0x0004
	float m_X1; //0x0008
	float m_Y1; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01660
// TypeInfo:  0x0000000142741720
struct GameTweakBucketDamage
{
	Array<float> m_PlayerDamageBucketTimes; //0x0000
	EvasiveBucketTimeSettings m_EvasiveBucketTimeSettings; //0x0008
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 01654
// TypeInfo:  0x00000001427417E0
struct AccuracyPenaltySettings
{
	float m_SprintMultiplier; //0x0000
	float m_CrouchMultiplier; //0x0004
	float m_ProneMultiplier; //0x0008
	float m_MovingVehicleMultiplier; //0x000C
	float m_VehicleStillMultiplier; //0x0010
	float m_SprintSpeed; //0x0014
	float m_MovingVehicleSpeed; //0x0018
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 01652
// TypeInfo:  0x0000000142741740
struct GameTweakCommon
{
	float m_SensingConeRange; //0x0000
	float m_SensingConeRangeWhenAlerted; //0x0004
	float m_SensingConeAngle; //0x0008
	float m_SensingConeAngleWhenAlerted; //0x000C
	float m_SensingConeAngleAbove; //0x0010
	float m_SensingConeAngleBelow; //0x0014
	float m_SensingShotFiredDistance; //0x0018
	float m_SensingHumanDrivenVehicleDistance; //0x001C
	float m_SensingExplosionDistance; //0x0020
	float m_SensingGrenadeDistance; //0x0024
	TinyPiecewiseLinearCurve m_DistanceToAwareTimeCurveCentral; //0x0028
	float m_AwareCurveCentralAngle; //0x0038
	TinyPiecewiseLinearCurve m_DistanceToAwareTimeCurvePeripheral; //0x003C
	float m_AwareStandingPenaltyMultiplier; //0x004C
	float m_AwareToAlertTime; //0x0050
	float m_HighIntensityRadius; //0x0054
	float m_ConcealmentCoolDownTime; //0x0058
	float m_ConcealmentDisableAtDistance; //0x005C
	float m_PassiveTime; //0x0060
	float m_GrenadeMinimumTime; //0x0064
	float m_GrenadeMaximumTime; //0x0068
	float m_ChargeGrenadeMinimumTime; //0x006C
	float m_ChargeGrenadeMaximumTime; //0x0070
	__int32 m_SimultaneousChargeCount; //0x0074
	__int32 m_SimultaneousVehicleUsage; //0x0078
	float m_MinVehicleBookingDelayOnTokenAvailable; //0x007C
	float m_MaxVehicleBookingDelayOnTokenAvailable; //0x0080
	float m_EnemyMinTimeInMediumIntensity; //0x0084
};//Size=0x0088

////////////////////////////////////////
// RuntimeId: 01658
// TypeInfo:  0x0000000142741620
struct GameTweakAITargeting
{
	float m_IntervalBetweenAdditionalEnemiesTargetingPlayer; //0x0000
	TinyPiecewiseLinearCurve m_FiringDelayAfterAquiringTarget; //0x0004
	float m_ReaquireTargetDistanceThreshold; //0x0014
	TinyPiecewiseLinearCurve m_FiringDelayAfterReaquiringTarget; //0x0018
	TinyPiecewiseLinearCurve m_TimeUntilDamageFromStartOfFirstBurst; //0x0028
	TinyPiecewiseLinearCurve m_TimeUntilDamageTimeIsFullyRestored; //0x0038
	AccuracyPenaltySettings m_AccuracyPenaltySettings; //0x0048
};//Size=0x0064

////////////////////////////////////////
// RuntimeId: 01646
// TypeInfo:  0x0000000142741840
struct FiringPatternData
{
	unsigned __int64 m_Pattern; //0x0000
	__int32 m_Id; //0x0008
	FiringWeaponClass m_WeaponClass; //0x000C
	IntensityClass m_Intensity; //0x0010
	__int32 m_Delay; //0x0014
	bool m_SingleShot; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 01632
// TypeInfo:  0x0000000142741580
struct Distances
{
	float m_Min; //0x0000
	float m_Max; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01634
// TypeInfo:  0x0000000142741640
struct VehicleVsSoldier
{
	Distances m_Distances; //0x0000
	__int32 m_NumRepositions; //0x0008
	float m_FlushOutTime; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01636
// TypeInfo:  0x00000001427415E0
struct VehicleVsVehicle
{
	Distances m_Distances; //0x0000
	float m_SearchTime; //0x0008
	float m_KeepFocusWhileSearchingTime; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01626
// TypeInfo:  0x0000000142741760
struct VehicleSuppressionSettings
{
	float m_SuppressionDistance; //0x0000
	float m_ReevaluateCoverDistance; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01624
// TypeInfo:  0x00000001427416A0
struct WeaponSuppressionSettings
{
	float m_SuppressionValue; //0x0000
	float m_ContinuousSuppressionTime; //0x0004
	float m_SuppressionAreaSize; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01622
// TypeInfo:  0x00000001427417C0
struct EngageSettings
{
	float m_DistanceToTarget; //0x0000
	float m_SuppressionValue; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01608
// TypeInfo:  0x0000000142741780
struct AttackCoverRequestSettings
{
	float m_MinimumTimeInCoverToRequest; //0x0000
	float m_MaximumTimeInCoverToRequest; //0x0004
	float m_MinimumTimeIntervalToRequestProtectiveCover; //0x0008
	float m_MaximumTimeIntervalToRequestProtectiveCover; //0x000C
	float m_MinimumTimeInCoverAfterTargetLost; //0x0010
	float m_MaximumTimeInCoverAfterTargetLost; //0x0014
	float m_DistanceToTargetCompromisedThreshold; //0x0018
	float m_MinimumDistanceToTarget; //0x001C
	TinyPiecewiseLinearCurve m_MinimumInitialDelay; //0x0020
	TinyPiecewiseLinearCurve m_MaximumInitialDelay; //0x0030
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 01526
// TypeInfo:  0x0000000142741820
struct BFCoverSlot
{
	Vec3 m_Position; //0x0000
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01520
// TypeInfo:  0x0000000142741880
struct BFCoverData
{
	Vec4 m_PosAndExtra0; //0x0000
	Vec4 m_DirectionAndExtra1; //0x0010
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 01516
// TypeInfo:  0x0000000142741860
struct CoverQueryScoreRuntime
{
	__int32 m_RelationMask; //0x0000
	__int32 m_Flags; //0x0004
	__int32 m_Filter; //0x0008
	CoverQueryStyle m_XStyle; //0x000C
	CoverQueryPosition m_FromPosition; //0x0010
	CoverQueryPosition m_ToPosition; //0x0014
	CoverQueryDirection m_ReferenceDirection; //0x0018
	CoverQueryCurveXSource m_CurveXSource; //0x001C
	Array<float> m_Curve; //0x0020
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 01510
// TypeInfo:  0x00000001427415C0
struct CoverQueryFilter
{
	bool m_LeftBlocked; //0x0000
	bool m_LeftNotBlocked; //0x0001
	bool m_RightBlocked; //0x0002
	bool m_RightNotBlocked; //0x0003
	bool m_TopBlocked; //0x0004
	bool m_TopNotBlocked; //0x0005
	bool m_StandCovers; //0x0006
	bool m_MediumCovers; //0x0007
	bool m_CrouchCovers; //0x0008
	bool m_ProneCovers; //0x0009
	bool m_OpenCovers; //0x000A
	bool m_OpenDirectionalCovers; //0x000B
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01490
// TypeInfo:  0x00000001427415A0
struct BFCoverZones
{
	BFCoverZoneDefinition* m_CoverZonesOverAndOut; //0x0000
	BFCoverZoneDefinition* m_CoverZonesOver; //0x0008
	BFCoverZoneDefinition* m_CoverZonesOut; //0x0010
	BFCoverZoneDefinition* m_CoverZonesOpen; //0x0018
	BFCoverZoneDefinition* m_CoverZonesOpenDirectional; //0x0020
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 01486
// TypeInfo:  0x00000001427418A0
struct BFCoverZone
{
	float m_FirstAngle; //0x0000
	float m_SecondAngle; //0x0004
	float m_CloseDistance; //0x0008
	float m_FarDistance; //0x000C
	bool m_Peek; //0x0010
	bool m_Over; //0x0011
	bool m_Out; //0x0012
	bool m_Flanked; //0x0013
	bool m_AlwaysRequestCover; //0x0014
	bool m_RequestCoverIfUnderFire; //0x0015
	bool m_ForceOutFiring; //0x0016
	bool m_TriggerFlanked; //0x0017
	bool m_SuppressedByEnemyBullets; //0x0018
	bool m_AllowProjectileFire; //0x0019
	char _0x001A[2];
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 01448
// TypeInfo:  0x000000014273DF98
struct BurstInterval
{
	float m_BurstLength; //0x0000
	float m_BurstLengthVariation; //0x0004
	float m_TimeBetweenBursts; //0x0008
	float m_TimeBetweenBurstsVariation; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01442
// TypeInfo:  0x000000014273DF58
struct Interval
{
	float m_MinimumTime; //0x0000
	float m_MaximumTime; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01430
// TypeInfo:  0x000000014273DE78
struct BFAIProjectileBinding
{
	AntRef m_FireProjectile; //0x0000
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 01424
// TypeInfo:  0x000000014273DED8
struct LinearTime
{
	float m_Distance; //0x0000
	float m_Time; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01426
// TypeInfo:  0x000000014273DF18
struct Dispersion
{
	float m_MinimumHorizontal; //0x0000
	float m_MaximumHorizontal; //0x0004
	float m_MinimumVertical; //0x0008
	float m_MaximumVertical; //0x000C
	float m_ScalingDistance; //0x0010
	bool m_ScaleWithDistance; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 01428
// TypeInfo:  0x000000014273DF78
struct BFAIProjectile
{
	BFAIProjectileCurveType m_Curve; //0x0000
	LinearTime m_Minimum; //0x0004
	LinearTime m_Maximum; //0x000C
	Dispersion m_Dispersion; //0x0014
	char _0x002C[4];
	ProjectileBlueprint* m_Projectile; //0x0030
	SoundAsset* m_Sound; //0x0038
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 01410
// TypeInfo:  0x000000014273DDD8
struct AreaBookingSettings
{
	float m_EnemyTeamBookingRadius; //0x0000
	float m_FriendlyTeamBookingRadius; //0x0004
	float m_CorpseBookingTime; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01408
// TypeInfo:  0x000000014273DEB8
struct SquadEngageData
{
	float m_EngageTime; //0x0000
	float m_FindCoverTime; //0x0004
	float m_FailureCooldownTime; //0x0008
	float m_CooldownTime; //0x000C
	float m_SecondaryTargetRadius; //0x0010
	float m_CoverFireTargetRadius; //0x0014
	float m_AllowedTargetHiddenTime; //0x0018
	float m_WaitingToFireTime; //0x001C
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 01406
// TypeInfo:  0x000000014273DDF8
struct ShootingData
{
	float m_KeepFiringAtPlayerTime; //0x0000
	float m_KeepFiringAtAITime; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 01402
// TypeInfo:  0x000000014273DE58
struct SquadTargettingData
{
	float m_VisibleTargetLimit; //0x0000
	float m_TargetLostTimer; //0x0004
	Array<float> m_TargetImportanceThresholds; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 01404
// TypeInfo:  0x000000014273DE98
struct TargetingData
{
	float m_ForcePlayerAsTargetRange; //0x0000
	float m_ForcePlayerAsTargetAfterAttackedTime; //0x0004
	float m_AimOffsetY; //0x0008
	char _0x000C[4];
	SquadTargettingData m_SquadTargettingData; //0x0010
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 01400
// TypeInfo:  0x000000014273DF38
struct DamageAndPrecisionData
{
	float m_BulletDamage; //0x0000
	float m_AiDamageBucketTime; //0x0004
	bool m_IsSquadUsingDamageBucket; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 01398
// TypeInfo:  0x000000014273DE18
struct BFAI2SpottingPotentialMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 01397
// TypeInfo:  0x000000014273DEF8
struct BFAI2SpottingFoundMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00898
// TypeInfo:  0x0000000142721E68
struct StatDamageHelperMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00897
// TypeInfo:  0x0000000142721E88
struct StatPointsMessageBase
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00896
// TypeInfo:  0x0000000142721EA8
struct StatEventMessageBase
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00895
// TypeInfo:  0x0000000142721EC8
struct StatTriggerEntityMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00894
// TypeInfo:  0x0000000142721EE8
struct StatEventEntityTriggerMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00893
// TypeInfo:  0x0000000142721F08
struct StatGainRankMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00892
// TypeInfo:  0x0000000142721F28
struct StatGainAwardMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00891
// TypeInfo:  0x0000000142721F48
struct StatFinalizeStatsMessageBase
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00890
// TypeInfo:  0x0000000142721F68
struct StatClubRecordClosingMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00889
// TypeInfo:  0x0000000142721F88
struct StatClubRecordCreatedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00888
// TypeInfo:  0x0000000142721FA8
struct StatPlayerRecordClosingMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00887
// TypeInfo:  0x0000000142721FC8
struct StatPlayerRecordCreatedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00886
// TypeInfo:  0x0000000142721FE8
struct ServerBackendStringMetricMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00885
// TypeInfo:  0x0000000142722008
struct ServerBackendCounterMetricMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00884
// TypeInfo:  0x0000000142722028
struct ServerBackendGaugeMetricMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00883
// TypeInfo:  0x0000000142722048
struct ServerBackendTagMetricMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00882
// TypeInfo:  0x0000000142722068
struct ServerBackendLiveScoreboardDisableMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00881
// TypeInfo:  0x0000000142722088
struct ServerBackendLiveScoreboardEnableMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00880
// TypeInfo:  0x00000001427220A8
struct ServerBackendLiveServerProxyDisableMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00879
// TypeInfo:  0x00000001427220C8
struct ServerBackendLiveServerProxyEnableMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00878
// TypeInfo:  0x00000001427220E8
struct ServerBackendLiveServerProxyConfigUpdatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00877
// TypeInfo:  0x0000000142722108
struct ServerBackendLogTransmitterSettingsUpdatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00876
// TypeInfo:  0x0000000142722128
struct ServerBackendBattlelogTransactionMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00875
// TypeInfo:  0x0000000142722148
struct PlaygroundServerBackendResponseMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00874
// TypeInfo:  0x0000000142722168
struct PeerServerBackendResponseMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00873
// TypeInfo:  0x0000000142722188
struct PeerServerBackendRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00872
// TypeInfo:  0x00000001427221A8
struct ServerBackendRoleResponseMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00871
// TypeInfo:  0x00000001427221C8
struct ServerBackendRoleRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00870
// TypeInfo:  0x00000001427221E8
struct ServerBackendBattlepackResponseMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00869
// TypeInfo:  0x0000000142722208
struct ServerBackendBattlepackRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00868
// TypeInfo:  0x0000000142722228
struct ServerBackendOnGameReportMetricMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00867
// TypeInfo:  0x0000000142722248
struct ServerBackendOnGameReportCompleteMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00866
// TypeInfo:  0x0000000142722268
struct ServerBackendGameReportCompleteMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00865
// TypeInfo:  0x0000000142722288
struct ServerBackendOnFinalizationCompleteMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00864
// TypeInfo:  0x00000001427222A8
struct VeniceServerMetricsFriendZoneSpawnMessage
{
	char _0x0000[128];
};//Size=0x0080

////////////////////////////////////////
// RuntimeId: 00863
// TypeInfo:  0x00000001427222C8
struct VeniceServerMetricsManDownImmobilizedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00862
// TypeInfo:  0x00000001427222E8
struct VeniceServerMetricsManDownMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00861
// TypeInfo:  0x0000000142722308
struct VeniceServerMetricsRestartRoundMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00860
// TypeInfo:  0x0000000142722328
struct VeniceServerMetricsStartRoundMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00859
// TypeInfo:  0x0000000142722348
struct VeniceServerMetricsLifeCounterMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00858
// TypeInfo:  0x0000000142722368
struct VeniceServerMetricsTicketCounterMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00857
// TypeInfo:  0x0000000142722388
struct VeniceServerMetricsRankupMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00856
// TypeInfo:  0x00000001427223A8
struct VeniceServerMetricsCreateLogMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00789
// TypeInfo:  0x00000001427223C8
struct ServerLevolutionTriggeredMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00784
// TypeInfo:  0x00000001427223E8
struct VeniceNetworkWeaponAimingMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00771
// TypeInfo:  0x0000000142722408
struct IndirectFireDispersionData
{
	float m_MaxAngle; //0x0000
	float m_MinAngle; //0x0004
	float m_DispersionAimMove; //0x0008
	float m_DispersionAimMoveThreshold; //0x000C
	float m_DispersionFiring; //0x0010
	float m_DispersionDeployment; //0x0014
	float m_DecreasePerSecond; //0x0018
};//Size=0x001C

////////////////////////////////////////
// RuntimeId: 00765
// TypeInfo:  0x0000000142722428
struct PlayerFriendManagerFriendJoinEventMessage
{
	char _0x0000[104];
};//Size=0x0068

////////////////////////////////////////
// RuntimeId: 00762
// TypeInfo:  0x0000000142722468
struct PlayerFriendManagerSetAllowCreateFriendSquadMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00761
// TypeInfo:  0x0000000142722488
struct PlayerFriendManagerAbortFriendJoinMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00754
// TypeInfo:  0x00000001427224A8
struct VeniceNetworkVictimDisabledPartMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00753
// TypeInfo:  0x00000001427224C8
struct VeniceNetworkVictimMissingPhysicsComponentMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00752
// TypeInfo:  0x00000001427224E8
struct VeniceNetworkIgnoredDamageMessage
{
	char _0x0000[120];
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 00751
// TypeInfo:  0x0000000142722508
struct VeniceNetworkSavePersistenceMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00750
// TypeInfo:  0x0000000142722528
struct VeniceNetworkClientLanguageMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00749
// TypeInfo:  0x0000000142722548
struct VeniceNetworkRequestClientLanguageMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00748
// TypeInfo:  0x0000000142722568
struct VeniceNetworkRequestScreenshotMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00747
// TypeInfo:  0x0000000142722588
struct VeniceNetworkClientCameraInfoMessageBase
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00746
// TypeInfo:  0x00000001427225A8
struct VeniceNetworkServerStatInfoMessageBase
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00745
// TypeInfo:  0x00000001427225C8
struct VeniceNetworkRequestServerStatInfoMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00744
// TypeInfo:  0x00000001427225E8
struct VeniceNetworkSuspiciousKeyMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00743
// TypeInfo:  0x0000000142722608
struct VeniceNetworkPunkBusterActiveMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00742
// TypeInfo:  0x0000000142722628
struct VeniceNetworkPunkBusterPacketMessageBase
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00741
// TypeInfo:  0x0000000142722648
struct VeniceNetworkServerInfoMessage
{
	char _0x0000[136];
};//Size=0x0088

////////////////////////////////////////
// RuntimeId: 00740
// TypeInfo:  0x0000000142722668
struct VeniceNetworkRequestServerInfoMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00739
// TypeInfo:  0x0000000142722688
struct VeniceNetworkSetPingMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00738
// TypeInfo:  0x00000001427226A8
struct VeniceNetworkMetricsAchievementMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00737
// TypeInfo:  0x00000001427226C8
struct VeniceNetworkLocalClientConnectionInfoUpdatedMessageBase
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00736
// TypeInfo:  0x00000001427226E8
struct VeniceNetworkOnPlayerSelectedTeamMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00733
// TypeInfo:  0x0000000142722728
struct VeniceNetworkFriendZoneDebugEnableMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00732
// TypeInfo:  0x0000000142722748
struct VeniceNetworkFriendZoneMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00731
// TypeInfo:  0x0000000142722768
struct VeniceNetworkVirtualGameStateMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00730
// TypeInfo:  0x0000000142722788
struct VeniceNetworkSendTelemetryTokenMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00729
// TypeInfo:  0x00000001427227A8
struct VeniceNetworkNotifyMicStateMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00728
// TypeInfo:  0x00000001427227C8
struct VeniceNetworkSetVoiceChannelMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00727
// TypeInfo:  0x00000001427227E8
struct VeniceNetworkVoiceTokenMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00726
// TypeInfo:  0x0000000142722808
struct VeniceNetworkEorStatsMessage
{
	char _0x0000[176];
};//Size=0x00B0

////////////////////////////////////////
// RuntimeId: 00725
// TypeInfo:  0x0000000142722828
struct VeniceNetworkSettingsMessage
{
	char _0x0000[168];
};//Size=0x00A8

////////////////////////////////////////
// RuntimeId: 00724
// TypeInfo:  0x0000000142722848
struct VeniceNetworkRequestCoopPlayerInformationMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00723
// TypeInfo:  0x0000000142722868
struct VeniceNetworkRequestCoopEorStatsMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00722
// TypeInfo:  0x0000000142722888
struct VeniceNetworkRequestEorStatsMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00721
// TypeInfo:  0x00000001427228A8
struct VeniceNetworkDefibKillMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00720
// TypeInfo:  0x00000001427228C8
struct VeniceNetworkScoreChangeMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00719
// TypeInfo:  0x00000001427228E8
struct VeniceNetworkCounterStatusMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00718
// TypeInfo:  0x0000000142722908
struct VeniceNetworkRequestCounterStatusMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00717
// TypeInfo:  0x0000000142722928
struct VeniceNetworkMissionAwardsStatusMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00714
// TypeInfo:  0x0000000142723E88
struct CounterStatus
{
	float m_CurrentValue; //0x0000
	float m_OriginalValue; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00716
// TypeInfo:  0x0000000142723E68
struct AwardStatus
{
	char* m_Code; //0x0000
	unsigned __int32 m_CurrentValue; //0x0008
	unsigned __int32 m_OriginalValue; //0x000C
	Array<CounterStatus> m_Counters; //0x0010
	bool m_IsCounting; //0x0018
	char _0x0019[7];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 00712
// TypeInfo:  0x0000000142723EA8
struct StatCounterStatus
{
	char* m_Code; //0x0000
	float m_CurrentValue; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00710
// TypeInfo:  0x0000000142722948
struct VeniceNetworkDogTagMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00709
// TypeInfo:  0x0000000142722968
struct VeniceNetworkAchievementUpdateMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00708
// TypeInfo:  0x0000000142722988
struct VeniceNetworkAchievementProgressMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00707
// TypeInfo:  0x00000001427229A8
struct VeniceNetworkUnlockAchievementsMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00706
// TypeInfo:  0x00000001427229C8
struct VeniceNetworkAllWeaponKillsMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00705
// TypeInfo:  0x00000001427229E8
struct VeniceNetworkRequestAllWeaponKillsMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00704
// TypeInfo:  0x0000000142722A08
struct VeniceNetworkBoostUpdateMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00701
// TypeInfo:  0x0000000142722A48
struct VeniceNetworkUnlockGainedMessage
{
	char _0x0000[120];
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 00698
// TypeInfo:  0x0000000142722A88
struct VeniceNetworkAwardGainedMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 00697
// TypeInfo:  0x0000000142722AA8
struct VeniceNetworkSetSquadPrivacyMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00696
// TypeInfo:  0x0000000142722AC8
struct VeniceNetworkLeaveSquadMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00695
// TypeInfo:  0x0000000142722AE8
struct VeniceNetworkKickFromSquadMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00694
// TypeInfo:  0x0000000142722B08
struct VeniceNetworkCreateSquadMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00693
// TypeInfo:  0x0000000142722B28
struct VeniceNetworkJoinSquadByOnlineIdMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00692
// TypeInfo:  0x0000000142722B48
struct VeniceNetworkJoinSquadMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00691
// TypeInfo:  0x0000000142722B68
struct VeniceNetworkOrderMessage
{
	char _0x0000[104];
};//Size=0x0068

////////////////////////////////////////
// RuntimeId: 00690
// TypeInfo:  0x0000000142722B88
struct VeniceNetworkFocusPointMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00689
// TypeInfo:  0x0000000142722BA8
struct VeniceNetworkSpottingOverheatMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00688
// TypeInfo:  0x0000000142722BC8
struct VeniceNetworkSpottingMessage
{
	char _0x0000[232];
};//Size=0x00E8

////////////////////////////////////////
// RuntimeId: 00687
// TypeInfo:  0x0000000142722BE8
struct EmblemTextureFinishedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00686
// TypeInfo:  0x0000000142722C08
struct ServerScreenshotReceivedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00685
// TypeInfo:  0x0000000142722C28
struct FieldUpgradesLevelUpPlayerMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00684
// TypeInfo:  0x0000000142722C48
struct PushNotificationChallengeActiveDeltaMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00683
// TypeInfo:  0x0000000142722C68
struct PushNotificationPresencePlayingDeltaMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00682
// TypeInfo:  0x0000000142722C88
struct PushNotificationPresentMessageBase
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00679
// TypeInfo:  0x0000000142722CC8
struct GameControlJoinServerMessageBase
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00678
// TypeInfo:  0x0000000142722CE8
struct ESportsMatchManagerDelayedTerminationMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00677
// TypeInfo:  0x0000000142722D08
struct ESportsMatchManagerTooFewPlayersMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00676
// TypeInfo:  0x0000000142722D28
struct VeniceCommonMetricsTriggerMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00675
// TypeInfo:  0x0000000142722D48
struct ServerUnlockSystemSetupMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00672
// TypeInfo:  0x0000000142722D88
struct ServerMapSequencerLevelLoadedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00671
// TypeInfo:  0x0000000142722DA8
struct ServerMapSequencerSwitchingLevelsMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00670
// TypeInfo:  0x0000000142722DC8
struct ServerMapSequencerControlledInfoMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00669
// TypeInfo:  0x0000000142722DE8
struct ServerMapSequencerMaxPlayerCountMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00668
// TypeInfo:  0x0000000142722E08
struct ServerMapSequencerEventMessageBase
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00665
// TypeInfo:  0x0000000142722E48
struct ClientPersistenceAwardGainedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00664
// TypeInfo:  0x0000000142722E68
struct VoiceSetPushToTalkStateMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00663
// TypeInfo:  0x0000000142722E88
struct VoiceChangedMicEnabledMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00662
// TypeInfo:  0x0000000142722EA8
struct VoiceSetMuteStatusMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00661
// TypeInfo:  0x0000000142722EC8
struct VoiceSettingsRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00660
// TypeInfo:  0x0000000142722EE8
struct VoiceSettingsMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00659
// TypeInfo:  0x0000000142722F08
struct VoiceChannelRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00658
// TypeInfo:  0x0000000142722F28
struct VoiceChannelMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00657
// TypeInfo:  0x0000000142722F48
struct UIMemoryCardDestroyedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00656
// TypeInfo:  0x0000000142722F68
struct UIMemoryCardCreatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00655
// TypeInfo:  0x0000000142722F88
struct UIIOStatusMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00652
// TypeInfo:  0x0000000142722FC8
struct UINPXTooltipMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00651
// TypeInfo:  0x0000000142722FE8
struct UITooltipMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00648
// TypeInfo:  0x0000000142723028
struct UISelectedWeaponMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00647
// TypeInfo:  0x0000000142723048
struct UISelectedVisualUnlocksMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00646
// TypeInfo:  0x0000000142723068
struct UIReceivedCustomizationFromBlazeMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00645
// TypeInfo:  0x0000000142723088
struct UIRefreshCustomizationSelectionsMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00644
// TypeInfo:  0x00000001427230A8
struct UIPreEndOfRoundReadyMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00643
// TypeInfo:  0x00000001427230C8
struct UIEndOfRoundReadyMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00642
// TypeInfo:  0x00000001427230E8
struct UIRequestEndOfRoundMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00641
// TypeInfo:  0x0000000142723108
struct UIRequestPreEndOfRoundMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00640
// TypeInfo:  0x0000000142723128
struct UILoadingProgressHideMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00639
// TypeInfo:  0x0000000142723148
struct UILoadingProgressShowMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00638
// TypeInfo:  0x0000000142723168
struct UIEnterFrontendMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00637
// TypeInfo:  0x0000000142723188
struct UIControlpointChangedTeamMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00636
// TypeInfo:  0x00000001427231A8
struct UIPlayerVehicleListRefreshMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00635
// TypeInfo:  0x00000001427231C8
struct UIHudTicketBleedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00634
// TypeInfo:  0x00000001427231E8
struct UIHudSquadLevelChangeMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00633
// TypeInfo:  0x0000000142723208
struct UIHudLastManStandingMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00632
// TypeInfo:  0x0000000142723228
struct UIHudResetWinningTeamMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00631
// TypeInfo:  0x0000000142723248
struct UITrackedAwardChangedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00630
// TypeInfo:  0x0000000142723268
struct UITrackedAwardUpdatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00629
// TypeInfo:  0x0000000142723288
struct UIHudReviveWeaponEquippedChangedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00628
// TypeInfo:  0x00000001427232A8
struct UIHudShowEnemiesMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00627
// TypeInfo:  0x00000001427232C8
struct UIHudShowCaptureProgressMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00626
// TypeInfo:  0x00000001427232E8
struct UIHudEnableMinimapMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00625
// TypeInfo:  0x0000000142723308
struct UIShowScoreboardMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00624
// TypeInfo:  0x0000000142723328
struct UIShowMinimapMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00623
// TypeInfo:  0x0000000142723348
struct ServerSoldierSuppressionSuppressMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00622
// TypeInfo:  0x0000000142723368
struct UIMinimapObjectiveEventMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00621
// TypeInfo:  0x0000000142723388
struct UIObjectiveEventMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00618
// TypeInfo:  0x00000001427233C8
struct ClientGameplayPlayerBaseDestroyedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00617
// TypeInfo:  0x00000001427233E8
struct ServerGameplayCTFFlagReturnedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00616
// TypeInfo:  0x0000000142723408
struct ServerGameplayCTFFlagCapturedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00615
// TypeInfo:  0x0000000142723428
struct ServerGameplayCTFFlagDroppedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00614
// TypeInfo:  0x0000000142723448
struct ServerGameplayCTFFlagPickedUpMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00613
// TypeInfo:  0x0000000142723468
struct ServerGameplayTeamTakeLeadMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00612
// TypeInfo:  0x0000000142723488
struct ServerGameplayTeamLostLeadMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00611
// TypeInfo:  0x00000001427234A8
struct ServerGameplayPlayerBaseDestroyedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00610
// TypeInfo:  0x00000001427234C8
struct ServerGameplayTeamReinforceMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00609
// TypeInfo:  0x00000001427234E8
struct ServerGameplayCapturePointPlayerEnteredMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00608
// TypeInfo:  0x0000000142723508
struct ServerGameplayCapturePointResetMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00607
// TypeInfo:  0x0000000142723528
struct ServerGameplayCapturePointLostMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00606
// TypeInfo:  0x0000000142723548
struct ServerGameplayCapturePointCapturedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00605
// TypeInfo:  0x0000000142723568
struct ServerGameplayCapturePointChangedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00604
// TypeInfo:  0x0000000142723588
struct ServerPlayerBoostUpdateMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00603
// TypeInfo:  0x00000001427235A8
struct ServerPlayerConsumableConsumedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00602
// TypeInfo:  0x00000001427235C8
struct ServerPlayerFieldUpgradeUpdateMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00601
// TypeInfo:  0x00000001427235E8
struct ServerPlayerCommanderOrderReplyMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00600
// TypeInfo:  0x0000000142723608
struct ServerPlayerNewCommanderOrderMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00599
// TypeInfo:  0x0000000142723628
struct ServerPlayerLicensesAvailableMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00598
// TypeInfo:  0x0000000142723648
struct ServerPlayerManDownRevivedMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00597
// TypeInfo:  0x0000000142723668
struct ServerPlayerMeleeInteruptedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00596
// TypeInfo:  0x0000000142723688
struct ServerPlayerTeamKillKickMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00595
// TypeInfo:  0x00000001427236A8
struct ServerPlayerNoInteractivityKickMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00594
// TypeInfo:  0x00000001427236C8
struct ServerPlayerSpawnOnSelectedSpawnPointMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00593
// TypeInfo:  0x00000001427236E8
struct ServerPlayerSpawnAtVehicleMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00592
// TypeInfo:  0x0000000142723708
struct ServerPlayerSpawnOnPlayerMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00591
// TypeInfo:  0x0000000142723728
struct ServerPlayerSquadLeaderStatusChangedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00590
// TypeInfo:  0x0000000142723748
struct ServerPlayerChangedSquadSpawnerStatusMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00589
// TypeInfo:  0x0000000142723768
struct ServerPlayerChangedVoiceChannelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00588
// TypeInfo:  0x0000000142723788
struct ServerPlayerSwitchSquadMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00587
// TypeInfo:  0x00000001427237A8
struct ClientPlayerMeleeCounterWindowEndsMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00586
// TypeInfo:  0x00000001427237C8
struct ClientPlayerMeleeCounterWindowStartsMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00585
// TypeInfo:  0x00000001427237E8
struct ClientPlayerChangedMatchReadyStatusMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00584
// TypeInfo:  0x0000000142723808
struct ClientPlayerVoiceSlotMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00583
// TypeInfo:  0x0000000142723828
struct ClientPlayerChangedVoiceChannelMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00582
// TypeInfo:  0x0000000142723848
struct ClientPlayerChangedAllowedToSpawnOnMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00581
// TypeInfo:  0x0000000142723868
struct ClientPlayerChangedSquadLeaderStatusMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00580
// TypeInfo:  0x0000000142723888
struct ClientPlayerNewSquadOrderMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00579
// TypeInfo:  0x00000001427238A8
struct ClientPlayerSwitchSquadMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00578
// TypeInfo:  0x00000001427238C8
struct ServerResendSyncedSettingsMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00577
// TypeInfo:  0x00000001427238E8
struct ServerRestartForESportsMatchMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00576
// TypeInfo:  0x0000000142723908
struct ServerRotateLevelMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00575
// TypeInfo:  0x0000000142723928
struct CommanderActivateCameraMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00574
// TypeInfo:  0x0000000142723948
struct CommanderAwardCommanderScoreMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00573
// TypeInfo:  0x0000000142723968
struct CommanderAwardCommanderSquadScoreMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00572
// TypeInfo:  0x0000000142723988
struct CommanderNetworkEMPDroneDeployedMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00571
// TypeInfo:  0x00000001427239A8
struct CommanderNetworkUAVDroneDeployedMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00570
// TypeInfo:  0x00000001427239C8
struct CommanderNetworkGunshipDeployedMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00569
// TypeInfo:  0x00000001427239E8
struct CommanderNetworkEarlyWarningEndedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00568
// TypeInfo:  0x0000000142723A08
struct CommanderNetworkEarlyWarningStartedMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00567
// TypeInfo:  0x0000000142723A28
struct CommanderNetworkRadarScanStartedMessage
{
	char _0x0000[128];
};//Size=0x0080

////////////////////////////////////////
// RuntimeId: 00566
// TypeInfo:  0x0000000142723A48
struct CommanderNetworkTomahawkLaunchedMessage
{
	char _0x0000[88];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00565
// TypeInfo:  0x0000000142723A68
struct CommanderNetworkSatelliteEMPEndedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00564
// TypeInfo:  0x0000000142723A88
struct CommanderNetworkSatelliteEMPStartedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00563
// TypeInfo:  0x0000000142723AA8
struct CommanderNetworkJamEndedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00562
// TypeInfo:  0x0000000142723AC8
struct CommanderNetworkJamStartedMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 00561
// TypeInfo:  0x0000000142723AE8
struct CommanderNetworkScanEndedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00560
// TypeInfo:  0x0000000142723B08
struct CommanderNetworkScanStartedMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 00559
// TypeInfo:  0x0000000142723B28
struct CommanderNetworkOrderReplyMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00558
// TypeInfo:  0x0000000142723B48
struct CommanderNetworkRemoveOrderMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00557
// TypeInfo:  0x0000000142723B68
struct CommanderNetworkIssueOrderMessage
{
	char _0x0000[128];
};//Size=0x0080

////////////////////////////////////////
// RuntimeId: 00556
// TypeInfo:  0x0000000142723B88
struct CommanderNetworkAbortActionMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00555
// TypeInfo:  0x0000000142723BA8
struct CommanderNetworkSelectedSquadMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00554
// TypeInfo:  0x0000000142723BC8
struct CommanderNetworkTriggerOrderReplyMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00553
// TypeInfo:  0x0000000142723BE8
struct CommanderNetworkTriggerRequestMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00552
// TypeInfo:  0x0000000142723C08
struct CommanderNetworkTriggerActionMessage
{
	char _0x0000[144];
};//Size=0x0090

////////////////////////////////////////
// RuntimeId: 00551
// TypeInfo:  0x0000000142723C28
struct CommanderNetworkLeaveSeatMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00550
// TypeInfo:  0x0000000142723C48
struct CommanderNetworkApplyForSeatMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00549
// TypeInfo:  0x0000000142723C68
struct CommanderNetworkSquadReinforcedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00548
// TypeInfo:  0x0000000142723C88
struct CommanderNetworkMutinyAbortedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00547
// TypeInfo:  0x0000000142723CA8
struct CommanderNetworkMutinyCompletedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00546
// TypeInfo:  0x0000000142723CC8
struct CommanderNetworkMutinyStartedMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00545
// TypeInfo:  0x0000000142723CE8
struct CommanderNetworkSquadLeaderRateCommanderMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00544
// TypeInfo:  0x0000000142723D08
struct CommanderNetworkRemoveRequestFromSquadMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00543
// TypeInfo:  0x0000000142723D28
struct CommanderNetworkAddRequestFromSquadMessage
{
	char _0x0000[96];
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00542
// TypeInfo:  0x0000000142723D48
struct CommanderNetworkRequestActionFromCommanderMessage
{
	char _0x0000[112];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 00541
// TypeInfo:  0x0000000142723D68
struct CommanderActionsActionStateChangedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00540
// TypeInfo:  0x0000000142723D88
struct CommanderSquadChangedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00539
// TypeInfo:  0x0000000142723DA8
struct CommanderCommanderChangedMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00478
// TypeInfo:  0x0000000142723EC8
struct MessageLineData
{
	char* m_MessageSid; //0x0000
	__int32 m_EntryInputAction; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00462
// TypeInfo:  0x0000000142723DE8
struct AimingConstraintEntityBinding
{
	AntRef m_ProneAimLimit; //0x0000
	AntRef m_ProneAimDistance; //0x0014
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00454
// TypeInfo:  0x0000000142723E08
struct CharacterMeleeBinding
{
	AntRef m_TriggerMelee; //0x0000
	AntRef m_DefendMelee; //0x0014
	AntRef m_MeleeKill; //0x0028
	AntRef m_SelfActor; //0x003C
	AntRef m_OtherActor; //0x0050
	AntRef m_MeleeActive; //0x0064
};//Size=0x0078

////////////////////////////////////////
// RuntimeId: 00452
// TypeInfo:  0x0000000142723E28
struct CharacterMeleeCommonBinding
{
	AntRef m_MeleeDistance; //0x0000
	AntRef m_MeleeAngle; //0x0014
	AntRef m_MeleeDirection; //0x0028
	AntRef m_DefendEnabled; //0x003C
	AntRef m_MeleeDefenceTime; //0x0050
	AntRef m_MeleeSequenceTime; //0x0064
	AntRef m_MeleeAborted; //0x0078
	AntRef m_IsTimeToKill; //0x008C
	AntRef m_CloseToTarget; //0x00A0
	AntRef m_MeleeType; //0x00B4
};//Size=0x00C8

////////////////////////////////////////
// RuntimeId: 00434
// TypeInfo:  0x0000000142723E48
struct KillWeight
{
	float m_LowIntenseWeight; //0x0000
	float m_HighIntenseWeight; //0x0004
	float m_CoolDownTime; //0x0008
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 00370
// TypeInfo:  0x0000000142719FE0
struct LookAtHuman
{
	AntSpeedLevel m_SpeedLevel; //0x0000
	float m_DelayMin; //0x0004
	float m_DelayMax; //0x0008
	float m_LengthMin; //0x000C
	float m_LengthMax; //0x0010
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 00352
// TypeInfo:  0x000000014271A000
struct WeaponInteractionData
{
	SoldierWeaponUnlockAsset* m_WeaponToInteractWith; //0x0000
	bool m_OnlyManDownTargets; //0x0008
	char _0x0009[7];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00324
// TypeInfo:  0x0000000142718FE0
struct SupportedShootingProximityChecking
{
	float m_RayAboveGunHeightOffset; //0x0000
	float m_RayAboveLength; //0x0004
	float m_RayBelowGunHeightOffset; //0x0008
	float m_RayBelowLength; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00314
// TypeInfo:  0x000000014271A040
struct SpecialMoveInterpolatedPoint
{
	Vec3 m_Value; //0x0000
	float m_Time; //0x0010
	char _0x0014[12];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 00318
// TypeInfo:  0x0000000142719000
struct SpecialMoveStateData
{
	float m_OptimumDistanceFromObject; //0x0000
	float m_OptimumHeightOfObject; //0x0004
	float m_OptimumLengthOfObject; //0x0008
	float m_MaxDistanceScale; //0x000C
	float m_MinDistanceScale; //0x0010
	float m_MaxHeightScale; //0x0014
	float m_MinHeightScale; //0x0018
	float m_MaxObjectLengthScale; //0x001C
	float m_MinObjectLengthScale; //0x0020
	float m_ExitAnimationDrivenStateVelocity; //0x0024
	SpecialMovesPoseType m_OverridePose; //0x0028
	SpecialMovesPoseType m_ResetPose; //0x002C
	Array<SpecialMoveInterpolatedPoint> m_GravityPoints; //0x0030
	Array<SpecialMoveInterpolatedPoint> m_MotionPoints; //0x0038
	bool m_ScaleWithDistanceToObject; //0x0040
	bool m_KeepInitialSoldierDirection; //0x0041
	char _0x0042[6];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00320
// TypeInfo:  0x000000014271A020
struct SpecialMoveVaultStateCriteria
{
	float m_DistToObject; //0x0000
	float m_DistToObjectTolerance; //0x0004
	float m_HeightOfObject; //0x0008
	float m_HeightOfObjectTolerance; //0x000C
	float m_LengthOfObject; //0x0010
	float m_LengthOfObjectTolerance; //0x0014
	SpecialMoveStateData m_SpecialMoveState; //0x0018
};//Size=0x0060

////////////////////////////////////////
// RuntimeId: 00308
// TypeInfo:  0x0000000142719020
struct AirMissileJammingData
{
	float m_MaxRadius; //0x0000
	float m_MinRadius; //0x0004
	float m_Theta; //0x0008
	float m_Phi; //0x000C
	float m_MinTurnSpeed; //0x0010
	float m_MaxTurnSpeed; //0x0014
	float m_QuietModeProbability; //0x0018
	float m_QuietModeTime; //0x001C
	float m_JammingTime; //0x0020
	float m_TurnCalculationTime; //0x0024
	float m_UpdateJammingPositionTime; //0x0028
	bool m_EnableAirMissileJamming; //0x002C
	char _0x002D[3];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00306
// TypeInfo:  0x0000000142719040
struct SmokeJammingData
{
	float m_MaxRadius; //0x0000
	float m_MinRadius; //0x0004
	float m_JammingTime; //0x0008
	float m_TargetUpdateTime; //0x000C
	bool m_EnableSmokeJamming; //0x0010
	bool m_JammingPositionIsLocationDependent; //0x0011
	bool m_ReportJammedBasedOnStartPosition; //0x0012
	char _0x0013[1];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 00302
// TypeInfo:  0x0000000142719060
struct Vault3pOnlyBinding
{
	AntRef m_IsVaulting; //0x0000
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 00300
// TypeInfo:  0x0000000142719080
struct Vault1pOnlyBinding
{
	AntRef m_IsVaulting; //0x0000
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 00298
// TypeInfo:  0x00000001427190A0
struct VaultBinding
{
	AntRef m_VaultActive; //0x0000
	AntRef m_VaultCancel; //0x0014
	AntRef m_VaultDepthDistance; //0x0028
	AntRef m_VaultEndHeight; //0x003C
	AntRef m_VaultStartDistance; //0x0050
	AntRef m_VaultStartHeight; //0x0064
	AntRef m_VaultType; //0x0078
};//Size=0x008C

////////////////////////////////////////
// RuntimeId: 00292
// TypeInfo:  0x00000001427190C0
struct AwarenessTargetInfo
{
	float m_Priority; //0x0000
	AwarenessTargetType m_TargetType; //0x0004
	float m_TargetRange; //0x0008
	bool m_MustBeInsideFrustum; //0x000C
	char _0x000D[3];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00288
// TypeInfo:  0x00000001427190E0
struct AwarenessComponentBinding
{
	AntRef m_RelativeLookAtPitch; //0x0000
	AntRef m_RelativeLookAtYaw; //0x0014
	AntRef m_HasAwarenessTarget; //0x0028
	AntRef m_ExplosionNearby; //0x003C
	AntRef m_ExplosionDirection; //0x0050
	AntRef m_NearbyThreat; //0x0064
	AntRef m_NearbyThreatDirection; //0x0078
	AntRef m_AmbientThreat; //0x008C
};//Size=0x00A0

////////////////////////////////////////
// RuntimeId: 00286
// TypeInfo:  0x000000014271A060
struct TabletCommanderClientHasLoadedLevelMessage
{
	bool m_Loaded; //0x0000
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 00284
// TypeInfo:  0x000000014271A080
struct TabletCommanderSelectedSquadChangedMessage
{
	SquadId m_SelectedSquad; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 00282
// TypeInfo:  0x000000014271A0A0
struct TabletCommanderAbortActionMessage
{
	unsigned __int8 m_ActionType; //0x0000
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 00280
// TypeInfo:  0x000000014271A0C0
struct TabletCommanderTriggerActionMessage
{
	unsigned __int8 m_ActionType; //0x0000
	char _0x0001[3];
	unsigned __int32 m_PlayerId; //0x0004
	unsigned __int32 m_MapMarkerId; //0x0008
	unsigned __int16 m_X; //0x000C
	unsigned __int16 m_Y; //0x000E
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00278
// TypeInfo:  0x000000014271A0E0
struct TabletCommanderPingMessage
{
	float m_PingTime; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 00276
// TypeInfo:  0x000000014271A100
struct TabletCommanderTryConnectMessage
{
	unsigned __int32 m_TCClientProtocolVersion; //0x0000
	char _0x0004[4];
	unsigned __int64 m_PlayerId; //0x0008
	char* m_PlayerName; //0x0010
	TabletCommanderPlatform m_Platform; //0x0018
	char _0x001C[4];
	char* m_DeviceModel; //0x0020
	char* m_DeviceOsVersion; //0x0028
	char* m_DeviceNetworkConnection; //0x0030
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00274
// TypeInfo:  0x000000014271A120
struct TabletCommanderCarrierStateMessage
{
	unsigned __int8 m_Team1CarrierHealth; //0x0000
	unsigned __int8 m_Team2CarrierHealth; //0x0001
	unsigned __int8 m_Team1CarrierState; //0x0002
	unsigned __int8 m_Team2CarrierState; //0x0003
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 00272
// TypeInfo:  0x000000014271A140
struct TabletCommanderChatMessage
{
	char* m_ChatMessage; //0x0000
	unsigned __int32 m_SenderPlayerId; //0x0008
	TabletCommanderChatChannel m_Channel; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00270
// TypeInfo:  0x000000014271A160
struct TabletCommanderEnemyCommanderChangedMessage
{
	char* m_CommanderName; //0x0000
	char* m_CommanderEmblem; //0x0008
	unsigned __int32 m_CommanderPlayerId; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00268
// TypeInfo:  0x000000014271A180
struct TabletCommanderMutinyCompletedMessage
{
	bool m_Dummy; //0x0000
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 00266
// TypeInfo:  0x000000014271A1A0
struct TabletCommanderRankGainedMessage
{
	unsigned __int8 m_OldRank; //0x0000
	unsigned __int8 m_NewRank; //0x0001
};//Size=0x0002

////////////////////////////////////////
// RuntimeId: 00186
// TypeInfo:  0x0000000142719160
struct TabletCommanderAwardData
{
	char* m_AwardCode; //0x0000
	char* m_Name; //0x0008
	char* m_Description; //0x0010
	char* m_ImageName; //0x0018
	float m_Score; //0x0020
	unsigned __int32 m_TimesTakenCount; //0x0024
	unsigned __int8 m_Group; //0x0028
	char _0x0029[7];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00184
// TypeInfo:  0x000000014271A640
struct TabletCommanderScoreBoardData
{
	unsigned __int32 m_Id; //0x0000
	unsigned __int32 m_Score; //0x0004
	unsigned __int16 m_Kills; //0x0008
	unsigned __int16 m_Deaths; //0x000A
	unsigned __int16 m_Rank; //0x000C
	char _0x000E[2];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00188
// TypeInfo:  0x0000000142719140
struct TabletCommanderAwardCriteria
{
	char* m_Description; //0x0000
	float m_CompletionValue; //0x0008
	float m_OriginalValue; //0x000C
	float m_AbsoluteValue; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00258
// TypeInfo:  0x000000014271A220
struct TabletCommanderPlayerLeftMessage
{
	unsigned __int32 m_PlayerId; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 00178
// TypeInfo:  0x00000001427191A0
struct TabletCommanderPlayerData
{
	unsigned __int32 m_Id; //0x0000
	char _0x0004[4];
	char* m_Name; //0x0008
	unsigned __int8 m_VoiceSlot; //0x0010
	char _0x0011[3];
	TeamId m_TeamId; //0x0014
	SquadId m_SquadId; //0x0018
	unsigned __int8 m_SoldierKit; //0x001C
	bool m_IsSquadLeader; //0x001D
	bool m_IsAlive; //0x001E
	char _0x001F[1];
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 00176
// TypeInfo:  0x00000001427191C0
struct TabletCommanderLevolutionState
{
	LevolutionType m_LevolutionType; //0x0000
	char _0x0004[4];
	char* m_LevolutionId; //0x0008
	unsigned __int16 m_X; //0x0010
	unsigned __int16 m_Y; //0x0012
	bool m_Activated; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00252
// TypeInfo:  0x000000014271A280
struct TabletCommanderScoringEventMessage
{
	char* m_Description; //0x0000
	float m_Score; //0x0008
	float m_RawScore; //0x000C
	unsigned __int8 m_StatEvent; //0x0010
	unsigned __int8 m_VisibilityType; //0x0011
	bool m_IsEnemyCommander; //0x0012
	char _0x0013[5];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00250
// TypeInfo:  0x000000014271A2A0
struct TabletCommanderPlayerKilledMessage
{
	unsigned __int32 m_KillerId; //0x0000
	unsigned __int32 m_VictimId; //0x0004
	char* m_WeaponName; //0x0008
	bool m_KilledByVehicle; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00248
// TypeInfo:  0x000000014271A2C0
struct TabletCommanderDeniedActionMessage
{
	unsigned __int8 m_ActionType; //0x0000
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 00246
// TypeInfo:  0x000000014271A2E0
struct TabletCommanderAcknowledgedActionMessage
{
	unsigned __int8 m_ActionType; //0x0000
};//Size=0x0001

////////////////////////////////////////
// RuntimeId: 00180
// TypeInfo:  0x0000000142719180
struct TabletCommanderActionState
{
	unsigned __int8 m_ActionType; //0x0000
	unsigned __int8 m_ActionState; //0x0001
	char _0x0002[2];
	TeamId m_TeamId; //0x0004
	float m_StateDuration; //0x0008
	float m_Radius; //0x000C
	unsigned __int16 m_TargetX; //0x0010
	unsigned __int16 m_TargetY; //0x0012
	bool m_IsExcluded; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00182
// TypeInfo:  0x000000014271A660
struct TabletCommanderCombatAreaPoint
{
	unsigned __int16 m_X; //0x0000
	unsigned __int16 m_Y; //0x0002
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 00240
// TypeInfo:  0x000000014271A340
struct TabletCommanderCommanderSwitchedTeamMessage
{
	TeamId m_TeamId; //0x0000
	TeamId m_EnemyTeamId; //0x0004
	__int32 m_Faction; //0x0008
	__int32 m_EnemyFaction; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00238
// TypeInfo:  0x000000014271A360
struct TabletCommanderLoadLevelRushMessage
{
	unsigned __int8 m_StartCratesCount; //0x0000
	unsigned __int8 m_CurrentCratesCount; //0x0001
	bool m_IsAttacker; //0x0002
};//Size=0x0003

////////////////////////////////////////
// RuntimeId: 00236
// TypeInfo:  0x000000014271A380
struct TabletCommanderLoadLevelSquadBarMessage
{
	Array<unsigned __int8> m_ActionTypes; //0x0000
	unsigned __int32 m_PointsPerSegment; //0x0008
	char _0x000C[4];
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00234
// TypeInfo:  0x000000014271A3A0
struct TabletCommanderLoadLevelLevolutionStateMessage
{
	Array<TabletCommanderLevolutionState> m_LevolutionStates; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00232
// TypeInfo:  0x000000014271A3C0
struct TabletCommanderLoadLevelActionStateMessage
{
	Array<TabletCommanderActionState> m_ActionStates; //0x0000
	RadarScanMode m_InfantryScanDir; //0x0008
	RadarScanMode m_VehicleScanDir; //0x000C
	unsigned __int32 m_EarlyWarningDuration; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00230
// TypeInfo:  0x000000014271A3E0
struct TabletCommanderLoadLevelPlayerDataMessage
{
	Array<TabletCommanderPlayerData> m_PlayerData; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00202
// TypeInfo:  0x000000014271A5A0
struct TabletCommanderLevolutionMiniMap
{
	char* m_Tag; //0x0000
	float m_Size; //0x0008
	unsigned __int16 m_X; //0x000C
	unsigned __int16 m_Y; //0x000E
	bool m_IsPatch; //0x0010
	char _0x0011[7];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00226
// TypeInfo:  0x000000014271A420
struct TabletCommanderJoinServerMessage
{
	char* m_ServerName; //0x0000
	char* m_ServerVersion; //0x0008
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00224
// TypeInfo:  0x000000014271A440
struct TabletCommanderPongMessage
{
	float m_PingTime; //0x0000
	float m_PongTime; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00222
// TypeInfo:  0x000000014271A460
struct TabletCommanderConnectionDeniedMessage
{
	unsigned __int32 m_TCServerProtocolVersion; //0x0000
	TabletCommanderConnectionDeniedReason m_DeniedReason; //0x0004
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00220
// TypeInfo:  0x000000014271A480
struct TabletCommanderConnectionApprovedMessage
{
	unsigned __int32 m_TCServerProtocolVersion; //0x0000
};//Size=0x0004

////////////////////////////////////////
// RuntimeId: 00164
// TypeInfo:  0x0000000142719220
struct TabletCommanderPacketBase
{
	TabletCommanderPacketType m_PacketType; //0x0000
	float m_ServerTime; //0x0004
	unsigned __int8 m_PacketFrequency; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 00216
// TypeInfo:  0x000000014271A4C0
struct TabletCommanderSquadRequest
{
	SquadId m_SquadId; //0x0000
	unsigned __int8 m_ActionType; //0x0004
	char _0x0005[3];
	unsigned __int32 m_ControlPointId; //0x0008
	unsigned __int16 m_TargetX; //0x000C
	unsigned __int16 m_TargetY; //0x000E
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00214
// TypeInfo:  0x000000014271A4E0
struct TabletCommanderOrder
{
	unsigned __int8 m_OrderType; //0x0000
	unsigned __int8 m_ReplyType; //0x0001
	char _0x0002[2];
	unsigned __int32 m_IssuedToPlayerId; //0x0004
	unsigned __int32 m_ControlPointId; //0x0008
	unsigned __int32 m_ControllableId; //0x000C
	unsigned __int16 m_TargetX; //0x0010
	unsigned __int16 m_TargetY; //0x0012
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 00212
// TypeInfo:  0x000000014271A500
struct TabletCommanderMapMarker
{
	unsigned __int32 m_MapMarkerId; //0x0000
	unsigned __int16 m_X; //0x0004
	unsigned __int16 m_Y; //0x0006
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00210
// TypeInfo:  0x000000014271A520
struct TabletCommanderObjective
{
	char* m_ObjectiveName; //0x0000
	char* m_LocationTextSid; //0x0008
	unsigned __int32 m_ObjectiveId; //0x0010
	TabletCommanderObjectiveType m_ObjectiveType; //0x0014
	unsigned __int8 m_ActionType; //0x0018
	char _0x0019[3];
	TeamId m_ControllingTeamId; //0x001C
	TeamId m_CapturingTeamId; //0x0020
	unsigned __int16 m_X; //0x0024
	unsigned __int16 m_Y; //0x0026
	__int16 m_ProgressVelocity; //0x0028
	unsigned __int8 m_ProgressValue; //0x002A
	bool m_Blink; //0x002B
	bool m_IsControlled; //0x002C
	char _0x002D[3];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00166
// TypeInfo:  0x0000000142719200
struct TabletCommanderNetworkState
{
	unsigned __int32 m_Id; //0x0000
	unsigned __int16 m_X; //0x0004
	unsigned __int16 m_Y; //0x0006
	unsigned __int8 m_Rotation; //0x0008
	char _0x0009[3];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 00168
// TypeInfo:  0x000000014271A6C0
struct TabletCommanderNetworkSoldierState
{
	TabletCommanderNetworkState m_NetworkState; //0x0000
	unsigned __int32 m_InVehicleId; //0x000C
	unsigned __int8 m_SoldierKit; //0x0010
	bool m_IsSquadLeader; //0x0011
	bool m_IsOnKillStreak; //0x0012
	bool m_IsHighValueTarget; //0x0013
	bool m_IsFiring; //0x0014
	char _0x0015[3];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00206
// TypeInfo:  0x000000014271A560
struct TabletCommanderHighFrequencyFriendlySquad
{
	SquadId m_SquadId; //0x0000
	float m_NormalizedSquadScore; //0x0004
	bool m_IsSquadWipeProtected; //0x0008
	bool m_IsSquadReinforced; //0x0009
	char _0x000A[6];
	Array<TabletCommanderNetworkSoldierState> m_Soldiers; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00228
// TypeInfo:  0x000000014271A400
struct TabletCommanderLoadLevelMessage
{
	char* m_LevelName; //0x0000
	TabletCommanderGameMode m_GameMode; //0x0008
	char _0x000C[4];
	char* m_CommanderName; //0x0010
	char* m_CommanderEmblem; //0x0018
	unsigned __int32 m_CommanderPlayerId; //0x0020
	float m_WorldSize; //0x0024
	float m_WorldCenterX; //0x0028
	float m_WorldCenterY; //0x002C
	float m_WorldRotation; //0x0030
	unsigned __int32 m_RoundTimeLimit; //0x0034
	unsigned __int32 m_PreRoundPlayerRequiredCount; //0x0038
	bool m_RoundInPreRoundState; //0x003C
	unsigned __int8 m_MaxPlayerCount; //0x003D
	unsigned __int8 m_CurrentPlayerCount; //0x003E
	unsigned __int8 m_MaxCommanderCount; //0x003F
	unsigned __int8 m_CurrentCommanderCount; //0x0040
	char _0x0041[7];
	Array<TabletCommanderLevolutionMiniMap> m_LevolutionMiniMaps; //0x0048
	bool m_RoundEnded; //0x0050
	char _0x0051[7];
};//Size=0x0058

////////////////////////////////////////
// RuntimeId: 00200
// TypeInfo:  0x0000000142719100
struct TabletCommanderMutinyState
{
	float m_MutinyTreshold; //0x0000
	unsigned __int32 m_MutinyDuration; //0x0004
	unsigned __int8 m_ActiveSquadCount; //0x0008
	unsigned __int8 m_NegativeRatingCount; //0x0009
	char _0x000A[2];
};//Size=0x000C

////////////////////////////////////////
// RuntimeId: 00198
// TypeInfo:  0x000000014271A5C0
struct TabletCommanderServiceStarProgression
{
	TabletCommanderAwardData m_ServiceStarAwardData; //0x0000
	TabletCommanderAwardCriteria m_Criteria; //0x0030
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00194
// TypeInfo:  0x000000014271A5E0
struct TabletCommanderRankLevelData
{
	unsigned __int32 m_RankPointsNeeded; //0x0000
	unsigned __int8 m_RankNumber; //0x0004
	char _0x0005[3];
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00196
// TypeInfo:  0x0000000142719120
struct TabletCommanderRankProgression
{
	Array<TabletCommanderRankLevelData> m_RankLevelData; //0x0000
	unsigned __int32 m_OriginalGlobalScore; //0x0008
	unsigned __int32 m_CurrentGlobalScore; //0x000C
	float m_ScoreMultiplier; //0x0010
	char _0x0014[4];
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00190
// TypeInfo:  0x000000014271A620
struct TabletCommanderDogTagData
{
	char* m_Name; //0x0000
	char* m_Description; //0x0008
	char* m_ImageName; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00192
// TypeInfo:  0x000000014271A600
struct TabletCommanderAssignment
{
	TabletCommanderAwardData m_AssignmentAwardData; //0x0000
	Array<TabletCommanderAwardData> m_Dependencies; //0x0030
	Array<TabletCommanderAwardCriteria> m_Criterias; //0x0038
	Array<TabletCommanderDogTagData> m_DogTags; //0x0040
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00260
// TypeInfo:  0x000000014271A200
struct TabletCommanderRoundOverMessage
{
	TeamId m_WinningTeam; //0x0000
	unsigned __int32 m_RoundTime; //0x0004
	unsigned __int32 m_EoRTime; //0x0008
	char _0x000C[4];
	Array<TabletCommanderAssignment> m_Assignments; //0x0010
	TabletCommanderRankProgression m_RankProgress; //0x0018
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00264
// TypeInfo:  0x000000014271A1C0
struct TabletCommanderAwardGainedMessage
{
	TabletCommanderAwardData m_Award; //0x0000
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00262
// TypeInfo:  0x000000014271A1E0
struct TabletCommanderScoreBoardMessage
{
	Array<TabletCommanderScoreBoardData> m_ScoreData; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00242
// TypeInfo:  0x000000014271A320
struct TabletCommanderCombatAreaMessage
{
	Array<TabletCommanderCombatAreaPoint> m_CombatAreaPoints; //0x0000
};//Size=0x0008

////////////////////////////////////////
// RuntimeId: 00244
// TypeInfo:  0x000000014271A300
struct TabletCommanderActionEnteredStateMessage
{
	TabletCommanderActionState m_ActionState; //0x0000
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00256
// TypeInfo:  0x000000014271A240
struct TabletCommanderPlayerJoinedMessage
{
	TabletCommanderPlayerData m_PlayerData; //0x0000
};//Size=0x0020

////////////////////////////////////////
// RuntimeId: 00254
// TypeInfo:  0x000000014271A260
struct TabletCommanderLevolutionMessage
{
	TabletCommanderLevolutionState m_LevolutionState; //0x0000
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00174
// TypeInfo:  0x00000001427191E0
struct TabletCommanderTickets
{
	unsigned __int32 m_FriendTickets; //0x0000
	unsigned __int32 m_FriendMaxTickets; //0x0004
	unsigned __int32 m_EnemyTickets; //0x0008
	unsigned __int32 m_EnemyMaxTickets; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00172
// TypeInfo:  0x000000014271A680
struct TabletCommanderNetworkBombState
{
	TabletCommanderNetworkState m_NetworkState; //0x0000
	TeamId m_TeamId; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00170
// TypeInfo:  0x000000014271A6A0
struct TabletCommanderNetworkVehicleState
{
	TabletCommanderNetworkState m_NetworkState; //0x0000
	unsigned __int32 m_IconType; //0x000C
	bool m_IsFiring; //0x0010
	char _0x0011[3];
};//Size=0x0014

////////////////////////////////////////
// RuntimeId: 00208
// TypeInfo:  0x000000014271A540
struct TabletCommanderLowFrequencyPacket
{
	TabletCommanderPacketBase m_PacketBase; //0x0000
	char _0x000C[4];
	Array<TabletCommanderNetworkSoldierState> m_FriendlyDeadSoldierList; //0x0010
	Array<TabletCommanderObjective> m_ObjectiveList; //0x0018
	Array<TabletCommanderOrder> m_OrderList; //0x0020
	Array<TabletCommanderSquadRequest> m_SquadRequestList; //0x0028
	Array<TabletCommanderMapMarker> m_MapMarkerList; //0x0030
	TabletCommanderTickets m_Tickets; //0x0038
	TabletCommanderMutinyState m_MutinyState; //0x0048
	unsigned __int32 m_RoundTimeSeconds; //0x0054
	unsigned __int32 m_SquadPoints; //0x0058
	unsigned __int32 m_PreRoundPlayerReadyCount; //0x005C
	unsigned __int32 m_PreRoundRestartTime; //0x0060
	__int32 m_ObliterationTargetsArmedBitmask; //0x0064
	__int32 m_ObliterationTargetsDestroyedBitmask; //0x0068
	unsigned __int8 m_CurrentCratesCount; //0x006C
	char _0x006D[3];
};//Size=0x0070

////////////////////////////////////////
// RuntimeId: 00204
// TypeInfo:  0x000000014271A580
struct TabletCommanderHighFrequencyPacket
{
	TabletCommanderPacketBase m_PacketBase; //0x0000
	char _0x000C[4];
	Array<TabletCommanderHighFrequencyFriendlySquad> m_FriendlySquadList; //0x0010
	Array<TabletCommanderNetworkVehicleState> m_FriendlyVehicleList; //0x0018
	Array<TabletCommanderNetworkState> m_FriendlyTomahawkList; //0x0020
	Array<TabletCommanderNetworkSoldierState> m_SpottedEnemySoldierList; //0x0028
	Array<TabletCommanderNetworkVehicleState> m_SpottedEnemyVehicleList; //0x0030
	Array<TabletCommanderNetworkState> m_SpottedEnemyTomahawkList; //0x0038
	Array<TabletCommanderNetworkBombState> m_ObliterationBomb; //0x0040
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00218
// TypeInfo:  0x000000014271A4A0
struct TabletCommanderMessageListPacket
{
	TabletCommanderPacketBase m_PacketBase; //0x0000
	char _0x000C[4];
	Array<TabletCommanderMessageType> m_MessageTypeList; //0x0010
};//Size=0x0018

////////////////////////////////////////
// RuntimeId: 00142
// TypeInfo:  0x0000000142719280
struct UavCameraPointData
{
	float m_MinTime; //0x0000
	float m_MaxTime; //0x0004
	float m_Speed; //0x0008
	float m_AccelerationTime; //0x000C
};//Size=0x0010

////////////////////////////////////////
// RuntimeId: 00140
// TypeInfo:  0x00000001427192A0
struct PunkBusterExecCmdMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00139
// TypeInfo:  0x00000001427192C0
struct PunkBusterMessageMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00138
// TypeInfo:  0x00000001427192E0
struct ServerUnlockListRefreshMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00137
// TypeInfo:  0x0000000142719300
struct ServerUnlockListEventMessageBase
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00134
// TypeInfo:  0x0000000142719340
struct ServerReservedSlotsListAggressiveJoinVIPPlayerMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00133
// TypeInfo:  0x0000000142719360
struct ServerReservedSlotsListEventMessageBase
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00132
// TypeInfo:  0x0000000142719380
struct ServerBanListEventMessageBase
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00131
// TypeInfo:  0x00000001427193A0
struct NetworkGameAdministrationAddGameBanResponseMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00128
// TypeInfo:  0x00000001427193E0
struct NetworkGameAdministrationAddGameBanRequestMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00127
// TypeInfo:  0x0000000142719400
struct NetworkGameAdministrationPacketMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00126
// TypeInfo:  0x0000000142719420
struct ServerGameAdministrationUpdateGameServerListsMessage
{
	char _0x0000[64];
};//Size=0x0040

////////////////////////////////////////
// RuntimeId: 00125
// TypeInfo:  0x0000000142719440
struct ServerGameAdministrationResetServerMessage
{
	char _0x0000[72];
};//Size=0x0048

////////////////////////////////////////
// RuntimeId: 00124
// TypeInfo:  0x0000000142719460
struct ServerGameAdministrationRefreshGameAttributesMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00123
// TypeInfo:  0x0000000142719480
struct ServerGameAdministrationGameSettingsUpdateMessage
{
	char _0x0000[152];
};//Size=0x0098

////////////////////////////////////////
// RuntimeId: 00122
// TypeInfo:  0x00000001427194A0
struct ServerGameAdministrationEventMessageBase
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00121
// TypeInfo:  0x00000001427194C0
struct ClientPersistenceUnlockMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00120
// TypeInfo:  0x00000001427194E0
struct PresenceStateRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00119
// TypeInfo:  0x0000000142719500
struct PresenceStateMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00118
// TypeInfo:  0x0000000142719520
struct PresenceXPromoRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00117
// TypeInfo:  0x0000000142719540
struct PresenceXPromoMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00116
// TypeInfo:  0x0000000142719560
struct PresenceWebRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00115
// TypeInfo:  0x0000000142719580
struct PresenceWebFeedRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00114
// TypeInfo:  0x00000001427195A0
struct PresenceWebAuthenticationRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00113
// TypeInfo:  0x00000001427195C0
struct PresenceWebAuthenticationMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00112
// TypeInfo:  0x00000001427195E0
struct PresenceWebMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00111
// TypeInfo:  0x0000000142719600
struct PresenceUserTitleInfoRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00110
// TypeInfo:  0x0000000142719620
struct PresenceUserTitleInfoMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00109
// TypeInfo:  0x0000000142719640
struct PresenceUserProfileInfoMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00108
// TypeInfo:  0x0000000142719660
struct PresenceUserSettingsRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00107
// TypeInfo:  0x0000000142719680
struct PresenceUserSettingsMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00106
// TypeInfo:  0x00000001427196A0
struct PresenceConsoleNewsRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00105
// TypeInfo:  0x00000001427196C0
struct PresenceConsoleNewsMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00104
// TypeInfo:  0x00000001427196E0
struct PresenceStoreRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00103
// TypeInfo:  0x0000000142719700
struct PresenceStoreMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00102
// TypeInfo:  0x0000000142719720
struct PresenceServerRentalRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00101
// TypeInfo:  0x0000000142719740
struct PresenceServerRentalMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00100
// TypeInfo:  0x0000000142719760
struct PresenceServerBrowserRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00099
// TypeInfo:  0x0000000142719780
struct PresenceServerBrowserMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00098
// TypeInfo:  0x00000001427197A0
struct PresencePlayerEmblemRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00097
// TypeInfo:  0x00000001427197C0
struct PresencePlayerEmblemMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00096
// TypeInfo:  0x00000001427197E0
struct PresenceSetupInfoMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00095
// TypeInfo:  0x0000000142719800
struct PresenceServerBannerRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00094
// TypeInfo:  0x0000000142719820
struct PresenceServerBannerMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00093
// TypeInfo:  0x0000000142719840
struct PresenceRspRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00092
// TypeInfo:  0x0000000142719860
struct PresenceRspMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00091
// TypeInfo:  0x0000000142719880
struct PresenceResetStorageRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00090
// TypeInfo:  0x00000001427198A0
struct PresenceResetStorageMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00089
// TypeInfo:  0x00000001427198C0
struct PresenceProgressionRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00088
// TypeInfo:  0x00000001427198E0
struct PresenceProgressionMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00087
// TypeInfo:  0x0000000142719900
struct PresencePingUpdatedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00086
// TypeInfo:  0x0000000142719920
struct PresencePlaygroundRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00085
// TypeInfo:  0x0000000142719940
struct PresencePeerGameRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00084
// TypeInfo:  0x0000000142719960
struct PresencePeerGameMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00083
// TypeInfo:  0x0000000142719980
struct PresencePartyRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00082
// TypeInfo:  0x00000001427199A0
struct PresencePartyMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00081
// TypeInfo:  0x00000001427199C0
struct PresenceNucleusLoginUIRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00080
// TypeInfo:  0x00000001427199E0
struct PresenceMigrateDataRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00079
// TypeInfo:  0x0000000142719A00
struct PresenceMigrateDataMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00078
// TypeInfo:  0x0000000142719A20
struct PresenceMatchFeedMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00077
// TypeInfo:  0x0000000142719A40
struct PresenceGameDataRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00076
// TypeInfo:  0x0000000142719A60
struct PresenceGameDataMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00075
// TypeInfo:  0x0000000142719A80
struct PresenceGameConfigurationRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00074
// TypeInfo:  0x0000000142719AA0
struct PresenceGameConfigurationMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00073
// TypeInfo:  0x0000000142719AC0
struct PresenceFriendsStatsRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00072
// TypeInfo:  0x0000000142719AE0
struct PresenceFriendsStatsMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00071
// TypeInfo:  0x0000000142719B00
struct PresenceDownloadRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00070
// TypeInfo:  0x0000000142719B20
struct PresenceDownloadMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00069
// TypeInfo:  0x0000000142719B40
struct PresencePushNotificationMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00068
// TypeInfo:  0x0000000142719B60
struct PresenceCommMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00067
// TypeInfo:  0x0000000142719B80
struct PresenceChallengesRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00066
// TypeInfo:  0x0000000142719BA0
struct PresenceChallengesMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00065
// TypeInfo:  0x0000000142719BC0
struct PresenceCalendarRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00064
// TypeInfo:  0x0000000142719BE0
struct PresenceCalendarMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00063
// TypeInfo:  0x0000000142719C00
struct PresenceBFCommerceMetricMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00062
// TypeInfo:  0x0000000142719C20
struct PresenceBFCommerceRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00061
// TypeInfo:  0x0000000142719C40
struct PresenceBFCommerceMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00060
// TypeInfo:  0x0000000142719C60
struct PresenceBattlepackRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00059
// TypeInfo:  0x0000000142719C80
struct PresenceBattlepackMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00058
// TypeInfo:  0x0000000142719CA0
struct PresenceBattlelogRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00057
// TypeInfo:  0x0000000142719CC0
struct PresenceBattlelogMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00056
// TypeInfo:  0x0000000142719CE0
struct PresenceAuthenticationRequestMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00055
// TypeInfo:  0x0000000142719D00
struct PresenceAuthenticationMessageBase
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00054
// TypeInfo:  0x0000000142719D20
struct NuiGrammarLoadCompletedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00053
// TypeInfo:  0x0000000142719D40
struct NuiCheckSpeechRecognizingMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00052
// TypeInfo:  0x0000000142719D60
struct NuiSpeechGrammarActivationSettingsMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00051
// TypeInfo:  0x0000000142719D80
struct NuiSpeechGrammarDeactivationMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00050
// TypeInfo:  0x0000000142719DA0
struct NuiSpeechGrammarActivationMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00049
// TypeInfo:  0x0000000142719DC0
struct NuiSpeechProblemDetectedMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00048
// TypeInfo:  0x0000000142719DE0
struct NuiSpeechOngoingActivityMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00047
// TypeInfo:  0x0000000142719E00
struct NuiSpeechRuleRecognitionFailedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00046
// TypeInfo:  0x0000000142719E20
struct NuiSpeechRuleRecognitionStartsMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00045
// TypeInfo:  0x0000000142719E40
struct NuiSpeechSoundEventMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00044
// TypeInfo:  0x0000000142719E60
struct NuiSpeechRuleRecognizedMessage
{
	char _0x0000[80];
};//Size=0x0050

////////////////////////////////////////
// RuntimeId: 00043
// TypeInfo:  0x0000000142719E80
struct VeniceClientMetricsQuitSPGameMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00042
// TypeInfo:  0x0000000142719EA0
struct VeniceClientMetricsRestartSPMissionMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00041
// TypeInfo:  0x0000000142719EC0
struct VeniceClientMetricsRestartSPCheckpointMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00040
// TypeInfo:  0x0000000142719EE0
struct VeniceClientMetricsResumeSPGameMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00039
// TypeInfo:  0x0000000142719F00
struct VeniceClientMetricsStartSPGameMessage
{
	char _0x0000[56];
};//Size=0x0038

////////////////////////////////////////
// RuntimeId: 00038
// TypeInfo:  0x0000000142719F20
struct VeniceClientMetricsBootMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00037
// TypeInfo:  0x0000000142719F40
struct VeniceClientMetricsLeaveCriticalHealthMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00036
// TypeInfo:  0x0000000142719F60
struct VeniceClientMetricsEnterCriticalHealthMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00035
// TypeInfo:  0x0000000142719F80
struct VeniceClientMetricsTimeMessage
{
	char _0x0000[48];
};//Size=0x0030

////////////////////////////////////////
// RuntimeId: 00034
// TypeInfo:  0x0000000142719FA0
struct VeniceClientMetricsListenerDestroyedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00033
// TypeInfo:  0x0000000142719FC0
struct VeniceClientMetricsListenerCreatedMessage
{
	char _0x0000[40];
};//Size=0x0028

////////////////////////////////////////
// RuntimeId: 00020
// TypeInfo:  0x0000000142714418
struct DVRScoringChainMomentMessage
{
	char _0x0000[48];
};//Size=0x0030
}