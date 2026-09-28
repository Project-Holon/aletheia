/*
 * function: func_02172E7C
 * address:  0x02172E7C
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_CloseAllConnectionsByTimeout: closes every gt2 connection with the closing flag raised.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   gt2CloseAllConnections  0x02195DE4  arm  ov009
 */

extern char *func_02175F3C(void);
extern void gt2CloseAllConnections(int conn);

void func_02172E7C(void)
{
    func_02175F3C()[0x629] = 1;
    gt2CloseAllConnections(**(int **)(func_02175F3C() + 4));
    func_02175F3C()[0x629] = 0;
}
