/*
 * function: func_02162748
 * address:  0x02162748
 * packet:   pkt_ov010_02162748
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: when idx is below the halfword count at +0x14 and the
 * 0x24-byte record idx in the table at +0x20 has a zero word at +0x18, fills
 * the record: halfword at +0xC, then a sub-record at +0x1C (halfword, halfword,
 * word). The last two arguments are stack arguments (word, halfword).
 *
 * 2026-10-05 note: the guard reads o->tbl[idx].busy and the body takes
 * &o->tbl[idx] again. Taking the pointer once before the guard gives the
 * table load before the 0x24 constant (7 bytes off).
 *
 * Addresses are Black-image addresses.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 h;
    u32 w;
} Sub;

typedef struct {
    u8 pad0[0xC];
    u16 a;
    u8 pad1[0xA];
    u32 busy;
    Sub s;
} Rec;

typedef struct {
    u8 pad0[0x14];
    u16 n;
    u8 pad1[0xA];
    Rec *tbl;
} Own;

void func_02162748(Own *o, u32 idx, u16 a, u16 b, u32 w, u16 h)
{
    if (idx < o->n) {
        if (o->tbl[idx].busy == 0) {
            Rec *r = &o->tbl[idx];
            Sub *s = &r->s;
            r->a = a;
            s->x = b;
            s->w = w;
            s->h = h;
        }
    }
}
