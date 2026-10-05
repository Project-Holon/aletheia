/*
 * function: sub_02023D94
 * address:  0x02023D94
 * packet:   pkt_02023A50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *
 * The two-field member of the sub_02023DC4/sub_02023DA8 forwarder family:
 * unpack the two words of `args` as positional arguments to
 * sub_02023B48, then tail-call func_02030EAC on the first argument and
 * return its result. `ldm r1, {r0, r1}` is the two-word load; a plain
 * struct-by-value copy or two separate field reads through the pointer
 * both produce the same pair of loads once the fields are consecutive
 * words read in order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02023D94.c \
 *       --func sub_02023D94 --addr 0x02023D94 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Args2 {
    u32 f0;
    u32 f4;
};

extern void sub_02023B48(u32 a, u32 b);
extern u32  func_02030EAC(void *obj);

u32 sub_02023D94(void *obj, struct Args2 *args)
{
    sub_02023B48(args->f0, args->f4);
    return func_02030EAC(obj);
}
