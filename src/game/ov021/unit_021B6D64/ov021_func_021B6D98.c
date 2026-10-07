/*
 * function: func_021B6D98
 * address:  0x021B6D98
 * packet:   pkt_ov021_021B6D98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9978     0x021D9978  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void (*fn)(void *, void *, void *);
    u8 pad[0x14];
} Entry;

extern Entry d_021D9978[];

int func_021B6D98(int idx, void *x, void *y, void *z)
{
    void (*fn)(void *, void *, void *) = d_021D9978[idx].fn;

    if (z != 0 && fn != 0) {
        fn(x, y, z);
        return 1;
    }
    return 0;
}
