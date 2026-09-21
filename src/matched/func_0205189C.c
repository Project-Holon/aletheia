/*
 * function: func_0205189C
 * address:  0x0205189C
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Word setter on the same object as its packet-mate
 * src/matched/func_020518AC.c: stores the argument into field 0x6c.
 */

typedef unsigned int u32;

struct Obj {
    char pad[0x6c];
    u32 f6c;
};

void func_0205189C(struct Obj *o, u32 v)
{
    o->f6c = v;
}
