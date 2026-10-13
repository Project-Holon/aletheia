/*
 * function: SCRIPT_WORK_GetPlayerZoneId
 * address:  0x02159B38
 * packet:   pkt_02159B38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct SaveBlock;
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);

int SCRIPT_WORK_GetPlayerZoneId(int a0)
{
    void *p;
    void *v0;

    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_02159B3E:
    p = GAME_DATA_GetMyPlayerWork((struct SaveBlock *)v0);
loc_02159B42:
    a0 = GAME_DATA_GetPlayerZoneId(p);
loc_02159B46:
    return a0;}
