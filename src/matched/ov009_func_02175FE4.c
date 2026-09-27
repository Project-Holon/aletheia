/*
 * function: func_02175FE4
 * address:  0x02175FE4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_ResetLastSomeDataRecvTimeByAidAll: restamps every node's transport record.
 *
 * symbols:
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02177748  0x02177748  arm  ov009
 */

extern int func_0217603C(void);
extern unsigned char *func_0217637C(int index);
extern void func_02177748(int aid);

void func_02175FE4(void)
{
    int i;

    for (i = 0; i < func_0217603C(); i++) {
        func_02177748(func_0217637C(i)[0x16]);
    }
}
