/*
 * function: func_02075794
 * address:  0x02075794
 * packet:   pkt_02075404
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02073344  0x02073344  arm
 *   func_020734AC  0x020734AC  arm
 *   func_02074CD0  0x02074CD0  arm
 *   func_020733DC  0x020733DC  arm
 *   func_020733E8  0x020733E8  arm
 *   func_02072F48  0x02072F48  arm
 *   func_02072F88  0x02072F88  arm
 *   func_020730DC  0x020730DC  arm
 *
 * The four-step open/bind path behind func_02075618 and func_02075698: take a
 * voice handle (func_02073344), read its slot (func_020734AC), load the wave
 * data through func_02074CD0 and release the handle if that fails, then bind
 * the loaded data and push the three per-voice parameters.  Eight arguments,
 * four in registers and four on the stack.
 *
 * THE BODY IS docs/notes/func_02075794.c.txt's BODY, UNCHANGED.  That note
 * measured it at 200 bytes against the original's 196 and recorded seven
 * rejected spellings, diagnosing a callee-saved permutation:
 *
 *     slot   original   that C
 *     a1     r8         r5
 *     a2     r7         r8
 *     s0     r6         r7
 *     h      r5         r6
 *
 * with the extra instruction being `mov r5, #0; mov r3, r5` for func_02074CD0's
 * fourth argument where the image emits `mov r3, #0` directly.  That is
 * verbatim the "kept constants" tell of docs/FRONTEND-PINS.md, and the note
 * measured every one of its seven spellings under the project default 1.1p1.
 * Under the cluster's ../2.0/sp2 pin the SAME C is 196 bytes, 0 mismatches,
 * first compile, with the image's register assignment: the residue was the
 * front end, not the source, exactly as docs/families/cluster_020737C0.h warns
 * for this address range.
 *
 * FILING THIS UNBLOCKS src/pending/func_02075618.c, whose header names the
 * PC24 at +0x0074 (this address, single caller image-wide) as the one site
 * keeping it at MATCH; with this entry EXACT the site resolves as `matched`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075794.c \
 *       --func func_02075794 --addr 0x02075794 --arm --cc ../2.0/sp2
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_02073344(u32 a0, u32 a1, u32 a2);
extern u32   func_020734AC(u32 a, void *h);
extern u32   func_02074CD0(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void  func_020733DC(void *h);
extern void  func_020733E8(void *h, u32 *a, u32 b, u32 c);
extern void  func_02072F48(u32 a, u32 b);
extern void  func_02072F88(u32 a, u32 b);
extern void  func_020730DC(u32 a, u32 b, u32 c);

u32 func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u8 *s1, u32 s2, u32 s3)
{
    void *h;
    u32 v;
    u32 slot;

    h = func_02073344(a0, a1, a3);
    if (h == 0) {
        return 0;
    }

    v = func_020734AC(a1, h);

    if (func_02074CD0(a2, 6, v, 0, &slot) != 0) {
        func_020733DC(h);
        return 0;
    }

    func_020733E8(h, (u32 *)(s1 + *(u32 *)(s1 + 0x18)), *(u32 *)s0, slot);
    func_02072F48(a0, s0[6]);
    func_02072F88(a0, s0[7]);
    func_020730DC(a0, s2, s3);
    return 1;
}
