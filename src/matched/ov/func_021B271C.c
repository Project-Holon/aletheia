/*
 * function: SCRCMD_GIMMICK45_SetState
 * address:  0x021B271C
 * packet:   pkt_021B271C
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
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   GIMMICK45_ReplacePlayerIfRequirementMet  0x021F38C4  thumb  ov045
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void GIMMICK45_ReplacePlayerIfRequirementMet(void *a0, int a1);

int SCRCMD_GIMMICK45_SetState(u32 a, u32 b, u32 c, u32 d)
{
GIMMICK45_ReplacePlayerIfRequirementMet(SCRCMD_WORK_GetGameSystem((void *)b), VM_GetU16((struct Stream *)a));
return 0;
}

