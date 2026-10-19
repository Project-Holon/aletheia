/*
 * file:     nwm_unloaddev.c
 * unit:     yes
 * function: NWM_UnloadDevice, NWMi_ForceUnloadDevice, NWMi_ForceUnloadDeviceCallback, NWMi_ForceExit
 * address:  0x02702BFC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_unloaddev.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   PXIi_HandlerRecvFifoNotEmpty  0x02088688  arm  arm9
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 */
#include "../types.h"

extern u32 NWMi_CheckState(u32, ...);
extern u32 NWMi_GetSystemWork(void);
extern void DC_InvalidateRange(u32, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(unsigned short apiid, unsigned short argc, ...);
extern u32 PM_GetExitFactor(void);
extern void OS_SpinWaitSysCycles(u32);
extern void PXIi_HandlerRecvFifoNotEmpty(void);
extern u32 NWM_GetState(void);
static void NWMi_ForceUnloadDeviceCallback(void);
extern u8 d_027341C8;
u32 NWM_UnloadDevice(u32 callback);
u32 NWMi_ForceUnloadDevice(u32 callback);
void NWMi_ForceExit(void);

static inline u32 flag_set(u32 n) {
    u32 base = NWMi_GetSystemWork();
    if (base != 0) {
        DC_InvalidateRange(*(u32 *)(base + 0x2278) + n, 1);
        return *(u8 *)(*(u32 *)(base + 0x2278) + n) == 1;
    }
    return 0;
}

u32 NWM_UnloadDevice(u32 callback) {
    u32 r = NWMi_CheckState(1, 2);
    u32 base;
    u32 busy;
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        busy = 1;
        DC_InvalidateRange(ptr + 4, 1);
        if (*(u8 *)(*(u32 *)(base + 0x2278) + 4) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(4, callback);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(4, 1, 0);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}

u32 NWMi_ForceUnloadDevice(u32 callback) {
    u32 r = NWMi_CheckState(5, 1, 2, 3, 4, 5);
    u32 base;
    u32 busy;
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        busy = 1;
        DC_InvalidateRange(ptr + 4, 1);
        if (*(u8 *)(*(u32 *)(base + 0x2278) + 4) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(4, callback);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(4, 1, 1);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}

/* Completion callback: sets the one-byte flag that NWMi_ForceExit polls. */
static void NWMi_ForceUnloadDeviceCallback(void) {
    d_027341C8 = 1;
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
