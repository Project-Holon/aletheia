/*
 * function: func_068980CC
 * address: 0x068980CC
 * packet: pkt_ov095_068980CC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_068980E4 0x068980E4 thumb ov095
 *   func_068980F4 0x068980F4 thumb ov095
 */
extern int func_068980E4(int key);
extern void func_068980F4(int key, int value);
void func_068980CC(void)
{
    if (func_068980E4(0x16) == 4)
        func_068980F4(0x4b, 1);
}
