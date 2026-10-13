/*
 * function: SCRCMD_POKEMON_FLD_StartOv55SubProc
 * address:  0x021B69B0
 * packet:   pkt_ov021_021B69B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * gCrowdSubprocTemplate is the ov055 proc table (ov055 is the overlay id passed to
 * FIELD_SUBPROC_Start), hence the ov055 token on its symbols: line.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb ov010
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb ov021
 *   ov055_id       0x00000037  data  a1
 *   gCrowdSubprocTemplate     0x021F45F0  data  ov055  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern u32 FIELDMAP_GetMapFunc(u8 *p);
extern int *FIELD_SUBPROC_Start(int, int *, const int *);
extern u8 ov055_id[];
extern const int gCrowdSubprocTemplate[];

int SCRCMD_POKEMON_FLD_StartOv55SubProc(void *a, void *b)
{
    FIELD_SUBPROC_Start((int)ov055_id, (int *)FIELDMAP_GetMapFunc((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam((int)SCRCMD_WORK_GetScriptWork(b)))[1])), gCrowdSubprocTemplate);
    return 0;
}
