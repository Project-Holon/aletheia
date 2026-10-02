/*
 * function: func_021D8F54
 * address: 0x021D8F54
 * packet: pkt_ov093_021D8F54
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D8E00 0x021D8E00 thumb ov093
 *   func_021D8E7C 0x021D8E7C thumb ov093
 */
extern int func_021D8E00(void *, int);
extern void func_021D8E7C(int, void *, unsigned int, unsigned int, unsigned char);
void func_021D8F54(int a, void *b, int c, int *d)
{
    if (*d && func_021D8E00(b, c)) func_021D8E7C(a, b, c, 0, 0);
}
