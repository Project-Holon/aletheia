/*
 * function: B_PLIST_DRAW_RegisterIconSet4
 * address: 0x0220E584
 * packet: pkt_ov198_0220E584
 * region: ov198
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
 */
#include "../include/Obj00172.h"
#include "../include/Obj25212.h"
#include "../include/Obj25213.h"
#include "../include/Obj25214.h"
#include "../include/Obj25215.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
extern int CLACT_RegisterPaletteEx(void *,unsigned,unsigned,unsigned,u16,u16,u16);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void B_PLIST_DRAW_RegisterIconSet4(char *p)
{
    void *owner;
    owner=func_020490F4(11,(u16)((((struct Obj25212 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    ((struct Obj00172 *)p)->f2504=CLACT_RegisterCharacter(owner,119,0,1,((struct Obj25213 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f251C=CLACT_RegisterPaletteEx(owner,116,1,256,4,1,((struct Obj25214 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2534=CLACT_RegisterCellAnim(owner,120,121,((struct Obj25215 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ARC_TOOL_DeleteHandle(owner);
}
