/*
 * function: PDC_MAIN_StepIntro
 * address:  0x021B644C
 * packet:   pkt_ov098_021B644C
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PDC_MSG_StartFadeIn  0x021B6B5C  thumb  ov098
 *   PDC_MSG_IsFadeIdle  0x021B6B68  thumb  ov098
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021F7998  0x021F7998  thumb  ov094
 *   PDC_MAIN_StartFadeIn  0x021B67A4  thumb  ov098
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   PDC_MSG_PrintMessage0  0x021B6910  thumb  ov098
 *   PDC_MSG_Update  0x021B6A3C  thumb  ov098
 *   PDC_GetPokedexSave  0x021B6154  thumb  ov098
 *   PDC_GetMon  0x021B6140  thumb  ov098
 *   func_021F8090  0x021F8090  thumb  ov094
 *   PDC_MAIN_SetStep  0x021B6364  thumb  ov098
 *   PDC_MAIN_StepConfirm  0x021B6504  thumb  ov098
 */
#include "../include/Obj00381.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void PDC_MSG_StartFadeIn(char *p);
extern int PDC_MSG_IsFadeIdle(char *p);
extern void func_021F7EE8(void *m, int key);
extern void func_021F7998(u32 a);
extern void PDC_MAIN_StartFadeIn(int a);
extern int func_021F7EB4(void);
extern void PDC_MSG_PrintMessage0(int a, int b);
extern int PDC_MSG_Update(u8 *p);
extern int PDC_GetPokedexSave(void *p);
extern int PDC_GetMon(void *p);
extern void func_021F8090(u32 a, u32 b, u32 c);
extern void PDC_MAIN_SetStep(u8 *p, u32 v);
extern int PDC_MAIN_StepConfirm(char *p);

int PDC_MAIN_StepIntro(char *p)
{
    int r;

    switch (((struct Obj00381 *)p)->f60) {
    case 0:
        PDC_MSG_StartFadeIn((char *)(((struct Obj00381 *)p)->f14));
        ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        break;
    case 1:
        if (PDC_MSG_IsFadeIdle((char *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_021F7EE8(((struct Obj00381 *)p)->f4, 1);
            func_021F7998(0x231);
            PDC_MAIN_StartFadeIn(2);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            PDC_MSG_PrintMessage0(((struct Obj00381 *)p)->f14, *(int *)&((struct Obj00381 *)p)->f0);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 3:
        if (PDC_MSG_Update((u8 *)(((struct Obj00381 *)p)->f14)) != 0) {
            r = PDC_GetPokedexSave(((struct Obj00381 *)p)->f0);
            func_021F8090(r, PDC_GetMon(((struct Obj00381 *)p)->f0), 1);
            PDC_MSG_StartFadeIn((char *)(((struct Obj00381 *)p)->f14));
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 4:
        if (PDC_MSG_IsFadeIdle((char *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_021F7998(0x23e);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0)
            PDC_MAIN_SetStep((u8 *)p, (u32)PDC_MAIN_StepConfirm);
        break;
    }
    return 0;
}
