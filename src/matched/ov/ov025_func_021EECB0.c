/*
 * function: func_021EECB0
 * address: 0x021EECB0
 * packet: pkt_ov025_021EECB0
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021EEEE0 0x021EEEE0 thumb ov025
 *   func_021A2160 0x021A2160 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 */
typedef unsigned char u8;
extern int *func_021A21B8(int *);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021EEEE0(int, int *);
extern void func_021A2160(u8 *, unsigned int, int);
extern void func_021A25CC(u8 *);
int func_021EECB0(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 3, 1, -1);
    *p = 10;
    func_021EEEE0((int)a, p);
    func_021A2160(a, 0, 0);
    func_021A25CC(a);
    return 1;
}
