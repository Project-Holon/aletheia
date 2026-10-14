/*
 * function: GURU2_MAIN_ApplyAngles
 * address: 0x021DF370
 * packet: pkt_ov137_021DF370
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate far-field then near-field stores preserve store scheduling.
 * symbols:
 *   GURU2_MAIN_UpdateCenterTransform 0x021E0570 thumb ov137
 *   GURU2_MAIN_UpdatePlayerRecords 0x021E07A4 thumb ov137
 *   GURU2_MAIN_FindNearestPlayerRecord 0x021E0A44 thumb ov137
 */
#include "../include/Obj04539.h"
#include "../include/Obj10622.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void GURU2_MAIN_UpdateCenterTransform(u8 *p);
extern void GURU2_MAIN_UpdatePlayerRecords(char *p);
extern u8 *GURU2_MAIN_FindNearestPlayerRecord(void *);
int GURU2_MAIN_ApplyAngles(u8 *p)
{
    int i;
    u8 *entry;
    u16 *values;
    if (((struct Obj04539 *)p)->f40 == 1) {
        values = (u16 *)(p + 108);
        ((struct Obj04539 *)p)->f11C = values[0] << 12;
        ((struct Obj04539 *)p)->f58 = values[0] << 12;
        for (i = 0; i < ((struct Obj04539 *)p)->f30; i++) {
            entry = p + 736 + i * 180;
            ((struct Obj10622 *)entry)->f1C = values[((struct Obj10622 *)entry)->f10 + 2] << 12;
            *(u16 *)(p + 96 + i * 2) = values[((struct Obj10622 *)entry)->f10 + 2];
        }
        ((struct Obj04539 *)p)->f1C = values[1];
        GURU2_MAIN_UpdateCenterTransform(p);
        GURU2_MAIN_UpdatePlayerRecords((char *)p);
        *(u8 * *)&((struct Obj04539 *)p)->f28 = GURU2_MAIN_FindNearestPlayerRecord(p);
        ((struct Obj04539 *)p)->f0 = 35;
    }
    return 0;
}
