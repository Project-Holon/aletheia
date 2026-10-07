/*
 * file:     fldmmdl_p10.c
 * unit:     yes
 * function: func_0216CEE4, func_0216CF2C
 * address:  0x0216CEE4
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
 *   func_0216E418  0x0216E418  thumb  ov010
 *   func_0216E42C  0x0216E42C  thumb  ov010
 *   func_0216CDC4  0x0216CDC4  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D71C  0x0216D71C  thumb  ov010
 *   func_0216DFAC  0x0216DFAC  thumb  ov010
 *   func_0216D508  0x0216D508  thumb  ov010
 *   func_0216E180  0x0216E180  thumb  ov010
 */
#include "../../matched/include/Obj00113.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u16 id;
    u16 pad0[3];
    u16 key;
    u16 pad1[13];
} Ent;

extern int func_0216E418(void *a);
extern unsigned int func_0216E42C(void *bitmap, int id);
extern int func_0216CDC4(u32 a, Ent *e, u32 b, u32 c);
extern void *func_0216D67C(void *a0);
extern int func_0216D948(int a0);
extern int func_0216D76C();
extern int func_0216D55C(int a0, int a1);
extern int func_0216D71C();
extern int func_0216DFAC(int a0);
extern int func_0216D508(int a0);
extern int func_0216E180();
int func_0216CEE4(u32 a, Ent *e, u32 b, int n, u32 c, u32 id);
int func_0216CF2C(int a0, int a1);


/*
 * The result local is never initialised on the not-found path (the
 * original returns whatever stack slot it had).
 */
int func_0216CEE4(u32 a, Ent *e, u32 b, int n, u32 c, u32 id)
{
    int r;

    do {
        if (func_0216E418(e) == 0 && e->id == id && func_0216E42C((void *)c, e->key) == 0) {
            r = func_0216CDC4(a, e, b, c);
            break;
        }
        e++;
    } while (--n);
    return r;
}


int func_0216CF2C(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216CF34:
    a0 = func_0216D948(a0);
loc_0216CF38:
    if (a0 != 1) goto loc_0216CF42;
loc_0216CF3C:
a0 = t4 + 0;
    a0 = func_0216D76C(a0);
loc_0216CF42:
a0 = t4 + 0;
a1 = 2;
    a0 = func_0216D55C(a0, a1);
loc_0216CF4A:
    if (a0 == 0) goto loc_0216CF5A;
loc_0216CF4E:
a0 = t4 + 0;
    a0 = func_0216D71C(a0);
loc_0216CF54:
a0 = t4 + 0;
    a0 = func_0216DFAC(a0);
loc_0216CF5A:
a0 = t4 + 0;
a0 = a0 + 0x88;
a0 = *(int *)&((struct Obj00113 *)((char *)a0))->f0;
    a0 = func_0216D508(a0);
loc_0216CF64:
a0 = t4 + 0;
    a0 = func_0216E180(a0);
loc_0216CF6A:
    return a0;}
