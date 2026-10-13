/*
 * function: SCRCMD_WORK_CmdSetMapReplaceFlag
 * address:  0x0215AE34
 * packet:   pkt_ov010_0215AE34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   MAP_REPLACE_SetFlag  0x02159F28  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   MAP_MATRIX_ApplyReplace  0x02159CC4  thumb  ov010
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_GetMatrixId  0x02013B44  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void MAP_REPLACE_SetFlag(int a, int b, int flag);
struct BigObj;
struct Rec44;
extern int MAP_MATRIX_Load(int a0, int a1, int a2, int a3);
extern void MAP_MATRIX_ApplyReplace(u32 *a, int b, int c);
extern u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
struct SaveBlock;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_GetMatrixId(u32 id);

int SCRCMD_WORK_CmdSetMapReplaceFlag(int a0, int a1)
{
    void *v0 = SCRCMD_WORK_GetGameSystem((void *)a1);
    void *p = SCRCMD_WORK_GetGameData((void *)a1);
    int x = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int y = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int flag = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int q, r, s, t;
    MAP_REPLACE_SetFlag((int)p, x, y);
    if (flag != 0) {
        q = GAME_DATA_GetFieldWork(p);
        r = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)p));
        s = ZONEDATA_GetMatrixId(r);
        t = SCRCMD_WORK_GetHeapId((void *)a1);
        MAP_MATRIX_Load(q, s, r, t);
        MAP_MATRIX_ApplyReplace((u32 *)q, (int)v0, t);
    }
    return 0;
}
