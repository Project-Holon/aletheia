/*
 * function: MYSTERY_ALBUM_SelectHandler
 * address: 0x021DC08C
 * packet: pkt_ov121_021DC08C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * spelling: BF04 uses char-pointer arithmetic and a signed acc read, retaining the post-switch acc reload; raw integer address arithmetic was four bytes short.
 * interfaces: 02035C60's live r0 is consumed by this caller despite its legacy void definition.
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   MYSTERY_ALBUM_StartIntro 0x021DDF5C thumb ov121
 *   MYSTERY_ALBUM_GetColumnCount 0x021DBDB8 thumb ov121
 *   MYSTERY_ALBUM_IsEntryValid 0x021DBF04 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_ALBUM_MoveHandler 0x021DC9CC thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_ALBUM_SaveHandler 0x021DCCE4 thumb ov121
 *   MYSTERY_ALBUM_StartScroll 0x021DBA78 thumb ov121
 *   MYSTERY_ALBUM_DeleteSlotActors 0x021DB528 thumb ov121
 *   MYSTERY_ALBUM_SetCursor 0x021DB478 thumb ov121
 *   MYSTERY_ALBUM_UpdateScroll 0x021DBA94 thumb ov121
 *   MYSTERY_ALBUM_ConfirmHandler 0x021DC4F0 thumb ov121
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   data_021DF86E 0x021DF86E data a1
 */
