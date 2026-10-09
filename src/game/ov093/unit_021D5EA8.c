/*
 * file:     unit_021D5EA8.c
 * unit:     yes
 * function: func_021D5EA8, func_021D5EFC, func_021D5F08, func_021D5F14, func_021D5F38, func_021D5F90, func_021D5FA4, func_021D5FB8, func_021D5FC0, func_021D5FE4, func_021D6008, func_021D6034, func_021D6064, func_021D6130, func_021D61A8, func_021D61F0, func_021D621C, func_021D6238, func_021D6264, func_021D62A8, func_021D62C4, func_021D62D8, func_021D6314, func_021D631C, func_021D6324, func_021D63B8, func_021D63EC, func_021D6408, func_021D6440, func_021D646C, func_021D64F0, func_021D6580, func_021D65C8
 * address:  0x021D5EA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One file again: the five parts are merged around one union Slot and one
 * struct UtilSlots built by offset from every old view.
 *
 * symbols:
 *   func_021D53DC  0x021D53DC  thumb  ov093
 *   func_021D53C8  0x021D53C8  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D7D6C  0x021D7D6C  thumb  ov093
 *   func_021E8AFC  0x021E8AFC  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021E8918  0x021E8918  thumb  ov093
 *   func_021D5750  0x021D5750  thumb  ov093
 *   func_021E8928  0x021E8928  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_02082BCC  0x02082BCC  arm
 *   func_021D67F4  0x021D67F4  thumb  ov093
 *   func_021D6824  0x021D6824  thumb  ov093
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_021D533C  0x021D533C  thumb  ov093
 *   func_021D5150  0x021D5150  thumb  ov093
 *   func_021D5364  0x021D5364  thumb  ov093
 *   func_021D539C  0x021D539C  thumb  ov093
 *   func_021D6E88  0x021D6E88  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021D53C0  0x021D53C0  thumb  ov093
 *   func_021D4EFC  0x021D4EFC  thumb  ov093
 *   func_021D66A0  0x021D66A0  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D5970  0x021D5970  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

union Slot {
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};

struct UtilEntry {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    u8 f8;
    u8 f9;
    u16 fA;
    u8 fC;
    u8 fD;
};

struct Byte7 { u8 v[7]; };

struct UtilSlots {
    void *w;
    u8 pad4[0x12];
    u16 f16;
    u8 pad18[3];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
    u8 f1b_b6 : 1;
    u8 f1b_b7 : 1;
    union Slot e[36];
    u8 b[36];
    u8 padD0[0x2c];
    struct Byte7 fc;
    u8 pad103[1];
    struct UtilEntry ent[4];
    u16 f13C;
    u8 pad13E[2];
    u8 f140;
    u8 f141;
    u8 f142;
    u8 pad143[1];
    u8 f144;
    u8 pad145[1];
    u16 f146;
    u16 f148;
    u16 f14A;
    u16 f14C;
    u16 f14E;
    u8 pad150[3];
    u8 bits153[2];
    u8 bits155[2];
    u8 f157[5];
    u8 pad15C[0x96];
    u16 f1f2;
};

struct Unk021D5FA4 { u8 pad[0xE]; u16 fE; u16 f10; };

typedef enum { SLOT_FIRST, SLOT_LIMIT=36, SLOT_UNSIGNED=0xFFFFFFFF } SlotIndex;

extern int func_021D53DC(signed char *p);
extern void func_021D53C8(unsigned char *p);
extern int func_021D5BDC(struct UtilSlots *, unsigned int);
extern int func_021D7D6C(int);
extern u8 func_021E8AFC(union Slot);
extern u16 func_021E8B80(union Slot);
extern union Slot func_021E8918(void);
extern int func_021D5750(struct UtilSlots *p, u16 id);
extern int func_021E8928(union Slot s);
extern int func_021E8A98(union Slot s);
extern int func_021E8A78(union Slot s);
extern int func_021D7B74(struct UtilSlots *p, u32 k);
extern void func_02082BCC(void *, int, u32);
extern void func_021D67F4(struct UtilSlots *);
extern void func_021D6824(struct UtilSlots *);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020185C4(void *p);
extern void func_021D533C(struct UtilSlots *p);
extern void func_021D5150(struct UtilSlots *p);
extern void func_021D5364(struct UtilSlots *p);
extern void func_021D539C(struct UtilSlots *p);
extern void func_021D6E88(struct UtilSlots *p);
extern void func_021D6C2C(struct UtilSlots *p);
extern void func_021D6D70(struct UtilSlots *p);
extern void func_021D53C0(unsigned char *p);
extern void func_021D4EFC(struct UtilSlots *a, void *mon, u32 c, u32 d);
extern int func_021D66A0(u32);
extern int func_021D58A8(struct UtilSlots *, int);
extern void func_021D5970(struct UtilSlots *, int, u16);

void func_021D5EA8(struct UtilSlots *p, int i, u8 n);
int func_021D5EFC(struct UtilSlots *p);
void func_021D5F08(struct UtilSlots *p);
u8 func_021D5F14(struct UtilSlots *p);
int func_021D5F38(struct UtilSlots *p, int n);
void func_021D5F90(struct Unk021D5FA4 *p, u16 n);
void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
void func_021D5FB8(struct Unk021D5FA4 *p);
void func_021D5FC0(struct UtilSlots *p, u32 n);
void func_021D5FE4(struct UtilSlots *p, unsigned int n);
void func_021D6008(struct UtilSlots *p, unsigned int n);
void func_021D6034(struct UtilSlots *p, int k, union Slot v);
int func_021D6064(struct UtilSlots *p, u32 k, union Slot *out, int *changed);
int func_021D6130(struct UtilSlots *p);
int func_021D61A8(struct UtilSlots *p);
void func_021D61F0(struct UtilSlots *p);
void func_021D621C(struct UtilSlots *p, int k);
void func_021D6238(struct UtilSlots *p, int k);
void func_021D6264(struct UtilSlots *p, int v);
int func_021D62A8(struct UtilSlots *p);
int func_021D62C4(struct UtilSlots *p, int i);
u16 func_021D62D8(struct UtilSlots *p, int i);
u32 func_021D6314(struct UtilSlots *p, int i);
u8 func_021D631C(struct UtilSlots *p, int i);
int func_021D6324(struct UtilSlots *p, int k);
void func_021D63B8(struct UtilSlots *p, int all);
void func_021D63EC(struct UtilSlots *p, u16 n);
void func_021D6408(struct UtilSlots *p);
void func_021D6440(struct UtilSlots *p, u32 n);
void func_021D646C(struct UtilSlots *p);
void func_021D64F0(struct UtilSlots *p);
void func_021D6580(struct UtilSlots *p);
void func_021D65C8(struct UtilSlots *p, struct UtilSlots *q);


void func_021D5EA8(struct UtilSlots *p, int i, u8 n)
{
    u8 *q;
    switch (i) {
    case 1: q = &p->fc.v[0]; break;
    case 2: q = &p->fc.v[1]; break;
    case 3: q = &p->fc.v[2]; break;
    case 4: q = &p->fc.v[3]; break;
    case 5: q = &p->fc.v[4]; break;
    case 6: q = &p->fc.v[5]; break;
    case 7: q = &p->fc.v[6]; break;
    default: return;
    }
    if (n <= 12) q[0] = n;
}

/*
 * note: unblocked when src/matched/func_021D53DC.c was filed EXACT; the
 * relocation now attests as `matched` (ov093) with no C change.
 */
