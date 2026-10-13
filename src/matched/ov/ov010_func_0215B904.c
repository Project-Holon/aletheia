/*
 * function: SCRCMD_PROC_CountPartyMonsOfSpecies
 * address:  0x0215B904
 * packet:   pkt_ov010_0215B904
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int SCRCMD_PROC_CountPartyMonsOfSpecies(void *a0, void *a1)
{
    u32 key = SCRIPT_WORK_ReadWorkValue(a0, a1);
    u16 *out = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    void *list = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData(a1));
    u16 n = func_0201AA18(list);
    u16 cnt = 0;
    int i;

    if (key != 0 && key <= 0x289) {
        for (i = 0; i < n; i++) {
            void *e = func_0201AB28(list, i);
            u16 t;

            if (e != 0 && POKE_TOOL_GetPartyValue(e, 0x4C, 0) == 0) {
                t = POKE_TOOL_GetPartyValue(e, 5, 0);
                if (t == key) {
                    cnt++;
                }
            }
        }
        *out = cnt;
    } else {
        *out = 0;
    }
    return 0;
}
