/*
 * file:     unit_021B95A0_p11.c
 * unit:     yes
 * function: func_021BA168, func_021BA190, func_021BA1C4, func_021BA1FC, func_021BA228
 * address:  0x021BA168
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
 *   func_021C5680 0x021C5680 thumb ov127
 *   func_021C57D8 0x021C57D8 thumb ov127
 *   func_021C57DC 0x021C57DC thumb ov127
 *   func_021C5840 0x021C5840 thumb ov127
 *   func_021C4918 0x021C4918 thumb ov127
 *   func_021BA418 0x021BA418 thumb ov099
 *   func_021BA2D0 0x021BA2D0 thumb ov099
 *   func_021BA5B4 0x021BA5B4 thumb ov099
 */
#include "../../matched/include/Obj02660.h"
#include "../../matched/include/Obj06347.h"
#include "../../matched/include/Obj02800.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BA168;

typedef signed short   s16;

typedef int BOOL;

typedef unsigned int u32_021BA190;

typedef unsigned int u32_021BA1C4;

typedef struct { short x,y; u16 a,b,c,d; } Params;

typedef unsigned long  u32_021BA1FC;

typedef signed char    s8;

typedef signed long    s32;

typedef struct {
    char pad[0x0C];
    u16 f0C;
} S;

typedef unsigned int u32_021BA228;

extern u8 *func_021C5680(u8 *,void *,int,u32_021BA190);
extern void func_021C57D8(void *,int);
extern void func_021C57DC(u8 *);
extern void func_021C5840(char *,int);
extern void *func_021C4918(void *,Params *);
extern int func_021BA418(void *,void *);
extern int func_021BA2D0(void *,void *);
extern void func_021BA5B4(void *,int,void *);
u8 *func_021BA168(u8 *p);
void func_021BA190(u8 *p,u8 *s,int n);
void func_021BA1C4(u8 *p,void **out,short *xy,int a,u16 d,u8 c,int b);
BOOL func_021BA1FC(S *s);
void func_021BA228(void *w,u8 *s);


/*
 * Scans the 0x30 records of 0x1C bytes at +0x30 and returns the address of the
 * first whose leading word is zero, else 0.  Two earlier lanes read the
 * product/address register pair as allocator taste; it is the two address
 * spellings.  With both written field-constant-first the compiler homes the
 * `i * 0x1C` product in r2 and prints `adds r3, r0, r2`, which is not what the
 * image has.  Writing the load field-last (`p + i * 0x1C + 0x30`, giving
 * `adds r2, r0, r3 ; ldr r2, [r2, #0x30]`) and the exit field-first
 * (`(u8 *)(p + 0x30) + i * 0x1C`, giving `adds r0, #0x30 ; adds r0, r0, r3`)
 * is what reproduces the image exactly.
 */
u8 *func_021BA168(u8 *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021BA168 *)(p + i * 0x1C + 0x30) == 0) {
            return (u8 *)(p + 0x30) + i * 0x1C;
        }
    }
    return 0;
}

void func_021BA190(u8 *p,u8 *s,int n) { *(u8 * *)&((struct Obj02660 *)s)->f4=func_021C5680(*(u8 * *)&((struct Obj06347 *)p)->f590,((struct Obj02660 *)s)->f0,n,((struct Obj06347 *)p)->f4); if (n==0) { func_021C57D8(((struct Obj02660 *)s)->f4,0); func_021C57DC(*(u8 * *)&((struct Obj02660 *)s)->f4); func_021C5840(*(char * *)&((struct Obj02660 *)s)->f4,0); } }

void func_021BA1C4(u8 *p,void **out,short *xy,int a,u16 d,u8 c,int b) { Params q; q.x=xy[0]; q.y=xy[1]; q.a=a; q.b=b; q.c=c; q.d=d; *out=func_021C4918(((struct Obj06347 *)p)->f58C,&q); }


BOOL func_021BA1FC(S *s)
{
    switch (s->f0C) {
    case 0:
    case 3:
    case 4:
        return 1;
    case 1:
    case 2:
    case 5:
        return 0;
    }

    return 0;
}

void func_021BA228(void *w,u8 *s) { ((struct Obj02800 *)s)->f10=(void *)func_021BA418; ((struct Obj02800 *)s)->f18=(void *)func_021BA2D0; ((struct Obj02800 *)s)->fC=0; func_021BA5B4(w,0,s); }
