/*
 * file:     mystery_util_p11.c
 * unit:     yes
 * function: func_021DB3E8, func_021DB478, func_021DB528, func_021DB54C
 * address:  0x021DB3E8
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040DA8 0x02040DA8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021D9A40 0x021D9A40 thumb ov121
 *   func_021DBDB8 0x021DBDB8 thumb ov121
 *   func_021D9B28 0x021D9B28 thumb ov121
 *   func_021D9B2C 0x021D9B2C thumb ov121
 *   func_021D9AC8 0x021D9AC8 thumb ov121
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021DB938 0x021DB938 thumb ov121
 *   d_021DF86E 0x021DF86E data ov121 a2
 *   d_021DF86F 0x021DF86F data ov121 a1
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DBF08 0x021DBF08 thumb ov121
 *   func_021DBF10 0x021DBF10 thumb ov121
 *   func_021DBF40 0x021DBF40 thumb ov121
 *   func_021DBF70 0x021DBF70 thumb ov121
 *   func_021DBF9C 0x021DBF9C thumb ov121
 *   func_021DBFE4 0x021DBFE4 thumb ov121
 *   func_021DC004 0x021DC004 thumb ov121
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC03C 0x021DC03C thumb ov121
 *   func_02041300 0x02041300 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02043814 0x02043814 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../../matched/include/Obj01058.h"
#include "../../matched/include/Obj00828.h"

struct Descriptor;
struct Obj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct CharBuf;
struct Bmp;
struct Vec2;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef short s16;

typedef union Rect { s16 h[4]; u8 b[8]; } Rect;

typedef struct Cur { s16 x; s16 y; } Cur;

typedef struct Pos { s16 x; s16 y; u8 pad[3]; u8 flag; } Pos;

extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021D9A40(u8 *p);
extern int func_021DBDB8(char *);
extern void func_021D9B28(u8 *p, unsigned v);
extern void func_021D9B2C(char *p, u32 a, u32 b, int c);
extern void func_021D9AC8(u8 *p, int a, int b);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_020409B4(u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021DB938(char *,int,u16);
extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void func_020413B0(u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02049238(void *);
extern void func_02082BCC(void *, int, int);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int func_021DBF04(int *p);
extern void *func_021DBF08(void *);
extern void *func_021DBF10(void *, u16);
extern u32 func_021DBF40(void *);
extern u32 func_021DBF70(void *);
extern int func_021DBF9C(void *);
extern int func_021DBFE4(void *);
extern int func_021DC004(void *);
extern int func_021DC024(void *);
extern int func_021DC03C(void *);
void func_021DB3E8(char *p);
void func_021DB478(char *p,int a,int b,int c,u16 heap);
void func_021DB528(char *p,int a);
void func_021DB54C(char *p, int a, int b, int c, u16 index, u16 heap);
extern const Rect d_021DF86E[];
extern const u8 d_021DF86F[];

void func_021DB3E8(char *p)
{
    int i;
    func_02040DA8(2,1,0);
    func_02040DA8(1,1,0);
    for(i=0;i<2;i++) func_0204B3B4(*(void **)(p+0xaf4+i*4));
    func_0204B3B4(((struct Obj01058 *)p)->fAF0);
    func_0204B3B4(((struct Obj01058 *)p)->fAEC);
    func_0204A8D4((u32)(((struct Obj01058 *)p)->fAFC));
    func_0204AFD8((u32)(((struct Obj01058 *)p)->fB00));
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fB04));
    func_021D9A40(((struct Obj01058 *)p)->fAB4);
    ((struct Obj01058 *)p)->fAB4=0;
    func_0204ADA4((u32)(((struct Obj01058 *)p)->fBA8));
    for(i=0;i<8;i++) func_020452E8(*(void **)(p+0xb08+i*4));
}

void func_021DB478(char *p,int a,int b,int c,u16 heap)
{
    int i;
    void *text,*other;
    for(i=0;i<4;i++) func_021DB54C(p,a,b,c,(u16)i,heap);
    text=func_020457B0(128,heap);
    other=func_02045EC0(((struct Obj00828 *)p)->f1C,150);
    func_0201EFA4(((struct Obj00828 *)p)->f18,0,c+1,1,1,1);
    func_0201EFA4(((struct Obj00828 *)p)->f18,1,func_021DBDB8(p),1,1,1);
    func_0201F250(((struct Obj00828 *)p)->f18,text,other);
    func_021D9B28(((struct Obj00828 *)p)->fAB4,0x39ea);
    func_021D9B2C(((struct Obj00828 *)p)->fAB4,0,0,1);
    func_021D9AC8(((struct Obj00828 *)p)->fAB4,(int)text,((struct Obj00828 *)p)->f10);
    func_02045808(text);
    func_02045808(other);
    func_020409B4(3);
}

void func_021DB528(char *p,int a) { int i; for(i=0;i<4;i++) func_021DB938(p,a,i); func_020409B4(3); }

#pragma opt_loop_invariants off

#pragma opt_lifetimes off

/*
 * note 2026-10-05 (lane P9): first draft, no source existed. DIFF, 1024 vs 1004 bytes.
 *   Structure matches the listing (loops, tail, callee arguments). Separate locals
 *   for rect/pos/cur (not one struct) give the right heap/index prologue; a static
 *   inline ents(p) = p + 0x28 gives the double store of the table base.
 *   Residue: the original keeps the two signed divisions by 3 inside the y loop
 *   (dividend (u8)k hoisted to a spill slot, rem first, quot second); every form
 *   tried hoists the whole tile base out of the loop (parenthesised, one expression,
 *   u8 m, inline cast, cols=3 local: 12 compiles). Spill slot numbers and register
 *   colours (rx r5, x r4, yy r7) follow from that. The 0x100 in the final block is
 *   built as r4(=1)+0xff in the original, not reproduced. Pool-base adds (p+0xb08
 *   etc.) are shared in the draft but recomputed in the original.
 *   Idioms checked: a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters
 *   (heap already u16 in all prototypes), narrow-stack-parameters-and-callee-prototype-
 *   free-the-narrow-home-store (prologue now matches for 14 bytes).
 * note 2026-10-05 (lane P9b): still DIFF, 1028 vs 1004 bytes. 13 more compiles, none changed
 *   the size. Tried: tile base as a static inline tb(k, y) called in the y body; separate
 *   rem/quo locals (rem first); tile expression written inside the x loop call argument;
 *   y loop as do/while; m = (u8)k assigned inside the y body instead of before the loop
 *   (mwcc hoists the cast AND both divisions out of the y loop in every form, so LICM
 *   hoists in one step through the whole chain); per-function pragmas opt_loop_invariants,
 *   opt_lifetimes, opt_propagation, opt_common_subs off (size 1028/1028/1064/1100, no help).
 *   The original hoists the (u8)k cast but keeps both calls in the y body: the divisions
 *   must be loop-variant or non-hoistable at IR level for a reason no source form tried
 *   shows. Untested guesses: a hoist budget limit, or a different dividend source.
 *   Idioms checked: signed-modulo-magic-reappears-when-the-source-divides-by-the-same-
 *   constant-twice (not applicable, divisor 3 is a real call here); matched twin ov217
 *   021BD178 has the divisions inside the loop only because its operands depend on i, j.
 * note 2026-10-05 final push G10L1: DIFF, 53 of 1004 bytes off (was 470 of 1028 at the start of
 *   the push). Size now equals the original. What closed most of the residue:
 *   (1) the tail pos.x chain is `if (a) x = h2; else if (b) x = h2 - 0x100; else if (b == 0)
 *   x = h2 + 0x100; else x = h2;` (the original tests a once; 1028 -> 1016 bytes);
 *   (2) the cur block is `if (a == 0) { if (b) x -= 0x100; else if (b == 0) x += 0x100; }`
 *   (1016 -> 1004); (3) `#pragma opt_loop_invariants off` keeps both /3 and %3 calls inside the
 *   y loop (the old lane tried it only while the size was still wrong); (4) do-while loops with
 *   `x = 0;` first in the y body and `y = 0;` before the loops give the original head order;
 *   (5) a local for func_021DBF08's result puts that call before the idx*4 address work;
 *   (6) declaration order off, tab, idx, y, y2, y3 (one counter per loop), m, src, k, ry, rx
 *   gives the original spill slots for most locals; tab = p + 0x28 plain (no inline helper);
 *   (7) dy = 0 before func_02082BCC.
 *   Residue (53 bytes): rx and x swapped (original x r4, rx r5; mine rx r4, x r5; decl order of
 *   x/rx did not move it, 2 compiles); index and ry slots swapped (original index sp+0x18, ry
 *   sp+0x1c); obj and the p+0xb88 base temp slots swapped (original obj sp+0x48, temp sp+0x44);
 *   `dx = 0` (movs r6) sits before the call to func_021DBF9C in mine, just before the blx of
 *   func_0204A6C8 in the original.
 *   Idioms checked: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no source
 *   order found that flips x/rx), a-separate-index-local-per-loop-reorders-spill-slots (y per
 *   loop: moved y2/y3 next to y), function-scope-versus-block-scope-decides-spill-slot-order,
 *   div-and-mod-are-two-calls, a-reloaded-loop-invariant-means-the-loop-was-not-rotated
 *   (goto loops still hoist). Twin: ov121 021DB938 (same top condition and loops).
 * note 2026-10-05 final push G10L1 round 2: DIFF, 28 of 1004 bytes off. `dx = 0;` moved to just
 *   after the func_0204A6C8 statement (53 -> 28; this also fixed the obj/temp slot swap).
 *   Remaining: x in r5 and rx in r4 (original x r4, rx r5), and the index/ry spill slots swapped
 *   (original index sp+0x18, ry sp+0x1c). Tried without effect: dx = 0 as a call argument (251),
 *   u8 rx/ry, a y=x=0 head, separate x2/x3 per loop, decl order of x/rx/tile; opt_propagation off
 *   (91), opt_common_subs off (758), opt_lifetimes off (25 but x r4, rx r6, tile r5, index/ry swap
 *   stays); callee prototypes re-grepped in src/matched (all match the draft). Without the
 *   pragma and with direct r.b[0]/r.b[1] reads (like matched 021DB938) the slots all match but
 *   both /3 and %3 are hoisted (84); `(u8)k` inline, `cols = 3` local did not stop the hoist.
 * note pass 2 2026-10-06 P2L41: EXACT (c99 and c). Closed with `#pragma opt_lifetimes off` (beside
 *   opt_loop_invariants off), one tile local per loop (tile, tile2, tile3, like y/y2/y3), x declared
 *   before rx, int ry passed straight to func_020413B0 with the u32 x/y prototype used by matched
 *   callers (ov217 021BA284, ov088 021BB810). Under lifetimes off the colour order follows degree
 *   then declaration order: per-loop tiles make the tiles drop out first, then rx, then x, giving
 *   x r4, rx r5, tile r6. Passing ry (not r.b[1]) keeps ry itself as the spilled web, so it takes
 *   the slot after k (sp+0x1c) and index takes sp+0x18.
 */
