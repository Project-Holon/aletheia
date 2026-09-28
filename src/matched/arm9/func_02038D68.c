/*
 * function: func_02038D68
 * address:  0x02038D68
 * packet:   pkt_02038D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   func_02039338   0x02039338  arm
 *   func_0203996C   0x0203996C  arm
 *   func_0203A770   0x0203A770  arm
 *   func_02037234   0x02037234  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038D68.c \
 *       --func func_02038D68 --addr 0x02038D68 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0203D798(void);
extern u32  func_02039338(void);
extern u32  func_0203996C(u32 a);
extern void func_0203A770(u8 a, u8 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02037234(u8 *p);

void func_02038D68(int a0, u32 a1, u32 a2, u8 *a3)
{
    u32 v;

    func_0203D798();
    v = func_0203996C(func_02039338());
    func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);

    if (func_02039338() == 0) {
        v = func_0203996C(0xFF);
        if (a0 < 0x11)
            func_0203A770(a3[0x0E], a3[0x0F], a0, a1, a2, v);
    }

    func_02037234(a3);
}
