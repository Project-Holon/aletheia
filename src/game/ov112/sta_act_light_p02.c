/*
 * file:     sta_act_light_p02.c
 * unit:     yes
 * function: func_021F6F1C, func_021F6F24, func_021F6F4C
 * address:  0x021F6F1C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F8454 0x021F8454 data a1
 *   func_021F7048 0x021F7048 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj08025.h"
#include "../../matched/include/Obj08026.h"
#include "../../matched/include/Obj00670.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_021F7048(u8 *,u32);
extern u32 func_020307B0(void *p);
void func_021F6F1C(void *a,char *p,u32 b,u32 c);
u8 *func_021F6F24(u32 heap,u32 v);
void func_021F6F4C(u8 *p);
extern const char d_021F8454[];

void func_021F6F1C(void *a,char *p,u32 b,u32 c)
{
    ((struct Obj08025 *)p)->f14=b;
    ((struct Obj08025 *)p)->f18=c;
}

u8 *func_021F6F24(u32 heap,u32 v) { u8 *p; p=func_02030734(heap,64,0,d_021F8454,81); ((struct Obj08026 *)p)->f0=heap; ((struct Obj08026 *)p)->f4=v; ((struct Obj08026 *)p)->f8=0; ((struct Obj08026 *)p)->f1C=0; return p; }

/*
 * extent: two zero alignment bytes follow code.
 */
void func_021F6F4C(u8 *p) { if(*(u32 *)&((struct Obj00670 *)p)->f1C) func_021F7048(p,*(u32 *)&((struct Obj00670 *)p)->f1C); func_020307B0(p); }
