/*
 * function: func_021BD118
 * address: 0x021BD118
 * packet: pkt_ov210_021BD118
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021ED8 0x02021ED8 thumb
 *   func_021BC8B4 0x021BC8B4 thumb ov210
 *   func_021BCA84 0x021BCA84 thumb ov210
 *   func_021BE564 0x021BE564 thumb ov210
 *   func_021BF418 0x021BF418 thumb ov210
 *   func_021BC5B4 0x021BC5B4 thumb ov210
 *   func_021BCD30 0x021BCD30 thumb ov210
 *   func_021BFEAC 0x021BFEAC thumb ov210
 *   func_0207D534 0x0207D534 arm
 *   func_021BCE0C 0x021BCE0C thumb ov210
 *   func_021BC82C 0x021BC82C thumb ov210
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02021ED8(const char *);
extern void func_021BC8B4(int);
extern void func_021BCA84(u8 *);
extern void func_021BE564(u8 *);
extern u32 func_021BF418(u8 *);
extern void func_021BC5B4(u32);
extern void func_021BCD30(u8 *);
extern void func_021BFEAC(u8 *, int);
extern void func_0207D534(void *, int);
extern void func_021BCE0C(char *, int);
extern void func_021BC82C(u8 *, int, int);
int func_021BD118(u8 *p)
{
    if (func_02021ED8(*(char **)(p + 12)) != 0) return 3;
    func_021BC8B4(1);
    func_021BCA84(p);
    func_021BE564(p);
    func_021BC5B4(func_021BF418(p));
    func_021BCD30(p);
    if (p[0x2b9] == 255) {
        func_021BFEAC(p, 0);
        func_0207D534((void *)0x0400006c, 0);
        func_0207D534((void *)0x0400106c, 0);
        func_021BCE0C((char *)p, -8);
        func_021BC82C(p, 16, 0);
        return 4;
    } else {
        func_021BFEAC(p, p[0x2b9]);
        return 4;
    }
}
