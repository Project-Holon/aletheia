/*
 * file:     nns_snd_player_11.c
 * unit:     yes
 * function: func_0207312C, func_020731E0, func_02073344, func_020733DC, func_020733E8, func_02073438, func_02073484, func_020734AC, func_02073500, func_02073548, func_02073598, func_020735EC, func_02073624, func_0207368C, func_02073710, func_02073760
 * address:  0x0207312C
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
 *   g_0214E00C  0x0214E00C  data
 *   g_0214E018  0x0214E018  data
 *   g_0214E024  0x0214E024  data
 *   g_0214E464  0x0214E464  data
 *   func_02060468  0x02060468  arm
 *   func_020604AC  0x020604AC  arm
 *   g_020A5D08  0x020A5D08  data
 *   func_0208A054  0x0208A054  arm
 *   func_02060614  0x02060614  arm
 *   func_02089D6C  0x02089D6C  arm
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   func_020893D0  0x020893D0  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 *   func_02089378  0x02089378  arm
 *   SND_PrepareSeq                  0x02089350  arm
 *   SND_SetTrackAllocatableChannel  0x0208948C  arm
 *   SND_GetCurrentCommandTag        0x02089D40  arm
 *   func_02075BAC  0x02075BAC  arm
 *   func_02089398    0x02089398  arm
 *   func_020605B4  0x020605B4  arm
 *   func_02074770  0x02074770  arm
 *   func_02060550  0x02060550  arm
 *   func_02089330    0x02089330  arm
 */
struct DList;
struct LerpObj;
struct Obj;
struct Voice;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed char s8;

typedef signed short s16;

struct Env { s32 f00; s32 f04; s32 f08; s32 f0c; };

struct Slot { u8 p00[8]; u16 h08; u8 p0a[2]; u8 list[0x0c]; u32 f18; u32 f1c; u8 b20; u8 p21[3]; };

struct Owner { struct Voice *f0; };

struct Voice {
    struct Owner *f00;
    struct Slot *f04;
    struct Voice *f08;
    struct Voice *f0c;
    u32 f10;
    u8  p14[0x1c - 0x14];
    struct Env env;
    u8  b2c;
    u8  b2d;
    u8  b2e;
    u8  b2f;
    u32 f30;
    u16 h34;
    u8  p36[0x3c - 0x36];
    u8  b3c;
    u8  b3d;
    s16 h3e;
    u8  b40;
    u8  b41;
    u8  p42[0x44 - 0x42];
};

extern void *func_02060614(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_020604AC(void *list, void *node);
extern void func_02060468(int p0, int p1);
extern void func_02060550(volatile struct DList *list, void *before, void *elem);
extern void func_02074770(struct Voice *o);
extern void func_02074758(void **a0);
extern void func_02072EA8(u32 * volatile *pp);
extern u32 func_0208A054(void);
extern int func_02089D6C(u32 tag);
extern void NNS_SndFaderUpdate(struct LerpObj *obj);
extern s32 NNS_SndFaderGet(struct Obj *o);
extern int NNS_SndFaderIsFinished(struct LerpObj *obj);
extern int func_02075B94(void *a, int b);
extern int func_02075BAC(void *a, int b, int c);
extern void func_020893D0(u32 player, int vol);
extern void func_02089378(u32 player);
extern void func_02089330(int playerNo);
extern void func_02089398(int playerNo, int flag);
extern void SND_PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, const void *bankData);
extern void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
extern u32  SND_GetCurrentCommandTag(void);
void func_0207312C(void);
void func_020731E0(void);
struct Voice *func_02073344(struct Owner *o, s32 idx, s32 pri);
void func_020733DC(struct Voice *h);
void func_020733E8(struct Voice *o, const void *seqBase, u32 seqOffset, const void *bankData);
void func_02073438(struct Voice *p, int fadeFrame);
void func_02073484(struct Voice *p, u8 v);
void *func_020734AC(s32 idx, struct Voice *owner);
int func_02073500(struct Voice *a0);
void func_02073548(void *list, struct Voice *obj);
void func_02073598(struct Voice *obj);
void func_020735EC(struct Voice *p);
struct Voice *func_02073624(s32 pri);
void func_0207368C(struct Voice *v);
void func_02073710(struct Voice *a);
void func_02073760(struct Voice *o, u32 v);
extern char g_0214E00C[];
extern char g_0214E018[];
extern struct Voice g_0214E024[];
extern struct Slot g_0214E464[];
extern s16 g_020A5D08[];






