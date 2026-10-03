/*
 * function: func_021F0FF0
 * address: 0x021F0FF0
 * packet: pkt_ov029_021F0FF0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: followed by existing ov029_func_021F1000.c.
 * symbols:
 *   func_02021B18 0x02021B18 thumb
 */
struct Obj02021B18;
extern void func_02021B18(struct Obj02021B18 *o);
void func_021F0FF0(char *p)
{
    func_02021B18(*(void **)(p + 0x210));
}
