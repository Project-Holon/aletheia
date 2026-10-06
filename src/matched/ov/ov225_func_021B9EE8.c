/*
 * function: func_021B9EE8
 * address: 0x021B9EE8
 * packet: pkt_ov225_021B9EE8
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9EEC,021B9EF8 re-read 0400000C;021B9F02 read 04000008.
 * symbols:
 *   func_02040588 0x02040588 arm
 */
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
void func_021B9EE8(void *a0){*(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;*(volatile unsigned short *)0x0400000C=(unsigned short)(*(volatile unsigned short *)0x0400000C&~3);*(volatile unsigned short *)0x04000008&=~0x40;func_02040588(2,1);}
