/*
 * function: func_021DF868
 * address:  0x021DF868
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Count the two arm timers down and re-arm the ones that expired.
 *
 * symbols:
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021E68B4  0x021E68B4  thumb  ov119
 */

extern int func_021D8AA8(void *p);
extern void func_021E68B4(int p, int n);

void func_021DF868(void *p)
{
    int i;

    if (func_021D8AA8(p) == 0)
        return;
    for (i = 0; i < 2; i++) {
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            continue;
        ((unsigned char *)p)[0x11e4 + i]--;
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            func_021E68B4((int)p, i);
    }
}

