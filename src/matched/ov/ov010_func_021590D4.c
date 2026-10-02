/*
 * function: func_021590D4
 * address: 0x021590D4
 * packet: pkt_ov010_021590D4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void *func_02158FD0(void *, unsigned int);
extern void func_02082A60(const void *, void *, unsigned int);
extern void func_020307B0(void *);
void func_021590D4(void *a, void *b)
{
    void *p = func_02158FD0(a, 0x8020);
    func_02082A60(b, p, 0x7e);
    func_020307B0(b);
}
