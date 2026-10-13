/*
 * function: NWM_StartScanEx
 * address:  0x02703088
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_CheckState  0x027028E4  arm twl
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   MI_CpuFill8  0x02082BCC  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   NWMi_SetCallbackTable  0x02703A34  arm twl
 *   func_02082D44  0x02082D44  arm twl
 *   NWMi_SendCommandDirect  0x02703B24  arm twl
 *   NWM_GetInfoElements  0x02703208  arm
 *   NWM_GetVenderInfoElements  0x02703250  arm
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
extern void func_02082D44(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(void *, u32);
extern u32 func_02082E74(void *, void *, u32);
u8 *NWM_GetInfoElements(u8 *a0, u8 a1);
u8 *NWM_GetVenderInfoElements(u8 *a0, u32 a1, void *a2);

u32 NWM_StartScanEx(u32 a0, const ApInfo *a1) {
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
        func_020862B8(ptr + 7, 1);
        if (*(u8 *)(*(u32 *)(base + 0x2278) + 7) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    if (a1 == 0) {
        return 5;
    }
    if (a1->buf == 0) {
        return 5;
    }
    if (a1->ssidLen > 0x20) {
        return 5;
    }
    if (a1->f34 > 0x20) {
        return 5;
    }
    MI_CpuFill8(a1->buf, 0, (a1->bufLen + 3) & ~3);
    func_020862D4(a1->buf, (a1->bufLen + 3) & ~3);
    r = 7;
    NWMi_SetCallbackTable(r, a0);
    cmd.cmd = r;
    cmd.f02 = a1->f06;
    cmd.bufLen = a1->bufLen;
    cmd.f06 = a1->f08;
    cmd.buf = a1->buf;
    cmd.f0C = a1->f0A;
    cmd.ssidLen = a1->ssidLen;
    cmd.f10 = a1->f34;
    func_02082D44(a1->ssid, cmd.ssid, 0x20);
    func_02082D44(a1->mac, cmd.mac, 6);
    r = NWMi_SendCommandDirect(&cmd, 0x38);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
