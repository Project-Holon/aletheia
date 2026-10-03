/*
 * function: func_021C33E0
 * address:  0x021C33E0
 * packet:   pkt_ov021_021C33E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears event flag 0x4139 (EXACT*: unlabelled follower).
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 */

typedef unsigned short u16;

extern void *func_02188C80(void *p);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201296C(void *p);
extern u16 *func_020143CC(void *p, int id);

void func_021C33E0(void *a)
{
    *func_020143CC(func_0201296C(func_020120F4(func_02188C80(a))), 0x4139) = 0;
}
