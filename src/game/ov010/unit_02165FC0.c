/*
 * file:     unit_02165FC0.c
 * unit:     yes
 * function: func_02165FC0, func_02165FCC, func_02166164, func_02166168, func_02166180, func_02166198, func_0216619C, func_021661B4, func_021661CC, func_021661EC, func_02166200, func_02166218, func_02166230, func_02166248, func_0216625C, func_0216626C, func_0216627C, func_0216628C
 * address:  0x02165FC0
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
 *   d_02171CE8  0x02171CE8  data  a1
 *   func_0201F31C  0x0201F31C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201EF4C  0x0201EF4C  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F104  0x0201F104  thumb
 *   func_0201F134  0x0201F134  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0201F1E0  0x0201F1E0  thumb
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165D8C  0x02165D8C  thumb  ov010
 *   func_02165E24  0x02165E24  thumb  ov010
 *   func_02165E34  0x02165E34  thumb  ov010
 *   func_02165E78  0x02165E78  thumb  ov010
 *   func_02165E8C  0x02165E8C  thumb  ov010
 *   func_02165E9C  0x02165E9C  thumb  ov010
 *   func_02165EAC  0x02165EAC  thumb  ov010
 *   func_02165ECC  0x02165ECC  thumb  ov010
 *   func_02165F30  0x02165F30  thumb  ov010
 *   func_02165F64  0x02165F64  thumb  ov010
 *   func_02165F74  0x02165F74  thumb  ov010
 *   func_02165F84  0x02165F84  thumb  ov010
 *   func_02165F94  0x02165F94  thumb  ov010
 *   func_02165FA4  0x02165FA4  thumb  ov010
 *   func_02165FB4  0x02165FB4  thumb  ov010
 *   func_0200E184  0x0200E184  thumb
 *   func_0200E164  0x0200E164  thumb
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E27C  0x0200E27C  thumb
 *   func_0200E024  0x0200E024  thumb
 *   func_0200E18C  0x0200E18C  thumb
 */
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef struct Row {
    u8 a;
    u8 b;
} Row;

typedef struct Rec_02165FCC Rec_02165FCC;

typedef signed int     s32;

typedef struct Rec_02166164 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166164;

typedef struct RecW {
    u8 pad00[0x34];
    u32 f34;            /* 0x34 */
} RecW;

typedef struct RecB {
    u8 pad00[0x34];
    u8 f34;             /* 0x34 */
} RecB;

typedef struct Rec_02166168 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166168;

typedef struct Rec_02166180 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166180;

typedef struct Rec_02166198 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166198;

