/*
 * function: C_GEAR_POWER_ONOFF_Create
 * address:  0x021EFEC0
 * packet:   pkt_ov035_021EFEC0
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_Create 0x021EFEC0 thumb
 *   func_02030734 0x02030734 arm
 *   sCGearPowerOnOffFileName    0x021F0678 data ov035 a1
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   C_GEAR_POWER_ONOFF_InitScreen 0x021EFF78 thumb ov035
 *   APP_ENV_IsWirelessAvailable 0x0202EB44 thumb
 *   GAMESYSTEM_GetAlwaysNetFlag 0x0201214C thumb
 *   C_GEAR_POWER_ONOFF_Update 0x021EFF3C thumb ov035
 */
#include "../include/Obj02409.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char sCGearPowerOnOffFileName[];
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *);
extern void C_GEAR_POWER_ONOFF_InitScreen(char *p, void *a1);
extern int APP_ENV_IsWirelessAvailable(void);
extern u32 GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *);
extern void C_GEAR_POWER_ONOFF_Update(char *p, int a1);

void *C_GEAR_POWER_ONOFF_Create(int a0, int a1, void *a2)
{
    char *p = (char *)func_02030734((u32)a2, 0x50, 1, sCGearPowerOnOffFileName, 0x12D);
    ((struct Obj02409 *)p)->f4 = a1;
    ((struct Obj02409 *)p)->f8 = GAMESYSTEM_GetGameComm((const struct Ctx *)a1);
    *(int *)&((struct Obj02409 *)p)->fC = a0;
    ((struct Obj02409 *)p)->f0 = (short unsigned int)a2;
    C_GEAR_POWER_ONOFF_InitScreen(p, a2);
    if (APP_ENV_IsWirelessAvailable() == 0)
        ((struct Obj02409 *)p)->f48 = 2;
    else if (GAMESYSTEM_GetAlwaysNetFlag((const struct Ctx *)a1) == 1)
        ((struct Obj02409 *)p)->f48 = 1;
    else
        ((struct Obj02409 *)p)->f48 = 0;
    C_GEAR_POWER_ONOFF_Update(p, 1);
    return p;
}
