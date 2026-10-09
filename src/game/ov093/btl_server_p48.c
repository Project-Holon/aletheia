/*
 * file:     btl_server_p48.c
 * unit:     yes
 * function: func_021C334C, func_021C3370, func_021C3394, func_021C33E8
 * address:  0x021C334C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021C3428  0x021C3428  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D5B7C(void *);
extern int func_021D5B48(u8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021C3428(int, int);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5B74(u8 *p, u8 *a, int c, int d);
int func_021C334C(u8 *p, u8 *q, int a, int b);
int func_021C3370(u8 *p, void *q);
int func_021C3394(u8 *p, u8 *q, int r);
void func_021C33E8(int a, int b, int c);


int func_021C334C(u8 *p, u8 *q, int a, int b)
{
    if (func_021C3394(p, q, b) == 0) {
        func_021C33E8((int)p, (int)q, a);
        return 1;
    }
    return 0;
}


int func_021C3370(u8 *p, void *q)
{
    if (func_021D5B7C(q) == 0) return 1;
    if (func_021D5B48(q) != 0) return 1;
    return 0;
}



int func_021C3394(u8 *p, u8 *q, int r)
{
    if (func_021D62C4((struct Unk021D62A8 *)q, 15) != 0) {
        if (r != 0) {
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 887, func_021D5440(q), 0xffff0000);
            p[0x78A] |= 0x20;
        }
        return 1;
    }
    return 0;
}



void func_021C33E8(int a, int b, int c)
{
    int v = func_021C3428(a + 0x1ab8, func_021D5440((u8 *)b));
    if (v != 6)
        func_021CD4B0((void *)(*(int *)&((struct Obj00003 *)a)->fC), 0x4d, v, 0x263);
    func_021C5B74((u8 *)a, (u8 *)b, c, 1);
}
