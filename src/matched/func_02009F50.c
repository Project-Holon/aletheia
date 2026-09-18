/*
 * unit:     no
 * function: func_02009F50
 * address:  0x02009F50
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern int func_0200A400(void *p);
extern void *func_0200A43C(void *p, int i);
extern int func_02009F0C(int v);
int func_02009F50(char *p, unsigned int idx)
{
    unsigned char *e = (unsigned char *)func_0200A43C(p, idx);
    func_0200A400(p);
    if (idx < 0xc && func_02009F0C(*(unsigned char *)((char *)e + 0xb3)) != 0)
        return 1;
    return 0;
}

