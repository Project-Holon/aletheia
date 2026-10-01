/*
 * function: func_021C1C04
 * address:  0x021C1C04
 * packet:   pkt_ov021_021C1C04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the effect handles and frees the object (EXACT*: trailing pad).
 */

typedef unsigned int u32;

extern void func_02048AC4(u32);
extern void func_02047E54(u32);
extern void func_020307B0(void *);

void func_021C1C04(u32 *p)
{
    func_02048AC4(p[1]);
    func_02048AC4(p[2]);
    func_02047E54(p[5]);
    func_020307B0(p);
}
