/*
 * function: func_0206EBB8
 * address:  0x0206EBB8
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md).
 * The image keeps `tst r1, #1` at 0x0206EC18 and `beq 0x0206EC30` at
 * 0x0206EC1C over the four-instruction guard body at 0x0206EC20..0x0206EC2C
 * (`ldr r1,[r0]` / `orr r1,r1,#4` / `str r1,[r0]` / `bx lr`); dsi/1.1p1
 * -O4,p predicates it to ldrne/orrne/strne/bxne, giving 148 bytes against
 * the original's 152. Under ../2.0/sp2 the same C is 152 bytes, 0 mismatches.
 *
 * symbols:
 *   g_02148DB0      0x02148DB0  data
 *
 * Same inlined two-step resolve as src/matched/unit_0206E394.c, but over the
 * global stash at 0x02148DB0: root -> bank (+0xD4), bank -> entry (indexed
 * table at bank+6), entry -> node (relative offset at entry+0).
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct { u8 unk00; u8 idx01; } Hdr;
typedef struct { u8 unk00; u8 cnt01; u8 unk02[4]; u16 off06; } Bank;
typedef struct { Hdr *h; u8 pad[0xD0]; Bank *bank; } Root;
typedef struct { u16 flags; u32 f04; u32 f08; u32 f0C; } Node;
typedef struct { u32 rel00; } Ent;

extern Root *g_02148DB0;

void func_0206EBB8(u32 *out)
{
    Root *r = g_02148DB0;
    Bank *b;
    Node *n;
    u8 *t;
    u32 idx;

    idx = r->h->idx01;
    b = r->bank;
    if (b == 0) goto none;
    if (b == 0) goto nullent;
    if (idx >= b->cnt01) goto nullent;
    t = (u8 *)b + b->off06;
    idx = (u32)(t + 4 + (*(u16 *)t) * idx);
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
    if ((n->flags & 1) != 0) {
        out[0] |= 4;
        return;
    }
    out[0x13] = n->f04;
    out[0x14] = n->f08;
    out[0x15] = n->f0C;
}
