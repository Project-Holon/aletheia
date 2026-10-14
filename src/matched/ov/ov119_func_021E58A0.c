/*
 * function: POKETRADE_2D_RegisterIconSpriteResources
 * address: 0x021E58A0
 * packet: pkt_ov119_021E58A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00252.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 x, y, z; u8 a, b; } Sprite;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
void POKETRADE_2D_RegisterIconSpriteResources(int p)
{
    void *a;
    Sprite s;
    a = func_020490F4(0x66, ((struct Obj00252 *)p)->f5F4);
    *(int *)&((struct Obj00252 *)p)->f894 = CLACT_RegisterCharacter(a, 0x18, 0, 1, ((struct Obj00252 *)p)->f5F4);
    *(int *)&((struct Obj00252 *)p)->f880 = CLACT_RegisterPaletteEx(a, 0x12, 1, 0xc0, 0, 6, ((struct Obj00252 *)p)->f5F4);
    *(int *)&((struct Obj00252 *)p)->f8B0 = CLACT_RegisterCellAnim(a, 0x17, 0x16, ((struct Obj00252 *)p)->f5F4);
    ARC_TOOL_DeleteHandle(a);
    s.x = 0x80; s.y = 0xb4; s.z = 2; s.a = 0xe; s.b = 0;
    ((struct Obj00252 *)p)->fF04 = (int)CLACT_CreateActor((void *)*(int *)&((struct Obj00252 *)p)->f9C4, *(int *)&((struct Obj00252 *)p)->f894, *(int *)&((struct Obj00252 *)p)->f880, *(int *)&((struct Obj00252 *)p)->f8B0, &s, 1, ((struct Obj00252 *)p)->f5F4);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00252 *)p)->fF04, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00252 *)p)->fF04, 1);
}
