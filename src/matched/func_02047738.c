/*
 * function: func_02047738
 * address:  0x02047738
 * packet:   pkt_02047564
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0   0x020307B0  arm
 *
 * Retire one record: a null pointer and a mismatched tag 0x2185 are both
 * passed over by predicated returns, then the owned pointer at +8 is freed
 * and cleared (only if it was set) before the tag is left at 0x2184 and the
 * record itself is freed.  Both tags are past a `mov` immediate and so are
 * two pool words at the end of the function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047738.c \
 *       --func func_02047738 --addr 0x02047738 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16  tag;
    u16  pad_02;
    u32  unk_04;
    void *unk_08;
};

extern void func_020307B0(void *p);

void func_02047738(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x2185)
        return;

    if (p->unk_08 != 0) {
        func_020307B0(p->unk_08);
        p->unk_08 = 0;
    }

    p->tag = 0x2184;
    func_020307B0(p);
}
