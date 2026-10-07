/*
 * file:     wifi_2dchar_p03.c
 * unit:     yes
 * function: func_021C42C4, func_021C42FC, func_021C4330, func_021C4354, func_021C4358
 * address:  0x021C42C4
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C4634 0x021C4634 thumb ov127
 *   d_021C5FB0 0x021C5FB0 data a4
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../../matched/include/Obj10465.h"
#include "../../matched/include/Obj23022.h"
#include "../../matched/include/Obj14018.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int     s32;

extern void func_021C4634(u8 *);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204AFD8(u32);
void func_021C42C4(u8 *p);
void func_021C42FC(char *p, int unused, u32 heap);
void func_021C4330(char *p, int a1);
void func_021C4354(void);
int func_021C4358(int a0, int a1);
extern const u8 d_021C5FB0[];

void func_021C42C4(u8 *p) { int flag; int n; flag=0; n=d_021C5FB0[((struct Obj10465 *)p)->fC]; if(n==255) flag=1; else if(n>=((struct Obj10465 *)p)->f14+1) flag=1; if(flag==1) { func_021C4634(p); ((struct Obj10465 *)p)->f14+=1; } }

/*
 * extent: trailing 2-byte alignment padding only.
 */
void func_021C42FC(char *p, int unused, u32 heap) { int i; for(i=16;i<18;i++) { *(u32 *)((u32)p+(u32)i*20+0x188)=func_0204AF28(((struct Obj23022 *)p)->f2F8,(i-16)*2,(i-16)*2+1,(u16)heap); } }

void func_021C4330(char *p, int a1) { int i; char *q; for(i=16;i<18;i++) { q=(char *)((u32)p+(u32)i*20); func_0204AFD8(((struct Obj14018 *)q)->f188); ((struct Obj14018 *)q)->f188=0; } }


void func_021C4354(void) { }


int func_021C4358(int a0, int a1) { return 1; }
