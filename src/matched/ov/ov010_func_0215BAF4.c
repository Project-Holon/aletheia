/*
 * function: SCRCMD_PROC_FindPartyMonWithMove
 * address:  0x0215BAF4
 * packet:   pkt_ov010_0215BAF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   SCRCMD_PROC_CheckMonKnowsMove  0x0215B500  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern int SCRCMD_PROC_CheckMonKnowsMove(int a0, int a1);

int SCRCMD_PROC_FindPartyMonWithMove(void *a0, void *a1)
{
    void *list = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(a1));
    u16 *out = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    void *key = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    int i;
    int n = POKEPARTY_GetCount(list);

    *out = 6;
    for (i = 0; i < n; i++) {
        if (SCRCMD_PROC_CheckMonKnowsMove((int)POKEPARTY_GetMember(list, i), (int)key) == 1) {
            *out = i;
            break;
        }
    }
    return 0;
}
