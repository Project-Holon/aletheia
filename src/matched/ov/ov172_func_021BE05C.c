/*
 * function: COMM_TVT_SYS_GetLayoutMode
 * address:  0x021BE05C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 1 for states 1 and 2, else 2.
 *
 * symbols:
 *   COMM_TVT_SYS_GetMemberCount  0x021BE054  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 COMM_TVT_SYS_GetMemberCount(void *p);

int COMM_TVT_SYS_GetLayoutMode(void *p)
{
    u8 v = COMM_TVT_SYS_GetMemberCount(p);
    if (v == 1) {
        return 1;
    }
    if (v == 2) {
        return 1;
    }
    return 2;
}
