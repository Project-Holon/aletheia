/*
 * file:     btl_server_p65.c
 * unit:     yes
 * function: func_021C4C40, func_021C4C50
 * address:  0x021C4C40
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
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C43F0  0x021C43F0  thumb  ov093
 *   func_021C4CEC  0x021C4CEC  thumb  ov093
 *   func_021C4CFC  0x021C4CFC  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 *   func_021C4D0C  0x021C4D0C  thumb  ov093
 */
#include "../../matched/include/Obj05192.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021CD64C(void *w, u8 id, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C43F0(u8 *p, u8 *a);
extern void func_021C4CEC(u8 *a);
extern u8 *func_021C4CFC(u8 *a);
extern int func_021D5B7C(void *m);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern u8 *func_021C4D0C(u8 *a);
void CallbackForJpeg(int result, void *arg);
void func_021C4C50(u8 *p, int k);


void CallbackForJpeg(int result, void *arg)
{
    func_021C4C50(arg, result);
}


void func_021C4C50(u8 *p, int k)
{
    int r = -1;
    u8 *q;
    switch (k) {
    case 0: break;
    case 1: r = 0x74; break;
    case 2: r = 0x76; break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: r = 0xb3; break;
    case 7: r = 0xb5; break;
    }
    if (r >= 0) {
        func_021CD64C(((struct Obj05192 *)p)->fC, 0x5a, r, 0xffff0000);
    }
    func_021CD4B0(((struct Obj05192 *)p)->fC, 0x24, (u8)k);
    if (k == 7) {
        func_021C43F0(p, *(u8 * *)&((struct Obj05192 *)p)->f868);
        func_021C4CEC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        q = func_021C4CFC(*(u8 * *)&((struct Obj05192 *)p)->f868);
        while (q) {
            if (func_021D5B7C(q)) {
                func_021C195C(p, q, 0);
            }
            q = func_021C4D0C(*(u8 * *)&((struct Obj05192 *)p)->f868);
        }
    }
}
