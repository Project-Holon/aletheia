/*
 * function: func_02189084
 * address:  0x02189084
 * packet:   pkt_ov021_02189084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   d_021D35D8     0x021D35D8  data  a4
 */

typedef void (*Fn)(unsigned char *p);

extern Fn d_021D35D8[];
void func_02047964(void);
void func_020479D8(void);

void func_02189084(unsigned char *p)
{
    Fn fn;
    func_02047964();
    func_020479D8();
    fn = d_021D35D8[*(int *)(p + 0x12C)];
    if (fn != 0)
        fn(p);
}
