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

struct Rec;
extern u32 func_02048AC4(void *ptr);
extern void func_02047E54(struct Rec *p);
extern u32 func_020307B0(void *p);

void func_021C1C04(u32 *p)
{
    func_02048AC4((void *)p[1]);
    func_02048AC4((void *)p[2]);
    func_02047E54((struct Rec *)p[5]);
    func_020307B0(p);
}
