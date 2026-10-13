/*
 * function: func_021C0134
 * address:  0x021C0134
 * packet:   pkt_ov208_021C0134
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   data_021C8558  0x021C8558  data
 *   data_021C8560  0x021C8560  data
 *   data_021C8568  0x021C8568  data
 *   data_021C8580  0x021C8580  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u32 w[4];
} BankDesc;

typedef struct {
    u8 v[7];
} Row7;

typedef struct {
    s16 x;
    s16 y;
} Pt;

extern const BankDesc data_021C8580;
extern const Row7 data_021C8558;
extern const Row7 data_021C8560;
extern const Row7 data_021C8568;

struct Obj;
struct Vec2;
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
struct Actor;
struct Bank;
struct Node;
struct Obj;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void MI_CpuFill8(void *dst, int v, int n);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);
extern void CLACT_SetActorBgPriority(u32 obj, int v);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

#define W(o) (*(u32 *)(p + (o)))
#define WP(o) (*(void **)(p + (o)))
#define OBJ(i) (*(u32 *)(p + (i) * 4 + 0xbc))

void func_021C0134(u16 *heap, u8 *p, int key)
{
    BankDesc desc;
    Row7 anim, pri, pal;
    ObjPos pos;
    Pt pt;
    void *h;
    u8 i;

    desc = data_021C8580;
    WP(0x1d4) = CLACT_CreateRenderer((u8 *)(&desc), 1, *heap);
    W(0x1d0) = (u32)CLACT_CreateUnit(0x10, 0, *heap);
    CLACT_SetUnitRenderer((struct Bank *)W(0x1d0), WP(0x1d4));

    h = func_020490F4(0x55, *heap);
    W(0x9c) = CLACT_RegisterPaletteEx(h, 2, 0, 0, 0, 5, *heap);
    W(0x98) = CLACT_RegisterCharacter(h, 8, 0, 0, *heap);
    W(0xa0) = CLACT_RegisterCellAnim(h, 0xc, 0x13, *heap);
    ARC_TOOL_DeleteHandle(h);

    h = func_020490F4(0x9f, *heap);
    W(0xa8) = CLACT_RegisterPaletteEx(h, 6, 0, 0xa0, 0, 2, *heap);
    W(0xa4) = CLACT_RegisterCharacter(h, 0x10, 0, 0, *heap);
    W(0xac) = CLACT_RegisterCellAnim(h, 0x1d, 0x2e, *heap);
    ARC_TOOL_DeleteHandle(h);

    h = func_020490F4(0x9f, *heap);
    W(0xb4) = CLACT_RegisterPaletteEx(h, 5, 0, 0xe0, 0, 1, *heap);
    W(0xb0) = CLACT_RegisterCharacter(h, 0xf, 0, 0, *heap);
    W(0xb8) = CLACT_RegisterCellAnim(h, 0x1c, 0x2d, *heap);
    ARC_TOOL_DeleteHandle(h);

    anim = data_021C8560;
    pri = data_021C8558;
    pal = data_021C8568;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    for (i = 4; i < 7; i++)
        OBJ(i) = (u32)CLACT_CreateActor((void *)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
    for (i = 0; i < 4; i++)
        OBJ(i) = (u32)CLACT_CreateActor((void *)W(0x1d0), W(0xa4), W(0xa8), W(0xac), &pos, 0, *heap);

    for (i = 0; i < 7; i++) {
        CLACT_SetActorAnimSeq((struct Obj *)OBJ(i), anim.v[i]);
        CLACT_SetActorAutoAnim((struct Obj *)OBJ(i), 1);
        CLACT_SetActorBgPriority(OBJ(i), pri.v[i]);
        CLACT_SetActorDrawPriority((struct Node *)OBJ(i), pal.v[i]);
        CLACT_SetActorDrawEnable((struct Obj *)OBJ(i), 0);
        CLACT_SetActorObjMode((struct Actor *)OBJ(i), 1);
    }

    pt.x = 0x80;
    pt.y = 0x60;
    for (i = 0; i < 4; i++)
        CLACT_AddActorSurfacePos((struct Obj *)OBJ(i), (const struct Vec2 *)(&pt), 0);

    p[0xd8] = 7;
}
