/*
 * function: func_02197E7C
 * address:  0x02197E7C
 * packet:   pkt_ov021_02197E7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the
 * ov021 table is a data start that another overlay mapped over the same
 * window also starts an object at, so the symbols hint is contested.  No C
 * change needed to promote.
 *
 * symbols:
 *   d_021D5D6C     0x021D5D6C  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int *d_021D5D6C[];

int func_02197E7C(int a, int b)
{
    int i;
    int **p;
    int *q;

    p = d_021D5D6C;
    do {
        q = *p;
        for (i = 0; i < 4; i++) {
            if (b == q[i]) {
                return (u16)q[a];
            }
        }
        p++;
    } while (*p != 0);
    return b;
}
