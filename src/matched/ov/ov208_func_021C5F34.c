/*
 * function: ov208_func_021C5F34
 * address:  0x021C5F34
 * packet:   pkt_ov208_021C5F34
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The unit index for the state 7 camera call is an enum-typed local set by a
 * ternary: an int ternary is canonicalised to `movs #1; beq; movs #0`, an int
 * if/else keeps the polarity but swaps r0/r1; the enum keeps both.
 *
 * symbols:
 *   func_021BC3A4  0x021BC3A4  thumb
 *   func_021BC3B4  0x021BC3B4  thumb
 *   func_021BC3B8  0x021BC3B8  thumb
 *   func_021BC3BC  0x021BC3BC  thumb
 *   func_021C5200  0x021C5200  thumb
 *   func_021BDC48  0x021BDC48  thumb
 *   func_021BDBAC  0x021BDBAC  thumb
 *   func_021C80AC  0x021C80AC  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_021BDAAC  0x021BDAAC  thumb
 *   func_021BDBEC  0x021BDBEC  thumb
 *   func_021BE82C  0x021BE82C  thumb
 *   func_021BDBA0  0x021BDBA0  thumb
 *   func_021C50F8  0x021C50F8  thumb
 *   func_02012BF8  0x02012BF8  thumb
 *   func_021BDC14  0x021BDC14  thumb
 *   func_021C7534  0x021C7534  thumb
 *   func_021C4F30  0x021C4F30  thumb
 *   func_021C4EAC  0x021C4EAC  thumb
 *   ov208_func_021C6A10  0x021C6A10  thumb  ov208
 *   func_021C6AFC  0x021C6AFC  thumb
 *   func_021C68D4  0x021C68D4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

extern int func_021BC3A4(int *p);
extern int func_021BC3B4(int *p);
extern int func_021BC3B8(char *p);
extern u16  func_021BC3BC(char *p);
extern void func_021C5200(void *p);
extern void func_021BDC48(void *s, u32 on);
extern void func_021BDBAC(void *s, int v);
extern void func_021C80AC(void *u, int k, Vec *v);
extern void func_02015C48(u32 obj, Vec *v);
extern void func_021BDAAC(void *s, u32 mode, u32 kind, u32 flag);
extern void func_021BDBEC(void *s, int v);
extern void func_021BE82C(void *icon, int kind);
extern void func_021BDBA0(void *s);
extern void func_021C50F8(u32 obj, Vec *out);
extern int func_02012BF8(int a0, int a1);
extern void func_021BDC14(char *p, int b);
extern void func_021C7534(void *a0, u8 *p, void *ctx);
extern void func_021C4F30(void *a0, u8 *p, void *ctx);
extern void func_021C4EAC(void *a0, u8 *p, void *ctx);
extern void ov208_func_021C6A10(void *a0, u8 *p, void *ctx);
extern void func_021C6AFC(void *a0, u8 *p, void *ctx);
extern void func_021C68D4(void *a0, u8 *p, void *ctx);

#define FALSE 0
#define TRUE 1
typedef enum { SIDE_0 = 0, SIDE_1 = 1 } Side;

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

void ov208_func_021C5F34(void *a0, u8 *p, void *ctx, int ev)
{
    void *scene;
    void *icon;
    int flag;
    Side idx;
    Vec v;
    Vec v2;

    scene = (void *)func_021BC3B4(ctx);
    icon = (void *)func_021BC3B8(ctx);
    flag = 0;
    switch (W(0x6b8)) {
    case 0:
        switch (ev) {
        case 1:
            if (W(0x6c4) == 0) {
                func_021C5200(p + 0x94);
                func_021C5200(p + 0xd8);
                W(0x6c4) = 1;
            }
            break;
        case 2:
            W(0x6cc) = 0;
            W(0x6d0) = 0;
            if (H(0x548) >= 2) {
                W(0x6c8) = 1;
                func_021C7534(a0, p, ctx);
            }
            break;
        }
        break;
    case 1:
        if (ev == 0 && W(0x694) == 5)
            func_021BDC48(scene, 1);
        break;
    case 2:
        if (ev == 3)
            func_021BDBAC(scene, 0);
        break;
    case 3:
        if (ev == 4) {
            flag = 1;
            if (H(0x548) >= 2) {
                if (W(0xc) != 0) {
                    func_021C80AC(p + 0xc, 1, &v);
                    func_02015C48(W(0xc), &v);
                }
                if (W(0x50) != 0) {
                    func_021C80AC(p + 0x50, 1, &v);
                    func_02015C48(W(0x50), &v);
                }
                if (W(0x94) != 0) {
                    func_021C80AC(p + 0x94, 2, &v);
                    func_02015C48(W(0x94), &v);
                }
                if (W(0xd8) != 0) {
                    func_021C80AC(p + 0xd8, 2, &v);
                    func_02015C48(W(0xd8), &v);
                }
            }
            func_021BDAAC(scene, 2, 3, func_021BC3BC(ctx) > 1);
            if (H(0x548) >= 3)
                func_021BDBEC(scene, 1);
            else
                func_021BDBEC(scene, 0);
            func_021BE82C(icon, 4);
        }
        break;
    case 4:
        switch (ev) {
        case 5:
            if (W(0x6bc) == 0) {
                W(0x6bc) = 1;
                W(0x6c0) = 0;
            }
            break;
        case 6:
            W(0x6cc) = 0;
            W(0x6d0) = 0;
            break;
        }
        break;
    case 5:
        if (ev == 4 && W(0x6d8) != 0) {
            W(0x6dc) = 1;
            if (W(0x6e0) != 0) {
                W(0x6d8) = 0;
                func_021BDBA0(scene);
            }
        }
        break;
    case 6:
        if (ev == 7)
            func_021BDBAC(scene, 0);
        break;
    case 7:
        if (ev == 0) {
            flag = 1;
            if (H(0x548) >= 2) {
                if (W(0xc) != 0) {
                    func_021C80AC(p + 0xc, 0, &v2);
                    func_02015C48(W(0xc), &v2);
                }
                if (W(0x50) != 0) {
                    func_021C80AC(p + 0x50, 0, &v2);
                    func_02015C48(W(0x50), &v2);
                }
                idx = W(0x124) != 0 ? SIDE_0 : SIDE_1;
                func_021C50F8(*(u32 *)(p + idx * 0x44 + 0xc), &v2);
                if (W(0x94) != 0) {
                    func_021C80AC(p + 0x94, 2, &v2);
                    func_02015C48(W(0x94), &v2);
                }
                if (W(0xd8) != 0) {
                    func_021C80AC(p + 0xd8, 2, &v2);
                    func_02015C48(W(0xd8), &v2);
                }
            }
            func_021BDAAC(scene, 0, 3, func_021BC3BC(ctx) > 1);
            func_021BDC14(scene, func_02012BF8(func_021BC3A4(ctx), 0x14));
            func_021BE82C(icon, 3);
            if (H(0x548) >= 2) {
                W(0x6c8) = 1;
                func_021C7534(a0, p, ctx);
            }
        }
        break;
    }
    W(0x6b8) = ev;
    if (flag) {
        func_021C4F30(a0, p, ctx);
        func_021C4EAC(a0, p, ctx);
        ov208_func_021C6A10(a0, p, ctx);
        func_021C6AFC(a0, p, ctx);
        func_021C68D4(a0, p, ctx);
        W(0x694) = 5;
        func_021BDC48(scene, 1);
    }
}
