/*
 * file:     zukan_toroku_graphic_p01.c
 * unit:     yes
 * function: func_0220AF40, func_0220B048, func_0220B0A4, func_0220B260, func_0220B2E0
 * address:  0x0220AF40
 * region:   ov207
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   overlay67 0x00000043 data
 *   overlay206 0x000000CE data
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0220B318 0x0220B318 thumb ov207
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0220B428 0x0220B428 thumb ov207
 *   func_021B9DE0 0x021B9DE0 thumb ov206
 *   func_0220B55C 0x0220B55C thumb ov207
 *   func_0203D34C 0x0203D34C arm
 *   func_0220B2F8 0x0220B2F8 thumb ov207
 *   func_020056A0 0x020056A0 thumb
 *   func_0204E720 0x0204E720 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0220B6E4 0x0220B6E4 thumb ov207
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0220B3B8 0x0220B3B8 thumb ov207
 *   func_021BA374 0x021BA374 thumb ov206
 *   func_0220B72C 0x0220B72C thumb ov207
 *   func_0204E804 0x0204E804 arm
 *   func_021BA544 0x021BA544 thumb ov206
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_021BA514 0x021BA514 thumb ov206
 *   func_021BA524 0x021BA524 thumb ov206
 *   func_021BA534 0x021BA534 thumb ov206
 *   func_0207D67C 0x0207D67C arm
 *   func_021BA4CC 0x021BA4CC thumb ov206
 *   func_021BA51C 0x021BA51C thumb ov206
 *   func_0220B908 0x0220B908 thumb ov207
 *   func_0220B940 0x0220B940 thumb ov207
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0220B40C 0x0220B40C thumb ov207
 *   func_0220B420 0x0220B420 thumb ov207
 *   func_0220B424 0x0220B424 thumb ov207
 *   func_020414EC 0x020414EC arm
 *   func_0204047C 0x0204047C arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0203FB44 0x0203FB44 arm
 */
#include "../../matched/include/Obj00162.h"

struct GfFont;
struct Obj0203159C;
struct Node;
struct PrintSys;
struct S020315D4;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct Main { u16 heap,pad; void *display,*font; u32 gfx; int enabled,zero; u32 unused[2]; void *mon,*other,*task; int flag,last; };

typedef enum OverlayId { OVERLAY_ZERO=0 } OverlayId;

