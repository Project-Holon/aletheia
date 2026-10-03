/*
 * function: func_021C4440
 * address: 0x021C4440
 * packet: pkt_ov127_021C4440
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
void func_021C4440(char *p,int i) { func_0204A8D4(*(u32 *)(p+20+(u32)i*20)); func_0204ADA4(*(u32 *)(p+24+(u32)i*20)); *(u32 *)(p+20+(u32)i*20)=-1; *(u32 *)(p+24+(u32)i*20)=-1; }
