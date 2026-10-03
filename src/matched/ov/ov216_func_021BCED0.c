/*
 * function: func_021BCED0
 * address: 0x021BCED0
 * packet: pkt_ov216_021BCED0
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_021BCD08 0x021BCD08 thumb ov216
 *   d_021BDD92 0x021BDD92 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub0204A9D0;
extern void func_0204A9D0(int,struct Sub0204A9D0*);
extern void func_021BCD08(void*,u32,u32,u32);
extern const u8 d_021BDD92[];
void func_021BCED0(u8*p,u32 n){func_0204A9D0(*(int*)(p+0x84),*(struct Sub0204A9D0**)((u32)p+n*8+0x8c));func_021BCD08((u8*)*(void**)(p+0x110)+(d_021BDD92[n]&15)*32,2,160,16);}