void func_021DB54C(char *p, int a, int b, int c, u16 index, u16 heap)
{
    void *obj;
    int off;
    char *tab;
    int idx;
    int y, y2, y3;
    int m;
    const Rect *src;
    int k, ry;
    int x, rx, yy, tile, tile2, tile3;
    s16 dx, dy;
    void *dsc;
    Rect r;
    Pos pos;
    Cur cur;
    k = index + c * 4;
    tab = p + 0x28;
    off = k * 0xdc;
    idx = index;
    src = &d_021DF86E[index];
    r = *src;
    if ((a && *(u32 *)(p + 0xad0) == 0) || (a == 0 && *(u32 *)(p + 0xad0))) {
        idx += 4;
        r.b[0] += 32;
        r.b[2] += 32;
    }
    y = 0;
    ry = r.b[1];
    rx = r.b[0];
    m = (u8)k;
    do {
        x = 0;
        yy = ry + y;
        tile = y * 32 + ((m % 3) * 64 + 0x58 + (m / 3) * 2);
        do {
            func_02041300(3, (u16)(x + tile), (u8)(rx + x - 2), (u8)yy, 1, 1, 3);
            x++;
        } while (x < 2);
        y++;
    } while (y < 2);
    if (func_021DBF04((int *)(tab + off)) == 0) {
        y2 = 0;
        do {
            x = 0;
            yy = ry + y2;
            tile2 = y2 * 32 + 384;
            do {
                func_02041300(3, (u16)(x + tile2), (u8)(rx + x), (u8)yy, 1, 1, 3);
                x++;
            } while (x < 12);
            y2++;
        } while (y2 < 7);
        func_02043B5C(func_02045770(*(void **)(p + 0xb08 + idx * 4)), 0);
        func_02045334(*(void **)(p + 0xb08 + idx * 4));
        return;
    }
    y3 = 0;
    do {
        x = 0;
        yy = ry + y3;
        tile3 = y3 * 32 + 0x40;
        do {
            func_02041300(3, (u16)(x + tile3), (u8)(rx + x), (u8)yy, 1, 1, 5);
            x++;
        } while (x < 12);
        y3++;
    } while (y3 < 7);
    func_020413B0(3, r.b[0], ry, 12, 7, (u8)func_021DC03C(tab + off));
    dsc = func_021DBF08(tab + off);
    func_02043814(dsc, func_02045770(*(void **)(p + 0xb08 + idx * 4)));
    func_02045334(*(void **)(p + 0xb08 + idx * 4));
    obj = func_021DBF10(tab + off, heap);
    if (func_021DC024(tab + off) != 1)
        *(int *)(p + 0xb88 + idx * 4) = func_0204AC18(obj, func_021DBF40(tab + off), 0, (u16)((idx + 4) << 5), 0, 1, heap);
    *(int *)(p + 0xb68 + idx * 4) = func_0204AF28(obj, func_021DBFE4(tab + off), func_021DC004(tab + off), heap);
    *(int *)(p + 0xb48 + idx * 4) = func_0204A6C8(obj, func_021DBF9C(tab + off), 0, 0, heap);
    dx = 0;
    func_02049238(obj);
    dy = 0;
    func_02082BCC(&pos, 0, 8);
    pos.y = r.h[3];
    pos.flag = 1;
    if (func_021DC024(tab + off) == 2) {
        dx = 4;
        dy = 8;
    }
    if (a)
        pos.x = r.h[2];
    else if (b)
        pos.x = r.h[2] - 0x100;
    else if (b == 0)
        pos.x = r.h[2] + 0x100;
    else
        pos.x = r.h[2];
    pos.x += dx;
    pos.y += dy;
    *(void **)(p + 0xb28 + idx * 4) = func_0204B294(*(void **)(p + 8), *(u32 *)(p + 0xb48 + idx * 4),
        func_021DC024(tab + off) == 1 ? *(u32 *)(p + 0xba8) : *(u32 *)(p + 0xb88 + idx * 4),
        *(u32 *)(p + 0xb68 + idx * 4), &pos, 0, *(u16 *)(p + 0x24));
    func_0204B6F4(*(void **)(p + 0xb28 + idx * 4), (u8)func_021DBF70(tab + off), 0);
    func_0204B3DC(*(void **)(p + 0xb28 + idx * 4), 1);
    if (*(u32 *)(p + 0xae0) && *(u16 *)(p + 0xade) == k) {
        cur.x = src->b[0] * 8 - 0x18;
        cur.y = d_021DF86F[index * 8] * 8 - 8;
        if (a == 0) {
            if (b)
                cur.x -= 0x100;
            else if (b == 0)
                cur.x += 0x100;
        }
        func_0204B404(*(void **)(p + 0xaf0), (const struct Vec2 *)(&cur), 0);
    }
}

#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
