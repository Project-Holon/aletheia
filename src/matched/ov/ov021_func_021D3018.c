/*
 * function: SCRCMD_SetEffectPosition
 * address:  0x021D3018
 * packet:   pkt_ov021_021D3018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GIMMICK64_ShowArcModelAt  0x021F3A44  thumb  ov064
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void GIMMICK64_ShowArcModelAt(void *a, int *v);

u32 SCRCMD_SetEffectPosition(u32 a, u32 b)
{
    int v[3];
    void *s0;
    int r6;
    int r7;
    int z;

    s0 = SCRCMD_WORK_GetGameSystem((void *)b);
    r6 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r7 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    z = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v[0] = (r6 << 16) + 0x8000;
    v[1] = r7 << 15;
    v[2] = (z << 16) + 0x8000;
    GIMMICK64_ShowArcModelAt(s0, v);
    return 0;
}
