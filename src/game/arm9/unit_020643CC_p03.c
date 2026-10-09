/*
 * file:     unit_020643CC_p03.c
 * unit:     yes
 * function: func_020648B4, func_020648E0, func_02064934, func_020649D4, func_02064AB4, func_02064B68
 * address:  0x020648B4
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
 *   func_02064648    0x02064648  arm
 *   func_020629E8   0x020629E8  arm
 *   func_02064364  0x02064364  arm
 *   func_02062D4C  0x02062D4C  arm
 *   func_02062D40  0x02062D40  arm
 *   func_02064140  0x02064140  arm
 *   func_020640DC  0x020640DC  arm
 *   func_02064120  0x02064120  arm
 *   func_02064100  0x02064100  arm
 *   func_020643CC  0x020643CC  arm
 *   func_02062F00  0x02062F00  arm
 *   sub_020643C4  0x020643C4  arm
 */
#include "../../matched/include/Obj03474.h"
#include "../../matched/include/Obj04783.h"
#include "../../matched/include/Obj03475.h"
#include "../../matched/include/Obj07024.h"

struct MultiCellBank;
struct CellAnim;
struct Root;
struct MCInstance;
struct MultiCellData;
struct O02064140;
struct Obj02064100;
struct MultiCellAnim;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct MultiCellData {
    u16 numNodes;
    u16 unk_02;
    u32 nodes;
};

struct MultiCellBank {
    u16 numMultiCell;
    u16 unk_02;
    struct MultiCellData *array;
};

typedef signed int     s32;

struct MCD { u16 numNodes; u16 numCellAnims; void *nodes; };

struct Root { struct MCD *data; void *set; u32 kind; char *cells; };

struct Obj { u8 pad_00[0x14]; void *unk_14; u8 pad_18[0x1c]; struct Root root; };

extern u16 func_02064648(struct MultiCellBank *bank);
extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);
extern void func_02064364(struct CellAnim *anim, s32 frames);
extern int func_02062D4C(char *self, int a1);
extern void *func_02062D40(struct CellAnim *anim);
extern void func_02064140(struct O02064140 *o, u32 a);
extern void func_020640DC(char *self, int a, int b);
extern void func_02064120(char *self, int a, int b);
extern void func_02064100(struct Obj02064100 *obj, u16 val);
extern void func_020643CC(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);
extern int func_02062F00(void *s, u32 i);
extern void sub_020643C4(struct MultiCellAnim *mca, u32 value);
int func_020648B4(u32 a, u32 b);
u16 func_020648E0(struct MultiCellBank *bank);
void func_02064934(struct Root *p, int arg);
void func_020649D4(char *self, int a1);
void func_02064AB4(char *self, unsigned int i);
void sub_02064B68(struct Obj *o, void *arg);



int func_020648B4(u32 a, u32 b)
{
    u32 v;

    if (b == 1) {
        v = func_02064648((struct MultiCellBank *)a) * 0x5c;
    } else {
        v = func_020648E0((struct MultiCellBank *)a) << 7;
    }
    return v;
}




/*
 * Returns the largest node count among the multi-cell descriptors of the bank,
 * 0 for an empty bank.  The counter is a u16 (the `lsl #16` / `lsr #16` pair
 * per iteration) and the count is re-read from the bank every iteration, which
 * is why the guard at the top is a rotated `cmp count, #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020648E0.c \
 *       --func func_020648E0 --addr 0x020648E0 --arm --cc 1.1p1
 */
u16 func_020648E0(struct MultiCellBank *bank)
{
    u16 max = 0;
    u16 i;

    for (i = 0; i < bank->numMultiCell; i++) {
        u16 n = func_020629E8(bank, i)->numNodes;

        if (n > max) {
            max = n;
        }
    }

    return max;
}


/*
 * Step every node of the multi-cell walk block (struct Root of
 * docs/families/cluster_020640DC.h) by `arg` ticks: kind == 1 walks the
 * flat 0x5c-stride array for data->numCellAnims, anything else the
 * 0x28-stride group headers' first word for data->numNodes.
 *
 * The lever that closed the note's last 4 bytes (two head loads swapped,
 * docs/notes/func_02064934.c.txt): declare the index and the array base
 * INSIDE EACH ARM.  A function-scope `u16 i = 0; char *base = p->f0c;`
 * issues the base load before the data-pointer load; per-arm locals let
 * the front end hoist the arms' common data-pointer load first, which is
 * the image.  No dead local needed.  Identical bytes under dsi/1.1p1 and
 * ../2.0/sp2 (not a pin).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064934.c \
 *       --func func_02064934 --addr 0x02064934 --arm --cc 1.1p1
 */
