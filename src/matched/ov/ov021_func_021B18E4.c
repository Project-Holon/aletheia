/*
 * function: SCRCMD_FLDMMDL_AddPartyFollowerMmdl
 * address:  0x021B18E4
 * packet:   pkt_ov021_021B18E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderById  0x0216CEE4  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct SaveBlock;
void *SCRCMD_WORK_GetOccupyInfo(void *p);
void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct BigObj;
u32 GAME_DATA_GetEventData(const struct BigObj *p);
u16 EVENTDATA_SYSTEM_GetNpcCount(u8 *p);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
struct Rec44;
unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
u32 GAME_DATA_GetEventWork(const struct BigObj *p);
u32 EVENTDATA_SYSTEM_GetNpcHeaders(u8 *p);
int FLDMMDL_AddMmdlHeaderById(int a, int b, int c, int d, void *e, int f);
void FLDMMDL_OnMoveBitMovePause(void *a0);

int SCRCMD_FLDMMDL_AddPartyFollowerMmdl(int a, int b)
{
    void *r4;
    int r5;
    int r6;
    int s8;
    int sc;
    int s10;
    int r0;

    s8 = (int)SCRCMD_WORK_GetOccupyInfo((void *)b);
    r4 = SCRCMD_WORK_GetGameData((void *)b);
    sc = GAME_DATA_GetEventData(r4);
    r5 = EVENTDATA_SYSTEM_GetNpcCount((u8 *)sc);
    s10 = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAME_DATA_GetMyPlayerWork(r4));
    r6 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    if (r5 != 0) {
        r4 = (void *)GAME_DATA_GetEventWork(r4);
        r0 = FLDMMDL_AddMmdlHeaderById(s8, EVENTDATA_SYSTEM_GetNpcHeaders((u8 *)sc), s10, r5, r4, r6);
        if (r0 != 0) {
            FLDMMDL_OnMoveBitMovePause((void *)r0);
        }
    }
    return 0;
}
