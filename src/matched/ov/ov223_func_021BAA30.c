/*
 * function: func_021BAA30
 * address: 0x021BAA30
 * packet: pkt_ov223_021BAA30
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;extern void func_0204B3B4(struct Obj *);extern void func_0204AFD8(u32),func_0204A8D4(u32),func_0204ADA4(u32);
void func_021BAA30(char *p) {u32 off;off=0x224;func_0204B3B4(*(struct Obj **)(p+off));func_0204AFD8(*(u32 *)(p+off-4));func_0204A8D4(*(u32 *)(p+off-12));off-=8;func_0204ADA4(*(u32 *)(p+off));}
