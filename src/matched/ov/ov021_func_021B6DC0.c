/*
 * function: func_021B6DC0
 * address:  0x021B6DC0
 * packet:   pkt_ov021_021B6DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D997C     0x021D997C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int (*fn)(void *, void *, void *);
    u8 pad[0x14];
} Entry;

extern Entry d_021D997C[];

int func_021B6DC0(int idx, void *x, void *y, void *z)
{
    int (*fn)(void *, void *, void *) = d_021D997C[idx].fn;

    if (z != 0 && fn != 0) {
        return fn(x, y, z);
    }
    return 0;
}
