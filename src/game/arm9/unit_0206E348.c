/*
 * file:     unit_0206E348.c
 * unit:     yes
 * function: func_0206E348, func_0206E358, func_0206E364, func_0206E388, func_0206E394, func_0206E5EC
 * address:  0x0206E348
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
 *   func_02069C14    0x02069C14  arm
 *   func_02061330    0x02061330  arm
 */
struct Obj02061330;
struct Node;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { u8 unk00[4]; u8 unk04; u8 count05; u8 unk06[4]; u16 off0A; } Bank;

typedef struct { u32 unk00; u32 unk04; u32 off08; u8 unk0C[0xC]; u8 count18; } Root;

typedef struct { u32 rel00; } Ent;

typedef struct { u32 unk00[3]; u32 attr0C; } Node;

extern void func_02061330(struct Obj02061330 *o, u32 x);
extern void func_02061344(struct Obj02061330 *o, u32 x);
extern u32 func_02069C14(const u8 *tag, const struct Node *n);
void func_0206E348(int a0, int a1, int a2, int a3);
void func_0206E358(struct Obj02061330 *ctx, int field);
void func_0206E364(u32 a, u32 b, u32 c);
void func_0206E388(struct Obj02061330 *ctx, int field);
void func_0206E394(Root *r, u32 idx, u32 v);
void func_0206E40C(Root *r, u32 idx, u32 v);
void func_0206E484(Root *r, u32 idx, u32 v);
void func_0206E4FC(Root *r, u32 idx, u32 v);
void func_0206E574(Root *r, u32 idx, u32 v);
void func_0206E5EC(Root *p, u32 a);

void func_0206E348(int a0, int a1, int a2, int a3){ func_02061330((struct Obj02061330 *)((int)a0), (int)0x54); }

void func_0206E358(struct Obj02061330 *ctx, int field){ func_02061344(ctx, field); }

/*
 * Forwards the two tail arguments through func_02069C14 and hands the result,
 * with the first argument, to func_02061330 -- the argument shuffle is why the
 * first parameter moves into r4 before either call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E364.c \
 *       --func func_0206E364 --addr 0x0206E364 --cc 1.1p1 --arm
 */
void func_0206E364(u32 a, u32 b, u32 c)
{
    func_02061330((struct Obj02061330 *)a, func_02069C14((const u8 *)b, (const struct Node *)c));
}

void func_0206E388(struct Obj02061330 *ctx, int field){ func_02061344(ctx, field); }

/*
 * A family of five near-identical bitfield setters over the same inlined
 * two-step resolve: root -> bank (relative offset at +0x08), bank -> entry
 * (indexed table at bank+4+off0A, element stride read as a u16 at that same
 * address), entry -> node (relative offset at entry+0). The five differ only
 * in which field of node->attr0C they clear and set:
 *   func_0206E394  bits 0..3     (mask 0x0000000f, shift 0)
 *   func_0206E40C  bits 4..5     (mask 0x00000030, shift 4)
 *   func_0206E484  bits 6..7     (mask 0x000000c0, shift 6)
 *   func_0206E4FC  bits 24..29   (mask 0x3f000000, shift 24)
 *   func_0206E574  bits 16..20   (mask 0x001f0000, shift 16)
 * func_0206E5EC (already EXACT, next packet boundary) loops func_0206E4FC.
 *
 * Two shape notes that cost the derivation real time:
 *  - Every NULL arm shares ONE tail (`n = 0` at the very end), so each early
 *    bail has to be a `goto` to that block; writing them as nested else arms
 *    predicates `moveq r1,#0` at the top instead of branching to +0x60.
 *  - The resolved entry pointer is carried in the `idx` PARAMETER's register
 *    (r1), not in a fresh local: declaring a separate `Ent *e` allocates r0
 *    and flips `mla r1,r0,r1,r3` to `mla r0,r1,r0,r3`. Reassigning `idx`
 *    itself is what reproduces the original register choice.
 *
 * No proc hint for this packet; compiled with the default arm946e. No
 * interworking-conflict or constant-materialisation tell was observed, so
 * docs/FRONTEND-PINS.md does not apply here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0206E394.c \
 *       --addr 0x0206E394 --arm
 */
