#pragma once

#include <string>
class TextureData;
class ImagePickingCallback;
class FilePickerSettings;
class PushNotificationMessage;
class ResourceLocation;
class UriListener;
class ActivationUri;
class Vec2;
enum class ControllerType;
enum class FullscreenMode;
class AppPlatform {
public:
    virtual ~AppPlatform();
    virtual void* getDataUrl() const = 0;
    virtual void* getUserDataUrl() const = 0;
    virtual void* getAlternateDataUrl() const;
    virtual std::string getPackagePath() = 0;
    virtual void* loadPNG(TextureData&, std::string const&);
    virtual void* loadTGA(TextureData&, std::string const&);
    virtual void* loadJPEG(TextureData&, std::string const&);
    virtual void* getKeyFromKeyCode(int, int, int);
    virtual void* showKeyboard(std::string const&, int, bool, bool, bool, Vec2 const&);
    virtual void* hideKeyboard();
    virtual void* isFullScreenKeyboard() const;
    virtual void* getKeyboardHeight() const;
    virtual void* hideMousePointer();
    virtual void* showMousePointer();
    virtual void* getPointerFocus();
    virtual void* setPointerFocus(bool);
    virtual void* toggleSimulateTouchWithMouse();
    virtual void* _fireLowMemory();
    virtual void* _fireAppSuspended();
    virtual void* _fireAppResumed();
    virtual void* _fireAppFocusLost();
    virtual void* _fireAppFocusGained();
    virtual void* _fireAppTerminated();
    virtual void* _fireAppConfigurationChanged();
    virtual void* _fireAppPaused();
    virtual void* swapBuffers() = 0;
    virtual void* discardBackbuffer();
    virtual void* getSystemRegion() const = 0;
    virtual void* getGraphicsTearingSupport() = 0;
    virtual void* pickImage(ImagePickingCallback&) = 0;
    virtual void* pickFile(FilePickerSettings&);
    virtual void* supportsFilePicking() const;
    virtual void* supportsClipboard() const;
    virtual void* setClipboard(std::string const&) const;
    virtual void* pushNotificationReceived(PushNotificationMessage const&);
    virtual void* createHolographicPlatform(bool) const;
    virtual void* createAndroidLaunchIntent();
    virtual void* updateLocalization(std::string const&);
    virtual void* setSleepEnabled(bool);
    virtual void* getExternalStoragePath() = 0;
    virtual void* getInternalStoragePath() = 0;
    virtual void* getUserdataPath() = 0;
    virtual void* getUserdataPathForLevels();
    virtual void* getApiEnvironmentPath();
    virtual void* showDialog(int);
    virtual void* createUserInput();
    virtual void* getUserInputStatus();
    virtual void* getUserInput();
    virtual void* getFileInterface(ResourceLocation const&);
    virtual void* getScreenWidth();
    virtual void* getScreenHeight();
    virtual void* setScreenSize(int, int);
    virtual void* setWindowSize(int, int);
    virtual void* setWindowText(std::string const&);
    virtual void* getPixelsPerMillimeter();
    virtual void* updateTextBoxText(std::string const&);
    virtual void* isKeyboardVisible();
    virtual void* supportsVibration();
    virtual void* vibrate(int);
    virtual void* getAssetFileFullPath(std::string const&);
    virtual void* readAssetFile(std::string const&);
    virtual void* readAssetFileZipped(std::string const&, std::string const&);
    virtual void* listAssetFilesIn(std::string const&, std::string const&) const;
    virtual void* getDateString(int);
    virtual void* checkLicense();
    virtual void* hasBuyButtonWhenInvalidLicense();
    virtual void* uploadPlatformDependentData(int, void*);
    virtual void* isNetworkEnabled(bool);
    virtual void* buyGame();
    virtual void* finish();
    virtual void* launchUri(std::string const&);
    virtual void* useXboxControlHelpers() const;
    virtual void* useCenteredGUI() const;
    virtual void* showPointMenuCursor() const;
    virtual void* getPlatformType() const;
    virtual void* getBuildPlatform() const;
    virtual void* setControllerType(ControllerType);
    virtual void* getControllerType() const;
    virtual void* hasIDEProfiler();
    virtual void* getPlatformStringVar(int);
    virtual void* getApplicationId() = 0;
    virtual void* getAvailableMemory();
    virtual void* getTotalMemory();
    virtual void* getUsedMemory();
    virtual void* getBroadcastAddresses();
    virtual void* getIPAddresses();
    virtual void* getModelName();
    virtual void* getDeviceId() = 0;
    virtual void* createUUID() = 0;
    virtual void* isFirstSnoopLaunch() = 0;
    virtual void* hasHardwareInformationChanged() = 0;
    virtual void* isTablet() = 0;
    virtual void* registerUriListener(UriListener&);
    virtual void* registerUriListener(std::string const&, UriListener&);
    virtual void* unregisterUriListener(UriListener const&);
    virtual void* notifyUriListeners(ActivationUri const&);
    virtual void* notifyUriListenerRegistrationDone();
    virtual void* setFullscreenMode(FullscreenMode);
    virtual void* isNetworkThrottled();
    virtual void* collectGraphicsHardwareDetails();
    virtual void* getEdition() const;
    virtual void* realmsBeta() const;
    virtual void* isFireTV() const;
    virtual void* getDefaultInputMode() const;
    virtual void* calculateAvailableDiskFreeSpace(std::string const&) = 0;
    virtual void* speakTextToSpeech(std::string const&);
    virtual void* setTextToSpeechEnabled(bool);
    virtual void* stopTextToSpeech();
    virtual void* isTextToSpeechSpeaking();
    virtual void* _notifyUriListeners(ActivationUri const&, bool);
    virtual void* getPlatformDpi() const;
    virtual void* getPlatformUIScalingRules() const;
    virtual void* getPlatformTempPath() = 0;
};
