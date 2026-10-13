/*
 * file:     nns_snd_arcplayer.c
 * unit:     yes
 * function: func_02075560, func_020755A8, func_02075618, func_02075698, func_02075794, func_02075858, func_02075968, func_02075994, func_02075A2C, func_02075A94, func_02075AB8, func_02075B28, func_02075B54, func_02075B94
 * address:  0x02075560
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
 *   NNS_SndArcGetSeqArcInfo  0x02074388  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   func_02073344  0x02073344  arm
 *   func_020734AC  0x020734AC  arm
 *   func_02074CD0  0x02074CD0  arm
 *   func_02074BEC  0x02074BEC  arm
 *   func_020733DC  0x020733DC  arm
 *   func_020733E8  0x020733E8  arm
 *   NNS_SndHandleSetPlayerPriority  0x02072F48  arm
 *   NNS_SndHandlePause  0x02072F88  arm
 *   func_020730B8  0x020730B8  arm
 *   NNS_SndHandleSetSweep  0x020730DC  arm
 *   data_0214EAC0  0x0214EAC0  data
 *   data_020A5D08  0x020A5D08  data
 *   func_02073A60  0x02073A60  arm
 *   func_02073AD0  0x02073AD0  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 *   g_02150178  0x02150178  data
 *   g_0214EA90  0x0214EA90  data
 *   g_02150190  0x02150190  data
 *   func_02073898  0x02073898  arm
 *   func_02087988 0x02087988  arm
 *   func_0208799C 0x0208799C  arm
 *   func_02060614 0x02060614  arm
 *   func_020605B4 0x020605B4  arm
 *   func_020604AC 0x020604AC  arm
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 */

struct Entry;
struct Table;
struct Node;
struct SndTrack;
struct LerpObj;
struct DList;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short s16;

struct LerpObj {
    int start;
    int target;
    int step;
    int duration;
};

/* One of the four sound tracks at data_0214EAC0. */
struct SndTrack {
    u8  pad000[0xf0];
    struct LerpObj lerp;
    u8  pad100[0x118 - 0x100];
    s32 b0 : 1;
    s32 b1 : 1;
    s32 b2 : 1;
    s32 b3 : 1;
    s32 brest : 28;
    s32 f11c;
    s32 f120;
    u8  pad124[0x128 - 0x124];
    int ref_count;
    u8  pad12c[0x154 - 0x12c];
    u32 *unk154;
    u8  pad158[0x15c - 0x158];
    s32 f15c;
    s32 f160;
    s32 f164;
    u8  pad168[0x170 - 0x168];
    void (*f170)(struct SndTrack *o);
    u8  pad174[0x178 - 0x174];
    void (*cb)(struct SndTrack *o);
};

struct SndMedia { u32 f0; };

struct SndBlock {
    u8  pad00[0x18];
    u32 f18;
};

struct DListElem {
    u8  pad00[8];
    u32 f8;
};

struct Entry {   /* 0xC bytes each */
    u32 f0;
    u16 f4;
    u8  f6;
    u8  f7;
    u8  f8;
    u8  f9;
    u8  padA[2];
};

struct Table { u8 pad00[0x1c]; u32 count; struct Entry arr[]; };

extern void *NNS_SndArcGetSeqInfo(int index);
extern void *NNS_SndArcGetSeqArcInfo(int index);
extern u32   NNS_SndArcGetFileAddress(u32 a);
extern struct Node *func_02073344(struct SndTrack *o, s32 idx, s32 pri);
extern void *func_020734AC(s32 idx, void *owner);
extern u32   func_02074CD0(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void  func_020733DC(void *h);
extern void func_020733E8(struct SndTrack *o, const void *seqBase, u32 seqOffset, const void *bankData);
extern void NNS_SndHandleSetPlayerPriority(struct SndTrack *o, u8 v);
extern void NNS_SndHandlePause(struct SndTrack *o, u32 v);
extern void  func_020730B8(u32 a, u32 b);
extern void NNS_SndHandleSetSweep(struct SndTrack *o, u32 a, u32 b);
extern void func_02073A60(struct SndTrack *a);
extern void func_02073AD0(struct SndTrack *, s32);
extern s32 NNS_SndFaderGet(struct LerpObj *o);
extern void NNS_SndFaderUpdate(struct LerpObj *obj);
extern int NNS_SndFaderIsFinished(struct LerpObj *obj);
extern void func_02086028(void *p);
extern void func_02086078(void *p);
extern void func_02073AB4(struct SndTrack *o);
extern void func_02073898(struct SndTrack *x);
extern void func_020604AC(void *list, void *object);
extern u32  func_02087988(void);
extern void func_0208799C(u32);
extern void *func_02060614(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
u32 func_02075560(u32 a, u32 b);
u32 func_020755A8(u32 a, int b, int c, int d, u32 e);
u32 func_02075618(u32 a, u32 b, u32 c);
u32 func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, struct Entry *s0, u32 s1);
u32 func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, struct Entry *s0, struct SndBlock *s1, u32 s2, u32 s3);
void func_02075858(void);
void func_02075968(struct SndTrack *o);
void func_02075994(struct SndTrack *o);
void func_02075A2C(struct SndTrack *o);
void func_02075A94(struct SndTrack *obj);
void func_02075AB8(void *a, u32 v);
void func_02075B28(void *p);
struct Entry *func_02075B54(struct Table *t, int idx);
void func_02075B94(struct LerpObj *obj);
extern struct SndTrack data_0214EAC0[4];
extern const s16 data_020A5D08[];
extern u8  g_02150178[];
extern u8  g_0214EA90[];
extern u8  g_02150190[];




