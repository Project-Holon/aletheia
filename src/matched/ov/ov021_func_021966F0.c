/*
 * function: func_021966F0
 * address:  0x021966F0
 * packet:   pkt_ov021_021966F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021966B0  0x021966B0  thumb  ov021
 *   func_0219707C  0x0219707C  thumb  ov021
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   func_02196974  0x02196974  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 *   d_021D4070     0x021D4070  data  a4
 *   d_021D4014     0x021D4014  data  a4
 *   d_021D4024     0x021D4024  data  a4
 *   d_021D404C     0x021D404C  data  a4
 *   d_021DDB84     0x021DDB84  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[4]; } Blk;

extern Blk d_021D4070;
extern u8 d_021D4014[];
extern u8 d_021D4024[];
extern u8 d_021D404C[];
extern u8 d_021DDB84[];
struct Cb;
extern void func_021966B0(u8 *p, u32 a);
extern void func_0219707C(u8 *p);
extern void func_0219630C(u32 a, void *b, void *c, void *d, void *e, void *f);
extern u32 func_02051B84(void *a, void *b, void *c, u32 d);
extern void func_02196034(void *p, void *fn, u32 n);
extern void func_0219649C(void *a, int b, struct Cb *c);
extern int func_02196974(u32 s, u8 *p);
extern void func_02196A4C(u8 *a);

void func_021966F0(u8 *p)
{
    Blk t = d_021D4070;

    func_021966B0(p, 0xB);
    func_0219707C(p);
    func_0219630C(4, &t, p, d_021DDB84, d_021D4014, d_021D4024);
    *(u32 *)(p + 0x24) = func_02051B84(d_021D404C, (void *)func_0219649C, p, *(u16 *)(p + 0x10));
    *(void **)(p + 4) = (void *)func_02196974;
    func_02196034(p, (void *)func_02196A4C, 0x340);
}
