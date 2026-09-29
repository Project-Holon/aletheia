/*
 * function: func_021B97F4
 * address:  0x021B97F4
 * packet:   pkt_ov069_021B97F4
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA65C  0x021BA65C  data  a4
 *   d_021BA7A0  0x021BA7A0  data  a4
 *   d_021BA60C  0x021BA60C  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B160 {
    u32 w[40];
} B160;

extern A16 d_021BA65C;
extern B160 d_021BA7A0;
extern u32 d_021BA60C[];

extern void func_0203F8F4(int);
extern void func_0203FC28(void *);
extern void func_0203FCA0(u8, void *, int);
extern void func_020414EC(u8);
extern void func_02040B94(u8, int, int, int);
extern void func_02040588(u8, int);

void func_021B97F4(void)
{
    A16 a;
    B160 b;
    u32 i;
    u32 id;

    func_0203F8F4(0x80);
    a = d_021BA65C;
    func_0203FC28(&a);
    b = d_021BA7A0;
    for (i = 0; i < 5; i++) {
        id = d_021BA60C[i];
        func_0203FCA0(id, &b.w[i * 8], 0);
        func_020414EC(id);
        func_02040B94(id, 0x20, 0, 0x80);
        func_02040588(id, 1);
    }
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_02040588(3, 0);
}
