/*
 * function: MYSTERY_UTIL_CreateTaskEx
 * address: 0x021DA8CC
 * packet: pkt_ov121_021DA8CC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a and b are u16; the descriptor input pointer is const.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_Create 0x02043678 arm
 *   d_021DFBA0 0x021DFBA0 data a4
 *   BMP_OAM_Create  0x020255A0  thumb  arm9
 */
#include "../include/Obj06451.h"
#include "../include/Obj08095.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef struct { void *win; s16 x,y; int z; int pal; u8 a,b; u16 c; int d; } Desc;
extern char d_021DFBA0[];
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void *STRBUF_Create(int,u16);
struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Grid;
struct Param;
struct Sys;
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
void *MYSTERY_UTIL_CreateTaskEx(const char *p,u16 a,u16 b,int c,u8 d,int e,void *f,void *g,u16 heap)
{
    Desc desc;
    char *out=func_02030734(heap,36,0,d_021DFBA0,0x6b1);
    MI_CpuFill8(out,0,36);
    ((struct Obj06451 *)out)->f20=g;
    ((struct Obj06451 *)out)->f18=STRBUF_Create(128,heap);
    ((struct Obj06451 *)out)->f0=BMP_Create(a,b,32,heap);
    MI_CpuFill8(&desc,0,24);
    desc.win=((struct Obj06451 *)out)->f0;
    desc.x=((struct Obj08095 *)p)->f0;
    desc.y=((struct Obj08095 *)p)->f2;
    desc.z=c;
    desc.a=((struct Obj08095 *)p)->f6;
    desc.c=e;
    desc.d=e;
    desc.b=((struct Obj08095 *)p)->f7;
    desc.pal=d;
    ((struct Obj06451 *)out)->f1C=BMP_OAM_Create(f,(const struct Param *)(&desc));
    return out;
}
