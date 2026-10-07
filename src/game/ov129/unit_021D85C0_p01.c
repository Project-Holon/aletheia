/*
 * file:     unit_021D85C0_p01.c
 * unit:     yes
 * function: func_021D85C0, func_021D8714, func_021D872C, func_021D8804, func_021D893C, func_021D8950, func_021D89C4, func_021D8AF4, func_021D8B0C, func_021D8B98, func_021D8BE4, func_021D8C5C
 * address:  0x021D85C0
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0202E4EC 0x0202E4EC thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_02021518 0x02021518 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_021D9838 0x021D9838 thumb ov129
 *   func_021D9490 0x021D9490 thumb ov129
 *   func_0207D63C 0x0207D63C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0203D34C 0x0203D34C arm
 *   d_021DA800 0x021DA800 data a4
 *   func_021D8F78  0x021D8F78  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_021D99F0 0x021D99F0 thumb ov129
 *   func_020450C8 0x020450C8 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02049238 0x02049238 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02045808 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020433E0 0x020433E0 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_0204363C 0x0204363C arm
 *   d_021DA638 0x021DA638 data a4
 *   d_021DA698 0x021DA698 data a4
 *   func_02021D50  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 *   d_021DA744 0x021DA744 data a4
 *   func_0202208C 0x0202208C thumb
 *   func_021D9890 0x021D9890 thumb ov129
 *   func_021DA164 0x021DA164 thumb ov129
 *   func_021D9AB0 0x021D9AB0 thumb ov129
 *   func_021DA1A8 0x021DA1A8 thumb ov129
 *   func_021D9BEC 0x021D9BEC thumb ov129
 *   func_021D9D44 0x021D9D44 thumb ov129
 *   func_021DA320 0x021DA320 thumb ov129
 *   func_021DA3B8 0x021DA3B8 thumb ov129
 *   func_021DA42C 0x021DA42C thumb ov129
 *   func_021DA524 0x021DA524 thumb ov129
 *   func_020221A4 0x020221A4 thumb
 *   func_021DA610 0x021DA610 thumb ov129
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021DA578 0x021DA578 thumb ov129
 *   func_021D9760 0x021D9760 thumb ov129
 *   func_02051C88 0x02051C88 arm
 *   func_021D8FA0 0x021D8FA0 thumb ov129
 */
#include "../../matched/include/Obj04506.h"
#include "../../matched/include/Obj23114.h"
#include "../../matched/include/Obj01937.h"
#include "../../matched/include/Obj01938.h"
#include "../../matched/include/Obj08136.h"
#include "../../matched/include/Obj10498.h"
#include "../../matched/include/Obj10499.h"
#include "../../matched/include/Obj02843.h"
#include "../../matched/include/Obj00361.h"

struct GfFont;
struct Obj02021EE4;
struct PalAnmSlot;
struct Param;
struct Obj0203159C;
struct Node;
struct S020315D4;
struct U16Vec;
struct BgTemplate;
struct DispVram;
struct S02021D50;
struct Ctx;
typedef unsigned u32_021D85C0;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { u32_021D85C0 words[9]; } Param;

typedef unsigned int   u32_021D872C;

typedef unsigned u32_021D8804;

typedef struct { u32_021D8804 words[8]; } BgTemplate;

typedef struct { BgTemplate rows[3]; } MainTemplates;

typedef struct { BgTemplate rows[4]; } SubTemplates;

typedef struct { int rows[2][3]; } Table;

typedef signed char s8;

typedef signed short s16;

typedef unsigned int u32_021D8AF4;

typedef signed int s32;

typedef unsigned int u32_021D8BE4;

typedef unsigned int u32_021D8C5C;

