/*
 * function: DENDOU_VIEW_StateEnterDetail
 * address: 0x021DD10C
 * packet: pkt_ov171_021DD10C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_SetActorAnim 0x021DE080 thumb ov171
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   DENDOU_VIEW_InitPaletteFade 0x021DE76C thumb ov171
 *   DENDOU_VIEW_ApplyPaletteFade 0x021DCBA4 thumb ov171
 *   DENDOU_VIEW_IsPaletteFadeBusy 0x021DCBE8 thumb ov171
 *   DENDOU_VIEW_DrawMemberInfo 0x021DDC28 thumb ov171
 *   DENDOU_VIEW_IsMemberLeftOfCenter 0x021DD5A8 thumb ov171
 *   DENDOU_VIEW_CountRotationSteps 0x021DD5D4 thumb ov171
 *   DENDOU_VIEW_StartRotation 0x021DD620 thumb ov171
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   sRotationStepByCount 0x021DEB50 data a4
 */
#include "../include/Obj01420.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void DENDOU_VIEW_SetActorAnim(u8 *p, int i, int value);
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void DENDOU_VIEW_InitPaletteFade(u8 *p, int mode);
extern void DENDOU_VIEW_ApplyPaletteFade(char *);
extern int DENDOU_VIEW_IsPaletteFadeBusy(u8 *p);
extern void DENDOU_VIEW_DrawMemberInfo(u8 *p);
extern int DENDOU_VIEW_IsMemberLeftOfCenter(u8 *p, int i);
extern u8 DENDOU_VIEW_CountRotationSteps(char *,s8,int,s8);
extern void DENDOU_VIEW_StartRotation(char *p, int step);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern const u8 sRotationStepByCount[];
int DENDOU_VIEW_StateEnterDetail(char *p) {
    s8 old;
    switch (((struct Obj01420 *)p)->fC70) {
    case 0:
        DENDOU_VIEW_SetActorAnim((u8 *)p,12,18);
        DENDOU_VIEW_SetActorAnim((u8 *)p,13,19);
        DENDOU_VIEW_SetActorAnim((u8 *)p,14,14);
        BG_SYS_SetMainPlaneVisible(2,1);
        DENDOU_VIEW_InitPaletteFade((u8 *)p,1);
        DENDOU_VIEW_ApplyPaletteFade(p);
        (((struct Obj01420 *)p)->fC70)++;
        break;
    case 1:
        if (!DENDOU_VIEW_IsPaletteFadeBusy((u8 *)p)) {
            ((struct Obj01420 *)p)->fC70=0;
            old=((struct Obj01420 *)p)->fC5C;
            if (((struct Obj01420 *)p)->fC5D==old) {
                ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
                DENDOU_VIEW_DrawMemberInfo((u8 *)p);
                return 7;
            }
            ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
            if (DENDOU_VIEW_IsMemberLeftOfCenter((u8 *)p,((struct Obj01420 *)p)->fC5D)==1) {
                ((struct Obj01420 *)p)->fC61=-sRotationStepByCount[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                DENDOU_VIEW_StartRotation(p,(s8)(-DENDOU_VIEW_CountRotationSteps(p,old,((struct Obj01420 *)p)->fC5D,1)));
            } else {
                ((struct Obj01420 *)p)->fC61=sRotationStepByCount[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                DENDOU_VIEW_StartRotation(p,(s8)DENDOU_VIEW_CountRotationSteps(p,old,((struct Obj01420 *)p)->fC5D,-1));
            }
            GFL_USE_PlaySeDefaultVolume(0x57b);
            return 9;
        }
        break;
    }
    return 6;
}
