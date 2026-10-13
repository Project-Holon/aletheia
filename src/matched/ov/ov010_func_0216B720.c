/*
 * function: FIELD_G3D_MAP_CmdGetTopTallyEntry
 * address:  0x0216B720
 * packet:   pkt_ov010_0216B720
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200E394  0x0200E394  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0200E4F8  0x0200E4F8  thumb
 *   func_0200E4B0  0x0200E4B0  thumb
 *   sTallyCategoryEntryCount     0x0217219C  data  ov010  a1
 *   sTallyCategoryEntryIds     0x021721BC  data  ov010  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200E394(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int func_0200E4F8(int a0, int a1, int a2);
extern u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);
extern u8 sTallyCategoryEntryCount[];
extern u8 sTallyCategoryEntryIds[];

int FIELD_G3D_MAP_CmdGetTopTallyEntry(int c, int vm)
{
    int i;
    int r5;
    void *r6;
    int best;
    u16 *dst;
    int out;
    int n;

    SCRCMD_WORK_GetScriptWork((void *)vm);
    r6 = func_0200E394(GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)vm)));
    r5 = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    dst = SCRIPT_WORK_ReadWorkPointer((void *)c, (void *)vm);
    n = sTallyCategoryEntryCount[r5];
    best = -1;
    for (i = 0; i < n; i++) {
        int a = func_0200E4F8((int)r6, r5, i + 1);
        int b = func_0200E4B0(r6, r5, i + 1);
        int s = a + b;
        if (best < s) {
            best = s;
            out = sTallyCategoryEntryIds[r5 * 17 + i];
        }
    }
    *dst = out;
    return 0;
}
