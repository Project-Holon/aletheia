/*
 * unit:     no
 * function: func_0200A000
 * address:  0x0200A000
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

struct Obj;
extern unsigned int func_0200A400(struct Obj *p);
extern void func_0200A49C(struct Obj *p);
extern void func_0200A480(struct Obj *p);
extern void *func_02009FD4(char *p, unsigned int idx);
extern void func_02082D44(void *dst, void *src, int n);
int func_0200A000(char *p, int idx, void *buf)
{
    char *e;
    int r = 0;
    func_0200A400((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    e = (char *)func_02009FD4(p, idx);
    if (e != 0) {
        func_02082D44(e, buf, 0xcc);
        r = 1;
    }
    func_0200A480((struct Obj *)p);
    return r;
}
