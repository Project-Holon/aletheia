/*
 * unit: yes
 * function: PMS_INPUT_VIEW_TaskResetEditCursor,PMS_INPUT_VIEW_TaskEndOnly2,PMS_INPUT_VIEW_TaskEndOnly3,PMS_INPUT_VIEW_TaskEndOnly4,PMS_INPUT_VIEW_TaskEndOnly5
 * address: 0x021BAA3C
 * packet: pkt_ov110_021BAA3C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_EDIT_PressCursor 0x021BC6F8 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13774.h"
typedef unsigned char u8;
extern void PMSIV_EDIT_PressCursor(void *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskResetEditCursor(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj00135 *)p)->f0;
    if(q[0x74]!=1) PMSIV_EDIT_PressCursor(((struct Obj13774 *)q)->f54);
    PMS_INPUT_VIEW_EndTask(p);
}
void PMS_INPUT_VIEW_TaskEndOnly2(void *unused,u8 *p) { PMS_INPUT_VIEW_EndTask(p); }
void PMS_INPUT_VIEW_TaskEndOnly3(void *unused,u8 *p) { PMS_INPUT_VIEW_EndTask(p); }
void PMS_INPUT_VIEW_TaskEndOnly4(void *unused,u8 *p) { PMS_INPUT_VIEW_EndTask(p); }
void PMS_INPUT_VIEW_TaskEndOnly5(void *unused,u8 *p) { PMS_INPUT_VIEW_EndTask(p); }
