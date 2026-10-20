/*
 * file:     msg_speed.c
 * unit:     yes
 * function: MSG_SPEED_SetSaveControl, MSG_SPEED_GetWait, MSG_SPEED_GetSlowerWait, MSG_SPEED_GetFasterWait, MSG_SPEED_GetWaitForSpeed
 * address:  0x02012FF0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from ica_anime.c, btl_setup.c by tools/splitfile.py.
 *
 * symbols:
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   sMsgSpeedSaveControl  0x020A7298  data
 *   sMsgSpeedWaitTable 0x0209DFB0  data
 *   CONFIG_GetTextSpeed  0x02008374  thumb
 */
#include "btl_setup_types.h"
#include "game_data_shared_types.h"

#include "system_data.h"

#include "config.h"

extern struct SaveControl *sMsgSpeedSaveControl;

extern const signed char sMsgSpeedWaitTable[];

void MSG_SPEED_SetSaveControl(struct SaveControl *save);

signed char MSG_SPEED_GetWait(void);

signed char MSG_SPEED_GetSlowerWait(void);

signed char MSG_SPEED_GetFasterWait(void);

signed char MSG_SPEED_GetWaitForSpeed(u32 speed);

/*
 * A whole translation unit, matched as one byte range.
 *
 * Message speed: the save control pointer setter and the clamped lookup of
 * the wait for the configured speed in sMsgSpeedWaitTable. These look like
 * a file of their own (see misplaced.tsv of the cleanup lane).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012FF0.c \
 *       --addr 0x02012FF0 --thumb
 */
void MSG_SPEED_SetSaveControl(struct SaveControl *save)
{
    sMsgSpeedSaveControl = save;
}

signed char MSG_SPEED_GetWait(void)
{
    u32 speed = CONFIG_GetTextSpeed(SYSTEM_DATA_GetConfig(sMsgSpeedSaveControl));
    if (speed >= 5) {
        speed = 4;
    }
    return sMsgSpeedWaitTable[speed];
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The slower and faster neighbours of the configured message speed, both
 * through the clamped lookup MSG_SPEED_GetWaitForSpeed.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02013020.c \
 *       --addr 0x02013020 --thumb
 */
signed char MSG_SPEED_GetSlowerWait(void)
{
    u32 speed = CONFIG_GetTextSpeed(SYSTEM_DATA_GetConfig(sMsgSpeedSaveControl));
    switch (speed) {
    case 0:
        speed = 1;
        break;
    case 1:
        speed = 2;
        break;
    case 2:
        speed = 3;
        break;
    }
    return MSG_SPEED_GetWaitForSpeed(speed);
}

signed char MSG_SPEED_GetFasterWait(void)
{
    u32 speed = CONFIG_GetTextSpeed(SYSTEM_DATA_GetConfig(sMsgSpeedSaveControl));
    switch (speed) {
    case 0:
        speed = 4;
        break;
    case 1:
        speed = 0;
        break;
    case 2:
        speed = 1;
        break;
    }
    return MSG_SPEED_GetWaitForSpeed(speed);
}

signed char MSG_SPEED_GetWaitForSpeed(u32 speed)
{
    if (speed >= 5) {
        speed = 4;
    }
    return sMsgSpeedWaitTable[speed];
}
