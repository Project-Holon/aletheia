/*
 * function: func_021896F4
 * address:  0x021896F4
 * packet:   pkt_ov021_021896F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026454  0x02026454  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0202647C  0x0202647C  thumb
 */

typedef unsigned int   u32;
extern u32 func_02026454(void *obj);
extern u32 func_0200FB24(void);
extern u32 func_0202647C(void *obj);

int func_021896F4(void *p)
{
    int r = func_02026454(p);

    switch (r) {
    case 0:
        if (func_0200FB24() != 0)
            r = func_0202647C(p);
        return r;
    case 1:
    case 2:
    case 5:
        return r;
    }
    return 2;
}
