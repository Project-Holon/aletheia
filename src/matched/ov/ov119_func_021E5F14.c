/*
 * function: func_021E5F14
 * address: 0x021E5F14
 * packet: pkt_ov119_021E5F14
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: x is narrowed to u8 at 021E5FE4/021E5FEC although ov067's callee declares u16.
 * initialization: ov067 UI_SCENE_LoadActorGfx reads only the seven words and bytes 1c..1e initialized below.
 * domain: call 021E1F20 loads side from the 0/1 slot initialized at 021E1E20/021E1E2C; call 021E2406 sets side=0 at 021E2400. Thus side*128+108 is 108 or 236.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020276B4 0x020276B4 thumb
 *   func_020276B8 0x020276B8 thumb
 *   func_020276BC 0x020276BC thumb
 *   func_020276C0 0x020276C0 thumb
 *   func_021E6008 0x021E6008 thumb ov119
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   POKERUS_IsInfected  0x0201B25C  thumb  arm9
 */
#include "../include/Obj00001.h"
#include "../include/Obj06429.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;
extern u32 POKERUS_IsInfected(void *);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern u32 func_020275E4(void);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32);
extern u32 func_020276C0(u32);
extern void func_021E6008(char *p, int b, void *c);
extern void UI_SCENE_LoadActorGfx(void *,In *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u8,u16,u8,u16);
void func_021E5F14(char *p, int side, int flag, void *mon)
{
    char *q = p + 0x964;
    In in;
    u32 a = POKERUS_IsInfected(mon);
    if (((struct Obj06429 *)q)->f10) {
        if (!a) func_0204B3DC((struct Obj *)((struct Obj06429 *)q)->f10,0);
        else func_0204B3DC((struct Obj *)((struct Obj06429 *)q)->f10,1);
        return;
    }
    if (!a) {
        if (!flag) func_021E6008(p,side,(void *)mon);
        return;
    }
    if (flag) { in.f0 = 0; in.b1c = 0; }
    else { in.f0 = 1; in.b1c = 11; }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_020276B4();
    in.f10 = func_020276B8();
    in.f14 = func_020276BC(2);
    in.f18 = func_020276C0(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q,&in,((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f5F4);
    if (flag) ((struct Obj06429 *)q)->f10 = UI_SCENE_CreateActor(q,((struct Obj00001 *)p)->f9C4,244,104,0,((struct Obj00001 *)p)->f5F4);
    else ((struct Obj06429 *)q)->f10 = UI_SCENE_CreateActor(q,((struct Obj00001 *)p)->f9C4,side*128+108,24,0,((struct Obj00001 *)p)->f5F4);
}
