/*
 * function: POKETRADE_SAVE_StepWaitSaveDone
 * address: 0x021E0C44
 * packet: pkt_ov119_021E0C44
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status:   EXACT
 * 2026-10-02: byte-correct; the call to the tail-call stub 0x02010934 (inside
 * matched unit_0201088C) now resolves since that stub was seeded as a start.
 * symbols:
 *   GFL_NET_SAVE_CheckFinished 0x02010904 thumb
 *   GFL_NET_SAVE_Delete 0x02010934 thumb
 *   POKETRADE_SAVE_RestoreBackups 0x021E02E8 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepBeginWipeOut 0x021E0C78 thumb ov119
 */
#include "../include/Obj10371.h"
typedef unsigned int   u32;
struct Sub0201088CObj;
extern u32 GFL_NET_SAVE_CheckFinished(struct Sub0201088CObj *p);
extern void GFL_NET_SAVE_Delete(struct Sub0201088CObj *p);
extern void POKETRADE_SAVE_RestoreBackups(char *p);
extern void POKETRADE_PROC_SetStep(void *p, int v);
extern void POKETRADE_SAVE_StepBeginWipeOut(char *p);
void POKETRADE_SAVE_StepWaitSaveDone(char *p)
{
    if (GFL_NET_SAVE_CheckFinished(((struct Obj10371 *)p)->fEF8)) {
        POKETRADE_SAVE_RestoreBackups(p);
        GFL_NET_SAVE_Delete(((struct Obj10371 *)p)->fEF8);
        *(int *)&((struct Obj10371 *)p)->fEF8 = 0;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepBeginWipeOut);
    }
}