void func_0206E394(Root *r, u32 idx, u32 v)
{
    Bank *b;
    Node *n;
    u8 *base;

    b = (r != 0 && r->off08 != 0) ? (Bank *)((u8 *)r + r->off08) : 0;
    if (b == 0) goto none;
    base = (u8 *)b + 4;
    if (base == 0) goto nullent;
    if (idx >= b->count05) goto nullent;
    idx = (u32)(base + b->off0A + 4 + (*(u16 *)(base + b->off0A)) * idx);
    goto have;
nullent:
    idx = 0;
have:
    if (idx == 0) goto none;
    n = (Node *)((u8 *)b + ((Ent *)idx)->rel00);
    goto set;
none:
    n = 0;
set:
    n->attr0C = (n->attr0C & ~0xf) | v;
}

/*
 * A family of five near-identical bitfield setters over the same inlined
 * two-step resolve: root -> bank (relative offset at +0x08), bank -> entry
 * (indexed table at bank+4+off0A, element stride read as a u16 at that same
 * address), entry -> node (relative offset at entry+0). The five differ only
 * in which field of node->attr0C they clear and set:
 *   func_0206E394  bits 0..3     (mask 0x0000000f, shift 0)
 *   func_0206E40C  bits 4..5     (mask 0x00000030, shift 4)
 *   func_0206E484  bits 6..7     (mask 0x000000c0, shift 6)
 *   func_0206E4FC  bits 24..29   (mask 0x3f000000, shift 24)
 *   func_0206E574  bits 16..20   (mask 0x001f0000, shift 16)
 * func_0206E5EC (already EXACT, next packet boundary) loops func_0206E4FC.
 *
 * Two shape notes that cost the derivation real time:
 *  - Every NULL arm shares ONE tail (`n = 0` at the very end), so each early
 *    bail has to be a `goto` to that block; writing them as nested else arms
 *    predicates `moveq r1,#0` at the top instead of branching to +0x60.
 *  - The resolved entry pointer is carried in the `idx` PARAMETER's register
 *    (r1), not in a fresh local: declaring a separate `Ent *e` allocates r0
 *    and flips `mla r1,r0,r1,r3` to `mla r0,r1,r0,r3`. Reassigning `idx`
 *    itself is what reproduces the original register choice.
 *
 * No proc hint for this packet; compiled with the default arm946e. No
 * interworking-conflict or constant-materialisation tell was observed, so
 * docs/FRONTEND-PINS.md does not apply here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0206E394.c \
 *       --addr 0x0206E394 --arm
 */
void func_0206E40C(Root *r, u32 idx, u32 v)
{
    Bank *b;
    Node *n;
    u8 *base;

    b = (r != 0 && r->off08 != 0) ? (Bank *)((u8 *)r + r->off08) : 0;
    if (b == 0) goto none;
    base = (u8 *)b + 4;
    if (base == 0) goto nullent;
    if (idx >= b->count05) goto nullent;
    idx = (u32)(base + b->off0A + 4 + (*(u16 *)(base + b->off0A)) * idx);
    goto have;
nullent:
    idx = 0;
have:
    if (idx == 0) goto none;
    n = (Node *)((u8 *)b + ((Ent *)idx)->rel00);
    goto set;
none:
    n = 0;
set:
    n->attr0C = (n->attr0C & ~0x30) | (v << 4);
}

