/*
 * function: func_021C5114
 * address: 0x021C5114
 * packet: pkt_ov136_021C5114
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0207D63C 0x0207D63C arm
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 */
#include "../include/Obj05421.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Node;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_0207D63C(void *, int, int, int, int);
void func_021C5114(u8 *p)
{
    PALANM_FreeSlotBuffers(((struct Obj05421 *)p)->f38, 0);
    PALANM_Delete(((struct Obj05421 *)p)->f38);
    ((struct Obj05421 *)p)->f38 = 0;
    func_02030EAC(((struct Obj05421 *)p)->fFC);
    func_02030DA4(((struct Obj05421 *)p)->fF8);
    func_020307B0(((struct Obj05421 *)p)->fF4);
    func_0207D63C((void *)0x04000050, 0, 0, 31, 0);
}
