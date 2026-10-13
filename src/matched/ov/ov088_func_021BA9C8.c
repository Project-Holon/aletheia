/*
 * function: STARTMENU_RemoveVblankTask
 * address:  0x021BA9C8
 * packet:   pkt_021BA9C8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 */

struct Node;
void func_02030EAC(struct Node *n);

void STARTMENU_RemoveVblankTask(int *p)
{
    func_02030EAC((struct Node *)p[5]);
}
