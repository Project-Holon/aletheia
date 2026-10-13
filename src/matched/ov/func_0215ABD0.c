/*
 * function: SCRCMD_WORK_CmdGetSeason
 * address:  0x0215ABD0
 * packet:   pkt_0215ABD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSeason  0x02012984  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);

int SCRCMD_WORK_CmdGetSeason(int a0, int a1)
{
    int t5;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215ABD8:
a0 = t5 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215ABE0:
    a0 = GAME_DATA_GetSeason(v0);
loc_0215ABE4:
*q = a0;
a0 = 0;
    return a0;}
