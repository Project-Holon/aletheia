/*
 * function: func_021DC08C
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
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203633C 0x0203633C arm
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021DDF5C 0x021DDF5C thumb ov121
 *   func_021DBDB8 0x021DBDB8 thumb ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021DC9CC 0x021DC9CC thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DCCE4 0x021DCCE4 thumb ov121
 *   func_021DBA78 0x021DBA78 thumb ov121
 *   func_021DB528 0x021DB528 thumb ov121
 *   func_021DB478 0x021DB478 thumb ov121
 *   func_021DBA94 0x021DBA94 thumb ov121
 *   func_021DC4F0 0x021DC4F0 thumb ov121
 *   func_020061E4 0x020061E4 thumb
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
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_0203633C(void);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_021DDF5C(u8 *p);
extern void func_020061E4(u32 a);
extern int func_021DBDB8(char *);
struct Vec2;
extern int func_021DBF04(int *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021DC9CC(void *task, u32 *state, char *p);
extern void func_021DC4F0(void *task, u32 *state, u8 *p);
extern void func_021DCCE4(void *arg, u32 *state, char *p);
extern void func_021D9E04(u8 *);
extern void func_021DBA78(u8 *p, int a);
extern void func_021DB528(char *,int);
extern void func_021DB478(char *,int,int,int,u16);
extern int func_021DBA94(char *);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
static inline int wrap(int value,int low,int high)
{
    if(value>high) return low;
    if(value<low) return high;
    return value;
}
void func_021DC08C(void *task,u32 *state,char *p)
{
    u32 repeat;
    int delta,changed,count,next,direction;
    Position pos;
    switch(*state) {
    case 0:
        func_0204B3DC(((struct Obj00061 *)p)->fAF4,1);
        func_0204B3DC(((struct Obj00061 *)p)->fAF8,1);
        func_0204B3DC(((struct Obj00061 *)p)->fAEC,1);
        repeat=func_0203633C();
        changed=0;delta=0;
        if(func_02035C60()) {
            ((struct Obj00061 *)p)->fAAC=*(void **)((u32)p+0xa7c+(u16)(((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)*4);
            if(((struct Obj00061 *)p)->fAAC) func_021DDF5C(((struct Obj00061 *)p)->fAAC);
        }
        if(repeat==512) delta=-1;
        else if(repeat==256) delta=1;
        else if(repeat&64) {
            func_020061E4(0x548);
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
            func_020061E4(0x548);
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
            func_021DBDB8(p);
            if(((struct Obj00061 *)p)->fACC==0 || ((struct Obj00061 *)p)->fACC==2) delta=-1;
            else if(((struct Obj00061 *)p)->fACC!=4) func_020061E4(0x548);
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
            func_021DBDB8(p);
            if(((struct Obj00061 *)p)->fACC==1 || ((struct Obj00061 *)p)->fACC==3) delta=1;
            else if(((struct Obj00061 *)p)->fACC!=4) func_020061E4(0x548);
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
        } else if(func_020362DC()&1) {
            if(((struct Obj00061 *)p)->fACC==4) {
                if(((struct Obj00061 *)p)->fAE0==0) {
                    func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                    func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                    func_020061E4(0x54c);
                    func_021DA8B0(task,(u32)func_021DCCE4);
                }
            } else if(func_021DBF04((int *)(p+40+220*((u32)*(int *)&((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)))) {
                func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                func_020061E4(0x54c);
                if(((struct Obj00061 *)p)->fAE0) func_021DA8B0(task,(u32)func_021DC9CC);
                else func_021DA8B0(task,(u32)func_021DC4F0);
            }
        } else if(func_020362DC()&2) {
            func_020061E4(0x551);
            if(((struct Obj00061 *)p)->fAE0) {
                if(*(u8 * *)&((struct Obj00061 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00061 *)p)->fABC);((struct Obj00061 *)p)->fABC=0;}
                func_0204B3DC(((struct Obj00061 *)p)->fAF0,0);
                ((struct Obj00061 *)p)->fAE0=0;
            } else {
                func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                func_021DA8B0(task,(u32)func_021DCCE4);
            }
        }
        if(delta) {
            count=func_021DBDB8(p);
            if(delta<0) {
                if(((struct Obj00061 *)p)->fAC8) next=((struct Obj00061 *)p)->fAC8-1;
                else next=count-1;
                direction=1;
            } else if(delta>0) {
                if(((struct Obj00061 *)p)->fAC8<count-1) next=((struct Obj00061 *)p)->fAC8+1;
                else next=0;
                direction=0;
            }
            func_020061E4(0x642);
            func_021DBA78((u8 *)p,direction);
            func_021DB528(p,0);
            func_021DB478(p,0,direction,next,((struct Obj00061 *)p)->f24);
            ((struct Obj00061 *)p)->fAC8=next;
            func_0204B3DC(((struct Obj00061 *)p)->fAEC,0);
            func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
            func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
            *state=1;
        }
        if(changed) {
            if((int)((struct Obj00061 *)p)->fACC<4) {
                pos.x=data_021DF86E[*(u32 *)(p+0xacc)].x*8-24;
                pos.y=data_021DF86E[*(u32 *)(p+0xacc)].y*8-8;
                func_0204B878(((struct Obj00061 *)p)->fAEC,0);
            } else {
                pos.x=176;pos.y=152;
                func_0204B878(((struct Obj00061 *)p)->fAEC,11);
            }
            func_0204B404(((struct Obj00061 *)p)->fAEC,(const struct Vec2 *)(&pos),0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
        }
        break;
    case 1:
        if(func_021DBA94(p)) *state=0;
        break;
    }
}
