/*
 * file:     fldeff_splash_p04.c
 * unit:     yes
 * function: func_021C4D7C, func_021C4DA8, func_021C4DC0, func_021C4DE4
 * address:  0x021C4D7C
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   d_021DE48C     0x021DE48C  data  ov021
 *   func_02011558  0x02011558  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021C4E34  0x021C4E34  thumb  ov021
 *   func_021C4E6C  0x021C4E6C  thumb  ov021
 */
#include "../../matched/include/Obj12132.h"

struct IcaAnime;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
} R_021C4D7C;

typedef unsigned char  u8;

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
} R_021C4DA8;

typedef signed int s32;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    u32 f14;
} R;

extern u16 func_02188C84(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02011558(struct IcaAnime *p);
extern u32 func_020307B0(void *p);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern void func_021C4E34(R *r);
extern void func_021C4E6C(char *p);
R_021C4D7C *func_021C4D7C(void *owner, u32 v);
int func_021C4DA8(void *a);
void func_021C4DC0(R_021C4DA8 *r, u32 a, u32 b, u32 c);
u32 func_021C4DE4(R *r, s32 dv);
extern char d_021DE48C[];



/*
 * Allocates the 0x18-byte script-runner record.
 */
R_021C4D7C *func_021C4D7C(void *owner, u32 v)
{
    u32 heap = func_02188C84(owner);
    R_021C4D7C *r = func_02030734(heap, 0x18, 0, d_021DE48C, 0x61);

    r->heap = heap;
    r->owner = owner;
    r->f8 = 0;
    r->f10 = 0;
    r->f14 = v;
    return r;
}




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
void func_021C4DC0(R_021C4DA8 *r, u32 a, u32 b, u32 c)
{
    if (r->task != 0)
        func_02011558((struct IcaAnime *)r->task);
    r->task = (u32)func_02011510(r->heap, a, b, c);
}


u32 func_021C4DE4(R *r, s32 dv)
{
    u32 v;

    if (r->task == 0)
        return 0;
    v = func_02011590((struct IcaAnime *)r->task, dv);
    func_021C4E34(r);
    func_021C4E6C((char *)r);
    return v;
}
