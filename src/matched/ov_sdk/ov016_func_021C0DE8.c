/*
 * function: func_021C0DE8
 * address:  0x021C0DE8
 * packet:   pkt_ov016_021C0DE8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procEnd (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   func_0207D42C  0x0207D42C  arm
 *   func_021D7474  0x021D7474  arm  ov016
 *   PM_SetLCDPower 0x0208C64C  arm
 *   func_021D6538  0x021D6538  arm  ov016
 *   func_021D6CE4  0x021D6CE4  arm  ov016
 *   func_021CFF80  0x021CFF80  arm  ov016
 *   func_021D4DC8  0x021D4DC8  arm  ov016
 *   func_021D6EEC  0x021D6EEC  arm  ov016
 *   func_021D5904  0x021D5904  arm  ov016
 *   func_021D556C  0x021D556C  arm  ov016
 *   func_021D4A20  0x021D4A20  arm  ov016
 *   func_021D7588  0x021D7588  arm  ov016
 *   func_021D63A8  0x021D63A8  arm  ov016
 *   func_021D72F8  0x021D72F8  arm  ov016
 */

extern void func_0207D42C(void);
extern void func_021D7474(void);
extern int PM_SetLCDPower(int sw);
extern void func_021D6538(void);
extern void func_021D6CE4(void);
extern void func_021CFF80(void);
extern void func_021D4DC8(void);
extern void func_021D6EEC(void);
extern void func_021D5904(void);
extern void func_021D556C(void);
extern void func_021D4A20(void);
extern void func_021D7588(void);
extern void func_021D63A8(void);
extern void func_021D72F8(void);

void func_021C0DE8(void)
{
    func_0207D42C();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    func_021D7474();
    PM_SetLCDPower(1);
    func_021D6538();
    func_021D6CE4();
    func_021CFF80();
    func_021D4DC8();
    func_021D6EEC();
    func_021D5904();
    func_021D556C();
    func_021D4A20();
    func_021D7588();
    func_021D63A8();
    func_021D72F8();
}
