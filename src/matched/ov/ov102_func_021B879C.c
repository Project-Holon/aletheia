/*
 * function: IRC_COMPATIBLE_MENU_InitScrollEffect
 * address: 0x021B879C
 * packet: pkt_ov102_021B879C
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02041EE4 0x02041EE4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, int, u32);
extern void func_02041EE4(u32,u32,u32);
void IRC_COMPATIBLE_MENU_InitScrollEffect(void *p, u32 a1) { MI_CpuFill8(p,0,28); func_02041EE4(4,3,88); func_02041EE4(7,3,88); }
