/*
 * function: func_021BAE50
 * address:  0x021BAE50
 * packet:   pkt_021BAE50
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02047964  0x02047964  arm
 *   func_02048AD0    0x02048AD0  arm
 *   func_020479D8    0x020479D8  arm
 */

extern void func_02047964(void *p);
struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);

void func_021BAE50(int *p)
{
    func_02047964(p);
    func_02048AD0((struct Light *)(*p));
    func_020479D8();
}
