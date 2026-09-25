/*
 * function: func_021BA43C
 * address:  0x021BA43C
 * packet:   pkt_021BA43C
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */

extern void func_020452E8(void *);

void func_021BA43C(int unused, char *p)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
    {
        func_020452E8(*(void **)(p + 0x8c + i * 4));
    }
}
