/*
 * function: func_021CA980
 * address:  0x021CA980
 * packet:   pkt_021CA980
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA980   0x021CA980  arm
 *   DWCi_SceneSetListSave_button  0x021CA9D8  arm
 *
 * Set r0 to 0xa, call func_02085A38, then run the four ov016 steps.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CA980.c \
 *       --func func_021CA980 --addr 0x021CA980 --region ov016 --cc dsi/1.1p1 --arm
 */

typedef unsigned int   u32;
extern void func_02085A38(u32 msec);
extern void func_021CAB68(void);
extern void func_021CA9A0(void);
extern void DWCi_SceneSetListSave_button(void);
extern void func_021CA9DC(void);

void func_021CA980(void)
{
    func_02085A38(0xa);
    func_021CAB68();
    func_021CA9A0();
    DWCi_SceneSetListSave_button();
    func_021CA9DC();
}