/*
 * Pinned ../2.0/sp2 on the documented "kept constants" tell.  The image
 * materialises the allocator's element size TWICE, `mov r1, #0x14`
 * (`14 10 a0 e3`) at 0x02073134 and again at 0x02073140; 1.1p1 -O4,p CSEs the
 * pair into one hoisted `mov r4, #0x14` plus two `mov r1, r4`, which costs a
 * further callee-saved register and turns the original's
 * `push {r4, r5, r6, r7, r8, sb, sl, lr}` (`f0 47 2d e9`) into a ten-register
 * `push {r3, r4, ..., fp, lr}`, 180 bytes with 128 concrete bytes out.  The
 * indexed-subscript spelling of the two loops additionally leaves an `mla`
 * cursor under both front ends; the pointer-cursor form above is what
 * reproduces the original's `add r7, r7, #0x44` / `add sb, sb, #0x24`
 * strength reduction.  Under the pin the same C is 180 bytes, 0 concrete
 * mismatches.
 *
 * Note c->b3c is the loop INDEX, not zero: the `strb r6, [r7, #0x3c]` at
 * 0x02073164 stores the counter before the `add r6, r6, #1` at 0x0207316C,
 * while c->b2c takes the separate hoisted zero in r5.  Writing both as 0
 * leaves exactly one byte out at +0x38.
 *
 * Blocked at MATCH, evidence class: `literal` unavailable for the ABS32 site
 * at +0xAC.  The word 0x0214E024 appears in exactly one pool image-wide, my
 * own pool_020731D8 at 0x020731D8 (the three grep hits in asm/arm9/src are
 * that one address seen through three overlapping listings), so it has no
 * witness outside 0x0207312C..0x020731E0 and cannot be attested.  Every other
 * site resolves: four `label`, three `literal`.
 */
void func_0207312C(void)
{
    s32 i;
    struct Voice *c;
    struct Slot *s;

    func_02060468((int)g_0214E018, 0x14);
    func_02060468((int)g_0214E00C, 0x14);

    for (i = 0, c = g_0214E024; i < 0x10; i++, c++) {
        c->b2c = 0;
        c->b3c = (u8)i;
        func_020604AC(g_0214E00C, c);
    }

    for (i = 0, s = g_0214E464; i < 0x20; i++, s++) {
        func_02060468((int)s, 0xc);
        func_02060468((int)(&s->list), 0);
        s->b20 = 0x7f;
        s->f18 = 1;
        s->f1c = 0;
    }
}





