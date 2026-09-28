/*
 * function: func_0207A9EC
 * address:  0x0207A9EC
 * packet:   pkt_0207A9EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: FSi_ReadRomCallback (TwlSDK libfs.TWL.HYB.a fs_proc_rom.o)
 *
 * symbols:
 *   CARDi_ReadRom    0x020771B4  arm
 *   func_0207A9C8    0x0207A9C8  arm
 *   fsi_default_dma_no 0x02150DA0  data
 */

typedef int BOOL;
typedef unsigned long u32;

extern u32 fsi_default_dma_no;
extern void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len,
                          void (*callback)(void *), void *arg, BOOL is_async);
extern void func_0207A9C8(void *arg);

int func_0207A9EC(void *p_arc, void *dst, u32 src, u32 len)
{
    CARDi_ReadRom(fsi_default_dma_no, (const void *)src, dst, len,
                  func_0207A9C8, p_arc, 1);
    return 0x100;
}
