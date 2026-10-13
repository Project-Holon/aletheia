/*
 * function: func_021B6340
 * address: 0x021B6340
 * packet: pkt_ov180_021B6340
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_020434DC(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void func_020403F4(u32);
void func_021B6340(void) {func_020434DC(8,0);BG_SYS_SetSubPlaneVisible(8,0);func_020403F4(7);func_020403F4(3);}
