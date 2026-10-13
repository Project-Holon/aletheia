/*
 * function: NWM_GetInfoElements
 * address:  0x02703208
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWM_StartScanEx  0x02703088  arm
 *   NWM_GetVenderInfoElements  0x02703250  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommandDirect  0x02703B24  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct ApInfo {
    u8 *buf;
    u16 bufLen;
    u16 f06;
    u16 f08;
    u16 f0A;
    u8 mac[6];
    u16 ssidLen;
    u8 ssid[0x20];
    u16 f34;
} ApInfo;

typedef struct ApCmd {
    u16 cmd;
    u16 f02;
    u16 bufLen;
    u16 f06;
    u8 *buf;
    u16 f0C;
    u16 ssidLen;
    u16 f10;
    u8 ssid[0x20];
    u8 mac[6];
} ApCmd;

extern u32 NWMi_CheckState(u32, ...);
extern u32 NWMi_GetSystemWork(void);
extern void func_020862B8(u32, u32);
extern void MI_CpuFill8(void *, u32, u32);
extern void func_020862D4(void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(void *, u32);
extern u32 func_02082E74(void *, void *, u32);
u32 NWM_StartScanEx(u32 a0, const ApInfo *a1);
u8 *NWM_GetInfoElements(u8 *a0, u8 a1);
u8 *NWM_GetVenderInfoElements(u8 *a0, u32 a1, void *a2);

u8 *NWM_GetInfoElements(u8 *a0, u8 a1) {
    u8 *p = a0 + 0x40;
    u8 *end = p + *(u16 *)a0 - 0x40;
    while (*p != a1 && p + p[1] + 2 <= end) {
        p += p[1] + 2;
    }
    if (*p != a1) {
        p = 0;
    }
    return p;
}
