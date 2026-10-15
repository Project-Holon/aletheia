/*
 * function: func_02210608
 * address: 0x02210608
 * packet: pkt_ov198_02210608
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   B_PLIST_ANM_CopyMonSpriteTiles 0x0220B120 thumb ov198
 *   B_PLIST_ANM_CopySubSpriteTiles 0x0220B3B4 thumb ov198
 *   func_020307B0 0x020307B0 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 */
#include "../include/Obj02535.h"
#include "../include/Obj25247.h"
#include "../include/Obj25248.h"
#include "../include/Obj25249.h"
#include "../include/Obj25250.h"
#include "../include/Obj25251.h"
#include "../include/Obj25252.h"
#include "../include/Obj25253.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot;
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *,u32,u32,void **,u16);
extern void B_PLIST_ANM_CopyMonSpriteTiles(char *,u16 *);
extern void B_PLIST_ANM_CopySubSpriteTiles(char *,u16 *);
extern u32 func_020307B0(void *p);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern int PALANM_GetDefaultWork(char *,int);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *,u32,u32,u32);
void func_02210608(char *p)
{
    void *owner=ARC_TOOL_CreateHandle(100,(u16)((((struct Obj25247 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10&0x7fff)|0x8000));
    void *handle;
    char *data;
    ARC_UTIL_UploadBgCharFromHandle(owner,18,7,0,0,1,((struct Obj25248 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    handle=ARC_UTIL_LoadPaletteDataFromHandle(owner,16,1,(void **)&data,((struct Obj25249 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    B_PLIST_ANM_CopyMonSpriteTiles(p,(u16 *)(data+12));
    func_020307B0(handle);
    handle=ARC_UTIL_LoadPaletteDataFromHandle(owner,17,1,(void **)&data,((struct Obj25250 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    B_PLIST_ANM_CopySubSpriteTiles(p,(u16 *)(data+12));
    func_020307B0(handle);
    PALANM_LoadArcPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,100,19,((struct Obj25251 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,0x1e0,0);
    ARC_TOOL_DeleteHandle(owner);
    MI_CpuCopy8((void *)(PALANM_GetDefaultWork(*(char * *)&((struct Obj02535 *)p)->f1D8,1)+0x180),p+0x1e78,32);
    func_0201F5BC(4,1,14,0,((struct Obj25252 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,1,0xe0,32);
    PALANM_LoadArcPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,23,5,((struct Obj25253 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,32,0xd0);
}
