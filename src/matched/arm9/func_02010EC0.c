/*
 * function: GPOWER_GetMinutesLeftByType
 * address:  0x02010EC0
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021461E8   0x021461E8  data
 *   g_0214621C   0x0214621C  data
 *   _u32_div_f   0x0209C2B0  arm
 *
 * Returns 0 for a 0x30 entry, otherwise the counter divided by 0x3c (or 1).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_GetMinutesLeftByType.c \
 *       --func GPOWER_GetMinutesLeftByType --addr 0x02010EC0 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 g_021461E8[];
extern u8 g_0214621C[];

u32 GPOWER_GetMinutesLeftByType(u32 i)
{
    u32 r;

    if (g_0214621C[i] == 0x30) {
        return 0;
    }
    r = ((u32 *)g_021461E8)[i] / 0x3c;
    return r != 0 ? r : 1;
}