/*
 * function: func_021BE708
 * address: 0x021BE708
 * packet: pkt_ov204_021BE708
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SAVE_CONTROL_INTR_IsFinished 0x021BD3A0 thumb ov088
 *   INTRO_MSG_PrintText 0x021BF23C thumb ov204
 *   INTRO_MSG_UpdatePrint 0x021BF2F4 thumb ov204
 *   INTRO_MSG_StartTimeIcon 0x021BF560 thumb ov204
 *   INTRO_MSG_DeleteTimeIcon 0x021BF580 thumb ov204
 */
#include "../include/Obj05530.h"
typedef unsigned char  u8;
extern int SAVE_CONTROL_INTR_IsFinished(unsigned char *p);
extern void INTRO_MSG_PrintText(char *p, void *a, int flag);
extern int INTRO_MSG_UpdatePrint(char *a);
extern void INTRO_MSG_StartTimeIcon(u8 *p);
extern void INTRO_MSG_DeleteTimeIcon(u8 *p);
int func_021BE708(char *p, int *state)
{
    switch (*state) {
    case 0:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1)
            return 1;
        INTRO_MSG_PrintText(((struct Obj05530 *)p)->f18, (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (INTRO_MSG_UpdatePrint(((struct Obj05530 *)p)->f18) == 1) {
            INTRO_MSG_StartTimeIcon(((struct Obj05530 *)p)->f18);
            ++*state;
        }
        break;
    case 2:
        if (SAVE_CONTROL_INTR_IsFinished(((struct Obj05530 *)p)->fA4) == 1) {
            INTRO_MSG_DeleteTimeIcon(((struct Obj05530 *)p)->f18);
            return 1;
        }
        break;
    }
    return 0;
}
