/*
 * function: func_021B8180
 * address:  0x021B8180
 * packet:   pkt_ov091_021B8180
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent's last two bytes (0x021B83D6) are alignment padding.
 * func_021BBAF8 is declared with a third argument: this caller loads
 * `add r2, sp, #0` (the 32-byte buf) before the bl.  The switch value is
 * signed (bgt/blt compare tree).
 *
 * symbols:
 *   func_020409B4  0x020409B4  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_021BB468  0x021BB468  thumb  ov091
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_021BB99C  0x021BB99C  thumb  ov091
 *   func_021BC228  0x021BC228  thumb  ov091
 *   func_021BBAF8  0x021BBAF8  thumb  ov091
 *   func_021F6744  0x021F6744  thumb  ov112
 */
#include "../include/Obj00009.h"
#include "../include/Obj20858.h"
#include "../include/Obj20859.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020409B4(u32 index);
extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern u32 func_0202136C(u16 v);
extern int func_021BB468(int unused, int *p);
extern void func_021BB714(void *a, u32 *s, u32 k);
extern void func_021BB7E8(u8 *a, u32 *s, u32 x);
extern void func_021BB97C(u8 *p, u32 obj);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern int func_021BC228(int unused, int id);
extern void func_021BBAF8(u8 *a, u8 *b, int *items);
extern int func_021F6744(void *p);

#define W(o) (*(u32 *)(p + (o)))

void func_021B8180(u8 *p)
{
    int buf[8];

    func_020409B4(0);
    switch (((struct Obj20858 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34) {
    case 0:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[1] = 3;
            buf[2] = 6;
            buf[0] = 0;
            buf[3] = 0x10;
        } else {
            buf[1] = 1;
            buf[2] = 3;
            buf[3] = 4;
            buf[0] = 0;
            buf[4] = 6;
            buf[5] = 0x10;
            if (func_0202136C(func_02017E1C((void *)W(0x38), 6, 0)) == 1) {
                buf[3] = 5;
            }
        }
        func_021BB97C(p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 1:
    case 22:
    case 23:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        } else {
            buf[0] = 8;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        }
        func_021BB97C(p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 5:
        buf[0] = 2;
        buf[1] = 6;
        buf[2] = 0x10;
        func_021BB97C(p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), func_021BC228((int)p, ((struct Obj20859 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f44));
        func_021BB98C(p, W(0x150));
        break;
    case 18:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[1] = 6;
            buf[0] = 0;
            buf[2] = 0x10;
        } else {
            buf[0] = 7;
            buf[2] = 6;
            buf[1] = 0;
            buf[3] = 0x10;
        }
        func_021BB97C(p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 21:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[0] = 0xb;
            buf[2] = 6;
            buf[3] = 0x10;
            buf[1] = 0;
            func_021BB714(p, (u32 *)W(0x150), 2);
            func_021BB7E8(p, (u32 *)W(0x150), 0xa2);
        } else {
            buf[1] = 6;
            buf[2] = 0x10;
            buf[0] = 0;
            func_021BB97C(p, W(0x150));
            func_021BB99C((int)p, W(0x150), 0, W(0x38));
            func_021BB714(p, (u32 *)W(0x150), 2);
            func_021BB7E8(p, (u32 *)W(0x150), 0x12);
            func_021BB98C(p, W(0x150));
        }
        break;
    case 25:
        if (func_021F6744((void *)W(0x38)) == 1) {
            buf[0] = 0xb;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        } else {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        }
        func_021BB97C(p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    default:
        buf[0] = 0;
        buf[1] = 6;
        buf[2] = 0x10;
        break;
    }
    func_021BBAF8(p, (u8 *)W(0x154), buf);
}
