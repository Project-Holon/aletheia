/*
 * function: BOX2_MAIN_StateMachineClose
 * address: 0x021E0068
 * packet: pkt_ov170_021E0068
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the full party-count-plus-30 expression to an int local.
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   BOX2_MAIN_MoveCursorWithMon 0x021DE158 thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb ov170
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj08233.h"
extern unsigned POKEPARTY_GetCount(void *p);
extern int BOX2_MAIN_MoveCursorWithMon(unsigned char *p, unsigned a, unsigned b);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern int BOX2_MAIN_WaitCursorMove(unsigned char *p);
extern void BOX2_MAIN_SetMoverEntry(char *p, void *a);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int BOX2_MAIN_StateMachineClose(char *p)
{
    char *s;
    int count;
    s = *(char * *)&((struct Obj00000 *)p)->f2C + 0x58;
    switch (((struct Obj08233 *)s)->fC) {
    case 0:
        count = POKEPARTY_GetCount((*(void *** )p)[2]) + 30;
        BOX2_MAIN_MoveCursorWithMon((unsigned char *)p, ((struct Obj00000 *)p)->f16, count);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        (((struct Obj08233 *)s)->fC)++;
        break;
    case 1:
        if (BOX2_MAIN_WaitCursorMove((unsigned char *)p) == 0) {
            BOX2_MAIN_SetMoverEntry(p, ((struct Obj08233 *)s)->f8);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((struct Obj08233 *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}
