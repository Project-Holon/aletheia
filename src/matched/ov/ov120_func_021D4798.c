/*
 * function: func_021D4798
 * address: 0x021D4798
 * packet: pkt_ov120_021D4798
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4774 0x021D4774 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020399A8(void); extern int func_02008468(void); extern int func_0203D3A8(void *,u16,u16,u32); extern void func_021D4244(int,void (*)(int),int); extern void func_021D4774(int);
void func_021D4798(u8 *p) { void *link; int n; link=func_020399A8(); n=func_02008468(); if (func_0203D3A8(link,0x2201,n,*(u32 *)(*(u32 *)(p+72)+20))) func_021D4244((int)p,func_021D4774,0x2bd); }