/*
 * Byte-correct: 356 bytes, 0 concrete mismatches, under the DEFAULT 1.1p1
 * -O4,p.  No compiler pin taken or needed.
 *
 * PROMOTED TO EXACT, 2026-09-21 (unblock lane), with NO change to the C.
 * It was parked at MATCH because the two PC24 sites at +0x04 (func_0208A054)
 * and +0x13C (func_02089378) had no `label` witness: both targets are defined
 * and labelled in asm/arm9/src/028_02087E60.s, but the only `bl` reaching
 * either one anywhere in the image (arm9 and all of asm/overlays) was inside
 * this function's own 356 bytes -- the `bl` at 0x020731E4 and the one at
 * 0x0207331C respectively -- so `label` refused both for want of an OUTSIDE
 * branch and a split could not help.  There is no second caller to find.
 * Both callees were therefore written and filed directly instead:
 * src/matched/func_02089378.c (32 bytes, shard pkt_02089378) and
 * src/matched/func_0208A054.c (40 bytes, shard pkt_0208A054), each EXACT on
 * its own evidence.  Both sites now resolve `matched x1` and all 13 of this
 * file's relocations are attested.
 *
 * Levers that mattered, in the order they paid (all under 1.1p1):
 *  - The three sound-curve indices are PLAIN s16 subscripts.  Spelling any of
 *    them with an arithmetic round-trip emits a signed-division fixup
 *    (`add r0,r0,r0,lsr #31` / `asr r0,r0,#1`) that the image does not have.
 *  - The guard at 0x02073250 is `(mask & (1 << v->b3c)) == 0`, not `!= 0`:
 *    the image's `bne 0x2073264` at 0x02073254 skips the func_0207368C arm.
 *  - Declaration order is the whole register allocation, and it took three
 *    passes: 57 bytes out with `v` first, 40 with `next` moved below `tbl`,
 *    12 once `tbl` is declared BEFORE `v` (tbl->r5, v->r6, next->r7).
 *    `tbl` and `lo` must also be ASSIGNED after the early-return guard, not
 *    at their declarations, or they hoist above it.
 *  - The volume sum is `e + (c + (b + a))` with the curve read bound to its
 *    own local `e`: the accumulator is the second operand (see
 *    docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *    Binding the SUM to a local instead forces it before the NNS_SndFaderGet
 *    call and costs 30+ bytes.
 *  - The last 8 bytes were the ISSUE ORDER of the three curve reads alone:
 *    b41, then b40, then f04->b20.  Any other order permutes sl/sb/r8.
 */
void func_020731E0(void)
{
    u32 mask;
    s16 *tbl;
    s32 lo;
    struct Voice *v;
    struct Voice *next;
    s32 vol;

    mask = func_0208A054();
    v = func_02060614((struct DList *)g_0214E018, 0);
    if (v == 0) {
        return;
    }
    lo = -0x8000;
    tbl = g_020A5D08;

    do {
        next = func_02060614((struct DList *)g_0214E018, v);
        if (v->b2d == 0) {
            if (func_02089D6C(v->f30) != 0) {
                v->b2d = 1;
            }
        }
        if (v->b2d != 0 && (mask & (1 << v->b3c)) == 0) {
            func_0207368C(v);
        } else {
            s32 a, b, c;
            NNS_SndFaderUpdate((struct LerpObj *)(&v->env));
            a = tbl[v->b41];
            b = tbl[v->b40];
            c = tbl[v->f04->b20];
            {
                s32 e = tbl[NNS_SndFaderGet((struct Obj *)(&v->env)) >> 8];
                vol = e + (c + (b + a));
            }
            if (vol < lo) {
                vol = lo;
            } else if (vol > 0x7fff) {
                vol = 0x7fff;
            }
            if (vol != v->h3e) {
                func_020893D0(v->b3c, vol);
                v->h3e = (s16)vol;
            }
            if (v->b2c == 2 && NNS_SndFaderIsFinished((struct LerpObj *)(&v->env)) != 0) {
                func_020735EC(v);
            }
            if (v->b2f != 0) {
                func_02089378(v->b3c);
                v->b2f = 0;
            }
        }
        v = next;
    } while (next != 0);
}








/*
 * Pinned ../2.0/sp2 on the documented "kept constants" tell: under 1.1p1 -O4,p
 * the three `return 0` sites and the null argument of func_02060614 CSE into a
 * single hoisted `mov r7, #0`, giving 156 bytes against the original's 152 and
 * permuting the whole callee-saved allocation (obj r4->r6, slot r6->r4,
 * pri r7->r5).  The image instead materialises each zero fresh
 * (`mov r1, #0` at 0x0207337C-4, `moveq r0, #0` at 0x0207338C, 0x0207339C,
 * 0x020733B4).  Four 1.1p1 spellings measured (separate node local, decl
 * reorder, early read of o->f0, explicit (void *)0 cast) all hoist the zero.
 * Under the pin the same C is 152 bytes, 0 concrete mismatches.
 *
 * PROMOTED TO EXACT, 2026-09-21, with NO change to the C.  It was parked at
 * MATCH because the PC24 site at +0x68 had no witness: func_02073624 has
 * exactly one branch anywhere in the image (the `bl` at 0x020733AC inside this
 * very function), so `label` refused it.  0x02073624 is now filed as
 * src/matched/func_02073624.c (104 bytes, shard pkt_02073624, same ../2.0/sp2
 * kept-constants pin), and the site resolves `matched x1`.  All six
 * relocations are attested.
 */
