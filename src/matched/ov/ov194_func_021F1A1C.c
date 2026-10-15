/*
 * function: NAMEIN_GRAPHIC_SetupCursor
 * address: 0x021F1A1C
 * packet: pkt_ov194_021F1A1C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 478 instruction bytes; 021F1BFA is two-byte zero alignment before021F1BFC.
 * lever: const Rect source schedules the loads ahead of argument stores; signed y destinations avoid an extra unsigned truncation pair (484/224 to482/157 toEXACT*478).
 * symbols:
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_020355C4 0x020355C4 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj01427.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Rect {int left,top,right,bottom;} Rect;
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u8 func_020355C4(void);
struct Actor;
extern void CLACT_RestartActorAnim(struct Actor *a);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void BG_SYS_PushTile(unsigned),MI_CpuFill8(void *,int,int);
void NAMEIN_GRAPHIC_SetupCursor(char *p,int mode,const Rect *rect,int flag,int selected)
{
    int x;
    short y;
    ((struct Obj01427 *)p)->f98=0;
    ((struct Obj01427 *)p)->f94=mode;
    ((struct Obj01427 *)p)->f9C=flag;
    ((struct Obj01427 *)p)->fA0=selected;
    BG_SYS_FillTileMap(2,0,0,32,24,1);
    BG_SYS_FillTileMap(1,0,0,32,24,1);
    if(flag!=0 && selected==3) {
        BG_SYS_FillTileMap(1,3,16,4,3,4);
        BG_SYS_FillTileMap(1,23,16,4,3,4);
    }
    x=(selected+1)*3;
    BG_SYS_FillTileMap(1,x,20,3,3,4);
    BG_SYS_FillTileMap(2,x,20,3,3,4);
    if(rect && mode!=0) {
        *(Rect *)(p+0x84)=*rect;
        if(mode==2) {
            BG_SYS_FillTileMap(2,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
            BG_SYS_FillTileMap(1,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
        }
        if(func_020355C4()==0) {
            ((struct Obj01427 *)p)->fAC=rect->left*8+7;
            y=rect->top*8+(rect->bottom-rect->top)*4-3;
            ((struct Obj01427 *)p)->fAE=y;
            ((struct Obj01427 *)p)->fB0=rect->right*8-7;
            ((struct Obj01427 *)p)->fB2=y;
            CLACT_RestartActorAnim(((struct Obj01427 *)p)->fA4);
            CLACT_RestartActorAnim(((struct Obj01427 *)p)->fA8);
            CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA4,1);
            CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA8,1);
        }
    }
    if(mode==0 || func_020355C4()==1) {
        CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA4,0);
        CLACT_SetActorDrawEnable(((struct Obj01427 *)p)->fA8,0);
    }
    BG_SYS_PushTile(2);
    BG_SYS_PushTile(1);
    if(mode!=0) {
        MI_CpuFill8(p+0x60,0,32);
        ((struct Obj01427 *)p)->f80=0;
        ((struct Obj01427 *)p)->f98=1;
    }
}
