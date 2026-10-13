/*
 * function: SCRCMD_WaitBgmStopped
 * address:  0x021AEEE0
 * packet:   pkt_021AEEE0
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
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 GFL_USE_IsBgmPlaying(void *);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);

int SCRCMD_WaitBgmStopped(u32 a, u32 b, u32 c, u32 d)
{
SCRCMD_WORK_GetGameSystem((void *)b);
if (GFL_USE_IsBgmPlaying(SCRCMD_WORK_GetScriptWork((void *)b)) == 0) {
    return 1;
}
return 0;
}

