/*
 * function: BTLV_INPUT_AllocTaskSlot
 * address:  0x022068C4
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_INPUT_AllocTaskSlot   0x022068C4  thumb
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj18616.h"

extern void BTLV_INPUT_DeleteTask(char *p, void *q);

int BTLV_INPUT_AllocTaskSlot(char *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (*(int *)(p + 8 + i * 4) == 0)
            break;
    }
    if (i == 8) {
        BTLV_INPUT_DeleteTask(p, (void *)(((struct Obj18616 *)p)->f8));
        i = 0;
    }
    return i;
}

