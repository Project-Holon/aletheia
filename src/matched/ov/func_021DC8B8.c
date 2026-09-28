/*
 * function: func_021DC8B8
 * address:  0x021DC8B8
 * packet:   pkt_021DC8B8
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   func_021DC8E4  0x021DC8E4  thumb  ov171
 */

extern int func_020056A0(void (*)(void), int *, int);
extern void func_021DC8E4(void);

void func_021DC8B8(int *p)
{
    *(int *)((char *)p + 0xB28) = func_020056A0(func_021DC8E4, p, 0);
}
