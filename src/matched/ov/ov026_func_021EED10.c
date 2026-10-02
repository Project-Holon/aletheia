/*
 * function: func_021EED10
 * address: 0x021EED10
 * packet: pkt_ov026_021EED10
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 *   func_021A2160 0x021A2160 thumb ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021A25CC(u8 *);
extern void func_021A2160(u8 *, u32, int);

int func_021EED10(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 15, 3, -1);
    ((unsigned short *)p)[1] = 1;
    func_021A25CC(a);
    func_021A2160(a, 0, 0);
    return 1;
}
