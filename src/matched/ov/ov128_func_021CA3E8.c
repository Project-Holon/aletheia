/*
 * function: WF2DMAP_TOUCH_SetBgOffset
 * address: 0x021CA3E8
 * packet: pkt_ov128_021CA3E8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D658 0x0207D658 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_0207D658(u32,int,int);
void WF2DMAP_TOUCH_SetBgOffset(int a) {if(a==1)func_0207D658(0x04000050,28,0);else func_0207D658(0x04000050,28,-8);}
