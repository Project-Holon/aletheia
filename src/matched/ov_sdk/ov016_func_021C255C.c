/*
 * function: DWCi_SceneOptInfo
 * address:  0x021C255C
 * packet:   pkt_ov016_021C255C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptInfo (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * symbols:
 *   initGraphics        0x021C2590  arm
 *   DWCi_HLlLoad        0x021BD674  arm
 *   DWCi_COMMENTlDispEx 0x021BD060  arm
 *   drawInfo            0x021C2610  arm
 *   DWCi_ChangeScene    0x021C0E40  arm
 *   procInit            0x021C2820  arm
 */

void initGraphics(void);
void DWCi_HLlLoad(int idx);
int DWCi_COMMENTlDispEx(int messageId, int n, int num);
void drawInfo(void);
void DWCi_ChangeScene(void (*scene)(void));
void procInit(void);

void DWCi_SceneOptInfo(void)
{
    initGraphics();
    DWCi_HLlLoad(0x11);
    DWCi_COMMENTlDispEx(0x3a, -1, 0);
    drawInfo();
    DWCi_ChangeScene(procInit);
}
