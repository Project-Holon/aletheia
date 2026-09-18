/*
 * unit:     no
 * function: func_0200A104
 * address:  0x0200A104
 * packet:   pkt_0200A104
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern unsigned int func_0200A400(void *p);
extern void func_0200A49C(void *p);
extern void func_0200A480(void *p);
extern void *func_0200A43C(void *p, int i);
int func_0200A104(char *p, unsigned int idx)
{
    int r = 0;
    unsigned int n = func_0200A400(p);
    func_0200A49C(p);
    if (idx < n) {
        unsigned char *e = (unsigned char *)func_0200A43C(p, idx);
        if (((unsigned int)(*(unsigned char *)((char *)e + 0xb4)) << 0x1e) >> 0x1f)
            r = 1;
    }
    func_0200A480(p);
    return r;
}
