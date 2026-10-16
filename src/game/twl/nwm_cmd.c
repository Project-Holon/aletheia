/*
 * file:     nwm_cmd.c
 * unit:     yes
 * function: NWMi_SetCallbackTable, NWMi_SetReceiveCallbackTable, NWMi_SendCommand, NWMi_SendCommandDirect, NwmGetCommandBuffer4Arm7
 * address:  0x02703A34
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_cmd.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   PXI_SendWordByFifo  0x02088610  arm  arm9
 *   OS_SendMessage  0x02085DBC  arm  arm9
 *   OS_ReceiveMessage  0x02085E50  arm  arm9
 *   DC_InvalidateRange  0x020862B8  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 NWMi_GetSystemWork(void);
extern void DC_StoreRange(u16 *, u32);
extern s32 PXI_SendWordByFifo(u32, u16 *, u32);
extern void OS_SendMessage(u32, u16 *, u32);
extern void MI_CpuCopy8(u32, u16 *, u32);
extern u32 OS_ReceiveMessage(u32, u16 **, u32);
extern void DC_InvalidateRange(void *, u32);
void NWMi_SetCallbackTable(u32 a0, u32 a1);
void NWMi_SetReceiveCallbackTable(u32 a0, u32 a1);
u32 NWMi_SendCommand(u16 a0, u16 a1, ...);
u32 NWMi_SendCommandDirect(u32 a0, u32 a1);
u16 *NwmGetCommandBuffer4Arm7(void);

void NWMi_SetCallbackTable(u32 a0, u32 a1) {
    u32 base = NWMi_GetSystemWork();
    *(u32 *)(base + (a0 << 2) + 0x2284) = a1;
}

void NWMi_SetReceiveCallbackTable(u32 a0, u32 a1) {
    u32 base = NWMi_GetSystemWork();
    *(u32 *)(base + (a0 << 2) + 0x22D4) = a1;
}

u32 NWMi_SendCommand(u16 a0, u16 a1, ...) {
    u32 ret;
    s32 res;
    char *ap;
    s32 i;
    s32 n;
    u16 *msg;
    u32 base;

    base = NWMi_GetSystemWork();
    msg = NwmGetCommandBuffer4Arm7();
    if (msg == 0) {
        return 6;
    }
    msg[0] = a0;
    ap = (char *)(((u32)&a1 & ~3) + 4);
    n = a1;
    for (i = 0; i < n; i++) {
        ((u32 *)msg)[1 + i] = *(u32 *)((ap += 4) - 4);
    }
    DC_StoreRange(msg, 0x100);
    res = PXI_SendWordByFifo(0x16, msg, 0);
    OS_SendMessage(base + 0x2000, msg, 1);
    ret = 6;
    if (res >= 0) {
        ret = 2;
    }
    return ret;
}

u32 NWMi_SendCommandDirect(u32 a0, u32 a1) {
    u32 base = NWMi_GetSystemWork();
    u16 *msg = NwmGetCommandBuffer4Arm7();
    s32 res;
    u32 ret;

    if (msg == 0) {
        return 6;
    }
    MI_CpuCopy8(a0, msg, a1);
    DC_StoreRange(msg, a1);
    res = PXI_SendWordByFifo(0x16, msg, 0);
    OS_SendMessage(base + 0x2000, msg, 1);
    ret = 6;
    if (res >= 0) {
        ret = 2;
    }
    return ret;
}

u16 *NwmGetCommandBuffer4Arm7(void) {
    u16 *msg = 0;
    u32 base = NWMi_GetSystemWork();

    do {
        if (OS_ReceiveMessage(base + 0x2000, &msg, 0) == 0) {
            return 0;
        }
        DC_InvalidateRange((void *)base, 0x2000);
        DC_InvalidateRange(msg, 2);
        if (!(*msg & 0x8000)) {
            OS_SendMessage(base + 0x2000, msg, 1);
            msg = 0;
        }
    } while (msg == 0);
    return msg;
}
