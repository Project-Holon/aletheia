/*
 * function: FIELD_PLACE_NAME_StateLettersLaunch
 * address:  0x021BCD84
 * packet:   pkt_ov021_021BCD84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_PLACE_NAME_GetStep  0x021BD0C0  thumb  ov021
 *   FIELD_PLACE_NAME_IncrementStep  0x021BD0D0  thumb  ov021
 *   FIELD_PLACE_NAME_LaunchNextLetter  0x021BC948  thumb  ov021
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 */
#include "../include/Obj01123.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 FIELD_PLACE_NAME_GetStep(u8 *p);
extern void FIELD_PLACE_NAME_IncrementStep(char *p);
extern void FIELD_PLACE_NAME_LaunchNextLetter(char *p);
extern void FIELD_PLACE_NAME_SetState(void *p, int keep);

void FIELD_PLACE_NAME_StateLettersLaunch(char *p)
{
    switch (FIELD_PLACE_NAME_GetStep((u8 *)p)) {
    case 0:
        p[0x149] = 0;
        FIELD_PLACE_NAME_IncrementStep(p);
        break;
    case 1:
        if (((struct Obj01123 *)p)->f42 % 3 == 0) {
            FIELD_PLACE_NAME_LaunchNextLetter(p);
            if (((struct Obj01123 *)p)->f20 <= ((struct Obj01123 *)p)->f149) {
                FIELD_PLACE_NAME_SetState(p, 5);
            }
        }
        break;
    }
}
