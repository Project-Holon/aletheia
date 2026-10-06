/*
 * function: func_0201235C
 * address:  0x0201235C
 * packet:   pkt_0201235C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012314  0x02012314  thumb
 *   func_02012108  0x02012108  thumb
 *
 * Reads the object's +0x10 word into a register first, then copies its +0 word
 * out through the caller's pointer and hands that same value to
 * func_02012314, then passes the +0x10 word and the pointer to func_02012108.
 * Order matters: the +0x10 load is hoisted above the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201235C.c \
 *       --func func_0201235C --addr 0x0201235C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct S0201235C {
    u32 f00;
    unsigned char pad[0xc];
    u32 f10;
};

extern void func_02012314(char *p);
struct Ctx;
extern void func_02012108(struct Ctx *p, u32 v);

void func_0201235C(struct S0201235C *o, u32 *out)
{
    u32 t = o->f10;
    u32 v = o->f00;

    *out = v;
    func_02012314((char *)o);
    func_02012108((struct Ctx *)t, (u32)out);
}
