/*
 * function: ZUKAN_DETAIL_AREA_CreatePokemonIcon
 * address:  0x021C0B6C
 * packet:   pkt_ov208_021C0B6C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

extern void *func_020490F4(u32 id, u32 heap);
extern u32  POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *res, unsigned int a, unsigned int b, unsigned int c, const void *pos, unsigned short f, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32  POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);
struct Actor;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void ARC_TOOL_DeleteHandle(void *h);

u32 ZUKAN_DETAIL_AREA_CreatePokemonIcon(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form,
                  u32 gender, u32 isEgg, u8 x, u8 y)
{
    ObjPos pos;
    void *h;
    u32 obj;

    h = func_020490F4(7, heap);
    pos.x = x;
    pos.y = y;
    pos.z = 1;
    pos.pri = 1;
    pos.f7 = 0;
    *slot = CLACT_RegisterCharacter(h, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)CLACT_CreateActor((void *)res, *slot, a, b, &pos, 1, heap);
    CLACT_SetActorAutoAnim((struct Obj *)obj, 0);
    CLACT_SetActorPaletteOffset((struct Obj *)obj, POKE_TOOL_CalcIconPalette(species, form, gender, isEgg), 0);
    CLACT_SetActorObjMode((struct Actor *)obj, 0);
    ARC_TOOL_DeleteHandle(h);
    return obj;
}
