/*
 * function: func_02176DEC
 * address:  0x02176DEC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call that supplies the second argument 1.
 *
 * symbols:
 *   func_02176DFC  0x02176DFC  arm
 */

extern int func_02176DFC(int aid, int type);

int func_02176DEC(int a)
{
    return func_02176DFC(a, 1);
}

