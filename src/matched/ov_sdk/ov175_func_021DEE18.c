/*
 * function: func_021DEE18
 * address:  0x021DEE18
 * packet:   pkt_021DEE18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DE840  0x021DE840  arm
 *
 * Voice state tail: the +0x0c cursor is the gate -- a null one returns
 * immediately; otherwise the +0x08 block's third word and the cursor's head
 * word are handed to func_021DE840.
 */

struct SAKEField;
extern void func_021DE840(int numFields, struct SAKEField *record);

void func_021DEE18(char *p)
{
    int *q = *(int **)(p + 0xc);
    int *r = *(int **)(p + 8);

    if (q == 0)
        return;
    func_021DE840(r[2], (struct SAKEField *)q[0]);
}

