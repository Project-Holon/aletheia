/*
 * function: func_021F1704
 * address:  0x021F1704
 * packet:   pkt_ov032_021F1704
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1704 0x021F1704 thumb
 *   func_021F1218 0x021F1218 thumb
 *   func_021F0EDC 0x021F0EDC thumb
 *   func_02031194 0x02031194 arm
 */

typedef unsigned char u8;

extern void func_021F1218(u8 *e, short x, short y);
extern void func_021F0EDC(u8 *e);
extern void func_02031194(void *h);

void func_021F1704(void *h, char *t)
{
    u8 *e;

    switch (*(int *)t) {
    case 0:
        if (*(u8 *)(t + 0xd) != 0) {
            *(u8 *)(t + 0xd) = *(u8 *)(t + 0xd) - 1;
            return;
        }
        *(u8 *)(t + 0xf) = *(u8 *)(t + 0xf) + 1;
        if (*(u8 *)(t + 0xf) < *(u8 *)(t + 0xe)) {
            int x = *(int *)(t + 0x14) + *(int *)(t + 0x1c);
            int y = *(int *)(t + 0x18) + *(int *)(t + 0x20);
            *(int *)(t + 0x14) = x;
            *(int *)(t + 0x18) = y;
            func_021F1218(*(u8 **)(t + 8), (short)(x >> 12), (short)(y >> 12));
            return;
        }
        func_021F1218(*(u8 **)(t + 8), *(short *)(t + 0x10), *(short *)(t + 0x12));
        e = *(u8 **)(t + 8);
        if (e[2] == 0 || e[2] == 5) {
            *(int *)t = *(int *)t + 1;
            return;
        }
        break;
    case 1:
    default:
        e = *(u8 **)(t + 8);
        if (*(int *)(e + 0x2c) != 0)
            return;
        func_021F0EDC(e);
        break;
    }
    **(int **)(t + 0x24) = **(int **)(t + 0x24) - 1;
    func_02031194(h);
}