void func_02064934(struct Root *p, int arg)
{
    if (p->kind == 1) {
        u16 i;
        char *cells = p->cells;
        for (i = 0; i < p->data->numCellAnims; i++) func_02064364((struct CellAnim *)(cells + i * 0x5c), arg);
    } else {
        u16 i;
        char *cells = p->cells;
        for (i = 0; i < p->data->numNodes; i++) func_02064364(*(void **)(cells + i * 0x28), arg);
    }
}



/*
 * The tick-driven form of func_02064AB4: steps the multi-cell animation by a
 * fx32 tick through func_02062D4C and, when that reports no advance, hands the
 * whole walk block at +0x34 to func_02064934 instead.  From the header test
 * down the body is func_02064AB4's verbatim.
 *
 * PIN ../2.0/sp2, inherited from the sibling src/matched/func_02064AB4.c: the
 * same case-2 cross-jump.  1.1p1 -O4,p shares case 2's
 * `add r0, r4, #0x48` / `bl func_020640DC` tail with the default arm's
 * identical pair at 0x02064A88/0x02064A8C and lands at 220 bytes against the
 * original's 224 (docs/notes/pkt_02064934.func_020649D4.c.txt).
 *
 * THREE C LEVERS, all needed and all found in this pass:
 *  1. func_02062D4C IS ARITY TWO, not three.  The note's body declared a third
 *     parameter and passed the latched halfword `t`; that costs a `mov r2, r5`
 *     at 0x020649E8 and the compile is 228 bytes.  The image sets only r0/r1.
 *  2. THE MISS ARM MUST BE A `goto` TO THE FUNCTION'S TAIL.  Written inline as
 *     `{ func_02064934(...); return; }` the compiler emits it in place under a
 *     `bne` where the image emits `beq #0x2064aa4` over the whole body to an
 *     arm placed AFTER the main epilogue.  Size-exact either way; the inline
 *     form is 140 concrete bytes out because everything after +0x1C is shifted
 *     by one instruction.
 *  3. `int kind;` MUST BE DECLARED BEFORE `int r7;`.  Declaration order is
 *     stack/colour order here: the reverse puts the masked kind in r7 and the
 *     descriptor in r6, where the image has kind in r6 and the descriptor in
 *     r7 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * The +0x2C PC24 to func_02064934 resolves by `sole-ref/code`: 0x02064934 is a
 * traced function start and this `bl` is its only branch image-wide, which is
 * exactly the single-caller shape `label` cannot reach.
 */
