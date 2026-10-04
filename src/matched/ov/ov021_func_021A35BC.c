/*
 * function: func_021A35BC
 * address:  0x021A35BC
 * packet:   pkt_ov021_021A35BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A30BC  0x021A30BC  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 */

int func_021A30BC(int a);
typedef signed int     s32;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
void *func_020120F4(const struct Ctx *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_020142E8(void *bitmap, s32 id);

int func_021A35BC(int a)
{
    if (func_020142E8((void *)func_0201296C(func_020120F4((const struct Ctx *)func_021A30BC(a))), 0x963) != 0)
        return 1;
    return 0;
}
