/*
 * function: func_021A2FE4
 * address:  0x021A2FE4
 * packet:   pkt_ov021_021A2FE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021A548C  0x021A548C  thumb
 *   func_021A54A0  0x021A54A0  thumb
 *   func_021A59EC  0x021A59EC  thumb
 *   func_021A396C  0x021A396C  thumb
 *   func_021A3818  0x021A3818  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188CFC(u8 *p);
extern int func_021A548C();
extern int func_021A54A0(u32 a);
extern u32 func_021A59EC(u32 p);
extern void func_021A396C(u8 *p, u32 v);
extern void func_021A3818(u32 *p);

void func_021A2FE4(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0) {
        if (func_021A548C(p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
        if (func_021A54A0(p[2]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    } else {
        if (func_021A59EC(p[3]) == 1) {
            func_021A396C((u8 *)p[1], 2);
            return;
        }
    }
    func_021A3818((u32 *)p[1]);
}
