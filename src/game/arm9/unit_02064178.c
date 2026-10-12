/*
 * file:     unit_02064178.c
 * unit:     yes
 * function: func_02064178, func_0206419C, func_0206428C, func_020642C8, func_0206434C, func_02064364, func_02064384, func_020643A4, func_020643C4
 * address:  0x02064178
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
 *   func_02064140  0x02064140  arm
 *   func_02066ABC  0x02066ABC  arm
 *   func_02062F38  0x02062F38  arm
 *   func_0206434C  0x0206434C  arm
 *   func_02066890  0x02066890  arm
 *   func_02062FF0   0x02062FF0  arm
 *   func_02062D4C  0x02062D4C  arm
 *   func_02062F00  0x02062F00  arm
 *   func_02062F90  0x02062F90  arm
 */

#include "cell_anim_types.h"

struct O02064140;
struct Obj02064100;
struct NNSG2dAnimController;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

struct CellAnimRec {
    u16 f0;
    u16 f2;
    union {
        int   w;
        short h[2];
    } f4;
    int f8;
    short fC;
    short fE;
};

struct CellDataSub {
    int f0;
    u8 *f4;
};

struct CellDataBank {
    u8 pad00[0xC];
    struct CellDataSub *fC;
};

struct MultiCellAnim {
    u8 pad00[0x14];
    u32 unk14;
};

extern void func_02064140(struct O02064140 *o, u32 a);
extern void *func_02062D40(struct CellAnim *anim);
extern void *func_0206285C(struct CellDataBank *bank, u32 idx);
extern void func_020640DC(char *p, int a, int b);
extern void func_02064120(char *p, int a, int b);
extern void func_02064100(struct Obj02064100 *obj, u16 val);
extern int func_02066ABC(int a0, int a1, int a2);
extern int func_02062F38(int a0);
extern void func_0206434C(char *self, int v);
extern void func_02066890(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02062FF0(struct CellAnim *anim, void *bank);
extern s32  func_02062D4C(struct CellAnim *anim, s32 frames);
extern int func_02062F00(void *s, u32 i);
extern void func_02062F90(struct NNSG2dAnimController *pAnimCtrl);
void func_02064178(struct CellAnim *o, u32 a);
void func_0206419C(struct CellAnim *self);
void func_0206428C(struct CellAnim *self, int a1, struct CellDataBank *c);
void func_020642C8(struct CellAnim *self, int a1, struct CellDataBank *c, int d, int e, int f, int g, int h, int i, int j);
void ENV_SetResourceSet(void *anim, void *seq);
void func_02064364(struct CellAnim *anim, s32 frames);
void func_02064384(struct CellAnim *anim, u32 i);
void func_020643A4(struct CellAnim *anim);
void func_020643C4(struct MultiCellAnim *mca, u32 value);




/*
 * Opens one 0x28-byte group header of the two-level cell-array shape: clears
 * the header's first word, stores the cell pointer at +0x04, sets the "in use"
 * word at +0x08 and tail-calls func_02064140 on the SRT block at +0x0c.
 * func_02064754 drives it once per group.
 *
 * PIN ../2.0/sp2: the tail-call scheduling form of the "kept constants" tell.
 * The image materialises the zero FIRST and stores it first -- `mov r2,#0` at
 * 0x02064178 / `str r2,[r0]` / `str r1,[r0,#4]` / `mov r1,#1` / `str r1,[r0,#8]`
 * -- and only then loads the tail-call pool word (`ldr ip,[pc,#4]` at
 * 0x0206418C).  1.1p1 -O4,p hoists that pool load ABOVE the three stores and
 * posts the zero store after them, which lets it drop one instruction: 32
 * bytes against the original's 36, 23 concrete out.  An earlier lane measured
 * the array spelling `((u32 *)o)[0] = 0; ...`, the named-field spelling and a
 * `(u8 *)o + 0xc` call argument and found all three byte-identical to each
 * other, i.e. the scheduling is not source-driven
 * (docs/notes/pkt_02064178.c.txt).  Under the pin this SAME C is 36 bytes, 0
 * mismatches.
 */
void func_02064178(struct CellAnim *o, u32 a)
{
    o->f00 = 0;
    o->hdr = (struct CellAnimHdr *)a;
    o->f08 = 1;
    func_02064140((struct O02064140 *)&o->active, 1);
}




void func_0206419C(struct CellAnim *self)
{
    struct CellAnimRec *p;
    struct CellDataBank *o;
    int kind;
    struct CellDataSub *q;
    int r;
    int r2;

    if (self->hdr->count == 0)
        return;

    func_02062D40(self);
    p = func_02062D40(self);

    o = self->dataBank;
    self->f30 = (int)func_0206285C(o, p->f0);

    kind = self->bank->unk04 & 0xff;

    func_02064140((struct O02064140 *)self->sub3c, 1);

    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC((char *)self->sub3c, p->f4.h[0], p->f4.h[1]);
        break;
    default:
        func_02064120((char *)self->sub3c, p->f4.w, p->f8);
        func_02064100((struct Obj02064100 *)self->sub3c, p->f2);
        func_020640DC((char *)self->sub3c, p->fC, p->fE);
        break;
    }

    q = o->fC;
    r = !!q;
    if (r == 0) return;

    if (*(volatile int *)&self->f38 != -1) r2 = 1; else r2 = 0;
    if (r2 == 0) return;

    {
        int *t = (int *)(q->f4 + p->f0 * 8);
        func_02066ABC(self->f38, t[0], t[1]);
    }
}



