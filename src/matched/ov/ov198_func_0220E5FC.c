/*
 * function: B_PLIST_DRAW_RegisterIconSet5
 * address: 0x0220E5FC
 * packet: pkt_ov198_0220E5FC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   APP_ICON_GetGearCellFileId 0x0202775C thumb
 *   APP_ICON_GetNoneFileId 0x02027758 thumb
 *   APP_ICON_GetGearPaletteFileId 0x02027760 thumb
 *   APP_ICON_GetGearAnimFileId 0x02027764 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00172.h"
#include "../include/Obj25216.h"
#include "../include/Obj25217.h"
#include "../include/Obj25218.h"
#include "../include/Obj25219.h"
typedef unsigned short u16;
extern unsigned APP_ICON_GetArchiveId(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int APP_ICON_GetGearCellFileId(int);
extern int APP_ICON_GetNoneFileId(void);
extern int APP_ICON_GetGearPaletteFileId(int);
extern int APP_ICON_GetGearAnimFileId(int);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern int CLACT_RegisterPalette(void *,unsigned,unsigned,unsigned,u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void B_PLIST_DRAW_RegisterIconSet5(char *p)
{
    void *owner;
    int first;
    owner=func_020490F4(APP_ICON_GetArchiveId(),(u16)((((struct Obj25216 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    ((struct Obj00172 *)p)->f2508=CLACT_RegisterCharacter(owner,APP_ICON_GetGearCellFileId(0),0,1,((struct Obj25217 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2520=CLACT_RegisterPalette(owner,APP_ICON_GetNoneFileId(),1,0x120,((struct Obj25218 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    first=APP_ICON_GetGearPaletteFileId(0);
    ((struct Obj00172 *)p)->f2538=CLACT_RegisterCellAnim(owner,first,APP_ICON_GetGearAnimFileId(0),((struct Obj25219 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ARC_TOOL_DeleteHandle(owner);
}
