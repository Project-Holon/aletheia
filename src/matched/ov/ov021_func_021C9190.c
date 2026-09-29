/*
 * function: func_021C9190
 * address:  0x021C9190
 * packet:   pkt_ov021_021C9190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   func_020478B8  0x020478B8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct V3 { int v[3]; } V3;

extern int func_0216DA30(int);
extern void func_0216D88C(int, V3 *);
extern void func_021AC1CC(u32, V3 *);
extern void func_02047910(u32 h, u32 i, int v);
extern int func_020478B8(u32 h, u32 i, int v);

void func_021C9190(u32 a, u8 *b)
{
    V3 v;

    if (func_0216DA30(*(int *)(b + 0x10)) != 0) {
        func_0216D88C(*(int *)(b + 0x10), &v);
        *(V3 *)(b + 0x28) = v;
        func_021AC1CC(a, &v);
        *(int *)(b + 0x2c) -= 0x4000;
        *(int *)(b + 0x30) += 0x2800;
        if (b[0x14] == 0) {
            func_02047910(*(u32 *)(b + 0x18), 0, 0x1000);
        }
        if (b[0x15] == 1 && b[0x16] == 0) {
            if (func_020478B8(*(u32 *)(b + 0x18), 1, 0x1000) == 0) {
                b[0x16] = 1;
            }
        }
    }
}
