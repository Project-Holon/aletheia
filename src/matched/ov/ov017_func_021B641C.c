/*
 * function: ERROR_SCREEN_Teardown
 * address:  0x021B641C
 * packet:   pkt_ov017_021B641C
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A48  0x02082A48  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_020809A0  0x020809A0  arm
 *   func_020808F4  0x020808F4  arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void *func_0207E24C(void);
extern void func_02082A48(int, u32, u32);
extern void *func_0207DFB4(void);
extern int func_020809A0(void);
extern int func_020808F4(void);

void ERROR_SCREEN_Teardown(void)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02082A48(0, (u32)func_0207E24C(), 0x4000);
    func_02082A48(0, (u32)func_0207DFB4(), 0x800);
    func_02082A48(0x7FFF, 0x05000000, 0x20);
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    func_020809A0();
    func_020808F4();
    func_0207D534((volatile u16 *)0x0400006C, 0);
    func_0207D534((volatile u16 *)0x0400106C, 0);
}
