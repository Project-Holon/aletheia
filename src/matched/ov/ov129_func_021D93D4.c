/*
 * function: WF2DMAP_SCENE_ClearSelection
 * address: 0x021D93D4
 * packet: pkt_ov129_021D93D4
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_SCENE_GetCellAnim 0x021DA158 thumb ov129
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 * Lever: subscript each record field; clear_record binds the element before its store.
 */
#include "../include/Obj00912.h"

extern int WF2DMAP_SCENE_GetCellAnim(int x, int flag);
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
typedef struct  {
    int state, value, flag, handle;
    char tail[12];
}
Record;
static inline unsigned clear_record(Record *q)  {
    q->state=0;
    return WF2DMAP_SCENE_GetCellAnim(0,q->flag);
}
void WF2DMAP_SCENE_ClearSelection(const Record *p)  {
    int i, v, next;
    ((struct Obj00912 *)p)->f1DC=1;
    ((struct Obj00912 *)p)->f1F4=0;
    if(((struct Obj00912 *)p)->f240==0)  {
        i=((struct Obj00912 *)p)->f23C-1;
        ((struct Obj00912 *)p)->f188=i;
        next=p[i].value;
        ((struct Obj00912 *)p)->f31C=1;
        ((struct Obj00912 *)p)->f320=next;
        ((struct Obj00912 *)p)->f324=1;
        return;
    }
    i=((struct Obj00912 *)p)->f188;
    CLACT_SetActorAnimSeq((struct Obj *)p[i].handle,clear_record(&((Record *)p)[i]));
    v=p[i].value;
    if(i>0)  {
        CLACT_SetActorAnimSeq((struct Obj *)p[i-1].handle,WF2DMAP_SCENE_GetCellAnim(p[i-1].state,p[i-1].flag));
        next=p[i-1].value;
        if(v!=next)  {
            ((struct Obj00912 *)p)->f31C=1;
            ((struct Obj00912 *)p)->f320=next;
            ((struct Obj00912 *)p)->f324=1;
            return;
        }
        ((struct Obj00912 *)p)->f31C=2;
        ((struct Obj00912 *)p)->f320=i-1;
    }
}
