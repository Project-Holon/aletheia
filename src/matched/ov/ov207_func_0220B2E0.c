/*
 * function: func_0220B2E0
 * address: 0x0220B2E0
 * packet: pkt_ov207_0220B2E0
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
void func_0220B2E0(u32*p){u32 v,hi;v=p[12];hi=v>>16;func_0203FB44(1,(u16)v,(u16)hi);}
