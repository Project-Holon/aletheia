/*
 * function: B_PLIST_DRAW_RegisterIconSet2
 * address: 0x0220E460
 * packet: pkt_ov198_0220E460
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetMoveKindCellFileId 0x02027610 thumb
 */
#include "../include/Obj00172.h"
#include "../include/Obj25202.h"
#include "../include/Obj25203.h"
#include "../include/Obj25204.h"
#include "../include/Obj25205.h"
#include "../include/Obj25206.h"
#include "../include/Obj25207.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterCharacter(void *, unsigned, unsigned, unsigned, u16);
extern int CLACT_RegisterPalette(void *, unsigned, unsigned, unsigned, u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned APP_ICON_GetTypeCellFileId(unsigned);
extern unsigned APP_ICON_GetMoveKindCellFileId(unsigned);
void B_PLIST_DRAW_RegisterIconSet2(char *p)
{
    void *owner;
    unsigned i;
    owner = func_020490F4(83,(u16)((((struct Obj25202 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f2518 = CLACT_RegisterPalette(owner, 33, 1, 160, ((struct Obj25203 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2530 = CLACT_RegisterCellAnim(owner, 59, 62, ((struct Obj25204 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    for (i = 8; i <= 21; i++)
        ((int *)(p + 0x24a4))[i] = CLACT_RegisterCharacter(owner, APP_ICON_GetTypeCellFileId(0), 0, 1, ((struct Obj25205 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f24FC = CLACT_RegisterCharacter(owner, APP_ICON_GetMoveKindCellFileId(0), 0, 1, ((struct Obj25206 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2500 = CLACT_RegisterCharacter(owner, APP_ICON_GetMoveKindCellFileId(0), 0, 1, ((struct Obj25207 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ARC_TOOL_DeleteHandle(owner);
}
