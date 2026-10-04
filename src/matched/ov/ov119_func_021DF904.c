/*
 * function: func_021DF904
 * address:  0x021DF904
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tear the object down when it is in the first state.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021E57FC  0x021E57FC  thumb  ov119
 */

extern int func_021D8AA8(void *p);
extern void func_021E57FC(int p);

void func_021DF904(void *p)
{
    if (func_021D8AA8(p))
        func_021E57FC((int)p);
}

