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
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
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
extern unsigned func_020275E4(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
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
    owner=func_020490F4(func_020275E4(),(u16)((((struct Obj25216 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10&0x7fff)|0x8000));
    ((struct Obj00172 *)p)->f2508=CLACT_RegisterCharacter(owner,func_0202775C(0),0,1,((struct Obj25217 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2520=CLACT_RegisterPalette(owner,func_02027758(),1,0x120,((struct Obj25218 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    first=func_02027760(0);
    ((struct Obj00172 *)p)->f2538=CLACT_RegisterCellAnim(owner,first,func_02027764(0),((struct Obj25219 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ARC_TOOL_DeleteHandle(owner);
}
