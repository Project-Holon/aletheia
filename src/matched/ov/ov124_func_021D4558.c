/*
 * function: func_021D4558
 * address: 0x021D4558
 * packet: pkt_ov124_021D4558
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021D4696.
 * interface: 0204B294 returns its forwarding target's live r0, used here.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj00068.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x, y, z; u8 a, b; } Request;
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(u32);
struct Obj;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void func_021D4558(char *p)
{
    u32 handle;
    Request req;
    handle = (u32)func_020490F4((u32)((void *)0x1d), ((struct Obj00068 *)p)->f0);
    func_02049B68((void *)handle, 1, 4, 0, 0, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 4, 6, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_020498F4((void *)handle, 10, 6, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 4, 7, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_020498F4((void *)handle, 9, 7, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    ARC_TOOL_DeleteHandle(handle);
    handle = (u32)func_020490F4((u32)((void *)0x1e), ((struct Obj00068 *)p)->f0);
    if (func_02008550(**(void ** *)&((struct Obj00068 *)p)->f4) == 0)
        ((struct Obj00068 *)p)->f50 = CLACT_RegisterPaletteEx((void *)handle, 19, 1, 0, 0, 15, ((struct Obj00068 *)p)->f0);
    else
        ((struct Obj00068 *)p)->f50 = CLACT_RegisterPaletteEx((void *)handle, 12, 1, 0, 0, 15, ((struct Obj00068 *)p)->f0);
    *(int *)&((struct Obj00068 *)p)->f54 = CLACT_RegisterCharacter((void *)handle, 22, 0, 1, ((struct Obj00068 *)p)->f0);
    *(int *)&((struct Obj00068 *)p)->f58 = CLACT_RegisterCellAnim((void *)handle, 21, 20, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 0, 4, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f44 = ARC_UTIL_LoadPaletteBlockFromHandle((void *)handle, 13, (u32)(p + 0x48), ((struct Obj00068 *)p)->f0);
    ARC_TOOL_DeleteHandle(handle);
    req.x = 32;
    req.y = 48;
    req.z = 0;
    req.a = 0;
    req.b = 0;
    ((struct Obj00068 *)p)->f5C = CLACT_CreateActor(((struct Obj00068 *)p)->f4C, *(u32 *)&((struct Obj00068 *)p)->f50, ((struct Obj00068 *)p)->f54, ((struct Obj00068 *)p)->f58, &req, 1, ((struct Obj00068 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj00068 *)p)->f5C, 0);
    CLACT_SetActorAutoAnim(((struct Obj00068 *)p)->f5C, 1);
}
