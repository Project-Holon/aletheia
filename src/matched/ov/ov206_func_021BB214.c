/*
 * function: func_021BB214
 * address: 0x021BB214
 * packet: pkt_ov206_021BB214
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
void func_021BB214(char *p, int i)
{
    char *s = p + i * 4;
    func_0204ADA4(*(void **)(s + 0x9c));
    func_0204A8D4(*(void **)(s + 0x94));
    func_0204AFD8(*(void **)(s + 0xa4));
}
