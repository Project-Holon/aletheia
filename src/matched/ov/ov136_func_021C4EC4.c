/*
 * function: func_021C4EC4
 * address:  0x021C4EC4
 * packet:   pkt_ov136_021C4EC4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4EC4 0x021C4EC4 thumb
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 */
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void BG_SYS_SetLcdSwap(u32 swap);
void func_021C4EC4(void *p)
{
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    BG_SYS_SetLcdSwap(1);
}
