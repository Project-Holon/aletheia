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
 *   func_02035CB8  0x02035CB8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_021BE0C8(void *p);
extern int func_02035C38(void);
extern int func_02035C60(void);
extern void func_021BB54C(void *ctx, u8 *p);
extern void func_021BB9E4(void *ctx, u8 *p);
extern u8 func_021BE054(void *p);
extern u32 func_021BDFE4(void *p);
extern u32 func_021BDFFC(void *p);
extern u8 *func_021B8BB8(void *ctx, u32 base, int *out);
extern void func_021B6E88(u32 a, u8 *e);
extern void func_021B8BFC(void *ctx, u32 base);
extern void *func_0207E008(void);
extern u32 func_0207E100(void);
extern u32 func_021BE078(void *p);
extern void func_020061E4(u32 id);
extern u32 func_02035CB8(u32 *outA, u32 *outB);

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
        *(int *)(p + 0xc) = 0;
    }
    if (func_02035C60() == 1 && *(int *)(p + 8) == 0 && *(int *)p == 5 && y >= 0xa8) {
        if (*(int *)(p + 0x28) == 1) {
            *(int *)(p + 0x28) = (*(int *)(p + 0x24) == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
        }
        func_021BB9E4(ctx, p);
        return;
    }
    if ((u32)(*(int *)p - 4) <= 1 && func_02035C60() == 1 && *(int *)(p + 8) == 0 && *(int *)(p + 0x28) == 3) {
        mode = func_021BE054(ctx);
        cur = func_021BDFE4(ctx);
        s1 = func_021BDFFC(ctx);
        e = func_021B8BB8(ctx, cur, &out1);
        if (out1 == 0) {
            e[0] = x;
            e[1] = y;
            e[2] = x;
            e[3] = y;
            e[6] = p[0x37];
            *(u16 *)(e + 4) = *(u16 *)(p + 0x34);
            if (mode == 1) {
                func_021B6E88(s1, e);
            } else {
                func_021B8BFC(ctx, cur);
            }
        }
    }
    if (func_02035C60() == 1 && *(int *)(p + 8) == 0) {
        if (*(int *)(p + 0x28) == 1) {
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
                *(u16 *)(p + 0x34) = v1;
            } else {
                v2 = *(u16 *)a2;
                if (v2 & 0x8000) {
                    *(u16 *)(p + 0x34) = v2;
                } else {
                    *(u16 *)(p + 0x34) = 0x8000;
                }
            }
            *(volatile u16 *)0x0500021A = *(u16 *)(p + 0x34) & 0x7fff;
            *(int *)(p + 0x28) = (*(int *)(p + 0x24) == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
            func_020061E4(0x66d);
        } else {
            *(int *)(p + 0xc) = 1;
            *(u32 *)(p + 0x2c) = 0xffff;
            *(u32 *)(p + 0x30) = 0xffff;
            func_021BB9E4(ctx, p);
        }
    }
    if ((*(int *)(p + 0x28) == 0 || *(int *)(p + 0x28) == 2) && *(int *)(p + 0xc) == 1) {
        func_02035CB8(&x2, &y2);
        if (*(int *)(p + 0xc) == 1) {
            if (*(u32 *)(p + 0x2c) != 0xffff && *(u32 *)(p + 0x30) != 0xffff) {
                mode = func_021BE054(ctx);
                cur = func_021BDFE4(ctx);
                s2 = func_021BDFFC(ctx);
                e = func_021B8BB8(ctx, cur, &out2);
                if (out2 == 0) {
                    e[0] = *(u32 *)(p + 0x2c);
                    e[1] = *(u32 *)(p + 0x30);
                    e[2] = x2;
                    e[3] = y2;
                    e[6] = p[0x36];
                    if (*(int *)(p + 0x28) == 2) {
                        *(u16 *)(e + 4) = 0;
                        e[6] = 2;
                    } else {
                        *(u16 *)(e + 4) = *(u16 *)(p + 0x34);
                    }
                    if (mode == 1) {
                        func_021B6E88(s2, e);
                    } else {
                        func_021B8BFC(ctx, cur);
                    }
                } else {
                    *(int *)(p + 0xc) = 0;
                }
            }
            *(u32 *)(p + 0x2c) = x2;
            *(u32 *)(p + 0x30) = y2;
        }
    }
}
