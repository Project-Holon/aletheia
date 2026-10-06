/*
 * function: func_021EEC5C
 * address:  0x021EEC5C
 * packet:   pkt_ov026_021EEC5C
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEC5C 0x021EEC5C thumb ov026
 *   func_021EEE38 0x021EEE38 thumb ov026
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21F8 0x021A21F8 thumb ov021
 *   func_021A22E0 0x021A22E0 thumb ov021
 *   func_021A2254 0x021A2254 thumb ov021
 *   func_021A25BC 0x021A25BC thumb ov021
 *   func_021A2114 0x021A2114 thumb ov021
 *   func_021A2160 0x021A2160 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int *func_021A21B8(int *p);
extern void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void func_021A22E0(u32 *p, int a, int b, int c);
extern void func_021A2254(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
extern void func_021A25BC(unsigned char *o, int arg);
extern int func_021A2114(u32 a, int b, u32 c);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern u16 func_02014A10(u32 i);
extern void func_021EEE38(int a, int n, int idx);

int func_021EEC5C(int a, int b, u16 c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 2, 0, 2, 0, -3, 1, 1, (int)func_021EEE38);
    func_021A22E0((u32 *)a, 9, 0x7F80, b);
    func_021A2254((u8 *)a, (void (*)(u8 *, int,  u32))func_021EEE38, 0x14, 5, 1, c);
    func_021A25BC((unsigned char *)a, 0x690);
    func_021A2114(a, 0x3E, func_02014A10(6));
    func_021A2160((unsigned char *)a, 1, 0);
    return 1;
}
