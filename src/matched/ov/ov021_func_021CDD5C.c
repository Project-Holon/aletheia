/*
 * function: func_021CDD5C
 * address:  0x021CDD5C
 * packet:   pkt_ov021_021CDD5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_021CF1AC  0x021CF1AC  thumb  ov021
 *   func_021CE7AC  0x021CE7AC  thumb  ov021
 *   func_021CF068  0x021CF068  thumb  ov021
 *   func_021CE81C  0x021CE81C  thumb  ov021
 *   func_021CF0F4  0x021CF0F4  thumb  ov021
 *   func_021CF32C  0x021CF32C  thumb  ov021
 *   func_021CE9A0  0x021CE9A0  thumb  ov021
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   data_021DB498  0x021DB498  data   ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021CE9E4(u8 *p, int n);
extern u32 func_021CF1AC(u32 a, u32 b, u32 c);
extern void func_021CE7AC(u8 *p);
extern int func_021CF068(u8 *p);
extern void func_021CE81C(void *p);
extern void func_021CF0F4(u8 *p);
extern int func_021CF32C(u32 flag);
extern void func_021CE9A0(u8 *p);
extern u32 func_020399A8(void);
extern void func_02039C68(u32 h, int a, int b);
extern int func_02039CB4(u32 h, int a, int b);
extern int func_02190EF0(u32 h);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0201F02C(int a, int b, int c);
extern u32 func_0200FB24(void);
extern u8 data_021DB498[];

#define U32(o) (*(u32 *)(p + (o)))

int func_021CDD5C(u8 *p)
{
    switch (p[0x51E]) {
    case 0:
        func_021CE9E4(p, 0x15);
        p[0x51E]++;
        break;
    case 1:
        if (func_021CF1AC((u32)(p + 0x30), 1, p[0x51B]) == 1) {
            p[0x51E]++;
        }
        break;
    case 2:
        func_021CE7AC(p);
        p[0x51E]++;
        break;
    case 3:
        if (func_021CF068(p) == 2) {
            func_021CE81C(p);
            func_021CF0F4(p);
            p[0x51E] = 10;
            break;
        }
        if (p[0x577] == 1) {
            if (func_021CF32C(p[0x51B]) == 1) {
                p[0x577] = 0;
            }
        }
        func_021CE9A0(p);
        if (p[0x519] == 1) {
            func_021CE81C(p);
            func_021CF0F4(p);
            p[0x51E] = 4;
        } else if (p[0x51A] == 1) {
            func_021CE81C(p);
            func_021CF0F4(p);
            p[0x51E] = 6;
        }
        break;
    case 4:
        if (p[0x520] == 0) {
            func_021CE9E4(p, 0x1e);
        }
        p[0x51E] = 5;
        func_02039C68(func_020399A8(), 1, 0x27);
        break;
    case 5:
        if (p[0x520] != 0 || func_02190EF0(U32(0x14)) == 1) {
            if (func_02039CB4(func_020399A8(), 1, 0x27) == 1) {
                U32(0x2c) = 1;
                p[0x51E] = 0xb;
            } else if (p[0x51A] == 1) {
                p[0x51E] = 6;
            }
        }
        break;
    case 6:
        func_021CE9E4(p, *(u16 *)(data_021DB498 + p[0x520] * 12 + 8));
        p[0x51E] = 7;
        break;
    case 7:
        if (func_02190EF0(U32(0x14)) == 1) {
            U32(0x2c) = 2;
            p[0x51E] = 0xb;
        }
        break;
    case 8:
        func_0203CEAC(0);
        func_0201F02C(U32(4), 0, U32(0x404));
        func_021CE9E4(p, 0x1f);
        p[0x51E] = 9;
        break;
    case 9:
        if (func_0203CDBC() == 1 && func_02190EF0(U32(0x14)) == 1) {
            U32(0x2c) = 3;
            p[0x51E] = 0xb;
        }
        break;
    case 10:
        U32(0x2c) = 2;
        p[0x51E] = 0xb;
        break;
    case 11:
        func_021CE81C(p);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(p);
        U32(0x2c) = 4;
        return 1;
    }
    return 0;
}