int func_021D5EFC(struct UtilSlots *p)
{
    return func_021D53DC((signed char *)p->fc.v);
}

/*
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 */
void func_021D5F08(struct UtilSlots *p)
{
    func_021D53C8((unsigned char *)p->fc.v);
}

u8 func_021D5F14(struct UtilSlots *p)
{
    u8 n;
    n = p->f142;
    if (func_021D5BDC(p, 9)) {
        n += 2;
        if (n > 4) n = 4;
    }
    return n;
}

/*
 * Lever: the clamp at the bottom stores the field in each arm
 * (`if (p->f > k) p->f = p->f - (u8)k; else p->f = 0;`). A local `v` assigned in the arms
 * and stored once, or a ternary, keeps k out of r4 (no push {r3,r4}; 8 bytes short).
 * `n * 0xffffffff` keeps the mvns/muls (a-multiply-by-minus-one-is-strength-reduced-but-by-0xffffffff-is-not.md).
 */
int func_021D5F38(struct UtilSlots *p, int n)
{
    int k;

    if (n > 0) {
        if (p->f142 < 4) {
            p->f142 = p->f142 + (u8)n;
            if (p->f142 > 4) p->f142 = 4;
            return 1;
        }
    } else {
        k = n * 0xffffffff;
        if (p->f142 != 0) {
            if (p->f142 > k) p->f142 = p->f142 - (u8)k; else p->f142 = 0;
            return 1;
        }
    }
    return 0;
}

/*
 * extent: final two bytes are zero alignment padding.
 * lever: plain subtraction avoids compound-assignment operand narrowing.
 */
void func_021D5F90(struct Unk021D5FA4 *p, u16 n)
{
    if (p->f10 > n) {
        p->f10 = p->f10 - n;
        return;
    }
    p->f10 = 0;
}

void func_021D5FA4(struct Unk021D5FA4 *p, u16 n)
{
    p->f10 += n;
    if (p->f10 > p->fE) p->f10 = p->fE;
}

