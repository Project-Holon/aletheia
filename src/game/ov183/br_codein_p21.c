/*
 * file:     br_codein_p21.c
 * unit:     yes
 * function: func_021DFCD4, func_021DFE98, func_021DFF78, func_021DFFB0, func_021E0044, func_021E0080
 * address:  0x021DFCD4
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E04C8 0x021E04C8 thumb ov183
 *   func_02035D20 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021E03B0 0x021E03B0 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FB4CC 0x021FB4CC thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 */
#include "../../matched/include/Obj00277.h"
#include "../../matched/include/Obj00351.h"
#include "../../matched/include/Obj02523.h"
#include "../../matched/include/Obj04571.h"
#include "../../matched/include/Obj04572.h"
#include "../../matched/include/Obj24621.h"
#include "../../matched/include/Obj04573.h"
#include "../../matched/include/Obj08315.h"
#include "../../matched/include/Obj14434.h"

struct Sub0200852CObj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {u32 words[10];} Config;

typedef struct {int a,b,c;} Triple;

typedef struct {u16 a,b,c;u8 flag,pad;} Params;

typedef struct {u8 a,b,c,d;u16 file,pad;} Record;

typedef struct Slot Slot;

extern int func_021E04C8(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021FD860(int,int,int *);
extern void func_020061E4(u32 a);
extern void func_021E03B0(char *,char *,int);
extern void func_021FD170(char *p, char *q, void *text);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern int func_021FB4CC(u32 *p, int a1, int a2);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021F9BF4(unsigned *,unsigned);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern Slot *func_0201F81C(u32,u32);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_021FC8C8(Config *,u32);
extern void func_02082BCC(void *,u32,u32);
extern int func_021FC124(int,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void func_021FB494(char *p);
extern void func_021FCC80(char *p);
extern u32 func_0201F868(void *p);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
extern void func_021FCD0C(char *p);
extern int func_021FCDA8(char *p);
extern void *func_0200CA1C(void *);
extern char *func_021FFBD4(void *, void *, int, int, int, int, int, u16);
extern void func_021FFE5C(char *);
extern unsigned func_021FFE34(char *p);
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
int func_021DFCD4(char *p,char *q);
int func_021DFE98(char *p,char *q);
int func_021DFF78(char *p, char *q);
int func_021DFFB0(char *p, char *q);
void func_021E0044(char *p, char *q);
int func_021E0080(char *p);
extern const Config d_021E3758;
extern const Record d_021E3728[];

/*
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 */
int func_021DFCD4(char *p,char *q)
{
    int result=func_021E04C8();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f18=19;
        func_021E03B0(p,q,0);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)105);
        ((struct Obj00277 *)p)->f50=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f14=0xffff;
        func_021E03B0(p,q,1);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)106);
        ((struct Obj00277 *)p)->f50=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        int args[2];
        v=func_02012944(((struct Obj00351 *)q)->f10);
        a=func_0200856C(v);b=func_02008570(v);
        if(!a && !b) {
            func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)120);
            func_020061E4(0x704);
            break;
        }
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        if(((struct Obj00351 *)q)->f16==255){((struct Obj00351 *)q)->f16=a;((struct Obj00351 *)q)->f17=b;}
        else{((struct Obj00351 *)q)->f16=255;((struct Obj00351 *)q)->f17=255;}
        func_021E03B0(p,q,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(func_02035D20(&x,&y)) {
            if(func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC),x,y)) {
                int args[2];
                args[0]=x;args[1]=y;
                func_021FD860(((struct Obj00277 *)p)->f40,1,args);
                ((struct Obj00277 *)p)->f50=-1;
                func_021F9BA0(((struct Obj00351 *)q)->fC);
                return 1;
            }
            if(func_021FB4CC((u32 *)(((struct Obj00277 *)p)->f10),x,y)) {
                if(((struct Obj00351 *)q)->f14!=0xffff || ((struct Obj00351 *)q)->f17!=255 || ((struct Obj00351 *)q)->f18!=19) {
                    int args[2];
                    args[0]=x;args[1]=y;
                    func_020061E4(0x703);
                    func_021FD860(((struct Obj00277 *)p)->f40,1,args);
                    ((struct Obj00277 *)p)->f50=-1;
                    func_021F9BF4(*(unsigned * *)&((struct Obj00351 *)q)->fC,5);
                    return 1;
                }
                func_020061E4(0x704);
                func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)108);
            }
        }
    }
    return 0;
}

int func_021DFE98(char *p,char *q)
{
    int first,second,i;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&((struct Obj04571 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj04571 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj04571 *)q)->f8),27,((struct Obj02523 *)p)->f54);
    *(Slot * *)&((struct Obj02523 *)p)->f14=func_0201F81C(19,((struct Obj02523 *)p)->f54);
    for(i=0;i<19;i++)func_0201F878((Slot *)((u32)*(Slot * *)&((struct Obj02523 *)p)->f14+i*8),second,i+205,i,((struct Obj02523 *)p)->f54);
    cfg=d_021E3758;
    cfg.words[0]=*(u32 *)&((struct Obj02523 *)p)->f14;cfg.words[1]=19;
    cfg.words[5]=*(u32 *)&((struct Obj04571 *)q)->f8;cfg.words[6]=((struct Obj04571 *)q)->f4;
    ((struct Obj02523 *)p)->f18=func_021FC8C8(&cfg,((struct Obj02523 *)p)->f54);
    func_02082BCC(&params,0,8);
    func_021FC124(*(int *)&((struct Obj04571 *)q)->f8,6,&triple);
    params.a=d_021E3728[0].a;params.b=d_021E3728[0].b;params.c=d_021E3728[0].c;params.flag=1;
    ((struct Obj02523 *)p)->fC=func_021FB378(&params,d_021E3728[0].file,96,1,*(int *)&((struct Obj04571 *)q)->f4,((struct Obj02523 *)p)->f44,first,second,&triple,((struct Obj02523 *)p)->f54);
    return 1;
}

int func_021DFF78(char *p, char *q)
{
    if (((struct Obj04572 *)p)->fC) {
        func_021FB494(((struct Obj04572 *)p)->fC);
        ((struct Obj04572 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04572 *)p)->f18);
    ((struct Obj04572 *)p)->f18 = 0;
    func_0201F868(((struct Obj04572 *)p)->f14);
    ((struct Obj04572 *)p)->f14 = 0;
    func_021FBDA4(((struct Obj24621 *)q)->f8, 27);
    func_020409B4(4);
    return 1;
}

int func_021DFFB0(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(((struct Obj00277 *)p)->f18);
    selected = func_021FCDA8(((struct Obj00277 *)p)->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00351 *)q)->f18 = selected;
        func_021E03B0(p, q, 0);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}

void func_021E0044(char *p, char *q)
{
    *(char * *)&((struct Obj04573 *)p)->f1C = func_021FFBD4(func_0200CA1C(((struct Obj08315 *)q)->f10), ((struct Obj08315 *)q)->f8, ((struct Obj08315 *)q)->f4, ((struct Obj04573 *)p)->f44, ((struct Obj08315 *)q)->f0, ((struct Obj04573 *)p)->f3C, ((struct Obj04573 *)p)->f40, ((struct Obj04573 *)p)->f54);
    func_021FFE5C(*(char * *)&((struct Obj04573 *)p)->f1C);
    func_021FFE34(*(char * *)&((struct Obj04573 *)p)->f1C);
}

int func_021E0080(char *p)
{
    func_021FFE70(((struct Obj14434 *)p)->f1C);
    func_021FFC6C(((struct Obj14434 *)p)->f1C);
    func_020409B4(4);
    return 1;
}
