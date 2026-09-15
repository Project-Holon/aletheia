/*
 * unit:     yes
 * function: sub_0204D494
 * address:  0x0204D494
 * packet:   pkt_0204D478
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02064384  0x02064384  arm
 *   sub_0204D494  0x0204D494  arm
 *   sub_0204D4A4  0x0204D4A4  arm
 *
 * Two of the three row-0 handlers of the eight-by-three table at 0x020A1394
 * (src/matched/func_0204D324.c has the row map).  Unlike the row-1 and row-7
 * handlers, which return the +0xc subobject directly, the row-0 handlers tail
 * call through it: `ldr ip,[pc,#4]; add r0,r0,#0xc; bx ip` is the one-section
 * tail-call form, docs/idioms/tail-call-is-a-pool-word-and-bx.md.  Neither
 * saves lr, so disasm.py gives them no labels and they used to be the
 * `EXACT*` tail of sub_0204D478.
 *
 * Cut out of the natural 0204D478..0204D4C4 range on the advice of
 * `--suggest-split`: the row-0 pool word 0x020A1394 is the array base itself,
 * so its only image-wide witness is the relocation site inside sub_0204D478,
 * and 0x02064AB4 (the third handler's target) has no witness at all.  Those
 * two functions are parked in src/pending/; these two are attested `label`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D494.c \
 *       --addr 0x0204D494 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u32 type;
    u8  pad_04[8];
    u8  unk_0c;
};

extern void *sub_02064384(void *p);

void *sub_0204D494(struct Obj *o)
{
    return sub_02064384(&o->unk_0c);
}

void *sub_0204D4A4(struct Obj *o)
{
    return sub_02064384(&o->unk_0c);
}
