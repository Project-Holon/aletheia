/*
 * function: func_021A5810
 * address:  0x021A5810
 * packet:   pkt_ov021_021A5810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02162564  0x02162564  thumb  ov010
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626B8  0x021626B8  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_021A3960(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_02164208(int dir, Vec3 *p, int amt);
extern int func_02162564(int a, Vec3 *p);
extern int func_021625CC(int a, int b);
extern int func_021626B8(int a, int b);

int func_021A5810(u8 *p, int dir)
{
    u8 *a;
    int h;
    int i;
    Vec3 pos;

    a = func_021A3960(*(u8 **)(p + 0xc));
    h = func_02012844(func_020120F4(func_02188C80(*(u8 **)(p + 0x10))));
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    func_02164208(dir, &pos, 0x10000);
    i = func_02162564(h, &pos);
    if (i == 0xffff) {
        return 0;
    }
    if (func_021626B8(func_021625CC(h, (u16)i), dir)) {
        return 1;
    }
    return 0;
}
