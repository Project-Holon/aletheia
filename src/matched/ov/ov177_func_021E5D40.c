/*
 * function: func_021E5D40
 * address: 0x021E5D40
 * packet: pkt_ov177_021E5D40
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E74FC  0x021E74FC  thumb ov177
 *   func_021E73B8  0x021E73B8  thumb ov177
 *   func_021E6EFC  0x021E6EFC  thumb ov177
 *   func_020307B0  0x020307B0  arm
 */
extern void func_021E74FC(char *p);
extern void func_021E73B8(char *p);
extern void func_021E6EFC(unsigned *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021E5D40(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    func_021E74FC(p);
    func_021E73B8(p);
    func_021E6EFC(p);
    func_020307B0(p);
}
