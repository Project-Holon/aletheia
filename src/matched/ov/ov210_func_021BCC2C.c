/*
 * function: func_021BCC2C
 * address: 0x021BCC2C
 * packet: pkt_ov210_021BCC2C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte alignment padding at 0x021BCCA6.
 * prototype: 02012BF8 caller sets r0/r1 only; legacy own C lists two unused extra parameters.
 * symbols:
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021BEDB8 0x021BEDB8 thumb ov210
 *   func_021BEE80 0x021BEE80 thumb ov210
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_02041B6C(u32);
extern int func_02012BF8(int, int);
extern void func_021BEDB8(int p, int i, int v);
extern void func_021BEE80(int p, int i, unsigned v);
void func_021BCC2C(char *p)
{
    func_02041090(1, *(u32 *)(p + 0x2bc), 0, 17, 32, 6);
    func_02041B6C(1);
    func_021BEDB8((int)p, 2, 15);
    func_021BEDB8((int)p, 3, 14);
    if (func_02012BF8(**(int **)p, 16) == 1)
        func_021BEDB8((int)p, 4, 22);
    else
        func_021BEDB8((int)p, 4, 21);
    func_021BEE80((int)p, 2, 1);
    func_021BEE80((int)p, 3, 1);
    func_021BEE80((int)p, 4, 1);
}
