/*
 * function: func_021F39D8
 * address: 0x021F39D8
 * packet: pkt_ov038_021F39D8
 * region: ov038
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding at 021F3A06.
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021BE580 0x021BE580 thumb ov021
 */
extern int func_02188D2C(int *);
extern int *func_021897BC(char *, int);
extern unsigned int func_02188C80(unsigned char *);
extern void *func_020120F4(const void *);
extern void *func_02012EC4(void *);
extern int *func_0200B3A4(void *, int);
extern void func_021BE580(void *);
void func_021F39D8(void *p)
{
    int h = func_02188D2C(p);
    func_021897BC(p, 1);
    func_0200B3A4(func_02012EC4(func_020120F4((void *)func_02188C80(p))), 6);
    func_021BE580((void *)h);
}
