/*
 * function: func_021D7D3C
 * address: 0x021D7D3C
 * packet: pkt_ov120_021D7D3C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 func_02045730(void *);
extern void func_02041B6C(u32);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(void *);
void func_021D7D3C(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(*(void **)(q+0x38)) { func_02041B6C(func_02045730(*(void **)(q+0x38))); func_0201F7A8(*(void **)(q+0x38),2); func_020456F8(*(void **)(q+0x38)); } } }
