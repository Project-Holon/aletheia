/*
 * function: func_021C08D4
 * address:  0x021C08D4
 * packet:   pkt_021C08D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_021BF6BC  0x021BF6BC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern int func_020056A0(void (*)(void), void *, int);
extern void func_021BF6BC(void);

void func_021C08D4(char *p)
{
    *(int *)(p + 0x3c0) = func_020056A0(func_021BF6BC, p, 0);
}
