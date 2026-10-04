/*
 * function: func_021FC374
 * address:  0x021FC374
 * packet:   pkt_ov094_021FC374
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: loads script id (archive 0x42 below 0x231, else 0x43) into the buffer at 0x1e8 and jumps into it.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02048F60 0x02048F60 arm
 *   func_020113B0 0x020113B0 thumb
 */
#include "../include/Obj03713.h"
#include "../include/Obj21683.h"
typedef unsigned short u16;

extern int func_0201134C(void *);
extern void func_020307B0(void *);
extern char *func_02048F60(int, int, u16);
typedef unsigned int   u32;
struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);

int func_021FC374(void *a, char *s)
{
    int id = func_0201134C(a);
    char *p;

    func_020307B0(((struct Obj03713 *)s)->f1E8);
    if (id < 0x231)
        *(char * *)&((struct Obj03713 *)s)->f1E8 = func_02048F60(0x42, id, (((struct Obj03713 *)s)->f238 & 0x7fff) | 0x8000);
    else
        *(char * *)&((struct Obj03713 *)s)->f1E8 = func_02048F60(0x43, id - 0x231, (((struct Obj03713 *)s)->f238 & 0x7fff) | 0x8000);
    p = *(char * *)&((struct Obj03713 *)s)->f1E8;
    ((struct Obj03713 *)s)->f4 = 0;
    func_020113B0(a, (u32)(p + ((struct Obj21683 *)p)->f4));
    return ((struct Obj03713 *)s)->f23C;
}
