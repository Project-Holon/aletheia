/*
 * function: SCRCMD_StartMmdlIcaAnime
 * address:  0x021D1A74
 * packet:   pkt_ov021_021D1A74
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
 *   SCRIPT_WORK_GetReturnParam  0x0215910C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_MMDL_ICA_Start  0x021D1894  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u32 SCRIPT_WORK_GetReturnParam(void *a);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void SCRCMD_MMDL_ICA_Start(u8 *p, u32 n);

int SCRCMD_StartMmdlIcaAnime(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    u32 k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    SCRCMD_MMDL_ICA_Start((u8 *)SCRIPT_WORK_GetReturnParam(x), k);
    return 0;
}
