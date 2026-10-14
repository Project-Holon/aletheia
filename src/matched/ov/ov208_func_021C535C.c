/*
 * function: ZUKAN_DETAIL_FORM_CreateIconActor
 * address:  0x021C535C
 * packet:   pkt_ov208_021C535C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u8  b6;
    u8  b7;
} Ov208ObjPos;

extern u32  POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
typedef signed int     s32;
struct Actor;
struct Obj;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int res, unsigned int j, unsigned int k, const void *pos, unsigned short f, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);
extern u32  POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

u32 ZUKAN_DETAIL_FORM_CreateIconActor(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species,
                        u32 form, u32 gender, u32 isEgg)
{
    Ov208ObjPos pos;
    u32 obj;

    pos.x = 0x80;
    pos.y = 0x80;
    pos.z = 1;
    pos.b6 = 1;
    pos.b7 = 0;
    *res = CLACT_RegisterCharacter((void *)arc, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)CLACT_CreateActor((void *)owner, *res, j, k, &pos, 1, heap);
    CLACT_SetActorAutoAnim((struct Obj *)obj, 0);
    CLACT_SetActorPaletteOffset((struct Obj *)obj, POKE_TOOL_CalcIconPalette(species, form, gender, isEgg), 0);
    CLACT_SetActorObjMode((struct Actor *)obj, 0);
    return obj;
}
