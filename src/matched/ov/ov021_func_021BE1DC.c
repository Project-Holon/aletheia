/*
 * function: func_021BE1DC
 * address:  0x021BE1DC
 * packet:   pkt_ov021_021BE1DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   d_021D9D98     0x021D9D98  data  a4
 *   d_021D9CBC     0x021D9CBC  data  a4
 */

extern void *func_02188C80(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int func_0200B3AC(void *p);
extern void func_02034AC4(void *);

extern void *d_021D9D98[];
extern void (*d_021D9CBC[])(void *);

void func_021BE1DC(void *arg)
{
    int i;

    i = func_0200B3AC(func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9D98[i] != 0) {
            func_02034AC4(d_021D9D98[i]);
        }
        d_021D9CBC[i](arg);
    }
}
