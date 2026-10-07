/*
 * file:     unit_021F36C0_p03.c
 * unit:     yes
 * function: func_021F3874, func_021F38B0, func_021F38E4, func_021F3918
 * address:  0x021F3874
 * region:   ov054
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048F60 0x02048F60 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021F394C 0x021F394C data a4
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E20 0x021C4E20 thumb ov021
 *   func_021C4E08 0x021C4E08 thumb ov021
 *   func_02005728 0x02005728 thumb
 */
#include "../../matched/include/Obj03165.h"

struct Big;
struct Ctx;
struct Rec94;
typedef struct { int v[2]; } Pair;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

extern void *func_02048F60(unsigned int,unsigned int,unsigned int);
extern u32 func_020307B0(void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_021C4E20(void *);
extern int func_021C4E08(void *,int);
extern unsigned func_02005728(unsigned);
void func_021F3874(char *p);
void func_021F38B0(char *p,int a);
void func_021F38E4(char *p,int a);
void func_021F3918(char *p, int i);
extern Pair d_021F394C;

void func_021F3874(char *p) { Pair t=d_021F394C; int i; for(i=0;i<2;i++){ int *q=func_02048F60(0x7f,t.v[i],((struct Obj03165 *)p)->f0); ((int *)(p+0x18))[i]=q[0]; ((int *)(p+0x20))[i]=q[1]; func_020307B0(q); } }

void func_021F38B0(char *p,int a) { int *q=func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))),11); int i; for(i=0;i<2;i++) { int offset=4*i; int v=func_021C4E20(*(void **)(p+8+offset)); *(int *)((char *)q+offset)=v>>12; } }

void func_021F38E4(char *p,int a) { int *q=func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))),11); int i; for(i=0;i<2;i++) func_021C4E08(*(void **)(p+8+4*i),(int)((unsigned)q[i]<<12)); }

void func_021F3918(char *p, int i)
{
    ((int *)(p + 0x10))[i] = ((int *)(p + 0x18))[i] +
        func_02005728(((int *)(p + 0x20))[i] - ((int *)(p + 0x18))[i] + 1);
}
