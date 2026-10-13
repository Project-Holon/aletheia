/*
 * function: FLD3D_CI_SetupSequence
 * address:  0x021C2320
 * packet:   pkt_ov021_021C2320
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLD_PARTICLE_CreateEffect  0x021C1A48  thumb  ov021
 *   FLD3D_CI_LoadSequence  0x021C24F0  thumb  ov021
 *   FLD3D_CI_SetupEffectUnit  0x021C1C24  thumb  ov021
 *   FLD_PARTICLE_LoadResource  0x021C1A98  thumb  ov021
 *   FLD_PARTICLE_StartEmitter  0x021C1AA8  thumb  ov021
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   BUTTON_MAN_GetResourceType  0x02051B04  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */
#include "../include/Obj00456.h"
#include "../include/Obj00616.h"

typedef unsigned char u8;
typedef unsigned short u16;

int FLD_PARTICLE_CreateEffect(int a);
void FLD3D_CI_LoadSequence(char *q, int d, u16 e);
void FLD3D_CI_SetupEffectUnit(char *p, char *q);
void *FLD_PARTICLE_LoadResource(u16 *p, int a, int b);
typedef unsigned int   u32;
int FLD_PARTICLE_StartEmitter(u32 a, u32 b, u32 c, u32 d);
struct Desc;
struct G3dSys;
u32 func_020489F4(u8 *a0, int i);
u32 func_02048A00(u8 *a0, int i);
u32 func_02048A18(u8 *a0, int i);
struct Evt;
struct Obj;
int G3D_SYSTEM_GetObjectAnimeCount(int *p);
u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
u16 BUTTON_MAN_GetResourceType(void *res);
void *func_020124E4(struct Obj *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void FLD3D_CI_SetupSequence(void *a, char *p, char *q, int d)
{
    int t;
    u8 i;
    int base;
    int cnt;
    u8 k;
    int h;
    int n;
    int r;

    ((struct Obj00616 *)p)->f58 = FLD_PARTICLE_CreateEffect(((struct Obj00616 *)p)->f0);
    FLD3D_CI_LoadSequence(q, d, ((struct Obj00616 *)p)->f10);
    FLD3D_CI_SetupEffectUnit(p, q + 0x10);
    if (((struct Obj00456 *)q)->f28 != 0xFFFF) {
        t = (int)FLD_PARTICLE_LoadResource((u16 *)(((struct Obj00616 *)p)->f0), 0x73, ((struct Obj00456 *)q)->f28);
        FLD_PARTICLE_StartEmitter(((struct Obj00616 *)p)->f0, t, 1, 0);
    } else {
        t = 0;
    }
    base = (int)func_020489F4((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    cnt = (int)func_02048A00((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    for (i = 0; i < cnt; i++) {
        h = (int)func_02048A18((u8 *)(((struct Obj00616 *)p)->f14), (u16)(base + i));
        n = G3D_SYSTEM_GetObjectAnimeCount((int *)h);
        for (k = 0; k < n; k++)
            G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)h, (u8)k);
    }
    ((struct Obj00616 *)p)->f5C = ((struct Obj00456 *)q)->f20;
    ((struct Obj00616 *)p)->f5E = ((struct Obj00456 *)q)->f22;
    ((struct Obj00616 *)p)->f60 = ((struct Obj00456 *)q)->f24;
    ((struct Obj00616 *)p)->f62 = ((struct Obj00456 *)q)->f26;
    if (t != 0)
        r = BUTTON_MAN_GetResourceType((void *)t);
    else
        r = 0;
    if (r == 2) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 0;
    } else if (r == 1) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 1;
    } else {
        ((struct Obj00616 *)p)->f78 = 1;
        ((struct Obj00616 *)p)->f7C = 1;
    }
    ((struct Obj00616 *)p)->f80 = 0;
    ((struct Obj00616 *)p)->f84 = 0;
    if (((struct Obj00456 *)q)->f2E != 0)
        ((struct Obj00616 *)p)->f80 = 1;
    if (((struct Obj00456 *)q)->f2F != 0)
        ((struct Obj00616 *)p)->f84 = 1;
    if (((struct Obj00616 *)p)->f128 != 0) {
        h = (int)func_020124E4((struct Obj *)a);
        GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, a, (void *)(((struct Obj00616 *)p)->f128), (int)0));
    }
}
