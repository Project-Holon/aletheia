/*
 * function: func_021BC56C
 * address: 0x021BC56C
 * packet: pkt_ov216_021BC56C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC43C 0x021BC43C thumb ov216
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14716.h"
extern void func_021BC43C(void *,char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021BC56C(char *p)
{
    int i;
    for(i=0;i<2;i++) func_021BC43C(p,p+0x68+i*12);
    for(i=0;i<16;i++) func_020307B0(*(void **)(p+0x90+i*8));
    func_020307B0(((struct Obj14716 *)p)->f114);
    func_021BC43C(p,p+0x80);
    func_021BC43C(p,p+0x5c);
    ARC_TOOL_DeleteHandle(((struct Obj14716 *)p)->f58);
}
