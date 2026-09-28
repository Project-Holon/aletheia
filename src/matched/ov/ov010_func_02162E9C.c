/*
 * function: func_02162E9C
 * address:  0x02162E9C
 * packet:   pkt_ov010_02162E9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Map-cell trigger test: an entry of mode 1 matches the three location
 * halfwords of p.
 */

typedef unsigned short u16;
typedef short s16;

typedef struct TrigCell {
    u16 a;              /* 0x08 */
    u16 b;              /* 0x0A */
    s16 c;              /* 0x0C */
} TrigCell;

typedef struct Trigger {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    TrigCell cell;      /* 0x08 */
} Trigger;

typedef struct CellKey {
    u16 a;              /* 0x00 */
    u16 pad02;
    s16 c;              /* 0x04 */
    u16 b;              /* 0x06 */
} CellKey;

int func_02162E9C(Trigger *t, const CellKey *k)
{
    TrigCell *c;

    if (t->mode == 0)
        return 0;
    c = &t->cell;
    if (c->a == k->a && c->b == k->b && c->c == k->c)
        return 1;
    return 0;
}
