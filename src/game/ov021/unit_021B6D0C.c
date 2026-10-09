/*
 * file:     unit_021B6D0C.c
 * function: func_021B6D0C
 * address:  0x021B6D0C
 * packet:   pkt_ov021_021B6D0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9974     0x021D9974  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int (*fn)(void *, void *, void *);
    u8 pad[0x14];
} Entry;

extern Entry d_021D9974[];

int func_021B6D0C(int idx, void *x, void *y, void *z)
{
    int (*fn)(void *, void *, void *) = d_021D9974[idx].fn;

    if (z != 0 && fn != 0) {
        return fn(x, y, z);
    }
    return 0;
}
