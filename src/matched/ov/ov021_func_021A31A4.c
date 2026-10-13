/*
 * function: FIELD_PLAYER_GetObjCodeOfFormCode
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
 *   gFieldPlayerFormTable  0x021D890C  data
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

extern const Row gFieldPlayerFormTable[];

int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v)
{
    const Pair *e;
    int k;

    k = 0;
    e = gFieldPlayerFormTable[i].e;
    for (; k < 10; k++, e++) {
        if (e->b == v)
            return e->a;
    }
    return 1;
}
