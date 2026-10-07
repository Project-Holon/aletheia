/*
 * file:     field_nogrid_mapper_p13.c
 * unit:     yes
 * function: func_021BB0B4, func_021BB11C, func_021BB13C, func_021BB188, func_021BB1A0, func_021BB1AC, func_021BB1B8
 * address:  0x021BB0B4
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
 *   func_0204A298  0x0204A298  arm
 *   func_02030734  0x02030734  arm
 *   d_021DE2C4     0x021DE2C4  data  a4
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj07530.h"
#include "../../matched/include/Obj20092.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32;

extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
void func_021BB0B4(u32 *a, u32 b, u32 c);
void func_021BB11C(u32 *p);
int func_021BB13C(char *a, char *b);
int func_021BB188(u16 a);
int func_021BB1A0(int x);
int func_021BB1AC(int x);
int func_021BB1B8(int x);
extern int d_021DE2C4;


void func_021BB0B4(u32 *a, u32 b, u32 c)
{
    u32 i = 0;
    u32 off;

    a[0] = (u32)func_0204A298(0x4f, (u32)b, 0, (u16)c, &a[1]);
    a[2] = *(u32 *)a[0];
    a[3] = (u32)func_02030734((u16)c, a[2] * 4, 1, (const char *)&d_021DE2C4, 0x86);
    off = 4;
    for (i = 0; i < a[2]; i++) {
        u16 *q;

        ((u32 *)a[3])[i] = a[0] + off;
        q = (u16 *)((u32 *)a[3])[i];
        off += q[0] * q[1] * 4 + 4;
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BB11C(u32 *p)
{
    if (p[0] != 0) {
        func_020307B0((void *)p[3]);
        func_020307B0((void *)p[0]);
        p[2] = 0;
        p[3] = 0;
        p[0] = 0;
    }
}


int func_021BB13C(char *a, char *b)
{
    int r = -1;
    if (((struct Obj07530 *)b)->f2 == 1) {
        unsigned idx = ((struct Obj07530 *)b)->f0;
        if (((struct Obj20092 *)a)->f8 > idx) {
            unsigned short *e = (*(unsigned short ***)(a + 0xc))[idx];
            unsigned w = e[0];
            int x = ((struct Obj07530 *)b)->f4 + (w >> 1);
            int y = ((struct Obj07530 *)b)->f6;
            if ((int)w > x && e[1] > y && x >= 0 && y >= 0)
                r = *(int *)((char *)e + (x + w * y) * 4 + 4);
        }
    }
    return r;
}


int func_021BB188(u16 a)
{
    if ((u16)(a + 0xFF60) <= 1) {
        return 1;
    }
    return 0;
}


int func_021BB1A0(int x)
{
    if (x == 163)
        return 1;
    return 0;
}


int func_021BB1AC(int x)
{
    if (x == 165)
        return 1;
    return 0;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
int func_021BB1B8(int x)
{
    if (x == 164)
        return 1;
    return 0;
}
