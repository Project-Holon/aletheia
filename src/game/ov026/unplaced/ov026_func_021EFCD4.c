/*
 * function: func_021EFCD4
 * address:  0x021EFCD4
 * packet:   pkt_ov026_021EFCD4
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (saves no lr), called from func_021EF9D8's state 4.
 * Reads the current entry's +0xC halfword (the entries are the 12-byte
 * records func_021EFBA4 fills from +8).
 */

typedef unsigned short u16;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    short d;
    short e;
    u16 f;
} Ent;

typedef struct {
    unsigned char state;
    unsigned char mode;
    u16 x2;
    u16 count;
    u16 cur;
    Ent ent[4];
} Obj;

u16 func_021EFCD4(Obj *p)
{
    u16 v;

    v = p->ent[p->cur].c;
    return v | (v << 5) | 0x2000;
}
