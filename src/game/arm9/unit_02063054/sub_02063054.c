/*
 * function: sub_02063054
 * address:  0x02063054
 * packet:   pkt_02063054
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm7tdmi
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * The sub-engine twin of src/matched/sub_02063068.c, biasing the caller's byte
 * offset by 0x07000400 instead of 0x07000000 and tail-calling the transfer
 * routine at 0x02082A60.
 *
 * -proc evidence, measured 2026-09-19 by wave r8 lane small-3 (the packet's
 * proc_hints line reads arm946e, but this row's bytes say otherwise): at
 * -proc arm946e the two-instruction bias is scheduled as
 *   +0000 add r1, r1, #0x400
 *   +0004 ldr ip, [pc, #4]
 *   +0008 add r1, r1, #0x7000000
 *   +000C bx ip
 * i.e. mwcc hoists the first `add` above the load of the tail-call target,
 * while the image loads the target first and then emits both adds
 * (+0000 ldr ip, [pc, #8]; +0004 add; +0008 add; +000C bx ip).  Every spelling
 * of the sum tried under arm946e (single expression, reversed add order, named
 * local, `|`, pointer-typed second parameter) hoists the add; under
 * `-proc arm7tdmi` the same C reproduces the image's four instructions with
 * zero concrete mismatches.  dsi/../1.2/sp2 is worse (it materialises the bias
 * in r2 and needs 24 bytes).  The trailing `*` is the unlabelled follower at
 * 0x02063068 (already matched as src/matched/sub_02063068.c): disasm.py gives
 * a prologue-less leaf no label, so the listing extent runs from 0x02063054 to
 * 0x02063078.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02063054.c \
 *       --func sub_02063054 --addr 0x02063054 --arm \
 *       --flags "-O4,p -proc arm7tdmi"
 *
 * symbols:
 *   sub_02082A60  0x02082A60  arm
 */

typedef unsigned int u32;

extern void sub_02082A60(void *src, u32 dest);

void sub_02063054(void *src, u32 offset)
{
    sub_02082A60(src, offset + 0x400 + 0x7000000);
}
