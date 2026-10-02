/*
 * function: func_021B6548
 * address: 0x021B6548
 * packet: pkt_ov067_021B6548
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B65C8 0x021B65C8 thumb ov067
 *   func_021B69C8 0x021B69C8 thumb ov067
 */
extern void *func_021B65C8(unsigned char *p, unsigned int v);
extern int func_021B69C8(void *p, int v);

int func_021B6548(unsigned char *p, unsigned int id, int v)
{
    return func_021B69C8(func_021B65C8(p, id), v);
}
