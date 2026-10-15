/*
 * function: RESEARCH_TOP_LoadBackground6
 * address: 0x021BA768
 * packet: pkt_ov217_021BA768
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
#include "../include/Obj14727.h"
typedef unsigned short u16;
struct ArcFile;
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *,unsigned,unsigned);
extern int func_02062B30(void *,void **);
extern void func_02041090(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char);
extern void func_020409B4(unsigned);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void RESEARCH_TOP_LoadBackground6(char *p)
{
    struct ArcFile *arc=func_020490F4(192,((struct Obj14727 *)p)->f4);
    void *file=ARC_TOOL_LoadHandleMember(arc,13,((struct Obj14727 *)p)->f4);
    void *data;
    func_02062B30(file,&data);
    func_02041090(6,(unsigned)((char *)data+12),0,0,32,24);
    func_020409B4(6);func_020307B0(file);ARC_TOOL_DeleteHandle(arc);
}
