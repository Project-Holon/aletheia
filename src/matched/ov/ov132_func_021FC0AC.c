/*
 * function: func_021FC0AC
 * address: 0x021FC0AC
 * packet: pkt_ov132_021FC0AC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021F9DC4 0x021F9DC4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FC178 0x021FC178 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
#include "../include/Obj01741.h"
#include "../include/Obj02486.h"
#include "../include/Obj10560.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *func_021F9DC4(void *,u8);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FC178(int,char *);
extern const char d_021FDD00[];
int func_021FC0AC(int unused,char *p)
{
    char *owner,*q;
    void *target;
    u32 j,i,h,g,f,e,d,c,b,a;
    owner=*(char * *)&((struct Obj02486 *)p)->f0;
    a=VM_GetU32(((struct Obj02486 *)p)->f4);
    b=VM_GetU32(((struct Obj02486 *)p)->f4);
    c=VM_GetU32(((struct Obj02486 *)p)->f4);
    d=VM_GetU32(((struct Obj02486 *)p)->f4);
    e=VM_GetU32(((struct Obj02486 *)p)->f4);
    f=VM_GetU32(((struct Obj02486 *)p)->f4);
    g=VM_GetU32(((struct Obj02486 *)p)->f4);
    h=VM_GetU32(((struct Obj02486 *)p)->f4);
    i=VM_GetU32(((struct Obj02486 *)p)->f4);
    j=VM_GetU32(((struct Obj02486 *)p)->f4);
    target=func_021F9DC4(((struct Obj10560 *)owner)->f34,a);
    q=func_02030734(((struct Obj10560 *)owner)->f0,56,0,d_021FDD00,0x691);
    *(char * *)&((struct Obj01741 *)q)->f30=owner;
    ((struct Obj01741 *)q)->f10=target;
    ((struct Obj01741 *)q)->f2C=b;
    ((struct Obj01741 *)q)->f14=e;
    ((struct Obj01741 *)q)->f18=f;
    ((struct Obj01741 *)q)->f1C=g;
    ((struct Obj01741 *)q)->f20=h-e;
    ((struct Obj01741 *)q)->f24=i-f;
    ((struct Obj01741 *)q)->f28=j-g;
    ((struct Obj01741 *)q)->f0=((struct Obj10560 *)owner)->f34;
    ((struct Obj01741 *)q)->f4=0;
    ((struct Obj01741 *)q)->f8=c;
    ((struct Obj01741 *)q)->fC=d;
    ((struct Obj01741 *)q)->f34=func_021FADA0(owner,(u32)func_021FC178,(u32)q,10);
    return 0;
}
