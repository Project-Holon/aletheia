/*
 * function: SCRCMD_MarkSeSlot
 * address:  0x021AF21C
 * packet:   pkt_ov021_021AF21C
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
 *   GFL_USE_GetSeSlot  0x02006148  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u8 *SCRIPT_WORK_GetTrainerParam(void *p);
extern int GFL_USE_GetSeSlot(u32 a);

void SCRCMD_MarkSeSlot(u32 a, u32 b)
{
    u8 *p = SCRIPT_WORK_GetTrainerParam((void *)a);

    *p |= 1 << GFL_USE_GetSeSlot(b);
}
