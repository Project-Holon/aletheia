/*
 * function: UNION_MSG_DeleteSubMenu
 * address:  0x0217F4AC
 * packet:   pkt_ov019_0217F4AC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_MSG_DeleteMenu  0x0217F2F4  thumb ov019
 *
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * UNION_ONESELF_BattleMenuMain.
 */

typedef unsigned char  u8;
void UNION_MSG_DeleteMenu(u8 *p);

void UNION_MSG_DeleteSubMenu(void *ctx)
{
    UNION_MSG_DeleteMenu(ctx);
}
