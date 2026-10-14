/*
 * function: ZUKAN_LIST_UpdateArrowActors
 * address: 0x021BE5D4
 * packet: pkt_ov209_021BE5D4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_CanScrollDown 0x021B93C0 thumb ov067
 *   ZUKAN_LIST_GetActorAnimSeq 0x021BD8B0 thumb ov209
 *   ZUKAN_LIST_StartActorAnim 0x021BD890 thumb ov209
 */
#include "../include/Obj00088.h"
extern int FRAME_LIST_GetCursor(char *);
extern int FRAME_LIST_GetScrollPos(char *);
extern int FRAME_LIST_CanScrollDown(char *);
extern int ZUKAN_LIST_GetActorAnimSeq(char *,int);
extern void ZUKAN_LIST_StartActorAnim(char *,int,int);
void ZUKAN_LIST_UpdateArrowActors(char *p,int flag)
{
    int n=FRAME_LIST_GetCursor(*(char * *)&((struct Obj00088 *)p)->fC2C);
    if (ZUKAN_LIST_GetActorAnimSeq(p,7)!=12 || flag==0) {
        if (FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj00088 *)p)->fC2C)==0 && n==0)
            ZUKAN_LIST_StartActorAnim(p,7,18);
        else ZUKAN_LIST_StartActorAnim(p,7,4);
    }
    if (ZUKAN_LIST_GetActorAnimSeq(p,6)!=13 || flag==0) {
        if (FRAME_LIST_CanScrollDown(*(char * *)&((struct Obj00088 *)p)->fC2C)==0 && n==((struct Obj00088 *)p)->fC34-1) {
            ZUKAN_LIST_StartActorAnim(p,6,19);
            return;
        }
        else ZUKAN_LIST_StartActorAnim(p,6,5);
    }
}
