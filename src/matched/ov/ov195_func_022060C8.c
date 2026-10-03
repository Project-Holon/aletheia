/*
 * function: func_022060C8
 * address:  0x022060C8
 * packet:   pkt_022060C8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 */

typedef int fx32;

typedef unsigned int   u32;
extern u32 func_02017E1C(void *p, u32 id, u32 v);

fx32 func_022060C8(void *p)
{
    int v = func_02017E1C(p, 5, 0);
    fx32 r = -0x12000;

    switch (v) {
    case 0x260:
        r = -0x1b000;
        break;
    case 0x261:
        r = -0x27000;
        break;
    case 0x40:
        r = -0x11e66;
        break;
    }
    return r;
}