/*
 * Binds one cell-bank row to an animation object: stores the row pointer at
 * +0x34, writes the "no cell bound" sentinel -1 at +0x38, opens the SRT block
 * at +0x3c through func_02064140 and finishes with the object's own two-call
 * tail.  The sibling of func_020642C8, which does the same fixups after an
 * eight-argument forward.
 *
 * PIN ../2.0/sp2: the "kept constants" tell in its allocation form.  The image
 * materialises the sentinel into r2 and stores it SECOND, between the +0x34
 * store and the `add r0, r5, #0x3c` argument setup -- `str r2,[r5,#0x34]` at
 * 0x02064298 / `mvn r2,#0` at 0x0206429C / `add r0,r5,#0x3c` / `mov r1,#1` /
 * `str r2,[r5,#0x38]` at 0x020642A8.  1.1p1 -O4,p allocates the -1 into r3
 * instead and sinks its store below the whole argument setup, giving
 * `mvn r3,#0` / `add r0,r5,#0x3c` / `mov r1,#1` / `str r2,[r5,#0x34]` /
 * `str r3,[r5,#0x38]`: the same 60 bytes, 17 concrete out.  An earlier lane
 * measured `0xffffffffu`, `(u32)-1` and a named `u32` local for the sentinel
 * and every one allocates r3 the same way (docs/notes/pkt_02064178.c.txt).
 * Under the pin this SAME C is 60 bytes, 0 mismatches, all three sites label.
 */
void func_0206428C(struct CellAnim *self, int a1, struct CellDataBank *c)
{
    self->dataBank = c;
    self->f38 = -1;
    func_02064140((struct O02064140 *)self->sub3c, 1);
    func_02062F38((int)self);
    func_0206434C((char *)self, a1);
}



/*
 * The eight-argument forwarder into func_02066890 (four in registers, four
 * on the stack at [sp]..[sp,#0xc], re-read from the caller's own stacked
 * arguments at [sp,#0x28]..[sp,#0x3c]), followed by the object fixups.
 *
 * Two levers, both needed, both `volatile`:
 *   1. The image stores self+0x38 TWICE, at 0x02064318 and again at
 *      0x02064328, with the self+0x34 store between them.  Written as plain
 *      assignments mwcc drops the first and the function is 128 bytes
 *      against 132, 64 concrete out.  Marking that field `volatile` is what
 *      keeps both stores.
 *   2. With only (1), the self+0x34 store sinks below the `add r0, r7, #0x3c`
 *      / `mov r1, #1` argument setup for func_02064140 (11 concrete bytes at
 *      the right size).  Marking that field `volatile` too pins it above
 *      them, matching 0x0206431C.
 * Both are plain field stores in the real source; `volatile` here is standing
 * in for whatever ordering the original had, and is the spelling that
 * reproduces the bytes.
 *
 * Byte-correct: 132 bytes, 0 concrete mismatches, under the DEFAULT 1.1p1
 * (no pin needed; ../2.0/sp2 also gives 132/0 with the same C).
 *
 * Blocked on: `label`.  Three of the four PC24 sites resolve, but func_02066890
 * has no branch anywhere in the image outside this function's own `bl` at
 * 0x02064314, and no matched entry, so the site stays wildcarded and the file
 * caps at MATCH.  It promotes as soon as 0x02066890 or a second caller of it
 * is filed.
 */
void func_020642C8(struct CellAnim *self, int a1, struct CellDataBank *c, int d,
                   int e, int f, int g, int h, int i, int j)
{
    func_02066890(d, e, f, g, c->fC->f0, h, i, j);
    *(volatile int *)&self->f38 = d;
    *(struct CellDataBank *volatile *)&self->dataBank = c;
    *(volatile int *)&self->f38 = d;
    func_02064140((struct O02064140 *)self->sub3c, 1);
    func_02062F38((int)self);
    func_0206434C((char *)self, a1);
}




void ENV_SetResourceSet(void *anim, void *seq)
{
    func_02062FF0(anim, seq);
    func_0206419C(anim);
}




/*
 * Advances one multi-cell node's cell animation by a fx32 tick and, only if
 * that actually changed the displayed frame, marks the node's OAM cache dirty
 * through func_0206419C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064364.c  *       --func func_02064364 --addr 0x02064364 --cc 1.1p1
 */
void func_02064364(struct CellAnim *anim, s32 frames)
{
    if (func_02062D4C(anim, frames) != 0) {
        func_0206419C(anim);
    }
}



/*
 * The single-step form of func_02064364: steps the node's cell animation by
 * one frame instead of by a tick, and marks the cache dirty if it moved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064384.c  *       --func func_02064384 --addr 0x02064384 --cc 1.1p1
 */
void func_02064384(struct CellAnim *anim, u32 i)
{
    if (func_02062F00(anim, i) != 0) {
        func_0206419C(anim);
    }
}



/*
 * Restarts one node's cell animation from frame 0, forces its active flag at
 * +0x0C on and marks the node's OAM cache dirty unconditionally.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020643A4.c  *       --func func_020643A4 --addr 0x020643A4 --cc 1.1p1
 */
void func_020643A4(struct CellAnim *anim)
{
    func_02062F90((struct NNSG2dAnimController *)anim);
    anim->active = 1;
    func_0206419C(anim);
}



/*
 * *
 * Stores the multi-cell animation's user callback/context word at +0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020643C4.c  *       --func func_020643C4 --addr 0x020643C4 --cc 1.1p1
 */
void func_020643C4(struct MultiCellAnim *mca, u32 value)
{
    mca->unk14 = value;
}
