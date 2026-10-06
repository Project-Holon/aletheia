/*
 * function: func_021C3008
 * address: 0x021C3008
 * packet: pkt_ov093_021C3008
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: reassigning value to the transformed result keeps it in its incoming register.
 * symbols:
 *   func_021C312C 0x021C312C thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021C5A4C 0x021C5A4C thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021C77B0 0x021C77B0 thumb ov093
 *   func_021C5A8C 0x021C5A8C thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C785C 0x021C785C thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C7820 0x021C7820 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Kind { K0, K1, K10 = 10 };
extern int func_021C312C(u8 *, u8 *, enum Kind, u8, u16, int);
typedef signed char    s8;
extern int func_021D5D14(s8 *p, int i, int sign);
extern void func_021C5A4C(u8 *p, u8 *a, int b, int c);
extern u32 func_021D6D7C(u8 *p);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern int func_021C77B0(u8 *, u8 *, u32, u32, u32, u32);
extern void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag);
extern u32 func_021CC8D8(void *, int);
extern void func_021C785C(u8 *, u32, u8 *, u32, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C7820(u8 *, u8 *, u32);
int func_021C3008(u8 *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j)
{
    int result;
    u32 lock;
    value = func_021C312C(p, a, kind, f, g, value);
    if (!func_021D5D14((s8 *)a, kind, value)) {
        if (i) {
            func_021C5A4C(p, a, kind, value);
            ((struct Obj00003 *)p)->f78A |= 0x10;
        }
        return 0;
    }
    if (func_021D6D7C(a)) {
        u8 id;
        id = func_021D5440(a);
        if (b != id) {
            if (i) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0xd2, id, 0xffff0000);
            return 0;
        }
    }
    result = 1;
    if (func_021C77B0(p, a, kind, b, value, h)) {
        func_021C5A8C(p, a, kind, value, g, j);
        lock = func_021CC8D8(p + 0x1d74, 8349);
        func_021C785C(p, b, a, kind, value);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 8351);
    } else {
        if (i) {
            lock = func_021CC8D8(p + 0x1d74, 8358);
            func_021C7820(p, a, h);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 8360);
        }
        result = 0;
    }
    return result;
}
