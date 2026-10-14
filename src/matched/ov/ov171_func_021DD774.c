/*
 * function: DENDOU_VIEW_AdvanceRotation
 * address: 0x021DD774
 * packet: pkt_ov171_021DD774
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Access the far halfwords as struct members; cache only the guard value, and retain field updates and reads.
 * symbols:
 *   DENDOU_VIEW_GetActiveActorBase 0x021DE5F4 thumb ov171
 *   DENDOU_VIEW_PlaceActorOnEllipse 0x021DE608 thumb ov171
 *   DENDOU_VIEW_SortActorPriorities 0x021DE684 thumb ov171
 */
#include "../include/Obj00142.h"
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef struct { char pad[0xb10]; s16 previous; char gap[10]; s16 current; } Angle;
extern int DENDOU_VIEW_GetActiveActorBase(char *);
extern void DENDOU_VIEW_PlaceActorOnEllipse(char *,int,int);
extern void DENDOU_VIEW_SortActorPriorities(u8 *p);
int DENDOU_VIEW_AdvanceRotation(char *p) {
    int base;
    unsigned i;
    Angle *a;
    int angle;
    base=DENDOU_VIEW_GetActiveActorBase(p);
    if (((struct Obj00142 *)p)->fC62==0) {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous=a->current;
            DENDOU_VIEW_PlaceActorOnEllipse(p,base+i,a->previous);
        }
        DENDOU_VIEW_SortActorPriorities((u8 *)p);
        return 0;
    } else {
        for(i=0;i<*(u16 *)(p+((struct Obj00142 *)p)->fC5E*0xbc+0xc4);i++) {
            a=(Angle *)(p+i*2);
            a->previous+=((struct Obj00142 *)p)->fC61;
            angle=a->previous;
            if (angle<0) a->previous+=360;
            else if (angle>=360) a->previous-=360;
            DENDOU_VIEW_PlaceActorOnEllipse(p,base+i,a->previous);
        }
        DENDOU_VIEW_SortActorPriorities((u8 *)p);
        (((struct Obj00142 *)p)->fC62)--;
        return 1;
    }
}
