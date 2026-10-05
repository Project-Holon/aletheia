/*
 * function: func_0216DB4C
 * address:  0x0216DB4C
 * packet:   pkt_0216DB4C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 *
 * symbols:
 *   func_0216D548   0x0216D548  thumb  ov010
 *   func_0216D550   0x0216D550  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D548(void *, unsigned, int);
extern int func_0216D550(void *, unsigned, int);

int func_0216DB4C(void *a0, int a1, int a2)
{
    if (a1 == 1)
        return func_0216D548(a0, 0x200, a2);

    return func_0216D550(a0, 0x200, a2);
}

