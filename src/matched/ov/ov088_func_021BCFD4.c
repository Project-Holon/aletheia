/*
 * function: STARTMENU_SaveEraseExitGraphics
 * address:  0x021BCFD4
 * packet:   pkt_ov088_021BCFD4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */

typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);

void STARTMENU_SaveEraseExitGraphics(void)
{
    func_020434DC(1, 0);
    func_020403F4(0);
    func_0203F9B4();
}
