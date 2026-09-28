/*
 * function: func_021CDE6C
 * address:  0x021CDE6C
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CDE6C   0x021CDE6C  arm
 *
 * Call func_021CDE80, func_021CDEBC, func_021CDEC0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CDE6C.c \
 *       --func func_021CDE6C --addr 0x021CDE6C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CDE80(void);
extern void func_021CDEBC(void);
extern void func_021CDEC0(void);

void func_021CDE6C(void)
{
    func_021CDE80();
    func_021CDEBC();
    func_021CDEC0();
}
