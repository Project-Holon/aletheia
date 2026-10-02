/*
 * function: func_021B9F24
 * address: 0x021B9F24
 * packet: pkt_ov069_021B9F24
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025CD0 0x02025CD0 thumb
 *   func_021B9FC8 0x021B9FC8 thumb ov069
 *   d_021BA71C 0x021BA71C data a4
 *   d_021BA5EC 0x021BA5EC data a4
 */
extern const char d_021BA71C[], d_021BA5EC[];
extern void *func_02025CD0(const void *a, const void *b, void *p, int k, unsigned char flag, unsigned short heap);
extern void func_021B9FC8(char *p, int i);
void func_021B9F24(char *p)
{
    *(void **)(p + 0x14C) = func_02025CD0(d_021BA71C, d_021BA5EC, p, 1, 0, 0x80);
    func_021B9FC8(p, 0);
}
