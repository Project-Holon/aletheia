/*
 * function: func_021DF8E0
 * address:  0x021DF8E0
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reset the two sub-objects and the decoder when in the first state.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021E68B4  0x021E68B4  thumb  ov119
 *   func_021E5868  0x021E5868  thumb  ov119
 */

extern int func_021D8AA8(void *p);
extern void func_021E68B4(void *p, int i);
extern void func_021E5868(void *p);

void func_021DF8E0(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 2; i++)
        func_021E68B4(p, i);
    func_021E5868(p);
}

