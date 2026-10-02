/*
 * function: func_02159130
 * address: 0x02159130
 * packet: pkt_ov010_02159130
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02172BA0 0x02172BA0 data a4
 *   func_02082A7C 0x02082A7C arm
 */
extern int d_02172BA0;
extern void func_02082A7C(int, void *, int);
void func_02159130(void)
{
    func_02082A7C(0, &d_02172BA0, 4);
}
