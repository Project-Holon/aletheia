/*
 * function: SCRCMD_SUBSCREEN_ChangeModeTask
 * address:  0x021D1AEC
 * packet:   pkt_ov021_021D1AEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);

int SCRCMD_SUBSCREEN_ChangeModeTask(int a, int *seq, u32 *c)
{
    switch (*seq) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(c[0])) {
            FIELD_SUBSCREEN_RequestMode(c[0], c[1]);
            (*seq)++;
        }
        break;
    case 1:
        if (FIELD_SUBSCREEN_IsIdle(c[0])) {
            return 1;
        }
        break;
    }
    return 0;
}
