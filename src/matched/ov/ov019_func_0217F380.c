/*
 * function: UNION_MSG_SelectMainMenu
 * address:  0x0217F380
 * packet:   pkt_ov019_0217F380
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_MSG_SelectMenu  0x0217F310  thumb ov019
 *
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * UNION_ONESELF_TalkParentMain.
 */

typedef unsigned int   u32;
int UNION_MSG_SelectMenu(char *p, u32 a1);

int UNION_MSG_SelectMainMenu(void *ctx, int a)
{
    return UNION_MSG_SelectMenu(ctx, a);
}
