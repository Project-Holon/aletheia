/*
 * function: func_021EF104
 * address: 0x021EF104
 * packet: pkt_ov026_021EF104
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021EF664 0x021EF664 thumb ov026
 *   func_021EF830 0x021EF830 thumb ov026
 */

typedef unsigned char u8;
typedef short s16;
extern int *func_021A21B8(int *);
extern int func_021A2248(u8 *, int);
extern void func_021EF664(int, s16 *, int, int);
extern void func_021EF830(int, s16 *);
int func_021EF104(u8 *a, int b, int c)
{
    s16 *p;
    p = (s16 *)func_021A21B8((int *)a);
    func_021A2248(a, c);
    func_021EF664((int)a, p, b, 0);
    func_021EF830((int)a, p);
    return 0;
}