void func_020649D4(char *self, int a1)
{
    unsigned short t = *(unsigned short *)(((struct Obj04783 *)self)->f0 + 4);
    char *p;
    int kind;
    int r7;

    if (func_02062D4C(self, a1) == 0) {
        goto miss;
    }
    ((struct Obj04783 *)self)->f30 += t;
    if (*(unsigned short *)(((struct Obj04783 *)self)->f4 + 4) == 0)
        return;
    p = func_02062D40((struct CellAnim *)self);
    r7 = (int)func_020629E8((struct MultiCellBank *)(((struct Obj04783 *)self)->f44), ((struct Obj03474 *)p)->f0);
    kind = *(int *)(((struct Obj04783 *)self)->f1C + 4) & 0xff;
    func_02064140((struct O02064140 *)(self + 0x48), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(self + 0x48, *(short *)&((struct Obj03474 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        func_02064120(self + 0x48, ((struct Obj03474 *)p)->f4, ((struct Obj03474 *)p)->f8);
        func_02064100((struct Obj02064100 *)(self + 0x48), ((struct Obj03474 *)p)->f2);
        func_020640DC(self + 0x48, ((struct Obj03474 *)p)->fC, ((struct Obj03474 *)p)->fE);
        break;
    }
    func_020643CC((struct MCInstance *)(self + 0x34), (const struct MultiCellData *)r7, ((struct Obj04783 *)self)->f30);
    return;
miss:
    func_02064934((struct Root *)(self + 0x34), a1);
}



/*
 * PIN ../2.0/sp2: the "kept branches" tell.  The image writes the case-2
 * call tail out in its own arm -- `add r0, r4, #0x48` (0x02064B20) /
 * `bl func_020640DC` (0x02064B24) / `b 0x02064B54` (0x02064B28) -- although
 * the default arm ends in a byte-identical `add r0, r4, #0x48` /
 * `bl func_020640DC` pair at 0x02064B4C/0x02064B50.  1.1p1 -O4,p cross-jumps
 * the two, branching case 2 into the default arm's pair and giving 172 bytes
 * against the original's 180, 64 concrete bytes out.  Two independent lanes
 * measured a dozen spellings (switch arm order, if-chain, goto tail, named
 * s16 locals, nested switch) and all cross-jump.  Under the pin the same C
 * is 180 bytes, 0 mismatches.
 *
 * Same body as func_020649D4 from the header test down, but with a guard
 * that returns early instead of the missed-lookup arm, and no call to
 * func_02064934.  The early-out is ONE expression: the two tests are
 * predicated onto a single `popeq` (`ldrne`/`cmpne`/`popeq`), which is what
 * makes it a `||` inside a single `if` rather than two `if`s (two separate
 * guards would each need their own `pop`).
 */
void func_02064AB4(char *self, unsigned int i)
{
    char *p;
    int kind;
    int item;

    if (func_02062F00(self, i) == 0 || *(unsigned short *)(((struct Obj07024 *)self)->f4 + 4) == 0)
        return;
    p = func_02062D40((struct CellAnim *)self);
    item = (int)func_020629E8((struct MultiCellBank *)(((struct Obj07024 *)self)->f44), ((struct Obj03475 *)p)->f0);
    kind = *(int *)(((struct Obj07024 *)self)->f1C + 4) & 0xff;
    func_02064140((struct O02064140 *)(self + 0x48), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(self + 0x48, *(short *)&((struct Obj03475 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        func_02064120(self + 0x48, ((struct Obj03475 *)p)->f4, ((struct Obj03475 *)p)->f8);
        func_02064100((struct Obj02064100 *)(self + 0x48), ((struct Obj03475 *)p)->f2);
        func_020640DC(self + 0x48, ((struct Obj03475 *)p)->fC, ((struct Obj03475 *)p)->fE);
        break;
    }
    func_020643CC((struct MCInstance *)(self + 0x34), (const struct MultiCellData *)item, ((struct Obj07024 *)self)->f30);
}


/*
 * PART 1 bank walker of docs/families/cluster_02064B68.h: publish `arg` at
 * +0x14, then step every record of the walk block at +0x34 (the same
 * struct Root func_02064934 takes) through sub_020643C4 -- kind 1 the flat
 * 0x5c-stride array for numCellAnims, else the 0x28-stride headers' first
 * word for numNodes.
 *
 * Two levers closed docs/notes/sub_02064B68.c.txt's last 11 bytes:
 *   - the index and base are PER-ARM locals (as in func_02064934);
 *   - the +0x14 store is written IN EACH ARM.  The front end hoists the
 *     common store above the branch but schedules it below the `cmp` and
 *     the index zero, which is the image; a single store before the `if`
 *     issues it above the `cmp` (11 out), and with it the volatile hdr
 *     the note needed is no longer necessary (the per-arm store is what
 *     keeps each arm's +0x34 load in its arm).
 * 1.1p1 gives 168 bytes / 24 out on the same C: pinned ../2.0/sp2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02064B68.c \
 *       --func sub_02064B68 --addr 0x02064B68 --arm --cc ../2.0/sp2
 */
void sub_02064B68(struct Obj *o, void *arg)
{
    if (o->root.kind == 1) {
        u16 i;
        char *cells = o->root.cells;
        o->unk_14 = arg;
        for (i = 0; i < o->root.data->numCellAnims; i++) sub_020643C4((struct MultiCellAnim *)(cells + i * 0x5c), (u32)arg);
    } else {
        u16 i;
        char *cells = o->root.cells;
        o->unk_14 = arg;
        for (i = 0; i < o->root.data->numNodes; i++) sub_020643C4(*(void **)(cells + i * 0x28), (u32)arg);
    }
}
