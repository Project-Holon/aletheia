/*
 * function: SCRCMD_GIMMICK39_TransferSound
 * address:  0x021B23E0
 * packet:   pkt_021B23E0
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
 *   GIMMICK39_TransferSound  0x021F3D74  thumb  ov039
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void GIMMICK39_TransferSound(u32 a);

int SCRCMD_GIMMICK39_TransferSound(u32 a, u32 b, u32 c, u32 d)
{
GIMMICK39_TransferSound((u32)SCRCMD_WORK_GetGameSystem((void *)b));
return 0;
}

