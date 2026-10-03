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

struct Obj;
extern void *func_0200A41C(struct Obj *p);
extern void func_0200A49C(struct Obj *p);
extern void func_0200A480(struct Obj *p);
int func_0200A1A8(char *p, unsigned int bit)
{
    int r = 0;
    unsigned char *t = (unsigned char *)func_0200A41C((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    if (bit < 0x800) {
        if (t[bit >> 3] & (1 << (bit & 7)))
            r = 1;
    }
    func_0200A480((struct Obj *)p);
    return r;
}
