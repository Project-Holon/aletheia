#ifndef GAME_OV000_WIFI_LOGIN_PARAM_TYPES_H
#define GAME_OV000_WIFI_LOGIN_PARAM_TYPES_H

#include "../types.h"

struct GameData;

/* Parameter block read by the Wi-Fi login overlay (ov115), 0x28 bytes. */
typedef struct WifiLoginParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
    u32 result;
    u32 reserved[2];
} WifiLoginParam;

/* Short parameter block of the second ov115 call (session confirm), 0x1C bytes. */
typedef struct WifiConfirmParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
} WifiConfirmParam;

#endif
