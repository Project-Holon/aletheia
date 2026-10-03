/*
 * function: func_021F00BC
 * address:  0x021F00BC
 * packet:   pkt_ov034_021F00BC
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F00BC 0x021F00BC thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204B3DC 0x0204B3DC arm
 */

extern void func_020456F8(int);
extern int func_02045730(int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
extern void func_0204B3DC(int, int);

void func_021F00BC(int *p)
{
    int h = p[0x11];
    unsigned int i;

    func_020456F8(h);
    func_02041B6C(func_02045730(h));
    for (i = 6; i <= 15; i++)
        func_0204B3DC(p[0x15 + i], 1);
    p[0x44] = 1;
}
