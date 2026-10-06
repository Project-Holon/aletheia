/*
 * function: func_02185814
 * address:  0x02185814
 * packet:   pkt_ov023_02185814
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203996C  0x0203996C  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02185354  0x02185354  thumb  ov023
 *   func_021857F4  0x021857F4  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 */

typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02185354(char *p);
extern void func_021857F4(char *p, int a, int b);
extern void func_02186444(char *p, u32 v);

int func_02185814(char *p, int a1)
{
    int z;
    z = 0;
    if (func_0203D3A8(func_0203996C(0xff), 0x2906, 0, 0)) {
        func_02186444(p, 0x12);
        func_021857F4(p, z, z);
        a1 = 2;
    }
    func_02185354(p);
    return a1;
}
