/*
 * function: func_021C47A0
 * address:  0x021C47A0
 * packet:   pkt_021C47A0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)

 * BLOCKED.  DIFF: the listing extent 021C47A0..021C47C4 covers 18 bytes of this function plus 18 bytes of untraced code (the veneer at 021C47B4), so the compared range can never close.
 */


extern void func_02014D2C(int, int);

void func_021C47A0(int a, int b, char *c)
{
    if (c == 0)
        return;
    if (*(int *)(c + 8) == 0)
        return;
    func_02014D2C(*(int *)(c + 8), b);
}

