/*
 * function: func_021F66B4
 * address: 0x021F66B4
 * packet: pkt_ov097_021F66B4
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: byte-pointer object base keeps field addresses inline instead
 * of the integer-base spelling's extra loop-invariant address register.
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021F681C 0x021F681C thumb ov097
 *   func_021F7308 0x021F7308 thumb ov097
 *   func_021F67F0 0x021F67F0 thumb ov097
 */
#include "../include/Obj00111.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct WinMgr;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern void func_020061E4(u32);
extern int func_021F681C(u8 *, int, int);
extern void func_021F7308(int a, unsigned b, int c);
extern int func_021F67F0(u8 *, int);
int func_021F66B4(u8 *p)
{
    u32 i;
    switch (((struct Obj00111 *)p)->f110) {
    case 0:
        if (func_0201C6B4(((struct Obj00111 *)p)->f1C) == 0) break;
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            for (i = 0; i < 3; i++) {
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 3, -1, 0, 16);
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 9, -1, 0, 16);
            }
        } else {
            for (i = 0; i < 3; i++) {
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i, 1, 0, 16);
                func_0202CD64(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, i + 6, 1, 0, 16);
            }
        }
        func_020061E4(0x642);
        (((struct Obj00111 *)p)->f110)++;
    case 1:
        if (*(int *)(*(int *)&((struct Obj00111 *)p)->f0 + 8) == 0) {
            if (func_0202CE40(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 3) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                func_020061E4(0x57a);
                return func_021F681C(p, 0x80, 4);
            }
            func_021F7308((int)p, 3, -8);
        } else {
            if (func_0202CE40(*(struct WinMgr * *)&((struct Obj00111 *)p)->f8, 0) == 0) {
                (((struct Obj00111 *)p)->f110)++;
                func_020061E4(0x57a);
                return func_021F681C(p, 0x80, 4);
            }
            func_021F7308((int)p, 0, 8);
        }
        break;
    case 2:
        return func_021F67F0(p, 1);
    }
    return 4;
}
