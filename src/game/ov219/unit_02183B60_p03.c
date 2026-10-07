/*
 * file:     unit_02183B60_p03.c
 * unit:     yes
 * function: func_02184734, func_02184790, func_02184798, func_021848F4, func_02184968, func_021849A4
 * address:  0x02184734
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02025B3C 0x02025B3C thumb
 *   d_02185E00 0x02185E00 data a4
 *   func_02035C08 0x02035C08 arm
 *   sub_020450F0 0x020450F0 arm
 *   sub_02045770 0x02045770 arm
 *   sub_02043B5C 0x02043B5C arm
 *   sub_02045374 0x02045374 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02049658 0x02049658 arm
 *   func_02049B68 0x02049B68 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   func_02040B94 0x02040B94 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_0204044C 0x0204044C arm
 *   func_02184BAC 0x02184BAC thumb ov219
 *   d_02185E58 0x02185E58 data a4
 *   d_02185E78 0x02185E78 data a4
 *   d_02185DBD 0x02185DBD data a1
 */
#include "../../matched/include/Obj00302.h"
#include "../../matched/include/Obj01012.h"

struct Descriptor;
struct CharBuf;
struct Cfg;
struct BgTemplate;
struct GfFont;
typedef unsigned short u16;

typedef struct {int words[9];} Matrix;

typedef struct {short x,y;Matrix matrix;u16 state,a,b,pad;} Record;

typedef struct {unsigned heap;void *ctx,*save,*field,*data;unsigned count;Record records[];} Records;

typedef struct {unsigned heap;void *ctx,*save,*field,*data;unsigned count;char pad[0xc2dc];int x,y;char pad2[0x40];unsigned a,b;} State;

typedef unsigned char u8;

typedef unsigned int u32;

