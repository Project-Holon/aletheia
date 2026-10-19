/*
 * file:     nwm_wpa.c
 * unit:     yes
 * function: NWM_SetWPAPSK
 * address:  0x02703960
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_wpa.o
 *
 * symbols:
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommandDirect  0x02703B24  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct TwlReq {
    u16 kind;
    u8 data[0x20];
} TwlReq;

typedef struct TwlMsg {
    u16 len;
    u16 kind;
    u8 data[0x20];
} TwlMsg;

extern u32 NWMi_CheckState(u32 n, ...);
extern void DC_StoreRange(const void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(u32 command, u32 length);

u32 NWM_SetWPAPSK(u32 callback, TwlReq *pskInfo) {
    u32 r;
    TwlMsg msg;

    r = NWMi_CheckState(1, 3);
    if (r != 0 && r != 2) {
        return r;
    }
    if (pskInfo == 0) {
        return 5;
    }
    DC_StoreRange(pskInfo, 0x22);
    switch (pskInfo->kind) {
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    default:
        return 5;
    }
    NWMi_SetCallbackTable(0x12, callback);
    msg.len = 0x12;
    msg.kind = pskInfo->kind;
    MI_CpuCopy8(pskInfo->data, msg.data, 0x20);
    r = NWMi_SendCommandDirect((u32)(&msg), 0x24);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
