/*
 * function: func_021A7198
 * address:  0x021A7198
 * packet:   pkt_ov021_021A7198
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V { u32 x, y, z; } V;

extern u32 func_02188C98(u8 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *a, struct VecFx32 *b);
extern void func_02164208(int dir, int *p, int amt);
extern int func_021AB0D4(void *a, void *b);
extern int func_021AB11C(u32 attr);

int func_021A7198(u32 a, u32 *b, V *c, u32 d)
{
    u32 h;
    V v;
    h = func_02188C98((u8 *)a);
    func_021A3038((unsigned char *)b[1], (struct VecFx32 *)c);
    v = *c;
    func_02164208(d, (int *)(&v), 0x10000);
    if (func_021AB11C(func_021AB0D4((void *)h, &v)) == 0)
        return 1;
    return 0;
}
