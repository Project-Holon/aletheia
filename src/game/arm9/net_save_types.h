#ifndef GAME_ARM9_NET_SAVE_TYPES_H
#define GAME_ARM9_NET_SAVE_TYPES_H

#include "../types.h"
#include "../ov000/wifi_login_param_types.h"

struct GameData;

/* Argument block of the ov123 save check proc. */
struct NetSaveCheckArgs {
    struct GameData *gameData;
    u8 *saveBuf;
    u16 heapId;
    u8 pad[2];
};

/* The 0x1D8-byte net_save.c save task record. */
struct NetSaveProcWork {
    WifiLoginParam login;                   /* +0x00: argument block of the ov115 login proc (result at +0x1C) */
    WifiConfirmParam confirm;               /* +0x28: argument block of the ov115 confirm proc */
    struct GameData *gameData;              /* +0x44 */
    struct NetSaveCheckArgs checkArgs;      /* +0x48 */
    u32 skipFinalSave;                      /* +0x54 */
    u32 saveFailed;                         /* +0x58 */
    u8 saveBuf[0x174];                      /* +0x5C */
    u16 heapId;                             /* +0x1D0 */
    u8 pad1D2[2];
    u32 state;                              /* +0x1D4 */
};

#endif
