/*
 * file:     pms_input_view_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95F4
 * address:  0x021B95A0
 * region:   ov110
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
 *   func_020247A8 0x020247A8 thumb
 *   func_021B9608 0x021B9608 thumb ov110
 *   func_021B98A0 0x021B98A0 thumb ov110
 *   d_021C3B80 0x021C3B80 data a1
 *   func_020247F0 0x020247F0 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj05283.h"
#include "../../matched/include/Obj22311.h"

struct PmsWordSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct PmsWordSys *func_020247A8(u32 heapId);
extern void func_021B9608(void *);
extern void func_021B98A0(u8 *p);
extern void func_020247F0(char *);
extern u32 func_020307B0(void *p);
void *func_021B95A0(u32 heap,void *save);
void func_021B95F4(char *a);
extern const char d_021C3B80[];

void *func_021B95A0(u32 heap,void *save)
{
    char *p;
    int i;
    p=func_02030734((u16)heap,0x1E50,0,d_021C3B80,88);
    ((struct Obj05283 *)p)->f0=save;
    ((struct Obj05283 *)p)->f4=func_020247A8(heap);
    for(i=0;i<226;i++) *(u8 *)(p+0x1D6E + i)=0;
    func_021B9608(p);
    func_021B98A0((u8 *)p);
    return p;
}

void func_021B95F4(char *a) { if(a) { func_020247F0(*(char * *)&((struct Obj22311 *)a)->f4); func_020307B0(a); } }
