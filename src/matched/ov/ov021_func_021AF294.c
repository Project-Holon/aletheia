/*
 * function: SCRCMD_PlaySe
 * address:  0x021AF294
 * packet:   pkt_ov021_021AF294
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_ClearFinishedSeSlots  0x021AF1E8  thumb  ov021
 *   SCRCMD_MarkSeSlot  0x021AF21C  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void SCRCMD_ClearFinishedSeSlots(u32 a);
extern void func_020061E4(u32 a);
extern void SCRCMD_MarkSeSlot(u32 a, u32 b);

int SCRCMD_PlaySe(u32 a, u32 b)
{
    u32 x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    void *y = SCRCMD_WORK_GetScriptWork((void *)b);

    SCRCMD_ClearFinishedSeSlots((u32)y);
    func_020061E4(x);
    SCRCMD_MarkSeSlot((u32)y, x);
    return 0;
}
