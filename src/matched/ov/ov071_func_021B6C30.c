/*
 * function: func_021B6C30
 * address: 0x021B6C30
 * packet: pkt_ov071_021B6C30
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021B6C46.
 * symbols:
 *   func_021B6DB4 0x021B6DB4 thumb ov071
 */
extern void func_021B6DB4(int *, int, int);
void func_021B6C30(int *p, int flag, int index)
{
    if (flag == 1) {
        func_021B6DB4(p, 1, index);
    } else {
        func_021B6DB4(p, 0, index);
    }
}
