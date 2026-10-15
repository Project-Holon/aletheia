/*
 * function: RESEARCH_LIST_LoadBackground6
 * address: 0x021BCAE8
 * packet: pkt_ov217_021BCAE8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   func_02041B6C 0x02041B6C arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm  arm9
 *   BG_SYS_DrawTile  0x02041090  arm  arm9
 * Original narrows the heap before 020490F4; its extern takes u16.
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Arc;
extern void *func_020490F4(u32 id, u32 heap);
struct ArcFile;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern int NNS_G2dGetUnpackedScreenData(void *, void **);
extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);
extern void func_02041B6C(u32 bit);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void RESEARCH_LIST_LoadBackground6(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct Obj00025 *)p)->f8 & 0x7FFF) | 0x8000));
    buf = ARC_TOOL_LoadHandleMember(arc, 13, ((struct Obj00025 *)p)->f8);
    NNS_G2dGetUnpackedScreenData(buf, &screen);
    BG_SYS_DrawTile(6, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(6);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}
