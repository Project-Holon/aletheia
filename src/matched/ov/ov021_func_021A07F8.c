/*
 * function: func_021A07F8
 * address:  0x021A07F8
 * packet:   pkt_ov021_021A07F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011400  0x02011400  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u8 func_02011400(int row, int col);

typedef struct {
    u16 h;
    s16 m;
} Time;

int func_021A07F8(u32 a, Time *t)
{
    int h = func_02011400(a, t->h);
    return h * 3600 + t->m * 60;
}
