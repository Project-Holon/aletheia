/*
 * function: SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotWithSe
 * address:  0x021B2DBC
 * packet:   pkt_ov021_021B2DBC
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
 *   FIELD_BUILDMODEL_GetNodeByHandle  0x0218BA98  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 *   FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry  0x0218C990  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
typedef unsigned int   u32;
extern int SCRCMD_SCREENEFFECTS_GetBuildModelMgr(u32 a);
extern int FIELD_BUILDMODEL_GetNodeByHandle(int a, int b);
extern void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *p, int v, int c);
extern int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(unsigned char *p, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int SCRCMD_SCREENEFFECTS_PlayBuildModelNodeSlotWithSe(int a, int b)
{
    unsigned short v;
    int p = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int q = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    int h = FIELD_BUILDMODEL_GetNodeByHandle(SCRCMD_SCREENEFFECTS_GetBuildModelMgr(b), p);

    if (h) {
        FIELD_BUILDMODEL_PlayNodeSlot((unsigned char *)h, q, 0);
        if (FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry((unsigned char *)h, (int)(&v))) {
            GFL_USE_PlaySeDefaultVolume(v);
        }
    }
    return 0;
}
