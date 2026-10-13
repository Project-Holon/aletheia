/*
 * function: FIELD_PLACE_NAME_Interrupt
 * address:  0x021BCBC8
 * packet:   pkt_ov021_021BCBC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 */
#include "../include/Obj05061.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void FIELD_PLACE_NAME_SetState(void *p, int keep);

void FIELD_PLACE_NAME_Interrupt(char *p)
{
    int r6;
    int r5;

    switch (((struct Obj05061 *)p)->f3C) {
    case 0:
    case 4:
    case 6:
        return;
    case 3:
    case 5:
        r6 = 5;
        r5 = 30;
        break;
    case 2:
        r6 = 6;
        r5 = (int)(20.0f * (1.0f - (float)(u32)((struct Obj05061 *)p)->f42 / 10.0f));
        break;
    case 1:
        r6 = 0;
        r5 = 0;
        break;
    }
    FIELD_PLACE_NAME_SetState(p, r6);
    ((struct Obj05061 *)p)->f42 = r5;
}
