/*
 * file:     zukan_detail_graphic_p34.c
 * unit:     yes
 * function: func_021C2A70, func_021C2BA8, func_021C2BE0, func_021C2BF4
 * address:  0x021C2A70
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_021C34A4  0x021C34A4  thumb  ov208
 *   func_021BDBA0  0x021BDBA0  thumb  ov208
 *   func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_021BDC2C  0x021BDC2C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 *   func_02040618  0x02040618  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021BC6BC  0x021BC6BC  thumb
 *   func_02005E30  0x02005E30  thumb
 */
#include "../../matched/include/Obj08403.h"
#include "../../matched/include/Obj25506.h"
#include "../../matched/include/Obj00146.h"

struct Ov208Cur;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

struct S {
    u8 pad0[0xcc];
    u32 fcc;
    u32 fd0;
};

extern int func_021BC3B4(int *p);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(struct Ov208Cur *p);
extern void func_021C34A4(u16 *heap, u8 *p, int key);
extern void func_021BDBA0(int p);
extern int func_021BC3A4(int *p);
extern int func_021BDC2C(char *p);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020409B4(u32 index);
extern void func_021BC6BC(char *p);
extern void func_02005E30(u32 v);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);
void func_021C2A70(void *a0, void *a1, void *heap, struct S *st, int *obj, int key);
void func_021C2BA8(void *unused, u8 *p);
void func_021C2BE0(void *unused, u8 *p, void *a2);
void func_021C2BF4(void *unused, char *p, void *a2);


void func_021C2A70(void *a0, void *a1, void *heap, struct S *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 17:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 18:
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 9:
        flag = 1;
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->fcc = 2;
        return;
    case 6: case 7: case 9:
        st->fcc = 1;
        return;
    case 3:
        func_021BDBA0(sc);
        return;
    case 4:
        func_021BDBA0(sc);
        return;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x13, func_021BDC2C((char *)sc));
        func_021BDBA0(sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0(sc);
        }
        break;
    }
}


void func_021C2BA8(void *unused, u8 *p)
{
    if (((struct Obj08403 *)p)->f1C != 0) {
        func_02040618(3, 0, ((struct Obj08403 *)p)->f18 - 1);
        func_02040618(3, 3, 0);
        func_020409B4(3);
        ((struct Obj08403 *)p)->f1C = 0;
    }
    func_021BC6BC(*(char * *)&((struct Obj08403 *)p)->fC8);
}


void func_021C2BE0(void *unused, u8 *p, void *a2)
{
    func_02005E30(0x1e);
    ((struct Obj25506 *)p)->fB8 = 1;
}


/*
 * Leaves state 2 and moves the object at +0xB8 to state 3.
 */
void func_021C2BF4(void *unused, char *p, void *a2)
{
    if (((struct Obj00146 *)p)->fB8 == 2) {
        func_02005E9C();
        func_02005DE4(0);
    }
    func_02005DF8(0x3c);
    ((struct Obj00146 *)p)->fB8 = 3;
}
