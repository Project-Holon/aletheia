/*
 * function: DOWSING_CreateCloseButton
 * address:  0x021F0924
 * packet:   pkt_ov033_021F0924
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the four `strh #0` after INFOWIN_Init are `Local s = {0};`
 *           opening an inner block there; declared at the top they land
 *           before the first call.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   INFOWIN_Init 0x02024A20 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020307B0 0x020307B0 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAutoAnimSpeed 0x0204B954 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

typedef struct {
    u16 heap;
    u16 heap2;
    u8 pad4[0x4];
    u32 f8;
    u32 fC;
    u8 pad10[0x4];
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
} Obj;

struct Actor;
struct Ctx;
struct Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void INFOWIN_Init(u8 a0, u8 a1, void *a2, u16 heap);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *o, u32 a, u32 b, void **out, u16 e);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32 bit);
extern u32 func_020307B0(void *p);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void ARC_TOOL_DeleteHandle(void *);

void DOWSING_CreateCloseButton(Obj *p)
{
    struct Scr *ptr;
    u32 heap2;

    heap2 = p->heap2;
    INFOWIN_Init(4, 3, GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p->f8)), p->heap);
    {
        Local s = {0};
        void *h;
        void *arc;
        u16 *d;
        u16 i;
        u16 base;

        arc = func_020490F4(func_020275E4(), heap2);
        func_02049B68(arc, func_02027624(), 4, 0x40, 0x20, heap2);
        p->f14 = func_02049740(arc, func_02027628(), 4, 0, 0, heap2);
        h = ARC_UTIL_LoadPaletteDataFromHandle(arc, func_0202762C(), 0, (void **)&ptr, heap2);
        base = p->f14;
        d = ptr->data;
        for (i = 0; i < 0x300; i++) {
            d[i] &= 0xFFF;
            d[i] = (base + d[i]) | 0x2000;
        }
        func_020410D0(4, 0, 0x15, 0x20, 3, (u32)ptr->data, 0, 0x15, 0x20, 0x18);
        func_02041B6C(4);
        func_020307B0(h);
        p->f18 = CLACT_RegisterPaletteEx(arc, func_02027614(), 1, 0x20, 0, 3, p->heap);
        p->f1C = CLACT_RegisterCharacter(arc, func_02027618(), 0, 1, p->heap);
        p->f20 = CLACT_RegisterCellAnim(arc, func_0202761C(0), func_02027620(0), p->heap);
        s.a = 0xE8;
        s.b = 0xA8;
        p->f24 = (u32)CLACT_CreateActor((void *)p->fC, p->f1C, p->f18, p->f20, &s, 1, p->heap);
        CLACT_SetActorAutoAnim((struct Obj *)p->f24, 1);
        CLACT_SetActorAutoAnimSpeed((struct Actor *)p->f24, 0x2000);
        CLACT_SetActorAnimSeq((struct Obj *)p->f24, 0);
        ARC_TOOL_DeleteHandle(arc);
        p->f28 = 0;
    }
}
