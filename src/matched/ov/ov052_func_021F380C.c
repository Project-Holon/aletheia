/*
 * function: func_021F380C
 * address: 0x021F380C
 * packet: pkt_ov052_021F380C
 * region: ov052
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_021F3998 0x021F3998 thumb ov052
 */

extern int func_02188C80(int);
extern unsigned func_020120F4(unsigned);
extern unsigned func_02012EC4(unsigned);
extern int func_02188C9C(int);
extern char *func_0200B3A4(unsigned, int);
extern int func_02188C84(int);
extern void func_021F3998(int, int *, int *);

int func_021F380C(int a)
{
    int y, x;
    unsigned h;
    func_02188C84(a);
    h = func_02012EC4(func_020120F4(func_02188C80(a)));
    func_021F3998(func_02188C9C(a), &x, &y);
    return **(int **)(func_0200B3A4(h, x) + 0x24);
}
