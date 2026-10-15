/*
 * function: ZKNSEARCH_SYS_GetVramBanks
 * address:  0x021BC3E8
 * packet:   pkt_ov210_021BC3E8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C0754  0x021C0754  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u8 d_021C0754[];

void *ZKNSEARCH_SYS_GetVramBanks(void)
{
    return d_021C0754;
}
