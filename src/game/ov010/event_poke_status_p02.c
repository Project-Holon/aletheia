/*
 * file:     event_poke_status_p02.c
 * unit:     yes
 * function: func_02159370, func_02159398, func_021593B8
 * address:  0x02159370
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215932C  0x0215932C  thumb  ov010
 *   func_02159AE8   0x02159AE8  thumb  ov010
 *   func_02011330   0x02011330  thumb
 */
#include "../../matched/include/Obj05851.h"
#include "../../matched/include/Obj12031.h"

struct Stream;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0215932C();
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02011330(struct Stream *s);
int func_02159370(int a0, int a1, int a2, int a3);
int func_02159398(void *a0, void *a1);
int func_021593B8(u8 *a, void *b);


int func_02159370(int a0, int a1, int a2, int a3)
{
    int t4;

t4 = a0 + 0;
a1 = ((struct Obj05851 *)t4)->f14;
a3 = ((struct Obj05851 *)t4)->f1C;
a0 = ((struct Obj12031 *)((char *)a1))->f0;
a2 = a1 + 1;
((struct Obj05851 *)t4)->f14 = a2;
a0 = a0 << 2;
a0 = *(int *)((char *)a3 + a0);
a1 = ((struct Obj12031 *)a1)->f1;
a0 = a0 << 0x18;
a2 = a2 + 1;
a0 = (unsigned)a0 >> 0x18;
((struct Obj05851 *)t4)->f14 = a2;
    a0 = func_0215932C(a0, a1, a2, a3);
loc_02159390:
((struct Obj05851 *)t4)->fE = a0;
a0 = 0;
    return a0;}


/*
 * Halfword out of the record the overlay looks up, classified through an
 * arm9 call, and the class byte stored back on the object.
 */
int func_02159398(void *a0, void *a1)
{
    u16 v = *func_02159AE8(a0, a1);

    *(u8 *)((char *)a0 + 0xE) = func_0215932C(v, func_02011330(a0));

    return 0;
}

int func_021593B8(u8 *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    u16 *q = func_02159AE8(a, b);
    a[14] = func_0215932C(*p, *q);
    return 0;
}
