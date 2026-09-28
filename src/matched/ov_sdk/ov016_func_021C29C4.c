/*
 * function: endScene2
 * address:  0x021C29C4
 * packet:   pkt_ov016_021C29C4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * symbols:
 *   DWCi_EFFlCheck      0x021D5580  arm
 *   DWCi_BTNlIsEnd      0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd 0x021D5CA8  arm
 *   DWCi_COMMENTlDelete 0x021BD138  arm
 *   DWCi_GXlInvisible   0x021D6090  arm
 *   DWCi_SetParam_      0x021C0E50  arm
 *   DWCi_ChangeScene    0x021C0E40  arm
 *   DWCi_SceneOptMenu   0x021C2A3C  arm
 */

int DWCi_EFFlCheck(int lcd);
int DWCi_BTNlIsEnd(void);
void DWCi_FNTlDeleteBgLcd(int lcd);
int DWCi_COMMENTlDelete(void);
void DWCi_GXlInvisible(int lcd, int plane);
void DWCi_SetParam_(unsigned int param0, unsigned int param1);
void DWCi_ChangeScene(void (*scene)(void));
void DWCi_SceneOptMenu(void);

void endScene2(void)
{
    if (DWCi_EFFlCheck(1)) return;
    if (DWCi_EFFlCheck(0)) return;
    if (!DWCi_BTNlIsEnd()) return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 1);
    DWCi_ChangeScene(DWCi_SceneOptMenu);
}
