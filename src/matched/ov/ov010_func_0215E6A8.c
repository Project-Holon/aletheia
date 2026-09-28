/*
 * function: func_0215E6A8
 * address:  0x0215E6A8
 * packet:   pkt_ov010_0215E6A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0215E3E4  0x0215E3E4  thumb  ov010
 */

typedef unsigned char u8;

extern void *func_02012EBC(void *p);
extern void *func_0200D418(void *p);
extern int func_0200D488(void *a, int i);
extern int func_0215E3E4(void *a, int i);

int func_0215E6A8(void *a, int x)
{
    u8 i;
    void *p;

    p = func_0200D418(func_02012EBC(a));
    i = 0;
    if (func_0200D488(p, 0) != 0 && x == func_0215E3E4(p, i)) {
        return 6;
    }
    i = 1;
    if (func_0200D488(p, 1) != 0 && x == func_0215E3E4(p, i)) {
        return 7;
    }
    return 0xffff;
}
