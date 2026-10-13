/*
 * unit:     yes
 * function: NNS_G3dMdlSetMdlLightEnableFlag
 * address:  0x0206E394
 * packet:   pkt_0206E394
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A family of five near-identical bitfield setters over the same inlined
 * two-step resolve: root -> bank (relative offset at +0x08), bank -> entry
 * (indexed table at bank+4+off0A, element stride read as a u16 at that same
 * address), entry -> node (relative offset at entry+0). The five differ only
 * in which field of node->attr0C they clear and set:
 *   NNS_G3dMdlSetMdlLightEnableFlag  bits 0..3     (mask 0x0000000f, shift 0)
 *   NNS_G3dMdlSetMdlPolygonMode  bits 4..5     (mask 0x00000030, shift 4)
 *   NNS_G3dMdlSetMdlCullMode  bits 6..7     (mask 0x000000c0, shift 6)
 *   NNS_G3dMdlSetMdlPolygonID  bits 24..29   (mask 0x3f000000, shift 24)
 *   NNS_G3dMdlSetMdlAlpha  bits 16..20   (mask 0x001f0000, shift 16)
 * NNS_G3dMdlSetMdlPolygonIDAll (already EXACT, next packet boundary) loops NNS_G3dMdlSetMdlPolygonID.
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

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u8 unk00[4]; u8 unk04; u8 count05; u8 unk06[4]; u16 off0A; } Bank;
typedef struct { u32 unk00; u32 unk04; u32 off08; } Root;
typedef struct { u32 rel00; } Ent;
typedef struct { u32 unk00[3]; u32 attr0C; } Node;

void NNS_G3dMdlSetMdlLightEnableFlag(Root *r, u32 idx, u32 v)
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

void NNS_G3dMdlSetMdlPolygonMode(Root *r, u32 idx, u32 v)
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

void NNS_G3dMdlSetMdlCullMode(Root *r, u32 idx, u32 v)
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

void NNS_G3dMdlSetMdlPolygonID(Root *r, u32 idx, u32 v)
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

void NNS_G3dMdlSetMdlAlpha(Root *r, u32 idx, u32 v)
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

