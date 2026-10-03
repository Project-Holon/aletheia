/*
 * function: func_0215F33C
 * address:  0x0215F33C
 * packet:   pkt_ov010_0215F33C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_0215911C  0x0215911C  thumb  ov010
 *   func_0215F608  0x0215F608  thumb  ov010
 *   func_0215A480  0x0215A480  thumb  ov010
 *   func_02162788  0x02162788  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern int func_02159B10();
extern void *func_0215A5E4(void *a0);
struct BigObj;
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_0215911C(void *p);
extern int func_0215F608();
extern u16 func_0215A480(unsigned a);
extern int func_02162788();

int func_0215F33C(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    int y = func_02159B10(a, b);
    int z = func_02159B10(a, b);
    int w = func_02159B10(a, b);
    u8 *base;
    int h;
    int r;
    r = func_02012844(func_0215A5E4((void *)b));
    base = (u8 *)func_0215911C(x);
    h = *(u16 *)(base + (u16)func_0215F608(base, y, w) * 8 + 6);
    func_02162788(r, z, func_0215A480(h));
    return 0;
}
