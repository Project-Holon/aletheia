/*
 * function: func_021DCBA4
 * address: 0x021DCBA4
 * packet: pkt_ov171_021DCBA4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02022004 0x02022004 thumb
 *   func_02021EE4 0x02021EE4 thumb
 */
typedef unsigned short u16;
extern void func_02022004(unsigned, unsigned, u16, unsigned, unsigned);
struct Obj02021EE4;
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
void func_021DCBA4(char *p)
{
    unsigned i;
    for (i=0; i<6; i++)
        func_02022004(*(unsigned *)(p+0xb30), 2, (1<<i)|(1<<(i+6)), (unsigned char)p[0xb3a+i], 0);
    func_02021EE4((struct Obj02021EE4 *)(*(unsigned *)(p+0xb30)), 1);
}
