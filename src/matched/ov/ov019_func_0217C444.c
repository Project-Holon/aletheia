/*
 * function: UNION_ONESELF_TalkParentEnd
 * address:  0x0217C444
 * packet:   pkt_ov019_0217C444
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   UNION_MSG_DeleteMainMenu  0x0217F378  thumb ov019
 */

void UNION_MSG_DeleteMainMenu(void *p);

int UNION_ONESELF_TalkParentEnd(void *p)
{
    UNION_MSG_DeleteMainMenu(p);
    return 1;
}
