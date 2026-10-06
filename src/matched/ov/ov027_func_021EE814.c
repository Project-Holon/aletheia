/*
 * function: func_021EE814
 * address:  0x021EE814
 * packet:   pkt_ov027_021EE814
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A21B8  0x021A21B8  thumb  ov021
 *   func_021A21F8  0x021A21F8  thumb  ov021
 *   func_021A22E0  0x021A22E0  thumb  ov021
 *   func_021A2254  0x021A2254  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 *   func_021A2114  0x021A2114  thumb  ov021
 *   func_021EEA04  0x021EEA04  thumb  ov027
 */

typedef unsigned char  u8;
int *func_021A21B8(int *p);
void func_021A21F8(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void func_021A22E0(int a, int b, int c, int d);
void func_021A2254(int a, void (*b)(int, int, int), int c, int d, int e, int f);
void func_021A2160(unsigned char *o, unsigned int v, int i);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 func_02014A10(u32 i);
int func_021A2114(u32 a, int b, u32 c);
void func_021EEA04(int a, int b, int c);

int func_021EE814(int a, int b, int c)
{
    func_021A21B8((int *)a);
    func_021A21F8((u8 *)a, 1, 2, 1, 2, -2, 4, 1, (int)func_021EEA04);
    func_021A22E0(a, 8, 0x7f5e, b);
    func_021A2254(a, func_021EEA04, 24, 2, 2, c);
    func_021A2160((unsigned char *)a, 1, 0);
    func_021A2114(a, 0x3e, func_02014A10(3));
    return 1;
}
