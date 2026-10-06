/*
 * file:     unit_02075560_p02.c
 * unit:     yes
 * function: func_02075698, func_02075794, func_02075858, func_02075968
 * address:  0x02075698
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02073344  0x02073344  arm
 *   func_020734AC  0x020734AC  arm
 *   func_02074CD0  0x02074CD0  arm
 *   func_02074BEC  0x02074BEC  arm
 *   func_020733DC  0x020733DC  arm
 *   func_020733E8  0x020733E8  arm
 *   func_02072F48  0x02072F48  arm
 *   func_02072F88  0x02072F88  arm
 *   func_020730B8  0x020730B8  arm
 *   func_020730DC  0x020730DC  arm
 *   data_0214EAC0  0x0214EAC0  data
 *   data_020A5D08  0x020A5D08  data
 *   func_02073A60  0x02073A60  arm
 *   func_02073AD0  0x02073AD0  arm
 *   func_02075994  0x02075994  arm
 *   func_02075BD4  0x02075BD4  arm
 *   func_02075C08  0x02075C08  arm
 *   func_02075C20  0x02075C20  arm
 */
#include "../../matched/include/Obj16686.h"
#include "../../matched/include/Obj08953.h"
#include "../../matched/include/Obj16687.h"

struct Node;
struct Obj;
struct A;
struct LerpObj;
struct Obj75994;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed int     s32;

typedef signed short s16;

struct Slot {
    u8  pad000[0xf0];
    u8  lerp[0x118 - 0xf0];
    s32 b0 : 1;
    s32 b1 : 1;
    s32 b2 : 1;
    s32 b3 : 1;
    s32 brest : 28;
    s32 f11c;
    s32 f120;
    u8  pad124[0x15c - 0x124];
    s32 f15c;
    s32 f160;
    s32 f164;
    u8  pad168[0x17c - 0x168];
};

typedef struct {
    u8  unk000[0x118];
    s32  b0 : 1;
    s32  b1 : 1;
    s32  b2 : 1;
    s32  rest : 29;
    u8  unk11c[0x154 - 0x11c];
    u32 *unk154;
} Obj02075968;

extern struct Node *func_02073344(struct Obj *o, s32 idx, s32 pri);
extern void *func_020734AC(s32 idx, void *owner);
extern u32   func_02074CD0(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void  func_020733DC(void *h);
extern void func_020733E8(struct Obj *o, const void *seqBase, u32 seqOffset, const void *bankData);
extern void func_02072F48(struct Obj *o, u8 v);
extern void func_02072F88(struct Obj *o, u32 v);
extern void  func_020730B8(u32 a, u32 b);
extern void func_020730DC(struct Obj *o, u32 a, u32 b);
extern void func_02073A60(struct A *a);
extern void func_02073AD0(struct Slot *, s32);
extern void func_02075994(struct Obj75994 *o);
extern s32 func_02075BD4(struct Obj *o);
extern void func_02075C08(struct LerpObj *obj);
extern int func_02075C20(struct LerpObj *obj);
u32 func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1);
u32 func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u8 *s1, u32 s2, u32 s3);
void func_02075858(void);
void func_02075968(Obj02075968 *o);
extern struct Slot data_0214EAC0[4];
extern const s16 data_020A5D08[];




/*
 * Sibling of src/matched/func_02075794.c (same open / bind / release shape):
 * open a handle with func_02073344, bind a slot through func_02074CD0 (kind
 * 6) and a block through func_02074BEC (kind 1, keyed by the sixth argument),
 * releasing the handle on either failure; then attach the block's +0x18
 * payload to the handle and apply the descriptor's bytes 6 and 7.  Called by
 * func_02075560 and func_020755A8 with the record pointer as s0 and the
 * record id as s1.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075698.c \
 *       --func func_02075698 --addr 0x02075698 --arm --cc ../2.0/sp2
 *   EXACT, 252 bytes, 10 of 10 relocation sites resolved (sp2p2 EXACT too,
 *   dsi/1.1p1 260 bytes DIFF).
 */
u32 func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1)
{
    void *h;
    u32 v;
    u8 *blk;
    u32 slot;

    h = func_02073344((struct Obj *)a0, a1, a3);
    if (h == 0) {
        return 0;
    }
    v = (u32)func_020734AC(a1, h);
    if (func_02074CD0(a2, 6, v, 0, &slot) != 0) {
        func_020733DC(h);
        return 0;
    }
    if (func_02074BEC(s1, 1, v, 0, (u32 *)(&blk)) != 0) {
        func_020733DC(h);
        return 0;
    }
    func_020733E8(h, (u32 *)(blk + ((struct Obj16686 *)blk)->f18), 0, (const void *)slot);
    func_02072F48((struct Obj *)a0, s0[6]);
    func_02072F88((struct Obj *)a0, s0[7]);
    func_020730B8(a0, s1);
    return 1;
}




