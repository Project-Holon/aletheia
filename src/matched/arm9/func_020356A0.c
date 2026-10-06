/*
 * unit:     no
 * function: func_020356A0
 * address:  0x020356A0
 * packet:   pkt_020356A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469BC     0x021469BC  data
 *   func_020363B8  0x020363B8  arm
 *   func_020363D4  0x020363D4  arm
 *   func_020363F0  0x020363F0  arm
 *   func_02035E84  0x02035E84  arm
 *   func_02035EB0  0x02035EB0  arm
 *   func_02035ECC  0x02035ECC  arm
 *
 * A descriptor fan-out: the global at 0x021469BC carries a callback at +4
 * which fills two twelve-byte records on the stack, and the seven
 * accessors below push each pair into the object in a0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u8  f0A;
    u8  f0B;
} S12;

typedef struct {
    u32 f00;
    int (*f04)(S12 *dst, S12 *src);
} Desc;

extern Desc g_021469BC;
extern int func_020363B8(int a0, int a1, int a2);
extern int func_020363D4(int a0, int a1, int a2);
extern int func_020363F0(int a0, int a1, int a2);
extern void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d);
extern int func_02035EB0(int a0, int a1, int a2);
extern int func_02035ECC(int a0, int a1, int a2);

void func_020356A0(int a0)
{
    S12 b;
    S12 a;

    if (g_021469BC.f04 == 0) {
        return;
    }
    if (g_021469BC.f04(&b, &a) == 0) {
        return;
    }
    func_020363B8(a0, b.f00, a.f00);
    func_020363D4(a0, b.f02, a.f02);
    func_020363F0(a0, b.f04, a.f04);
    func_02035E84((void *)a0, b.f06, b.f08, a.f06, a.f08);
    func_02035EB0(a0, b.f0A, a.f0A);
    func_02035ECC(a0, b.f0B, a.f0B);
}
