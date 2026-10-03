/*
 * function: func_021E62A0
 * address: 0x021E62A0
 * packet: pkt_ov177_021E62A0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E7454  0x021E7454  thumb ov177
 *   func_021E73B8  0x021E73B8  thumb ov177
 *   func_021E7270  0x021E7270  thumb ov177
 *   func_021E6EFC  0x021E6EFC  thumb ov177
 *   func_020307B0  0x020307B0  arm
 */
extern void func_021E7454(int *p);
extern void func_021E73B8(char *p);
extern void func_021E7270(char *p);
extern void func_021E6EFC(unsigned *p);
extern void func_020307B0(void *);
void func_021E62A0(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    func_021E7454(p);
    func_021E73B8(p);
    func_021E7270(p);
    func_021E6EFC(p);
    func_020307B0(p);
}
