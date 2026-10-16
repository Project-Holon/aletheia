/*
 * unit: yes
 * function: ZUKAN_INFO_SetPokemonPage
 * address: 0x021BA6B0
 * packet: pkt_ov206_021BA6B0
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   ZUKAN_INFO_ReleaseActor 0x021BB160 thumb ov206
 *   ZUKAN_INFO_ClearActors 0x021BA4F4 thumb ov206
 *   ZUKAN_INFO_FlushMainWindow 0x021BB0FC thumb ov206
 *   ZUKAN_INFO_RefreshDisplay 0x021BBC38 thumb ov206
 *   ZUKAN_INFO_RefreshPage 0x021BBC68 thumb ov206
 *   ZUKAN_INFO_SetActors 0x021BB13C thumb ov206
 *   ZUKAN_INFO_SetSlotDrawEnable 0x021BBE34 thumb ov206
 */
#include "../include/Obj00551.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *POKE_PERSONAL_Create(unsigned int a, int b, unsigned int c);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern void ZUKAN_INFO_ReleaseActor(char *p, int i);
extern void ZUKAN_INFO_ClearActors(char *p);
extern void ZUKAN_INFO_FlushMainWindow(void *obj);
struct S;
extern void ZUKAN_INFO_RefreshDisplay(struct S *p);
extern void ZUKAN_INFO_RefreshPage(struct S *p, int v);
extern void ZUKAN_INFO_SetActors(void *a0, void *a1, void *a2, void *a3);
extern void ZUKAN_INFO_SetSlotDrawEnable(struct S *p, int v);
void ZUKAN_INFO_SetPokemonPage(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7)
{
    int x;
    u32 h;
    int y;
    if (((struct Obj00551 *)p)->f26C != 0) POKE_PERSONAL_Delete(((struct Obj00551 *)p)->f26C);
    ((struct Obj00551 *)p)->f26C = POKE_PERSONAL_Create(a1, a2, ((struct Obj00551 *)p)->f0);
    if (((struct Obj00551 *)p)->fB4 != 0) ((struct Obj00551 *)p)->fB4 = 0; else ((struct Obj00551 *)p)->fB4 = 1;
    if (((struct Obj00551 *)p)->fE0 != 0) ((struct Obj00551 *)p)->fE0 = 0; else ((struct Obj00551 *)p)->fE0 = 1;
    if (((struct Obj00551 *)p)->f190 != 0) ((struct Obj00551 *)p)->f190 = 0; else ((struct Obj00551 *)p)->f190 = 1;
    ZUKAN_INFO_ReleaseActor(p, ((struct Obj00551 *)p)->fB4);
    ZUKAN_INFO_ClearActors(p);
    ((struct Obj00551 *)p)->fC = a1;
    ((struct Obj00551 *)p)->fE = a2;
    ((struct Obj00551 *)p)->f10 = a3;
    ((struct Obj00551 *)p)->f12 = a4;
    ((struct Obj00551 *)p)->f14 = a5;
    ((struct Obj00551 *)p)->f8 = a6;
    h = (u16)POKE_PERSONAL_GetParam(((struct Obj00551 *)p)->f26C, 0x20);
    if (((struct Obj00551 *)p)->fE >= h) ((struct Obj00551 *)p)->fE = 0;
    ZUKAN_INFO_FlushMainWindow(p);
    if (a7 == 6 || ((struct Obj00551 *)p)->fC > 0x1ed) ZUKAN_INFO_RefreshDisplay((struct S *)p);
    else ZUKAN_INFO_RefreshPage((struct S *)p, a7);
    switch (((struct Obj00551 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    ZUKAN_INFO_SetActors(p, (void *)x, (void *)((u16)(y + ((struct Obj00551 *)p)->f1B4)), (void *)(((struct Obj00551 *)p)->fB4));
    ZUKAN_INFO_SetSlotDrawEnable((struct S *)p, (((struct Obj00551 *)p)->f44 != 0) ? 0 : 1);
}
