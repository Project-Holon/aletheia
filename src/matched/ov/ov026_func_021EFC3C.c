/*
 * function: func_021EFC3C
 * address:  0x021EFC3C
 * packet:   pkt_ov026_021EFC3C
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The handed 644-byte extent is 152 bytes of code; the unlabelled leaf
 * func_021EFCD4 and ov026 data follow. The tail entry must be spelled
 * `p->ent[i].field` (a `u16 *q = p + i * 12` cursor, as in the loop of the
 * twin func_021EFBA4, gives 62 bytes out: the image indexes +0xC from a
 * separate p+0xC base and re-adds p + i*12 per store).
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   d_021EFD1C     0x021EFD1C  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    s16 d;
    s16 e;
    u16 f;
} Ent;

typedef struct {
    u8 state;
    u8 mode;
    u16 x2;
    u16 count;
    u16 cur;
    Ent ent[4];
} Obj;

extern u32 func_020056EC(u32 v);
extern u8 d_021EFD1C[];

void func_021EFC3C(Obj *p)
{
    int i;

    p->x2 = 2;
    p->count = func_020056EC(2) + 1;
    i = 0;
    p->count = p->count + 1;
    for (; i < p->count - 1; i++) {
        p->ent[i].c = func_020056EC(3) + 0x12;
        p->ent[i].a = 4;
        p->ent[i].b = 8;
        p->ent[i].d = func_020056EC(4);
        p->ent[i].e = 10;
        p->ent[i].f = 0x693;
    }
    p->ent[i].c = func_020056EC(1) + 0x1E;
    p->ent[i].a = 4;
    p->ent[i].b = d_021EFD1C[p->ent[i].c];
    p->ent[i].d = func_020056EC(300) + 0xF0;
    p->ent[i].e = 10;
    p->ent[i].f = 0x692;
}
