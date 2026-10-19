/*
 * function: SCRCMD_POKEMON_FLD_AddTableValueToPoints
 * address:  0x021B72CC
 * packet:   pkt_ov021_021B72CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same ARC_UTIL_LoadMemberWithSize lookup as SCRCMD_POKEMON_FLD_LookupTableValue / SCRCMD_POKEMON_FLD_CheckTableItemInBag.  Here the
 * table byte sScrcmdTableFileIds[idx] is loaded ahead of the `str r0,[sp]` that
 * passes &cnt: that needs the table declared const, otherwise the load
 * may alias the stack store and is scheduled after it.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_AddMoney  0x0200C278  thumb
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   func_020307B0  0x020307B0  arm
 *   sScrcmdTableFileIds     0x021D99D0  data   ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent { u32 k; u32 v; };

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Blk34;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct SaveBlock;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_AddMoney(struct Blk34 *p, u32 v);
extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_020307B0(void *p);
extern const u8 sScrcmdTableFileIds[];

int SCRCMD_POKEMON_FLD_AddTableValueToPoints(u32 a, u32 b)
{
    void *h;
    u32 v;
    u32 k;
    u32 idx;
    struct Ent *arr;
    u32 cnt;
    u32 i;

    v = FIELDMAP_GetHeapId((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork((void *)b)))[1]));
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    idx = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    h = SCRCMD_WORK_GetGameData((void *)b);
    GAME_DATA_GetMyPlayerWork(h);
    arr = (struct Ent *)ARC_UTIL_LoadMemberWithSize(0xd0, sScrcmdTableFileIds[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            BEACON_AddMoney(GAME_DATA_GetMiscSave(h), arr[i].v);
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}
