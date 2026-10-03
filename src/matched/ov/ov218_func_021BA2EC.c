/*
 * function: func_021BA2EC
 * address: 0x021BA2EC
 * packet: pkt_ov218_021BA2EC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
extern void func_0204A8D4(u32);extern void func_0204ADA4(u32);extern void func_0204AFD8(u32);
void func_021BA2EC(char *p){if(*(u32 *)(p+0x2d0)!=-1)func_0204A8D4(*(u32 *)(p+0x2d0));if(*(u32 *)(p+0x2d4)!=-1)func_0204ADA4(*(u32 *)(p+0x2d4));if(*(u32 *)(p+0x2d8)!=-1)func_0204AFD8(*(u32 *)(p+0x2d8));}
