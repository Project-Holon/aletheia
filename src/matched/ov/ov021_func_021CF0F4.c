/*
 * function: COMM_ENTRY_ResetLeaveConfirm
 * address:  0x021CF0F4
 * packet:   pkt_ov021_021CF0F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_MSGBG_DeleteMenuFunc(void *a);

void COMM_ENTRY_ResetLeaveConfirm(u8 *p)
{
    u32 *q = (u32 *)(p + 0x130);

    if (q[0] != 0) {
        FIELD_MSGBG_DeleteMenuFunc((void *)q[0]);
        q[0] = 0;
    }
    ((u8 *)q)[8] = 0;
}
