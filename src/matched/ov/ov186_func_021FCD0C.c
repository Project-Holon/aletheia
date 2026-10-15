/*
 * function: BR_UTIL_MainListMenu
 * address: 0x021FCD0C
 * packet: pkt_ov186_021FCD0C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_ListMenuIsScrollable 0x021FCDA0 thumb ov186
 *   BR_UTIL_PollScrollDrag 0x021FCEDC thumb ov186
 *   BR_UTIL_DrawListRows 0x021FCE60 thumb ov186
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00048.h"
typedef unsigned int   u32;
extern int BR_UTIL_ListMenuIsScrollable(char *);
extern int BR_UTIL_PollScrollDrag(char *);
extern int GFL_USE_IsSeqPlaying(u32 a);
struct Obj;
extern void BR_UTIL_DrawListRows(char *,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
void BR_UTIL_MainListMenu(char *p)
{
    if(BR_UTIL_ListMenuIsScrollable(p)) {
        ((struct Obj00048 *)p)->f4C=BR_UTIL_PollScrollDrag(p);
        if(((struct Obj00048 *)p)->f4C) {
            if(((int (*)(char *,int))*(int *)(p+0x50))(p,((struct Obj00048 *)p)->f4C)) {
                if(GFL_USE_IsSeqPlaying(0x6FE)==0) GFL_USE_PlaySeDefaultVolume(0x6FE);
                BR_UTIL_DrawListRows(p,((struct Obj00048 *)p)->f42);
            }
            if(((struct Obj00048 *)p)->f4D) {
                if(((struct Obj00048 *)p)->f42==0) CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,0);
                else CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,1);
                if(((struct Obj00048 *)p)->f4==((struct Obj00048 *)p)->f42+((struct Obj00048 *)p)->f44) CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,0);
                else CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,1);
            }
        }
    }
    ((void (*)(char *))*(int *)(p+0x58))(p);
}
