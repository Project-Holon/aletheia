/*
 * function: SCRCMD_FillPartnerCandidatesFromScript
 * address:  0x021D0084
 * packet:   pkt_021D0084
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
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_FillPartnerCandidates  0x021CFC4C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRCMD_FillPartnerCandidates(void *, int, void *);

int SCRCMD_FillPartnerCandidatesFromScript(u32 a, u32 b, u32 c, u32 d)
{
SCRCMD_WORK_GetScriptWork((void *)b);
SCRCMD_FillPartnerCandidates(SCRCMD_WORK_GetGameSystem((void *)b), SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b), (void *)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b));
return 0;
}

