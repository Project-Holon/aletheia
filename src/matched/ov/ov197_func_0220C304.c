/*
 * function: B_BAG_MAIN_RegisterIconGraphics
 * address: 0x0220C304
 * packet: pkt_ov197_0220C304
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj00315.h"
#include "../include/Obj25027.h"
#include "../include/Obj25028.h"
#include "../include/Obj25029.h"
#include "../include/Obj25030.h"
#include "../include/Obj25031.h"
#include "../include/Obj25032.h"
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterCharacter(void *,unsigned,unsigned,unsigned,u16);
typedef signed int     s32;
typedef unsigned int   u32;
struct PalAnmSlot;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int CLACT_RegisterCellAnim(void *,unsigned,unsigned,unsigned);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void B_BAG_MAIN_RegisterIconGraphics(char *p)
{
    void *arc = func_020490F4(11,(u16)((((struct Obj25027 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    char *data;
    void *buf;
    ((struct Obj00315 *)p)->f564=CLACT_RegisterCharacter(arc,119,0,1,((struct Obj25028 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f588=CLACT_RegisterPaletteEx(arc,116,1,256,4,1,((struct Obj25029 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f594=CLACT_RegisterCellAnim(arc,120,121,((struct Obj25030 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    buf=ARC_UTIL_LoadPaletteBlockFromHandle(arc,116,(u32)(&data),(u16)((((struct Obj25031 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    PALANM_CopyToSlot(((struct Obj00315 *)p)->f8,*(char * *)&((struct Obj25032 *)data)->fC+128,3,128,32);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}
