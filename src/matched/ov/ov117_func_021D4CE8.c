/*
 * function: func_021D4CE8
 * address:  0x021D4CE8
 * packet:   pkt_ov117_021D4CE8
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4480  0x021D4480  thumb  ov117
 *   func_021D434C  0x021D434C  thumb  ov117
 *   func_021D43C8  0x021D43C8  thumb  ov117
 *   func_021D49C4  0x021D49C4  thumb  ov117
 *   func_021D49F4  0x021D49F4  thumb  ov117
 *   func_021D4A48  0x021D4A48  thumb  ov117
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
 *   func_021DFA98  0x021DFA98  thumb  ov119
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

extern int func_021D4480(int);
extern void func_021D434C(void *);
extern void func_021D43C8(void *);
extern void func_021D49C4(void *);
extern void func_021D49F4(u32, void *);
extern void func_021D4A48(void *, int);
extern void func_02015F50(u32, u32, u32, s32, u32);
extern void func_02015EA0(u32);
extern void func_02015EB0(u32);
extern void func_02015E4C(u32);
extern void func_02015C30(u32, Vec *);
extern void func_02015C48(u32, Vec *);
extern void func_02015C94(u32, Vec *);
extern void func_02015CAC(u32, void *);
extern int func_020515CC(u32, int, int, void *);
extern void func_0202208C(int, int, int, int, int, int, int);
extern void func_020307B0(u32);
extern void func_021E71F0(void *, int);
extern void func_021E7208(void *, int);
extern void func_021DFD24(u32);
extern u32 func_021DFB84(u32, int, Vec *, u32);
extern void func_021DFA98(int);
extern void func_021DFC68(u32, void *);
extern void func_021E3230(void *);
extern void func_021D8E84(void *, int);

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define WORK (*(u32 **)(p + 0xc))

void func_021D4CE8(u8 *p)
{
    Vec v;
    Vec v2;
    Vec v3;
    Vec v4;

    if (FRAME == func_021D4480(1)) {
        func_02015F50(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(2)) {
        func_02015F50(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(3)) {
        func_021D43C8(p);
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(4)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0x18);
    }
    if (FRAME == func_021D4480(4)) {
        func_02015EA0(OBJ(0));
    }
    if (FRAME == func_021D4480(-1)) {
        func_020515CC(WORK[0], 0, 0, p);
    }
    if (FRAME == func_021D4480(0x15E)) {
        func_020515CC(WORK[1], 0, 0, p);
    }
    if (FRAME == func_021D4480(0xC8)) {
        func_020515CC(WORK[2], 1, 0, p);
    }
    if (FRAME == func_021D4480(0x14)) {
        func_020515CC(WORK[3], 2, 0, p);
    }
    if (FRAME == func_021D4480(0x258)) {
        func_020515CC(WORK[4], 2, 0, p);
    }
    if (FRAME == func_021D4480(-1)) {
        func_020515CC(WORK[5], 3, 0, p);
    }
    if (FRAME == func_021D4480(0x256)) {
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(0x82)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0x14), 1, HEAP);
    }
    if (FRAME == func_021D4480(0xB4)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D4480(0x19), 1, HEAP);
    }
    if (FRAME == func_021D4480(0xFA)) {
        func_02015EB0(OBJ(2));
        v.x = -0x32000;
        v.y = -0x1F4000;
        v.z = 0xA000;
        func_02015C48(OBJ(2), &v);
        v.x = -0x32000;
        v.y = 0x12C000;
        v.z = 0xA000;
        func_021DFD24(*(u32 *)(p + 0x85C));
        *(u32 *)(p + 0x85C) = func_021DFB84(OBJ(2), func_021D4480(0x96), &v, HEAP);
        func_02015C94(OBJ(2), &v);
        v.x = v.x * 2;
        v.y = v.y * 2;
        func_02015CAC(OBJ(2), &v);
    }
    if (FRAME == func_021D4480(0xFB)) {
        func_02015EB0(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x12C000;
        v2.z = -0xA000;
        func_02015C48(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = -0x172000;
        v2.z = -0xA000;
        func_021DFD24(*(u32 *)(p + 0x860));
        *(u32 *)(p + 0x860) = func_021DFB84(OBJ(3), func_021D4480(0x96), &v2, HEAP);
        func_02015CAC(OBJ(3), (u8 *)WORK + 0x54);
        func_02015C94(OBJ(3), &v2);
        *(s32 *)((u8 *)WORK + 0x48) = v2.x;
        *(s32 *)((u8 *)WORK + 0x4C) = v2.y;
        *(s32 *)((u8 *)WORK + 0x50) = v2.z;
        func_02015C94(OBJ(3), &v3);
    }
    if (FRAME == func_021D4480(0xFC)) {
    }
    if (FRAME == func_021D4480(0x267)) {
        if (*(u8 *)(p + 0x11EE) == 0) {
            func_021D49F4(OBJ(3), p);
        } else {
            func_021D49F4(OBJ(3), p);
            func_02015EA0(OBJ(3));
            func_021D49F4(OBJ(1), p);
        }
        func_021D4A48(p, 3);
    }
    if (FRAME == func_021D4480(0x268)) {
        func_02015F50(OBJ(3), 8, 8, 0, 0x7FFF);
        func_02015F50(OBJ(1), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x269)) {
        func_02015F50(OBJ(3), 0, 0, 0, 0x7FFF);
        func_02015F50(OBJ(1), 0, 0, 0, 0x7FFF);
    }
    if (func_021D4480(0x267) < FRAME && *(u8 *)(p + 0x11EE) != 0 && *(u32 *)(p + 0x868) != 0
        && *(u32 *)(*(u32 *)(p + 0x868) + 8) == 9) {
        func_02015C30(OBJ(1), &v4);
        func_02015C48(OBJ(3), &v4);
        func_02015EB0(OBJ(3));
        func_02015EA0(OBJ(1));
        **(u32 **)(p + 0x868) = OBJ(3);
    }
    if (FRAME == func_021D4480(0x279)) {
        func_02015E4C(OBJ(3));
    }
    func_021DFA98(FRAME);
    if (FRAME == func_021D4480(0x199)) {
        func_0202208C(0, 0, 0, 0x7FFF, func_021D4480(0xA), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x1A4)) {
        func_0202208C(0, 1, 1, 0x7FFF, func_021D4480(0x19), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x293)) {
        func_020307B0(*(u32 *)(p + 0x85C));
        *(u32 *)(p + 0x85C) = 0;
        func_020307B0(*(u32 *)(p + 0x860));
        *(u32 *)(p + 0x860) = 0;
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D49C4);
    }
    func_021DFC68(*(u32 *)(p + 0x85C), p);
    func_021DFC68(*(u32 *)(p + 0x860), p);
    func_021DFC68(*(u32 *)(p + 0x864), p);
    func_021DFC68(*(u32 *)(p + 0x868), p);
}
