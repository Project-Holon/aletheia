/*
 * file:     comm_player_p24.c
 * unit:     yes
 * function: func_021699A0, func_02169A14, func_02169A68
 * address:  0x021699A0
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
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0207DEA4  0x0207DEA4  arm
 *   func_02046F48  0x02046F48  arm
 */
#include "../../matched/include/Obj04164.h"
#include "../../matched/include/Obj02337.h"

struct Tagged;
typedef unsigned char u8;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned short u16;

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void func_0206DB80(void);
extern int func_0207DEA4(s32 *in);
extern void *func_02046F48(struct Tagged *p);
int func_021699A0(void *p);
u32 func_02169A14(u32 a);
void *func_02169A68(int a0);


int func_021699A0(void *p)
{
    s16 v[6];
    u32 w[3];
    u32 one;
    char *q;
    int r;

    r = 1;
    q = p ? (char *)p + 0x14 : 0;
    v[0] = ((struct Obj04164 *)q)->f18;
    v[1] = ((struct Obj04164 *)q)->f1A;
    v[2] = ((struct Obj04164 *)q)->f1C;
    v[3] = ((struct Obj04164 *)q)->f1E;
    v[4] = ((struct Obj04164 *)q)->f20;
    v[5] = ((struct Obj04164 *)q)->f22;
    func_0206DDA4(0x11, 0, 0);
    w[0] = ((struct Obj04164 *)q)->f24;
    w[1] = w[0];
    w[2] = w[0];
    func_0206DDA4(0x1b, w, 3);
    if (func_02169A14((u32)v) == 0)
        r = 0;
    one = 1;
    func_0206DDA4(0x12, &one, 1);
    return r;
}


u32 func_02169A14(u32 a)
{
    u32 x;
    u32 y;
    u32 z;

    x = 1;
    y = 0x30C1;
    func_0206DDA4(0x29, &y, 1);
    z = 0;
    func_0206DDA4(0x40, &z, 1);
    func_0206DDA4(0x41, 0, 0);
    func_0206DDA4(0x70, (void *)a, 3);
    func_0206DB80();
    while (func_0207DEA4((s32 *)(&x)) != 0)
        ;
    return x;
}


void *func_02169A68(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
a0 = a0 + 0x88;
a0 = *(int *)&((struct Obj02337 *)((char *)a0))->f0;
    p = func_02046F48((struct Tagged *)a0);
loc_02169A74:
    if (p != 0) goto loc_02169A82;
loc_02169A78:
a0 = t4 + 0;
a0 = a0 + 0x94;
p = ((struct Obj02337 *)((char *)a0))->f0;
    if (p != 0) goto loc_02169A86;
loc_02169A82:
t4 = t4 + 0x88;
p = ((struct Obj02337 *)((char *)t4))->f0;
loc_02169A86:
    return p;}
