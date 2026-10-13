/*
 * file:     unit_021D64B8.c
 * unit:     yes
 * function: func_021D64B8, func_021D6538
 * address:  0x021D64B8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm
 *   func_0208A998  0x0208A998  arm
 *   func_02088234  0x02088234  arm
 *   func_0208AA2C  0x0208AA2C  arm
 *   func_0208AC0C  0x0208AC0C  arm
 *   func_0208B220  0x0208B220  arm
 *   func_0208B238  0x0208B238  arm
 *   DWCi_IPTlUpdate  0x021D656C  arm
 *   g_021DE688     0x021DE688  data
 */
struct TPCalibrateParam;
extern void *func_021D6414(unsigned long size, int alignment);
extern int func_0208A998(struct TPCalibrateParam *calibrate);
extern void  func_02088234(void);
extern void func_0208AA2C(const struct TPCalibrateParam *param);
extern void  func_0208AC0C(int a, int b, void *c, int d);
extern void func_0208B220(unsigned int command_flgs);
extern unsigned int func_0208B238(unsigned int command_flgs);
extern void  DWCi_IPTlUpdate(void);
extern void func_0208AD14(void);
extern void func_021D6438(void **mem);
void func_021D64B8(void);
void func_021D6538(void);
extern void *g_021DE688[];


void func_021D64B8(void)
{
    char buf[8];

    g_021DE688[1] = func_021D6414(0x3a, 4);
    if (func_0208A998((struct TPCalibrateParam *)buf) == 0)
        func_02088234();
    func_0208AA2C((const struct TPCalibrateParam *)buf);
    func_0208AC0C(0, 4, g_021DE688[1], 5);
    func_0208B220(2);
    if (func_0208B238(2) != 0)
        func_02088234();
    DWCi_IPTlUpdate();
}


/*
 * Drain the channel-4 queue, then post the event at 0x021DE68C.
 * Addresses are Black-image addresses.
 */
void func_021D6538(void)
{
    int v = 4;

    do {
        func_0208AD14();
        func_0208B220(v);
    } while (func_0208B238(v) != 0);
    func_021D6438((void *)0x021DE68C);
}
