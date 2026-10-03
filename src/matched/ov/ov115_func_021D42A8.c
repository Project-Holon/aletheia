/*
 * function: func_021D42A8
 * address: 0x021D42A8
 * packet: pkt_ov115_021D42A8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_0201283C(const void *);
extern void func_02009860(u32);
void func_021D42A8(u8 *p) { func_02009860(func_0201283C(*(void **)(p+0x44))); }
