/*
 * function: func_021DCEE4
 * address: 0x021DCEE4
 * packet: pkt_ov183_021DCEE4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj00730.h"
#include "../include/Obj03329.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u16 x,y,n;u8 flag,pad;} Desc;
typedef struct {int a,b,c;} Triple;
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBE54(char *,u32,u32);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC124(void *,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void MI_CpuFill8(void *,int,u32);
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
            MI_CpuFill8(&d,0,8);
            d.x=24;d.y=168;d.n=0;d.flag=1;
            func_021FC124(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=func_021FB378(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
            d.x=136;d.n=3;
            ((struct Obj00730 *)p)->f20=func_021FB378(&d,84,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        } else {
            Desc d;
            Triple t;
            MI_CpuFill8(&d,0,8);
            d.x=80;d.y=168;d.n=0;d.flag=1;
            func_021FC124(((struct Obj03329 *)q)->f10,6,&t);
            ((struct Obj00730 *)p)->f1C=func_021FB378(&d,4,96,1,((struct Obj03329 *)q)->f18,((struct Obj00730 *)p)->f0,a,b,&t,((struct Obj00730 *)p)->fB4);
        }
        ((struct Obj00730 *)p)->f28=func_021FC6A4(4,8,3,16,2,14,((struct Obj00730 *)p)->f4,((struct Obj00730 *)p)->fB4);
        if(((struct Obj00730 *)p)->fB0) func_021FC754(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x72,(void *)a,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00730 *)p)->f28,(void *)b,(void *)0x71,(void *)a,0x3da0);
    }
}