extern void func_0203064C(u32_021D85C0 a, u32_021D85C0 b, u32_021D85C0 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32_021D85C0 size, u32_021D85C0 heap);
extern void func_02082BCC(void *,int,u32_021D85C0);
extern struct Param *func_0202E4EC(u32_021D85C0 heap, u32_021D85C0 a1, u32_021D85C0 a2, u32_021D85C0 a3, u32_021D85C0 *src);
extern u32_021D85C0 func_020307B0(void *p);
extern void func_020434CC(void),func_02043588(void);
extern void *func_020490F4(u32_021D85C0 id, u32_021D85C0 heap);
extern void func_0203F8F4(u16),func_02045088(u16);
extern void * func_02021518(u32_021D85C0);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32_021D85C0 heapId);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32_021D85C0 idx, u32_021D85C0 size, u32_021D85C0 heap);
extern void func_021D9838(char *p, unsigned a);
extern void func_021D9490(char *p);
extern void func_0207D63C(void *,int,int,int,int);
extern void *func_020056A0(u32_021D85C0,u32_021D85C0,u32_021D85C0);
extern void func_0203D34C(u32_021D85C0,u32_021D85C0);
extern int func_021D8F78(char *p);
extern void func_0204A600(void *);
extern void func_02030EAC(struct Node *n);
extern u32_021D872C func_0201D83C(void *ptr);
extern void func_021D99F0(char *);
extern void func_020450C8(void);
extern void func_020434DC(unsigned,unsigned);
extern void func_02043598(unsigned,unsigned);
extern void func_020403F4(unsigned);
extern void func_0203F9B4(void);
extern void func_020215A0(struct PalAnmSlot *slots, u32_021D872C idx);
extern u32_021D872C func_02021540(void *a0);
extern void func_02049238(void *);
extern void func_02051C6C(void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32_021D872C heap);
extern void func_020434CC(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_02082A7C(u32_021D8804,void *,u32_021D8804);
extern void func_0203FCA0(u32_021D8804 bgId, const struct BgTemplate *tmpl, u32_021D8804 type);
extern void func_020414EC(u32_021D8804);
extern void func_0204363C(u32_021D8804);
extern void func_02021D50(struct S02021D50 *p);
extern void func_0204A648(void);
extern void func_021D9890(char *);
extern void func_021DA164(void *);
extern void func_021D9AB0(char *);
extern void func_021DA1A8(char *,int);
extern void func_021D9BEC(char *);
extern void func_021D9D44(char *);
extern void func_021DA320(char *);
extern void func_021DA3B8(char *);
extern void func_021DA42C(u8 *p);
extern void func_021DA524(void **p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned func_020221A4(void);
extern void func_021DA610(void *p, int sel, void *b, unsigned int c);
extern u32_021D8BE4 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021DA578(void *p, int a, void *b, u32_021D8BE4 c);
extern void func_021D9760(char *);
extern s32 func_02051C88(struct Ctx *c);
extern void func_021D8FA0(char *);
int func_021D85C0(void *obj,void *unused,const Param *cfg);
int func_021D8714(int a, int b, int c, int d);
int func_021D872C(void *a,int b,int c,char *p);
void func_021D8804(void);
void func_021D893C(int a, char *p);
void func_021D8950(char *p,int v);
void func_021D89C4(char *p);
void func_021D8AF4(char *p, int v);
int func_021D8B0C(char *p);
int func_021D8B98(char *p);
int func_021D8BE4(char *p);
int func_021D8C5C(char *p);
extern const u32_021D85C0 d_021DA800[];
extern const MainTemplates d_021DA638;
extern const SubTemplates d_021DA698;
extern const Table d_021DA744;

static inline void GX_SetVisiblePlane(int plane) { *(volatile u32_021D85C0 *)0x04000000=(*(volatile u32_021D85C0 *)0x04000000 & ~0x1F00u)|((u32_021D85C0)plane<<8); }

static inline void GXS_SetVisiblePlane(int plane) { *(volatile u32_021D85C0 *)0x04001000=(*(volatile u32_021D85C0 *)0x04001000 & ~0x1F00u)|((u32_021D85C0)plane<<8); }

int func_021D85C0(void *obj,void *unused,const Param *cfg)
{
    u8 *p;
    u32_021D85C0 sizes[3];
    Param *q;
    func_0203064C((u32_021D85C0)((void *)1),50,0x40000);
    p=func_0203159C(obj,0x34C,50);
    func_02082BCC(p,0,0x34C);
    if(cfg==0) {
        sizes[0]=4; sizes[1]=4; sizes[2]=4;
        q=(Param *)func_0202E4EC(50,0,0,12,sizes);
        *(Param *)(p+0x328)=*q;
        func_020307B0(q);
    } else *(Param *)(p+0x328)=*cfg;
    func_020434CC(); func_02043588();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    *(void **)(p+0x258)=func_020490F4(59,50);
    func_0203F8F4(50); func_02045088(50);
    *(void **)(p+0x290)=func_02021518(50);
    *(void **)(p+0x314)=func_0201D7EC(23,0,0,0,50);
    func_02021EE4(*(void **)(p+0x290),1);
    func_0202155C(*(void **)(p+0x290),0,512,50);
    func_021D8804();
    func_021D9838((char *)p,(unsigned int)d_021DA800); func_021D89C4((char *)p); func_021D9490((char *)p);
    func_0207D63C((void *)0x04000050,0,6,15,7);
    func_0207D63C((void *)0x04001050,0,14,7,8);
    *(void **)(p+0x318)=func_020056A0((u32_021D85C0)func_021D893C,(u32_021D85C0)p,16);
    func_0203D34C(1,50);
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021D8714(int a, int b, int c, int d)
{
    void *r = (void *)func_021D8F78((char *)d);

    func_0204A600(r);
    return r != 0;
}

/*
 * The caller supplies the pointer through the legacy argless 02021540 thunk.
 */
int func_021D872C(void *a,int b,int c,char *p)
{
    func_02030EAC(((struct Obj04506 *)p)->f318);
    func_0201D83C(((struct Obj04506 *)p)->f314);
    func_021D99F0(p);
    func_020450C8();
    func_020434DC(1,0); func_020434DC(2,0); func_020434DC(4,0); func_020434DC(8,0);
    func_02043598(1,0); func_02043598(2,0); func_02043598(4,0); func_02043598(8,0);
    func_020403F4(1); func_020403F4(2); func_020403F4(3); func_020403F4(4);
    func_020403F4(5); func_020403F4(6); func_020403F4(7);
    func_0203F9B4();
    func_020215A0(((struct Obj04506 *)p)->f290,0);
    func_02021540(((struct Obj04506 *)p)->f290);
    func_02049238(((struct Obj04506 *)p)->f258);
    func_02051C6C(((struct Obj04506 *)p)->f294);
    if(c==0) func_02045808(((struct Obj04506 *)p)->f348);
    func_020315D4(a);
    func_020306F0(50);
    return 1;
}

void func_021D8804(void)
{
    MainTemplates main;
    SubTemplates sub;
    func_020434CC();
    func_020433E0((const struct DispVram *)d_021DA800);
    func_02082A7C(0,(void *)0x06000000,0x80000);
    func_02082A7C(0,(void *)0x06200000,0x20000);
    func_02082A7C(0,(void *)0x06400000,0x40000);
    func_02082A7C(0,(void *)0x06600000,0x20000);
    main=d_021DA638;
    func_0203FCA0(1,(const struct BgTemplate *)(&main.rows[0]),0);
    func_0203FCA0(2,(const struct BgTemplate *)(&main.rows[1]),0);
    func_0203FCA0(3,(const struct BgTemplate *)(&main.rows[2]),0);
    func_020414EC(1); func_020414EC(2); func_020414EC(3);
    func_020434DC(1,0); func_020434DC(2,1); func_020434DC(4,0); func_020434DC(8,0);
    sub=d_021DA698;
    func_0203FCA0(4,(const struct BgTemplate *)(&sub.rows[0]),0);
    func_0203FCA0(5,(const struct BgTemplate *)(&sub.rows[1]),0);
    func_0203FCA0(6,(const struct BgTemplate *)(&sub.rows[2]),0);
    func_0203FCA0(7,(const struct BgTemplate *)(&sub.rows[3]),0);
    func_020414EC(4); func_020414EC(5); func_020414EC(6); func_020414EC(7);
    func_02043598(1,1); func_02043598(2,1); func_02043598(4,0); func_02043598(8,0);
    func_0204363C(0);
    func_020434DC(16,1); func_02043598(16,1);
}


void func_021D893C(int a, char *p)
{
    func_02021D50((struct S02021D50 *)(((struct Obj23114 *)p)->f290));
    func_0204A648();
}


/*
 * Extent ends with two bytes of zero alignment padding.
 */
void func_021D8950(char *p,int v)  {
    ((struct Obj01937 *)p)->f244=((struct Obj01937 *)p)->f240;
    ((struct Obj01937 *)p)->f240=v;
    ((struct Obj01937 *)p)->f248=0;
    ((struct Obj01937 *)p)->f24C=0;
    ((struct Obj01937 *)p)->f250=0;
    ((struct Obj01937 *)p)->f254=0;
    if(v)  {
        ((struct Obj01937 *)p)->f248=*(unsigned short *)(p+(v-1)*4+0x21c);
        ((struct Obj01937 *)p)->f24C=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
    if(((struct Obj01937 *)p)->f244)  {
        v=((struct Obj01937 *)p)->f244;
        ((struct Obj01937 *)p)->f250=*(unsigned short *)(p+(v-1)*4+0x21c);
        ((struct Obj01937 *)p)->f254=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
}

/*
 * Lever: copy the table through a second aggregate, retain its indexed read,
 * and initialize i before selecting q. The copy folds into the existing slot.
 */
void func_021D89C4(char *p)
{
    int i,j,n,sum;
    Table t;
    Table copy;
    const int *q;
    ((struct Obj01938 *)p)->f2FC=1;
    ((struct Obj01938 *)p)->f21C=0;
    n=((struct Obj01938 *)p)->f330;
    ((struct Obj01938 *)p)->f21E=n;
    ((struct Obj01938 *)p)->f220=n;
    n+=((struct Obj01938 *)p)->f334;
    ((struct Obj01938 *)p)->f222=n;
    ((struct Obj01938 *)p)->f224=n;
    ((struct Obj01938 *)p)->f226=((struct Obj01938 *)p)->f338+n;
    func_021D8950(p,1);
    for(i=0;i<3;i++) ((struct Obj01938 *)p)->f23C+=*(int *)(p+i*4+0x330);
    t=d_021DA744;
    n=0;
    copy=t;
    if(((struct Obj01938 *)p)->f330!=4) n=1;
    i=0;
    q=copy.rows[n];
    for(;i<3;i++) *(u16 *)(p+i*2+0x214)=copy.rows[n][i];
    *(u16 *)(p+i*2+0x214)=q[i-1];
    sum=0;
    for(i=0;i<2;i++) {
        sum+=*(int *)(p+i*4+0x330);
        *(int *)(p+i*28+0x150)=sum-1;
    }
    i=0;
    n=0;
    do {
        for(j=0;j<*(int *)(p+i*4+0x330);j++) {
            *(int *)(p+n*28+4)=i+1;
            n++;
        }
        i++;
    } while(n<((struct Obj01938 *)p)->f23C);
}


void func_021D8AF4(char *p, int v)
{
    ((struct Obj08136 *)p)->f22C = v;
    ((struct Obj08136 *)p)->f230 = 0;
    ((struct Obj08136 *)p)->f234 = 0;
    ((struct Obj08136 *)p)->f238 = 0;
}

int func_021D8B0C(char *p)  {
    func_021D9890(p);
    func_021DA164(p);
    func_021D9AB0(p);
    func_021DA1A8(p,0);
    func_021D9BEC(p);
    func_021D9D44(p);
    func_021DA320(p);
    func_021DA3B8(p);
    func_021DA42C((u8 *)p);
    func_021DA524((void **)(p+0x310),((struct Obj10498 *)p)->f328,4,2,19,27,4,((struct Obj10498 *)p)->f314,((struct Obj10498 *)p)->f344);
    func_021D8AF4(p,1);
    func_0202208C(0,1,1,0,6,1,50);
    return 0;
}

int func_021D8B98(char *p)  {
    switch(((struct Obj10499 *)p)->f234)  {
        case 0: func_0202208C(0,0,0,0,6,1,50);
        ((struct Obj10499 *)p)->f234+=1;
        break;
        case 1: if(func_020221A4()==1) ((struct Obj10499 *)p)->f234+=1;
        break;
        default: return 1;
    }
    return 0;
}

int func_021D8BE4(char *p)  {
    switch(((struct Obj02843 *)p)->f234)  {
        case 0: func_021DA610((void *)(((struct Obj02843 *)p)->f310),((struct Obj02843 *)p)->f328,(void *)(((struct Obj02843 *)p)->f314),((struct Obj02843 *)p)->f344);
        ((struct Obj02843 *)p)->f234+=1;
        break;
        case 1: if((func_020362DC() & 2) || (func_020362DC() & 1) || func_02035C60())  {
            func_021DA578((void *)(((struct Obj02843 *)p)->f310),((struct Obj02843 *)p)->f328,(void *)(((struct Obj02843 *)p)->f314),((struct Obj02843 *)p)->f344);
            func_021D8AF4(p,1);
        }
        break;
    }
    return 0;
}

int func_021D8C5C(char *p) {if(((struct Obj00361 *)p)->f234==0){if(func_020221A4()==1)((struct Obj00361 *)p)->f234+=1;}else {func_021D9760(p);func_02051C88(((struct Obj00361 *)p)->f294);func_021D8FA0(p);}return 0;}
