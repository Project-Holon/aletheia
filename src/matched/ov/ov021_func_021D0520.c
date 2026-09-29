/*
 * function: func_021D0520
 * address:  0x021D0520
 * packet:   pkt_ov021_021D0520
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

extern int func_0216E1C4(u32 a, u16 *b);
extern void func_021AC154(u32 a);
extern void func_0216D88C(u32 a, Vec3 *v);
extern int func_02163E58(u32 m, Vec3 *pos, int *h);
extern void func_021AC1CC(u32 a, Vec3 *v);

void func_021D0520(u32 a, u8 *b)
{
    int h;
    Vec3 v;

    if (func_0216E1C4(*(u32 *)(b + 8), (u16 *)(b + 0x10)) == 0) {
        func_021AC154(a);
        return;
    }
    func_0216D88C(*(u32 *)(b + 8), &v);
    if (func_02163E58(*(u32 *)(b + 8), &v, &h) == 1) {
        v.y = h;
    }
    func_021AC1CC(a, &v);
}
