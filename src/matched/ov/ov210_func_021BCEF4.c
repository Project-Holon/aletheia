/*
 * function: ZKNSEARCH_MAIN_LookupEntryId
 * address:  0x021BCEF4
 * packet:   pkt_ov210_021BCEF4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C072E  0x021C072E  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u16 d_021C072E[];

u16 ZKNSEARCH_MAIN_LookupEntryId(int a0, int a1)
{
    (void)a0;
    return d_021C072E[a1];
}
