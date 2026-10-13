/*
 * function: PMS_INPUT_HandleWordListInput
 * address: 0x021BF1C4
 * packet: pkt_ov110_021BF1C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_CheckUiSwitch 0x021BD808 thumb ov110
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PMS_INPUT_HandleWordListKeys 0x021BEE60 thumb ov110
 *   PMS_INPUT_HandleWordListTouch 0x021BF0C0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int PMS_INPUT_CheckUiSwitch(u8 *,void *);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void PMS_INPUT_HandleWordListKeys(u8 *p, u32 *q);
extern void PMS_INPUT_HandleWordListTouch(u8 *p, u32 *q);
void PMS_INPUT_HandleWordListInput(u8 *p,void *q) {
    if(PMS_INPUT_CheckUiSwitch(p,q) && *(u32 *)&((struct Obj00012 *)p)->f70==0 && !(KEY_GetTrg()&2)) { GFL_USE_PlaySeDefaultVolume(1352); return; }
    if(*(u32 *)&((struct Obj00012 *)p)->f70==0) PMS_INPUT_HandleWordListKeys(p,q);
    else PMS_INPUT_HandleWordListTouch(p,q);
}
