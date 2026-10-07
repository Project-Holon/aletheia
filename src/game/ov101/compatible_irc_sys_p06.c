/*
 * file:     compatible_irc_sys_p06.c
 * unit:     yes
 * function: func_021B6AD8, func_021B6BA8, func_021B6BE4, func_021B6BFC
 * address:  0x021B6AD8
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
 *   func_021B6C20 0x021B6C20 thumb ov101
 *   func_021B6A3C 0x021B6A3C thumb ov101
 *   func_021B6A7C 0x021B6A7C thumb ov101
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 */
#include "../../matched/include/Obj02808.h"
#include "../../matched/include/Obj22112.h"
#include "../../matched/include/Obj22113.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern int func_021B6C20(int *,int,int,int);
extern void func_021B6A3C(u8 *,u32);
extern void func_021B6A7C(u8 *,u16 *);
extern void func_02082BCC(void *,int,u32);
extern void *func_02031324(int);
extern unsigned int func_02031330(void *);
void func_021B6AD8(u8 *p,u16 *state);
void func_021B6BA8(u8 *p,u16 *state);
void func_021B6BE4(u8 *p,int heap);
unsigned int func_021B6BFC(u8 *p);

void func_021B6AD8(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        p[0x2e]=0;
        p[0x2c]=0;
        *state=1;
        break;
    case 1:
        if(func_021B6C20((int *)(p+4),2,0x3a,(int)p)) *state=2;
        break;
    case 2:
        if(((struct Obj02808 *)p)->f28==0) *state=3;
        else if(((struct Obj02808 *)p)->f28==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 3:
        if(func_021B6C20((int *)(p+4),1,0x3a,(int)p)) *state=4;
        break;
    case 4:
        if(((struct Obj02808 *)p)->f24==0) *state=5;
        else if(((struct Obj02808 *)p)->f24==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 5:
        if(func_021B6C20((int *)(p+4),3,0x3a,(int)p)) *state=6;
        break;
    case 6:
        func_021B6A3C(p,(u32)func_021B6A7C);
        break;
    }
}

void func_021B6BA8(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: if(func_021B6C20((int *)(p+4),4,58,(int)p)) *state=2; break; case 2: func_021B6A3C(p,(u32)func_021B6A7C); break; } }

void func_021B6BE4(u8 *p,int heap) { func_02082BCC(p,0,12); ((struct Obj22112 *)p)->f0=func_02031324(heap); }

unsigned int func_021B6BFC(u8 *p) { return func_02031330((void *)((struct Obj22113 *)p)->f0); }
