/*
 * function: func_021CADAC
 * address:  0x021CADAC
 * packet:   pkt_021CA980
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CADAC   0x021CADAC  arm
 *   DWCi_SceneSetRakuButton_draw  0x021CAE04  arm
 *
 * Set r0 to 0xa, call func_02085A38, then run the four ov016 steps.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CADAC.c \
 *       --func func_021CADAC --addr 0x021CADAC --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned int   u32;
extern void func_02085A38(u32 msec);
extern void func_021CAF78(void);
extern void func_021CADCC(void);
extern void DWCi_SceneSetRakuButton_draw(void);
extern void func_021CAE08(void);

void func_021CADAC(void)
{
    func_02085A38(0xa);
    func_021CAF78();
    func_021CADCC();
    DWCi_SceneSetRakuButton_draw();
    func_021CAE08();
}
