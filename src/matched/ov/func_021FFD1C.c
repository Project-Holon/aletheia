/*
 * function: func_021FFD1C
 * address:  0x021FFD1C
 * packet:   pkt_021FFD1C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFAEC  0x021FFAEC  thumb
 *   tbl_022038A2   0x022038A2  data  a2
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[0xD34];
    u32 spr;
} Obj;

extern const Pos tbl_022038A2[];

extern void func_021FFAEC(u32 a, u16 b, int c);

void func_021FFD1C(Obj *p, int i, int dy)
{
    func_021FFAEC(p->spr, tbl_022038A2[i].x, dy + (tbl_022038A2[i].y + 0x20));
}
