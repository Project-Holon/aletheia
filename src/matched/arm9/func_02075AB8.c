/*
 * function: NNSi_SndTrackListUnlinkByValue
 * address:  0x02075AB8
 * packet:   pkt_02075AB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988  arm
 *   OS_RestoreInterrupts 0x0208799C  arm
 *   NNS_FndGetNextListObject 0x02060614  arm
 *   NNS_FndRemoveListObject 0x020605B4  arm
 *   NNSi_SndTrackListUnlinkElem 0x02075B28  arm
 *
 * The unlink walk holds the interrupt state in the lowest callee-saved
 * register and the next link in r6, so the state survives the two calls in
 * the body; declaring `n` inside the loop (rather than hoisting it) is what
 * keeps r6 out of the prologue's push.
 */
#include "../include/Obj16688.h"

typedef unsigned int u32;

extern u32  OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
struct DList;
extern void *NNS_FndGetNextListObject(struct DList *list, void *elem);
extern void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);
extern int NNSi_SndTrackListUnlinkElem(void *a0);

void NNSi_SndTrackListUnlinkByValue(void *a, u32 v)
{
    u32 state = OS_DisableInterrupts();
    void *p = NNS_FndGetNextListObject(a, 0);

    while (p != 0) {
        void *n = NNS_FndGetNextListObject(a, p);

        if (((struct Obj16688 *)p)->f8 == v) {
            NNS_FndRemoveListObject(a, p);
            NNSi_SndTrackListUnlinkElem(p);
        }
        p = n;
    }
    OS_RestoreInterrupts(state);
}
