/*
 * file:     compatible_irc_sys_p07.c
 * unit:     yes
 * function: func_021B6C08, func_021B6C20
 * address:  0x021B6C08
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021B74B8 0x021B74B8 data a4
 *   func_02031348 0x02031348 arm
 */
#include "../../matched/include/Obj22114.h"

struct S020314B8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Row { int a,b; int (*create)(int,int); void (*destroy)(int,int); } Row;

extern void func_0203133C(struct S020314B8 *p);
extern void func_02082BCC(void *,int,u32);
extern void func_02031348(int,int,int,int);
void func_021B6C08(u8 *p);
int func_021B6C20(int *p,int index,int heap,int arg);
extern const Row d_021B74B8[];

void func_021B6C08(u8 *p) { func_0203133C(((struct Obj22114 *)p)->f0); func_02082BCC(p,0,12); }

int func_021B6C20(int *p,int index,int heap,int arg)
{
    int result;
    switch(p[1]) {
    case 0:
        if(d_021B74B8[index].create) result=d_021B74B8[index].create(heap,arg);
        else result=0;
        p[2]=result;
        p[1]=1;
        break;
    case 1:
        func_02031348(p[0],d_021B74B8[index].a,d_021B74B8[index].b,p[2]);
        p[1]=2;
        break;
    case 2:
        if(d_021B74B8[index].destroy) d_021B74B8[index].destroy(p[2],arg);
        p[1]=3;
        break;
    case 3:
        p[1]=0;
        return 1;
    }
    return 0;
}
