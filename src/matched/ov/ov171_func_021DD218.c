/*
 * function: DENDOU_VIEW_StateDetail
 * address: 0x021DD218
 * packet: pkt_ov171_021DD218
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   DENDOU_VIEW_ReadDetailInput 0x021DE914 thumb ov171
 *   DENDOU_VIEW_StepCursor 0x021DD558 thumb ov171
 *   DENDOU_VIEW_StartRotation 0x021DD620 thumb ov171
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   DENDOU_VIEW_StartButtonAnim 0x021DD500 thumb ov171
 *   DENDOU_VIEW_IsMemberLeftOfCenter 0x021DD5A8 thumb ov171
 *   DENDOU_VIEW_CountRotationSteps 0x021DD5D4 thumb ov171
 *   sRotationStepByCount 0x021DEB50 data a4
 */
#include "../include/Obj00347.h"
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int DENDOU_VIEW_ReadDetailInput(char *);
extern int DENDOU_VIEW_StepCursor(char *, s8);
extern void DENDOU_VIEW_StartRotation(char *p, int step);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int DENDOU_VIEW_StartButtonAnim(char *, int, int, int);
extern int DENDOU_VIEW_IsMemberLeftOfCenter(u8 *p, int i);
extern u8 DENDOU_VIEW_CountRotationSteps(char *, s8, int, s8);
extern const u8 sRotationStepByCount[];
int DENDOU_VIEW_StateDetail(char *p) {
    int choice;
    s8 old;
    if (!PRINTSYS_QUE_IsFinished(((struct Obj00347 *)p)->fB6C)) return 7;
    choice = DENDOU_VIEW_ReadDetailInput(p);
    switch (choice) {
    case 0:
        if (DENDOU_VIEW_StepCursor(p, 1) == 1) {
            ((struct Obj00347 *)p)->fC61 = -sRotationStepByCount[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            DENDOU_VIEW_StartRotation(p, (s8)(-1));
            GFL_USE_PlaySeDefaultVolume(0x57b);
            return 9;
        }
        break;
    case 1:
        if (DENDOU_VIEW_StepCursor(p, -1) == 1) {
            ((struct Obj00347 *)p)->fC61 = sRotationStepByCount[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            DENDOU_VIEW_StartRotation(p, (s8)1);
            GFL_USE_PlaySeDefaultVolume(0x57b);
            return 9;
        }
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return DENDOU_VIEW_StartButtonAnim(p, 15, 9, 8);
    case 5: case 6: case 7: case 8: case 9: case 10:
        old = ((struct Obj00347 *)p)->fC5C;
        if (choice - 5 == old) break;
        ((struct Obj00347 *)p)->fC5C = choice - 5;
        if (DENDOU_VIEW_IsMemberLeftOfCenter((u8 *)p, choice - 5) == 1) {
            ((struct Obj00347 *)p)->fC61 = -sRotationStepByCount[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            DENDOU_VIEW_StartRotation(p, (s8)(-DENDOU_VIEW_CountRotationSteps(p, old, (s8)(choice - 5), 1)));
        } else {
            ((struct Obj00347 *)p)->fC61 = sRotationStepByCount[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            DENDOU_VIEW_StartRotation(p, (s8)DENDOU_VIEW_CountRotationSteps(p, old, (s8)(choice - 5), -1));
        }
        GFL_USE_PlaySeDefaultVolume(0x57b);
        return 9;
    }
    return 7;
}
