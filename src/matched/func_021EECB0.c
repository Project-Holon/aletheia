/*
 * function: func_021EECB0
 * address:  0x021EECB0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE408  0x021EE408  thumb  ov170
 *
 * Re-key the 0xA168 field unless the caller has a real selector.
 *   Two register facts pin it: the else-branch call must forward BOTH
 *   live argument registers (func_021EE408(p, a) -- the one-argument
 *   form makes the range-check temp land in r1 where the image has r2),
 *   and the stored value is the reloaded 0xA168 word, not the call's
 *   result (the field is re-read after the 0x70 call).
 */

extern void func_020260E4(int, int);
extern void func_021EE408(char *, int);
extern void func_020260E4(int, int);
extern void func_021EE408(char *, int);
void func_021EECB0(char *p, int a)
{
    int v;
    if (a == 0 || (unsigned)(a - 5) <= 1) {
        func_020260E4(*(int *)(*(int *)(p + 0x2c) + 0x70),
                      *(int *)(*(int *)(p + 0x2c) + 0xA168) & 0xff);
        v = *(int *)(*(int *)(p + 0x2c) + 0xA168);
    } else {
        func_021EE408(p, a);
        v = a;
    }
    *(int *)(*(int *)(p + 0x2c) + 0xA168) = v;
}

