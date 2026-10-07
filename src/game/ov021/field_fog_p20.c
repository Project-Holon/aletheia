/*
 * file:     field_fog_p20.c
 * unit:     yes
 * function: func_021A0D44, func_021A0D68
 * address:  0x021A0D44
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
 *   func_020307B0  0x020307B0  arm
 *   d_021D8738     0x021D8738  data
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   d_021D872C  0x021D872C  data  a4
 */
#include "../../matched/include/G_021D8738.h"
#include "../../matched/include/Obj02081.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    void (*init)(u32 *a, u32 prev);
    void (*update)(u32 *a, s32 flag);
    u32 f8;
    u32 fC;
    void (*exit)(u32 *a);
    u32 f14;
    u32 f18;
} Mode;

extern u32 func_020307B0(void *p);
extern int func_02189A2C(int *a);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
u8 func_021A0D44(u32 *p);
void func_021A0D68(u32 *a);
extern struct G_021D8738 d_021D8738[];
extern Mode d_021D872C[];


/*
 * Addresses are Black-image addresses.
 */
u8 func_021A0D44(u32 *p)
{
    u32 id = p[0];
    d_021D8738[id].fn(p);
    func_020307B0(p);
    return id;
}


void func_021A0D68(u32 *a)
{
    switch (a[2]) {
    case 0:
        d_021D872C[a[0]].update(a, func_02189A2C((int *)a[5]) == 0);
        break;
    case 1:
        func_0202208C((void *)4, 0, 0, 0, 1, 1, ((struct Obj02081 *)a)->fC);
        a[2] = 2;
        break;
    case 2:
        if (func_020221A4() == 1) {
            d_021D872C[a[0]].exit(a);
            d_021D872C[a[1]].init(a, a[0]);
            a[0] = a[1];
            a[2] = 4;
        }
        break;
    case 3:
        break;
    case 4:
        func_0202208C((void *)4, 1, 1, 0, 1, 1, ((struct Obj02081 *)a)->fC);
        a[2] = 5;
        break;
    case 5:
        if (func_020221A4() == 1) {
            a[2] = 0;
        }
        d_021D872C[a[0]].update(a, func_02189A2C((int *)a[5]) == 0);
        break;
    }
}
