/*
 * function: func_0216A6B4
 * address:  0x0216A6B4
 * packet:   pkt_0216A6B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 56 compiled 54
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021D0FE0  0x021D0FE0  thumb
 */
#include "../include/Obj17760.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_021D0FE0();

int func_0216A6B4(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    u16 *q;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A6C0:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A6C6:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A6CC:
    v2 = GAME_DATA_GetListCursor(p);
loc_0216A6D0:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A6DA:
a1 = ((struct Obj17760 *)((char *)v2))->f0;
    a0 = func_021D0FE0(v1, a1);
loc_0216A6E4:
*q = a0;
a0 = 0;
    return a0;}
