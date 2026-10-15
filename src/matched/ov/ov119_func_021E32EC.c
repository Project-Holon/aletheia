/*
 * function: POKETRADE_3D_Draw3DScene
 * address:  0x021E32EC
 * packet:   pkt_ov119_021E32EC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_GetObjectAnimeCount  0x0204779C  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   G3D_SYSTEM_DrawStart  0x02047964  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   PARTICLE_DrawAllSystems  0x02051534  arm
 *   PARTICLE_UpdateAllSystems  0x02051574  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   g3dSceneHandlers  0x021E7AC8  data a4
 *   gAnimeFrameCfg  0x021E8144  data a4
 */
#include "../include/Obj00907.h"

typedef unsigned short u16;

typedef struct {
    void (*fn)(char *p, void *out);
    int unused;
} Handler;

typedef struct {
    int x;
    int amount;
} Cfg;

typedef struct {
    char pad00[0x90];
    int *a90;           /* 0x090 */
    int *a94;           /* 0x094 */
    int *a98;           /* 0x098 */
    int *a9C;           /* 0x09C */
    int pada0[2];       /* 0x0A0 */
    int aA8;            /* 0x0A8 */
    int aAC;            /* 0x0AC */
} Sub;

extern const Handler g3dSceneHandlers[];
extern Cfg gAnimeFrameCfg;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
struct Light;
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern int PARTICLE_DrawAllSystems(void);
extern int PARTICLE_UpdateAllSystems(void);
typedef signed int     s32;
struct Arg;
struct IcaAnime;
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);

void POKETRADE_3D_Draw3DScene(char *p)
{
    char buf[0x3C];
    void *q;
    int n;
    int i;
    int idx;

    idx = ((struct Obj00907 *)p)->f109C;
    if (idx == -1)
        return;
    if (g3dSceneHandlers[idx].fn != 0)
        g3dSceneHandlers[idx].fn(p, buf);
    if (((struct Obj00907 *)p)->f824 != 0xFFFF) {
        q = (void *)func_02048A18(((struct Obj00907 *)p)->f820, ((struct Obj00907 *)p)->f824);
        n = G3D_SYSTEM_GetObjectAnimeCount(q);
        for (i = 0; i < n; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(q, (u16)i, gAnimeFrameCfg.amount);
    }
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset(((struct Obj00907 *)p)->f83C);
    G3D_SYSTEM_ApplyLookAt();
    if (((struct Obj00907 *)p)->fC != 0) {
        PARTICLE_DrawAllSystems();
        PARTICLE_UpdateAllSystems();
    }
    if (((struct Obj00907 *)p)->f824 != 0xFFFF)
        G3D_SYSTEM_DrawObject((void *)func_02048A18(((struct Obj00907 *)p)->f820, ((struct Obj00907 *)p)->f824), (struct Arg *)buf);
    if (*(Sub * *)&((struct Obj00907 *)p)->fC != 0) {
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a90 != 0) {
            if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->aA8 == 0)
                (*(Sub * *)&((struct Obj00907 *)p)->fC)->aA8 = ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a90), gAnimeFrameCfg.amount);
            if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->aAC == 0)
                (*(Sub * *)&((struct Obj00907 *)p)->fC)->aAC = ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a94), gAnimeFrameCfg.amount);
        }
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a9C != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a9C), gAnimeFrameCfg.amount);
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a98 != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a98), gAnimeFrameCfg.amount);
    }
}