/*
 * A family of five near-identical bitfield setters over the same inlined
 * two-step resolve: root -> bank (relative offset at +0x08), bank -> entry
 * (indexed table at bank+4+off0A, element stride read as a u16 at that same
 * address), entry -> node (relative offset at entry+0). The five differ only
 * in which field of node->attr0C they clear and set:
 *   func_0206E394  bits 0..3     (mask 0x0000000f, shift 0)
 *   func_0206E40C  bits 4..5     (mask 0x00000030, shift 4)
 *   func_0206E484  bits 6..7     (mask 0x000000c0, shift 6)
 *   func_0206E4FC  bits 24..29   (mask 0x3f000000, shift 24)
 *   func_0206E574  bits 16..20   (mask 0x001f0000, shift 16)
 * func_0206E5EC (already EXACT, next packet boundary) loops func_0206E4FC.
 *
 * Two shape notes that cost the derivation real time:
 *  - Every NULL arm shares ONE tail (`n = 0` at the very end), so each early
 *    bail has to be a `goto` to that block; writing them as nested else arms
 *    predicates `moveq r1,#0` at the top instead of branching to +0x60.
 *  - The resolved entry pointer is carried in the `idx` PARAMETER's register
 *    (r1), not in a fresh local: declaring a separate `Ent *e` allocates r0
 *    and flips `mla r1,r0,r1,r3` to `mla r0,r1,r0,r3`. Reassigning `idx`
 *    itself is what reproduces the original register choice.
 *
 * No proc hint for this packet; compiled with the default arm946e. No
 * interworking-conflict or constant-materialisation tell was observed, so
 * docs/FRONTEND-PINS.md does not apply here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0206E394.c \
 *       --addr 0x0206E394 --arm
 */
void func_0206E484(Root *r, u32 idx, u32 v)
{
    Bank *b;
    Node *n;
    u8 *base;

    b = (r != 0 && r->off08 != 0) ? (Bank *)((u8 *)r + r->off08) : 0;
    if (b == 0) goto none;
    base = (u8 *)b + 4;
    if (base == 0) goto nullent;
    if (idx >= b->count05) goto nullent;
    idx = (u32)(base + b->off0A + 4 + (*(u16 *)(base + b->off0A)) * idx);
    goto have;
nullent:
    idx = 0;
have:
    if (idx == 0) goto none;
    n = (Node *)((u8 *)b + ((Ent *)idx)->rel00);
    goto set;
none:
    n = 0;
set:
    n->attr0C = (n->attr0C & ~0xc0) | (v << 6);
}

/*
 * A family of five near-identical bitfield setters over the same inlined
 * two-step resolve: root -> bank (relative offset at +0x08), bank -> entry
 * (indexed table at bank+4+off0A, element stride read as a u16 at that same
 * address), entry -> node (relative offset at entry+0). The five differ only
 * in which field of node->attr0C they clear and set:
 *   func_0206E394  bits 0..3     (mask 0x0000000f, shift 0)
 *   func_0206E40C  bits 4..5     (mask 0x00000030, shift 4)
 *   func_0206E484  bits 6..7     (mask 0x000000c0, shift 6)
 *   func_0206E4FC  bits 24..29   (mask 0x3f000000, shift 24)
 *   func_0206E574  bits 16..20   (mask 0x001f0000, shift 16)
 * func_0206E5EC (already EXACT, next packet boundary) loops func_0206E4FC.
 *
 * Two shape notes that cost the derivation real time:
 *  - Every NULL arm shares ONE tail (`n = 0` at the very end), so each early
 *    bail has to be a `goto` to that block; writing them as nested else arms
 *    predicates `moveq r1,#0` at the top instead of branching to +0x60.
 *  - The resolved entry pointer is carried in the `idx` PARAMETER's register
 *    (r1), not in a fresh local: declaring a separate `Ent *e` allocates r0
 *    and flips `mla r1,r0,r1,r3` to `mla r0,r1,r0,r3`. Reassigning `idx`
 *    itself is what reproduces the original register choice.
 *
 * No proc hint for this packet; compiled with the default arm946e. No
 * interworking-conflict or constant-materialisation tell was observed, so
 * docs/FRONTEND-PINS.md does not apply here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0206E394.c \
 *       --addr 0x0206E394 --arm
 */
