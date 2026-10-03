/*
 * function: func_021F07DC
 * address: 0x021F07DC
 * packet: pkt_ov033_021F07DC
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 */
typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
void func_021F07DC(char *p) { unsigned v = *(unsigned *)(p+0x10); func_0203FB44(7, (unsigned short)v, (unsigned short)(v>>16)); }
