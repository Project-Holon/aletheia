/*
 * file:     nwm_setwepkey.c
 * unit:     yes
 * function: NWM_SetWEPKey
 * address:  0x027034C0
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_setwepkey.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommandDirect  0x02703B24  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct TwlWork {
    u8 pad[0x2278];
    u8 *busy;
} TwlWork;

typedef struct TwlMsg {
    u16 len;
    u16 w2;
    u16 w4;
    u16 w6;
    u8 data[0x50];
} TwlMsg;

extern u32 NWMi_CheckState(u32, u32);
extern TwlWork *NWMi_GetSystemWork(void);
extern void DC_InvalidateRange(u8 *, u32);
extern void DC_StoreRange(const void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(void *, u32);

u32 NWM_SetWEPKey(u32 callback, u32 wepMode, u32 keyId, const u8 *wepKey, u16 flags) {
    u32 r;
    u32 busy;
    u32 kind;
    TwlWork *w;
    TwlMsg msg;

    r = NWMi_CheckState(1, 3);
    if (r != 0 && r != 2) {
        return r;
    }
    w = NWMi_GetSystemWork();
    if (w != 0) {
        DC_InvalidateRange(w->busy + 13, 1);
        busy = (w->busy[13] == 1);
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    switch (wepMode) {
    case 0:
        kind = 0;
        break;
    case 1:
        kind = 5;
        break;
    case 2:
        kind = 13;
        break;
    case 3:
        kind = 16;
        break;
    default:
        return 5;
    }
    DC_StoreRange(wepKey, 0x50);
    NWMi_SetCallbackTable(13, callback);
    msg.len = 13;
    msg.w4 = keyId;
    msg.w6 = kind;
    msg.w2 = flags;
    MI_CpuCopy8(wepKey, msg.data, 0x50);
    r = NWMi_SendCommandDirect(&msg, 0x58);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
