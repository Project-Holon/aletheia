/*
 * function: func_021A2F6C
 * address:  0x021A2F6C
 * packet:   pkt_ov021_021A2F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A53D0  0x021A53D0  thumb  ov021
 *   func_021A5A34  0x021A5A34  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 func_02188CFC(u8 *p);
void func_021A53D0(u32 *p);
void func_021A5A34(u32 *p);

void func_021A2F6C(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A53D0((u32 *)p[2]);
    else
        func_021A5A34((u32 *)p[3]);
}
