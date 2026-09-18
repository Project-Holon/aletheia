/*
 * unit:     no
 * function: func_0200A1A8
 * address:  0x0200A1A8
 * packet:   pkt_0200A170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern void *func_0200A41C(void *p);
extern void func_0200A49C(void *p);
extern void func_0200A480(void *p);
int func_0200A1A8(char *p, unsigned int bit)
{
    int r = 0;
    unsigned char *t = (unsigned char *)func_0200A41C(p);
    func_0200A49C(p);
    if (bit < 0x800) {
        if (t[bit >> 3] & (1 << (bit & 7)))
            r = 1;
    }
    func_0200A480(p);
    return r;
}
