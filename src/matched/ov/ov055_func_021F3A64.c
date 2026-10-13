/*
 * function: CROWD_Exit
 * address:  0x021F3A64
 * packet:   pkt_ov055_021F3A64
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_SetZoneEffectWork  0x02189A68  thumb  ov021
 *   CROWD_DeletePerson  0x021F3CE4  thumb  ov055
 *   CROWD_FreeConfig  0x021F3F20  thumb  ov055
 *   CROWD_ExitChatter  0x021F4430  thumb  ov055
 */
#include "../include/Obj13119.h"

extern void FIELDMAP_SetZoneEffectWork(char *a, int b);
extern void CROWD_DeletePerson(char *);
extern void CROWD_FreeConfig(unsigned char *p);
extern void CROWD_ExitChatter(unsigned char *p);

void CROWD_Exit(int a, int b, char *c)
{
    int i;

    FIELDMAP_SetZoneEffectWork((char *)b, 0);
    for (i = 0; i < 0x20; i++)
        CROWD_DeletePerson(c + 8 + i * 0x18);
    CROWD_FreeConfig((unsigned char *)(c + 0x308));
    CROWD_ExitChatter((unsigned char *)(c + 0x348));
    ((struct Obj13119 *)c)->f0 = 0;
    ((struct Obj13119 *)c)->f4 = 0;
}
