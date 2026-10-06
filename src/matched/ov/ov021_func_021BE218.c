/*
 * function: func_021BE218
 * address:  0x021BE218
 * packet:   pkt_ov021_021BE218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE218  0x021BE218  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   d_021D9BE0     0x021D9BE0  data  ov021  a4
 *   d_021D9D98     0x021D9D98  data  ov021  a4
 */

extern void *func_02188C80(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 func_0200B3AC(struct Rec94 *p);
extern void func_02034A5C(int handle);

extern void (*d_021D9BE0[])(void *);
extern void *d_021D9D98[];

void func_021BE218(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9BE0[i] != 0) {
            d_021D9BE0[i](arg);
        }
        if (d_021D9D98[i] != 0) {
            func_02034A5C((int)d_021D9D98[i]);
        }
    }
}
