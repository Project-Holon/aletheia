/*
 * unit:     no
 * address:  0x02031140
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02031140
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * Two calls into the TwlSDK environment/resource module: first with a
 * pointer stashed at +0x14 of the argument, then with the argument itself.
 * ENV_SetResourceSet is the recovered SDK symbol at 0x020307B0
 * (TwlSDK/libenv.TWL.HYB.a(env_system.o)); this whole packet's accessors
 * (sub_0202FBAC and neighbours) read the resource-set table that
 * ENV_SetResourceSet installs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02031140.c \
 *       --func sub_02031140 --addr 0x02031140 --cc 1.1p1
 */

struct S02031140 {
    char  pad[0x14];
    void *field14;
};

extern void ENV_SetResourceSet(void *p);

void sub_02031140(struct S02031140 *p)
{
    ENV_SetResourceSet(p->field14);
    ENV_SetResourceSet(p);
}
