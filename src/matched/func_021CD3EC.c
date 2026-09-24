/*
 * function: func_021CD3EC
 * address:  0x021CD3EC
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CD3EC   0x021CD3EC  arm
 *
 * Call func_021CD400, func_021CD404, func_021CD408.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CD3EC.c \
 *       --func func_021CD3EC --addr 0x021CD3EC --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CD400(void);
extern void func_021CD404(void);
extern void func_021CD408(void);

void func_021CD3EC(void)
{
    func_021CD400();
    func_021CD404();
    func_021CD408();
}
