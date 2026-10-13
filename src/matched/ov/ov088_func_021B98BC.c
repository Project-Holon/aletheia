/*
 * function: STARTMENU_ResetDisplayState
 * address:  0x021B98BC
 * packet:   pkt_ov088_021B98BC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0207D534(volatile u16 *reg, int brightness);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);

void STARTMENU_ResetDisplayState(void)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
}
