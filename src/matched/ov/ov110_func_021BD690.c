/*
 * function: func_021BD690
 * address: 0x021BD690
 * packet: pkt_ov110_021BD690
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * blocker: 0x02024530, Thumb ARM9, integrator-owned unlabelled leaf.
 * No witness outside this caller; tu --suggest-split leaves it out.
 * Scratch one verdict EXACT (4 bytes), fixed compiler/flags, no region:
 * typedef unsigned short u16;
 * unsigned int func_02024530(const u16 *p) { return p[1]; }
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_0202452C 0x0202452C thumb
 *   func_02024584 0x02024584 thumb
 *   func_02024530 0x02024530 thumb
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_0202452C(const u16 *p);
extern u8 func_02024584(u32 i);
extern unsigned int func_02024530(const u16 *p);
void func_021BD690(u8 *p, u16 *out)
{
    *(s16 *)p=func_0202452C(out);
    p[3]=func_02024584(*(s16 *)p);
    p[2]=func_02024530(out);
}
