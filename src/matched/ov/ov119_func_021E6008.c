/*
 * function: POKETRADE_2D_CreateCuredPokerusIcon
 * address: 0x021E6008
 * packet: pkt_ov119_021E6008
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: caller truncates x to u8 despite callee's wider x type.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02027748 0x02027748 thumb
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   POKERUS_IsCured  0x0201B280  thumb  arm9
 */
#include "../include/Obj00001.h"
#include "../include/Obj08074.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { int f0,f4,f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;
extern unsigned int POKERUS_IsCured(void *a);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
typedef unsigned int   u32;
extern u32 func_020275E4(void);
extern int func_02027748(void);
extern int func_0202774C(int);
extern int func_02027750(int);
extern int func_02027754(int);
extern void UI_SCENE_LoadActorGfx(void *, In *, int, u16);
extern int UI_SCENE_CreateActor(void *, int, u8, u16, u8, u16);
void POKETRADE_2D_CreateCuredPokerusIcon(char *p, int b, void *c)
{
    char *q = p + 0x978;
    In in;
    int a = POKERUS_IsCured(c);
    if (a == 0) return;
    if (((struct Obj08074 *)q)->f10) {
        if (a == 0) CLACT_SetActorDrawEnable((struct Obj *)((struct Obj08074 *)q)->f10, 0);
        else CLACT_SetActorDrawEnable((struct Obj *)((struct Obj08074 *)q)->f10, 1);
        return;
    }
    in.f0 = 1; in.b1c = 14; in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_02027748();
    in.f10 = func_0202774C(2);
    in.f14 = func_02027750(2);
    in.f18 = func_02027754(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q, &in, ((struct Obj00001 *)p)->f9C4, ((struct Obj00001 *)p)->f5F4);
    ((struct Obj08074 *)q)->f10 = UI_SCENE_CreateActor(q, ((struct Obj00001 *)p)->f9C4, 108 + b * 128, 20, 13, ((struct Obj00001 *)p)->f5F4);
}
