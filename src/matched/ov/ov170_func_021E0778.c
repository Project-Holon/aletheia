/*
 * function: BOX2_MAIN_SceneWaitCursor
 * address: 0x021E0778
 * packet: pkt_ov170_021E0778
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb ov170
 */
#include "../include/Obj02502.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_SEQ_GetActorSurfacePos(char *,int,short *,short *,u16);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void BOX2_SEQ_MoveCursorToSlot(char *,int);
#define W(p) (*(char **)((p)+0x2C))
int BOX2_MAIN_SceneWaitCursor(u8 *p)
{
    char *s=W(p)+0x58;
    short xy[2];
    int k;
    switch(((struct Obj02502 *)s)->fC) {
    case 0:
        BOX2_SEQ_SetCursorFrame((char *)p,7);
        (((struct Obj02502 *)s)->fC)++;
    case 1:
        if(((struct Obj02502 *)s)->fE==4) {
            ((struct Obj02502 *)s)->fE=0;
            (((struct Obj02502 *)s)->fC)++;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(W(p),4,&xy[1],&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos(W(p),4,(short)xy[1],(short)(xy[0]+2),(short)0);
        (((struct Obj02502 *)s)->fE)++;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x666);
        BOX2_SEQ_SetCursorFrame((char *)p,8);
        (((struct Obj02502 *)s)->fC)++;
    case 3:
        if(((struct Obj02502 *)s)->fE==4) {
            ((struct Obj02502 *)s)->fE=0;
            ((struct Obj02502 *)s)->fC=0;
            return 0;
        }
        BOX2_SEQ_GetActorSurfacePos(W(p),4,&xy[1],&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos(W(p),4,(short)xy[1],(short)(xy[0]-2),(short)0);
        k=*(u8 *)(W(p)+0x3DF6);
        BOX2_SEQ_GetActorSurfacePos(W(p),k,&xy[1],&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos(W(p),k,(short)xy[1],(short)(xy[0]-2),(short)0);
        BOX2_SEQ_MoveCursorToSlot(W(p),0x24);
        (((struct Obj02502 *)s)->fE)++;
        break;
    }
    return 1;
}
