/*
 * function: func_021A31A4
 * address:  0x021A31A4
 * packet:   pkt_ov021_021A31A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks up v in the b column of row i and returns the matching a, else 1.
 *
 * symbols:
 *   data_021D890C  0x021D890C  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
} Pair;

typedef struct {
    Pair e[10];
} Row;

extern const Row data_021D890C[];

u16 func_021A31A4(int i, u16 v)
{
    const Pair *e;
    int k;

    k = 0;
    e = data_021D890C[i].e;
    for (; k < 10; k++, e++) {
        if (e->b == v)
            return e->a;
    }
    return 1;
}
