/*
 * function: func_0217C194
 * address: 0x0217C194
 * packet: pkt_ov018_0217C194
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0x0217C1CE.
 * symbols:
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_02013D5C 0x02013D5C thumb
 *   func_0217C14C 0x0217C14C thumb ov018
 */
typedef unsigned short u16;
extern int func_02188C9C(int);
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern void func_0217C14C(int, u16, u16, int);
void func_0217C194(int p)
{
    int i;
    if (func_02013D5C(func_02188C9C(p)) != 0) {
        for (i = 0; i < 3; ++i)
            func_0217C14C(p, (((i << 22) + 0x1f8000) >> 12) / 16, 29, 32);
    }
}
