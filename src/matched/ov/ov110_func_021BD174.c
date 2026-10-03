/*
 * function: func_021BD174
 * address: 0x021BD174
 * packet: pkt_ov110_021BD174
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_0204B3B4(void *);
void func_021BD174(u8 *p)
{
    u8 i;
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x90));
}
