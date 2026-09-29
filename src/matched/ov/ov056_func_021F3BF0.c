/*
 * function: func_021F3BF0
 * address:  0x021F3BF0
 * packet:   pkt_ov056_021F3BF0
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_0204784C  0x0204784C  arm
 *   func_020477A4  0x020477A4  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02047400(u32 a, u32 b, u32 c);
extern u32 func_02047564(u32 a, u32 b, u32 c);
extern u32 func_0204767C(u32 a, u32 *b, u32 c);
extern void func_0204784C(u32 h, u16 i, int *v);
extern void func_020477A4(u32 h, u16 i);

void func_021F3BF0(u32 *p)
{
    int i;
    int v;

    i = 0;
    p[4] = func_02047400(p[0], 0, p[0]);
    p[5] = func_02047564(p[4], p[1], 0);
    p[6] = func_02047564(p[4], p[2], 0);
    p[7] = func_0204767C(p[4], &p[5], 2);
    v = 0;
    for (; i < 2; i++) {
        func_0204784C(p[7], i, &v);
        func_020477A4(p[7], i);
    }
}