extern u32 func_02025B3C(u32);
extern int func_02035C08(const void *);
extern u32 sub_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *sub_02045770(struct Descriptor*);
extern void sub_02043B5C(struct CharBuf*,u8);
extern void sub_02045374(struct Cfg*);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201DE00(u8 *,u8 *,u8 *),func_0201DD78(u32,u32,u32);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32),func_020414EC(u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040EBC(u32,u32);
extern void func_0201F73C(void *,int,int,int),func_02045334(struct Descriptor *),func_0204044C(u32),func_02184BAC(char *);
void func_02184734(State *p);
u32 func_02184790(u32 key);
void func_02184798(char *p);
void func_021848F4(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance);
u32 func_02184968(const u8 *p,int flag);
void func_021849A4(char *p,void *arc);
extern const char d_02185E00[];
extern const struct BgTemplate d_02185E58,d_02185E78;
extern const u8 d_02185DBD[];

/*
 * lever: full context member offsets preserve the c2f4 pool base; a cast Tail pointer instead hoists p+c2f4 and raw scalar offsets pool c33c.
 * extent: unlabelled92-byte follower inside handed021846B8 extent; next labelled stub02184790 excluded.
 */
void func_02184734(State *p)
{
    unsigned i;
    for(i=0;i<p->count;i++){
        if(((Records *)p)->records[i].a==p->a && ((Records *)p)->records[i].b==p->b){
            ((Records *)p)->records[i].state=3;
            p->x=((Records *)p)->records[i].x;
            p->y=((Records *)p)->records[i].y;
        }
    }
}

u32 func_02184790(u32 key){return func_02025B3C(key);}

void func_02184798(char *p)
{
    int flag=0;
    int result;
    int xf,dx,yf,dy;
    ((struct Obj00302 *)p)->fC320=0;
    result=func_02035C08(d_02185E00);
    if(result==0)flag=0x400;
    else if(result==1)flag=2;
    if(((struct Obj00302 *)p)->fC35C!=0){
        if(flag!=0){((struct Obj00302 *)p)->fC320=flag;return;}
        ((struct Obj00302 *)p)->fC324=0;
        ((struct Obj00302 *)p)->fC330=0;
        ((struct Obj00302 *)p)->fC334=0;
        ((struct Obj00302 *)p)->fC338=0;
        ((struct Obj00302 *)p)->fC320=0;
        ((struct Obj00302 *)p)->fC328=((struct Obj00302 *)p)->fC364;
        ((struct Obj00302 *)p)->fC32C=((struct Obj00302 *)p)->fC368;
        ((struct Obj00302 *)p)->fC338=4;
    }
    if(((struct Obj00302 *)p)->fC360!=0){
        switch(((struct Obj00302 *)p)->fC324){
        case 0:
            if(((struct Obj00302 *)p)->fC338==0)(((struct Obj00302 *)p)->fC324)++;
            else (((struct Obj00302 *)p)->fC338)--;
        case 1:
            if(flag!=0)return;
            func_021848F4(p,((struct Obj00302 *)p)->fC328,((struct Obj00302 *)p)->fC32C,&xf,&dx,&yf,&dy);
            ((struct Obj00302 *)p)->fC320=xf|yf;
            ((struct Obj00302 *)p)->fC330=dx;
            ((struct Obj00302 *)p)->fC334=dy;
            ((struct Obj00302 *)p)->fC328=((struct Obj00302 *)p)->fC364;
            ((struct Obj00302 *)p)->fC32C=((struct Obj00302 *)p)->fC368;
            return;
        default:return;
        }
    }else{
        if(flag==0 && ((struct Obj00302 *)p)->fC338!=0 && ((struct Obj00302 *)p)->fC330<4 && ((struct Obj00302 *)p)->fC334<4)
            ((struct Obj00302 *)p)->fC320=1;
        ((struct Obj00302 *)p)->fC324=0;
        ((struct Obj00302 *)p)->fC330=0;
        ((struct Obj00302 *)p)->fC334=0;
        ((struct Obj00302 *)p)->fC338=0;
    }
}

/*
 * lever: declare oldx before a named base pointer; this puts oldx in r5
 * and base in r6. Const on the parameter alone left their five-byte swap.
 */
void func_021848F4(const char *p,int x,int y,int *xflag,int *xdistance,int *yflag,int *ydistance)
{
    int oldx;
    const char *base=p;
    int xf=0,yf=0,dx=0,dy=0;
    oldx=((struct Obj00302 *)base)->fC364;
    if(oldx!=0xffff){
        dx=oldx-x;
        if(dx<0){dx^=-1;xf=0x10;}
        else if(dx>0)xf=0x20;
    }
    *xflag=xf;*xdistance=dx&63;
    if(((struct Obj00302 *)base)->fC368!=0xffff){
        dy=((struct Obj00302 *)base)->fC368-y;
        if(dy<0){dy^=-1;yf=0x80;}
        else if(dy>0)yf=0x40;
    }
    *yflag=yf;*ydistance=dy&63;
}

u32 func_02184968(const u8 *p,int flag){u32 q;q=sub_020450F0(p[0],p[1],p[2],p[3],p[4],p[5],1);sub_02043B5C((struct CharBuf*)sub_02045770((struct Descriptor*)q),15);if(flag==1)sub_02045374((struct Cfg*)q);return q;}

/*
 * prototype: explicit original heap shift pairs require narrow extern parameters for D7EC/40B94 despite their full-width own declarations;84968 returns descriptor pointer.
 */
void func_021849A4(char *p,void *arc)
{
    ((struct Obj01012 *)p)->fC06C=func_0201D7EC(0x17,0,0,0,(u16)(((struct Obj01012 *)p)->f0));
    func_0201DE00((u8 *)p+0xc084,(u8 *)p+0xc085,(u8 *)p+0xc086);
    func_0201DD78(1,2,0xf);
    func_0203FCA0(6,&d_02185E58,0);
    func_020414EC(6);
    func_0203FCA0(7,&d_02185E78,0);
    func_02049658(arc,5,7,0,0,0,((struct Obj01012 *)p)->f0);
    func_02049B68(arc,6,4,0,0x80,((struct Obj01012 *)p)->f0);
    func_020498F4(arc,7,7,0,0,0,((struct Obj01012 *)p)->f0);
    func_0201F5BC(6,4,6,0,((struct Obj01012 *)p)->f0);
    func_0201F5BC(6,0x22,7,0,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,4,0x80,0x20,((struct Obj01012 *)p)->f0);
    func_02040B94(6,0x20,0,(u16)(((struct Obj01012 *)p)->f0));
    func_02040EBC(6,0x4753);
    ((struct Obj01012 *)p)->fC01C=(void *)func_02184968(d_02185DBD,1);
    func_0201F73C(((struct Obj01012 *)p)->fC01C,0,4,6);
    func_02045334(((struct Obj01012 *)p)->fC01C);
    ((struct Obj01012 *)p)->fC0B0=0;
    func_0203FCA0(2,&d_02185E58,0);
    func_020414EC(2);
    func_0204044C(1);
    func_0203FCA0(3,&d_02185E78,0);
    func_02049658(arc,5,3,0,0,0,((struct Obj01012 *)p)->f0);
    func_02049B68(arc,6,0,0,0x80,((struct Obj01012 *)p)->f0);
    func_020498F4(arc,7,3,0,0,0,((struct Obj01012 *)p)->f0);
    func_0201F5BC(2,0x22,7,0,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,0,0x80,0x20,((struct Obj01012 *)p)->f0);
    func_02049B40(0x17,5,0,0x100,0x20,((struct Obj01012 *)p)->f0);
    func_02040B94(2,0x20,0,(u16)(((struct Obj01012 *)p)->f0));
    func_02040EBC(2,0);
    func_02184BAC(p);
}
