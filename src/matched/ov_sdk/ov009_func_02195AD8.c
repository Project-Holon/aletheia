/*
 * function: gt2CloseSocket
 * address:  0x02195AD8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the two helpers on the argument.
 *
 * symbols:
 *   gt2CloseAllConnectionsHard  0x02195DE4  arm  ov009
 *   func_02197FDC  0x02197FDC  arm  ov009
 */

extern void gt2CloseAllConnectionsHard(int *p);
extern void func_02197FDC(void *p);

void gt2CloseSocket(void *p)
{
    gt2CloseAllConnectionsHard(p);
    func_02197FDC(p);
}

