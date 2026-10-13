/*
 * function: P_STA_SKILL_ShowCantForgetMsg
 * address: 0x021DB688
 * packet: pkt_ov131_021DB688
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   P_STATUS_PrintMsgToWin 0x021D618C thumb ov131
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj10523.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void P_STATUS_PrintMsgToWin(unsigned char *p, unsigned int a, int b, int c, unsigned short d, unsigned short e);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void P_STA_SKILL_ShowCantForgetMsg(u8 *a,u8 *b,int c) {
    ((struct Obj10523 *)b)->fC=1;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj10523 *)b)->f8C),0);
    if(c==1) P_STATUS_PrintMsgToWin(a,(unsigned int)(((struct Obj10523 *)b)->f8C),156,0,0,15424);
    GFL_USE_PlaySeDefaultVolume(1367);
}
