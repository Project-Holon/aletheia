/*
 * function: RESEARCH_TOP_LoadBackground2
 * address: 0x021BA7E0
 * packet: pkt_ov217_021BA7E0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14728.h"
typedef unsigned short u16;
struct ArcFile;
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *,unsigned,unsigned);
extern int NNS_G2dGetUnpackedScreenData(void *,void **);
extern void BG_SYS_DrawTile(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char);
extern void func_020409B4(unsigned);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void RESEARCH_TOP_LoadBackground2(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct Obj14728 *)p)->f4);
    void *file=ARC_TOOL_LoadHandleMember(arc,4,((struct Obj14728 *)p)->f4);
    void *data;
    NNS_G2dGetUnpackedScreenData(file,&data);
    BG_SYS_DrawTile(2,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(2);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}