/*
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
u32 func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u8 *s1, u32 s2, u32 s3)
{
    void *h;
    u32 v;
    u32 slot;

    h = func_02073344((struct Obj *)a0, a1, a3);
    if (h == 0) {
        return 0;
    }

    v = (u32)func_020734AC(a1, h);

    if (func_02074CD0(a2, 6, v, 0, &slot) != 0) {
        func_020733DC(h);
        return 0;
    }

    func_020733E8(h, (u32 *)(s1 + ((struct Obj16687 *)s1)->f18), ((struct Obj08953 *)s0)->f0, (const void *)slot);
    func_02072F48((struct Obj *)a0, s0[6]);
    func_02072F88((struct Obj *)a0, s0[7]);
    func_020730DC((struct Obj *)a0, s2, s3);
    return 1;
}



/*
 * The per-slot tick of the four 0x17c-byte entries of data_0214EAC0: bit 0
 * gates the slot, bit 2 + f120 runs the reconfigure and flips the pending
 * bits, bit 1 steps the lerp and recomputes the f164 sum out of the s16
 * table data_020A5D08, and bit 3 polls for completion.
 *
 * PINNED ../2.0/sp2 on the "kept branches" tell (docs/FRONTEND-PINS.md),
 * cross-jump form. The image writes the f11c == 0 arm's tail out in full --
 * `mov r0, r7` (`07 00 a0 e1`) at 0x02075884 / `bl func_02075994` at
 * 0x02075888 / `b 0x0207594c` (`2e 00 00 ea`) at 0x0207588C -- although the
 * bit-3 completion arm ends in a byte-identical `mov r0, r7` / `bl
 * func_02075994` pair at 0x02075944/0x02075948. dsi/1.1p1 -O4,p cross-jumps
 * the two, branching the f11c arm straight into the completion arm's pair,
 * giving 264 bytes against the original's 272 with everything after
 * 0x02075884 shifted by eight. An explicit `goto` past the else, the
 * if/else chain and the early-continue spelling all fold the same way.
 * Under the pin the same C is 272 bytes, 0 mismatches: BYTE-CORRECT.
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. Three
 * sites are unattested: the two PC24 to func_02075994, whose only branches
 * image-wide are these two `bl`s inside this function, and the ABS32 at
 * +0x108, whose only pool word image-wide is this function's own at
 * 0x02075960 (inside the 272-byte compared range), so `literal` refuses it.
 * Filing func_02075994 EXACT clears the two PC24 sites but not the ABS32.
 *
 * NOTE for src/pending/func_02072758.c: that file names 0x02075858 as one
 * of its three blocking PC24 sites. This file is byte-correct but stays
 * MATCH, so it does NOT promote func_02072758 -- only a `matched` entry can.
 */
void func_02075858(void)
{
    s32 i;
    s32 v;
    s32 a, b, c, d;
    struct Slot *s = data_0214EAC0;

    for (i = 0; i < 4; i++) {
        if (s->b0) {
            if (s->f11c == 0) {
                func_02075994((struct Obj75994 *)s);
                goto next;
            } else {
                if (s->b2 && s->f120 != 0) {
                    func_02073A60((struct A *)s);
                    s->b1 = 1;
                    s->b2 = 0;
                }
                if (s->b1) {
                    func_02075C08((struct LerpObj *)s->lerp);
                    a = data_020A5D08[s->f15c];
                    b = func_02075BD4((struct Obj *)s->lerp) >> 8;
                    c = s->f160;
                    d = data_020A5D08[b];
                    v = data_020A5D08[c] + (d + a);

                    if (v != s->f164) {
                        func_02073AD0(s, v);
                        s->f164 = v;
                    }
                    if (s->b3) {
                        if (func_02075C20((struct LerpObj *)s->lerp) != 0) {
                            func_02075994((struct Obj75994 *)s);
                        }
                    }
                }
            }
        }
next:
        s++;
    }
}


/*
 * Release the object's attached cell (+0x154: clear what it points at, then
 * the pointer) and clear flag bits 0, 2 and 1 of the word at +0x118, in that
 * order.  The +0x118 word is the signed one-bit bitfield set its callers
 * 0x02075A2C and 0x02075994 test with lsl/asrs (docs/notes/pkt_02075794.c.txt).
 *
 * Front end: ../2.0/sp2.  The tell is the first clear writing a FRESH
 * register (`bic r2, r1, #1` then `bic r1, r2, #4`): 1.1p1 coalesces it
 * (`bic r1, r1, #1`, 2 bytes out under every spelling and a 2000-compile
 * anneal); ../2.0/sp2 and sp2p2 give the image's allocation for both the
 * bitfield and the three-statement mask spelling.
 */
void func_02075968(Obj02075968 *o)
{
    if (o->unk154 != 0) {
        *o->unk154 = 0;
        o->unk154 = 0;
    }
    o->b0 = 0;
    o->b2 = 0;
    o->b1 = 0;
}
