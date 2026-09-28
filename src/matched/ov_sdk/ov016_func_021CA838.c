/*
 * function: DWCi_SceneSetRakuButton
 * address:  0x021CA838
 * packet:   pkt_ov016_021CA838
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics      0x021CA874 arm
 *   DWCi_HLlLoadSet   0x021BD6D4 arm
 *   DWCi_CMNlMsgDraw  0x021BD29C arm
 *   DWCi_ANIMElInitEx 0x021BC820 arm
 *   DWCi_ChangeScene  0x021C0E40 arm
 *   Choose            0x021DE5F8 data
 *   procInit          0x021CA8F4 arm
 */

void initGraphics(void);
void DWCi_HLlLoadSet(void);
void DWCi_CMNlMsgDraw(int msgId);
void DWCi_ANIMElInitEx(int color);
void DWCi_ChangeScene(void (*scene)(void));
extern unsigned char Choose;
void procInit(void);

void DWCi_SceneSetRakuButton(void)
{
    Choose = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x25);
    DWCi_ANIMElInitEx(1);
    DWCi_ChangeScene(procInit);
}
