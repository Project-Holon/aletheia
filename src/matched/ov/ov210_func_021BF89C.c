/*
 * function: func_021BF89C
 * address: 0x021BF89C
 * packet: pkt_ov210_021BF89C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B93B8 0x021B93B8 thumb
 *   func_021BEDF0 0x021BEDF0 thumb
 *   func_021BCEF0 0x021BCEF0 thumb
 *   func_021BEE38 0x021BEE38 thumb
 */
#include "../include/Obj04619.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021B93B8(void *);
extern void func_021BEDF0(int p, int i, int v);
extern u32 func_021BCEF0(u32 a, u32 b);
extern void func_021BEE38(char *, int, unsigned short, short, unsigned short);

void func_021BF89C(char *p, u8 a, u8 b)
{
    u8 cur = (u8)func_021B93B8(((struct Obj04619 *)p)->f1E0);
    u8 d;
    int y;

    func_021BEDF0((int)p, 9, 0);
    func_021BEDF0((int)p, 0xA, 0);
    func_021BEDF0((int)p, 0xB, 0);
    func_021BEDF0((int)p, 0xC, 0);
    func_021BEDF0((int)p, 0xD, 0);
    func_021BEDF0((int)p, 0xE, 0);
    if (a != 0xFF) {
        a = (u8)func_021BCEF0((u32)p, a);
        d = (u8)(a - cur < 0 ? -(a - cur) : a - cur);
        if (a < cur) {
            if (d <= 8) {
                func_021BEDF0((int)p, 0xB, 1);
                y = (8 - d) * 0x18 + 0xC;
                func_021BEE38(p, 0xB, 0x8C, (s16)y, 1);
                func_021BEDF0((int)p, 0xD, 1);
                func_021BEE38(p, 0xD, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            func_021BEDF0((int)p, 9, 1);
            func_021BEE38(p, 9, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
    if (b != 0xFF) {
        b = (u8)func_021BCEF0((u32)p, b);
        d = (u8)(b - cur < 0 ? -(b - cur) : b - cur);
        if (b < cur) {
            if (d <= 8) {
                func_021BEDF0((int)p, 0xC, 1);
                y = (8 - d) * 0x18 + 0xC;
                func_021BEE38(p, 0xC, 0x8C, (s16)y, 1);
                func_021BEDF0((int)p, 0xE, 1);
                func_021BEE38(p, 0xE, 0x8C, (s16)y, 1);
            }
        } else if (d <= 7) {
            func_021BEDF0((int)p, 0xA, 1);
            func_021BEE38(p, 0xA, 0x8C, (s16)(d * 0x18 + 0xC), 0);
        }
    }
}
