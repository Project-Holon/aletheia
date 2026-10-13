/*
 * function: STARTMENU_Demo3dUpdate
 * address:  0x021B9DD0
 * packet:   pkt_ov088_021B9DD0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020489F4  0x020489F4  arm
 *   ICA_ANIME_IncFrameNoLoop  0x020115C0  thumb
 *   ICA_ANIME_SetCameraStatus  0x02011B8C  thumb
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   d_021BD538     0x021BD538  data  ov088  a4
 */
#include "../include/Obj03674.h"

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct IcaAnime;
struct Light;
extern u32 func_020489F4(u8 *a0, int i);
extern u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *p, s32 v);
extern void ICA_ANIME_SetCameraStatus(void *, void *);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern u32 func_02048A18(u8 *a0, int i);
struct Arg;
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern void G3D_SYSTEM_DrawEnd(void);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern char d_021BD538[];

void STARTMENU_Demo3dUpdate(int *p)
{
    int base;
    unsigned i;
    void *h;
    base = func_020489F4((void *)p[0], ((struct Obj03674 *)p)->f4);
    ICA_ANIME_IncFrameNoLoop((void *)p[3], 0x1000);
    ICA_ANIME_SetCameraStatus((void *)p[4], (void *)p[3]);
    G3D_CAMERA_Reset((void *)p[4]);
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        G3D_SYSTEM_DrawObject(h, (struct Arg *)d_021BD538);
    }
    G3D_SYSTEM_DrawEnd();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        G3D_SYSTEM_LoopObjectAnimeFrame(h, 0, 0x1000);
        if (i == 0)
            G3D_SYSTEM_LoopObjectAnimeFrame(h, 1, 0x1000);
    }
}
