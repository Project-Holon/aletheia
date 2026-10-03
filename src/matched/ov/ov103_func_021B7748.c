/*
 * function: func_021B7748
 * address: 0x021B7748
 * packet: pkt_ov103_021B7748
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B7750 reads display control register.
 * symbols:
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B9174 0x021B9174 thumb ov103
 *   func_021B80E4 0x021B80E4 thumb ov103
 *   func_021B78EC 0x021B78EC thumb ov103
 *   func_021B7FC8 0x021B7FC8 thumb ov103
 *   func_021B8B1C 0x021B8B1C thumb ov103
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
typedef unsigned char u8;
extern void func_021B71C0(int);
extern void func_021B9174(void *p);
extern void func_021B80E4(u8 *);
extern void func_021B78EC(u8 *);
extern void func_021B7FC8(u8 *);
extern void func_021B8B1C(u8 *);
extern void func_020315D4(int);
extern void func_020306F0(int);
int func_021B7748(int a, int b, int c, u8 *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    func_021B71C0(*(int *)(p + 0xa38));
    func_021B9174(p + 0x198);
    func_021B80E4(p + 0x748);
    func_021B80E4(p + 0x184);
    func_021B78EC(p);
    func_021B7FC8(p + 0x174);
    func_021B8B1C(p + 0x75c);
    func_020315D4(a);
    func_020306F0(55);
    return 1;
}
