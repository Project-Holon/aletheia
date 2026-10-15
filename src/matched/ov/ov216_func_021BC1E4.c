/*
 * function: func_021BC1E4
 * address: 0x021BC1E4
 * packet: pkt_ov216_021BC1E4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj01591.h"
#include "../include/Obj25769.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct ArcFile;struct NitroFileHeader;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *,u32,u32);
extern int NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *,void **);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0207D63C(u32 *,u32,u32,int,int);
void func_021BC1E4(char *p,u16 heap)
{
    struct ArcFile *arc;
    arc=func_020490F4(85,heap);
    func_02049B68(arc,0,0,0,512,heap);
    func_02049B68(((struct Obj01591 *)p)->f54,28,4,0,512,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,4,0,0,1,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,5,0,0,1,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,7,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,32,4,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,32,5,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,33,7,0,0,1,heap);
    BG_SYS_FillTileMap(5,0,0,32,24,1);
    func_020409B4(5);
    func_02049658(((struct Obj01591 *)p)->f54,31,1,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,34,1,0,2048,1,heap);
    func_02049658(arc,5,2,0,0,0,heap);
    func_020498F4(arc,17,2,0,2048,0,heap);
    func_02049658(arc,7,3,0,0,0,heap);
    func_020498F4(arc,16,3,0,2048,0,heap);
    ((struct Obj01591 *)p)->f120=ARC_TOOL_LoadHandleMember(*(struct ArcFile * *)&((struct Obj01591 *)p)->f54,29,((struct Obj01591 *)p)->f0);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct Obj01591 *)p)->f120,(void **)(p+280));
    ((struct Obj01591 *)p)->f11C=((struct Obj25769 *)(*(char * *)&((struct Obj01591 *)p)->f118))->fC;
    ARC_TOOL_DeleteHandle(arc);
    func_0207D63C((u32 *)0x04000050,2,30,11,5);
    func_0207D63C((u32 *)0x04001050,3,31,13,3);
}