struct Voice *func_02073344(struct Owner *o, s32 idx, s32 pri)
{
    struct Slot *s = &g_0214E464[idx];
    struct Voice *e = o->f0;

    if (e != 0) {
        func_02072EA8((u32 * volatile*)o);
    }
    if (s->h08 >= s->f18) {
        e = func_02060614((struct DList *)s, 0);
        if (e == 0) {
            return 0;
        }
        if (pri < e->b3d) {
            return 0;
        }
        func_020735EC(e);
    }
    e = func_02073624(pri);
    if (e == 0) {
        return 0;
    }
    func_02073548(s, e);
    e->f00 = o;
    o->f0 = e;
    return e;
}






void func_020733DC(struct Voice *h){ func_0207368C(h); }







/*
 * Start a sequence on a voice (the NitroSystem sound-player layer over the
 * TwlSDK SND driver): prepare the sequence on the voice's player number,
 * restrict its allocatable channels when the owning player object has a
 * channel mask at +0x1c, reset the voice, record the current command tag and
 * mark it prepared/playing.
 *
 * The 2-byte residue of docs/notes/pkt_020733E8.c.txt (the guard load in r2
 * where the compile used r0) was an ARITY, as that note suspected, but on
 * both callees at once: SND_PrepareSeq takes FOUR arguments (playerNo,
 * seqBase, seqOffset, bankData), so this function forwards its own r1..r3
 * untouched; and SND_SetTrackAllocatableChannel takes THREE (playerNo,
 * trackBitMask, chBitMask), so the guard value in r2 is the channel mask
 * being passed on.  The callers func_02075698 / func_02075794 already pass
 * four arguments.  The pin is ../2.0/sp2 (1.1p1: 9 bytes out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020733E8.c \
 *       --func func_020733E8 --addr 0x020733E8 --arm --cc ../2.0/sp2
 */
void func_020733E8(struct Voice *o, const void *seqBase, u32 seqOffset, const void *bankData)
{
    struct Slot *s = o->f04;
    SND_PrepareSeq(o->b3c, seqBase, seqOffset, bankData);
    if (s->f1c != 0) {
        SND_SetTrackAllocatableChannel(o->b3c, 0xFFFF, s->f1c);
    }
    func_02073500(o);
    o->f30 = SND_GetCurrentCommandTag();
    o->b2f = 1;
    o->b2c = 1;
}







/*
 * Stop a voice's sequence with an optional fade (the NitroSystem sound-player
 * stop shape): nothing to do for a null or idle voice; a zero fade stops at
 * once through func_020735EC; otherwise start the embedded fader at +0x1c
 * toward 0 over `fadeFrame` frames, drop the voice's priority to 0 and mark it
 * releasing (state 2).
 *
 * The four-byte gap in docs/notes/func_02073438.c.txt (the image copies the
 * second argument into r2 before the guard) was the ARITY OF THE FADER CALL:
 * func_02075BAC takes three arguments (fader, target, frames) -- its own body
 * saves r0, r1 AND r2 and stores all three -- so fadeFrame is moved into r2
 * early and passed on.  That note tried forwarding n in place of the 0 and a
 * third parameter on THIS function, not the third argument of the callee.
 * The pin is ../2.0/sp2 (1.1p1 is 80 bytes with a wide push).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02073438.c \
 *       --func func_02073438 --addr 0x02073438 --arm --cc ../2.0/sp2
 */
void func_02073438(struct Voice *p, int fadeFrame)
{
    if (p == 0) return;
    if (p->b2c == 0) return;
    if (fadeFrame == 0) {
        func_020735EC(p);
        return;
    }
    func_02075BAC(&p->env, 0, fadeFrame);
    func_02073760(p, 0);
    p->b2c = 2;
}





