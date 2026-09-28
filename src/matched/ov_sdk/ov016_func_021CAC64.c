/*
 * function: DWCi_SceneSetRakuButton1
 * address:  0x021CAC64
 * packet:   pkt_ov016_021CAC64
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics      0x021CACA0 arm
 *   DWCi_HLlLoadSet   0x021BD6D4 arm
 *   DWCi_CMNlMsgDraw  0x021BD29C arm
 *   DWCi_ANIMElInitEx 0x021BC820 arm
 *   DWCi_ChangeScene  0x021C0E40 arm
 *   procInit          0x021CAD20 arm
 */

void initGraphics(void);
void DWCi_HLlLoadSet(void);
void DWCi_CMNlMsgDraw(int msgId);
void DWCi_ANIMElInitEx(int color);
void DWCi_ChangeScene(void (*scene)(void));
void procInit(void);

void DWCi_SceneSetRakuButton1(void)
{
    *(unsigned char *)0x021DE5FC = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x2a);
    DWCi_ANIMElInitEx(2);
    DWCi_ChangeScene(procInit);
}