u32 func_02075560(u32 a, u32 b)
{
    struct Entry *p = NNS_SndArcGetSeqInfo(b);

    if (p == 0) return 0;
    return func_02075698(a, (p)->f9, (p)->f4, (p)->f8,
                         p, b);
}




u32 func_020755A8(u32 a, int b, int c, int d, u32 e)
{
    struct Entry *p = NNS_SndArcGetSeqInfo(e);

    if (p == 0) return 0;
    if (d < 0) d = p->f8;
    if (c < 0) c = p->f4;
    if (b < 0) b = p->f9;
    return func_02075698(a, (u32)b, (u32)c, (u32)d, p, e);
}




/*
 * Four-step open path, each step gated on its predecessor's result and each
 * early exit answering 0: resolve the media handle (NNS_SndArcGetSeqArcInfo), take the
 * object the handle points at and look up its record (NNS_SndArcGetFileAddress), bind the
 * record to the caller's key (func_02075B54), then hand seven values to
 * func_02075794 - the caller's first argument, three fields of the record
 * (bytes at +9 and +8, the halfword at +4) and four words parked on the stack
 * (the record itself, the looked-up object, and the caller's second and third
 * arguments).
 *
 * UNBLOCKED 2026-09-22 (wave 7, pkt_02075404).  This file was previously capped
 * at MATCH on the `matched` class: func_02075794 (the PC24 at +0x0074) has no
 * branch outside 02075618..02075698, and the callee was left DIFF at 200 vs 196
 * bytes by an earlier lane (docs/notes/func_02075794.c.txt), so it could not be
 * filed and could not attest this call.  That DIFF was a compiler question, not
 * a source one: the same body is byte-exact under `--cc ../2.0/sp2` and is now
 * src/matched/func_02075794.c, so this site resolves as `matched` and all four
 * of this file's relocations resolve.  Compiled 128 bytes, original 128 bytes.
 * This file itself stays on the project default 1.1p1; the cluster is mixed,
 * see docs/families/cluster_02074A34.h.
 */
