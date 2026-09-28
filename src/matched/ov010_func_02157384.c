/*
 * function: func_02157384
 * address:  0x02157384
 * packet:   pkt_ov010_02157384
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: the byte at +0xF of the 0x2C-byte record that slot i
 * of the index table at +8 selects.
 */

typedef unsigned char u8;

typedef struct Rec2C {
    u8 pad[0xF];
    u8 f0f;
    u8 pad10[0x1C];
} Rec2C;

typedef struct Table {
    u8 pad[8];
    u8 index[4];        /* 0x08 */
    Rec2C *recs;        /* 0x0C */
} Table;

u8 func_02157384(Table *t, int i)
{
    return t->recs[t->index[i]].f0f;
}
