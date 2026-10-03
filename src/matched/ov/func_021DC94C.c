/*
 * function: func_021DC94C
 * address:  0x021DC94C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC970  0x021DC970  thumb  ov170
 *
 * Seat the 0x54 handler word.
 */



extern int func_020056A0(void *, void *, int);
typedef unsigned int   u32;
extern void func_021DC970(u32 a, char *p);
void func_021DC94C(char *p)
{
    *(int *)(*(int *)(p + 0x2c) + 0x54) = func_020056A0((void *)func_021DC970, p, 0);
}
