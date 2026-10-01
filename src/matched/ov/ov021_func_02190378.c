/*
 * function: func_02190378
 * address:  0x02190378
 * packet:   pkt_ov021_02190378
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_020403F4(u8 a);

int func_02190378(u8 *a)
{
    if (*(u16 *)(a + 4) != 0xff) {
        func_020403F4(*(u16 *)(a + 4));
        *(u16 *)(a + 4) = 0xff;
        return 1;
    }
    return 0;
}
