/*
 * unit:     no
 * address:  0x02030B50
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * function: sub_02030B50
 *
 * BLOCKED on three of nine relocation sites; all 84 concrete bytes are
 * correct. Each blocked target's only reference in the image is a call or
 * pool word inside this function:
 *
 *   0x0209128C  bracketing call, twice   no packet claimed, out of range
 *   0x02060F50  the heap walk            library block around 0x02060000
 *   0x02030A7C  the visitor, ABS32       src/pending/sub_02030A7C.c
 *
 * 0x02030A7C is byte-correct but permanently MATCH itself (its two data
 * symbols have no literal witness anywhere), so this file cannot be
 * promoted through that route either. --suggest-split cannot cut a single
 * function section.
 *
 * The heap report: four whole-heap queries whose results are thrown away,
 * then a walk of every live block through the visitor sub_02030A7C.
 *
 *   void sub_02030B50(u32 heapId)
 *
 * The four opening calls are sub_020303D8 (arena size), sub_02030344
 * (first block), sub_0203038C (the mode-4 dump) and sub_0203046C (the live
 * allocation count), each taking the same id and each discarding its
 * answer: a release build's remains of four printed lines. They are still
 * calls with side effects (every one of them writes g_EnvModule.error), so
 * none of them folds away.
 *
 * sub_0209128C brackets the walk, 1 before and 0 after. The 0 is not
 * materialised twice: `mov r4, #0` feeds both the third argument of
 * sub_02060F50 (via `mov r2, r4`) and the closing sub_0209128C(0), which
 * is why the id in r4 is dead by then and the register is reused
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The visitor is passed by address as an ABS32 pool word, so sub_02030A7C
 * must be an EXACT manifest entry for this file to resolve.
 *
 * symbols:
 *   sub_02030344    0x02030344  arm
 *   sub_0203038C    0x0203038C  arm
 *   sub_020303D8    0x020303D8  arm
 *   sub_02030428    0x02030428  arm
 *   sub_0203046C    0x0203046C  arm
 *   sub_02030A7C    0x02030A7C  arm
 *   sub_02060F50    0x02060F50  arm
 *   sub_0209128C    0x0209128C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02030B50.c \
 *       --func sub_02030B50 --addr 0x02030B50 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 sub_020303D8(u32 heapId);
extern void *sub_02030344(u32 heapId);
extern void *sub_0203038C(u32 heapId);
extern u16 sub_0203046C(u32 heapId);
extern void *sub_02030428(u32 heapId);
extern void sub_02030A7C(void *hdr);
extern void sub_02060F50(void *arena, void (*visit)(void *), u32 arg);
extern void sub_0209128C(u32 on);

void sub_02030B50(u32 heapId)
{
    sub_020303D8(heapId);
    sub_02030344(heapId);
    sub_0203038C(heapId);
    sub_0203046C(heapId);
    sub_0209128C(1);
    sub_02060F50(sub_02030428(heapId), sub_02030A7C, 0);
    sub_0209128C(0);
}
