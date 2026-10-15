/*
 * function: MUSICAL_MCSS_FreeCellBank
 * address: 0x021F6540
 * packet: pkt_ov112_021F6540
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes follow the compiled body.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   NNSi_G2dLoadVramResourceSub 0x02063A54 arm
 *   NNSi_G2dLoadVramResourceBySel 0x02063E54 arm
 */
#include "../include/Obj22552.h"
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
struct Out;
struct Res;
extern void NNSi_G2dLoadVramResourceSub(struct Res *r, u32 dst, int mode, struct Out *out);
extern void NNSi_G2dLoadVramResourceBySel(void *,void *,int,void *);
void MUSICAL_MCSS_FreeCellBank(void *a, void **p)
{
    if(p[8]) ((struct Obj22552 *)((char *)p[8]))->fEC &= ~4u;
    if(p[4]) { NNSi_G2dLoadVramResourceSub(p[0],(u32)p[6],0,p[2]); func_020307B0(p[4]); }
    if(p[1]) { NNSi_G2dLoadVramResourceBySel(p[1],p[7],0,p[3]); func_020307B0(p[5]); }
    func_020307B0(p);
    if(a) func_02030EAC(a);
}
