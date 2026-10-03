/*
 * function: func_021C6DAC
 * address: 0x021C6DAC
 * packet: pkt_ov128_021C6DAC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021C6DAC(u8 *p) {int i;func_0204B3B4(*(void **)(p+0x168));func_0204B3B4(*(void **)(p+0x164));for(i=0;i<2;i++) func_0204B3B4(*(void **)((u32)p+i*4+0x15c));}
