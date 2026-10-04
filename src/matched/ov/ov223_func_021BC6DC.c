/*
 * function: func_021BC6DC
 * address:  0x021BC6DC
 * packet:   pkt_ov223_021BC6DC
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   veneer_02047964  0x02047964  arm
 *   func_02048AD0    0x02048AD0  arm
 *   func_020479D8    0x020479D8  arm
 */

extern void veneer_02047964(void *p);
struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);

void func_021BC6DC(int *p)
{
    veneer_02047964(p);
    func_02048AD0((struct Light *)(*p));
    func_020479D8();
}