/*
 * store constant 0x0 at #0x10
 */
void func_021D5FB8(struct Unk021D5FA4 *p)
{
    p->f10 = 0x0;
}

void func_021D5FC0(struct UtilSlots *p, u32 n)
{
    p->bits153[(u8)(n >> 3)] |= (u8)(1 << (n & 7));
}

/*
 * lever: index the offset base (p + 0x155), preserving its separate add.
 */
void func_021D5FE4(struct UtilSlots *p, unsigned int n)
{
    p->bits155[(u8)(n >> 3)] |= (u8)(1 << (n & 7));
}

void func_021D6008(struct UtilSlots *p, unsigned int n)
{
    p->bits155[(u8)(n >> 3)] &= (u8)~(u8)(1 << (n & 7));
}

void func_021D6034(struct UtilSlots *p, int k, union Slot v)
{
    if (func_021D7D6C(k)) func_021D61F0(p);
    p->e[(u32)k] = v;
    p->b[(u32)k] = 0;
}

/*
 * extent: two bytes of zero alignment padding at 0x021D612E.
 */
int func_021D6064(struct UtilSlots *p, u32 k, union Slot *out, int *changed)
{
    u8 max;
    union Slot slot;
    u32 tmp;
    if (k == 2 || k == 6) return 0;
    if (p->e[k].s.kind != 0) {
        max = func_021E8AFC(p->e[k]);
        slot = p->e[k];
        if (out != 0) *out = slot;
        if (changed != 0) *changed = 0;
        if (k == 27 && func_021D5750(p, func_021E8B80(slot)) == 0) {
            p->e[k] = func_021E8918();
            p->b[k] = 0;
            if (changed != 0) *changed = 1;
        }
        if (max != 0) {
            p->b[k]++;
            if (p->b[k] >= max) {
                p->e[k] = func_021E8918();
                p->b[k] = 0;
                if (changed != 0) *changed = 1;
            }
        } else if (p->e[k].s.kind == 1 && p->e[k].s.lo != 0) {
            tmp = k;
            if (p->b[k] < p->e[tmp].s.lo) p->b[k]++;
        }
        return 1;
    }
    return 0;
}

int func_021D6130(struct UtilSlots *p)
{
    union Slot *s = &p->e[2];
    u8 max;
    int f;
    int inc;
    if (s->s.kind != 0) {
        max = func_021E8AFC(*s);
        if (max != 0) {
            f = func_021D62C4(p, 0x10) ? 0 : (p->f13C == 0x30);
            inc = 2;
            if (f == 0) inc = 1;
            p->b[2] += (u8)inc;
            if (p->b[2] >= max) {
                *s = func_021E8918();
                func_021D6238(p, 2);
                return 1;
            }
        }
    }
    return 0;
}

int func_021D61A8(struct UtilSlots *p)
{
    union Slot *s = &p->e[6];
    u8 max;
    if (s->s.kind != 0) {
        max = func_021E8AFC(*s);
        if (max != 0) {
            p->b[6]++;
            if (p->b[6] >= max) {
                *s = func_021E8918();
                func_021D6238(p, 6);
                return 1;
            }
        }
    }
    return 0;
}

void func_021D61F0(struct UtilSlots *p)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        p->e[i] = func_021E8918();
        p->b[i] = 0;
        func_021D621C(p, i);
    }
}

void func_021D621C(struct UtilSlots *p, int k)
{
    if (k == 2) {
        p->e[9] = func_021E8918();
        p->b[9] = 0;
    }
}

void func_021D6238(struct UtilSlots *p, int k)
{
    if (func_021D7D6C(k) != 0) {
        func_021D61F0(p);
        return;
    }
    p->e[k] = func_021E8918();
    p->b[k] = 0;
}

void func_021D6264(struct UtilSlots *p, int v)
{
    u32 i;
    if (v != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            if (func_021E8928(p->e[i]) == 0 && v == func_021E8A98(p->e[i])) {
                p->e[i] = func_021E8918();
                func_021D621C(p, i);
            }
        }
    }
}

int func_021D62A8(struct UtilSlots *p)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        if (p->e[i].s.kind) return i;
    }
    return 0;
}

int func_021D62C4(struct UtilSlots *p, int i)
{
    if (p->e[i].s.kind) return 1;
    return 0;
}

u16 func_021D62D8(struct UtilSlots *p, int i)
{
    switch (p->e[i].s.kind) {
    case 2: return p->e[i].w.v;
    case 3: return p->e[i].s.lo;
    case 4: return p->e[i].s.hi;
    }
    return 0;
}

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: lsls r1, r1, #2; adds r0, r0, r1; ldr r0, [r0, #0x1c]; bx lr.
 */
