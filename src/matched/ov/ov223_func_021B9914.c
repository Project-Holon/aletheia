/*
 * function: PSEL_UpdateListAnime
 * address: 0x021B9914
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9914
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   ICA_ANIME_IncFrameLoop 0x02011590 thumb
 *   PSEL_GRAPHIC_GetCamera 0x021BC52C thumb ov223
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 */
#include "../include/Obj01594.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *,int,int);
typedef signed int     s32;
struct IcaAnime;
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);
extern unsigned PSEL_GRAPHIC_GetCamera(unsigned char *p);
extern void ICA_ANIME_SetCameraStatus(void *,void *);
void PSEL_UpdateListAnime(char *p)
{
    int *obj;
    u32 n;
    u16 i,j;
    for(i=0;i<((struct Obj01594 *)p)->f3A;i++) {
        obj=(int *)func_02048A18(*(unsigned char * *)&((struct Obj01594 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj01594 *)p)->f3C+i*68));
        n=G3D_SYSTEM_GetObjectAnimeCount(obj);
        for(j=0;j<n;j++) G3D_SYSTEM_LoopObjectAnimeFrame(obj,j,2048);
    }
    ICA_ANIME_IncFrameLoop(((struct Obj01594 *)p)->f40,2048);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(((struct Obj01594 *)p)->f14),((struct Obj01594 *)p)->f40);
    (*(u32 *)&((struct Obj01594 *)p)->f50)++;
}
