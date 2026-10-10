/*
 * file:     button_man_p04.c
 * unit:     yes
 * function: func_02057EF8, func_02057F8C, func_020580A8, func_02058180, func_02058204, func_020582CC, func_02058300, func_02058380, func_020583CC
 * address:  0x02057EF8
 * region:   arm9
 * compiler: dsi/../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A1B38     0x020A1B38  data
 *   func_0207AF00  0x0207AF00  thumb
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_0207AF38  0x0207AF38  thumb
 *   func_0207B51C  0x0207B51C  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   g_02146A8C     0x02146A8C  data
 */
struct Node;
struct List {
    volatile struct Node *head;
    int count;
    volatile struct Node *tail;
};

struct Node {
    volatile struct Node *next;
    volatile struct Node *prev;
};

struct Node_02058380 {
    struct Node_02058380 * volatile next;
    struct Node_02058380 *prev;
};

struct List_02058380 {
    struct Node_02058380 * volatile head;
    volatile int count;
    struct Node_02058380 * volatile tail;
};

struct Node_02057EF8 {
    struct Node_02057EF8 *next;
    struct Node_02057EF8 *prev;
};

struct List_02057EF8 {
    struct Node_02057EF8 * volatile head;
    int count;
    struct Node_02057EF8 *tail;
};

typedef signed short s16;

struct Obj {
    s16 v0;
    s16 v1;
    s16 v2;
};

typedef unsigned short u16;

typedef unsigned int u32;

struct Obj_02058204 {
    s16 v0;
    s16 v1;
    s16 v2;
    u16 f06;
};

struct Src {
    char _00[0x26];
    u16 f26;
};

struct A {
    int x;
    int y;
    int z;
    s16 scale;
};

struct B_02058180 {
    int pad_00[2];
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
};

typedef unsigned char u8;

struct Obj_02057EF8 {
    u16 f00;
    u16 f02;
};

struct A_02057F8C {
    int target;
    s16 f04;
    u16 mode : 2;
    u16 rest : 14;
};

struct C {
    char _00[0x74];
    int f74;
};

struct S {
    char _00[0xc];
    int c;
    char _10[8];
    int f18;
    char _1c[8];
    u16 f24;
    u16 f26;
    char _28[0x14];
    int f3c;
};

typedef int fx32;

typedef long long fx64;

struct A_02057EF8 {
    fx32 x;
    fx32 y;
    fx32 z;
    short w;
};

struct B_02057EF8 {
    fx32 _00;
    fx32 _04;
    fx32 _08;
    fx32 _0C;
    fx32 _10;
};

extern void func_0207AF00(u8 *buf, int a, int b);
extern void func_0207AF1C(u8 *buf, int a, int b);
extern void func_0207AF38(u8 *buf, int a, int b);
extern void func_0207B51C(u8 *a, u8 *b, u8 *c);
void func_020583CC(volatile struct List *list, volatile struct Node *node);
struct Node_02058380 *func_02058380(struct List_02058380 *list);
struct Node_02057EF8 *func_02058300(struct List_02057EF8 *list, struct Node_02057EF8 *node);
void func_020582CC(struct Obj *o, void *s, int *dst);
void func_02058204(struct Obj_02058204 *o, struct Src *s, int *dst);
void func_02058180(struct A *a, struct B_02058180 *b, volatile int *c);
void func_020580A8(struct Obj_02057EF8 *o, u8 *dst);
void func_02057F8C(struct A_02057F8C *a, struct S *s, int unused, struct C *c);
void func_02057EF8(struct A_02057EF8 *a, struct B_02057EF8 *b);
extern s16 g_020A1B38[];


void func_020583CC(volatile struct List *list, volatile struct Node *node)
{
    volatile struct Node *head;

    head = list->head;
    if (head == 0) {
        list->head = node;
        list->tail = node;
        node->next = 0;
        node->prev = node->next;
    } else {
        node->next = head;
        node->prev = 0;
        list->head->prev = node;
        list->head = node;
    }
    list->count++;
}



struct Node_02058380 *func_02058380(struct List_02058380 *list)
{
    struct Node_02058380 *ret;
    struct Node_02058380 *head;

    ret = 0;
    head = list->head;
    if (head != 0) {
        ret = head;
        list->head = head->next;
        if (list->head != 0) {
            head->next->prev = 0;
        } else {
            list->head = 0;
            list->tail = 0;
        }
        list->count--;
    }
    return ret;
}




struct Node_02057EF8 *func_02058300(struct List_02057EF8 *list, struct Node_02057EF8 *node)
{
    struct Node_02057EF8 *next;

    next = node->next;
    if (next == 0) {
        if (list->head == node) {
            list->head = 0;
            list->tail = 0;
        } else {
            node->prev->next = 0;
            list->tail = list->tail->prev;
        }
    } else {
        if (list->head == node) {
            list->head = next;
            list->head->prev = 0;
        } else {
            next->prev = node->prev;
            node->prev->next = node->next;
        }
    }
    list->count--;
    return node;
}





/*
 * Handler row 0 of the 3D-rig table searched by func_020518AC: adds the three
 * s16 components of o to dst[0..2].  Same compiler as its sibling
 * func_02058204 (1.1p1 merges the first two loads into an ldm).  The middle
 * argument is unused but kept for the handler signature func_02058204 has.
 */
void func_020582CC(struct Obj *o, void *s, int *dst)
{
    dst[0] = dst[0] + o->v0;
    dst[1] = dst[1] + o->v1;
    dst[2] = dst[2] + o->v2;
}






