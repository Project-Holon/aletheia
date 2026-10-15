/*
 * function: BEACON_VIEW_IconMoveTask
 * address:  0x021F1418
 * packet:   pkt_ov032_021F1418
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_IconMoveTask 0x021F1418 thumb
 *   BEACON_VIEW_SetEntryVisible 0x021F0EA4 thumb
 *   BEACON_VIEW_SetEntryStatusVisible 0x021F0ED0 thumb
 *   BEACON_VIEW_MoveEntryToPeer 0x021F150C thumb
 *   BEACON_VIEW_MoveEntryToSlot 0x021F1484 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj01676.h"

typedef unsigned char u8;

struct TcblNode;
extern void BEACON_VIEW_SetEntryVisible(char *p, unsigned a);
extern void BEACON_VIEW_SetEntryStatusVisible(char *p, int a);
extern void BEACON_VIEW_MoveEntryToPeer(u8 *this, u8 *p, void *s);
extern void BEACON_VIEW_MoveEntryToSlot(char *this, int a, u8 *b, u8 *c, void *s);
extern void TCBL_DeleteTask(struct TcblNode *n);

void BEACON_VIEW_IconMoveTask(void *h, u8 *t)
{
    void *this;

    this = ((struct Obj01676 *)t)->fC;
    if (((struct Obj01676 *)t)->f10 > 0)
        return;
    if (t[0] == 0) {
        BEACON_VIEW_SetEntryVisible(((struct Obj01676 *)t)->f8, 1);
        if (((struct Obj01676 *)t)->f4 == 1) {
            BEACON_VIEW_MoveEntryToPeer(this, ((struct Obj01676 *)t)->f8, t + 0x10);
            BEACON_VIEW_SetEntryStatusVisible(((struct Obj01676 *)t)->f8, 1);
        } else {
            BEACON_VIEW_MoveEntryToSlot(this, t[1], ((struct Obj01676 *)t)->f8, 0, t + 0x10);
        }
        t[0] = t[0] + 1;
        return;
    }
    if (*(int * *)&((struct Obj01676 *)t)->f14 != 0)
        *(*(int * *)&((struct Obj01676 *)t)->f14) = *(*(int * *)&((struct Obj01676 *)t)->f14) - 1;
    TCBL_DeleteTask(h);
}
