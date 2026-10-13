/*
 * function: SCRCMD_StopSe
 * address:  0x021AF2BC
 * packet:   pkt_021AF2BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_StopMarkedSeSlots  0x021AF26C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void SCRCMD_StopMarkedSeSlots(u32 a);

int SCRCMD_StopSe(u32 a, u32 b, u32 c, u32 d)
{
SCRCMD_StopMarkedSeSlots((u32)SCRCMD_WORK_GetScriptWork((void *)b));
return 0;
}

