/*
 * file:     event_poke_status_p16.c
 * unit:     yes
 * function: func_0215A55C, func_0215A5A4
 * address:  0x0215A55C
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
 *   func_02030734 0x02030734 arm
 *   func_02158F6C 0x02158F6C thumb ov010
 *   d_021728E0 0x021728E0 data ov010 a4
 *   func_020307B0  0x020307B0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0215A738  0x0215A738  thumb  ov010
 */
#include "../../matched/include/Obj05883.h"
#include "../../matched/include/Obj04882.h"

typedef struct { int w[4]; } S16;

typedef struct { unsigned short id; S16 r; } T;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern unsigned int func_02158F6C(void *);
extern int func_020307B0();
extern int func_02045C04();
extern int func_0215A738(int a0);
void *func_0215A55C(const S16 *src, int v);
int func_0215A5A4(int a0);
extern int d_021728E0;

/*
 * lever: const source pointer hoists its copy before the destination id store.
 */
void *func_0215A55C(const S16 *src, int v)
{
    T *p;
    const S16 *s;
    p = (T *)func_02030734((unsigned short)((v & 0x7fff) | 0x8000), 0x24, 1, (const char *)&d_021728E0, 0x94);
    s = src;
    p->id = v;
    p->r = *s;
    ((struct Obj05883 *)p)->f20 = func_02158F6C((void *)src->w[3]);
    return p;
}


int func_0215A5A4(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj04882 *)t4)->f1C;
    if (a0 == 0) goto loc_0215A5B2;
loc_0215A5AE:
    a0 = func_020307B0(a0);
loc_0215A5B2:
a0 = ((struct Obj04882 *)t4)->f14;
    if (a0 == 0) goto loc_0215A5BC;
loc_0215A5B8:
    a0 = func_02045C04(a0);
loc_0215A5BC:
a0 = t4 + 0;
    a0 = func_0215A738(a0);
loc_0215A5C2:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215A5C8:
    return a0;}
