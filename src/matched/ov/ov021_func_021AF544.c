/*
 * function: SCRCMD_AddItem
 * address:  0x021AF544
 * packet:   pkt_ov021_021AF544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_02007E50  0x02007E50  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 func_02007E50(void *a, u32 b, u32 c, u32 d);

int SCRCMD_AddItem(u32 a, u32 b)
{
    u32 p;
    void *x;
    u32 u, v;
    u16 *h;

    p = SCRCMD_WORK_GetHeapId((void *)b);
    x = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData((void *)b));
    u = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    h = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *h = func_02007E50(x, u, v, p);
    return 0;
}
