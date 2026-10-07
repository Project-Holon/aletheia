/*
 * file:     br_util_p04.c
 * unit:     yes
 * function: func_021FCDA0, func_021FCDA8, func_021FCDAC, func_021FCDE8, func_021FCE0C
 * address:  0x021FCDA0
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D68 0x02200D68 data a4
 *   func_021FCE60 0x021FCE60 thumb ov186
 */
#include "../../matched/include/Obj24838.h"
#include "../../matched/include/Obj24839.h"
#include "../../matched/include/Obj00048.h"
#include "../../matched/include/Obj08332.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_02034714(const char *,u32,const char *);
extern void func_021FCE60(char *,int);
void func_021FCDA0(u8*p);
int func_021FCDA8(char *p);
void func_021FCDAC(u8 *p, u16 i, u32 v);
u32 func_021FCDE8(u8 *p, u16 i);
int func_021FCE0C(char *p,unsigned field);
void func_021FCE50(char *p);
extern const char d_02200D68[];


void func_021FCDA0(u8*p){(*(void(**)(u8*))(p+0x54))(p);}

/*
 * leaf: S27 parent clearance; ov183 callers DFFB0 and E024C sole blocker.
 */
int func_021FCDA8(char *p)
{
    return ((struct Obj24838 *)p)->f48;
}

void func_021FCDAC(u8 *p, u16 i, u32 v)
{
    if(i>=*(u32 *)(p+4))func_02034714(d_02200D68,0,d_02200D68);
    if(*(u32 *)(*(u32 *)p+i*8)!=0)func_02034714(d_02200D68,0,d_02200D68);
    *(u32 *)((u32)p+i*4+0x8c)=v;
}

u32 func_021FCDE8(u8 *p, u16 i)
{
    if(i>=((struct Obj24839 *)p)->f4)func_02034714(d_02200D68,0,d_02200D68);
    return *(u32 *)((u32)p+i*4+0x8c);
}

/*
 * extent: lead plus tail-call stub at 021FCE50.
 */
int func_021FCE0C(char *p,unsigned field)
{
    switch(field) {
    case 0:return ((struct Obj08332 *)p)->f40;
    case 1:return ((struct Obj08332 *)p)->f42;
    case 2:return ((struct Obj08332 *)p)->f4C;
    case 3:return ((struct Obj08332 *)p)->f4;
    default:func_02034714(d_02200D68,0,d_02200D68);return 0;
    }
}

void func_021FCE50(char *p)
{
    func_021FCE60(p,((struct Obj00048 *)p)->f42);
}
