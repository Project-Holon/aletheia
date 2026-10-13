/*
 * function: NWMi_ForceExit
 * address:  0x02702D7C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PM_GetExitFactor  0x0273153C  arm twl
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   OS_SpinWaitSysCycles  0x02087A04  arm twl
 *   PXIi_HandlerRecvFifoNotEmpty  0x02088688  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   NWM_GetState  0x027028B0  arm twl
 *   NWMi_CheckState  0x027028E4  arm twl
 *   d_027341C8     0x027341C8  data twl
 *   NWMi_ForceUnloadDevice  0x02702CA0  arm twl
 *   NWMi_ForceUnloadDeviceCallback  0x02702D68  arm twl
 *   NWM_UnloadDevice  0x02702BFC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommand  0x02703A74  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 NWMi_CheckState(u32, ...);
extern u32 NWMi_GetSystemWork(void);
extern void func_020862B8(u32, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(u32, u32, u32);
extern u32 PM_GetExitFactor(void);
extern void OS_SpinWaitSysCycles(u32);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern u32 NWM_GetState(void);
void NWMi_ForceUnloadDeviceCallback(void);
extern u8 d_027341C8;
u32 NWM_UnloadDevice(u32 a0);
u32 NWMi_ForceUnloadDevice(u32 a0);

static inline u32 flag_set(u32 n) {
    u32 base = NWMi_GetSystemWork();
    if (base != 0) {
        func_020862B8(*(u32 *)(base + 0x2278) + n, 1);
        return *(u8 *)(*(u32 *)(base + 0x2278) + n) == 1;
    }
    return 0;
}

void NWMi_ForceExit(void) {
    int timeout;
    u32 base;
    if (PM_GetExitFactor() == 0) {
        return;
    }
    base = NWMi_GetSystemWork();
    timeout = 0x3fec420;
    if (base == 0) {
        return;
    }
    OS_SpinWaitSysCycles(0x61a80);
    while ((flag_set(3) == 1 && NWM_GetState() == 1) || flag_set(1) == 1 || flag_set(0x13) == 1) {
        OS_SpinWaitSysCycles(0x2710);
        PXIi_HandlerRecvFifoNotEmpty();
    }
    if (NWMi_CheckState(4, 2, 3, 4, 5) != 0) {
        return;
    }
    d_027341C8 = 0;
    NWMi_ForceUnloadDevice((u32)NWMi_ForceUnloadDeviceCallback);
    for (;;) {
        OS_SpinWaitSysCycles(0x2710);
        PXIi_HandlerRecvFifoNotEmpty();
        timeout -= 0x2710;
        if (timeout < 0) {
            return;
        }
        if (d_027341C8 != 0) {
            return;
        }
    }
}
