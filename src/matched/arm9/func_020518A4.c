/*
 * function: func_020518A4
 * address:  0x020518A4
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword setter on the same object as its packet-mate
 * src/matched/func_020518AC.c: stores the argument into field 0x70.
 */

typedef unsigned short u16;

struct Obj {
    char pad[0x70];
    u16 f70;
};

void func_020518A4(struct Obj *o, u16 v)
{
    o->f70 = v;
}
