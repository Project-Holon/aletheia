/*
 * function: func_021D64B8
 * address:  0x021D64B8
 * packet:   pkt_021D64B8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm
 *   func_0208A998  0x0208A998  arm
 *   func_02088234  0x02088234  arm
 *   func_0208AA2C  0x0208AA2C  arm
 *   func_0208AC0C  0x0208AC0C  arm
 *   func_0208B220  0x0208B220  arm
 *   func_0208B238  0x0208B238  arm
 *   func_021D656C  0x021D656C  arm
 *   g_021DE688     0x021DE688  data
 */

extern void *func_021D6414(unsigned long size, int alignment);
extern int   func_0208A998(void *p);
extern void  func_02088234(void);
extern void  func_0208AA2C(void *p);
extern void  func_0208AC0C(int a, int b, void *c, int d);
extern void func_0208B220(unsigned int command_flgs);
extern unsigned int func_0208B238(unsigned int command_flgs);
extern void  func_021D656C(void);
extern void *g_021DE688[];

void func_021D64B8(void)
{
    char buf[8];

    g_021DE688[1] = func_021D6414(0x3a, 4);
    if (func_0208A998(buf) == 0)
        func_02088234();
    func_0208AA2C(buf);
    func_0208AC0C(0, 4, g_021DE688[1], 5);
    func_0208B220(2);
    if (func_0208B238(2) != 0)
        func_02088234();
    func_021D656C();
}
