/*
 * function: SCRCMD_StopMarkedSeSlots
 * address:  0x021AF26C
 * packet:   pkt_ov021_021AF26C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   SCRIPT_WORK_GetTrainerParam  0x02158F88  thumb  ov010
 *   GFL_USE_StopSeSlot  0x020061F8  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u8 *SCRIPT_WORK_GetTrainerParam(void *p);
extern void GFL_USE_StopSeSlot(int i);

void SCRCMD_StopMarkedSeSlots(u32 a)
{
    int i;
    u8 *p;

    p = SCRIPT_WORK_GetTrainerParam((void *)a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i))
            GFL_USE_StopSeSlot(i);
    }
    *p = 0;
}
