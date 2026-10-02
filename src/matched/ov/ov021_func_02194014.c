/*
 * function: func_02194014
 * address:  0x02194014
 * packet:   pkt_ov021_02194014
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Cell holds the Pair as one member; the struct copy t[i][j].k = e emits the
 * two byte stores, the first one addressed [j*4, row].
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u8 a; u8 b; } Pair;
typedef struct { Pair k; u16 c; } Cell;

void func_02194014(Cell (*t)[8], int j, int i, Pair e, u16 c)
{
    t[i][j].k = e;
    t[i][j].c = c;
}
