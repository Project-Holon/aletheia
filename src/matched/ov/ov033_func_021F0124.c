/*
 * function: DOWSING_Delete
 * address:  0x021F0124
 * packet:   pkt_ov033_021F0124
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DOWSING_DeleteSearch 0x021EFEE4 thumb ov033
 *   DOWSING_ExitFade 0x021F0C0C thumb ov033
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   DOWSING_DeleteCloseButton 0x021F0A90 thumb ov033
 *   DOWSING_DeleteParts 0x021F08EC thumb ov033
 *   DOWSING_FreeBackground 0x021F07DC thumb ov033
 *   DOWSING_ExitBgsAndActorUnit 0x021F0738 thumb ov033
 */
#include "../include/Obj09801.h"

struct Node;
extern void DOWSING_DeleteSearch(void *p);
extern void DOWSING_ExitFade(char *p);
extern void func_02030EAC(struct Node *n);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void DOWSING_DeleteCloseButton(char *p);
extern void DOWSING_DeleteParts(char *p);
extern void DOWSING_FreeBackground(char *p);
extern void DOWSING_ExitBgsAndActorUnit(char *p);

void DOWSING_Delete(char *p)
{
    *(volatile unsigned short *)0x04001050 = 0;
    DOWSING_DeleteSearch((void *)(((struct Obj09801 *)p)->fD0));
    DOWSING_ExitFade(p);
    func_02030EAC((struct Node *)(((struct Obj09801 *)p)->fA8));
    func_020307B0(((struct Obj09801 *)p)->f60);
    DOWSING_DeleteCloseButton(p);
    DOWSING_DeleteParts(p);
    DOWSING_FreeBackground(p);
    DOWSING_ExitBgsAndActorUnit(p);
    func_020307B0(p);
}
