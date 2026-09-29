/*
 * function: func_02188B58
 * address:  0x02188B58
 * packet:   pkt_ov021_02188B58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   data_021D36B8  0x021D36B8  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef u32 (*Fn)(void *a, void *b);
extern Fn data_021D36B8[][2];

u32 func_02188B58(void *a, u8 *b)
{
    u32 c = *(u32 *)(b + 0xCC);
    s32 r = 0;
    Fn f;
    Fn *row;

    *(u32 *)(b + 0xCC) = c + 1;
    row = data_021D36B8[*(u32 *)(b + 0xC4)];
    f = row[b[0xC9]];
    if (f != 0)
        r = f(a, b);
    switch (r) {
    case 0:
        b[0xC9] = (b[0xC9] == 0);
        break;
    case 1:
        *(u32 *)(b + 0xC4) = *(u32 *)(b + 0xC4) + 1;
        b[0xC8] = 0;
        b[0xC9] = 0;
        break;
    case 2:
        return 1;
    }
    return 0;
}