u32 func_021D6314(struct UtilSlots *p, int i) { return p->e[i].raw; }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0xac; ldrb r0, [r0]; bx lr.
 */
u8 func_021D631C(struct UtilSlots *p, int i) { return p->b[i]; }

int func_021D6324(struct UtilSlots *p, int k)
{
    if (func_021D62C4(p, k) != 0) {
        switch (k) {
        case 5:
            if (func_021E8A78(p->e[k]) != 0)
                return func_021D7B74(p, 0x10) * p->b[k];
            return func_021D7B74(p, 8);
        case 4:
            return func_021D7B74(p, 8);
        case 9:
            if (func_021D62C4(p, 2) != 0)
                return func_021D7B74(p, 4);
            break;
        case 10:
            return func_021D7B74(p, 4);
        default:
            return 0;
        }
    }
    return 0;
}

/*
 * lever: enum loop counter with unsigned bound retains the entry guard;
 *   word-array indexing settles zero/offset scratch register allocation.
 */
void func_021D63B8(struct UtilSlots *p, int all)
{
    SlotIndex i;
    i = 0;
    if (all == 0) i = 6;
    for (; i < 36U; i++) {
        p->e[i].raw = 0;
        p->e[i].s.kind = 0;
    }
    func_02082BCC(p->b, 0, 36);
}

void func_021D63EC(struct UtilSlots *p, u16 n)
{
    p->f148 = n;
    p->f146 = 0;
    p->f1b_b7 = 1;
    func_021D67F4(p);
}

/*
 * volatile: halfword at +0x146 re-read at 021D641C and 021D6428.
 */
void func_021D6408(struct UtilSlots *p)
{
    func_02082BCC(p->bits153, 0, 2);
    if (*(volatile u16 *)&p->f146 < 9999)
        *(volatile u16 *)&p->f146 += 1;
    func_021D6824(p);
}

void func_021D6440(struct UtilSlots *p, u32 n)
{
    u8 *q;
    u8 i;
    u8 bit;
    q = p->bits153;
    i = n >> 3;
    bit = 1 << (n & 7);
    q[i] &= (u8)~bit;
}

void func_021D646C(struct UtilSlots *p)
{
    func_02082BCC(p->bits153, 0, 2);
    func_02082BCC(p->bits155, 0, 2);
    func_021D533C(p);
    func_021D5150(p);
    func_021D5364(p);
    func_021D539C(p);
    func_021D6E88(p);
    func_021D6C2C(p);
    func_021D6D70(p);
    func_021D63B8(p, 1);
    func_021D53C0(p->fc.v);
    p->f141 = p->f1b_lo;
    p->f13C = p->f16;
    func_02017E40(p->w, 0x6f, p->f141);
    func_020185C4(p->w);
}

void func_021D64F0(struct UtilSlots *p)
{
    func_02082BCC(p->bits153, 0, 2);
    func_021D533C(p);
    func_021D5150(p);
    func_021D5364(p);
    func_021D539C(p);
    func_021D6E88(p);
    func_021D6C2C(p);
    if (func_021D5BDC(p, 0xe) == 0) {
        func_021D6D70(p);
        func_021D63B8(p, 0);
        func_021D53C0(p->fc.v);
        func_02082BCC(p->bits155, 0, 2);
    }
    p->f141 = p->f1b_lo;
    p->f13C = p->f16;
    func_02017E40(p->w, 0x6f, p->f141);
    func_020185C4(p->w);
}

void func_021D6580(struct UtilSlots *p)
{
    func_021D4EFC(p, p->w, 0, 1);
    func_02082BCC(p->bits155, 0, 2);
    func_02082BCC(p->bits153, 0, 2);
    func_021D6D70(p);
    func_021D5364(p);
    func_021D63B8(p, 0);
    func_021D53C0(p->fc.v);
}

void func_021D65C8(struct UtilSlots *p, struct UtilSlots *q)
{
    unsigned long i;
    u16 t;
    u16 t2;
    p->fc = q->fc;
    p->f1f2 = q->f1f2;
    for (i = 0; i < 36; i++) {
        if (q->e[i].s.kind != 0 && func_021D66A0(i)) {
            p->e[i] = q->e[i];
            p->b[i] = q->b[i];
        }
    }
    if (func_021D5BDC(q, 10)) {
        func_021D5FE4(p, 10);
        t = func_021D58A8(p, 8);
        t2 = func_021D58A8(p, 9);
        func_021D5970(p, 8, t2);
        func_021D5970(p, 9, t);
    }
    if (func_021D5BDC(q, 9)) func_021D5FE4(p, 9);
    func_021D6D70(q);
    func_021D63B8(q, 0);
    func_021D53C0(q->fc.v);
    func_02082BCC(q->bits155, 0, 2);
}
