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
 * status:   EXACT*
 */

struct Obj;
extern unsigned int func_0200A400(struct Obj *obj);
extern void *func_0200A43C(struct Obj *obj, unsigned int index);
typedef unsigned int   u32;
extern u32 func_02009F0C(u32 a);
int func_02009F50(char *p, unsigned int idx)
{
    unsigned char *e = (unsigned char *)func_0200A43C((struct Obj *)p, idx);
    func_0200A400((struct Obj *)p);
    if (idx < 0xc && func_02009F0C(*(unsigned char *)((char *)e + 0xb3)) != 0)
        return 1;
    return 0;
}

