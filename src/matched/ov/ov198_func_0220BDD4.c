/*
 * function: func_0220BDD4
 * address:  0x0220BDD4
 * packet:   pkt_0220BDD4
 * region:   ov198
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

void func_0220BDD4(char *p)
{
    unsigned int i;
    for (i = 0; i < *(unsigned char *)(p + 0x2174); i++)
    {
        func_020452E8(*(void **)(p + 0x1f70 + i * 8));
    }
}
