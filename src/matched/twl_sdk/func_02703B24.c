/*
 * function: NWMi_SendCommandDirect
 * address:  0x02703B24
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
 *   MI_CpuCopy8  0x02082D44  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   PXI_SendWordByFifo  0x02088610  arm twl
 *   func_02085DBC  0x02085DBC  arm twl
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 NWMi_GetSystemWork(void);
extern u16 *NwmGetCommandBuffer4Arm7(void);
extern void MI_CpuCopy8(u32, u16 *, u32);
extern void func_020862D4(u16 *, u32);
extern s32 PXI_SendWordByFifo(u32, u16 *, u32);
extern void func_02085DBC(u32, u16 *, u32);

u32 NWMi_SendCommandDirect(u32 a0, u32 a1) {
    u32 base = NWMi_GetSystemWork();
    u16 *msg = NwmGetCommandBuffer4Arm7();
    s32 res;
    u32 ret;

    if (msg == 0) {
        return 6;
    }
    MI_CpuCopy8(a0, msg, a1);
    func_020862D4(msg, a1);
    res = PXI_SendWordByFifo(0x16, msg, 0);
    func_02085DBC(base + 0x2000, msg, 1);
    ret = 6;
    if (res >= 0) {
        ret = 2;
    }
    return ret;
}
