/*
 * function: func_021BA2D8
 * address: 0x021BA2D8
 * packet: pkt_ov110_021BA2D8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021BF714 0x021BF714 thumb ov110
 *   func_021BC72C 0x021BC72C thumb ov110
 *   func_021BF7E0 0x021BF7E0 thumb ov110
 *   func_021BCC58 0x021BCC58 thumb ov110
 *   func_021BC6EC 0x021BC6EC thumb ov110
 *   func_021BC724 0x021BC724 thumb ov110
 *   func_021BB76C 0x021BB76C thumb ov110
 *   func_021BBEF4 0x021BBEF4 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BB958 0x021BB958 thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BB784 0x021BB784 thumb ov110
 *   func_021BBF54 0x021BBF54 thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj01921.h"
#include "../include/Obj03748.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021BC704(u8 *p, u32 flag);
extern u16 func_021BF714(u8 *);
extern void func_021BC72C(u8 *, int);
extern void func_021BF7E0(u8 *);
extern void func_021BCC58(u8 *);
extern void func_021BC6EC(void *p);
extern void func_021BC724(u8 *);
extern void func_021BB76C(u8 *);
extern void func_021BBEF4(u8 *p, u8 value);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB958(u8 *);
extern void func_021BAD68(u8 *, int);
extern int func_021BB784(u8 *);
extern int func_021BBF54(u8 *);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *, unsigned int);
extern void func_021BB658(u8 *, int);
extern void func_021B9CBC(u8 *);
void func_021BA2D8(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj03748 *)p)->f0;
    int a, b;
    switch (((struct Obj03748 *)p)->f14) {
    case 0:
        func_021BC704(*(u8 * *)&((struct Obj01921 *)q)->f54, 1);
        func_021BC72C(*(u8 * *)&((struct Obj01921 *)q)->f54, func_021BF714(*(u8 * *)&((struct Obj03748 *)p)->f4));
        ++((struct Obj03748 *)p)->f14;
        break;
    case 1:
        func_021BF7E0(*(u8 * *)&((struct Obj03748 *)p)->f4);
        func_021BCC58(*(u8 * *)&((struct Obj01921 *)q)->f64);
        func_021BC6EC(*(u8 * *)&((struct Obj01921 *)q)->f54);
        func_021BC724(*(u8 * *)&((struct Obj01921 *)q)->f54);
        func_021BB76C(*(u8 * *)&((struct Obj01921 *)q)->f58);
        func_021BBEF4(*(u8 * *)&((struct Obj01921 *)q)->f54, 0);
        if (func_021BF6DC(*(u8 * *)&((struct Obj03748 *)p)->f4) == 1) func_021BB958(*(u8 * *)&((struct Obj01921 *)q)->f58);
        if (func_021BF6DC(*(u8 * *)&((struct Obj03748 *)p)->f4) == 0) func_021BAD68(p, 2);
        else func_021BAD68(p, 4);
        ++((struct Obj03748 *)p)->f14;
        break;
    case 2:
        a = func_021BB784(*(u8 * *)&((struct Obj01921 *)q)->f58);
        b = func_021BBF54(*(u8 * *)&((struct Obj01921 *)q)->f54);
        if (a && b) {
            func_021BB6A0(*(u8 * *)&((struct Obj01921 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj01921 *)q)->f18));
            func_021BB658(*(u8 * *)&((struct Obj01921 *)q)->f58, 1);
            func_021B9CBC(p);
        }
        break;
    }
}
