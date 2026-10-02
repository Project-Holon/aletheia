/*
 * function: func_021F388C
 * address: 0x021F388C
 * packet: pkt_ov052_021F388C
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
 */

extern int func_02188C80(int);
extern unsigned func_020120F4(unsigned);
extern unsigned func_02012EC4(unsigned);
extern int func_02188C9C(int);
extern char *func_0200B3A4(unsigned, int);

void func_021F388C(int a)
{
    unsigned h = func_02012EC4(func_020120F4(func_02188C80(a)));
    if (func_02188C9C(a) == 0x4b) {
        char *p = func_0200B3A4(h, 0x27);
        if (p != 0) {
            unsigned char *q = *(unsigned char **)(p + 0x24);
            if (q != 0)
                *q = 1;
        }
    }
}
