/*
 * function: func_02188A64
 * address: 0x02188A64
 * packet: pkt_ov096_02188A64
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188AB4 0x02188AB4 thumb ov096
 */
struct Cursor;
extern int func_02188AB4(struct Cursor *a, unsigned char *b, int c);
int func_02188A64(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 1);
    return *(int *)(b + 0xc4);
}
