/*
 * function: func_021F0B74
 * address:  0x021F0B74
 * packet:   pkt_ov033_021F0B74
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     func_02030CBC takes (n, mem) (sub_0200545C): the 0xB8 result
 *           left in r1 before `blx func_02030CBC` is its second argument.
 *
 * symbols:
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   d_021F0E60 0x021F0E60 data ov033 a1
 */

extern unsigned func_02030CB0(unsigned);
extern void *func_02030734(unsigned, unsigned, unsigned, const char *, unsigned);
extern void *func_02030CBC(unsigned, void *);
extern unsigned func_02021518(unsigned);
extern void func_02021EE4(unsigned, unsigned);
extern void func_0202155C(unsigned, unsigned, unsigned, unsigned);
extern void func_020216D4(unsigned, unsigned, unsigned, unsigned);
extern const char d_021F0E60[];

void func_021F0B74(char *p)
{
    *(void **)(p + 0xB8) = func_02030734(*(unsigned short *)p, func_02030CB0(2), 1, d_021F0E60, 0x6DF);
    *(void **)(p + 0xB4) = func_02030CBC(2, *(void **)(p + 0xB8));
    *(unsigned *)(p + 0xBC) = func_02021518(*(unsigned short *)p);
    func_02021EE4(*(unsigned *)(p + 0xBC), 1);
    func_0202155C(*(unsigned *)(p + 0xBC), 1, 0x60, *(unsigned short *)p);
    func_0202155C(*(unsigned *)(p + 0xBC), 3, 0x80, *(unsigned short *)p);
    func_020216D4(*(unsigned *)(p + 0xBC), 1, 0, 0x60);
    func_020216D4(*(unsigned *)(p + 0xBC), 3, 0, 0x80);
    *(unsigned *)(p + 0xC0) = 0;
    *(unsigned *)(p + 0xC4) = 0;
}
