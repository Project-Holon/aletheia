/*
 * function: func_021844D8
 * address:  0x021844D8
 * packet:   pkt_ov023_021844D8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The extent runs long: 0x0218454C is an unlabelled leaf,
 * char *f(int i, char *p) { return p + 0x7ec0 + i * 0x3f0; }
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082B0C  0x02082B0C  arm
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_0203996C  0x0203996C  arm
 *   func_0203AA94  0x0203AA94  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
typedef signed int     s32;
struct Bmp;
struct Entry;
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082B0C(u32 src, char *dst, u32 n);
extern u32 func_021841A0(u32 x);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203AA94(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

void func_021844D8(char *p, int x)
{
    int i;
    u32 *q;
    u32 t;
    u32 sum;
    u8 c;

    t = (u32)func_020437D4((const struct Bmp *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x118))));
    func_02082B0C(t + x * 1000, p + 0x7ad0, 1000);
    q = (u32 *)(p + 0x7ad0);
    sum = 0;
    for (i = 0; i < 250; i++)
        sum ^= q[i];
    *(u32 *)(p + 0x7eb8) = sum;
    *(u8 *)(p + 0x7ebc) = x;
    c = func_021841A0(*(u32 *)*(u32 **)(p + 4));
    func_0203AA94((u32)func_0203996C(0xff), c, 0x2900, 0x3f0, (u32)(p + 0x7ad0));
}
