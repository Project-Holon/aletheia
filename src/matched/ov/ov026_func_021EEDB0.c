/*
 * function: func_021EEDB0
 * address: 0x021EEDB0
 * packet: pkt_ov026_021EEDB0
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 *   func_021EF9CC 0x021EF9CC thumb ov026
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *func_021A21B8(int *);
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
extern void func_021EF9CC(int);

int func_021EEDB0(u8 *a, int b)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A231C((u32 *)a, b);
    func_021A2120((u32 *)a, b);
    func_021EF9CC((int)(p + 3));
    return 1;
}
