/*
 * function: INTRUDE_COMM_GetAreaSlotFlag
 * address:  0x02158468
 * packet:   pkt_02158468
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GAME_DATA_GetSlotFlag  0x02012B98  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u32 GAME_COMM_GetGameData(void *obj);
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u8 GAME_DATA_GetIntrudeIdByte(void *p);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern u8 GAME_DATA_GetSlotFlag(const struct BigObj *p, u32 i);

int INTRUDE_COMM_GetAreaSlotFlag(int a0)
{
    int a1;
    int t4;
    int t5;

    a0 = GAME_COMM_GetGameData((void *)a0);
loc_0215846E:
t5 = a0 + 0;
    a0 = GAME_DATA_GetIntrudeCount((const struct BigObj *)a0);
loc_02158474:
    if (a0 != 0) goto loc_02158480;
loc_02158478:
a0 = t5 + 0;
    a0 = GAME_DATA_GetSeason((const struct BigObj *)a0);
loc_0215847E:
    return a0;
loc_02158480:
a0 = t5 + 0;
    a0 = GAME_DATA_GetIntrudeIdByte((void *)a0);
loc_02158486:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = GAME_DATA_GetExitMode((const struct BigObj *)a0);
loc_0215848E:
    if (t4 != a0) goto loc_0215849A;
loc_02158492:
a0 = t5 + 0;
    a0 = GAME_DATA_GetSeason((const struct BigObj *)a0);
loc_02158498:
    return a0;
loc_0215849A:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = GAME_DATA_GetSlotFlag((const struct BigObj *)a0, a1);
loc_021584A2:
    return a0;}
