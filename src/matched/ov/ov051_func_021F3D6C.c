/*
 * function: func_021F3D6C
 * address: 0x021F3D6C
 * packet: pkt_ov051_021F3D6C
 * region: ov051
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
 *   func_021F3D94 0x021F3D94 thumb ov051
 */

extern int func_02188C80(int);
extern unsigned func_020120F4(unsigned);
extern unsigned func_02012EC4(unsigned);
extern int func_02188C9C(int);
extern char *func_0200B3A4(unsigned, int);
extern int func_021F3D94(int);

void *func_021F3D6C(int a)
{
    unsigned h = func_02012EC4(func_020120F4(func_02188C80(a)));
    return *(void **)(func_0200B3A4(h, func_021F3D94(func_02188C9C(a))) + 4);
}
