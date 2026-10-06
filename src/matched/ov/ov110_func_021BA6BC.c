/*
 * function: func_021BA6BC
 * address: 0x021BA6BC
 * packet: pkt_ov110_021BA6BC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: write the BB9C0 call in both conditional arms to keep the empty-arm branch and register allocation.
 * prototype: BF7FC's live r0 is read despite its void owner declaration; full BB1C0 target is a byte getter.
 * symbols:
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BD000 0x021BD000 thumb ov110
 *   func_021BD028 0x021BD028 thumb ov110
 *   func_021BCC58 0x021BCC58 thumb ov110
 *   func_021BFC20 0x021BFC20 thumb ov110
 *   func_021BFB7C 0x021BFB7C thumb ov110
 *   func_021BFBA0 0x021BFBA0 thumb ov110
 *   func_021BB8B8 0x021BB8B8 thumb ov110
 *   func_021BAD2C 0x021BAD2C thumb ov110
 *   func_021BB870 0x021BB870 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BB8AC 0x021BB8AC thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj01531.h"
#include "../include/Obj02164.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021BF7FC(u8 *);
extern int func_021BD000(char *p);
extern int func_021BD028(u8 *);
extern void func_021BCC58(u8 *);
extern void func_021BFC20(u8 *, unsigned);
extern void func_021BFB7C(u8 *p);
extern int func_021BFBA0(u8 *);
extern void func_021BB8B8(u8 *);
extern void func_021BAD2C(u8 *, int);
extern void func_021BB870(u8 *);
extern u8 func_021BF6DC(u8 *);
extern void func_021BB9C0(u8 *, int);
extern void func_021BAD68(u8 *, int);
extern int func_021BB8AC(u8 *);
extern int func_021BBB0C(u8 *, int);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *, unsigned);
extern void func_021BB658(u8 *, int);
extern void func_021B9CBC(u8 *);
void func_021BA6BC(void *unused, u8 *p)
{
    u8 *q;
    int a, b, flag;
    u32 enabled;
    q = *(u8 * *)&((struct Obj02164 *)p)->f0;
    enabled = func_021BF7FC(*(u8 * *)&((struct Obj02164 *)p)->f4);
    switch (((struct Obj02164 *)p)->f14) {
    case 0:
        func_021BD000((char *)(*(u8 * *)&((struct Obj01531 *)q)->f64));
        ++((struct Obj02164 *)p)->f14;
        break;
    case 1:
        if (func_021BD028(*(u8 * *)&((struct Obj01531 *)q)->f64)) ++((struct Obj02164 *)p)->f14;
        break;
    case 2:
        func_021BCC58(*(u8 * *)&((struct Obj01531 *)q)->f64);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 3:
        func_021BFC20(*(u8 * *)&((struct Obj01531 *)q)->f5C, 0);
        func_021BFB7C(*(u8 * *)&((struct Obj01531 *)q)->f5C);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 4:
        if (func_021BFBA0(*(u8 * *)&((struct Obj01531 *)q)->f5C)) {
            func_021BB8B8(*(u8 * *)&((struct Obj01531 *)q)->f58);
            ++((struct Obj02164 *)p)->f14;
        }
        break;
    case 5:
        func_021BAD2C(*(u8 * *)&((struct Obj02164 *)p)->f0, 0);
        flag = 0;
        func_021BB870(*(u8 * *)&((struct Obj01531 *)q)->f58);
        if (func_021BF6DC(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) {
            flag = 0;
            func_021BB9C0(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        } else {
            if (enabled) flag = 1;
            func_021BB9C0(*(u8 * *)&((struct Obj01531 *)q)->f58, flag);
        }
        if (func_021BF6DC(*(u8 * *)&((struct Obj02164 *)p)->f4) == 0) func_021BAD68(p, 2);
        else func_021BAD68(p, 4);
        ++((struct Obj02164 *)p)->f14;
        break;
    case 6:
        a = func_021BB8AC(*(u8 * *)&((struct Obj01531 *)q)->f58);
        b = func_021BBB0C(*(u8 * *)&((struct Obj01531 *)q)->f58, enabled != 0);
        if (a && b) {
            func_021BB6A0(*(u8 * *)&((struct Obj01531 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj01531 *)q)->f18));
            func_021BB658(*(u8 * *)&((struct Obj01531 *)q)->f58, 1);
            func_021B9CBC(p);
        }
        break;
    }
}
