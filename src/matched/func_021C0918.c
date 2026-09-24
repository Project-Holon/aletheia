/*
 * function: func_021C0918
 * address:  0x021C0918
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026498  0x02026498  thumb
 *   func_021BF734  0x021BF734  thumb  ov217
 *
 * Opens the +0x10 record (func_02012138 on the result of func_021BF734),
 * tags it with 1, and releases it when func_02026454 reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02012138();
extern u32 func_02026400();
extern u32 func_02026454();
extern u32 func_02026498();
extern u32 func_021BF734();
void func_021C0918(void)
{
    func_021BF734();
    u32 v1 = func_02012138();
    func_02026498(v1, 1);
    if (func_02026454(v1) == 2) {
    func_02026400(v1);
    }
}
