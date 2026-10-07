/*
 * file:     unit_021E5440_p01.c
 * unit:     yes
 * function: func_021E5440, func_021E54CC, func_021E5524
 * address:  0x021E5440
 * region:   ov178
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
 *   func_02031324 0x02031324 arm
 *   func_021E56F4 0x021E56F4 thumb ov178
 *   func_021E57E0 0x021E57E0 thumb ov178
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_021B6108 0x021B6108 thumb ov090
 *   func_02034A5C 0x02034A5C arm
 *   ov090_id 0x0000005A data
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   ov091_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   d_021BED00 0x021BED00 data a4 ov091
 *   d_021DC800 0x021DC800 data a4 ov131
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D798 0x0203D798 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FB38 0x0200FB38 thumb
 *   func_02157170 0x02157170 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02031348 0x02031348 arm
 *   func_02031330 0x02031330 arm
 *   func_021B6114 0x021B6114 thumb ov090
 */
#include "../../matched/include/Obj04565.h"
#include "../../matched/include/Obj14378.h"
#include "../../matched/include/Obj14379.h"
#include "../../matched/include/Obj24455.h"
#include "../../matched/include/Obj00349.h"
#include "../../matched/include/Obj10715.h"

struct Obj0203159C;
struct Party;
struct PartyMon;
struct S020314B8;
struct S020315D4;
typedef unsigned int   u32_021E5440;

typedef struct {unsigned words[9];} Copy;

typedef signed int     s32;

typedef unsigned int   u32_021E54CC;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned u32_021E5524;

extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32_021E5440 size, u32_021E5440 heap);
extern void func_02082BCC(void *,int,int);
extern void *func_02031324(int a0);
extern void func_021E56F4(void *,void *,void *);
extern void func_021E57E0(int *,int *,char *);
extern void *func_0201AB28(void *,unsigned);
extern u32_021E54CC func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_021B6108(void *);
extern void func_02034A5C(s32 handle);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned);
extern int func_0203CD98(void);
extern void *func_0203D798(void);
extern u32_021E5524 func_0200FB24(void);
extern void func_0200FB38(void);
extern int func_02157170(void *,void *);
extern int func_02034AC4(int);
extern void func_02031348(void *,u32_021E5524,void *,void *);
extern u32_021E5524 func_02031330(void *);
extern void func_021B6114(u8 *);
int func_021E5440(void *handle,int unused,char *q);
int func_021E54CC(void *handle,int unused,char *q,char *p);
int func_021E5524(void *unused,int unused2,char *q,char *p);
extern unsigned d_02FFFC3C;
extern unsigned ov090_id[];
extern u8 ov091_id[],ov131_id[],d_021BED00[],d_021DC800[];

int func_021E5440(void *handle,int unused,char *q)
{
 char *p;
 func_0203064C(1,0x58,0x30000);
 p=func_0203159C(handle,0xFC,0x58);
 func_02082BCC(p,0,0xFC);
 *(Copy *)(p+0xD4)=*(Copy *)q;
 ((struct Obj04565 *)p)->fF8=0x58;
 ((struct Obj04565 *)p)->fD0=func_02031324(((struct Obj04565 *)p)->fF8);
 ((struct Obj04565 *)p)->f4=((struct Obj14378 *)q)->f4;
 func_021E56F4(q,p,p+8);func_021E57E0((int *)q,(int *)p,p+0xA0);
 ((struct Obj04565 *)p)->fC8=0;
 ((struct Obj04565 *)p)->fCC=d_02FFFC3C;
 ((struct Obj04565 *)p)->f0=0;((struct Obj14378 *)q)->f20=0;
 return 1;
}

int func_021E54CC(void *handle,int unused,char *q,char *p)
{
 unsigned char i;
 for(i=0;i<6;i++) {
 unsigned n=*(unsigned char *)(p+i+0x51);
 if(n!=0)func_0201A98C(((struct Obj14379 *)q)->f1C,func_0201AB28(((struct Obj14379 *)q)->f4,n-1));
 }
 func_021B6108(p+8);func_02034A5C((unsigned)ov090_id);
 func_0203133C(((struct Obj24455 *)p)->fD0);func_020315D4(handle);func_020306F0(0x58);
 return 1;
}

int func_021E5524(void *unused,int unused2,char *q,char *p)
{
    if(((struct Obj00349 *)p)->f98==1 && ((struct Obj00349 *)p)->f68!=0) {
        u32_021E5524 now;
        now=d_02FFFC3C;
        ((struct Obj00349 *)p)->fC8+=(u8)(now-((struct Obj00349 *)p)->fCC);
        ((struct Obj00349 *)p)->fCC=now;
        if(((struct Obj00349 *)p)->fC8>60) {
            --((struct Obj00349 *)p)->f68;
            ((struct Obj00349 *)p)->fC8-=60;
        }
    }
    if(func_0203CD98()) {
        if(*((u8 *)func_0203D798()+0x65)==3) {
            if(func_0200FB24()) {
                func_0200FB38();
                ((struct Obj10715 *)q)->f20=2;
                ((struct Obj00349 *)p)->f6B=1;((struct Obj00349 *)p)->fC4=1;
            }
        } else {
            int one;
            one=1;
            switch(func_02157170((void *)1,(void *)1)) {
            case 0:case 3:break;
            case 4:((struct Obj10715 *)q)->f20=3;((struct Obj00349 *)p)->f6B=one;((struct Obj00349 *)p)->fC4=one;break;
            case 1:case 2:default:((struct Obj10715 *)q)->f20=1;((struct Obj00349 *)p)->f6B=1;((struct Obj00349 *)p)->fC4=1;break;
            }
        }
    }
    switch(((struct Obj00349 *)p)->f0) {
    case 0:func_02034AC4((int)ov091_id);
        func_02031348(((struct Obj00349 *)p)->fD0,-1,d_021BED00,p+8);((struct Obj00349 *)p)->f0=1;break;
    case 1:if(func_02031330(((struct Obj00349 *)p)->fD0)==0)((struct Obj00349 *)p)->f0=2;break;
    case 2:func_02034A5C((int)ov091_id);
        if(((struct Obj00349 *)p)->f48==1) {((struct Obj00349 *)p)->fAF=((struct Obj00349 *)p)->f44;((struct Obj00349 *)p)->f0=3;}
        else return 1;
        break;
    case 3:func_02034AC4((int)ov131_id);
        func_02031348(((struct Obj00349 *)p)->fD0,-1,d_021DC800,p+0xa0);((struct Obj00349 *)p)->f0=4;break;
    case 4:
        if(((struct Obj00349 *)p)->f98==1 && ((struct Obj00349 *)p)->f68==0)((struct Obj00349 *)p)->fC4=1;
        if(func_02031330(((struct Obj00349 *)p)->fD0)==0)((struct Obj00349 *)p)->f0=5;break;
    case 5:func_02034A5C((int)ov131_id);
        if(((struct Obj00349 *)p)->f6B==0) {((struct Obj00349 *)p)->f44=((struct Obj00349 *)p)->fAF;((struct Obj00349 *)p)->f0=0;}
        else return 1;
        break;
    }
    if(((struct Obj00349 *)p)->f6B==0) {
        p+=8;
        func_021B6114((u8 *)p);
    }
    return 0;
}
