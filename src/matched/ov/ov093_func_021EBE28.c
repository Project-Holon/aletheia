/*
 * function: BTLV_SCU_ProcEntryDoubleLinkLocal
 * address:  0x021EBE28
 * packet:   pkt_ov093_021EBE28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ProcQuickEntryDouble  0x021EB670  thumb  ov093
 *   gBtlvScuDoubleLinkLocalPhases  0x021F3900  data  a4
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 */

typedef unsigned char u8;

extern int BTLV_SCU_ProcQuickEntryDouble(u8 *, int *);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern int (*const gBtlvScuDoubleLinkLocalPhases[][2])(u8 *, int *);


int BTLV_SCU_ProcEntryDoubleLinkLocal(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return BTLV_SCU_ProcQuickEntryDouble(b, a);
    if (b[0x14f] < 3) {
        if (gBtlvScuDoubleLinkLocalPhases[b[0x14f]][BTL_MAIN_GetOwnClientId(*(u8 **)(b + 0x134))](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}
