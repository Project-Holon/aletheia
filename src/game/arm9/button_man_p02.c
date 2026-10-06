/*
 * file:     button_man_p02.c
 * unit:     yes
 * function: func_020518AC, func_020519C4, func_020519E4, func_02051A04, func_02051A24
 * address:  0x020518AC
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
 *   func_02057EF8  0x02057EF8  arm
 *   func_02057F8C  0x02057F8C  arm
 *   func_020580A8  0x020580A8  arm
 *   func_02058180  0x02058180  arm
 *   func_02058204  0x02058204  arm
 *   func_020582CC  0x020582CC  arm
 */
#include "../../matched/include/Obj16187.h"
#include "../../matched/include/Obj16190.h"
#include "../../matched/include/Obj16191.h"

struct A;
struct B;
struct C;
struct Obj;
struct S;
struct Src;
typedef unsigned short u16;

struct Ent {
    void *fn;
    void *data;
};

struct Blk {
    char pad[0x18];
    struct Ent *ents;
    u16 count;
};

typedef unsigned char  u8;

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

extern void func_02057EF8(struct A *a, struct B *b);
extern void func_02057F8C(struct A *a, struct S *s, int unused, struct C *c);
extern void func_020580A8(struct Obj *o, u8 *dst);
extern void func_02058180(struct A *a, struct B *b, volatile int *c);
extern void func_02058204(struct Obj *o, struct Src *s, int *dst);
extern void func_020582CC(struct Obj *o, void *s, int *dst);
void *func_020518AC(void *obj, int kind);
void func_020519E4(void *p, u16 *q);
void func_02051A24(void *p, int v);


/*
 * Linear search of the block at obj+0x20 for the first 8-byte entry whose
 * first word is the handler address selected by `kind`, returning that
 * entry's second word (or NULL).  The six handlers are the 3D-rig rows at
 * 0x02057EF8..0x020582CC, all pool words and all attested by the sibling
 * pool at 0x02052DB0.
 *
 * Two tells decide the shape.  Declaring the index BEFORE the count is what
 * puts the count in r4 and the index in lr (declaration-order-decides-which-
 * register-a-local-gets).  And the image's `adds ip, r5, lr, lsl #3` / `beq`
 * pair at +0040 is a redundant null test on the entry pointer: the `adds`
 * form only appears when the source writes `if (e == 0) continue;`, which
 * folds into the address computation.  Without it the switch is four bytes
 * shorter and every branch target shifts.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020518AC.c \
 *       --func func_020518AC --addr 0x020518AC --cc 1.1p1 --arm
 */
void *func_020518AC(void *obj, int kind)
{
    struct Blk *b = *(struct Blk * *)&((struct Obj16187 *)obj)->f20;
    int i;
    int n = b->count;

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++) {
        struct Ent *e = &b->ents[i];
        if (e == 0)
            continue;
        switch (kind) {
        case 0:
            if (e->fn == (void *)func_020582CC)
                return e->data;
            break;
        case 1:
            if (e->fn == (void *)func_02058204)
                return e->data;
            break;
        case 2:
            if (e->fn == (void *)func_02058180)
                return e->data;
            break;
        case 3:
            if (e->fn == (void *)func_020580A8)
                return e->data;
            break;
        case 4:
            if (e->fn == (void *)func_02057F8C)
                return e->data;
            break;
        case 5:
            if (e->fn == (void *)func_02057EF8)
                return e->data;
            break;
        default:
            return 0;
        }
    }
    return 0;
}


/*
 * Copies a 12-byte record into the slot func_020518AC hands back for class 2.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020519C4.c \
 *       --func func_020519C4 --addr 0x020519C4 --cc 1.1p1 --arm
 */
void func_020519C4(void *p, struct S12 *q)
{
    struct S12 *r = func_020518AC(p, 2);

    if (r != 0)
        *r = *q;
}


/*
 * The class-3 slot carries only a halfword at +2.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020519E4.c \
 *       --func func_020519E4 --addr 0x020519E4 --cc 1.1p1 --arm
 */
void func_020519E4(void *p, u16 *q)
{
    char *r = func_020518AC(p, 3);

    if (r != 0)
        ((struct Obj16190 *)r)->f2 = *q;
}


/*
 * Same 12-byte copy as func_020519C4, out of the class-5 slot.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051A04.c \
 *       --func func_02051A04 --addr 0x02051A04 --cc 1.1p1 --arm
 */
void func_02051A04(void *p, struct S12 *q)
{
    struct S12 *r = func_020518AC(p, 5);

    if (r != 0)
        *r = *q;
}


/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x90/4] = v`. With func_02051A2C (the +0x94 twin) it is the storage
 * setter pair the ov118 functions func_021D6EAC/func_021D6F0C call.
 *
 * Addresses are Black-image addresses.
 */
void func_02051A24(void *p, int v)
{
    ((struct Obj16191 *)p)->f90 = v;
}
