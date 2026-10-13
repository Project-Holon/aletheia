/*
 * function: PMS_INPUT_HandleBrowseInput
 * address: 0x021BEADC
 * packet: pkt_ov110_021BEADC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_CheckUiSwitch 0x021BD808 thumb ov110
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_VIEW_IsTaskNotRunning 0x021B9C90 thumb ov110
 *   PMS_INPUT_HandleBrowseKeys 0x021BE580 thumb ov110
 *   PMS_INPUT_HandleBrowseTouch 0x021BE934 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int PMS_INPUT_CheckUiSwitch(u8 *,void *);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int PMS_INPUT_VIEW_IsTaskNotRunning(unsigned int a, int b);
extern void PMS_INPUT_HandleBrowseKeys(u8 *p, u32 *q);
extern void PMS_INPUT_HandleBrowseTouch(u8 *p, u32 *q);
void PMS_INPUT_HandleBrowseInput(u8 *p,void *q) {
    if(PMS_INPUT_CheckUiSwitch(p,q)) {
        if(p[105]==0) {
            if(*(u32 *)&((struct Obj00012 *)p)->f70==0 && !(KEY_GetTrg()&2)) { GFL_USE_PlaySeDefaultVolume(1352); return; }
        } else {
            if(*(u32 *)&((struct Obj00012 *)p)->f70==0) { GFL_USE_PlaySeDefaultVolume(1352); return; }
        }
    }
    if(PMS_INPUT_VIEW_IsTaskNotRunning((unsigned int)(((struct Obj00012 *)p)->f14),30)) {
        if(*(u32 *)&((struct Obj00012 *)p)->f70==0) PMS_INPUT_HandleBrowseKeys(p,q);
        else PMS_INPUT_HandleBrowseTouch(p,q);
    }
}
