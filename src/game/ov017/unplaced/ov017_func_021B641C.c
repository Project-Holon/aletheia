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
 *   MIi_CpuClear16  0x02082A48  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_020809A0  0x020809A0  arm
 *   func_020808F4  0x020808F4  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

#define REG_DISPCNT_MAIN       (*(volatile u32 *)0x04000000)
#define REG_MASTER_BRIGHT_MAIN ((volatile u16 *)0x0400006C)
#define REG_MASTER_BRIGHT_SUB  ((volatile u16 *)0x0400106C)
#define PLTT_MAIN_BG           0x05000000

extern void func_0207D534(volatile u16 *reg, int brightness);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void *func_0207E24C(void);
extern void MIi_CpuClear16(int value, u32 dst, u32 size);
extern void *func_0207DFB4(void);
extern int func_020809A0(void);
extern int func_020808F4(void);

/* Error screen teardown: fade out, hide the planes, clear character data, tile map and palette, disable the main BGs. */
void ERROR_SCREEN_Teardown(void)
{
    func_0207D534(REG_MASTER_BRIGHT_MAIN, -16);
    func_0207D534(REG_MASTER_BRIGHT_SUB, -16);
    BG_SYS_SetSubVisiblePlanes(0);
    MIi_CpuClear16(0, (u32)func_0207E24C(), 0x4000);
    MIi_CpuClear16(0, (u32)func_0207DFB4(), 0x800);
    MIi_CpuClear16(0x7FFF, PLTT_MAIN_BG, 0x20);
    REG_DISPCNT_MAIN &= 0xFFFFE0FF;
    func_020809A0();
    func_020808F4();
    func_0207D534(REG_MASTER_BRIGHT_MAIN, 0);
    func_0207D534(REG_MASTER_BRIGHT_SUB, 0);
}
