/*
 * function: func_021F3714
 * address:  0x021F3714
 * packet:   pkt_ov058_021F3714
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct Big;
extern void *func_02188C80(void *p);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int func_02188D2C(int *p);
extern void func_021BE418(u8 *p, u16 i);
extern void func_021897A0(unsigned char *p, int id);

void func_021F3714(void *a0)
{
    func_02012EC4((struct Big *)func_020120F4(func_02188C80(a0)));
    func_021BE418((u8 *)func_02188D2C((int *)a0), 0);
    func_021897A0((unsigned char *)a0, 1);
}
