/*
 * function: MYSTERY_UTIL_Update
 * address:  0x021DA840
 * packet:   pkt_021DA840
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_UTIL_IsWindowListDone  0x021DA2C8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int MYSTERY_UTIL_IsWindowListDone(u8 *p);

int MYSTERY_UTIL_Update(void **p)
{
    return MYSTERY_UTIL_IsWindowListDone(*p);
}
