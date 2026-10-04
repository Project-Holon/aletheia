/*
 * function: func_021BD5C4
 * address:  0x021BD5C4
 * packet:   pkt_021BD5C4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_021BC610  0x021BC610  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern int func_020056A0(void (*)(void), void *, int);
typedef unsigned int   u32;
extern void func_021BC610(u32 a0, u32 a1);

void func_021BD5C4(char *p)
{
    *(int *)(p + 0x154) = func_020056A0((void (*)(void))func_021BC610, p, 0);
}
