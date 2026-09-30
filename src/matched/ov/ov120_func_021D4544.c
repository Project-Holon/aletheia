/*
 * function: func_021D4544
 * address: 0x021D4544
 * packet: pkt_ov120_021D4544
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7A74 0x021D7A74 thumb ov120
 *   func_021D7F5C 0x021D7F5C thumb ov120
 *   func_021D80D4 0x021D80D4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D44EC 0x021D44EC thumb ov120
 */
extern void func_021D7A74(int, int);
extern void func_021D7F5C(int, int);
extern void func_021D80D4(int);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D44EC(int);
void func_021D4544(int a)
{
    --*(int *)(a + 0x14);
    if (*(int *)(a + 0x14) == 20)
        func_021D7A74(*(int *)(a + 0x40), 0x27);
    if (*(int *)(a + 0x14) == 0) {
        func_021D7F5C(*(int *)(a + 0x40), 0x23);
        func_021D80D4(*(int *)(a + 0x40));
        func_021D4244(a, func_021D44EC, 0x241);
    }
}
