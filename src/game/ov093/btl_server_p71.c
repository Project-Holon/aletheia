/*
 * file:     btl_server_p71.c
 * unit:     yes
 * function: func_021C5774, func_021C5798, func_021C5840, func_021C59C4
 * address:  0x021C5774
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
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021C604C  0x021C604C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021CD63C  0x021CD63C  thumb  ov093
 */
#include "../../matched/include/Obj21099.h"
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD63C(void *p, int v);
extern void func_021C604C(u8 *p, u8 *a, int n);
void func_021C5774(u8 *p, u8 *a);
void func_021C5798(u8 *p, u16 *a, u32 n, int *arr, u8 **ptrs, u16 *vals, u8 *unused1, int unused2);
void func_021C5840(u8 *p, u32 count, int *v, u8 **a, int flag);
void func_021C59C4(u8 *p, u32 n, u8 **a, u8 *b, int flag);

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
