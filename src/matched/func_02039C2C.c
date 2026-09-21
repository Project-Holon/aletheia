/*
 * function: func_02039C2C
 * address:  0x02039C2C
 * packet:   pkt_02039C2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A message handler from the dispatch table at 0x020A0870, sharing the
 * five-argument shape of its table neighbour func_02039B5C: the first four
 * arguments arrive in r0-r3 and the fifth, the receiver object, on the
 * stack.  This one copies the message's 16-bit tag into the receiver's
 * 0x44 field and ignores everything else.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Msg {
    u16 tag;
};

struct Obj {
    u16 pad[0x44 / 2];
    u16 tag;
};

void func_02039C2C(u32 a0, u32 a1, struct Msg *msg, u32 a3, struct Obj *obj)
{
    obj->tag = msg->tag;
}
