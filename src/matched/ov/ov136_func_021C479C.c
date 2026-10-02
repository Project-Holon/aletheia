/*
 * function: func_021C479C
 * address:  0x021C479C
 * packet:   pkt_ov136_021C479C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C479C 0x021C479C thumb
 *   func_021C4538 0x021C4538 thumb
 *   func_021C45C0 0x021C45C0 thumb
 *   func_021C4700 0x021C4700 thumb
 */
typedef unsigned char u8;
extern int func_021C4538(u8 *p);
extern int func_021C45C0(u8 *p);
extern int func_021C4700(u8 *p);
int func_021C479C(u8 *p)
{
    if (func_021C4538(p)) return 0;
    if (p[0xA] == 1) return func_021C45C0(p);
    return func_021C4700(p);
}
