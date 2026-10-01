/*
 * function: func_02194014
 * address:  0x02194014
 * packet:   pkt_ov021_02194014
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: 17 bytes of register colouring left.  The original computes
 * j*4 into r3 (the spilled struct register) before i*32 and keeps the cell
 * pointer in r1; this shape does i*32 first.  Pair is a 2-byte struct passed
 * in r3, c is the 5th (stack) argument.
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

typedef struct { u8 a; u8 b; u16 c; } Cell;

typedef struct { u8 a; u8 b; } Pair;
void func_02194014(Cell (*t)[8], int j, int i, Pair e, u16 c)
{
    Cell *p = &t[i][j];
    p->a = e.a;
    p->b = e.b;
    p->c = c;
}
