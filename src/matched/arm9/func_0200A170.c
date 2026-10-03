/*
 * unit:     no
 * function: func_0200A170
 * address:  0x0200A170
 * packet:   pkt_0200A170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

struct Obj;
extern unsigned int func_0200A400(struct Obj *obj);
extern void func_0200A49C(struct Obj *obj);
extern void func_0200A480(struct Obj *obj);
extern int func_02009F50(char *p, unsigned int idx);
int func_0200A170(char *p)
{
    int found = 0;
    unsigned int i;
    unsigned int n = func_0200A400((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    for (i = 0; i < n; i++) {
        if (func_02009F50(p, i) == 1)
            found = 1;
    }
    func_0200A480((struct Obj *)p);
    return found;
}
