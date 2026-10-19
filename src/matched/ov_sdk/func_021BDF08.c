/*
 * function: taskMain
 * address:  0x021BDF08
 * packet:   pkt_021BDF08
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   taskMain   0x021BDF08  arm
 *
 * Call func_021BDF20, func_021BE0D8, func_021BE3E4, func_021BE618.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/taskMain.c \
 *       --func taskMain --addr 0x021BDF08 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021BDF20(void);
extern void func_021BE0D8(void);
extern void func_021BE3E4(void);
extern void func_021BE618(void);

void taskMain(void)
{
    func_021BDF20();
    func_021BE0D8();
    func_021BE3E4();
    func_021BE618();
}
