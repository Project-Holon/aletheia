/*
 * function: EVENTDATA_SYSTEM_IsSpecialExitConnect
 * address:  0x021625E8
 * packet:   pkt_ov010_021625E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, callee of ov020 EVENT_MAPCHANGE_CreateExitWarpEvent.
 */

typedef unsigned short u16;

typedef struct { u16 h0; u16 h2; } R;

int EVENTDATA_SYSTEM_IsSpecialExitConnect(R *p)
{
    if (p->h2 == 0x100) {
        return 1;
    }
    return 0;
}
