/*
 * function: RINGTONE_SYS_HandleRingTimeout
 * address:  0x0202A0E8
 * packet:   pkt_0202A084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   RINGTONE_SYS_TickRing  0x02029F8C  thumb
 *   RINGTONE_SYS_PostEvent  0x0202A084  thumb
 */
#include "../include/Obj04055.h"

typedef unsigned int u32;

typedef unsigned short u16;
extern int RINGTONE_SYS_TickRing(u16 *p);
extern void RINGTONE_SYS_PostEvent(u32 *p, int event);

void RINGTONE_SYS_HandleRingTimeout(u32 *p)
{
    int r = RINGTONE_SYS_TickRing((u16 *)p);

    switch (((struct Obj04055 *)p)->f0) {
    case 0:
        break;
    case 1:
        if (r == 0) {
            RINGTONE_SYS_PostEvent(p, 0);
        }
        break;
    case 2:
        break;
    case 3:
        if (r == 0) {
            RINGTONE_SYS_PostEvent(p, 2);
        }
        break;
    }
}
