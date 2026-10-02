/*
 * function: func_021B6C4C
 * address: 0x021B6C4C
 * packet: pkt_ov067_021B6C4C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B6C72.
 * lever: halve the full-width call result before the return narrows to u16.
 * symbols:
 *   func_0201D304 0x0201D304 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct StrObj;
extern u32 func_0201D304(struct StrObj *, u32, u32);
u16 func_021B6C4C(struct StrObj *s, u32 a, u32 mode)
{
    if (mode == 1) return func_0201D304(s, a, 0);
    if (mode == 2) return func_0201D304(s, a, 0) >> 1;
    return 0;
}
