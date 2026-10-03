/*
 * function: func_021F3724
 * address:  0x021F3724
 * packet:   pkt_ov060_021F3724
 * region:   ov060
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

extern void *func_02188C80(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_02188D2C(void *p);
extern void func_021BE418(unsigned char *p, unsigned short i);
extern void func_021897A0(unsigned char *p, int id);

void func_021F3724(unsigned char *p)
{
    func_02012EC4(func_020120F4(func_02188C80(p)));
    func_021BE418(func_02188D2C(p), 0);
    func_021897A0(p, 0);
}
