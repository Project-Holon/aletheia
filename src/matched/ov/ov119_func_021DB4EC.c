/*
 * function: func_021DB4EC
 * address: 0x021DB4EC
 * packet: pkt_ov119_021DB4EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB4B4 0x021DB4B4 thumb ov119
 */
extern int func_021DB4B4(int);
int func_021DB4EC(char *p, int index)
{
    int position = func_021DB4B4(index);
    int start = *(short *)(p + 0x107c);
    if (start < position && start + 0xe0 > position)
        return 1;
    position += *(int *)(p + 0x63c);
    if (start < position && start + 0xe0 > position)
        return 1;
    return 0;
}
