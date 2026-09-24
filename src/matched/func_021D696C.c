/*
 * function: func_021D696C
 * address:  0x021D696C
 * packet:   pkt_021D696C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D696C   0x021D696C  arm
 *
 * Validity test for a records window: bails out unless the shared flag word
 * (0x02FFFFA8 bit 0x8000) and bit 1 of the current record's +0x38 byte are
 * set, then checks a[0]/a[2] against the +0x28 bound and a[1]/a[3] against the
 * +0x2a bound. Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
} ByteBits;

int func_021D696C(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->f1 == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}
