/*
 * function: CROWD_UpdateChatterSlot
 * address:  0x021F4574
 * packet:   pkt_ov055_021F4574
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf callee of CROWD_UpdateChatter.
 *
 * symbols:
 *   FIELD_MSGBG_DeleteSubMsgWin  0x0219196C  thumb  ov021
 *   CROWD_ClearChatterSlot  0x021F459C  thumb  ov055
 */

typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void FIELD_MSGBG_DeleteSubMsgWin(u32 a, u32 b);
extern void CROWD_ClearChatterSlot(void *p);

void CROWD_UpdateChatterSlot(u16 *p, u32 x)
{
    if (p[0] != 0) {
        s16 *c = (s16 *)p + 3;

        *c = *c + 1;
        if (*c >= 0x10) {
            FIELD_MSGBG_DeleteSubMsgWin(x, p[2]);
            CROWD_ClearChatterSlot(p);
        }
    }
}
