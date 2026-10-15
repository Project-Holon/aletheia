/*
 * function: BEACON_VIEW_IconSlideTask
 * address:  0x021F1704
 * packet:   pkt_ov032_021F1704
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_IconSlideTask 0x021F1704 thumb
 *   BEACON_VIEW_SetEntryPosition 0x021F1218 thumb
 *   BEACON_VIEW_ResetEntry 0x021F0EDC thumb
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj00225.h"
#include "../include/Obj00710.h"

typedef unsigned char u8;

extern void BEACON_VIEW_SetEntryPosition(char *p, short x, short y);
extern void BEACON_VIEW_ResetEntry(char *p);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void BEACON_VIEW_IconSlideTask(void *h, char *t)
{
    u8 *e;

    switch (((struct Obj00710 *)t)->f0) {
    case 0:
        if (((struct Obj00710 *)t)->fD != 0) {
            ((struct Obj00710 *)t)->fD = ((struct Obj00710 *)t)->fD - 1;
            return;
        }
        ((struct Obj00710 *)t)->fF = ((struct Obj00710 *)t)->fF + 1;
        if (((struct Obj00710 *)t)->fF < ((struct Obj00710 *)t)->fE) {
            int x = ((struct Obj00710 *)t)->f14 + ((struct Obj00710 *)t)->f1C;
            int y = ((struct Obj00710 *)t)->f18 + ((struct Obj00710 *)t)->f20;
            ((struct Obj00710 *)t)->f14 = x;
            ((struct Obj00710 *)t)->f18 = y;
            BEACON_VIEW_SetEntryPosition((char *)(*(u8 * *)&((struct Obj00710 *)t)->f8), (short)(x >> 12), (short)(y >> 12));
            return;
        }
        BEACON_VIEW_SetEntryPosition((char *)(*(u8 * *)&((struct Obj00710 *)t)->f8), ((struct Obj00710 *)t)->f10, ((struct Obj00710 *)t)->f12);
        e = *(u8 * *)&((struct Obj00710 *)t)->f8;
        if (e[2] == 0 || e[2] == 5) {
            ((struct Obj00710 *)t)->f0 = ((struct Obj00710 *)t)->f0 + 1;
            return;
        }
        break;
    case 1:
    default:
        e = *(u8 * *)&((struct Obj00710 *)t)->f8;
        if (((struct Obj00225 *)e)->f2C != 0)
            return;
        BEACON_VIEW_ResetEntry((char *)e);
        break;
    }
    **(int * *)&((struct Obj00710 *)t)->f24 = **(int * *)&((struct Obj00710 *)t)->f24 - 1;
    TCBL_DeleteTask(h);
}