#include "../include/Obj00061.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Position;
typedef struct {u8 x,y,pad[6];} Coord;
extern const Coord data_021DF86E[];
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u32 KEY_GetRepeat(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void MYSTERY_ALBUM_StartIntro(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int MYSTERY_ALBUM_GetColumnCount(char *);
struct Vec2;
extern int MYSTERY_ALBUM_IsEntryValid(int *p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_ALBUM_MoveHandler(void *task, u32 *state, char *p);
extern void MYSTERY_ALBUM_ConfirmHandler(void *task, u32 *state, u8 *p);
extern void MYSTERY_ALBUM_SaveHandler(void *arg, u32 *state, char *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *);
extern void MYSTERY_ALBUM_StartScroll(u8 *p, int a);
extern void MYSTERY_ALBUM_DeleteSlotActors(char *,int);
extern void MYSTERY_ALBUM_SetCursor(char *,int,int,int,u16);
extern int MYSTERY_ALBUM_UpdateScroll(char *);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
static inline int wrap(int value,int low,int high)
{
    if(value>high) return low;
    if(value<low) return high;
    return value;
}
void MYSTERY_ALBUM_SelectHandler(void *task,u32 *state,char *p)
{
    u32 repeat;
    int delta,changed,count,next,direction;
    Position pos;
    switch(*state) {
    case 0:
        CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF4,1);
        CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF8,1);
        CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAEC,1);
        repeat=KEY_GetRepeat();
        changed=0;delta=0;
        if(TOUCHPANEL_GetTrg()) {
            ((struct Obj00061 *)p)->fAAC=*(void **)((u32)p+0xa7c+(u16)(((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)*4);
            if(((struct Obj00061 *)p)->fAAC) MYSTERY_ALBUM_StartIntro(((struct Obj00061 *)p)->fAAC);
        }
        if(repeat==512) delta=-1;
        else if(repeat==256) delta=1;
        else if(repeat&64) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            switch(((struct Obj00061 *)p)->fACC) {
            case 0:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=2;
                else {((struct Obj00061 *)p)->fAE4=1;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 1:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=3;
                else {((struct Obj00061 *)p)->fAE4=0;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 2: ((struct Obj00061 *)p)->fACC=0;break;
            case 3: ((struct Obj00061 *)p)->fACC=1;break;
            case 4:
                if(((struct Obj00061 *)p)->fAE4) ((struct Obj00061 *)p)->fACC=2;
                else ((struct Obj00061 *)p)->fACC=3;
                break;
            }
            changed=1;
        } else if(repeat&128) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            switch(((struct Obj00061 *)p)->fACC) {
            case 0: ((struct Obj00061 *)p)->fACC=2;break;
            case 1: ((struct Obj00061 *)p)->fACC=3;break;
            case 2:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=0;
                else {((struct Obj00061 *)p)->fAE4=1;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 3:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=1;
                else {((struct Obj00061 *)p)->fAE4=0;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 4:
                if(((struct Obj00061 *)p)->fAE4) ((struct Obj00061 *)p)->fACC=0;
                else ((struct Obj00061 *)p)->fACC=1;
                break;
            }
            changed=1;
        } else if(repeat&32) {
            MYSTERY_ALBUM_GetColumnCount(p);
            if(((struct Obj00061 *)p)->fACC==0 || ((struct Obj00061 *)p)->fACC==2) delta=-1;
            else if(((struct Obj00061 *)p)->fACC!=4) GFL_USE_PlaySeDefaultVolume(0x548);
            if(((struct Obj00061 *)p)->fACC!=4) {
                if(((struct Obj00061 *)p)->fACC<=1) {
                    --((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,0,1);
                } else {
                    --((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,2,3);
                }
                changed=1;
            }
        } else if(repeat&16) {
            MYSTERY_ALBUM_GetColumnCount(p);
            if(((struct Obj00061 *)p)->fACC==1 || ((struct Obj00061 *)p)->fACC==3) delta=1;
            else if(((struct Obj00061 *)p)->fACC!=4) GFL_USE_PlaySeDefaultVolume(0x548);
            if(((struct Obj00061 *)p)->fACC!=4) {
                if(((struct Obj00061 *)p)->fACC<=1) {
                    ++((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,0,1);
                } else {
                    ++((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,2,3);
                }
                changed=1;
            }
        } else if(KEY_GetTrg()&1) {
            if(((struct Obj00061 *)p)->fACC==4) {
                if(((struct Obj00061 *)p)->fAE0==0) {
                    CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF4,0);
                    CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF8,0);
                    GFL_USE_PlaySeDefaultVolume(0x54c);
                    MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SaveHandler);
                }
            } else if(MYSTERY_ALBUM_IsEntryValid((int *)(p+40+220*((u32)*(int *)&((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)))) {
                CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF4,0);
                CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF8,0);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                if(((struct Obj00061 *)p)->fAE0) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_MoveHandler);
                else MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_ConfirmHandler);
            }
        } else if(KEY_GetTrg()&2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            if(((struct Obj00061 *)p)->fAE0) {
                if(*(u8 * *)&((struct Obj00061 *)p)->fABC) {MYSTERY_UTIL_DeleteMenuWindow(*(u8 * *)&((struct Obj00061 *)p)->fABC);((struct Obj00061 *)p)->fABC=0;}
                CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF0,0);
                ((struct Obj00061 *)p)->fAE0=0;
            } else {
                CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF4,0);
                CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF8,0);
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SaveHandler);
            }
        }
        if(delta) {
            count=MYSTERY_ALBUM_GetColumnCount(p);
            if(delta<0) {
                if(((struct Obj00061 *)p)->fAC8) next=((struct Obj00061 *)p)->fAC8-1;
                else next=count-1;
                direction=1;
            } else if(delta>0) {
                if(((struct Obj00061 *)p)->fAC8<count-1) next=((struct Obj00061 *)p)->fAC8+1;
                else next=0;
                direction=0;
            }
            GFL_USE_PlaySeDefaultVolume(0x642);
            MYSTERY_ALBUM_StartScroll((u8 *)p,direction);
            MYSTERY_ALBUM_DeleteSlotActors(p,0);
            MYSTERY_ALBUM_SetCursor(p,0,direction,next,((struct Obj00061 *)p)->f24);
            ((struct Obj00061 *)p)->fAC8=next;
            CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAEC,0);
            CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF4,0);
            CLACT_SetActorDrawEnable(((struct Obj00061 *)p)->fAF8,0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
            *state=1;
        }
        if(changed) {
            if((int)((struct Obj00061 *)p)->fACC<4) {
                pos.x=data_021DF86E[*(u32 *)(p+0xacc)].x*8-24;
                pos.y=data_021DF86E[*(u32 *)(p+0xacc)].y*8-8;
                CLACT_SetActorAnimSeq(((struct Obj00061 *)p)->fAEC,0);
            } else {
                pos.x=176;pos.y=152;
                CLACT_SetActorAnimSeq(((struct Obj00061 *)p)->fAEC,11);
            }
            CLACT_AddActorSurfacePos(((struct Obj00061 *)p)->fAEC,(const struct Vec2 *)(&pos),0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
        }
        break;
    case 1:
        if(MYSTERY_ALBUM_UpdateScroll(p)) *state=0;
        break;
    }
}
