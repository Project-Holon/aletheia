/*
 * function: BEACON_DETAIL_GRA_TimerCallback
 * address: 0x021BD768
 * packet: pkt_ov216_021BD768
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_AddFadeTask 0x021BD668 thumb ov216
 *   BEACON_DETAIL_GRA_UpdateTimer 0x021BD73C thumb ov216
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj03375.h"
typedef unsigned char u8;
struct TcblNode;
extern void BEACON_DETAIL_GRA_AddFadeTask(char *owner, int direction, int *counter);
extern int BEACON_DETAIL_GRA_UpdateTimer(char *);
extern void TCBL_DeleteTask(struct TcblNode *);
void BEACON_DETAIL_GRA_TimerCallback(struct TcblNode *task, void *data)
{
    char *p = data;
    switch (((struct Obj03375 *)p)->f0) {
    case 0:
        BEACON_DETAIL_GRA_AddFadeTask(((struct Obj03375 *)p)->f8, 0, (int *)(p + 4));
        ++((struct Obj03375 *)p)->f0;
        break;
    case 1:
        if (((struct Obj03375 *)p)->f4 == 0)
            ++((struct Obj03375 *)p)->f0;
        break;
    case 2:
        if (BEACON_DETAIL_GRA_UpdateTimer(p) == 0) {
            BEACON_DETAIL_GRA_AddFadeTask(((struct Obj03375 *)p)->f8, 1, (int *)(p + 4));
            ++((struct Obj03375 *)p)->f0;
        }
        break;
    case 3:
        if (((struct Obj03375 *)p)->f4 != 0)
            break;
    default:
        --**(int * *)&((struct Obj03375 *)p)->fC;
        TCBL_DeleteTask(task);
        break;
    }
}
