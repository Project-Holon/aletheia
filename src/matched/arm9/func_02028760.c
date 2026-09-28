/*
 * unit:     no
 * function: func_02028760
 * address:  0x02028760
 * packet:   pkt_02028590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern void *func_02030734(void *a, int size, int b, void *name, int line);
extern void func_020287B4(void *p);
void *func_02028760(void *a, int v)
{
    char *p = (char *)func_02030734(a, 0xa, 0, (void *)0x020A7500, 0x42);
    func_020287B4(p);
    *p = (char)v;
    return p;
}
