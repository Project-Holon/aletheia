/*
 * function: func_021BD5D4
 * address: 0x021BD5D4
 * packet: pkt_ov209_021BD5D4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD4F4 0x021BD4F4 thumb ov209
 *   func_0200CA70 0x0200CA70 thumb
 *   func_021BD440 0x021BD440 thumb ov209
 *   func_021BD4DC 0x021BD4DC thumb ov209
 */
extern void func_021BD4F4(char *, unsigned);
extern unsigned func_0200CA70(void *);
extern void func_021BD440(char *, unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned);
extern void func_021BD4DC(char *);
void func_021BD5D4(char *p)
{
    func_021BD4F4(p, 0);
    if (func_0200CA70(*(void **)(*(char **)p + 4)) == 1)
        func_021BD440(p, 0, 1, 0, 4, 0x39e0, 0);
    else
        func_021BD440(p, 0, 0, 0, 4, 0x39e0, 0);
    func_021BD4DC(p + 32);
}
