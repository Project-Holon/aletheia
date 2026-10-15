/*
 * function: SODATEYA_CreateEggMon
 * address:  0x021C3898
 * packet:   pkt_ov021_021C3898
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   DAYCARE_GetSlotMon  0x0200BC2C  thumb
 *   SODATEYA_BuildEgg  0x021C38F4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03142.h"

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned char  u8;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 DAYCARE_GetSlotMon(u32, int);
extern void SODATEYA_BuildEgg(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon);

void SODATEYA_CreateEggMon(u32 *p, u32 c)
{
    u32 a = (u32)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p[1])));
    u32 b = DAYCARE_GetSlotMon(p[2], 0);
    u32 d = DAYCARE_GetSlotMon(p[2], 1);

    SODATEYA_BuildEgg(((struct Obj03142 *)p)->f0, (void *)a, (void *)0xEA62, b, d, (void *)c);
}
