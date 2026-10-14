/*
 * function: COMM_TVT_SYS_GetResId
 * address:  0x021BE018
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x180 of element i (stride 4).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 COMM_TVT_SYS_GetResId(void *p, int i)
{
    return *(u32 *)((char *)p + i * 4 + 0x180);
}
