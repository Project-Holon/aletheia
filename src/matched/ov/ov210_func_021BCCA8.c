/*
 * function: func_021BCCA8
 * address: 0x021BCCA8
 * packet: pkt_ov210_021BCCA8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02012BF8 caller sets r0/r1 only; legacy own C lists two unused extra parameters.
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021BEDF0 0x021BEDF0 thumb ov210
 *   func_021BEDB8 0x021BEDB8 thumb ov210
 *   func_021BEE80 0x021BEE80 thumb ov210
 *   func_021BED1C 0x021BED1C thumb ov210
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02041B6C(u32);
extern int func_02012BF8(int, int);
extern void func_021BEDF0(u8 *, u32, u32);
extern void func_021BEDB8(void *, int, int);
extern void func_021BEE80(char *, int, int);
extern void func_021BED1C(char *);
void func_021BCCA8(char *p)
{
    func_021BEDF0((u8 *)p, 8, 0);
    func_02041300(1, 0, 0, 17, 32, 6, 0);
    func_02041B6C(1);
    func_021BEDB8(p, 2, 1);
    func_021BEDB8(p, 3, 0);
    if (func_02012BF8(**(int **)p, 16) == 1)
        func_021BEDB8(p, 4, 7);
    else
        func_021BEDB8(p, 4, 6);
    func_021BEE80(p, 2, 0);
    func_021BEE80(p, 3, 0);
    func_021BEE80(p, 4, 0);
    func_021BED1C(p);
}
