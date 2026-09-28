/*
 * function: func_021D5BB8
 * address:  0x021D5BB8
 * packet:   pkt_ov118_021D5BB8
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D56E0  0x021D56E0  thumb  ov118
 *   func_021D55AC  0x021D55AC  thumb  ov118
 *   func_021D5628  0x021D5628  thumb  ov118
 *   func_021D56FC  0x021D56FC  thumb  ov118
 *   func_021D5888  0x021D5888  thumb  ov118
 *   func_021D572C  0x021D572C  thumb  ov118
 *   func_021D5748  0x021D5748  thumb  ov118
 *   func_02015F50  0x02015F50  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015E4C  0x02015E4C  thumb
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015C94  0x02015C94  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_020515CC  0x020515CC  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_021DFA60  0x021DFA60  thumb  ov119
 *   func_021DFB4C  0x021DFB4C  thumb  ov119
 *   func_021D5930  0x021D5930  thumb  ov118
 *   func_021D5990  0x021D5990  thumb  ov118
 *   _dflt          0x0209B750  arm
 *   _dmul          0x0209B2E8  arm
 *   _dfix          0x0209C508  arm
 *   func_02015E04  0x02015E04  thumb
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern int func_021D56E0(int);
extern void func_021D55AC(void *);
extern void func_021D5628(void *);
extern void func_021D56FC(void *);
extern void func_021D5888(u8 *, int);
extern void func_021D572C(u8 *, int);
extern void func_021D5748(u8 *, int);
extern void func_02015F50(u32, u32, u32, s32, u32);
extern void func_02015EA0(u32);
extern void func_02015EB0(u32);
extern void func_02015E4C(u32);
extern void func_02015C30(u32, Vec *);
extern void func_02015C48(u32, Vec *);
extern void func_02015C94(u32, Vec *);
extern void func_02015CAC(u32, void *);
extern int func_020515CC(u32, int, void *, void *);
extern void func_0202208C(int, int, int, int, int, int, int);
extern void func_020307B0(u32);
extern void func_021E71F0(void *, int);
extern void func_021E7208(void *, int);
extern void func_021DFD24(u32);
extern u32 func_021DFB84(u32, int, Vec *, u32);
extern void func_021DFA60(s32);
extern void func_021DFB4C(u32, int, void *);
extern void func_021D5930(void);
extern void func_021D5990(void);
extern void func_021DFC68(u32, void *);
extern void func_021E3230(void *);
extern void func_021D8E84(void *, int);

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define WORK (*(u32 **)(p + 0xc))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))

void func_021D5BB8(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    func_021DFA60(FRAME);
    if (FRAME == func_021D56E0(1)) {
        func_02015F50(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D56E0(2)) {
        func_02015F50(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D56E0(3)) {
        func_021D5628(p);
        func_021D55AC(p);
    }
    if (FRAME == func_021D56E0(4)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0x18);
    }
    if (FRAME == func_021D56E0(4)) {
        func_02015EA0(OBJ(0));
    }
    if (FRAME == func_021D56E0(0x356)) {
        func_020515CC(WORK[0], 10, 0, p);
    }
    if (FRAME == func_021D56E0(0x65)) {
        func_020515CC(WORK[1], 1, 0, p);
    }
    if (FRAME == func_021D56E0(0x9A)) {
        func_020515CC(WORK[2], 2, 0, p);
    }
    if (FRAME == func_021D56E0(0x356)) {
        func_020515CC(WORK[8], 2, 0, p);
    }
    if (FRAME == func_021D56E0(0xE)) {
        func_020515CC(WORK[3], 3, 0, p);
    }
    if (FRAME == func_021D56E0(0x483)) {
        func_020515CC(WORK[7], 3, 0, p);
    }
    if (FRAME == func_021D56E0(0x9A)) {
        func_020515CC(WORK[4], 4, func_021D5930, p);
    }
    if (FRAME == func_021D56E0(0x152)) {
        func_020515CC(WORK[5], 5, 0, p);
    }
    if (FRAME == func_021D56E0(0x2BC)) {
        func_020515CC(WORK[6], 6, func_021D5990, p);
    }
    if (FRAME == func_021D56E0(0x47F)) {
        func_021D5628(p);
        func_021D55AC(p);
    }
    if (FRAME == func_021D56E0(0x10A)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0x14), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x12D)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x19), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x14A)) {
        func_02015EB0(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        func_02015C48(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D56E0(0xF), &v1, HEAP);
        func_02015E04(OBJ(2));
        func_02015C94(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        func_02015CAC(OBJ(2), &v1);
    }
    if (FRAME == func_021D56E0(0x14B)) {
        func_02015EB0(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        func_02015C48(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D56E0(0xF), &v2, HEAP);
        func_02015E04(OBJ(3));
        func_02015C94(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        func_02015CAC(OBJ(3), &v2);
    }
    if (FRAME == func_021D56E0(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        func_021DFB4C(SLOT0, func_021D56E0(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        func_021DFB4C(SLOT1, func_021D56E0(0x1C), &v3);
    }
    if (FRAME == func_021D56E0(0x170)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(2), func_021D56E0(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(3), func_021D56E0(0x2E), &v4, HEAP);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D56E0(0x1B2)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_02015EB0(OBJ(0));
        func_02015F50(OBJ(0), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_02015C48(OBJ(0), &v5);
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D56E0(0x67), &v5, HEAP);
        func_02015C94(OBJ(0), &v5);
        v5.x *= 1.2;
        v5.y *= 1.2;
        func_02015CAC(OBJ(0), &v5);
        func_020307B0(SLOT1);
        SLOT1 = 0;
        func_02015EB0(OBJ(1));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_02015C48(OBJ(1), &v6);
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D56E0(0x67), &v6, HEAP);
        func_02015C94(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        func_02015CAC(OBJ(1), &v6);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D56E0(0x1F8)) {
        func_021DFB4C(SLOT0, func_021D56E0(0x80), (void *)(SLOT0 + 0x28));
        func_021DFB4C(SLOT1, func_021D56E0(0x80), (void *)(SLOT1 + 0x28));
    }
    if (FRAME == func_021D56E0(0x27D)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        func_021DFD24(SLOT0);
        SLOT0 = func_021DFB84(OBJ(0), func_021D56E0(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        func_021DFD24(SLOT1);
        SLOT1 = func_021DFB84(OBJ(1), func_021D56E0(7), &v7, HEAP);
    }
    func_021D56E0(0x48B);
    if (FRAME == func_021D56E0(0x48B + 3)) {
        if (*(u8 *)(p + 0x11EE) == 0) {
            func_021D5888(p, 3);
            func_021D5748(p, 3);
            func_02015F50(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
        } else {
            func_021D5888(p, 3);
            func_02015EA0(OBJ(3));
            func_021D5888(p, 1);
            func_021D5748(p, 3);
            func_02015F50(OBJ(1), 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (FRAME == func_021D56E0(0x48F)) {
        func_02015F50(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D56E0(0x490)) {
        func_02015F50(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (func_021D56E0(0x48E) < FRAME && *(u8 *)(p + 0x11EE) != 0 && *(u32 *)(p + 0x868) != 0
        && *(u32 *)(*(u32 *)(p + 0x868) + 8) == 9) {
        func_02015C30(OBJ(1), &v8);
        func_02015C48(OBJ(3), &v8);
        func_02015EB0(OBJ(3));
        func_02015EA0(OBJ(1));
        **(u32 **)(p + 0x868) = OBJ(3);
    }
    if (FRAME == func_021D56E0(0x4A0)) {
        func_02015E4C(OBJ(3));
    }
    if (FRAME == func_021D56E0(0x28B)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0xA), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x2B5)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x19), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x380)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D56E0(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x3CA)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D56E0(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D56E0(0x4C1)) {
        func_021D572C(p, 0);
        func_021D572C(p, 1);
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D56FC);
    }
    func_021DFC68(SLOT0, p);
    func_021DFC68(SLOT1, p);
    func_021DFC68(*(u32 *)(p + 0x864), p);
    func_021DFC68(*(u32 *)(p + 0x868), p);
}
