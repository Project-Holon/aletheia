/*
 * function: SCRCMD_PROC_FLD_StoreWifiFriendCount
 * address:  0x021B4C34
 * packet:   pkt_021B4C34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   func_02009A34  0x02009A34  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Sub020097BCObj;
extern u32 func_02009A34(struct Sub020097BCObj *obj);
struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);

int SCRCMD_PROC_FLD_StoreWifiFriendCount(u32 a, u32 b)
{
*SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = func_02009A34((struct Sub020097BCObj *)GAME_DATA_GetWifiList(SCRCMD_WORK_GetGameData((void *)b)));
return 0;
}

