/*
 * function: func_021F7840
 * address: 0x021F7840
 * packet: pkt_ov135_021F7840
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02202940(void *);
extern void func_020452E8(void *);
void func_021F7840(char *p) { int i; func_02202940(p+0xfa0); func_020452E8(*(void **)(p+0xde0)); for(i=0;i<6;i++) func_020452E8(*(void **)((u32)p+(u32)i*4+0xd90)); func_020452E8(*(void **)(p+0xd40)); }
