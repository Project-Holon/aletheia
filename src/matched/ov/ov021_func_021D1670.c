/*
 * function: SCRCMD_CheckWifiListFlags
 * address:  0x021D1670
 * packet:   pkt_ov021_021D1670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * GAME_DATA_GetGameSync (arm9 Thumb leaf) is filed as src/matched/arm9/GAME_DATA_GetGameSync.c
 * to give the witness.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetGameSync  0x02012F8C  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_020092D8  0x020092D8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 GAME_DATA_GetGameSync(u32 *p);
struct Sub02009210Obj;
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern u8 func_020092D8(const struct Sub02009210Obj *obj);

int SCRCMD_CheckWifiListFlags(u32 a, u32 b)
{
    void *r7;
    u32 r6;
    u16 *r4;
    u32 r5;

    SCRCMD_WORK_GetScriptWork((void *)b);
    SCRCMD_WORK_GetGameSystem((void *)b);
    r7 = SCRCMD_WORK_GetGameData((void *)b);
    r6 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    r5 = GAME_DATA_GetGameSync(r7);
    if (r6 == 0) {
        if (func_020092EC((const struct Sub02009210Obj *)r5) == 1 && func_020092D8((const struct Sub02009210Obj *)r5) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
    }
    return 0;
}
