/*
 * function: SCRCMD_WaitSeStopped
 * address:  0x021AF2CC
 * packet:   pkt_021AF2CC
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
 *   SCRCMD_IsMarkedSeBusy  0x021AF23C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRCMD_IsMarkedSeBusy(u32 a);

int SCRCMD_WaitSeStopped(u32 a, u32 b, u32 c, u32 d)
{
if (SCRCMD_IsMarkedSeBusy((u32)SCRCMD_WORK_GetScriptWork((void *)b)) == 0) {
    return 1;
}
return 0;
}

