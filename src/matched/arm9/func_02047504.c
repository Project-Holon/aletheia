/*
 * function: func_02047504
 * address:  0x02047504
 * packet:   pkt_02047400
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C      0x02146A5C  data
 *   func_0206E358   0x0206E358  arm
 *   func_020307B0   0x020307B0  arm
 *
 * Release one tagged record: nothing at all for a null pointer, and nothing
 * for a record whose halfword tag at +0 is not 0x7A14.  Otherwise hand the
 * pointer's +4 field to func_0206E358, drop the tag to one below its own
 * value and free the record.
 *
 * The tag is pooled once (0x7A14 is past a `mov` immediate) and reused for
 * the decrement, which is why the new value arrives as `sub r1, r4, #1`
 * rather than as a second literal; the `mov r0, r5` before the store is the
 * free call's argument being set up early.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047504.c \
 *       --func func_02047504 --addr 0x02047504 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 tag;
    u16 unk_02;
    u32 unk_04;
};

extern u32 g_02146A5C;
extern void func_0206E358(u32 ctx, u32 field);
extern u32 func_020307B0(void *p);

void func_02047504(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x7A14)
        return;

    func_0206E358(g_02146A5C, p->unk_04);
    p->tag = 0x7A14 - 1;
    func_020307B0(p);
}
