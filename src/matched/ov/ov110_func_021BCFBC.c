/*
 * function: func_021BCFBC
 * address: 0x021BCFBC
 * packet: pkt_ov110_021BCFBC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_0202822C(char *,int);
void func_021BCFBC(char *p,u32 index,int value) { int i; for(i=0;i<3;i++) { if (*(void **)((u32)p+(u32)i*4+0x64)) func_02028218(*(void **)((u32)p+(u32)i*4+0x64),0); } if (*(void **)((u32)p+index*4+0x64)) func_0202822C(*(char **)((u32)p+index*4+0x64),value); }