extern int func_02034AC4(int);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern void *func_0220B318(int,int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *);
extern u32 func_0220B428(u8 *p);
extern void *func_021B9DE0(u16,void *,u32,u32,u32,u32,u8,u32,u32,u32,u32,u32,u32);
extern char *func_0220B55C(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_0203D34C(u32,u32);
extern void func_0220B2F8(int,char *);
extern void *func_020056A0(u32,u32,u32);
extern void func_0204E720(u32,int,int,int);
extern void func_02030EAC(struct Node *n);
extern void func_0220B6E4(unsigned *p);
extern void func_021BA2CC(char *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_0220B3B8(unsigned *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(int);
extern void func_021BA374(char *);
extern int func_0220B72C(char *);
extern int func_0204E804(void);
extern void func_021BA544(char *);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020355D8(u8);
extern void func_021BA514(char *);
extern int func_021BA524(char *);
extern int func_021BA534(char *);
extern void func_0207D67C(u32,int,int,int,int,int);
extern void func_021BA4CC(char *);
extern void func_021BA51C(char *);
extern void func_0220B908(char *);
extern int func_0220B940(char *);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_0220B40C(u8 *p);
extern void func_0220B420(void *);
extern void func_0220B424(void *);
extern void func_020414EC(u32 i);
extern void func_0204047C(int idx, unsigned short val);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_020409B4(u32 index);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
int func_0220AF40(void *owner,int unused,u32 *args);
int func_0220B048(void *a,int b,int c,unsigned *p);
int func_0220B0A4(void *unused,int unused2,u32 *args,u32 *p);
void func_0220B260(unsigned *p);
void func_0220B2E0(u32*p);
extern char overlay67[],overlay206[];
extern char overlay206[],overlay67[];

int func_0220AF40(void *owner,int unused,u32 *args)
{
    struct Main *p;
    int flag;
    func_02034AC4((int)overlay67);
    func_02034AC4((int)overlay206);
    func_0203064C((u32)((void *)1),0x6a,0x80000);
    p=func_0203159C(owner,0x34,0x6a);
    func_02082BCC(p,0,0x34);
    p->heap=0x6a;
    p->display=func_0220B318(1,p->heap);
    p->font=func_0201D7EC(0x17,0,0,0,p->heap);
    p->gfx=func_0201C440((void *)(u32)p->heap);
    if(args[0]==0) { p->enabled=0; p->zero=0; } else { p->enabled=1; p->zero=0; }
    flag=0;
    if(args[0]!=0) flag=1;
    p->mon=func_021B9DE0(p->heap,(void *)args[1],args[2],1,flag,0,0,func_0220B428(p->display),(u32)p->font,p->gfx,0,0,0);
    p->other=func_0220B55C(p->heap,args[1],args[3],args[4],args[5],func_0220B428(p->display),(u32)p->font,p->gfx,args[6]);
    func_0203D34C(0,p->heap);
    if(p->enabled==1) func_0220B260((u32 *)p);
    p->task=func_020056A0((u32)func_0220B2F8,(u32)p,1);
    func_0204E720(3,16,0,2);
    return 1;
}

/*
 * lever: extern overlay-id addresses preserve the pooled FS_OVERLAY_ID values.
 */
int func_0220B048(void *a,int b,int c,unsigned *p)
{
    func_02030EAC((void *)p[10]);
    func_0220B2E0(p);
    func_0220B6E4((void *)p[9]);
    func_021BA2CC((void *)p[8]);
    func_0201C6EC((void *)p[3]);
    func_0201C4C0((void *)p[3]);
    func_0201D83C((void *)p[2]);
    func_0220B3B8((void *)p[1]);
    func_020315D4(a);
    func_020306F0(106);
    func_02034A5C((OverlayId)overlay206);
    func_02034A5C((OverlayId)overlay67);
    return 1;
}

/*
 * ABI: 02035C60 is void in its matched forwarder, but this caller keeps and tests live r0.
 */
int func_0220B0A4(void *unused,int unused2,u32 *args,u32 *p)
{
    int done=0;
    int result,flag,input;
    func_021BA374((char *)p[8]);
    result=func_0220B72C((char *)p[9]);
    switch(p[4]) {
    case 0:
        switch(p[5]) {
        case 0:
            if(func_0204E804()==0) { func_021BA544((char *)p[8]); p[5]=1; }
            break;
        case 1:
            flag=0;
            input=func_02035C60();
            if(func_020362DC()&3) { func_020355D8(0); flag=1; }
            if(input!=0) { func_020355D8(1); flag=1; }
            if(flag!=0) { func_021BA514((char *)p[8]); p[5]=2; }
            break;
        case 2:
            if(func_021BA524((char *)p[8])!=0 || func_021BA534((char *)p[8])!=0) { p[7]=0; p[6]=16; p[5]=3; }
            break;
        case 3:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]--; }
            func_0207D67C(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==0) { func_021BA4CC((char *)p[8]); func_0220B260(p); p[5]=4; }
            break;
        case 4:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]++; }
            func_0207D67C(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==16) p[5]=5;
            break;
        case 5:
            if(func_021BA534((char *)p[8])!=0) { p[4]=1; p[5]=1; }
            break;
        }
        break;
    case 1:
        switch(p[5]) {
        case 0:
            if(func_0204E804()==0) { func_021BA51C((char *)p[8]); p[5]=1; }
            break;
        case 1:
            func_0220B908((char *)p[9]); p[5]=2;
            break;
        case 2:
            if(result==1) { func_0204E720(3,0,16,2); p[5]=3; }
            break;
        case 3:
            if(func_0204E804()==0) {
                switch(func_0220B940((char *)p[9])) {
                case 0: args[7]=0; break;
                case 1: args[7]=1; break;
                }
                p[5]=4; done=1;
            }
            break;
        }
        break;
    }
    func_0201C4E4((struct PrintSys *)p[3]);
    func_0220B40C((void *)p[1]);
    func_0220B420((void *)p[1]);
    func_0220B424((void *)p[1]);
    return done;
}

void func_0220B260(unsigned *p)
{
    void *r;
    p[11]=1;
    func_020414EC(3);
    func_0204047C(1,3);
    func_0204047C(3,0);
    r=func_020490F4(159,((struct Obj00162 *)p)->f0);
    func_02049B68(r,7,0,0,32,((struct Obj00162 *)p)->f0);
    p[12]=func_02049740(r,17,1,2048,0,((struct Obj00162 *)p)->f0);
    func_020498F4(r,(int)39,(int)1,(u16)p[12],(int)1536,(int)0,(unsigned)(((struct Obj00162 *)p)->f0));
    func_02049238(r);
    func_020409B4(1);
}

void func_0220B2E0(u32*p){u32 v,hi;v=p[12];hi=v>>16;func_0203FB44(1,(u16)v,(u16)hi);}
