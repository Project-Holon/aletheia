/*
 * file:     nwm_sendframe.c
 * unit:     yes
 * function: NWM_SendFrame, NWMi_AddMACHeader
 * address:  0x027036A0
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_sendframe.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
typedef unsigned int u32;

typedef unsigned char  u8;

typedef struct TwlWork {
    u8 pad[0x2278];
    u8 *buf;
} TwlWork;

extern TwlWork *NWMi_GetSystemWork(void);
extern u32 NWMi_CheckState(u32, u32);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void DC_StoreRange(void *, u32);
extern u32 NWMi_SendCommand(u32, u32, u32, void *, u32);
extern void MI_CpuCopy8(u32, u32, u32);
void NWMi_AddMACHeader(u32 a0, u32 a1, u8 *a2, u32 a3);

u32 NWM_SendFrame(u32 a0, u32 a1, u8 *a2, u32 a3) {
    TwlWork *w;
    u32 r;
    u32 saved;

    w = NWMi_GetSystemWork();
    r = NWMi_CheckState(1, 4);
    if (r != 0 && r != 2) {
        return r;
    }
    saved = OS_DisableInterrupts();
    if (a3 > 0x5F2) {
        OS_RestoreInterrupts(saved);
        return 5;
    }
    DC_StoreRange(a2, a3);
    NWMi_AddMACHeader(a1, (u32)(w->buf + 0x40), a2, a3);
    DC_StoreRange(a2, 0xE);
    r = NWMi_SendCommand(0xB, 3, a0, a2, a3);
    if (r == 0) {
        return 2;
    }
    OS_RestoreInterrupts(saved);
    return r;
}

void NWMi_AddMACHeader(u32 a0, u32 a1, u8 *a2, u32 a3) {
    if (a3 < 0xE) {
        return;
    }
    MI_CpuCopy8(a0, (u32)a2, 6);
    MI_CpuCopy8(a1, (u32)(a2 + 6), 6);
}
