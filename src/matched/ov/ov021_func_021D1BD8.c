/*
 * function: SCRCMD_SUBSCREEN_ResetModeTask
 * address:  0x021D1BD8
 * packet:   pkt_ov021_021D1BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int SCRIPT_WORK_ResetFieldParam(int a0);
typedef unsigned char  u8;
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);
extern void SCRIPT_WORK_ResetCheckFlag(int n);

int SCRCMD_SUBSCREEN_ResetModeTask(u32 *a, int *seq)
{
    u32 r4;

    r4 = FIELDMAP_GetSubscreen((u8 *)(((u32 *)SCRIPT_WORK_ResetFieldParam(a[2]))[1]));
    switch (*seq) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(r4)) {
            FIELD_SUBSCREEN_RequestMode(r4, 0);
            SCRIPT_WORK_ResetCheckFlag(8);
            (*seq)++;
        }
        break;
    case 1:
        if (FIELD_SUBSCREEN_IsIdle(r4)) {
            return 1;
        }
        break;
    }
    return 0;
}
