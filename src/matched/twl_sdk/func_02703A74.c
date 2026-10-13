/*
 * function: NWMi_SendCommand
 * address:  0x02703A74
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   NwmGetCommandBuffer4Arm7  0x02703B98  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   PXI_SendWordByFifo  0x02088610  arm twl
 *   func_02085DBC  0x02085DBC  arm twl
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 NWMi_GetSystemWork(void);
extern u16 *NwmGetCommandBuffer4Arm7(void);
extern void func_020862D4(u16 *, u32);
extern s32 PXI_SendWordByFifo(u32, u16 *, u32);
extern void func_02085DBC(u32, u16 *, u32);

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
    func_020862D4(msg, 0x100);
    res = PXI_SendWordByFifo(0x16, msg, 0);
    func_02085DBC(base + 0x2000, msg, 1);
    ret = 6;
    if (res >= 0) {
        ret = 2;
    }
    return ret;
}
