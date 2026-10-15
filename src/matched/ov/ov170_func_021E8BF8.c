/*
 * function: BOX2_SEQ_StateClosePmVoiceB
 * address:  0x021E8BF8
 * packet:   pkt_ov170_021E8BF8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_02007A80 0x02007A80 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_SEQ_GotoBox2Main 0x021E949C thumb
 *   BOX2_SEQ_GotoSceneA 0x021EA928 thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 */
#include "../include/Obj00000.h"

struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int func_02007A80(void *save, unsigned bits);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_GotoBox2Main(char *p, int a, int b);
extern int BOX2_SEQ_GotoSceneA(unsigned char *p, int a);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);

#define WORK(p) (*(char **)((p) + 0x2C))
#define SEL(p) (*(unsigned char *)(WORK(p) + 0xA17C))

int BOX2_SEQ_StateClosePmVoiceB(unsigned char *p)
{
    switch ((unsigned)func_02025DE8(*(void **)(WORK(p) + 0x70))) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 5;
            return BOX2_SEQ_GotoBox2Main((char *)p, 0, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA(p, 0);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 1;
            return BOX2_SEQ_GotoBox2Main((char *)p, 1, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA(p, 1);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 2;
            return BOX2_SEQ_GotoBox2Main((char *)p, 2, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA(p, 2);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 3;
            return BOX2_SEQ_GotoBox2Main((char *)p, 3, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA(p, 3);
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 4;
            return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
        }
        if (SEL(p) == 5 && func_02007A80(((void **)((struct Obj00000 *)p)->f0)[1], 2) == 1) {
            SEL(p) = 6;
            return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
        }
        if (SEL(p) == 6) {
            SEL(p) = 5;
            return BOX2_SEQ_GotoBox2Main((char *)p, 4, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA(p, 4);
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (SEL(p) == 0)
            return BOX2_SEQ_GotoBox2Main((char *)p, 5, BOX2_SEQ_ReturnAfterClear((char *)p, 0x5F));
        SEL(p) = 0;
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
    case 0xFFFFFFFE:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (SEL(p) == 0)
            return BOX2_SEQ_GotoBox2Main((char *)p, 5, BOX2_SEQ_ReturnAfterClear((char *)p, 0x5F));
        SEL(p) = 0;
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
    case 0xFFFFFFFD:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x65));
    }
    return 0x65;
}
