/*
 * file:     eventdata_system_p14.c
 * unit:     yes
 * function: func_02162958, func_02162970, func_02162A54, func_02162A5C, func_02162A64, func_02162A6C
 * address:  0x02162958
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021628E4 0x021628E4 thumb ov010
 *   func_02162E48  0x02162E48  thumb  ov010
 *   func_02162E9C  0x02162E9C  thumb  ov010
 *   func_02164708  0x02164708  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 *   func_02162CE8  0x02162CE8  thumb  ov010
 *   func_02162ECC  0x02162ECC  thumb  ov010
 */
struct Ctx;
struct Rec;
struct CellKey;
struct VecFx32;
struct TriggerSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef int s32;

typedef struct Trigger {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    s32 data[3];        /* 0x08 */
} Trigger;

typedef struct TriggerSet {
    u8 pad00[0x12];
    u16 count;          /* 0x12 */
    u8 pad14[8];
    Trigger *list;      /* 0x1C */
} TriggerSet;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern struct Rec *func_021628E4(struct Ctx *c, void *a, int key);
extern int func_02162E48(struct Trigger *t, const struct VecFx32 *pos);
extern int func_02162E9C(struct Trigger *t, const struct CellKey *k);
extern u16 func_02164708(u16 id);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_02162CE8(const void *p, V3 *out);
extern void func_02162ECC(const char *p, int *out);
u16 func_02162958(void *c, void *a, int key);
u16 func_02162970(TriggerSet *set, void *flags, const void *where, u16 type);
u16 func_02162A54(void *set, void *flags, const void *where, u16 type);
u16 func_02162A5C(void *set, void *flags, const void *where, u16 type);
void func_02162A64(const void *p, V3 *out);
void func_02162A6C(int a, int b);

u16 func_02162958(void *c, void *a, int key)
{
    u16 *r = (u16 *)func_021628E4(c, a, key);
    if (r != 0) return *r;
    return 0xffff;
}


/*
 * Finds the trigger that fires at a place: walks the 0x14-byte entries,
 * tests position (mode 0) or map cell (mode 1), then filters by entry
 * kind against the facing/type argument. Answers the entry id or 0xFFFF.
 *
 * Levers (2026-09-28 tree_ov010_4): one guarded body (single 0xFFFF
 * exit), the count held in a u32 local (a u16 local is re-read from its
 * spill slot before the guard), and case 5 as `type == 2 || type == 3`,
 * which 1.1p1 folds to a loop-hoisted `(u16)(type + 0xFFFE) <= 1`
 * (`(u16)(type - 2) <= 1` gives `subs #2` instead).
 */
u16 func_02162970(TriggerSet *set, void *flags, const void *where, u16 type)
{
    Trigger *t;
    u16 i;
    u32 count;

    t = set->list;
    if (t != 0) {
    count = set->count;
    for (i = 0; i < count; i++, t++) {
        if (t->mode == 0) {
            if (!func_02162E48(t, where))
                continue;
        } else {
            if (!func_02162E9C(t, where))
                continue;
        }
        if (t->kind2 == 2) {
            if (func_020142E8(flags, func_02164708(t->id)) == 0)
                return t->id;
            continue;
        }
        switch (t->kind) {
        case 0:
            if (type == 0)
                return t->id;
            break;
        case 1:
            if (type == 3)
                return t->id;
            break;
        case 2:
            if (type == 2)
                return t->id;
            break;
        case 3:
            if (type == 1)
                return t->id;
            break;
        case 4:
            return t->id;
        case 5:
            if (type == 2 || type == 3)
                return t->id;
            break;
        case 6:
            if (type <= 1)
                return t->id;
            break;
        }
    }
    }
    return 0xFFFF;
}


/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_02189BD0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A54(void *set, void *flags, const void *where, u16 type)
{
    return func_02162970(set, flags, where, type);
}


/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_0218A278.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A5C(void *set, void *flags, const void *where, u16 type)
{
    return func_02162970(set, flags, where, type);
}


/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162CE8.  Blocker of ov061 func_021F388C.
 */
void func_02162A64(const void *p, V3 *out)
{
    func_02162CE8(p, out);
}


/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162ECC.  Blocker of ov021 func_021AFDAC.
 */
void func_02162A6C(int a, int b)
{
    func_02162ECC((const char *)a, (int *)b);
}
