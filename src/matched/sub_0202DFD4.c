/*
 * unit:     no
 * function: sub_0202DFD4
 * address:  0x0202DFD4
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *
 * Three teardown calls on three consecutive pointer fields, each a
 * different ARM entry point, in the order the fields sit in the struct.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202DFD4.c \
 *       --func sub_0202DFD4 --addr 0x0202DFD4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

struct Obj0202DFD4 {
    u8    pad[8];
    void *unk08;
    void *unk0C;
    void *unk10;
};

extern void func_0204ADA4(void *p);
extern void func_0204A8D4(void *p);
extern void func_0204AFD8(void *p);

void sub_0202DFD4(struct Obj0202DFD4 *p)
{
    func_0204ADA4(p->unk08);
    func_0204A8D4(p->unk0C);
    func_0204AFD8(p->unk10);
}
