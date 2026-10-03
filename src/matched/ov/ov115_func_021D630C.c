/*
 * function: func_021D630C
 * address:  0x021D630C
 * packet:   pkt_021D630C
 * region:   ov115
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021D6134  0x021D6134  thumb  ov115
 */

typedef unsigned int   u32;
u32 func_020221A4(void);
void func_021D6134(void *a0, int a1, int a2);

void func_021D630C(void *a0)
{
    if (func_020221A4())
        func_021D6134(a0, 0, 0x221);
}
