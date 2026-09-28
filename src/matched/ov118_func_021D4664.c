/*
 * function: func_021D4664
 * address:  0x021D4664
 * packet:   pkt_ov118_021D4664
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4240  0x021D4240  thumb  ov118
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D4480  0x021D4480  thumb  ov118
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021E64B8  0x021E64B8  thumb  ov119
 *   func_021E4888  0x021E4888  thumb  ov119
 *   func_021E2680  0x021E2680  thumb  ov119
 *   func_021D4484  0x021D4484  thumb  ov118
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02015C30  0x02015C30  thumb
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFBB4  0x021DFBB4  thumb  ov119
 *   func_021E36C8  0x021E36C8  thumb  ov119
 *   func_02015E04  0x02015E04  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D48F0  0x021D48F0  thumb  ov118
 *   d_021D7D00     0x021D7D00  data
 *   d_021D7DD8     0x021D7DD8  data
 *   d_021D86A0     0x021D86A0  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D4240(s8 *fade);
extern void func_021DFC68(u32, void *);
extern int func_021D4480(int);
extern void func_021E71F0(void *p, int a);
extern void func_021E7208(void *p, int a);
extern void func_021E64B8(void *p);
extern void func_021E4888(void *p);
extern void func_021E2680(void *p);
extern void func_021D4484(void *p, int a);
extern int func_021D8AA8(void *);
extern u32 func_021D8FA4(void *, int);
extern u32 func_02017E1C(u32, u32, u32);
extern void func_02006CAC(void *buf);
extern u32 func_02006984(u32, u32, u32, u32, u32, u32, u32, void *);
extern void func_020307B0(u32);
extern void func_02015C30(u32, Vec *);
extern void func_021DFD24(u32);
extern u32 func_021DFBB4(u32, u32, Vec *, const void *, u16);
extern void func_021E36C8(void *p, int a, int b, u32 mon, int c);
extern void func_02015E04(u32);
extern void func_02015EA0(u32);
extern void func_021D8E84(void *p, int next);
extern void func_021D48F0(u8 *p);
extern const u8 d_021D7D00[];
extern const u8 d_021D7DD8[];
extern u8 d_021D86A0[];

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))

void func_021D4664(u8 *p)
{
    u32 mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    func_021D4240(*(s8 **)(p + 0x818));
    func_021DFC68(*(u32 *)(p + 0x85C), p);
    func_021DFC68(*(u32 *)(p + 0x860), p);
    if (FRAME > func_021D4480(0x2A)) {
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0);
        func_021E64B8(p);
        func_021E4888(p);
        func_021E2680(p);
        func_021D4484(p, 0);
        mon = func_021D8FA4(p, func_021D8AA8(p));
        func_02017E1C(mon, 7, 0);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            a = func_02017E1C(mon, 0xAB, 0);
            b = func_02017E1C(mon, 0x6F, 0);
            func_02006CAC(&buf);
            func_02006984(a, b, 0x40, 0, 0, 0, 0, &buf);
        }
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        if (*(u8 *)(p + 0x11ED) == 0) {
            func_02015C30(OBJ(0), &v1);
            func_021DFD24(SLOT0);
            if (*(u8 *)(p + 0x11EF) != 0) {
                SLOT0 = func_021DFBB4(OBJ(0), 0x14, &v1, d_021D86A0, HEAP);
            } else {
                SLOT0 = func_021DFBB4(OBJ(0), 0x12, &v1, d_021D7D00, HEAP);
            }
            func_021E36C8(p, 2, 0, func_021D8FA4(p, func_021D8AA8(p)), 1);
            func_02015E04(OBJ(2));
            func_02015EA0(OBJ(2));
        } else {
            func_02015C30(OBJ(0), &v2);
            func_021DFD24(SLOT0);
            if (*(u8 *)(p + 0x11EF) != 0) {
                SLOT0 = func_021DFBB4(OBJ(0), 0x14, &v2, d_021D86A0, HEAP);
            } else {
                SLOT0 = func_021DFBB4(OBJ(0), 0x28, &v2, d_021D7DD8, HEAP);
            }
        }
        func_021D8E84(p, (int)func_021D48F0);
    }
}