u32 func_02075618(u32 a, u32 b, u32 c)
{
    struct SndMedia *r;
    u32 q;
    struct Entry *st;

    r = NNS_SndArcGetSeqArcInfo(b);
    if (r == 0) {
        return 0;
    }

    q = NNS_SndArcGetFileAddress(r->f0);
    if (q == 0) {
        return 0;
    }

    st = func_02075B54((struct Table *)q, c);
    if (st == 0) {
        return 0;
    }

    return func_02075794(a, st->f9, st->f4, st->f8, st, (struct SndBlock *)q, b, c);
}






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
u32 func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, struct Entry *s0, u32 s1)
{
    void *h;
    u32 v;
    struct SndBlock *blk;
    u32 slot;

    h = func_02073344((struct SndTrack *)a0, a1, a3);
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
    func_020733E8(h, (u32 *)((u8 *)blk + blk->f18), 0, (const void *)slot);
    NNS_SndHandleSetPlayerPriority((struct SndTrack *)a0, s0->f6);
    NNS_SndHandlePause((struct SndTrack *)a0, s0->f7);
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
u32 func_02075794(u32 a0, u32 a1, u32 a2, u32 a3, struct Entry *s0, struct SndBlock *s1, u32 s2, u32 s3)
{
    void *h;
    u32 v;
    u32 slot;

    h = func_02073344((struct SndTrack *)a0, a1, a3);
    if (h == 0) {
        return 0;
    }

    v = (u32)func_020734AC(a1, h);

    if (func_02074CD0(a2, 6, v, 0, &slot) != 0) {
        func_020733DC(h);
        return 0;
    }

    func_020733E8(h, (u32 *)((u8 *)s1 + s1->f18), s0->f0, (const void *)slot);
    NNS_SndHandleSetPlayerPriority((struct SndTrack *)a0, s0->f6);
    NNS_SndHandlePause((struct SndTrack *)a0, s0->f7);
    NNS_SndHandleSetSweep((struct SndTrack *)a0, s2, s3);
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
    struct SndTrack *s = data_0214EAC0;

    for (i = 0; i < 4; i++) {
        if (s->b0) {
            if (s->f11c == 0) {
                func_02075994(s);
                goto next;
            } else {
                if (s->b2 && s->f120 != 0) {
                    func_02073A60(s);
                    s->b1 = 1;
                    s->b2 = 0;
                }
                if (s->b1) {
                    NNS_SndFaderUpdate(&s->lerp);
                    a = data_020A5D08[s->f15c];
                    b = NNS_SndFaderGet(&s->lerp) >> 8;
                    c = s->f160;
                    d = data_020A5D08[b];
                    v = data_020A5D08[c] + (d + a);

                    if (v != s->f164) {
                        func_02073AD0(s, v);
                        s->f164 = v;
                    }
                    if (s->b3) {
                        if (NNS_SndFaderIsFinished(&s->lerp) != 0) {
                            func_02075994(s);
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
void func_02075968(struct SndTrack *o)
{
    if (o->unk154 != 0) {
        *o->unk154 = 0;
        o->unk154 = 0;
    }
    o->b0 = 0;
    o->b2 = 0;
    o->b1 = 0;
}





/*
 * Symbols:
 *   g_02150178  0x02150178  data
 *   g_0214EA90  0x0214EA90  data
 *
 * Two relocation sites stay wildcarded, neither for want of C:
 *   +0064  bl func_02075A2C   `label`: 0x02075A2C's only branch image-wide is
 *                             this function's own call (asm, single caller).
 *                             It is inside THIS packet; the callee is parked
 *                             (byte-correct MATCH, its own `bl 0x02075968`
 *                             site has the same defect), so filing it does not
 *                             attest this site either.
 *   +0090  ABS32 g_02150178   `literal`: the only pool word naming 0x02150178
 *                             anywhere in the image, so own-pool-only.
 * The remaining six sites resolve (`label` x20/x20/x5/x20/x20, `literal` x5).
 * Spelled with the two bitfields at +0x118 as signed 1-bit fields; an
 * unsigned field emits `lsrs r0, r0, #0x1f` where the image has `asrs`, a
 * concrete two-byte diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02075994.c \
 *       --func func_02075994 --addr 0x02075994 --arm --cc 1.1p1
 */
void func_02075994(struct SndTrack *o)
{
    u8 *p;

    func_02086028(g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0)
        func_02086028(p + 0x10c8);
    if (o->b1 != 0)
        func_02073AB4(o);
    if (o->b0 != 0)
        o->cb(o);
    func_02075A2C(o);
    func_02086078(g_02150178);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p == 0)
        return;
    func_02086078(p + 0x10c8);
}




/*
 *           branch anywhere in the image outside 02075A2C..02075A94, so
 *           `label` refuses it - and 0x02075968 is itself only 8 bytes from
 *           EXACT (two BIC destinations), see docs/notes/pkt_02075794.c.txt.
 *           (2) ABS32 g_02150190: the data address is named by exactly one
 *           pool word in the image, this function's own, so `literal` has no
 *           second occurrence either.  The other four sites resolve
 *           (func_02075A94 and func_02075AB8 as `matched`, g_0214EA90 as
 *           `literal x5`).  The body is byte-correct.
 */
void func_02075A2C(struct SndTrack *o)
{
    u8 *p;

    if (o->b0 == 0) return;
    func_02075A94(o);
    o->f170(o);
    func_02075AB8(g_02150190, (u32)o);
    p = *(u8 **)(g_0214EA90 + 4);
    if (p != 0) func_02075AB8(p + 0x10e0, (u32)o);
    func_02075968(o);
}




void func_02075A94(struct SndTrack *obj)
{
    if (obj->ref_count != 0) {
        if (--obj->ref_count == 0) {
            func_02073898(obj);
        }
    }
}




/*
 * The unlink walk holds the interrupt state in the lowest callee-saved
 * register and the next link in r6, so the state survives the two calls in
 * the body; declaring `n` inside the loop (rather than hoisting it) is what
 * keeps r6 out of the prologue's push.
 */
void func_02075AB8(void *a, u32 v)
{
    u32 state = func_02087988();
    void *p = func_02060614(a, 0);

    while (p != 0) {
        void *n = func_02060614(a, p);

        if (((struct DListElem *)p)->f8 == v) {
            func_020605B4(a, p);
            func_02075B28(p);
        }
        p = n;
    }
    func_0208799C(state);
}



void func_02075B28(void *p)
{
    u32 state = func_02087988();
    func_020604AC(g_0214EA90 + 0xc, p);
    func_0208799C(state);
}



/*
 * Signed compare against zero for the negative index (`movlt`/`bxlt`) but an
 *  * unsigned `>=` for the bound (`movhs`/`bxhs`), which is what an `int` index
 *  * compared against a `u32` count gives; the -1 element test is the
 *  * R_ARM_ABS32-free third guard the tail ends on. No relocations at all.
 */
struct Entry *func_02075B54(struct Table *t, int idx)
{
    struct Entry *e;

    if (idx < 0) return 0;
    if (idx >= t->count) return 0;
    e = &t->arr[idx];
    if (e->f0 == -1) return 0;
    return e;
}




void func_02075B94(struct LerpObj *obj)
{
    obj->target = 0;
    obj->start = 0;
    obj->duration = 0;
    obj->step = 0;
}
