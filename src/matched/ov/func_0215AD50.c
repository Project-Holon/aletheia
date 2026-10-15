/*
 * function: SCRCMD_WORK_CmdSetWarpDestination
 * address:  0x0215AD50
 * packet:   pkt_0215AD50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   MAP_REPLACE_IsValidWarpId  0x02159F84  thumb  ov010
 *   GAME_DATA_SetWarpId  0x02012900  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int MAP_REPLACE_IsValidWarpId(int a0);
extern int GAME_DATA_SetWarpId();

int SCRCMD_WORK_CmdSetWarpDestination(int a0, int a1)
{    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215AD5C:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
loc_0215AD66:
t5 = a0 + 0;
    a0 = MAP_REPLACE_IsValidWarpId(a0);
loc_0215AD6C:
    if (a0 != 1) goto loc_0215AD78;
loc_0215AD70:
a1 = t5 + 0;
    a0 = GAME_DATA_SetWarpId(v0, a1);
loc_0215AD78:
a0 = 0;
    return a0;}
