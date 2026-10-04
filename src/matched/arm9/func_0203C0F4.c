/*
 * function: func_0203C0F4
 * address:  0x0203C0F4
 * packet:   pkt_0203C0F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203C0DC  0x0203C0DC  arm
 *   func_0203C0B4  0x0203C0B4  arm
 *   func_0203C060  0x0203C060  arm
 *   func_0203C064  0x0203C064  arm
 *   func_0203C05C  0x0203C05C  arm
 */
#include "../include/Obj11369.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

extern int  g_021469DC;
extern void *func_0203D788(void);
extern void func_0203AD80(int a0, int a1, int a2, int a3);
extern void func_0203C0DC(u8 *p, u32 v);
extern void func_0203C0B4(void);
extern void func_0203C060(void);
extern void func_0203C064(void);
extern void func_0203C05C(void);

void func_0203C0F4(void *p)
{
    u8 *net = func_0203D788();
    u32 *obj = *(u32 * *)&((struct Obj11369 *)net)->f340;
    s32 res = ((s32 (*)(int))obj[3])(0);

    if (res == 1000) {
        func_0203AD80(g_021469DC, (int)func_0203C0B4, 0, 1403);
        return;
    }

    obj = *(u32 * *)&((struct Obj11369 *)net)->f340;
    if (((s32 (*)(void))obj[0xac / 4])() != 0) {
        func_0203AD80(g_021469DC, (int)func_0203C0B4, 0, 1407);
        return;
    }

    if (res == 1007) {
        return;
    }

    if (res == 1001) {
        func_0203AD80(g_021469DC, (int)func_0203C060, 0, 1413);
        return;
    }

    if (res == 1002) {
        func_0203AD80(g_021469DC, (int)func_0203C064, 0, 1416);
        return;
    }

    if (res >= 10) {
        func_0203AD80(g_021469DC, (int)func_0203C064, 0, 1420);
        return;
    }

    if (res >= 0) {
        return;
    }

    func_0203C0DC(p, res);
    func_0203AD80(g_021469DC, (int)func_0203C05C, 0, 1424);
}
