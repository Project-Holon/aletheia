/*
 * function: func_021DA004
 * address: 0x021DA004
 * packet: pkt_ov129_021DA004
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero alignment padding.
 * Lever: declare the 4-byte-stride pointer before the 28-byte-stride pointer.
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_021D9FF0 0x021D9FF0 thumb ov129
 */
#include "../include/Obj02186.h"
#include "../include/Obj04507.h"
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021D9FF0(char *,int,int);
void func_021DA004(char *p)
{
    int i;
    char *r,*q;
    s16 x,y;
    for(i=0;i<2;i++) {
        r=p+i*4;
        x=((struct Obj04507 *)r)->f2F2+20;
        y=(((struct Obj04507 *)r)->f2F0+((struct Obj04507 *)r)->f2F1)/2;
        y-=7;
        q=p+i*28;
        switch(((struct Obj02186 *)q)->f1DC) {
        case 0:
            ((struct Obj02186 *)q)->f1F4=0;
            break;
        case 1:
            ((struct Obj02186 *)q)->f1F4+=1;
            if(((struct Obj02186 *)q)->f1F4==1) {
                func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),1);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            } else if(((struct Obj02186 *)q)->f1F4==2) {
                func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),2);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            } else if(((struct Obj02186 *)q)->f1F4==10) {
                func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),0);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
                ((struct Obj02186 *)q)->f1DC+=1;
            }
            break;
        default:
            func_0204B878((struct Obj *)(((struct Obj02186 *)q)->f1E8),0);
            func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            ((struct Obj02186 *)q)->f1DC=0;
            break;
        }
    }
}
