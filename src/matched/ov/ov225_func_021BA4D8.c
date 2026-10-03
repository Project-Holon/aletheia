/*
 * function: func_021BA4D8
 * address: 0x021BA4D8
 * packet: pkt_ov225_021BA4D8
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   sub_0204B3B4 0x0204B3B4 arm
 *   sub_0204AFD8 0x0204AFD8 arm
 *   sub_0204A8D4 0x0204A8D4 arm
 *   sub_0204ADA4 0x0204ADA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void sub_0204B3B4(struct Obj *);
extern void sub_0204AFD8(u32);
extern void sub_0204A8D4(u32);
extern void sub_0204ADA4(u32);
void func_021BA4D8(char *p) { u8 i; for(i=0;i<2;i++) sub_0204B3B4(*(struct Obj **)(p+i*4+0x38)); sub_0204AFD8(*(u32 *)(p+0x34)); sub_0204A8D4(*(u32 *)(p+0x2c)); sub_0204ADA4(*(u32 *)(p+0x30)); }
