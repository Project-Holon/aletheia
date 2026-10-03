/*
 * function: func_021D95D0
 * address:  0x021D95D0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Select the alternate buffer when the object is idle.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_021D95A0  0x021D95A0  thumb  ov119
 */

extern int func_021D8AA8(void *p);
extern void *func_021D8FA4(void *p, int i);
typedef unsigned int   u32;
extern u32 func_021D95A0(void *mon);

int func_021D95D0(void *p)
{
    int b = 0;

    if (func_021D8AA8(p))
        b = 1;
    return func_021D95A0(func_021D8FA4(p, b));
}

