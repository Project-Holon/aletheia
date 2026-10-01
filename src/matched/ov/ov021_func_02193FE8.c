/*
 * function: func_02193FE8
 * address:  0x02193FE8
 * packet:   pkt_ov021_02193FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

void func_02193FE8(Cell (*t)[8])
{
    int i;
    int j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            t[i][j].b = 0xFF;
            t[i][j].c = 0xFFFF;
        }
    }
}
