/*
 * function: func_02012314
 * address:  0x02012314
 * packet:   pkt_02012304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern void func_020307B0(void *p);
void func_02012314(char *p)
{
    void *q = *(void **)(p + 0xc);
    if (q) func_020307B0(q);
    func_020307B0(p);
}
