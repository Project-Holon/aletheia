/*
 * function: RESEARCH_GRAPH_LoadBackground6
 * address: 0x021C00AC
 * packet: pkt_ov217_021C00AC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14748.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct ArcFile;
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);
extern int func_02062B30(void *, void **);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_020409B4(u32);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void RESEARCH_GRAPH_LoadBackground6(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = func_020490F4(192, ((struct Obj14748 *)p)->f4);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 13, ((struct Obj14748 *)p)->f4);
    func_02062B30(blob, &out);
    func_02041090(6, (u32)((char *)out + 12), 0, 0, 32, 24);
    func_020409B4(6);
    func_020307B0((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}
