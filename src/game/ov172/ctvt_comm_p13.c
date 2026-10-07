/*
 * file:     ctvt_comm_p13.c
 * unit:     yes
 * function: func_021B9E5C, func_021B9F4C
 * address:  0x021B9E5C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045334  0x02045334  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_021B9AB8  0x021B9AB8  thumb  ov172
 *   d_021C6F6E     0x021C6F6E  data
 *   func_02035D20 0x02035D20 arm
 *   func_02035CB8 0x02035CB8 arm
 */
#include "../../matched/include/Obj04553.h"

struct Bmp;
struct Descriptor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

extern int func_0209C0A4(int a, u16 b);
extern void *func_02045770(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02045334(struct Descriptor *);
extern void func_021B9AB8(int a0, char *obj, void *dev, int a3, u8 s0, u8 s1, u8 s2, u8 s3);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
int func_021B9F4C(int a, int b, int mode);
extern u8 d_021C6F6E[];


void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v)
{
    u32 n;
    void *dev;
    int flag;
    u32 c;
    int h;
    int x;
    u32 c1;

    if (idx < 0)
        return;
    n = func_0209C0A4(idx * 0x7B, v);
    dev = func_020437D4(func_02045770(((struct Obj04553 *)obj)->f2C));
    flag = 0;
    c = ((struct Obj04553 *)obj)->f30;
    if (c < n) {
        flag = 1;
        while (c < n) {
            c1 = c + 1;
            x = c1 * v;
            h = ((tbl[x / 128 / 2] + 0x8000) << 6) / 0x10000;
            if (c < 0xB) {
                u32 t = 0x20 - d_021C6F6E[c - 3];
                if (h < t)
                    h = t;
            }
            if (c > 0x72) {
                u32 t = 0x20 - d_021C6F6E[(u8)(0x7A - c)];
                if (h < t)
                    h = t;
            }
            func_021B9AB8(a0, obj, dev, c, ((struct Obj04553 *)obj)->f31, (u8)c1, (u8)h, a3);
            ((struct Obj04553 *)obj)->f30 += 1;
            ((struct Obj04553 *)obj)->f31 = (u8)h;
            c = ((struct Obj04553 *)obj)->f30;
        }
    }
    if (flag == 1)
        func_02045334((struct Descriptor *)*(int *)&((struct Obj04553 *)obj)->f2C);
}

/*
 * extent: Two bytes of zero alignment padding follow the return.
 */
int func_021B9F4C(int a, int b, int mode)
{
    u32 x, y;
    int dx, dy, d;
    if (mode == 0) func_02035D20(&x, &y);
    else func_02035CB8(&x, &y);
    if (y >= 104) {
        dx = 128 - x;
        dy = 104 - y;
        d = dx * dx + dy * dy;
        if (d > 256 && d < 5184) return 1;
    }
    return 0;
}
