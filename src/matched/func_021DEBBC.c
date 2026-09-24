/*
 * function: func_021DEBBC
 * address:  0x021DEBBC
 * packet:   pkt_021DEBBC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DE8AC  0x021DE8AC  arm
 *
 * Forward the +0x08 block's third word and the +0x0c cursor's two head words
 * to func_021DE8AC; a null cursor is a no-op.
 */

extern void func_021DE8AC(int, int, int);

void func_021DEBBC(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE8AC(r[2], q[0], q[1]);
}

