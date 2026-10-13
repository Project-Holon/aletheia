/*
 * function: func_021BB288
 * address:  0x021BB288
 * packet:   pkt_ov172_021BB288
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035D20  0x02035D20  arm
 *   func_021BE0C8  0x021BE0C8  thumb  ov172
 *   func_02035C38  0x02035C38  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021BB54C  0x021BB54C  thumb  ov172
 *   func_021BB9E4  0x021BB9E4  thumb  ov172
 *   func_021BE054  0x021BE054  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021BDFFC  0x021BDFFC  thumb  ov172
 *   func_021B8BB8  0x021B8BB8  thumb  ov172
 *   func_021B6E88  0x021B6E88  thumb  ov172
 *   func_021B8BFC  0x021B8BFC  thumb  ov172
 *   func_0207E008  0x0207E008  arm
 *   func_0207E100  0x0207E100  arm
 *   func_021BE078  0x021BE078  thumb  ov172
 *   func_020061E4  0x020061E4  thumb
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 */
#include "../include/Obj00024.h"
#include "../include/Obj01757.h"
#include "../include/Obj24101.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_021BE0C8(void *p);
extern int func_02035C38(void);
extern int func_02035C60(void);
extern void func_021BB54C(void *ctx, u8 *p);
extern void func_021BB9E4(void *a0, char *a1);
extern u8 func_021BE054(void *p);
extern u32 func_021BDFE4(void *p);
extern u32 func_021BDFFC(void *p);
extern int func_021B8BB8(int a, unsigned char *p, int *out);
extern void func_021B6E88(char *p, void *q);
extern void func_021B8BFC(int unused, u8 *p);
extern void *func_0207E008(void);
extern u32 func_0207E100(void);
extern u32 func_021BE078(void *p);
extern void func_020061E4(u32 id);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);

void func_021BB288(void *ctx, u8 *p)
{
    u32 x;
    u32 y;
    int out1;
    u32 x2;
    u32 y2;
    int out2;
    u32 s2;
    u32 s1;
    u32 base;
    u16 *pb;
    u32 off;
    u32 a2;
    u32 v1;
    u32 v2;
    u8 mode;
    u32 base2;
    u8 *e;
    u32 cur;

    func_02035D20(&x, &y);
    if (func_021BE0C8(ctx) == 1) {
        return;
    }
    if (func_02035C38() == 0) {
        ((struct Obj00024 *)p)->fC = 0;
    }
    if (func_02035C60() == 1 && ((struct Obj00024 *)p)->f8 == 0 && ((struct Obj00024 *)p)->f0 == 5 && y >= 0xa8) {
        if (((struct Obj00024 *)p)->f28 == 1) {
            ((struct Obj00024 *)p)->f28 = (((struct Obj00024 *)p)->f24 == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
        }
        func_021BB9E4(ctx, (char *)p);
        return;
    }
    if ((u32)(((struct Obj00024 *)p)->f0 - 4) <= 1 && func_02035C60() == 1 && ((struct Obj00024 *)p)->f8 == 0 && ((struct Obj00024 *)p)->f28 == 3) {
        mode = func_021BE054(ctx);
        cur = func_021BDFE4(ctx);
        s1 = func_021BDFFC(ctx);
        e = (u8 *)func_021B8BB8((int)ctx, (unsigned char *)cur, &out1);
        if (out1 == 0) {
            e[0] = x;
            e[1] = y;
            e[2] = x;
            e[3] = y;
            e[6] = p[0x37];
            ((struct Obj01757 *)e)->f4 = ((struct Obj00024 *)p)->f34;
            if (mode == 1) {
                func_021B6E88((char *)s1, e);
            } else {
                func_021B8BFC((int)ctx, (u8 *)cur);
            }
        }
    }
    if (func_02035C60() == 1 && ((struct Obj00024 *)p)->f8 == 0) {
        if (((struct Obj00024 *)p)->f28 == 1) {
            pb = (u16 *)func_0207E008();
            off = y << 9;
            base = (x << 1) + (u32)pb;
            func_0207E100();
            if (func_021BE078(ctx) == 1) {
                a2 = ((y >> 1) << 9) + ((x & ~1) + func_0207E100());
            } else {
                a2 = (y << 9) + ((x << 1) + func_0207E100());
            }
            v1 = *(u16 *)(off + base);
            if (v1 & 0x8000) {
                ((struct Obj00024 *)p)->f34 = v1;
            } else {
                v2 = ((struct Obj24101 *)a2)->f0;
                if (v2 & 0x8000) {
                    ((struct Obj00024 *)p)->f34 = v2;
                } else {
                    ((struct Obj00024 *)p)->f34 = 0x8000;
                }
            }
            *(volatile u16 *)0x0500021A = ((struct Obj00024 *)p)->f34 & 0x7fff;
            ((struct Obj00024 *)p)->f28 = (((struct Obj00024 *)p)->f24 == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
            func_020061E4(0x66d);
        } else {
            ((struct Obj00024 *)p)->fC = 1;
            ((struct Obj00024 *)p)->f2C = 0xffff;
            ((struct Obj00024 *)p)->f30 = 0xffff;
            func_021BB9E4(ctx, (char *)p);
        }
    }
    if ((((struct Obj00024 *)p)->f28 == 0 || ((struct Obj00024 *)p)->f28 == 2) && ((struct Obj00024 *)p)->fC == 1) {
        TOUCHPANEL_GetPointCont(&x2, &y2);
        if (((struct Obj00024 *)p)->fC == 1) {
            if (((struct Obj00024 *)p)->f2C != 0xffff && ((struct Obj00024 *)p)->f30 != 0xffff) {
                mode = func_021BE054(ctx);
                cur = func_021BDFE4(ctx);
                s2 = func_021BDFFC(ctx);
                e = (u8 *)func_021B8BB8((int)ctx, (unsigned char *)cur, &out2);
                if (out2 == 0) {
                    e[0] = ((struct Obj00024 *)p)->f2C;
                    e[1] = ((struct Obj00024 *)p)->f30;
                    e[2] = x2;
                    e[3] = y2;
                    e[6] = p[0x36];
                    if (((struct Obj00024 *)p)->f28 == 2) {
                        ((struct Obj01757 *)e)->f4 = 0;
                        e[6] = 2;
                    } else {
                        ((struct Obj01757 *)e)->f4 = ((struct Obj00024 *)p)->f34;
                    }
                    if (mode == 1) {
                        func_021B6E88((char *)s2, e);
                    } else {
                        func_021B8BFC((int)ctx, (u8 *)cur);
                    }
                } else {
                    ((struct Obj00024 *)p)->fC = 0;
                }
            }
            ((struct Obj00024 *)p)->f2C = x2;
            ((struct Obj00024 *)p)->f30 = y2;
        }
    }
}
