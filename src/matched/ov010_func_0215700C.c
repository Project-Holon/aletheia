/*
 * function: func_0215700C
 * address:  0x0215700C
 * packet:   pkt_ov010_0215700C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct Rec6 {
    u16 id;             /* 0x00 */
    s16 f02;            /* 0x02 */
    u8 f04;             /* 0x04 */
    u8 pad05;
} Rec6;

typedef struct Obj {
    u8 pad00[0x14];
    Rec6 recs[9];       /* 0x14 */
} Obj;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Obj *f04[4];        /* 0x04 */
} Stage;

void func_0215700C(Stage *s, u8 idx, u8 j, u16 id, s16 a, u8 b)
{
    Obj *o;

    o = s->f04[idx];
    o->recs[j].id = id;
    o->recs[j].f02 = a;
    o->recs[j].f04 = b;
}
