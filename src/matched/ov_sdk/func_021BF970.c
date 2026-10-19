/*
 * function: taskMain
 * address:  0x021BF970
 * packet:   pkt_021BF970
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   taskMain   0x021BF970  arm
 *
 * Call func_021BF988, func_021BFB38, func_021BFCF8, func_021BFF14.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/taskMain.c \
 *       --func taskMain --addr 0x021BF970 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021BF988(void);
extern void func_021BFB38(void);
extern void func_021BFCF8(void);
extern void func_021BFF14(void);

void taskMain(void)
{
    func_021BF988();
    func_021BFB38();
    func_021BFCF8();
    func_021BFF14();
}
