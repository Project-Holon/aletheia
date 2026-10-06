/*
 * function: func_020345DC
 * address:  0x020345DC
 * packet:   pkt_02034520
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct Struct020345DC {
    void *ptr;
};

extern unsigned int func_02033C9C(void *a);
typedef unsigned int   u32;
extern u32 sub_020307B0(void *p);

void func_020345DC(struct Struct020345DC *obj)
{
    func_02033C9C(obj->ptr);
    sub_020307B0(obj);
}
