/*
 * file:     btl_server_p26.c
 * unit:     yes
 * function: func_021BD554, func_021BD584, func_021BD60C, func_021BD6B8
 * address:  0x021BD554
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
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021B86E4  0x021B86E4  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021BD708  0x021BD708  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75A8(int, unsigned int);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern u8 func_021B8DDC(u32 x);
extern u8 func_021B8FF4(u8 *p);
extern void func_021BA1B4(char **p, int i);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021B86E4(unsigned int **p);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern int func_021D58A8(u8 *p, int k);
extern u32 func_021D78AC(u32 range);
extern int func_021BD708(u8 *p, u8 *a, int r, int z);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern int func_021D5B68(void *p);
void func_021BD554(u8 *p, u8 *m);
int func_021BD584(u8 *p, u8 *a);
int func_021BD60C(u8 *p, u8 *a, u8 flag);
int func_021BD6B8(u8 *p, u8 *a);

void func_021BD554(u8 *p, u8 *m)
{
    func_021D74F8(2712);
    func_021D75A8(2, func_021D5440(m));
    func_021D70F0(p, 164);
    func_021D7540(2715);
}


int func_021BD584(u8 *p, u8 *a)
{
    int k = func_021B8DDC(func_021D5440(a));
    int m = func_021B8FF4(*(u8 * *)&((struct Obj00003 *)p)->f4);
    int s = func_021BD60C(p, a, 0);
    if (s) return 1;
    if (k == m) {
        func_021BA1B4((char **)(*(u8 * *)&((struct Obj00003 *)p)->f4), 0x4e);
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x49, 0xffff0000);
    } else {
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x36b, func_021D5440(a), 0xffff0000);
    }
    if (k == m) {
        p[0x786]++;
        if (p[0x786] > 0x1e) p[0x786] = 0x1e;
    }
    return s;
}


int func_021BD60C(u8 *p, u8 *a, u8 flag)
{
    int ret = 0;
    int k;
    u8 *q;
    u16 lo;
    u16 hi;
    int d;
    u32 t;
    if (func_021B86E4((unsigned int **)(*(u8 * *)&((struct Obj00003 *)p)->f4)) == 0) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4(*(u8 * *)&((struct Obj00003 *)p)->f4)) {
            ret = func_021BD6B8(p, a);
            if (ret) flag = 1;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
        ret = 1;
    }
    if (flag == 0) {
        q = func_021B9920(*(u8 * *)&((struct Obj00003 *)p)->f8, 1, 0);
        if (q) {
            lo = func_021D58A8(a, 0xc);
            hi = func_021D58A8(q, 0xc);
            if (lo <= hi) {
                d = (((int)lo << 12) / (int)hi << 7) >> 12;
                t = d + p[0x786] * 30;
                if (func_021D78AC(0x100) >= t) return 0;
            }
        }
    }
    return func_021BD708(p, a, ret, 0);
}


int func_021BD6B8(u8 *p, u8 *a)
{
    int r;
    if (func_021D5B68(a) == 0) {
        func_021D74F8(2849);
        func_021D75EC(2, func_021D5440(a));
        func_021D7630(0x51, 0);
        func_021D70F0(p, 0xb);
        r = func_021D775C(0x51);
        func_021D7540(2854);
        return r;
    }
    return 0;
}
