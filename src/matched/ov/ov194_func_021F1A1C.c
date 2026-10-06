/*
 * function: func_021F1A1C
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
 *   func_020413B0 0x020413B0 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj01427.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Rect {int left,top,right,bottom;} Rect;
extern void func_020413B0(unsigned,u8,u8,u8,u8,u8);
extern u8 func_020355C4(void);
struct Actor;
extern void func_0204B9A0(struct Actor *a);
struct Obj;
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_020409B4(unsigned),func_02082BCC(void *,int,int);
void func_021F1A1C(char *p,int mode,const Rect *rect,int flag,int selected)
{
    int x;
    short y;
    ((struct Obj01427 *)p)->f98=0;
    ((struct Obj01427 *)p)->f94=mode;
    ((struct Obj01427 *)p)->f9C=flag;
    ((struct Obj01427 *)p)->fA0=selected;
    func_020413B0(2,0,0,32,24,1);
    func_020413B0(1,0,0,32,24,1);
    if(flag!=0 && selected==3) {
        func_020413B0(1,3,16,4,3,4);
        func_020413B0(1,23,16,4,3,4);
    }
    x=(selected+1)*3;
    func_020413B0(1,x,20,3,3,4);
    func_020413B0(2,x,20,3,3,4);
    if(rect && mode!=0) {
        *(Rect *)(p+0x84)=*rect;
        if(mode==2) {
            func_020413B0(2,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
            func_020413B0(1,rect->left,rect->top,rect->right-rect->left,rect->bottom-rect->top,mode+1);
        }
        if(func_020355C4()==0) {
            ((struct Obj01427 *)p)->fAC=rect->left*8+7;
            y=rect->top*8+(rect->bottom-rect->top)*4-3;
            ((struct Obj01427 *)p)->fAE=y;
            ((struct Obj01427 *)p)->fB0=rect->right*8-7;
            ((struct Obj01427 *)p)->fB2=y;
            func_0204B9A0(((struct Obj01427 *)p)->fA4);
            func_0204B9A0(((struct Obj01427 *)p)->fA8);
            func_0204B3DC(((struct Obj01427 *)p)->fA4,1);
            func_0204B3DC(((struct Obj01427 *)p)->fA8,1);
        }
    }
    if(mode==0 || func_020355C4()==1) {
        func_0204B3DC(((struct Obj01427 *)p)->fA4,0);
        func_0204B3DC(((struct Obj01427 *)p)->fA8,0);
    }
    func_020409B4(2);
    func_020409B4(1);
    if(mode!=0) {
        func_02082BCC(p+0x60,0,32);
        ((struct Obj01427 *)p)->f80=0;
        ((struct Obj01427 *)p)->f98=1;
    }
}