/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * Pauses the sequence behind the object when the new value differs from the
 * cached one at +0x2E, then caches it.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02073484.c \
 *       --func func_02073484 --addr 0x02073484 --cc 1.1p1 --arm
 */
void func_02073484(struct Voice *p, u8 v)
{
    if (p != 0 && v != p->b2e) {
        func_02089398(p->b3c, v);
        p->b2e = v;
    }
}








/*
 * Takes the head node off the free list embedded at +0x0c of slot `idx` of the
 * g_0214E464 table, binds it to `owner` in both directions, drains the owner's
 * deferred requests through func_02074770, and returns the owner back.
 * Returns 0 when the free list is empty.
 *
 * THE TABLE STRIDE IS 0x24 AND THE LIST IS EMBEDDED AT +0x0c.  Both are fixed
 * by the head: `mov r2, #0x24 / mla r5, r0, r2, r3` is an indexed subscript on
 * a 0x24-stride array (the same table and stride matched func_0207312C and
 * func_02073344 already use), and the list argument is `add r0, r5, #0xc`, the
 * ADDRESS of an embedded object, not a loaded pointer.  Declaring the +0x0c
 * field as a `void *` and passing it emits an extra `ldr` and loses the add.
 *
 * THE LAST TWO STATEMENTS RE-READ n->f08 RATHER THAN REUSING `owner`.  The
 * image loads `ldr r0, [r4, #8]` twice, once for func_02074770's argument and
 * once for the return value, even though the value was just stored there from
 * r4's own `str r4, [r6, #8]`.  Writing `func_02074770(owner); return owner;`
 * folds both loads away and is 8 bytes short.  The re-read is what the C above
 * spells literally, and it is also why the two stores are written in the order
 * f0c-then-f08: the compiler does not reorder them and the second store is what
 * the following load depends on.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 * docs/families/cluster_020726D0.h).  Under dsi/1.1p1 -O4,p the slot base and
 * the owner are both live across the func_02060614 call, so 1.1p1 hoists them
 * into a SIXTH and SEVENTH callee-saved register: the frame becomes
 * `push {r3, r4, r5, r6, r7, lr}` against the image's `push {r4, r5, r6, lr}`,
 * `add r0, r5, #0xc` becomes `add r0, r6, #0xc` and the owner moves from r6 to
 * r7 -- every byte from +0x20 on shifts.  The image keeps the slot base in r5
 * and the owner in r6 and materialises what it needs at each use.  Under the
 * pin the same C is 84 bytes, 0 concrete mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020734AC.c \
 *       --func func_020734AC --addr 0x020734AC --cc ../2.0/sp2 --arm
 */
void *func_020734AC(s32 idx, struct Voice *owner)
{
    struct Slot *s = &g_0214E464[idx];
    struct Voice *n = func_02060614((struct DList *)s->list, 0);
    if (n == 0) return 0;
    func_020605B4((volatile struct DList *)s->list, n);
    n->f0c = owner;
    owner->f08 = n;
    func_02074770(n->f08);
    return n->f08;
}








int func_02073500(struct Voice *a0)
{
    int t0, t1;
    a0->b2e = 0;
    a0->b2d = 0;
    a0->b2f = 0;
    a0->h34 = 0;
    a0->h3e = 0;
    a0->b40 = 0x7f;
    a0->b41 = 0x7f;
    t0 = func_02075B94(&a0->env, 0x7f);
    t1 = func_02075BAC(&a0->env, 0x7f00, 1);
    return t1;
}








void func_02073548(void *list, struct Voice *obj)
{
    struct Voice *curr = (struct Voice *)func_02060614(list, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = (struct Voice *)func_02060614(list, curr);
    }
    func_02060550(list, curr, obj);
    obj->f04 = list;
}






