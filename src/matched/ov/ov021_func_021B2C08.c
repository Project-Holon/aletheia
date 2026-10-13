/*
 * function: SCRCMD_SCREENEFFECTS_PlayBuildModelAnimPair
 * address:  0x021B2C08
 * packet:   pkt_ov021_021B2C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_SCREENEFFECTS_GetBuildModelMgr  0x021B2BD8  thumb  ov021
 *   SCRCMD_SCREENEFFECTS_FindBuildModelEntry  0x021B2BEC  thumb  ov021
 *   FIELD_BUILDMODEL_PlayEntryAnim  0x0218C69C  thumb  ov021
 * Addresses are Black-image addresses.
 */

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
typedef unsigned int   u32;
extern int SCRCMD_SCREENEFFECTS_GetBuildModelMgr(u32 a);
extern int SCRCMD_SCREENEFFECTS_FindBuildModelEntry(int a, int b, int c, int d);
extern void FIELD_BUILDMODEL_PlayEntryAnim(unsigned char *p, int b, int i, int c);

int SCRCMD_SCREENEFFECTS_PlayBuildModelAnimPair(int a, int b)
{
    int p = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int q = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int r = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int h = SCRCMD_SCREENEFFECTS_GetBuildModelMgr(b);
    int t = SCRCMD_SCREENEFFECTS_FindBuildModelEntry(h, p, q, r);

    if (t) {
        FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)h, t, 0, 1);
        FIELD_BUILDMODEL_PlayEntryAnim((unsigned char *)h, t, 0, 3);
    }
    return 0;
}
