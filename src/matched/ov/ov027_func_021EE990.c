/*
 * function: func_021EE990
 * address:  0x021EE990
 * packet:   pkt_ov027_021EE990
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The 2 trailing bytes (0x021EEA02) are alignment padding before
 * func_021EEA04, which is why the verdict is EXACT*.
 *
 * symbols:
 *   func_021A2630  0x021A2630  thumb  ov021
 *   func_021A2638  0x021A2638  thumb  ov021
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A2654  0x021A2654  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 */

int *func_021A2630(int a);
int func_021A2638(int a);
int func_021A2640(int a, short *pt);
void func_021A2654(int a, short *pt);
void func_021A21E0(int a);

void func_021EE990(int a)
{
    int *o = func_021A2630(a);
    short pt[2];

    func_021A2638(a);
    func_021A2640(a, pt);
    if (o[3] == 0) {
        pt[0] = pt[0] + (short)o[4];
        pt[1] = pt[1] + (short)o[2];
        if (o[0] % 5 == 0)
            o[4] = o[4] + o[5];
        if (o[0]++ > o[1])
            o[3] = 1;
        func_021A2654(a, pt);
    } else {
        func_021A21E0(a);
    }
}
