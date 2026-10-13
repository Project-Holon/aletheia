/*
 * function: func_021E2D70
 * address: 0x021E2D70
 * packet: pkt_ov119_021E2D70
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 *   ICA_ANIME_SetFrame 0x020115EC thumb
 */
#include "../include/Obj00673.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void *ICA_ANIME_CreateStream(u32,u32,u32,u32);
typedef signed int     s32;
struct IcaAnime;
extern void ICA_ANIME_SetFrame(struct IcaAnime *p, s32 v);
void func_021E2D70(char *p,unsigned mode)
{
    switch(mode) {
    case 0:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x38,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x39,10);
        ((struct Obj00673 *)p)->f98=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        ((struct Obj00673 *)p)->f9C=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        break;
    case 1:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3f,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3e,10);
        ((struct Obj00673 *)p)->f98=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        break;
    case 2:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3d,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3c,10);
        break;
    case 3:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3b,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3a,10);
        ((struct Obj00673 *)p)->f9C=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        ICA_ANIME_SetFrame(((struct Obj00673 *)p)->f9C,0x2b5000);
        break;
    }
}
