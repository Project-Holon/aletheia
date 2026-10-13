/*
 * function: DWCi_Ndi_unlockGlobal
 * address:  0x021C78F4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Tail call of func_02086078 on the 0x021D3C38 block.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02086078(void *);

void DWCi_Ndi_unlockGlobal(void)
{
    func_02086078((void *)0x021D3C38);
}
