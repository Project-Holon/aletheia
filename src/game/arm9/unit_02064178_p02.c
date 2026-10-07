/*
 * file:     unit_02064178_p02.c
 * unit:     yes
 * function: func_020642C8, func_0206434C, func_02064364, func_02064384, func_020643A4, func_020643C4
 * address:  0x020642C8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02066890  0x02066890  arm
 *   func_02064140  0x02064140  arm
 *   func_02062F38  0x02062F38  arm
 *   func_0206434C  0x0206434C  arm
 *   func_02062FF0   0x02062FF0  arm
 *   func_0206419C   0x0206419C  arm
 *   func_02062D4C  0x02062D4C  arm
 *   func_02062F00  0x02062F00  arm
 *   func_02062F90  0x02062F90  arm
 */
#include "../../matched/include/Obj08900.h"
#include "../../matched/include/Obj16429.h"

struct O02064140;
struct CellAnim;
struct NNSG2dAnimController;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

struct CellAnim {
    u8 pad00[0xC];
    u32 active;
};

struct MultiCellAnim {
    u8 pad00[0x14];
    u32 unk14;
};

extern void func_02066890(u32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02064140(struct O02064140 *o, u32 a);
extern int func_02062F38(int a0);
extern void func_0206434C(char *self, int v);
extern void func_02062FF0(struct CellAnim *anim, void *bank);
extern void func_0206419C(char *self);
extern s32  func_02062D4C(struct CellAnim *anim, s32 frames);
extern int func_02062F00(void *s, u32 i);
extern void func_02062F90(struct NNSG2dAnimController *pAnimCtrl);
void func_020642C8(char *self, int a1, char *c, int d, int e, int f, int g, int h, int i, int j);
void ENV_SetResourceSet(void *anim, void *seq);


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
void func_020642C8(char *self, int a1, char *c, int d,
                   int e, int f, int g, int h, int i, int j)
{
    func_02066890(d, e, f, g, *(int *)*(int * *)&((struct Obj16429 *)c)->fC, h, i, j);
    *(volatile int *)&((struct Obj08900 *)self)->f38 = d;
    *(char *volatile *)&((struct Obj08900 *)self)->f34 = c;
    *(volatile int *)&((struct Obj08900 *)self)->f38 = d;
    func_02064140((struct O02064140 *)(self + 0x3c), 1);
    func_02062F38((int)self);
    func_0206434C(self, a1);
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
        func_0206419C((char *)anim);
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
        func_0206419C((char *)anim);
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
    func_0206419C((char *)anim);
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
