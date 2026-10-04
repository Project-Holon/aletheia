/*
 * function: func_021BA83C
 * address: 0x021BA83C
 * packet: pkt_ov181_021BA83C
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display register stores at 04000050 and 04000052.
 * symbols:
 *   func_021B9A80 0x021B9A80 thumb ov181
 *   func_0207D63C 0x0207D63C arm
 *   func_020434DC 0x020434DC arm
 *   func_0207D534 0x0207D534 arm
 *   func_02051E74 0x02051E74 arm
 *   func_02040860 0x02040860 arm
 */
#include "../include/Obj00682.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
struct Mtx22 { int m[4]; };
extern void func_021B9A80(void *, int);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02051E74(struct Mtx22 *, unsigned, const void *, const void *, u8);
extern void func_02040860(unsigned, unsigned, unsigned, unsigned);
int func_021BA83C(char *p)
{
    struct Mtx22 matrix;
    int v;
    unsigned scale;
    switch (((struct Obj00682 *)p)->f2CE) {
    case 0:
        func_021B9A80(p, 1);
        func_0207D63C(0x04000050, 8, 0x20, 0, 16);
        func_020434DC(8, 1);
        func_0207D534((void *)0x0400006c, 0);
        func_0207D534((void *)0x0400106c, 0);
        *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
        ++((struct Obj00682 *)p)->f2CE;
        break;
    case 1:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000052 = 16;
            func_02051E74(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            *(u16 *)&((struct Obj00682 *)p)->f2DA = 0xa6;
            ++((struct Obj00682 *)p)->f2CE;
        } else {
            *(volatile u16 *)0x04000052 = v | ((16 - v) << 8);
            scale = 8 - ((struct Obj00682 *)p)->f2D0 / 2;
            func_02051E74(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    case 2:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2DA -= 4;
        else --((struct Obj00682 *)p)->f2DA;
        if (((struct Obj00682 *)p)->f2DA <= 0) {
            ((struct Obj00682 *)p)->f2DA = 0;
            ++((struct Obj00682 *)p)->f2CE;
        }
        break;
    case 3:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000050 = 0;
            func_020434DC(8, 0);
            func_02051E74(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
            func_021B9A80(p, 0);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            ((struct Obj00682 *)p)->f2CE = 0;
            return 0;
        } else {
            *(volatile u16 *)0x04000052 = (16 - v) | (v << 8);
            scale = ((struct Obj00682 *)p)->f2D0 / 2 + 1;
            func_02051E74(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    }
    return 1;
}
