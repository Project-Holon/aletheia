/*
 * file:     unit_021B95A0_p14.c
 * unit:     yes
 * function: func_021BB114, func_021BB120, func_021BB134, func_021BB138, func_021BB140
 * address:  0x021BB114
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj13145.h"
#include "../../matched/include/Obj13146.h"
#include "../../matched/include/Obj20651.h"
#include "../../matched/include/Obj20652.h"

typedef unsigned char u8;

typedef void (*Callback)(void *, void *, int);

void func_021BB114(void *p);
void func_021BB120(u8 *p);
int func_021BB134(void *p);
void func_021BB138(void *p, int v);
void func_021BB140(void *p);

/*
 * Tail call to func_02082BCC(p, 0, 0x10).
 */
void func_021BB114(void *p)
{
    void func_02082BCC(void *, int, int);
    func_02082BCC(p, 0, 0x10);
}

void func_021BB120(u8 *p)
{
    if (((struct Obj13145 *)p)->f4 == 0)
        (*(Callback *)p)(p, p + 8, ((struct Obj13145 *)p)->fC);
}


int func_021BB134(void *p)
{
    return ((struct Obj20651 *)p)->f4;
}


/*
 * Getter and two small setters.
 */
void func_021BB138(void *p, int v)
{
    ((struct Obj13146 *)p)->f0 = v;
    ((struct Obj13146 *)p)->f8 = 0;
}


void func_021BB140(void *p)
{
    ((struct Obj20652 *)p)->f4 = 1;
}
