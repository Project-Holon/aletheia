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

extern void *func_02030734(unsigned int a, unsigned int size, int b, const char *name, unsigned short line);
struct Fader;
extern void func_020287B4(struct Fader *s);
void *func_02028760(void *a, int v)
{
    char *p = (char *)func_02030734((unsigned int)a, 0xa, 0, (const char *)0x020A7500, 0x42);
    func_020287B4((struct Fader *)p);
    *p = (char)v;
    return p;
}
