/*
 * function: WORLDTRADE_SUBLCD_CreateActors
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
 *   WORLDTRADE_SUBLCD_LoadPalette  0x021FFC18  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   WORLDTRADE_SUBLCD_SetActorSurfacePos  0x021FFAEC  thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   WORLDTRADE_SetActorSurfacePos  0x021F4EA0  thumb
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   tbl_022038A2   0x022038A2  data  a2
 *
 * Create the screen's sprites after loading their graphics
 * (WORLDTRADE_SUBLCD_LoadPalette): the header sprite, seven list sprites placed from the
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

extern void WORLDTRADE_SUBLCD_LoadPalette(Obj *p);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorBgPriority(u32, int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void WORLDTRADE_SUBLCD_SetActorSurfacePos(u32 a, int b, int c);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void WORLDTRADE_SetActorSurfacePos(u32 a, u32 b, u32 c);
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

void WORLDTRADE_SUBLCD_CreateActors(Obj *p)
{
    Local s;
    SPos pos;
    int i;

    WORLDTRADE_SUBLCD_LoadPalette(p);
    s.a = 0x80;
    s.b = 0x82;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    p->spr[0] = (u32)CLACT_CreateActor((void *)p->res.f0, p->res.f1C, p->res.f20, p->res.f24, &s, 1, 0x48);
    CLACT_SetActorAutoAnim((struct Obj *)p->spr[0], 1);
    CLACT_SetActorBgPriority(p->spr[0], 2);
    CLACT_SetActorAnimSeq((struct Obj *)p->spr[0], 3);
    CLACT_SetActorDrawEnable((struct Obj *)p->spr[0], 1);
    for (i = 0; i < 7; i++) {
        p->spr[i + 1] = (u32)CLACT_CreateActor((void *)p->res.f0, p->res.f10, p->res.f14, p->res.f18, &s, 1, 0x48);
        CLACT_SetActorAutoAnim((struct Obj *)p->spr[i + 1], 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->spr[i + 1], i * 4 + 0xE);
        CLACT_SetActorDrawEnable((struct Obj *)p->spr[i + 1], 0);
        WORLDTRADE_SUBLCD_SetActorSurfacePos(p->spr[i + 1], tbl_022038A2[i].x, tbl_022038A2[i].y);
        CLACT_SetActorBgPriority(p->spr[i + 1], 2);
        CLACT_SetActorPaletteOffset((struct Obj *)p->spr[i + 1], (u8)(i + 2), 1);
    }
    p->arrow = (u32)CLACT_CreateActor((void *)p->res.f0, p->res.f10, p->res.f14, p->res.f18, &s, 1, 0x48);
    CLACT_SetActorAutoAnim((struct Obj *)p->arrow, 1);
    CLACT_SetActorAnimSeq((struct Obj *)p->arrow, 0x2b);
    CLACT_SetActorDrawEnable((struct Obj *)p->arrow, 0);
    WORLDTRADE_SUBLCD_SetActorSurfacePos(p->arrow, 0x80, 0x56);
    CLACT_SetActorBgPriority(p->arrow, 1);
    p->page = (u32)CLACT_CreateActor((void *)p->res.f0, p->res.f10, p->res.f14, p->res.f18, &s, 1, 0x48);
    CLACT_SetActorAutoAnim((struct Obj *)p->page, 1);
    CLACT_SetActorAnimSeq((struct Obj *)p->page, 0x2a);
    WORLDTRADE_SetActorSurfacePos(p->page, 0x37, p->pageNum + 0xa8);
    CLACT_SetActorDrawEnable((struct Obj *)p->page, 0);
    for (i = 0; i < 8; i++) {
        CLACT_GetActorSurfacePos((struct Actor *)p->spr[i], (struct PtS *)&pos, 1);
        p->pos[i].x = pos.x;
        p->pos[i].y = pos.y;
    }
}
