/*
 * function: func_021DC6A4
 * address: 0x021DC6A4
 * packet: pkt_ov175_021DC6A4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5B80 0x021C5B80 arm ov114
 *   d_021E4B80 0x021E4B80 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_021E4B80[];
extern int func_021C5B80(void);
void func_021DC6A4(u8 *p,int state) { d_021E4B80[0]=0; *(u32 *)(d_021E4B80+4)=0; *(u32 *)(p+0x130)=state; *(u32 *)(p+0x12c)=200; if(func_021C5B80()==0) *(u32 *)(p+0x130)=state; }
