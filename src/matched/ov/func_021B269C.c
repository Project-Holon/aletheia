/*
 * function: SCRCMD_GIMMICK44_Cleanup
 * address:  0x021B269C
 * packet:   pkt_021B269C
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
 *   FIELD_GIMMICK_LIFT_SnapLiftToBottom  0x021F3970  thumb  ov044
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void FIELD_GIMMICK_LIFT_SnapLiftToBottom(void *a);

int SCRCMD_GIMMICK44_Cleanup(u32 a, u32 b, u32 c, u32 d)
{
FIELD_GIMMICK_LIFT_SnapLiftToBottom(SCRCMD_WORK_GetGameSystem((void *)b));
return 0;
}

