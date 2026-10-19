/*
 * file:     nwm_startscan.c
 * unit:     yes
 * function: NWM_StartScanEx, NWM_GetInfoElements, NWM_GetVenderInfoElements
 * address:  0x02703088
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_startscan.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommandDirect  0x02703B24  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   MI_CpuComp8  0x02082E74  arm  arm9
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
#include "../types.h"

typedef struct ApInfo {
    u8 *buf;
    u16 bufLen;
    u16 channelList;
    u16 maxChannelTime;
    u16 scanType;
    u8 mac[6];
    u16 ssidLen;
    u8 ssid[0x20];
    u16 ssidMatchLength;
} ApInfo;

typedef struct ApCmd {
    u16 cmd;
    u16 channelList;
    u16 bufLen;
    u16 maxChannelTime;
    u8 *buf;
    u16 scanType;
    u16 ssidLen;
    u16 ssidMatchLength;
    u8 ssid[0x20];
    u8 mac[6];
} ApCmd;

extern u32 NWMi_CheckState(u32, ...);
extern u32 NWMi_GetSystemWork(void);
extern void DC_InvalidateRange(u32, u32);
extern void MI_CpuFill8(void *, u32, u32);
extern void DC_StoreRange(void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(unsigned int command, unsigned int length);
extern int MI_CpuComp8(void *, void *, u32);
u32 NWM_StartScanEx(u32 callback, const ApInfo *param);
u8 *NWM_GetInfoElements(u8 *bssDesc, u8 elementId);
u8 *NWM_GetVenderInfoElements(u8 *bssDesc, u32 elementId, void *oui);

u32 NWM_StartScanEx(u32 callback, const ApInfo *param) {
    ApCmd cmd;
    u32 r = NWMi_CheckState(1, 3);
    u32 base;
    u32 busy;
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        busy = 1;
        DC_InvalidateRange(ptr + 7, 1);
        if (*(u8 *)(*(u32 *)(base + 0x2278) + 7) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    if (param == 0) {
        return 5;
    }
    if (param->buf == 0) {
        return 5;
    }
    if (param->ssidLen > 0x20) {
        return 5;
    }
    if (param->ssidMatchLength > 0x20) {
        return 5;
    }
    MI_CpuFill8(param->buf, 0, (param->bufLen + 3) & ~3);
    DC_StoreRange(param->buf, (param->bufLen + 3) & ~3);
    r = 7;
    NWMi_SetCallbackTable(r, callback);
    cmd.cmd = r;
    cmd.channelList = param->channelList;
    cmd.bufLen = param->bufLen;
    cmd.maxChannelTime = param->maxChannelTime;
    cmd.buf = param->buf;
    cmd.scanType = param->scanType;
    cmd.ssidLen = param->ssidLen;
    cmd.ssidMatchLength = param->ssidMatchLength;
    MI_CpuCopy8(param->ssid, cmd.ssid, 0x20);
    MI_CpuCopy8(param->mac, cmd.mac, 6);
    r = NWMi_SendCommandDirect((unsigned int)(&cmd), 0x38);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}

u8 *NWM_GetInfoElements(u8 *bssDesc, u8 elementId) {
    u8 *p = bssDesc + 0x40;
    u8 *end = p + *(u16 *)bssDesc - 0x40;
    while (*p != elementId && p + p[1] + 2 <= end) {
        p += p[1] + 2;
    }
    if (*p != elementId) {
        p = 0;
    }
    return p;
}

u8 *NWM_GetVenderInfoElements(u8 *bssDesc, u32 elementId, void *oui) {
    u8 *p = bssDesc + 0x40;
    u8 *end = p + *(u16 *)bssDesc - 0x40;
    if (elementId != 0xdd) {
        return 0;
    }
    while (p + p[1] + 2 <= end) {
        if (*p == elementId && MI_CpuComp8(p + 2, oui, 4) == 0) {
            return p;
        }
        p += p[1] + 2;
    }
    return 0;
}
