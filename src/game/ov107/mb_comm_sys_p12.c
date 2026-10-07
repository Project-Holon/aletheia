/*
 * file:     mb_comm_sys_p12.c
 * unit:     yes
 * function: func_021F0DDC, func_021F0DE8, func_021F0E40
 * address:  0x021F0DDC
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
 *   d_021F6EAC  0x021F6EAC  data
 *   func_02030734 0x02030734 arm
 *   func_020173E8 0x020173E8 thumb
 *   d_021F6E28 0x021F6E28 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_0203E6C0 0x0203E6C0 arm
 */
#include "../../matched/include/G_Masks.h"
#include "../../matched/include/Obj10259.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct {u16 f00,pad02;u32 f04,f08,f0C;void *f10;u32 f14;u16 pad18:11;u16 f18:1;u16 pad19:4;u8 pad1A[14];} Object;

typedef struct {u8 pad[24];unsigned short low:11,flag:1,rest:4;} State;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020173E8(void);
extern u32 func_020307B0(void *p);
extern void func_0203E6C0(void);
u32 func_021F0DDC(void);
Object *func_021F0DE8(u16 heap);
void func_021F0E40(State *p);
extern struct Masks d_021F6EAC;
extern const char d_021F6E28[];

u32 func_021F0DDC(void) { return *(u32 *)(((u8 *)&d_021F6EAC) + 0x18); }

Object *func_021F0DE8(u16 heap){Object *p;p=func_02030734(heap,40,1,d_021F6E28,159);p->f00=heap;p->f04=0;p->f14=0;p->f18=0;p->f0C=0;p->f08=0;p->f10=func_02030734(p->f00,6*func_020173E8()+4,1,d_021F6E28,169);return p;}

void func_021F0E40(State *p) { if(((struct Obj10259 *)p)->f14)func_020307B0(((struct Obj10259 *)p)->f14);if(p->flag==1)func_0203E6C0();func_020307B0(((struct Obj10259 *)p)->f10);func_020307B0(p); }
