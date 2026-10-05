/*
 * function: func_021B8154
 * address: 0x021B8154
 * packet: pkt_ov172_021B8154
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 wD4 lane05: EXACT*. Three source fixes: the 0x21-byte copy b+0x40 -> b+0x80 is a struct copy
 *   (one-member u8[0x21] struct); the slot stores go in offset order (0x74 = 0, 0x78 = 0xff, 0x7c = 0);
 *   in the j loop `hit = 1` comes before the slot store.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203EA54 0x0203EA54 arm
 *   func_0203E758 0x0203E758 arm
 *   func_02082A90 0x02082A90 arm
 *   func_021C2B74 0x021C2B74 arm ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 *   func_021B8454 0x021B8454 thumb ov172
 *   func_021BE1A4 0x021BE1A4 thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021B8628 0x021B8628 thumb ov172
 *   func_021BE0F8 0x021BE0F8 thumb ov172
 *   func_021BE0FC 0x021BE0FC thumb ov172
 *   func_021BE0AC 0x021BE0AC thumb ov172
 *   func_021B7818 0x021B7818 thumb ov172
 *   func_021B785C 0x021B785C thumb ov172
 *   func_021B77B8 0x021B77B8 thumb ov172
 *   func_021B77E8 0x021B77E8 thumb ov172
 *   func_021B8A14 0x021B8A14 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021B8AD4 0x021B8AD4 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020399A8(void);
extern int func_0203D1A4(void *);
extern int func_0203D1B4(void);
extern int func_0203EA54(void);
extern void func_0203E758(int, int, int, int);
extern void func_02082A90(const void *, void *, u32);
extern int func_021C2B74(int, int, int, int, int, int, int, int, int);
extern u32 func_021BDFDC(void *);
extern void func_021B7740(void *, char *, int, int);
extern void func_021B8454(void *, char *);
extern void func_021BE1A4(void *);
extern u32 func_021BE078(void *);
extern void func_021B8628(void *, char *, char *, int);
extern u32 func_021BE0F8(void *);
extern void func_021BE0FC(void *, u32);
extern u32 func_021BE0AC(void *);
extern u32 func_021B7818(void *, u32);
extern u32 func_021B785C(void *, u32);
extern u32 func_021B77B8(void *, u32);
extern u32 func_021B77E8(void *, u32);
extern void func_021B8A14(void *, char *);
extern int func_021B8740(void *, char *, int, int);
extern int func_021B8AD4(void *, char *);
typedef struct { u8 x[0x21]; } S21;
#define W(o) (*(int *)(b + (o)))
#define B(o) (*(u8 *)(b + (o)))
void func_021B8154(void *a, char *b)
{
    int busy;
    u8 i;
    u8 cur;
    u8 j;
    u32 r7;
    u32 s18, s1c, s20, s24;
    int res;
    int hit;
    busy = func_0203D1A4(func_020399A8());
    if (W(0x174) == 2) {
        if (W(0x64) == 0) {
            u32 v = func_021BDFDC(a);
            W(0x64) = 1;
            W(0x68) = 1;
            W(0x6c) = 1;
            W(0x70) = 1;
            W(0x74) = 0;
            B(0x78) = 0xff;
            W(0x7c) = 0;
            *(S21 *)(b + 0x80) = *(S21 *)(b + 0x40);
            B(0x2c) = 1;
            B(4) = 1;
            func_021B7740(a, (char *)v, 0, 0);
        }
    } else {
        cur = func_0203D1B4();
        if (B(4) != cur) {
            func_021B8454(a, b);
            func_021BE1A4(a);
            if (B(4) < cur && busy == 0) {
                W(0x3b8) = 1;
                W(0x3bc) = func_021BE078(a);
            }
            W(0x3b4) = 1;
            B(4) = cur;
            B(0x2c) = cur;
        }
    }
    for (i = 0; i < 4; i++) func_021B8628(a, b, b + 0x64 + i * 0x40, i);
    if (B(4) > 1) {
        if (W(0x184) == 1) {
            if (func_0203EA54() == 1) W(0x184) = 0;
        } else {
            u8 c1 = B(0x182);
            u8 c2 = B(0x183);
            if (c1 == (c1 & c2) && c1 != 0) {
                if (func_021BE0F8(a) == 0) {
                    func_021BE0FC(a, 1);
                    if (func_021BE0AC(a) == 0) {
                        r7 = func_021BDFDC(a);
                        s18 = func_021B7818(a, r7);
                        s1c = func_021B785C(a, r7);
                        func_02082A90((void *)s18, (void *)W(0x18c), s1c);
                        s20 = func_021B77B8(a, r7);
                        s24 = func_021B77E8(a, r7);
                        res = func_021C2B74(W(0x18c), W(0x190), s1c, W(0x188), s20, s24, 0x46, 1, 4);
                        if (res != 0) {
                            func_0203E758(W(0x190), res, B(0x182), 0);
                            B(0x183) = 0;
                            W(0x184) = 1;
                        }
                    }
                    func_021BE0FC(a, 0);
                }
            }
        }
        if (B(0x1ac) != B(0x1ad)) {
            if (W(0x3c0) == 1) func_021B8A14(a, b);
        }
        if (W(0x3c4) == 1) {
            if (func_021B8740(a, b, 4, 0) == 1) W(0x3c4) = 0;
        }
        if (W(0x3cc) == 1) {
            if (func_021B8740(a, b, 5, 0) == 1) W(0x3cc) = 0;
        }
        if (W(0x3b4) == 1) {
            if (func_021B8AD4(a, b) == 1) W(0x3b4) = 0;
        }
    }
    if (busy == 0) {
        if (W(0x3b8) == 1) {
            if (func_021B8740(a, b, 2, W(0x3bc)) == 1) W(0x3b8) = 0;
        }
        if (W(0x3b0) == 1) {
            hit = 0;
            for (j = 0; j < 4; j++) {
                if (*(int *)(b + j * 64 + 0x74) == 1) {
                    if (B(0x3d8) == 0xff) B(0x3d8) = j;
                    hit = 1;
                    *(int *)(b + j * 64 + 0x74) = 0;
                }
            }
            if (hit == 0) B(0x3d8) = 0xff;
            if (B(0x3d8) != B(0x3ae)) W(0x3d4) = 1;
            W(0x3b0) = 0;
        }
        cur = B(0x3d8);
        if (cur != 0xff) {
            if (*(int *)(b + cur * 64 + 0x64) == 0) {
                B(0x3d8) = 0xff;
                W(0x3d4) = 1;
                W(0x3b0) = 0;
            }
        }
        if (W(0x3d4) == 1) {
            if (func_021B8740(a, b, 1, B(0x3d8)) == 1) W(0x3d4) = 0;
        }
    }
}
