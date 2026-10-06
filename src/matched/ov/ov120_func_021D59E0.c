/*
 * function: func_021D59E0
 * address: 0x021D59E0
 * packet: pkt_ov120_021D59E0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021D8418 0x021D8418 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D44AC 0x021D44AC thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D5AD4 0x021D5AD4 thumb ov120
 */
#include "../include/Obj01928.h"
#include "../include/Obj22833.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_021D8418(int);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D44AC(int *p);
extern void func_021D79F4(u8 *p, u16 n);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern u32 func_021D6988(u8 *p);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern void func_021D5AD4(u8 *p);
void func_021D59E0(u8 *p)
{
    int state;
    if (func_020279E8(((struct Obj01928 *)p)->f38)) {
        state = func_02027A04(((struct Obj01928 *)p)->f38);
        func_021D8418(*(int *)&((struct Obj01928 *)p)->f38);
        *(int *)&((struct Obj01928 *)p)->f38 = 0;
        switch (state) {
        case 0:
            ((struct Obj22833 *)(*(u8 * *)&((struct Obj01928 *)p)->f48))->f1B0 = 1;
            ((struct Obj01928 *)p)->f14 = 0;
            func_021D4244((int *)p, (int)func_021D44AC, 0x8b5);
            return;
        case 1:
            if (((struct Obj01928 *)p)->f184 == 0)
                func_021D79F4(((struct Obj01928 *)p)->f40, 0x20);
            else
                func_021D79F4(((struct Obj01928 *)p)->f40, 0x2b);
            if (func_020355C4() == 0)
                func_021D69F4(((struct Obj01928 *)p)->f3C, 0, ((struct Obj01928 *)p)->f15C);
            func_021B6558((unsigned char *)func_021D6988(((struct Obj01928 *)p)->f3C), 1, 1);
            func_021D63F4(((struct Obj01928 *)p)->f3C, 0, 0);
            func_021D4244((int *)p, (int)func_021D5AD4, 0x8c3);
            break;
        }
    }
}
