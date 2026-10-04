/*
 * function: func_021D50C4
 * address: 0x021D50C4
 * packet: pkt_ov120_021D50C4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021D8418 0x021D8418 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D7550 0x021D7550 thumb ov120
 *   func_021D8520 0x021D8520 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4B48 0x021D4B48 thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D6FD8 0x021D6FD8 thumb ov120
 *   func_021D50A0 0x021D50A0 thumb ov120
 */
#include "../include/Obj01151.h"
#include "../include/Obj22830.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_021D8418(int);
extern u32 func_021D6988(u8 *p);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D79F4(u8 *p, u16 n);
extern void func_021D7550(u8 *p);
extern void func_021D8520(char *p, u16 n);
extern void func_021D4244(int, int, int);
extern void func_021D4B48(u8 *p);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D6FD8(u8 *p, u32 flag);
extern void func_021D50A0(u8 *p);
void func_021D50C4(u8 *p)
{
    int state;
    if (func_020279E8(((struct Obj01151 *)p)->f38)) {
        int zero;
        state = func_02027A04(((struct Obj01151 *)p)->f38);
        func_021D8418(*(int *)&((struct Obj01151 *)p)->f38);
        zero = 0;
        *(int *)&((struct Obj01151 *)p)->f38 = zero;
        func_021B6558((unsigned char *)func_021D6988(((struct Obj01151 *)p)->f3C), 1, 1);
        switch (state) {
        case 0:
            func_021D79F4(((struct Obj01151 *)p)->f40, 0xe);
            func_021D7550(((struct Obj01151 *)p)->f3C);
            func_021D8520(((struct Obj01151 *)p)->f40, 0xd);
            ((struct Obj01151 *)p)->f144 = zero;
            ((struct Obj01151 *)p)->f13C = zero;
            ((struct Obj01151 *)p)->f140 = zero;
            ((struct Obj22830 *)(*(u8 * *)&((struct Obj01151 *)p)->f48))->f1B0 = 3;
            func_021D4244((int)p, (int)func_021D4B48, 0x614);
            return;
        case 1:
            func_021D63F4(((struct Obj01151 *)p)->f3C, zero, zero);
            func_021D79F4(((struct Obj01151 *)p)->f40, 0x13);
            if (func_020355C4() == 0)
                func_021D69F4(((struct Obj01151 *)p)->f3C, 0, ((struct Obj01151 *)p)->f164);
            else
                func_021D69F4(((struct Obj01151 *)p)->f3C, 0, 9);
            func_021D6FD8(((struct Obj01151 *)p)->f3C, 1);
            func_021D4244((int)p, (int)func_021D50A0, 0x620);
            break;
        }
    }
}
