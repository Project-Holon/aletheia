/*
 * function: func_021BA4B4
 * address:  0x021BA4B4
 * packet:   pkt_021BA4B4
 * region:   ov218
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */

extern void func_0204B3B4(void *);

void func_021BA4B4(char *p)
{
    int i;
    for (i = 0; i < 0x24; i++)
    {
        void *q = *(void **)(p + 0x240 + i * 4);
        if (q != 0)
        {
            func_0204B3B4(q);
        }
    }
}