/*
 * Priority-ordered insert into the g_0214E018 list.  Walks the list with the
 * generic iterator func_02060614 (a null cursor asks for the head, a node asks
 * for its successor), stops at the first node whose b3d priority byte is
 * strictly greater than the new object's, and inserts before it with
 * func_02060550.  Running off the end leaves `curr` null, which is
 * func_02060550's "append" case, so one loop serves both.
 *
 * TWO INDEPENDENT ERRORS were fixed to close this, and only the first is
 * interesting:
 *
 * 1. THE LIST OBJECT IS AN ARRAY, NOT A POINTER.  The parked version declared
 *    `extern void *g_0214E018;` and passed `g_0214E018`, so every call site
 *    emitted an extra `ldr r0, [r0]` to LOAD the pointer out of the object.
 *    The image has no such load: it hands the ADDRESS 0x0214E018 straight to
 *    the callee.  `extern char g_0214E018[];` is the spelling every matched
 *    sibling in this range already uses (func_0207312C, func_020731E0), and
 *    this file disagreeing with them was the whole of the 47-byte residue's
 *    tail.  Fixing it alone took the file to 8 bytes out, all in the head.
 *
 * 2. PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 *    docs/families/cluster_020726D0.h).  With the declaration fixed, dsi/1.1p1
 *    still hoists the g_0214E018 pool word into callee-saved r4 BEFORE the
 *    `mov r5, r0` (giving `ldr r4,[pc,#0x44] / mov r5,r0 / mov r0,r4`) and
 *    serves both the entry call and the loop call from it.  The image instead
 *    materialises the entry call's argument from its OWN pool word
 *    (`ldr r0,[pc,#0x40]` at 0x020735A0) and only loads r4 at 0x020735B4,
 *    AFTER the early-exit test -- i.e. it does not pay for the loop's base on
 *    the path that never reaches the loop.  Two distinct pool entries for one
 *    symbol, the cluster's signature.  Under the pin the same C is 84 bytes,
 *    0 concrete mismatches.
 *
 * The comparison is UNSIGNED (`blo` at 0x020735C4), so b3d is u8 and the test
 * is `obj->b3d < curr->b3d`; a signed spelling emits `blt`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02073598.c \
 *       --func func_02073598 --addr 0x02073598 --cc ../2.0/sp2 --arm
 */
void func_02073598(struct Voice *obj)
{
    struct Voice *curr = func_02060614((struct DList *)g_0214E018, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = func_02060614((struct DList *)g_0214E018, curr);
    }
    func_02060550((volatile struct DList *)g_0214E018, curr, obj);
}





/*
 * Tears the player down: in state 2 first sets the volume to -723, then stops
 * the sequence and calls the state machine again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020735EC.c \
 *       --func func_020735EC --addr 0x020735EC --cc 1.1p1 --arm
 */
void func_020735EC(struct Voice *p)
{
    if (p->b2c == 2) {
        func_020893D0(p->b3c, -723);
    }
    func_02089330(p->b3c);
    func_0207368C(p);
}





/*
 * Voice allocator: take the head of the free list at 0x0214E00C; if it is
 * empty, take the head of the ACTIVE list at 0x0214E018 instead and steal it,
 * but only if the caller's priority is at least the victim's, else return 0.
 * Move the chosen node onto the free list, stamp the priority and attach it.
 *
 * b3d is UNSIGNED (`u8`).  The image loads it with `ldrb r1, [r4, #0x3d]` at
 * 0x02073650; declared `s8` the compiler emits `ldrsb`, 3 concrete bytes out at
 * the same 104 and otherwise identical.  The compare is still signed (`movlt`)
 * because the priority parameter is s32.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md), which
 * docs/notes/pkt_02073624.c.txt predicted at this address.  The two list-walk
 * calls each take a literal 0 as their second argument and the image
 * materialises it FRESH at both, `mov r1, #0` at 0x02073630 (`00 10 a0 e3`) and
 * again at 0x02073644, and reuses it for neither the `movlt r0, #0` early exit
 * at 0x02073658 nor anything else.  1.1p1 -O4,p CSEs all three into a single
 * hoisted `mov r4, #0` above the first call, then spends `mov r1, r4` at each
 * call site and `movlt r0, r4` at the exit; that costs a fourth callee-saved
 * register and turns the original's `push {r3, r4, r5, lr}` (`38 40 2d e9`)
 * into `push {r4, r5, r6, lr}` with the node in r5 and the priority in r6,
 * 108 bytes against the original's 104 and 96 concrete bytes out.  Under the
 * pin the same C is 104 bytes, 0 mismatches.
 *
 * Filing this address unblocks src/pending/func_02073344.c, whose PC24 site at
 * +0x68 had no witness for this function.
 */
