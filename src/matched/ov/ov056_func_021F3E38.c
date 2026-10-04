/*
 * function: func_021F3E38
 * address:  0x021F3E38
 * packet:   pkt_ov056_021F3E38
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028B50  0x02028B50  thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_02188C80(void *p);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028B50(u8 *p, int a0);

void func_021F3E38(void *a0, void *a1)
{
    func_02028B50((u8 *)func_02012A30(func_020120F4(func_02188C80(a1))), 0x746);
}