void func_0206E4FC(Root *r, u32 idx, u32 v)
{
    Bank *b;
    Node *n;
    u8 *base;

    b = (r != 0 && r->off08 != 0) ? (Bank *)((u8 *)r + r->off08) : 0;
    if (b == 0) goto none;
    base = (u8 *)b + 4;
    if (base == 0) goto nullent;
    if (idx >= b->count05) goto nullent;
    idx = (u32)(base + b->off0A + 4 + (*(u16 *)(base + b->off0A)) * idx);
    goto have;
nullent:
    idx = 0;
have:
    if (idx == 0) goto none;
    n = (Node *)((u8 *)b + ((Ent *)idx)->rel00);
    goto set;
none:
    n = 0;
set:
    n->attr0C = (n->attr0C & ~0x3f000000) | (v << 24);
}

/*
 * A family of five near-identical bitfield setters over the same inlined
 * two-step resolve: root -> bank (relative offset at +0x08), bank -> entry
 * (indexed table at bank+4+off0A, element stride read as a u16 at that same
 * address), entry -> node (relative offset at entry+0). The five differ only
 * in which field of node->attr0C they clear and set:
 *   func_0206E394  bits 0..3     (mask 0x0000000f, shift 0)
 *   func_0206E40C  bits 4..5     (mask 0x00000030, shift 4)
 *   func_0206E484  bits 6..7     (mask 0x000000c0, shift 6)
 *   func_0206E4FC  bits 24..29   (mask 0x3f000000, shift 24)
 *   func_0206E574  bits 16..20   (mask 0x001f0000, shift 16)
 * func_0206E5EC (already EXACT, next packet boundary) loops func_0206E4FC.
 *
 * Two shape notes that cost the derivation real time:
 *  - Every NULL arm shares ONE tail (`n = 0` at the very end), so each early
 *    bail has to be a `goto` to that block; writing them as nested else arms
 *    predicates `moveq r1,#0` at the top instead of branching to +0x60.
 *  - The resolved entry pointer is carried in the `idx` PARAMETER's register
 *    (r1), not in a fresh local: declaring a separate `Ent *e` allocates r0
 *    and flips `mla r1,r0,r1,r3` to `mla r0,r1,r0,r3`. Reassigning `idx`
 *    itself is what reproduces the original register choice.
 *
 * No proc hint for this packet; compiled with the default arm946e. No
 * interworking-conflict or constant-materialisation tell was observed, so
 * docs/FRONTEND-PINS.md does not apply here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0206E394.c \
 *       --addr 0x0206E394 --arm
 */
void func_0206E574(Root *r, u32 idx, u32 v)
{
    Bank *b;
    Node *n;
    u8 *base;

    b = (r != 0 && r->off08 != 0) ? (Bank *)((u8 *)r + r->off08) : 0;
    if (b == 0) goto none;
    base = (u8 *)b + 4;
    if (base == 0) goto nullent;
    if (idx >= b->count05) goto nullent;
    idx = (u32)(base + b->off0A + 4 + (*(u16 *)(base + b->off0A)) * idx);
    goto have;
nullent:
    idx = 0;
have:
    if (idx == 0) goto none;
    n = (Node *)((u8 *)b + ((Ent *)idx)->rel00);
    goto set;
none:
    n = 0;
set:
    n->attr0C = (n->attr0C & ~0x1f0000) | (v << 16);
}

/*
 * Walks the count byte at +0x18, calling func_0206E4FC with the counter and the
 * caller's second argument; the counter is zeroed before the entry test (which
 * is why the original's `mov r4, #0` precedes `cmp`/`popls`) and the count is
 * re-read from memory every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E5EC.c \
 *       --func func_0206E5EC --addr 0x0206E5EC --cc 1.1p1 --arm
 */
void func_0206E5EC(Root *p, u32 a)
{
    u32 i = 0;

    for (i = 0; i < p->count18; i++) {
        func_0206E4FC(p, i, a);
    }
}