typedef struct Rec_0216619C {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_0216619C;

typedef struct Rec_021661B4 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_021661B4;

typedef struct Rec_021661CC {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_021661CC;

typedef struct Rec_021661EC {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_021661EC;

typedef struct Rec_02166200 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166200;

typedef struct Rec_02166218 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166218;

typedef struct Rec_02166230 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166230;

typedef struct Rec_02166248 {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02166248;

typedef struct Rec_0216625C {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_0216625C;

typedef struct Rec_0216626C {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_0216626C;

typedef struct Rec_0216627C {
    u8 pad00[0xC];
    u32 pad0c : 16;
    u32 a : 10;
    u32 b : 6;
    u8 pad10[0x32 - 0x10];
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_0216627C;

typedef struct {
    u32 w;
} W;

extern void func_0201F31C(struct WordSet *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF4C(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F104(struct WordSet *p, u32 i, u32 a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern void func_0201F1E0(struct WordSet *p, u32 i, u32 v);
extern void func_02165C34(struct Rec_02165FCC *r, void *buf);
extern u8 func_02165D08(struct Rec_02165FCC *r);
extern int func_02165D8C(int a0, int a1);
extern u16 func_02165E24(Rec_02165FCC *r);
extern u16 func_02165E34(struct Rec_02165FCC *r);
extern u16 func_02165E78(struct Rec_02165FCC *r);
extern u16 func_02165E8C(struct Rec_02165FCC *r);
extern u16 func_02165E9C(struct Rec_02165FCC *r);
extern u16 func_02165EAC(struct Rec_02165FCC *r);
extern void func_02165ECC(struct Rec_02165FCC *r, void *buf);
extern u16 func_02165F30(struct Rec_02165FCC *r);
extern u32 func_02165F64(struct Rec_02165FCC *r);
extern u16 func_02165F74(struct Rec_02165FCC *r);
extern u32 func_02165F84(struct Rec_02165FCC *r);
extern u8 func_02165F94(struct Rec_02165FCC *r);
extern u16 func_02165FA4(struct Rec_02165FCC *r);
extern u8 func_02165FB4(u16 type);
extern u32 func_0200E184(u32 slot);
extern u32 func_0200E164(u32 *obj, u32 kind);
extern void func_0200E06C(char *p);
extern void func_0200E27C(u8 *obj, int idx);
extern void func_0200E024(void *obj);
extern void func_0200E18C(u32 *obj, u32 slot);
u8 func_02165FC0(u32 type);
void func_02165FCC(Rec_02165FCC *r, void *win, u32 heap);
int func_02166164(Rec_02166164 *r);
int func_02166168(Rec_02166168 *r);
int func_02166180(Rec_02166180 *r);
int func_02166198(Rec_02166198 *r);
int func_0216619C(Rec_0216619C *r);
int func_021661B4(Rec_021661B4 *r);
int func_021661CC(Rec_021661CC *r);
int func_021661EC(RecW *r);
int func_02166200(Rec_02166200 *r);
int func_02166218(Rec_02166218 *r);
int func_02166230(Rec_02166230 *r);
int func_02166248(RecW *r);
int func_0216625C(RecB *r);
int func_0216626C(Rec_0216626C *r);
int func_0216627C(Rec_0216627C *r);
int func_0216628C(u32 *obj, u32 slot);
extern const Row d_02171CE8[];


/*
 * Second byte of the two-byte table row for a record type.
 */
u8 func_02165FC0(u32 type)
{
    return d_02171CE8[type].b;
}


/*
 * Print a record into a text window: its name into slot 0, then the
 * type-specific value (number, string or item) into slots 1 and 2.
 */
void func_02165FCC(Rec_02165FCC *r, void *win, u32 heap)
{
    void *str;
    u8 kind;
    u32 v;

    func_0201F31C(win);
    str = func_020457B0(0x21, heap);
    if (str == 0)
        return;
    func_02165C34(r, str);
    func_0201EE0C(win, 0, str, 0, 1, 2);
    kind = func_02165FB4(func_02165E24(r));
    switch (kind) {
    case 1:
        v = func_02165F30(r);
        func_0201F104(win, 1, v);
        func_0201F134(win, 2, v);
        break;
    case 2:
    case 4:
        func_0201EE60(win, 1, func_02165E34(r));
        if (kind == 2)
            break;
    case 3:
        func_02165ECC(r, str);
        func_0201EE0C(win, 2, str, 0, 1, 2);
        break;
    case 5:
        func_0201EF4C(win, 1, func_02165E78(r));
        break;
    case 6:
        func_0201EFA4(win, 1, func_02165F74(r), 3, 0, 1);
        break;
    case 7:
        func_0201EFA4(win, 1, func_02165F64(r), 3, 0, 1);
        break;
    case 8:
        func_0201EE60(win, 1, func_02165E9C(r));
        break;
    case 9:
        func_0201EF40(win, 1, func_02165EAC(r));
        break;
    case 10:
        func_0201EF34(win, 1, func_02165E8C(r));
        break;
    case 11:
        func_0201EFA4(win, 1, func_02165F84(r), 1, 0, 1);
        break;
    case 12:
        func_0201F1E0(win, 1, func_02165F94(r));
        break;
    case 13:
        func_0201F184(win, 1, func_02165FA4(r));
        break;
    case 14:
        func_02165D8C((int)r, (int)str);
        func_0201EE0C(win, 1, str, func_02165D08(r), 1, 2);
        break;
    case 15:
        break;
    }
    func_02045808(str);
}


/*
 * Record field validator: returns 1 when the field is out of range.
 */
int func_02166164(Rec_02166164 *r)
{
    return 0;
}


int func_02166168(Rec_02166168 *r)
{
    if (r->f34 == 0 || r->f34 >= 0x268)
        return 1;
    return 0;
}


int func_02166180(Rec_02166180 *r)
{
    if (r->f32 == 0 || r->f32 > 0x289)
        return 1;
    return 0;
}


int func_02166198(Rec_02166198 *r)
{
    return 0;
}


int func_0216619C(Rec_0216619C *r)
{
    if (r->f32 == 0 || r->f32 > 0x289)
        return 1;
    return 0;
}


int func_021661B4(Rec_021661B4 *r)
{
    if (r->f34 == 0 || r->f34 > 0x272)
        return 1;
    return 0;
}


int func_021661CC(Rec_021661CC *r)
{
    if (r->a > 999 || r->b > 59)
        return 1;
    return 0;
}


int func_021661EC(RecW *r)
{
    if (r->f34 > 99999)
        return 1;
    return 0;
}


int func_02166200(Rec_02166200 *r)
{
    if (r->f34 == 0 || r->f34 > 0x289)
        return 1;
    return 0;
}


int func_02166218(Rec_02166218 *r)
{
    if (r->f36 == 0 || r->f36 > 0x272)
        return 1;
    return 0;
}


int func_02166230(Rec_02166230 *r)
{
    if (r->f34 == 0 || r->f34 >= 0x230)
        return 1;
    return 0;
}


int func_02166248(RecW *r)
{
    if (r->f34 == 0 || r->f34 > 7)
        return 1;
    return 0;
}


int func_0216625C(RecB *r)
{
    if (r->f34 > 6)
        return 1;
    return 0;
}


int func_0216626C(Rec_0216626C *r)
{
    if (r->f34 >= 0x30)
        return 1;
    return 0;
}


int func_0216627C(Rec_0216627C *r)
{
    if (r->f38 >= 0x30)
        return 1;
    return 0;
}


/*
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 *
 * Maps the slot's kind (0..3, via the 0x0200E184 thunk) to a new kind,
 * asks func_0200E164 for a free slot, and moves the word at obj[slot]
 * there; kind 3 also runs func_0200E27C on it. Returns 0 on failure.
 *
 * 2026-10-05 (P25L5): all 128 bytes match. The word move is a one-word
 * struct copy (W, lever "one-word structs for word copies"); the plain
 * u32 copy gave 8 bytes off (cmp r5,#3 after the str, dst*4 in r0).
 * Only blocker: func_0200E184 is a Thumb veneer (ldr r3,[pc]; bx r3) to
 * the real function at 0x0200E0BC (44 bytes, maps a value to 0..3 by a
 * 4-entry threshold table). It has no witness outside this function, so
 * the relocation stays unresolved. No C can express the veneer; the
 * integrator should seed a label or witness for 0x0200E184.
 * Tried and inert (8 bytes off): raw byte offsets, u16 dst (31 off),
 * const callee proto, u8 obj, u8 kind, inline copy helper, byte offset
 * locals, per-arm store (45 off), each pragma (scheduling, peephole,
 * opt_propagation, opt_common_subs, opt_lifetimes, opt_dead_assignments).
 */
int func_0216628C(u32 *obj, u32 slot)
{
    u32 kind;
    u32 dst;

    switch (func_0200E184(slot)) {
    case 0:
        kind = 2;
        break;
    case 1:
        kind = 3;
        break;
    case 2:
        kind = 0;
        break;
    case 3:
        kind = 1;
        break;
    default:
        return 0;
    }
    dst = func_0200E164(obj, kind);
    if (dst == 0xFFFF)
        return 0;
    func_0200E06C((char *)obj);
    ((W *)obj)[dst] = ((W *)obj)[slot];
    if (kind == 3)
        func_0200E27C((u8 *)obj, (u16)dst);
    func_0200E024(obj);
    func_0200E18C(obj, slot);
    return 1;
}
