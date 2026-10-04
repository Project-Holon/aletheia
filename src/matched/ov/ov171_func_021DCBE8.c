/*
 * function: func_021DCBE8
 * address: 0x021DCBE8
 * packet: pkt_ov171_021DCBE8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02021EE4 0x02021EE4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02021ED8(const char*);
struct Obj02021EE4;
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
int func_021DCBE8(u8*p){if(func_02021ED8(*(char**)(p+0xb30)))return 1;func_02021EE4((struct Obj02021EE4 *)(*(u32*)(p+0xb30)),0);return 0;}
