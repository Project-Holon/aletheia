/*
 * file:     br_codein_p07.c
 * unit:     yes
 * function: func_021DCE48, func_021DCEE4, func_021DD054
 * address:  0x021DCE48
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
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 */
#include "../../matched/include/Obj00050.h"
#include "../../matched/include/Obj02893.h"
#include "../../matched/include/Obj24572.h"
#include "../../matched/include/Obj00730.h"
#include "../../matched/include/Obj03329.h"
#include "../../matched/include/Obj06598.h"
#include "../../matched/include/Obj10730.h"

struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {u16 x,y,n;u8 flag,pad;} Desc;

typedef struct {int a,b,c;} Triple;

extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBE54(char *,u32,u32);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC124(void *,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_02082BCC(void *,int,u32);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
void func_021DCE48(char *p,char *q);
void func_021DCEE4(char *p,char *q);
void func_021DD054(char *p, char *q);

void func_021DCE48(char *p,char *q)
{
    int i;
    char *slot;
    if(((struct Obj00050 *)p)->fD4) {
        for(i=0;i<12;i++) {
            slot=p+i*4;
            if(((struct Obj02893 *)slot)->f80) {
                func_0204B3DC(((struct Obj02893 *)slot)->f80,0);
                func_0204B3B4(((struct Obj02893 *)slot)->f80);
                *(int *)&((struct Obj02893 *)slot)->f80=0;
            }
            if(((struct Obj02893 *)slot)->f50!=-1) { func_0204A8D4(((struct Obj02893 *)slot)->f50); ((struct Obj02893 *)slot)->f50=-1; }
        }
        if(((struct Obj00050 *)p)->f48!=-1) { func_0204ADA4(((struct Obj00050 *)p)->f48); ((struct Obj00050 *)p)->f48=-1; }
        if(((struct Obj00050 *)p)->f4C!=-1) { func_0204AFD8(((struct Obj00050 *)p)->f4C); ((struct Obj00050 *)p)->f4C=-1; }
        for(i=0;i<5;i++) {
            slot=p+i*4;
            if(((struct Obj02893 *)slot)->f30) { func_021FC734(((struct Obj02893 *)slot)->f30); *(int *)&((struct Obj02893 *)slot)->f30=0; }
        }
        func_021FBDA4(((struct Obj24572 *)q)->f10,6);
        func_020409B4(1);
        ((struct Obj00050 *)p)->fD4=0;
    }
}

void func_021DCEE4(char *p,char *q)
{
    int a,b;
    if(!((struct Obj00730 *)p)->fD8) {
        ((struct Obj00730 *)p)->fD8=1;
        func_021FB964((void *)(*(int *)&((struct Obj03329 *)q)->f10),5,((struct Obj00730 *)p)->fB4);
        func_021FBE54(*(char * *)&((struct Obj03329 *)q)->f10,6,((struct Obj00730 *)p)->fB4);
        a=func_021FC20C(*(char * *)&((struct Obj03329 *)q)->f10);
        b=func_021FC214(*(char * *)&((struct Obj03329 *)q)->f10);
        if(((struct Obj00730 *)p)->fCC) {
            Desc d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.x=24;d.y=168;d.n=0;d.flag=1;
            func_021FC124(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=func_021FB378(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
            d.x=136;d.n=3;
            ((struct Obj00730 *)p)->f20=func_021FB378(&d,84,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        } else {
            Desc d;
            Triple t;
            func_02082BCC(&d,0,8);
            d.x=80;d.y=168;d.n=0;d.flag=1;
            func_021FC124(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=func_021FB378(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        }
        ((struct Obj00730 *)p)->f28=func_021FC6A4(4,8,3,16,2,14,((struct Obj00730 *)p)->f4,((struct Obj00730 *)p)->fB4);
        if(((struct Obj00730 *)p)->fB0) func_021FC754(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
    }
}

void func_021DD054(char *p, char *q)
{
    int i;
    char *slot;
    if(((struct Obj00050 *)p)->fD8) {
        if(((struct Obj00050 *)p)->f28) { func_021FC734(((struct Obj00050 *)p)->f28); *(int *)&((struct Obj00050 *)p)->f28=0; }
        for(i=0;i<2;i++) {
            slot=p+i*4;
            if(((struct Obj10730 *)slot)->f1C) { func_021FB494(((struct Obj10730 *)slot)->f1C); *(int *)&((struct Obj10730 *)slot)->f1C=0; }
        }
        func_020409B4(4);
        func_021FC0C8((char *)(((struct Obj06598 *)q)->f10),6);
        func_021FBDA4(((struct Obj06598 *)q)->f10,5);
        ((struct Obj00050 *)p)->fD8=0;
    }
}
