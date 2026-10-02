/*
 * function: func_021F39D0
 * address: 0x021F39D0
 * packet: pkt_ov053_021F39D0
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E20 0x021C4E20 thumb ov021
 */

extern int func_02188C80(int);
extern unsigned func_020120F4(unsigned);
extern unsigned func_02012EC4(unsigned);
extern char *func_0200B3A4(unsigned, int);
extern unsigned func_021C4E20(void *);

void func_021F39D0(char *a, int b)
{
    int i;
    int *p = (int *)func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(b))), 1);
    for (i = 0; i < 5; i++)
        p[i] = (int)func_021C4E20(((void **)(a + 8))[i]) >> 12;
}
