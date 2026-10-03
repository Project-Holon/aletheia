/*
 * function: func_021DF6B4
 * address: 0x021DF6B4
 * packet: pkt_ov119_021DF6B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 */
extern int func_021D8AF4(int a, char *p);
extern int func_021D8B0C(int, int);
int func_021DF6B4(char *p, int a, int b)
{
    int x = func_021D8AF4(a, p);
    int y = func_021D8B0C(a, b);
    if (*(int *)(p + 0xF94) == y && *(int *)(p + 0xF98) == x) {
        return 1;
    }
    return 0;
}
