/*
 * function: func_021D6BA4
 * address:  0x021D6BA4
 * packet:   pkt_ov118_021D6BA4
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6AD4  0x021D6AD4  thumb  ov118
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015E4C  0x02015E4C  thumb
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   func_021E1098  0x021E1098  thumb  ov119
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_020307B0  0x020307B0  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021D6F90  0x021D6F90  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D6AD4(u8 *p);
extern void func_02015C30(u32, Vec *);
extern void func_02015C48(u32, Vec *);
extern void func_02015EB0(u32);
extern void func_02015EA0(u32);
extern void func_02015E4C(u32);
extern int func_021E12AC(void *p);
extern void func_021E1098(void *p);
extern void func_021E36D8(void *p, int a);
extern void func_020307B0(u32);
extern void func_021D8E84(void *p, int next);
extern void func_021DFC68(u32, void *);
extern void func_021D6F90(u8 *p);

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define SLOT0 (*(u32 *)(p + 0x85C))

void func_021D6BA4(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        func_021D6AD4(p);
    }
    if (*(u8 *)(p + 0x11ED) == 0 && FRAME == 6) {
        func_02015C30(OBJ(0), &v);
        func_02015C48(OBJ(2), &v);
        func_02015EB0(OBJ(2));
        func_02015EA0(OBJ(0));
        func_02015E4C(OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && func_021E12AC(p) != 0) {
        func_021E1098(p);
        if (*(u8 *)(p + 0x11ED) == 0) {
            func_021E36D8(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        func_021D8E84(p, (int)func_021D6F90);
    }
    func_021DFC68(SLOT0, p);
}
