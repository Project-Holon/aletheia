/*
 * function: sub_02023DA8
 * address:  0x02023DA8
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
 * The four-field member of the sub_02023DC4/sub_02023D94 forwarder
 * family: unpack the four words of `args` as positional arguments to
 * sub_02023B74, then tail-call func_02030EAC on the first argument and
 * return its result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02023DA8.c \
 *       --func sub_02023DA8 --addr 0x02023DA8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Args4 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
};

extern void sub_02023B74(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02030EAC(void *obj);

u32 sub_02023DA8(void *obj, struct Args4 *args)
{
    sub_02023B74(args->f0, args->f4, args->f8, args->fC);
    return func_02030EAC(obj);
}
