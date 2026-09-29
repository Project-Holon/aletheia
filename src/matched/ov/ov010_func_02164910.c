/*
 * function: func_02164910
 * address:  0x02164910
 * packet:   pkt_ov010_02164910
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads three values off a stream, loads overlay 82 and calls into it.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_0215A5DC  0x0215A5DC  thumb ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159144  0x02159144  thumb ov010
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F5260  0x021F5260  thumb ov082
 *   func_0215897C  0x0215897C  thumb ov010
 *   ov_id_52       0x00000052  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_0215A5F4(void *a);
extern u32  func_0215A5DC(void *a);
extern u32  func_02011330(void *a);
extern void func_02159144(int a);
extern void func_02034AC4(void *a);
extern int  func_021F5260(u32 a, u32 b, u32 c, u32 d, void *e);
extern void func_0215897C(u32 a, int b);
extern u8 ov_id_52[];

int func_02164910(void *s, void *q)
{
    u32 x = func_0215A5F4(q);
    u32 y = func_0215A5DC(q);
    u8 a = func_02011330(s);
    u8 b = func_02011330(s);
    u32 c = func_02011330(s);
    int r;
    func_02159144(7);
    func_02034AC4(ov_id_52);
    r = func_021F5260(a, b, c, y, q);
    if (r == 0) {
        return 1;
    }
    func_0215897C(x, r);
    return 1;
}
