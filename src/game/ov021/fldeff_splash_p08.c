/*
 * file:     fldeff_splash_p08.c
 * unit:     yes
 * function: func_021C4DA8, func_021C4DC0
 * address:  0x021C4DA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02011558  0x02011558  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj12132.h"

struct IcaAnime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    u32 f14;
} R;

extern void func_02011558(struct IcaAnime *p);
extern u32 func_020307B0(void *p);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
int func_021C4DA8(void *a);
void func_021C4DC0(R *r, u32 a, u32 b, u32 c);


int func_021C4DA8(void *a)
{
if (((struct Obj12132 *)((u8 *)(a)))->f10 != 0) {
    func_02011558((struct IcaAnime *)(((struct Obj12132 *)((u8 *)(a)))->f10));
}
return func_020307B0(a);
}


/*
 * Restarts the record's task with new arguments.
 */
void func_021C4DC0(R *r, u32 a, u32 b, u32 c)
{
    if (r->task != 0)
        func_02011558((struct IcaAnime *)r->task);
    r->task = (u32)func_02011510(r->heap, a, b, c);
}
