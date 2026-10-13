/*
 * function: func_021E5998
 * address:  0x021E5998
 * packet:   pkt_ov119_021E5998
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00285.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u8 func_020355C4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_021D8FA4(void *p, int a);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern u32 POKE_TOOL_GetGraphicIndex(void *mon);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int POKE_TOOL_GetIconPalette(void *);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021E5998(char *p)
{
    void *arc;
    void *a, *b;
    int z;
    ObjTmpl u, t;
    u.x = 0x80;
    u.y = 0x10;
    u.prio = 0x13;
    u.pal = 0xe;
    u.mode = 1;
    ((struct Obj00285 *)p)->fF08 = CLACT_CreateActor(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f894, (unsigned int)((struct Obj00285 *)p)->f880,
        (unsigned int)((struct Obj00285 *)p)->f8B0, &u, 1, ((struct Obj00285 *)p)->f5F4);
    CLACT_SetActorAutoAnim(((struct Obj00285 *)p)->fF08, 1);
    CLACT_SetActorDrawEnable(((struct Obj00285 *)p)->fF08, 1);
    u.x = 0x60;
    u.y = 0x10;
    u.prio = 0;
    u.pal = 0xb;
    u.mode = 1;
    ((struct Obj00285 *)p)->fF0C = CLACT_CreateActor(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f894, (unsigned int)((struct Obj00285 *)p)->f880,
        (unsigned int)((struct Obj00285 *)p)->f8B0, &u, 1, ((struct Obj00285 *)p)->f5F4);
    CLACT_SetActorAutoAnim(((struct Obj00285 *)p)->fF0C, 1);
    if (func_020355C4()) {
        CLACT_SetActorDrawEnable(((struct Obj00285 *)p)->fF0C, 0);
    }
    arc = func_020490F4(7, ((struct Obj00285 *)p)->f5F4);
    z = 0;
    a = POKE_TOOL_GetBoxParam(func_021D8FA4(p, 0));
    b = POKE_TOOL_GetBoxParam(func_021D8FA4(p, 1));
    ((struct Obj00285 *)p)->f89C = (void *)CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(a), z, 1, ((struct Obj00285 *)p)->f5F4);
    ((struct Obj00285 *)p)->f8A0 = (void *)CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(b), z, 1, ((struct Obj00285 *)p)->f5F4);
    t.x = 0x60;
    t.y = 0xc;
    t.prio = z;
    t.pal = 0xc;
    t.mode = 1;
    ((struct Obj00285 *)p)->fF10 = CLACT_CreateActor(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f89C, (unsigned int)((struct Obj00285 *)p)->f87C,
        (unsigned int)((struct Obj00285 *)p)->f8AC, &t, 1, ((struct Obj00285 *)p)->f5F4);
    CLACT_SetActorAutoAnim(((struct Obj00285 *)p)->fF10, 0);
    CLACT_SetActorDrawEnable(((struct Obj00285 *)p)->fF10, 1);
    CLACT_SetActorPaletteOffset(((struct Obj00285 *)p)->fF10, POKE_TOOL_GetIconPalette(a), 1);
    t.x = 0xa0;
    ((struct Obj00285 *)p)->fF14 = CLACT_CreateActor(((struct Obj00285 *)p)->f9C4, (unsigned int)((struct Obj00285 *)p)->f8A0, (unsigned int)((struct Obj00285 *)p)->f87C,
        (unsigned int)((struct Obj00285 *)p)->f8AC, &t, 1, ((struct Obj00285 *)p)->f5F4);
    CLACT_SetActorAutoAnim(((struct Obj00285 *)p)->fF14, 0);
    CLACT_SetActorDrawEnable(((struct Obj00285 *)p)->fF14, 1);
    CLACT_SetActorPaletteOffset(((struct Obj00285 *)p)->fF14, POKE_TOOL_GetIconPalette(b), 1);
    ARC_TOOL_DeleteHandle(arc);
}
