/*
 * file:     unit_021BF050_p14.c
 * unit:     yes
 * function: func_021C12FC, func_021C1334
 * address:  0x021C12FC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021BCC58  0x021BCC58  thumb  ov099
 */
#include "../../matched/include/Obj10210.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32_021C12FC;

typedef unsigned short u16;

typedef unsigned long  u32_021C1334;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern void func_021BCC58(char *p, u32_021C1334 x);
void func_021C12FC(int a,int b,u8 *data,char *p,int handle);
void func_021C1334(int a, int b, int *p, void *q, int e);

void func_021C12FC(int a,int b,u8 *data,char *p,int handle){if(handle==(int)func_020399A8()){if(((struct Obj10210 *)p)->f1CC==0x48){((struct Obj10210 *)p)->f1357=*data;func_02039C68((struct Link *)func_020399A8(),0x1a,10);}else ((struct Obj10210 *)p)->f1CC=21;}}


/*
 * When the fifth argument matches the arm9 predicate, applies the first word of the third to the fourth.
 */
void func_021C1334(int a, int b, int *p, void *q, int e)
{
    if (e == (int)func_020399A8()) {
        func_021BCC58(q, *p);
    }
}
