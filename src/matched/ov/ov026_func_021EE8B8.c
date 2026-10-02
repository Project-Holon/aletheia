/*
 * function: func_021EE8B8
 * address: 0x021EE8B8
 * packet: pkt_ov026_021EE8B8
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 *   func_021A25CC 0x021A25CC thumb ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern void func_021A2228(u8 *, int, int, int, int);
extern void func_021A25CC(u8 *);

int func_021EE8B8(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 8, 4, -1);
    *p = 1;
    func_021A25CC(a);
    return 1;
}
