/*
 * function: BTL_SERVER_StepWaitEnd
 * address:  0x021BB320
 * packet:   pkt_ov093_021BB320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BTL_MAIN_GetOwnsSlots  0x021B9114  thumb  ov093
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 */
#include "../include/Obj21033.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 BTL_MAIN_GetOwnsSlots(u8 **);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);

int BTL_SERVER_StepWaitEnd(u8 *p, int *s)
{
    switch (*s) {
    case 0: {
        int r = 0;
        if (BTL_MAIN_GetOwnsSlots(*(u8 ** *)&((struct Obj21033 *)p)->fC) == 0) {
            if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) r = 1;
        } else {
            r = 1;
        }
        if (r != 0) {
            (*s)++;
            return 1;
        }
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}
