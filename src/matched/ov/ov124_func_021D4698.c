/*
 * function: func_021D4698
 * address: 0x021D4698
 * packet: pkt_ov124_021D4698
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_020307B0(void *);
extern void func_0204B3B4(struct Obj *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
void func_021D4698(char *p) {func_020307B0(*(void **)(p+0x44));func_0204B3B4(*(struct Obj **)(p+0x5c));func_0204ADA4(*(u32 *)(p+0x50));func_0204A8D4(*(u32 *)(p+0x54));func_0204AFD8(*(u32 *)(p+0x58));}
