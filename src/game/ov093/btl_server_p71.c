/*
 * file:     btl_server_p71.c
 * unit:     yes
 * function: func_021C56A8, func_021C5718, func_021C572C, func_021C5750, func_021C5774, func_021C5798, func_021C5840, func_021C59C4, func_021C5A1C, func_021C5A34, func_021C5A4C, func_021C5A8C, func_021C5B74
 * address:  0x021C56A8
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
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D7E10  0x021D7E10  thumb  ov093
 *   func_021CD64C   0x021CD64C  thumb
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021C604C  0x021C604C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021CD63C  0x021CD63C  thumb  ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021C5BD4  0x021C5BD4  thumb  ov093
 */
#include "../../matched/include/Obj18306.h"
#include "../../matched/include/Obj07752.h"
#include "../../matched/include/Obj21098.h"
#include "../../matched/include/Obj21099.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13335.h"
#include "../../matched/include/Obj04360.h"

struct Unk021D62A8;
struct Unk021D5FA4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D7E10(struct Unk021D62A8 *p);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD63C(void *p, int v);
extern void func_021C604C(u8 *p, u8 *a, int n);
extern u8 func_021D5DC0(s8 *p, int i, u8 n);
extern u8 func_021D5E38(s8 *p, int i, u8 n);
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern int func_021C5BD4(void *p, int v);
int func_021C56A8(u8 *p, int *pv);
void func_021C5718(u8 *p);
void func_021C572C(u8 *p, u8 *a, u32 v);
void func_021C5750(u8 *p, u8 *a);
void func_021C5774(u8 *p, u8 *a);
void func_021C5798(u8 *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2);
void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag);
void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag);
void func_021C5A1C(u8 *p, u8 *a);
void func_021C5A34(u8 *p, u8 *a);
void func_021C5A4C(u8 *p, u8 *a, int b, int c);
void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag);
void func_021C5B74(u8 *p, u8 *a, int c, int d);



int func_021C56A8(u8 *p, int *pv)
{
    int ret = 0;
    int r = func_021D62A8((struct Unk021D62A8 *)p);
    int t;
    switch (*pv) {
    case 0:
        break;
    case 0x24:
        if (r) ret = r;
        *pv = 0;
        break;
    case 0x25:
        if (r) {
            ret = r;
            *pv = 6;
        } else {
            if (func_021D62C4((struct Unk021D62A8 *)p, 6)) ret = 6;
            *pv = 0;
        }
        break;
    case 0x26:
        t = func_021D7E10((struct Unk021D62A8 *)p);
        if (t) return t;
        *pv = ret;
        return t;
    default:
        if (func_021D62C4((struct Unk021D62A8 *)p, *pv)) ret = *pv;
        *pv = 0;
        break;
    }
    return ret;
}



/* 021C5718  4-arg call, field 0xc and the pool constant 0xffff0000 */
void func_021C5718(u8 *p)
{
    func_021CD64C((void *)(((struct Obj18306 *)p)->fC), 0x5a, 0x47, 0xffff0000);
}





void func_021C572C(u8 *p, u8 *a, u32 v)
{
    func_021CD64C(((struct Obj07752 *)p)->fC, 0x5b, 213, func_021D5440(a), 0xffff0000);
}





void func_021C5750(u8 *p, u8 *a)
{
    func_021CD64C(((struct Obj21098 *)p)->fC, 0x5b, 210, func_021D5440(a), 0xffff0000);
}





void func_021C5774(u8 *p, u8 *a)
{
    func_021CD64C(((struct Obj21099 *)p)->fC, 0x5b, 216, func_021D5440(a), 0xffff0000);
}






void func_021C5798(u8 *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2)
{
    u32 i;
    u8 hi;
    u8 lo;
    int k;
    lo = 0;
    hi = 0;
    for (i = 0; i < n; i++) {
        func_021C604C(p, ptrs[i], vals[i]);
        if (arr[i] > 3) hi++;
        if (arr[i] < 3) lo++;
    }
    if (hi) k = 2;
    else if (lo) k = 3;
    else k = 1;
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x33, (u8)n, (u8)k, *a);
    for (i = 0; i < n; i++) {
        func_021CD63C(((struct Obj00003 *)p)->fC, func_021D5440(ptrs[i]));
    }
}





void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag)
{
    u8 low = 0;
    u8 high = 0;
    u32 i;
    u8 list[3];
    for (i = 0; i < count; i++) {
        if (v[i] > 3) high++;
        if (v[i] < 3) low++;
    }
    if (flag) {
        if (high) {
            u8 n = 0;
            for (i = 0; i < count; i++) {
                if (v[i] > 3) list[n++] = func_021D5440(a[i]);
            }
            switch (high) {
            case 1: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 6, list[0], 0xffff0000); break;
            case 2: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 9, list[0], list[1], 0xffff0000); break;
            case 3: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 12, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
        if (low) {
            u8 n;
            i = 0;
            n = 0;
            for (; i < count; i++) {
                if (v[i] < 3) list[n++] = func_021D5440(a[i]);
            }
            switch (low) {
            case 1: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 15, list[0], 0xffff0000); break;
            case 2: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 18, list[0], list[1], 0xffff0000); break;
            case 3: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 21, list[0], list[1], list[2], 0xffff0000); break;
            }
        }
    } else {
        if (high) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 78, 0xffff0000);
        else if (low) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 79, 0xffff0000);
    }
}






void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (b[i]) {
            if (flag) {
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x180, func_021D5440(a[i]), 0xffff0000);
            } else {
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x51, 0xffff0000);
            }
        }
    }
}




void func_021C5A1C(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x57, func_021D5440(a));
}




void func_021C5A34(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x58, func_021D5440(a));
}





void func_021C5A4C(u8 *p, u8 *a, int b, int c)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021CD64C(((struct Obj13335 *)p)->fC, 0x5b, 0x99, n, b, 0xffff0000);
    } else {
        func_021CD64C(((struct Obj13335 *)p)->fC, 0x5b, 0xae, n, b, 0xffff0000);
    }
}



void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag)
{
    u8 n = func_021D5440(a);
    if (d > 0) {
        int x = func_021D5DC0((s8 *)a, c, d);
        u8 t = x;
        func_021CD4B0(((struct Obj04360 *)p)->fC, 9, n, (u8)c, t);
        func_021CD4B0(((struct Obj04360 *)p)->fC, 0x37, n, (u8)c, t);
        if (flag) {
            if (msg == 0) func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x1b, n, c, x, 0xffff0000);
            else func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x3aa, n, msg, c, x, 0xffff0000);
        }
    } else {
        int x = func_021D5E38((s8 *)a, c, -d);
        u8 t = x;
        func_021CD4B0(((struct Obj04360 *)p)->fC, 10, n, (u8)c, t);
        func_021CD4B0(((struct Obj04360 *)p)->fC, 0x38, n, (u8)c, t);
        func_021CD64C(((struct Obj04360 *)p)->fC, 0x5b, 0x5a, n, c, x, 0xffff0000);
    }
}




void func_021C5B74(u8 *p, u8 *a, int c, int d)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021D5FA4((struct Unk021D5FA4 *)a, (u16)c);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 2, n, (u16)c);
    } else if (c < 0) {
        func_021C604C(p, a, -c);
    }
    if (d) {
        if (func_021C5BD4(p + 0x1AB8, n) != 6) {
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x41, n);
        }
    }
}
