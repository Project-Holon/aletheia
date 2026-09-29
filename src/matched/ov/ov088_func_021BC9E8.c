/*
 * function: func_021BC9E8
 * address:  0x021BC9E8
 * packet:   pkt_ov088_021BC9E8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 1's fade call takes its zero from an enum local set at the top of
 * the arm: the enum is not folded, so the zero stays in r5 (the register
 * the stack-argument zeros use) through to `adds r2, r5, #0`. A literal 0,
 * an int local set to 0, and int-typed func_02049624 parameters all give
 * `movs r2, #0` scheduled after r0/r1 (6 bytes out); the permuter (300,
 * --types) found nothing.
 * volatile: DISPCNT 0x04000000 and DB_DISPCNT 0x04001000 read-modify-written by the SDK inlines GX_SetVisibleWnd/GXS_SetVisibleWnd (0x021BCA3A, 0x021BCA46)
 *
 * symbols:
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0207D534  0x0207D534  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040588  0x02040588  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   d_021BD944     0x021BD944  data  a4
 *   d_021BD8F4     0x021BD8F4  data  a4
 *   d_021BD904     0x021BD904  data  a4
 *   d_021BD924     0x021BD924  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define reg_G2_BLDCNT      (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
#define reg_GX_DISPCNT     (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}

static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}

typedef enum { Z0 } Zero;

typedef struct {
    u16 state;
    u16 pad;
    int count;
} St;

extern void func_02043534(int);
extern void func_020435F4(int);
extern void func_020433E0(const void *);
extern void func_0203F8F4(int);
extern void func_0203FC28(const void *);
extern void func_0203FCA0(int, const void *, int);
extern void func_0207D534(u32 reg, int brightness);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0204989C(int, int, int, int, int, int, int);
extern void func_02049B40(int, int, int, int, int, int);
extern void func_02040588(int a, int b);
extern void func_0204363C(int a);
extern void func_0204361C(void);
extern void func_0204E720(int a, int b, int c, int d);
extern int func_0204E804(void);
extern u32 func_020362DC(void);
extern void func_020409B4(u32 layer);
extern void func_0203F9B4(void);

extern const u8 d_021BD944[];
extern const u8 d_021BD8F4[];
extern const u8 d_021BD904[];
extern const u8 d_021BD924[];

int func_021BC9E8(int a0, int a1, int *mode, St *st)
{
    Zero z;

    switch (st->state) {
    case 0:
        func_02043534(0);
        func_020435F4(0);
        reg_G2_BLDCNT = 0;
        reg_G2S_DB_BLDCNT = 0;
        GX_SetVisibleWnd(0);
        GXS_SetVisibleWnd(0);
        func_020433E0(d_021BD944);
        func_0203F8F4(0x16);
        func_0203FC28(d_021BD8F4);
        func_0203FCA0(1, d_021BD904, 0);
        func_0203FCA0(5, d_021BD924, 0);
        if (*mode == 1) {
            func_0207D534(0x0400006C, -16);
            func_0207D534(0x0400106C, -16);
            st->state = 7;
        } else {
            func_0207D534(0x0400006C, 16);
            func_0207D534(0x0400106C, 16);
            st->state = 1;
        }
        break;
    case 1:
        z = Z0;
        func_02049624(0x1a, 0xc, 1, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xd, 1, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 0, 0, 0, 0x16);
        func_02049624(0x1a, 0xc, 5, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xe, 5, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 4, 0, 0, 0x16);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(0xc, 0x10, z, 2);
        st->state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) {
            st->state = 3;
            st->count = 0;
        }
        break;
    case 3:
        if (++st->count > 0x5a)
            st->state = 4;
        if (func_020362DC() & 0xb)
            st->state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 0x10, 2);
        st->state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) {
            st->state = 6;
            st->count = 0;
        }
        break;
    case 6:
        if (++st->count > 0x1e) {
            st->state = 7;
            st->count = 0;
        }
        break;
    case 7:
        func_02049624(0xa4, 1, 1, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 2, 1, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 0, 0, 0, 0x16);
        func_02049624(0xa4, 3, 5, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 4, 5, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 4, 0, 0, 0x16);
        func_020409B4(1);
        func_020409B4(5);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(3, 0x10, 0, 2);
        st->state = 8;
        break;
    case 8:
        if (func_0204E804() == 0)
            st->state = 9;
        break;
    case 9:
        if (++st->count > 0x5a) {
            st->state = 10;
            st->count = 0;
        }
        break;
    case 10:
        func_0204E720(3, 0, 0x10, 2);
        st->state = 0xb;
        break;
    case 11:
        if (func_0204E804() == 0)
            st->state = 0xc;
        break;
    case 12:
        if (++st->count > 0x1e)
            st->state = 0xd;
        break;
    case 13:
        func_0203F9B4();
        return 1;
    }
    return 0;
}
