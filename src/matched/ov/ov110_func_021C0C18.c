/*
 * function: func_021C0C18
 * address: 0x021C0C18
 * packet: pkt_ov110_021C0C18
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202DC08 0x0202DC08 thumb
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
extern void func_0202DC08(struct Obj *p);
extern void func_020452E8(struct Descriptor *d);
void func_021C0C18(u8 *p) { int i; func_0202DC08(*(void **)(p+0x8c)); for(i=0;i<4;i++) func_020452E8(*(void **)(p+0x6c+i*4)); }
