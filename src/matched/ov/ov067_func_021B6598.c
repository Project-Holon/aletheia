/*
 * function: func_021B6598
 * address: 0x021B6598
 * packet: pkt_ov067_021B6598
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B65C8 0x021B65C8 thumb ov067
 *   func_021B69D8 0x021B69D8 thumb ov067
 */
extern void *func_021B65C8(unsigned char *p, unsigned int v);
extern void func_021B69D8(void *p, unsigned int v);

void func_021B6598(unsigned char *p, unsigned int id, unsigned int v)
{
    func_021B69D8(func_021B65C8(p, id), v);
}
