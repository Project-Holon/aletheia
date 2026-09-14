/*
 * function: sub_02023DC4
 * address:  0x02023DC4
 * packet:   pkt_02023A50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *
 * A three-field struct forwarder: unpack the three words of `args` as
 * positional arguments to sub_02023BFC, then tail-call the ARM function
 * func_02030EAC on the first argument and return its result. The `blx`
 * is the interworking call the linker rewrites a Thumb `bl` into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02023DC4.c \
 *       --func sub_02023DC4 --addr 0x02023DC4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Args3 {
    u32 f0;
    u32 f4;
    u32 f8;
};

extern void sub_02023BFC(u32 a, u32 b, u32 c);
extern u32  func_02030EAC(void *obj);

u32 sub_02023DC4(void *obj, struct Args3 *args)
{
    sub_02023BFC(args->f0, args->f4, args->f8);
    return func_02030EAC(obj);
}
