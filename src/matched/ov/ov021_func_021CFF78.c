/*
 * function: SCRCMD_IsPartnerCandidateMarked
 * address:  0x021CFF78
 * packet:   pkt_ov021_021CFF78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   SCRCMD_GetPartnerCandidateHistoryIndex  0x021CFCF4  thumb  ov021
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02009634  0x02009634  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Big;
struct Ctx;
struct Sub02009470Obj;
struct Tbl021CFCF4;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetSaveSyncBlock(int base);
extern u8 SCRCMD_GetPartnerCandidateHistoryIndex(struct Tbl021CFCF4 *p, u32 i);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);

int SCRCMD_IsPartnerCandidateMarked(u32 a, u32 b)
{
    u32 h, p, k, r;
    u16 *out;

    SCRCMD_WORK_GetScriptWork((void *)b);
    h = (u32)GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem((void *)b));
    p = GAME_DATA_GetSaveSyncBlock(h);
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *out = 0;
    r = SCRCMD_GetPartnerCandidateHistoryIndex((struct Tbl021CFCF4 *)p, k);
    if (r != 0xff) {
        if ((u8)func_02009634(func_02009470(GAME_DATA_GetSaveControl((struct Big *)h)), r, 5)) {
            *out = 1;
        }
    }
    return 0;
}
