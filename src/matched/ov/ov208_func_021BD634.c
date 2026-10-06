/*
 * function: ov208_func_021BD634
 * address:  0x021BD634
 * packet:   pkt_ov208_021BD634
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wD8 lane04): EXACT. res is a const int * (021BD56C is a plain `return p[i]` getter, declared
 *   with a const parameter) and p->f4 = 1 comes before p->f34 = 0 in the source. With a non-const res the f4
 *   store is not sunk below the pos clear arguments; with const res and the old f34-first order 4 bytes differ
 *   (movs r7,#1 after the f34 store).
 * 2026-10-04 (D2-16): no change in the 8-byte residue (str r7,[r5,#4] after the memset argument setup in the image). Reread listing:
 * r7=1 is set before the f34 store, the store p->f4 sits between the arg moves and the blx. Nothing new tried beyond D1/C2 list.
 *
 * 2026-10-04 (D1-08): also tried `struct Ov208Pos pos = {0}` in a nested block (compiler zeroes with strh, not a memset call; 203 bytes out).
 *
 * 2026-10-02 (lane C2-01): also tried a local `one = 1` shared by all three uses of 1, f4 store after
 * the pos memset, f4/f34 stores swapped: 8/16/12 bytes out, no better.
 * 8 bytes out: the store p->f4 = 1 (str r7, [r5, #4]) is scheduled after the
 * memset argument setup in the image, before it in every spelling tried.
 *
 * 2026-10-05 (D4-18): still 8 bytes. Tried: p->f4 as a raw *(u32 *)((u8 *)p + 4) = 1 (same 8 bytes); p->f4 after the pos memset call (16 bytes, r7=1 then lands after the call). Image has movs r7,#1 before the f34 store and the f4 store between the memset argument moves and the blx; no honest statement order produces that.
 *
 * 2026-10-05 (D5-03): still 8 bytes. Re-read: the r7 = 1 is also the second argument of
 *   func_021BD56C(res, 1) (`adds r1, r7, #0`), so it is one value live across the calls; ours has
 *   the same colouring, only the store schedule differs. Tried: MI_CpuClear8-style static inline
 *   wrapper for both clears, one `int one` shared by the f4 store and the 021BD56C argument only,
 *   f4 store in its own block after f34, f34 before the desc copy with f4 after it (23 bytes).
 *   Arguments and callee arities all agree with the image.
 *
 * 2026-10-05 (D6-04): still 8 bytes. Tried: f4 store before the desc struct copy (23 bytes, the
 *   copy does not let it sink), a block-local `struct Ov208Pos *pp = &pos;` set before the f4 store
 *   (same 8 bytes). The four instructions are pure ALU plus one store with no memory conflict, so
 *   only the scheduler's tie order differs; the D6 const-table lever (021C2238) does not apply here.
 *
 * 2026-10-05 (D7-08): still 8 bytes. Tried: the clear + desc copy + f34 store as a static inline ObjInit(p, desc)
 *   with f4 after it (8 bytes); f34 and f4 stores in a static inline ObjFlags(p) (8 bytes); f4 before f34 in
 *   source: the scheduler still emits str f34 first (needed to free r0) and then str f4 before the argument
 *   moves (12 bytes, movs r7/movs r0 swap). The image puts the store after the three argument moves; mwcc keeps
 *   source order among ready instructions, so the store must have been later in the IR than the argument setup,
 *   which no plain C statement order before the call gives.

 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020416D4  0x020416D4  arm
 *   func_021BD56C  0x021BD56C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BD880  0x021BD880  thumb
 *   func_021BD89C  0x021BD89C  thumb
 *   data_021C8314  0x021C8314  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActKind {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
};

struct Ov208Pos {
    s16 x;
    s16 y;
    u16 h4;
    u8  b6;
    u8  b7;
};

struct Ov208ActObj {
    u32 f0;
    u32 f4;
    u32 f8;
    void (*fc)(void);
    u32 f10;
    struct Ov208ActDesc desc;
    u32 f34;
};

extern void func_02082BCC(void *p, u32 v, u32 n);
extern u8   func_020416D4(u32 layer);
struct Obj;
extern int func_021BD56C(int *p, int i);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BD880(char *p);
extern void func_021BD89C(char *p);
extern const struct Ov208ActKind data_021C8314[];

void ov208_func_021BD634(struct Ov208ActObj *p, u32 owner, const int *res, struct Ov208ActDesc *desc,
                         u32 prio, u16 mode)
{
    struct Ov208Pos pos;
    u32 i;
    u32 j;
    u32 k;
    int n;

    func_02082BCC(p, 0, 0x38);
    p->desc = *desc;
    p->f4 = 1;
    p->f34 = 0;
    func_02082BCC(&pos, 0, 8);
    pos.b7 = func_020416D4((u8)res[3]);
    pos.x = desc->x;
    pos.y = desc->y;
    if (desc->f0 >= 7) {
        i = desc->ha;
        j = desc->hc;
        k = desc->he;
        p->f10 = 0;
    } else {
        i = func_021BD56C((int *)res, 1);
        j = func_021BD56C((int *)res, 0);
        k = func_021BD56C((int *)res, 2);
        n = desc->f0;
        p->desc.h10 = data_021C8314[n].a;
        p->desc.h12 = data_021C8314[n].b;
        p->desc.h14 = data_021C8314[n].c;
        p->desc.f18 = data_021C8314[n].e;
        p->desc.f1c = data_021C8314[n].d;
        p->f10 = data_021C8314[n].f;
    }
    p->f8 = p->desc.h10;
    pos.h4 = p->desc.h10;
    p->f0 = (u32)func_0204B294((void *)owner, i, j, k, &pos, prio, mode);
    func_0204B92C((struct Obj *)p->f0, 1);
    switch (p->f10) {
    case 0:
        p->fc = (void (*)(void))func_021BD880;
        break;
    case 1:
        p->fc = (void (*)(void))func_021BD89C;
        break;
    }
}
