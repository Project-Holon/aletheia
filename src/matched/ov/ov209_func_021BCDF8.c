/*
 * function: ZUKAN_LIST_StateFadeIn
 * address: 0x021BCDF8
 * packet: pkt_ov209_021BCDF8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: int step schedules the p copy before movs r6,16; enum step swaps those instructions (DIFF4).
 * symbols:
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   ZUKAN_LIST_UpdateArrowActors 0x021BE5D4 thumb ov209
 *   ZUKAN_LIST_UpdateScrollBarActor 0x021BE588 thumb ov209
 *   ZUKAN_LIST_HideAllActors 0x021BE43C thumb ov209
 *   ZUKAN_LIST_ResetPaletteSlots 0x021BD280 thumb ov209
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   func_0207D534 0x0207D534 arm
 *   ZUKAN_LIST_RequestFade 0x021BC730 thumb ov209
 *   ZUKAN_LIST_StartActorMoveFrames 0x021BC90C thumb ov209
 *   ZUKAN_LIST_UpdateActorMove 0x021BC91C thumb ov209
 */
#include "../include/Obj00088.h"
typedef struct S S;
typedef unsigned short u16;
typedef unsigned char  u8;
extern int FRAME_LIST_UpdateInit(struct S *p);
extern void ZUKAN_LIST_UpdateArrowActors(char *, int);
extern void ZUKAN_LIST_UpdateScrollBarActor(char *);
extern void ZUKAN_LIST_HideAllActors(char *);
extern void ZUKAN_LIST_ResetPaletteSlots(char *);
extern unsigned PALANM_GetFadeRequestBits(const char *);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void ZUKAN_LIST_RequestFade(char *p, u8 a, u8 b);
extern void ZUKAN_LIST_StartActorMoveFrames(char *, int);
extern int ZUKAN_LIST_UpdateActorMove(char *);
enum Value { V0 };
int ZUKAN_LIST_StateFadeIn(char *p)
{
    int step;
    switch (((struct Obj00088 *)p)->fC30) {
    case 0:
        if (FRAME_LIST_UpdateInit(*(S * *)&((struct Obj00088 *)p)->fC2C) == 0) {
            ZUKAN_LIST_UpdateArrowActors(p, 0);
            ZUKAN_LIST_UpdateScrollBarActor(p);
            ZUKAN_LIST_HideAllActors(p);
            ZUKAN_LIST_ResetPaletteSlots(p);
            (((struct Obj00088 *)p)->fC30)++;
        }
        break;
    case 1:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00088 *)p)->fC) == 0) {
            func_0207D534((unsigned short *)0x0400006c, 0);
            func_0207D534((unsigned short *)0x0400106c, 0);
            ZUKAN_LIST_RequestFade(p, step = 16, 0);
            step -= 24;
            ZUKAN_LIST_StartActorMoveFrames(p, step);
            (((struct Obj00088 *)p)->fC30)++;
        }
        break;
    case 2:
        if (ZUKAN_LIST_UpdateActorMove(p) == 0 && PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00088 *)p)->fC) == 0) {
            ((struct Obj00088 *)p)->fC30 = 0;
            return 4;
        }
        break;
    }
    return 3;
}
