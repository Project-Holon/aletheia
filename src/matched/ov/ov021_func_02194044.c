/*
 * function: FIELD_WFBC_BLOCK_IsPlaced
 * address:  0x02194044
 * packet:   pkt_ov021_02194044
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

int FIELD_WFBC_BLOCK_IsPlaced(Cell (*t)[8], u8 b, u16 c)
{
    int i;
    int j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (b == t[i][j].b && c == t[i][j].c) {
                return 1;
            }
        }
    }
    return 0;
}
