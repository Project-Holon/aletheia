/*
 * function: func_021FF6A4
 * address:  0x021FF6A4
 * packet:   pkt_021FF6A4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FFC18  0x021FFC18  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021FFAEC  0x021FFAEC  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_021F4EA0  0x021F4EA0  thumb
 *   func_0204B454  0x0204B454  arm
 *   tbl_022038A2   0x022038A2  data  a2
 *
 * Create the screen's sprites after loading their graphics
 * (func_021FFC18): the header sprite, seven list sprites placed from the
 * position table with palettes 2..8, the arrow sprite and the page
 * sprite, then record the position of each of the first eight sprites
 * at +0xEC4.
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    s16 x;
    s16 y;
} SPos;

typedef struct {
    u32 f0;
    u8 pad4[0xC];
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Res;

typedef struct {
    u8 pad0[0xBC0];
    Res res;
    u8 padBE8[0xD0C - 0xBE8];
    u32 spr[10];
    u32 arrow;
    u32 page;
    u32 pageNum;
    u8 padD40[0xEC4 - 0xD40];
    SPos pos[8];
} Obj;

extern const Pos tbl_022038A2[];

extern void func_021FFC18(Obj *p);
extern u32 func_0204B294(u32, u32, u32, u32, Local *, u32, u32);
extern void func_0204B92C(u32, int);
extern void func_0204B84C(u32, int);
extern void func_0204B878(u32, u16);
extern void func_0204B3DC(u32, int);
extern void func_021FFAEC(u32 a, u16 b, u16 c);
extern void func_0204B6F4(u32 obj, u32 v, u32 flag);
extern void func_021F4EA0(u32 a, u32 b, u32 c);
extern void func_0204B454(u32 obj, SPos *out, int c);

void func_021FF6A4(Obj *p)
{
    Local s;
    SPos pos;
    int i;

    func_021FFC18(p);
    s.a = 0x80;
    s.b = 0x82;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    p->spr[0] = func_0204B294(p->res.f0, p->res.f1C, p->res.f20, p->res.f24, &s, 1, 0x48);
    func_0204B92C(p->spr[0], 1);
    func_0204B84C(p->spr[0], 2);
    func_0204B878(p->spr[0], 3);
    func_0204B3DC(p->spr[0], 1);
    for (i = 0; i < 7; i++) {
        p->spr[i + 1] = func_0204B294(p->res.f0, p->res.f10, p->res.f14, p->res.f18, &s, 1, 0x48);
        func_0204B92C(p->spr[i + 1], 1);
        func_0204B878(p->spr[i + 1], i * 4 + 0xE);
        func_0204B3DC(p->spr[i + 1], 0);
        func_021FFAEC(p->spr[i + 1], tbl_022038A2[i].x, tbl_022038A2[i].y);
        func_0204B84C(p->spr[i + 1], 2);
        func_0204B6F4(p->spr[i + 1], (u8)(i + 2), 1);
    }
    p->arrow = func_0204B294(p->res.f0, p->res.f10, p->res.f14, p->res.f18, &s, 1, 0x48);
    func_0204B92C(p->arrow, 1);
    func_0204B878(p->arrow, 0x2b);
    func_0204B3DC(p->arrow, 0);
    func_021FFAEC(p->arrow, 0x80, 0x56);
    func_0204B84C(p->arrow, 1);
    p->page = func_0204B294(p->res.f0, p->res.f10, p->res.f14, p->res.f18, &s, 1, 0x48);
    func_0204B92C(p->page, 1);
    func_0204B878(p->page, 0x2a);
    func_021F4EA0(p->page, 0x37, p->pageNum + 0xa8);
    func_0204B3DC(p->page, 0);
    for (i = 0; i < 8; i++) {
        func_0204B454(p->spr[i], &pos, 1);
        p->pos[i].x = pos.x;
        p->pos[i].y = pos.y;
    }
}
