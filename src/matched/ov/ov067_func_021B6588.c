/*
 * function: func_021B6588
 * address: 0x021B6588
 * packet: pkt_ov067_021B6588
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_FindButton 0x021B65C8 thumb ov067
 *   func_021B6A1C 0x021B6A1C thumb ov067
 */
extern void *TOUCHBAR_FindButton(unsigned char *p, unsigned int v);
extern void func_021B6A1C(void *p, unsigned int v);

void func_021B6588(unsigned char *p, unsigned int id, unsigned int v)
{
    func_021B6A1C(TOUCHBAR_FindButton(p, id), v);
}
