/*
 * function: func_02206128
 * address:  0x02206128
 * packet:   pkt_ov094_02206128
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern void func_0204B3B4(void *h);

void func_02206128(char *p)
{
    if (*(void **)(p + 0x21c) != 0) {
        func_0204B3B4(*(void **)(p + 0x21c));
        *(void **)(p + 0x21c) = 0;
    }
}
