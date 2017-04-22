#pragma once

#include <memory>
#include <string>
#include <deque>
#include "../client/MinecraftClient.h"

class MinecraftUISoundPlayer;
class ProgressHandler;
enum CraftingType;
class PatchNotesModel;
namespace Realms {
	class World;
};
class AbstractScreen;
enum PlayScreenDefaultTab;
class MashupData;
enum StoreNavigationOrigin;
enum SettingsTabIndex;
namespace Social {
	class SignInResult;
};
class LevelSummary;
enum StorageVersion;
class RealmsCreateParams;
class ResourceLocation;
enum RealmsOfferTier;
class PackDependencyManager;
class BaseScreen;
class AbstractScreenSetupCleanupStrategy;
class Player;
class BlockPos;
struct EntityUniqueID;
class SignBlockEntity;
class ChalkboardBlockEntity;

class ScreenChooser {
public:

	/* 0x00 */ MinecraftClient& client;
	/* 0x04 */ std::unique_ptr<MinecraftUISoundPlayer> soundplayer;
	/* 0x08 */ bool canInvite;
	/* 0x0C */ char filler1[8]; // no idea what this is used for
	/* size = 0x14 */

	// non virtual
	ScreenChooser(MinecraftGame&, ClientInstance&, bool);
	~ScreenChooser();
	void schedulePopScreen(int);
	void setDisconnectScreen(std::string const&, std::string const&, std::string const&);
	void pushImportExportProgressScreen(std::string const&, std::string const&);
	void setCanInvite(bool);
	void* getPlayScreen();
	void pushChatScreen();
	void pushDebugScreen();
	void pushPauseScreen();
	void pushToastScreen();
	void pushUpsellScreen(bool);
	void pushConsoleScreen();
	void pushVRAlignScreen();
	void setStartMenuScreen();
	void pushInventoryScreen(CraftingType);
	void pushMobEffectsScreen();
	void pushNoWifiWarningScreen();
	void pushRealmsWarningScreen(Realms::World const&, std::string const&, int);
	void pushXblFirstLaunchScreen();
	void pushHolographicCursorScreen();
	void pushNoInvitesOrJoiningScreen();
	void pushCellularDataWarningScreen(std::function<void (bool)>);
	void pushRealmsPendingInvitesScreen(bool);
	void pushHolographicPostRenderScreen();
	bool isInBedScreen(AbstractScreen const&) const;
	void pushRealityModeTransitionScreen();
	void pushRealityScreen();
	void pushHudScreen();
	void setGameplayScreen();
	void pushPlayScreen(PlayScreenDefaultTab);
	void pushInviteScreen();
	void pushMashupScreen(MashupData&, StoreNavigationOrigin);
	void pushLanguageScreen();
	void pushPortfolioScreen();
	void pushVRControlScreen(bool);
	void setLeaveLevelScreen();
	void pushSkinPickerScreen();
	void pushAchievementScreen();
	void pushCreateWorldScreen();
	void pushMakeInfiniteScreen(LevelSummary const&, StorageVersion);
	void pushRealmsCreateScreen(RealmsCreateParams const&);
	void pushVRInformationScreen();
	void pushWorldTemplateScreen(bool);
	void pushRealmsSettingsScreen(Realms::World const&);
	void pushRealmsWhitelistScreen(Realms::World const&);
	void pushFileCopyProgressScreen(std::string const&, ResourceLocation const&, bool, std::string const&, bool, std::function<void (bool)>);
	void pushLocalWorldPickerScreen(std::string const&);
	void pushCreateWorldUpsellScreen(bool, RealmsOfferTier, bool, bool, std::string const&);
	void pushXblOptionalSignInScreen(std::string const&, std::string const&, std::string const&, std::string const&, std::function<void ()>);
	void pushFileDownloadProgressScreen(std::string const&, std::string const&);
	void pushCreateWorldFromTemplateScreen(LevelSummary const&);
	bool isLevelLoadingProgressScreen(AbstractScreen&) const;
	void pushEditWorldScreen(LevelSummary const&);
	void pushFileUploadProgressScreen(std::string const&, std::string const&, bool);
	void pushAddEditExternalServerScreen(int);
	void _pushScreen(std::shared_ptr<BaseScreen>, bool);
	void _pushScreen(std::shared_ptr<BaseScreen>, std::unique_ptr<AbstractScreenSetupCleanupStrategy, std::default_delete<AbstractScreenSetupCleanupStrategy>>, bool);
	void pushAnvilScreen(Player&, BlockPos const&);
	void pushChestScreen(Player&, EntityUniqueID);
	void pushChestScreen(Player&, BlockPos const&);
	void pushDeathScreen();
	void pushHorseScreen(Player&, EntityUniqueID const&);
	void pushInBedScreen(Player&);
	void pushBeaconScreen(Player&, BlockPos const&);
	void pushHopperScreen(Player&, EntityUniqueID const&);
	void pushHopperScreen(Player&, BlockPos const&);
	void _pushInviteScreen();
	void pushCreditsScreen(std::function<void ()>);
	void pushDropperScreen(Player&, BlockPos const&);
	void pushFurnaceScreen(Player&, BlockPos const&);
	void pushDispenserScreen(Player&, BlockPos const&);
	void pushWorkbenchScreen(BlockPos const&, bool);
	void pushChalkboardScreen(ChalkboardBlockEntity&);
	void pushEnchantingScreen(Player&, BlockPos const&);
	void pushGlobalPauseScreen();
	void pushNpcInteractScreen(Player&, Entity&, bool);
	void _pushAchievementScreen();
	void pushBrewingStandScreen(Player&, BlockPos const&);
	void pushNetherProgressScreen(bool);
	void pushCommandBlockScreen(Player&, BlockPos const&);
	void pushCommandBlockMinecartScreen(Player&, EntityUniqueID const&);
	void pushCoinPurchaseScreen();
	void pushDevConsole();
	void pushTradeScreen(Player&, EntityUniqueID const&);
	void pushRealmsPurchaseInfoScreen();
	void pushEncryptionWarningScreen(std::function<void (bool)>);
	void pushProgressScreen(std::string const&, std::unique_ptr<ProgressHandler, std::default_delete<ProgressHandler>>, bool);
	void pushResourcePackPurchaseScreen(StoreCatalogItemModel const&, StoreNavigationOrigin);
	void pushStoreHomeScreen(std::string const&);
	void pushSkinPackPurchaseScreen(std::string const&, std::string const&);
	void pushSkinPackUpsellScreen(std::string const&, std::string const&, int);
	void pushStoreItemListScreen(std::string const&, std::string const&, std::string const&);
	void pushStructureEditor(BlockPos const&);
	void pushThirdPartyStoreScreen();
	void pushPatchNotesScreen(std::unique_ptr<PatchNotesModel, std::default_delete<PatchNotesModel>>);
	void pushProgressScreen(std::string const&, std::deque<std::unique_ptr<ProgressHandler, std::default_delete<ProgressHandler>>, std::allocator<std::unique_ptr<ProgressHandler, std::default_delete<ProgressHandler>>>>, bool);
	void pushModalProgressScreen(std::string const&, std::unique_ptr<ProgressHandler, std::default_delete<ProgressHandler>>, bool, bool);
	void pushRealmsJoinProgressScreen(std::string const&, std::unique_ptr<ProgressHandler, std::default_delete<ProgressHandler>>, std::unique_ptr<ProgressHandler, std::default_delete<ProgressHandler>>, bool);
	void pushNetworkProgressScreen(std::string const&, std::unique_ptr<ProgressHandler, std::default_delete<ProgressHandler>>);
	void pushDlcProgressScreen(std::vector<std::string, std::allocator<std::string>> const&, std::function<void (bool)>, bool);
	void pushSafeZoneScreen();
	void* pushSignScreen(BlockPos const&);
	void* pushManifestValidationScreen(PackManifestFactory&, ResourceLocation const&, std::string const&, bool, PackContentItem const*);
	void* pushOptionsScreen(SettingsTabIndex, bool);
	void* pushWorldSeedCatalogScreen(std::function<void (std::string const&, std::string const&, std::string const&)>);
	void* _getUIScreenSetupStrategy(bool);
	void pushAcceptDeclineInvitationScreen(std::string&, std::string&, std::function<void (bool)>);
	void setActiveDirectoryAuthenticationScreen();
	void pushActiveDirectoryAuthenticationScreen();
	bool isModalScreen(AbstractScreen&) const;
	void* getSoundPlayer() const;
	void* createGlobalVars() const;
	bool isProgressScreen(AbstractScreen&) const;
	bool isAchievementsScreen(AbstractScreen&) const;
	bool isPendingInvitesScreen(AbstractScreen&) const;
	bool _isInGame() const;

};
