/*
 * function: GAME_DATA_GetSaveBlockWork
 * address:  0x02012F8C
 * packet:   pkt_02012F8C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls func_02009448(*p).  Filed as the witness for
 * ov021 SCRCMD_CheckWifiListFlags, SCRCMD_WifiListOperation and SCRCMD_SetWifiFriendNameWord.
 *
 * symbols:
 *   GAME_DATA_GetSaveBlockWork  0x02012F8C  thumb
 *   func_02009448  0x02009448  thumb
 */

typedef unsigned int u32;

struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);

u32 GAME_DATA_GetSaveBlockWork(u32 *p)
{
    return (u32)func_02009448((void *)(*p));
}