u32 g_02146A8C;






/*
 * note:     EXACT* because the follower at 0x020582C0 is an unlabelled leaf run
 *           (its own literal pool); every byte of the 188-byte function plus the
 *           pool at 0x020582C0 compares identical.
 */
void func_02058204(struct Obj_02058204 *o, struct Src *s, int *dst)
{
    int r;

    if (s->f26 % o->f06 != 0) {
        return;
    }

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[0] = dst[0] + ((o->v0 * r - (o->v0 << 8)) >> 8);

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[1] = dst[1] + ((o->v1 * r - (o->v1 << 8)) >> 8);

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[2] = dst[2] + ((o->v2 * r - (o->v2 << 8)) >> 8);
}







void func_02058180(struct A *a, struct B_02058180 *b, volatile int *c)
{
    c[0] = c[0] + (a->scale * (a->x - b->f08 - b->f14) >> 12);
    c[1] = c[1] + (a->scale * (a->y - b->f0c - b->f18) >> 12);
    c[2] = c[2] + (a->scale * (a->z - b->f10 - b->f1c) >> 12);
}








/*
 * wave r8 lane rigD: first compile, EXACT under ../1.2/sp2 -proc arm946e.
 * The r6 note called this row "untouched" and predicted five label-class
 * relocation sites; all five resolve (four branch, one literal), and the
 * shared table is one symbol for all three cases.
 *
 * The two spellings that matter:
 *  - the three cases are identical apart from the callee, so each arm
 *    re-reads `idx = o->f00 >> 4;` (hoisting it above the switch costs the
 *    asr slot).
 *  - the subscripts are `idx * 2` and `idx * 2 + 1`, not `idx`/`idx + 1`:
 *    both address the same halfwords, but the image forms the byte offsets
 *    from `lsl r2, r1, #1` + `add r1, r2, #1` + two `lsl #1`s, which is the
 *    `idx * 2` spelling (the `idx`/`idx + 1` spelling is 12 bytes short).
 */
void func_020580A8(struct Obj_02057EF8 *o, u8 *dst)
{
    u8 buf[0x28];
    int idx;

    switch (o->f02) {
    case 0:
        idx = o->f00 >> 4;
        func_0207AF00(buf, g_020A1B38[idx * 2], g_020A1B38[idx * 2 + 1]);
        break;
    case 1:
        idx = o->f00 >> 4;
        func_0207AF1C(buf, g_020A1B38[idx * 2], g_020A1B38[idx * 2 + 1]);
        break;
    case 2:
        idx = o->f00 >> 4;
        func_0207AF38(buf, g_020A1B38[idx * 2], g_020A1B38[idx * 2 + 1]);
        break;
    }

    func_0207B51C(dst + 8, buf, dst + 8);
}









/*
 * wave r8 lane rigD: the wave r6 DIFF at this address is closed.  The two
 * levers the r6 note asked for are both real and both necessary:
 *
 *  - the mode dispatch is a `switch` on a 2-bit bitfield member, not an
 *    if/else-if chain: `sw` puts BOTH case tests before the default `bx lr`
 *    and the two bodies after it, which is the 284-byte layout (the
 *    if/else-if spelling hoists case 0's body to the first test and comes
 *    out 260 bytes).
 *  - the mode-1 clamp is the 64-bit `(s64)x * y + 0x800 >> 12` form, not the
 *    32-bit one: 32-bit gives `mul/add/asr` (4 instructions, 260 bytes),
 *    the `long long` form gives the image's `smull/adc/lsr/orr` quartet with
 *    the pooled `mov r0, #0x800` in the middle.
 *
 * The arm shape the r6 note arrived at is also exact as written: the inner
 * `return` sits INSIDE the inner `if` (predicated `bxgt lr` in mode 0, a
 * `ble <tail>` out-of-line clamp in mode 1), and the redundant
 * `if (v < target) return;` after it is what makes the shared tail block
 * exist at all.
 */
void func_02057F8C(struct A_02057F8C *a, struct S *s, int unused, struct C *c)
{
    int target;
    int v;

    target = a->target;
    if (c->f74 != 0x80000000) target = c->f74;

    switch (a->mode) {
    case 0:
        v = s->f3c;
        if (v < target) {
            if (v + s->c > target) {
                s->c = target - v;
                s->f26 = s->f24;
                return;
            }
        }
        if (v < target) return;
        if (v + s->c < target) {
            s->c = target - v;
            s->f26 = s->f24;
        }
        return;
    case 1:
        v = s->f3c;
        if (v < target) {
            if (v + s->c > target) {
                s->c = target - v;
                s->f18 = -(int)(((long long)s->f18 * a->f04 + 0x800) >> 12);
                return;
            }
        }
        if (v < target) return;
        if (v + s->c < target) {
            s->c = target - v;
            s->f18 = -(int)(((long long)s->f18 * a->f04 + 0x800) >> 12);
        }
        return;
    }
}









static inline fx32 FX_Mul(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800) >> 12);
}









void func_02057EF8(struct A_02057EF8 *a, struct B_02057EF8 *b)
{
    b->_08 = b->_08 + FX_Mul(a->w, a->x - b->_08);
    b->_0C = b->_0C + FX_Mul(a->w, a->y - b->_0C);
    b->_10 = b->_10 + FX_Mul(a->w, a->z - b->_10);
}
