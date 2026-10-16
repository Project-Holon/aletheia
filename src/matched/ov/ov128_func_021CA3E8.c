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
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void G2x_SetBlendBrightness_(u32,int,int);
void WF2DMAP_TOUCH_SetBgOffset(int a) {if(a==1)G2x_SetBlendBrightness_(0x04000050,28,0);else G2x_SetBlendBrightness_(0x04000050,28,-8);}
