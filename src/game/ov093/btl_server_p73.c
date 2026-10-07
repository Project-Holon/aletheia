/*
 * file:     btl_server_p73.c
 * unit:     yes
 * function: func_021C5A8C, func_021C5B74
 * address:  0x021C5A8C
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
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D5FA4  0x021D5FA4  thumb  ov093
 *   func_021C604C  0x021C604C  thumb  ov093
 *   func_021C5BD4  0x021C5BD4  thumb  ov093
 */
#include "../../matched/include/Obj04360.h"
#include "../../matched/include/Obj00003.h"

struct Unk021D5FA4;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern u8 func_021D5DC0(s8 *p, int i, u8 n);
extern u8 func_021D5E38(s8 *p, int i, u8 n);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD64C(void *, u8, ...);
extern void func_021D5FA4(struct Unk021D5FA4 *p, u16 n);
extern void func_021C604C(u8 *p, u8 *a, int n);
extern int func_021C5BD4(void *p, int v);
void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag);
void func_021C5B74(u8 *p, u8 *a, int c, int d);

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
