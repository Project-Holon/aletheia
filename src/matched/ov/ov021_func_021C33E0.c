/*
 * function: func_021C33E0
 * address:  0x021C33E0
 * packet:   pkt_ov021_021C33E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
typedef unsigned int   u32;
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020143CC(u32 a, u32 b);

void func_021C33E0(void *a)
{
    *((u16 *)func_020143CC(func_0201296C(func_020120F4(func_02188C80(a))), 0x4139)) = 0;
}
