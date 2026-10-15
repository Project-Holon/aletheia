/*
 * function: INTRO_G3D_UpdateIntro
 * address: 0x021BFA40
 * packet: pkt_ov204_021BFA40
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_IncObjectAnimeFrame 0x020478B8 arm
 *   G3D_SYSTEM_DisableObjectAnime 0x020477D4 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   INTRO_G3D_SetAnimFrame 0x021BFBC8 thumb ov204
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj06676.h"

extern void func_0207D63C(void *, int, int, int, int);
typedef unsigned int   u32;
struct G3dSys;
struct Owner;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *, int, int);
extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void INTRO_G3D_SetAnimFrame(char *, unsigned int);

int INTRO_G3D_UpdateIntro(char *p)
{
    switch (((struct Obj06676 *)p)->f24)
    {
    case 0:
        func_0207D63C((void *)0x04000050, 1, 9, 0, 0);
        GFL_USE_PlaySeDefaultVolume(0x555);
        ++((struct Obj06676 *)p)->f24;
    case 1:
    {
        void *obj = (void *)func_02048A18(((struct Obj06676 *)p)->f8, ((struct Obj06676 *)p)->f10);
        int a = G3D_SYSTEM_IncObjectAnimeFrame(obj, 3, 4096);
        int b = G3D_SYSTEM_IncObjectAnimeFrame(obj, 4, 4096);
        if (a == 0 && b == 0)
        {
            G3D_SYSTEM_DisableObjectAnime(obj, 3);
            G3D_SYSTEM_DisableObjectAnime(obj, 4);
            G3D_SYSTEM_EnableObjectAnime(obj, 0);
            G3D_SYSTEM_EnableObjectAnime(obj, 1);
            G3D_SYSTEM_EnableObjectAnime(obj, 2);
            INTRO_G3D_SetAnimFrame(p, 60);
            ++((struct Obj06676 *)p)->f24;
        }
        break;
    }
    case 2:
        return 1;
    }
    return 0;
}
