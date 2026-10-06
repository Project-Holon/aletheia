/*
 * file:     wipe_sub_p18.c
 * unit:     yes
 * function: func_020244F8, func_02024508, func_02024520, func_0202452C, func_02024530, func_02024534, func_02024570, func_02024584, func_02024598, func_020245A0, func_020245AC, func_020245D4, func_0202465C, func_020246C8, func_0202473C, func_02024768, func_020247A8
 * address:  0x020244F8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0209F71C  0x0209F71C  data
 *   func_02024498  0x02024498  thumb
 *   func_020248D8  0x020248D8  thumb
 *   data_0209F734  0x0209F734  data
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   str_020A746C   0x020A746C  data  a1
 *   tbl_0209F7AC   0x0209F7AC  data  a2
 */
#include "../../matched/include/Obj05795.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Container {
    u8 pad[4];
    u16 arr[];
};

typedef int           s32;

struct Data {
    u16 a;
    u16 b;
    u16 c[2];
};

struct Rec8 {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

struct T {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
};

struct Tbl {
    u16 f[12];
};

struct PmsWordSys {
    u32   heapId;
    void *msg[13];
};

extern u32 func_02024498(u32 a0, u32 a1, u32 a2);
extern int func_020248D8(u32 v, u32 *a1, u32 *a2);
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern void *func_02045B38(u32 a, u32 b, u32 id, u16 heap);
u32 func_020244F8(struct Container *p, u32 idx);
u32 sub_02024508(u32 x);
u32 sub_02024520(u32 x);
int func_0202452C(const u16 *p);
unsigned int func_02024530(const u16 *p);
int func_02024534(const struct Data *p1, const struct Data *p2);
void sub_02024570(struct Rec8 *dst, const struct Rec8 *src);
u8 func_02024584(u32 i);
void func_02024598(void *p0, int p1, int p2);
void func_020245A0(u8 *p,unsigned i,u16 v);
void func_020245AC(struct T *p, u32 a1);
u32 func_020245D4(struct T *p, u32 a1);
u32 func_0202465C(struct T *p, u32 a1, u32 a2);
u32 func_020246C8(u16 *p, u32 mode, u32 flag);
u32 func_0202473C(u32 *p, u32 a);
s32 func_02024768(u32 v);
struct PmsWordSys *func_020247A8(u32 heapId);
extern u8 g_0209F71C[];
extern const struct Tbl data_0209F734;
extern const char str_020A746C[];
extern const u16  tbl_0209F7AC[];



u32 func_020244F8(struct Container *p, u32 idx)
{
    return sub_02024508(p->arr[idx]);
}



/*
 * A sentinel-guarded bit test: 0xFFFF is treated as "unset" and reads as
 * bit 0, everything else reads back bit 11.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024508.c \
 *       --func sub_02024508 --addr 0x02024508 --cc 1.1p1 --thumb
 */
u32 sub_02024508(u32 x)
{
    if (x == 0xFFFF) {
        return 0;
    }
    return ((s32)x >> 11) & 1;
}




/*
 * A plain bitmask, `& 0x7FF`. Immediately followed by two unlabelled
 * one-argument halfword accessors (`ldrh r0,[r0]`/`bx lr` and
 * `ldrh r0,[r0,#2]`/`bx lr`) that carry no push prologue and so are
 * invisible to disasm.py's sweep; not reproduced here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024520.c \
 *       --func sub_02024520 --addr 0x02024520 --cc 1.1p1 --thumb
 */
u32 sub_02024520(u32 x)
{
    return x & 0x7FF;
}




/*
 * Unlabelled Thumb leaf in the ARM9 module: returns the first halfword.
 *
 * Addresses are Black-image addresses.
 */
int func_0202452C(const u16 *p)
{
    return *p;
}



/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
unsigned int func_02024530(const u16 *p) { return p[1]; }




int func_02024534(const struct Data *p1, const struct Data *p2)
{
    int i;

    if (p1->a != p2->a || p1->b != p2->b) {
        return 0;
    }

    for (i = 0; i < 2; i++) {
        if (p1->c[i] != p2->c[i]) {
            return 0;
        }
    }

    return 1;
}



/*
 * A plain 4-halfword struct copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024570.c \
 *       --func sub_02024570 --addr 0x02024570 --cc 1.1p1 --thumb
 */
void sub_02024570(struct Rec8 *dst, const struct Rec8 *src)
{
    *dst = *src;
}



u8 func_02024584(u32 i)
{
    if (i < 7) {
        return g_0209F71C[i];
    }
    return 0;
}



void func_02024598(void *p0, int p1, int p2){ ((struct Obj05795 *)p0)->f0 = (unsigned short)p1; ((struct Obj05795 *)p0)->f2 = (unsigned short)p2; }


/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
void func_020245A0(u8 *p,unsigned i,u16 v) {
    if(i<2) *(u16 *)(p+4+2*i)=v;
}



void func_020245AC(struct T *p, u32 a1)
{
    u32 n = func_02024498(p->f00, p->f02, a1);

    if (n < 2) {
        do {
            *(u16 *)((char *)p + n * 2 + 4) = 0xffff;
            n++;
        } while (n < 2);
    }
}



/*
 * pmsi_param.c's word-array validator: guards the (category, page) pair
 * against the per-category count, asks func_02024498 how many words the
 * page carries, and runs each word through the same two-arm check
 * func_020246C8 performs on a single word.
 *
 * THE LEVER that closed this (it was DIFF, 132 bytes against 136, for the
 * whole of the previous wave -- see docs/notes/func_020245D4.diff.c.txt):
 * BOTH arms of the two-arm check write the `ok = 0; goto ret;` tail out,
 * and the label `setfail` sits INSIDE THE FIRST ARM'S COPY.  That is the
 * mixed case of docs/idioms/two-arms-write-the-tail-out-and-the-third-
 * branches-back-into-one.md.  The original spends a conditional AND an
 * unconditional branch at +0x64/+0x66 (`bne <loop increment>; b <setfail>`)
 * exactly because the two arms did not cross-jump; every shape that shares
 * one copy behind a single label folds them into one inverted `beq`, loses
 * four bytes and shifts every later branch target.
 *
 * Equally load-bearing: the `!= 0` arm is written FIRST
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  With the
 * `== 0` arm first the two call sites swap and 17 bytes differ.
 *
 * `sel` must be a named local: the guard reads p->f02 once and the same
 * value is handed to func_02024498, which is what keeps r5 live across the
 * func_02024584 call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020245D4.c \
 *       --func func_020245D4 --addr 0x020245D4 --thumb --cc 1.1p1
 */
u32 func_020245D4(struct T *p, u32 a1)
{
    u32 ok;
    u32 n;
    u32 i;
    u32 y, x;
    u32 sel;

    if (p->f00 >= 7) {
        goto fail;
    }
    sel = p->f02;
    if (sel >= func_02024584(p->f00)) {
        goto fail;
    }

    n = func_02024498(p->f00, sel, (u16)((a1 & 0x7FFF) | 0x8000));
    ok = 1;
    for (i = 0; i < n; i++) {
        struct T *q = (struct T *)((u16 *)p + i);

        if (sub_02024508(q->f04) != 0) {
            s32 v = sub_02024520(q->f04);

            if (v >= 1 && v < 11) {
                continue;
            }
setfail:
            ok = 0;
            goto ret;
        } else {
            if (func_020248D8(q->f04, &x, &y) != 0) {
                continue;
            }
            ok = 0;
            goto ret;
        }
    }
ret:
    return ok;
fail:
    return 0;
}



u32 func_0202465C(struct T *p, u32 a1, u32 a2)
{
    u32 ok = 1;
    u32 n;
    u32 i;

    if (p->f00 >= 7 || p->f02 >= (u32)func_02024584(p->f00)) {
        ok = 0;
        p->f00 = 0;
        p->f02 = 0;
    }

    n = func_02024498(p->f00, p->f02, (u16)((a2 & 0x7FFF) | 0x8000));
    if (n > 2) {
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (func_020246C8(&p->f04 + i, a1, 1) == 0) {
            ok = 0;
        }
    }
    return ok;
}



/*
 * pmsi_param.c's single-word validator (see docs/families/pmsi_param.h and
 * func_020245D4, which runs the same two-arm check over a word array).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 116/116, 1 byte out at +0x3E
 * for three waves, docs/notes/func_020246C8.diff.c.txt): the flag arm writes
 * the fail tail `ok = 0; *p = 0x6A1; goto done;` out after the range test,
 * like the flag == 0 arm does. The image's `blt` lands on an unconditional
 * `b bad` instead of on `bad` itself: a branch that jump threading did not
 * follow is a branch into a cross-jumped copy of a written-out tail, because
 * cross-jumping runs after threading. Falling into the shared `bad:` label
 * lets 1.1p1 thread the hop away.
 */
u32 func_020246C8(u16 *p, u32 mode, u32 flag)
{
    u32 ok = 1;
    u32 y, x;

    if (mode != 0) {
        if (*p == 0xFFFF) {
            return ok;
        }
    } else {
        if (*p == 0xFFFF) {
            *p = 0x6A1;
            return 0;
        }
    }

    if (sub_02024508(*p) != 0) {
        s32 v;

        if (flag != 0) {
            v = sub_02024520(*p);
            if (v >= 1 && v < 11) {
                goto done;
            }
            ok = 0;
            *p = 0x6A1;
            goto done;
        } else {
            ok = 0;
            *p = 0x6A1;
            goto done;
        }
    } else {
        if (func_02024768(*p) == 0) {
            if (func_020248D8(*p, &x, &y) != 0) {
                goto done;
            }
        }
    }
bad:
    ok = 0;
    *p = 0x6A1;
done:
    return ok;
}




/*
 * Clamp a counter to the range 1..10, with a mode argument that changes
 * only the zero case: called with `a == 0` and a zero field, the field is
 * reset to 1 and 0 is returned; called with `a != 0` a zero field is left
 * alone and 1 is returned outright, skipping the range check entirely.
 * Every other value goes through the same range test regardless of `a`.
 *
 * The `result` local has to be initialised before either branch reads
 * `*p` (docs/idioms/initialise-the-result-before-the-input-or-every-arm-
 * duplicates-the-return.md): that ordering, not the declaration order, is
 * what keeps the constant 1 resident in one register across both early
 * returns and the range check's shared exit, instead of each arm
 * rematerialising its own `movs r0, #k; bx lr`. The two early returns
 * (the `a != 0` zero case and the `a == 0` zero case) are written as
 * direct `return` statements and stay as separate tails; only the range
 * check's in-range case and the clamp's fallthrough share one exit block,
 * reached by a `goto` from the first and by falling into it from the
 * second, exactly as the original's single `blt` past the clamp and the
 * clamp's own fallthrough both land on one `adds r0, r2, #0; bx lr`.
 *
 * This is wordset.c's normaliser: src/pending/sub_0201EFFC.c calls it and
 * is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202473C.c \
 *       --func func_0202473C --addr 0x0202473C --cc 1.1p1 --thumb
 */
u32 func_0202473C(u32 *p, u32 a)
{
    u32 result = 1;
    s32 v;

    if (a != 0) {
        v = (s32)*p;
        if (v != 0) {
            goto range;
        }
        return result;
    }
    v = (s32)*p;
    if (v != 0) {
        goto range;
    }
    *p = result;
    return 0;

range:
    if (v < 1) {
        goto clamp;
    }
    if (v < 0xb) {
        goto end;
    }

clamp:
    *p = 1;
    result = 0;

end:
    return result;
}




/*
 * Blocked: data_0209F734 (a 12-halfword table) is named by exactly one pool word,
 * 0x020247A4, and that word is inside this function's own range once the
 * body compiles to its full 64 bytes; the `literal` class discards it. Every
 * concrete byte reproduces.
 */
s32 func_02024768(u32 v)
{
    struct Tbl b;
    u8 i;

    b = data_0209F734;
    for (i = 0; i < 12; i++) {
        if (v == b.f[i]) {
            return 1;
        }
    }
    return 0;
}




/*
 * pms_word.c: allocate the 0x38-byte word-message system and open its
 * thirteen message archives (ids from the u16 table at 0x0209F7AC).  The
 * heap id store sits inside the loop in the image, so it is inside the
 * loop here.  The r4/r5 swap of docs/notes/pkt_02024768.c.txt was the
 * declaration order: the counter is declared before the result pointer
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md),
 * found by tools/permuter.py and reduced to that one change.
 */
struct PmsWordSys *func_020247A8(u32 heapId)
{
    int i;
    struct PmsWordSys *p;

    p = func_02030734((u16)heapId, 0x38, 0, str_020A746C, 0x32);
    for (i = 0; i < 13; i++) {
        p->heapId = heapId;
        p->msg[i] = func_02045B38(0, 2, tbl_0209F7AC[i], heapId);
    }
    return p;
}
