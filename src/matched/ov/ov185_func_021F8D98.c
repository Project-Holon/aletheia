/*
 * function: func_021F8D98
 * address: 0x021F8D98
 * packet: pkt_ov185_021F8D98
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   d_021F90A0 0x021F90A0 data a1
 */
#include "../include/Obj03338.h"
#include "../include/Obj05490.h"
typedef unsigned short u16;
typedef struct Config {u16 x,y,z; unsigned char a,b;} Config;
typedef struct Triple {int a,b,c;} Triple;
extern const char d_021F90A0[];
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021FC4DC(u8 *p);
extern int func_021FC124(void *,unsigned,void *);
extern void func_02082BCC(void *,int,unsigned);
extern void func_02034714(const char *,unsigned,const char *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,unsigned char,unsigned char,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
void func_021F8D98(char *p,char *q)
{
    int a,b;
    void *v;
    Config cfg;
    Triple triple;
    if (!*(int *)&((struct Obj03338 *)p)->f1C) {
        a=func_021FC20C(*(char * *)&((struct Obj05490 *)q)->fC);
        b=func_021FC214(*(char * *)&((struct Obj05490 *)q)->fC);
        func_021FC4DC(((struct Obj05490 *)q)->f8);
        func_02082BCC(&cfg,0,8);
        cfg.x=0x50;cfg.y=0xa8;cfg.z=0;cfg.a=1;
        v=(void *)func_021FC4DC(((struct Obj05490 *)q)->f8);
        if (!func_021FC124(((struct Obj05490 *)q)->fC,6,&triple)) func_02034714(d_021F90A0,0,d_021F90A0);
        ((struct Obj03338 *)p)->f18=func_021FB378(&cfg,4,0x60,1,(int)v,((struct Obj03338 *)p)->f28,a,b,&triple,((struct Obj03338 *)p)->f30);
        ((struct Obj03338 *)p)->f1C=func_021FC6A4(4,8,3,0x10,2,0xe,((struct Obj03338 *)p)->f2C,((struct Obj03338 *)p)->f30);
        func_021FC754(*(char * *)&((struct Obj03338 *)p)->f1C,(void *)b,(void *)0x71,(void *)a,0x3da0);
        func_021FB964((void *)(*(int *)&((struct Obj05490 *)q)->fC),0x16,((struct Obj03338 *)p)->f30);
    }
}
