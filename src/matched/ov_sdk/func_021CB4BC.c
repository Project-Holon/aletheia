/*
 * function: func_021CB4BC
 * address:  0x021CB4BC
 * packet:   pkt_021CA980
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CB4BC   0x021CB4BC  arm
 *
 * Set r0 to 0xa, call func_02085A38, then run the four ov016 steps.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CB4BC.c \
 *       --func func_021CB4BC --addr 0x021CB4BC --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_02085A38(int);
extern void func_021CB6A4(void);
extern void func_021CB4DC(void);
extern void func_021CB514(void);
extern void func_021CB518(void);

void func_021CB4BC(void)
{
    func_02085A38(0xa);
    func_021CB6A4();
    func_021CB4DC();
    func_021CB514();
    func_021CB518();
}
