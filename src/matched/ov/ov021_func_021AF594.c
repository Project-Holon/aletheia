/*
 * function: SCRCMD_RemoveItem
 * address:  0x021AF594
 * packet:   pkt_ov021_021AF594
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
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02007F1C  0x02007F1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct BigObj;
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u16 func_02007F1C(void *, u32, u32, u32);

int SCRCMD_RemoveItem(u32 a, u32 b)
{
    u32 c = SCRCMD_WORK_GetHeapId((void *)b);
    void *d;
    u32 e, f;
    u16 *p;
    d = GAME_DATA_GetMyItem(SCRCMD_WORK_GetGameData((void *)b));
    e = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    f = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    p = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *p = func_02007F1C(d, e, f, c);
    return 0;
}
