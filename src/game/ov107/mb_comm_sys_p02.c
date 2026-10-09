/*
 * file:     mb_comm_sys_p02.c
 * unit:     yes
 * function: func_021F1370, func_021F13BC
 * address:  0x021F1370
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203996C 0x0203996C arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02030734 0x02030734 arm
 *   d_021F6E28 0x021F6E28 data ov107 a1
 *   d_021F6EE8 0x021F6EE8 data a4
 */
#include "../../matched/include/Obj13764.h"
#include "../../matched/include/Obj07995.h"
#include "../../matched/include/Obj22300.h"
#include "../../matched/include/Obj22301.h"

struct Entry;
typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

extern struct Entry *func_0203996C(s32 idx);
extern int func_0203D1B4(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void *func_02030734(unsigned int,unsigned int,int,const char *,u16);
int func_021F1370(void *unused,void *p);
void func_021F13AC(int a,int b,int c,char *p);
void *func_021F13BC(void *a,char *p);
void func_021F13E8(int a,int b,int c,char *p);
void *func_021F13F4(int a,char *p);
int *func_021F13F8(void);
int func_021F1400(void);
extern const char d_021F6E28[];
extern int d_021F6EE8[];

int func_021F1370(void *unused,void *p)
{
    void *obj;
    obj=func_0203996C(255);
    if(func_0203D1B4()<2) return 0;
    return func_0203D3F8((u32)obj,1,0x401,8,(u32)p,1,0,1);
}

void func_021F13AC(int a,int b,int c,char *p)
{
    ((struct Obj13764 *)p)->f18=(((struct Obj13764 *)p)->f18&~1)|1;
}

void *func_021F13BC(void *a,char *p)
{
    if(!((struct Obj07995 *)p)->f14) ((struct Obj07995 *)p)->f14=func_02030734(((struct Obj07995 *)p)->f0,8,1,d_021F6E28,862);
    return ((struct Obj07995 *)p)->f14;
}

void func_021F13E8(int a,int b,int c,char *p){((struct Obj22300 *)p)->f18|=2;}

void *func_021F13F4(int a,char *p){return ((struct Obj22301 *)p)->f10;}

int *func_021F13F8(void){return d_021F6EE8;}

int func_021F1400(void){return 2;}
