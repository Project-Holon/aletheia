/*
 * function: func_021A0260
 * address:  0x021A0260
 * packet:   pkt_ov021_021A0260
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u32 f4;
    int f8;
    u32 fc;
    int f10;
} Lerp;

void func_021A0260(Lerp *s, u32 a, u32 b, u16 c, u16 d, u16 e)
{
    s->f0 = 0;
    s->f2 = e;
    s->f4 = a;
    s->f8 = b - a;
    s->fc = c;
    s->f10 = d - c;
}
