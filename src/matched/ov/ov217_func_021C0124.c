/*
 * function: RESEARCH_GRAPH_LoadBackground2
 * address: 0x021C0124
 * packet: pkt_ov217_021C0124
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021C016E is two-byte alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14749.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct ArcFile;
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);
extern int NNS_G2dGetUnpackedScreenData(void *, void **);
extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);
extern void BG_SYS_PushTile(u32);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void RESEARCH_GRAPH_LoadBackground2(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = func_020490F4(192, ((struct Obj14749 *)p)->f4);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 7, ((struct Obj14749 *)p)->f4);
    NNS_G2dGetUnpackedScreenData(blob, &out);
    BG_SYS_DrawTile(2, (u32)((char *)out + 12), 0, 0, 32, 32);
    BG_SYS_PushTile(2);
    func_020307B0((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}
