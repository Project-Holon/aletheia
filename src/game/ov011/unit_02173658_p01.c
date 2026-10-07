/*
 * file:     unit_02173658_p01.c
 * unit:     yes
 * function: func_021736EC, func_02173728
 * address:  0x021736EC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_02039338 0x02039338 arm
 *   func_020399A8 0x020399A8 arm
 *   func_021736E0 0x021736E0 thumb ov011
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02026478 0x02026478 thumb
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012B4C 0x02012B4C thumb
 */
#include "../../matched/include/Obj12413.h"

struct Entry;
struct Link;
struct BigObj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern int func_021736D8(void);
extern u16 func_02039338(void);
extern struct Entry *func_020399A8(void);
extern void func_021736E0(int, int, int, char *, unsigned int);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_02026478(void *obj);
extern unsigned int func_0203D1A4(struct Link *);
extern void func_02012B4C(struct BigObj *p, u8 v);
int func_021736EC(char *p);
void func_02173728(unsigned int a, int b, u8 *c, u8 *d);

/*
 * The fifth argument to 021736E0 is visibly written to the outgoing stack slot.
 */
int func_021736EC(char *p)
{
    unsigned int n;
    if (func_021736D8() == 0) {
        n = func_02039338();
        func_021736E0(n, 0, 0, p, (unsigned int)func_020399A8());
        return 1;
    }
    return func_0203D3A8((struct Entry *)((unsigned int)func_020399A8()), 0x200, 0, 0);
}

/*
 * The loaded byte stays live as r1 into 02012B4C.
 */
void func_02173728(unsigned int a, int b, u8 *c, u8 *d)
{
    void *h;
    unsigned int n;
    h = (void *)func_02026478(((struct Obj12413 *)d)->f4);
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        n = *c;
        d[0x902] = n;
        func_02012B4C(h, n);
    }
}
