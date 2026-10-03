/*
 * function: func_021DD294
 * address: 0x021DD294
 * packet: pkt_ov119_021DD294
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E2A1C 0x021E2A1C thumb ov119
 */
extern void func_021E2A1C(char *p, int a, int b);
void func_021DD294(char *p, int a, int b)
{
    if (*(int *)(p + 0x118C) == 3)
        func_021E2A1C(p, a, b);
}
