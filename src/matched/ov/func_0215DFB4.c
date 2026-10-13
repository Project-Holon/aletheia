/*
 * function: func_0215DFB4
 * address:  0x0215DFB4
 * packet:   pkt_0215DFB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 92 compiled 90
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   func_021CD688  0x021CD688  thumb
 *   func_021FC804  0x021FC804  thumb
 *   func_021CD5A4  0x021CD5A4  thumb
 */
#include "../include/Obj02658.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern int GAME_DATA_GetExternalWork(char *base);
extern int func_021CD688();
extern int func_021FC804();
extern int func_021CD5A4();

int func_0215DFB4(int a0, int a1)
{
    int t4;
    int t5;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215DFBE:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215DFC4:
    a0 = GAME_DATA_GetExternalWork(v1);
loc_0215DFC8:
t4 = a0 + 0;
a0 = ((struct Obj02658 *)t4)->f8;
    a0 = func_021CD688(a0);
loc_0215DFD0:
t5 = 0;
    if (a0 == 1) goto loc_0215DFE0;
loc_0215DFD6:
    if (a0 == 2) goto loc_0215DFEC;
loc_0215DFDA:
    if (a0 == 4) goto loc_0215DFF4;
loc_0215DFDE:
    goto loc_0215DFFC;
loc_0215DFE0:
a0 = ((struct Obj02658 *)t4)->f30;
((struct Obj02658 *)((char *)a0))->f0 = t5;
a0 = ((struct Obj02658 *)t4)->f4;
    a0 = func_021FC804(a0);
loc_0215DFEA:
    goto loc_0215DFFA;
loc_0215DFEC:
a0 = ((struct Obj02658 *)t4)->f30;
t5 = 1;
((struct Obj02658 *)((char *)a0))->f0 = t5;
    goto loc_0215DFFC;
loc_0215DFF4:
a0 = ((struct Obj02658 *)t4)->f30;
a1 = 2;
((struct Obj02658 *)((char *)a0))->f0 = a1;
loc_0215DFFA:
t5 = 1;
loc_0215DFFC:
    if (t5 != 1) goto loc_0215E00A;
loc_0215E000:
a0 = ((struct Obj02658 *)t4)->f8;
    a0 = func_021CD5A4(a0);
loc_0215E006:
a0 = 0;
((struct Obj02658 *)t4)->f8 = a0;
loc_0215E00A:
a0 = t5 + 0;
    return a0;}
