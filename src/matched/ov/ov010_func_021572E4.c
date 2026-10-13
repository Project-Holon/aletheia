/*
 * function: MUSICAL_PROGRAM_CreateNpcPerformer
 * address:  0x021572E4
 * packet:   pkt_ov010_021572E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The stage slot b is a u8 (as wide as either callee's parameter); a u32
 * or int b is reloaded from its spill one instruction early. The u32 is
 * spelled out in the call, not through an inline reader, so the top byte is
 * loaded once and kept in ip for the fourth argument.
 *
 * symbols:
 *   MUSICAL_STAGE_SYS_CreateNpcPerformer  0x02156FD0  thumb  ov010
 *   MUSICAL_STAGE_SYS_SetPerformerProp  0x0215700C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Move {
    u16 id;             /* 0x00 */
    u8 f02;             /* 0x02 */
    u8 pad03;
} Move;

typedef struct Ent {
    u16 f00;            /* 0x00 */
    u8 f02[4];          /* 0x02 */
    u16 f06;            /* 0x06 */
    u8 pad08[4];
    Move moves[8];      /* 0x0C */
} Ent;

typedef struct Tbl {
    u8 pad00[0x0C];
    Ent ents[1];        /* 0x0C */
} Tbl;

typedef struct Deal {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
    Tbl *f0C;           /* 0x0C */
} Deal;

typedef signed short   s16;
struct Stage;
extern void MUSICAL_STAGE_SYS_CreateNpcPerformer(struct Stage *s, u8 idx, u16 id, u8 v, u32 w, u16 x, u16 y);
extern void MUSICAL_STAGE_SYS_SetPerformerProp(struct Stage *s, u8 idx, u8 j, u16 id, s16 a, u8 b);

void MUSICAL_PROGRAM_CreateNpcPerformer(Deal *d, void *a, u8 b, u8 slot, u16 y)
{
    Ent *e;
    u8 j;

    e = &d->f0C->ents[d->f08[slot]];
    MUSICAL_STAGE_SYS_CreateNpcPerformer(a, b, e->f00, e->f02[3], e->f02[0] + (e->f02[1] << 8) + (e->f02[2] << 16) + (e->f02[3] << 24), e->f06, y);
    for (j = 0; j < 8; j++) {
        if (e->moves[j].id != 0x1FE && e->moves[j].id != 0x1FF)
            MUSICAL_STAGE_SYS_SetPerformerProp(a, b, e->moves[j].f02, e->moves[j].id, 0, j);
    }
}
