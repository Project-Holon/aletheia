/*
 * function: func_021C244C
 * address:  0x021C244C
 * packet:   pkt_021C20AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C244C   0x021C244C  arm
 *
 * Call func_021C2460, func_021C2480, func_021C2484.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C244C.c \
 *       --func func_021C244C --addr 0x021C244C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021C2460(void);
extern void func_021C2480(void);
extern void func_021C2484(void);

void func_021C244C(void)
{
    func_021C2460();
    func_021C2480();
    func_021C2484();
}
