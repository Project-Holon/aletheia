/*
 * function: FIELD_COMM_ACTOR_CTRL_GetMmdl
 * address:  0x021943EC
 * packet:   pkt_ov021_021943EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf (push {r4, r5} saves no lr): finds the record whose
 * key equals the argument among n 12-byte records and returns its +8 field,
 * or 0. Sole blocker of ov010 COMM_PLAYER_SetEffect's callee relocation.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Rec {
    u32 key;
    u32 f4;
    u32 val;
} Rec;

typedef struct Tbl {
    u16 n;
    u16 pad;
    u32 f4;
    Rec *recs;
} Tbl;

u32 FIELD_COMM_ACTOR_CTRL_GetMmdl(Tbl *t, u32 key)
{
    u16 i;
    Rec *r;
    u16 n;

    n = t->n;
    i = 0;
    r = t->recs;
    for (; i < n; i++, r++) {
        if (r->val != 0 && r->key == key)
            return r->val;
    }
    return 0;
}