struct Voice *func_02073624(s32 pri)
{
    struct Voice *v;

    v = func_02060614((struct DList *)g_0214E00C, 0);
    if (v == 0) {
        v = func_02060614((struct DList *)g_0214E018, 0);
        if (pri < v->b3d) {
            return 0;
        }
        func_020735EC(v);
    }
    func_020605B4((volatile struct DList *)g_0214E00C, v);
    v->b3d = (u8)pri;
    func_02073598(v);
    return v;
}





/*
 * Voice teardown, the counterpart of func_02073624: clear the back-pointer in
 * the owner, unlink from the f04 sub-list, unlink from the f08 sub-list if it
 * has one, then move the node from the active list at 0x0214E018 back to the
 * free list at 0x0214E00C and clear the state byte.
 *
 * The lever, and the whole reason docs/notes/pkt_02073624.c.txt left this one
 * open at 84 bytes: the inner func_020604AC call's second argument is
 * `v->f08`, NOT `v`.  The image's guard load `ldr r1, [r4, #8]` at 0x020736C0
 * IS the argument register -- the `cmp r1, #0` / `beq` pair tests the value in
 * place and the call site then only has to compute r0.  Passing `v` costs a
 * fresh `mov r1, r4` and 4 bytes, and forces the guard load into r0.  Every
 * other call in the body does pass `v`, which is what makes the odd one out
 * easy to miss.  The sub-list base is `(char *)v->f04 + 0xc`, read into r5
 * before the FIRST func_020605B4 call and reused, not re-read.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md), the same
 * one as this packet's func_02073624.c.  The image materialises each zero
 * fresh: `movne r0, #0` at 0x0207369C for the owner pair, `mov r0, #0` at
 * 0x020736B8 for f04, `mov r1, #0` at 0x020736D8 for the f08 pair and
 * `mov r0, #0` at 0x020736FC for b2c.  1.1p1 -O4,p CSEs all four into one
 * hoisted `mov r5, #0`, which costs a further callee-saved register and turns
 * the original's `push {r3, r4, r5, lr}` (`38 40 2d e9`) into
 * `push {r4, r5, r6, lr}` with the sub-list base displaced from r5 to r6; the
 * same 132 bytes with 40 concrete bytes out.  Under the pin the same C is
 * 132 bytes, 0 mismatches.
 */
void func_0207368C(struct Voice *v)
{
    struct Slot *s;

    if (v->f00 != 0) {
        v->f00->f0 = 0;
        v->f00 = 0;
    }
    s = v->f04;
    func_020605B4((volatile struct DList *)s, v);
    v->f04 = 0;
    if (v->f08 != 0) {
        func_020604AC((char *)s + 0xc, v->f08);
        v->f08->f0c = 0;
        v->f08 = 0;
    }
    func_020605B4((volatile struct DList *)g_0214E018, v);
    func_020604AC(g_0214E00C, v);
    v->b2c = 0;
}



void func_02073710(struct Voice *a)
{
    if (a->f08 == 0) return;
    func_02074758((void **)a->f08);
    if (a->f0c != 0) { a->f0c->f08 = 0; return; }
    func_020605B4((volatile struct DList *)(g_0214E464[a->f10].list), a);
}


void func_02073760(struct Voice *o, u32 v)
{
    struct Slot *q = o->f04;
    if (q != 0) { func_020605B4((void *)q, o); o->f04 = 0; }
    func_020605B4((volatile struct DList *)g_0214E018, o);
    o->b3d = (u8)v;
    if (q != 0) func_02073548((void *)q, o);
    func_02073598(o);
}
