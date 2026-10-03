/*
 * function: func_021F7DD0
 * address: 0x021F7DD0
 * packet: pkt_ov135_021F7DD0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F7B9C 0x021F7B9C thumb ov135
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 */
typedef unsigned char u8;
extern int func_021F99F0(void *p);
extern void func_0201F7A8(void *p, unsigned kind);
extern int func_021F7B9C(u8 *p, int event);
extern void func_021F882C(u8 *dst, int i, int kind);
extern int func_021F886C(int x, int y, int which);
extern void func_021F81C8(void *a, void *b, void *c, void *d, int e, int f, int g, void *h);
int func_021F7DD0(u8 *p)
{
    unsigned result = func_021F99F0(*(void **)(p + 0xDE4));
    switch (result) {
    case 12: case (unsigned)-2:
        func_0201F7A8(*(void **)(p + 0xD40), 0);
        if (func_021F7B9C(p + 0xB50, *(int *)(*(u8 **)(p + 0xE00) + 0x20))) {
            *(unsigned *)(p + 0x28) = 0;
        } else {
            *(unsigned *)(p + 0x28) = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        func_021F882C(p + 0xB50, result, 0);
        *(unsigned *)(p + 0x28) = 13;
        result = func_021F886C(*(signed char *)(p + 0xB53), *(signed char *)(p + 0xB54), 0);
        func_021F81C8(*(void **)(p + 0xB6C), *(void **)(p + 0xB70), *(void **)(p + 0xB68), p + 0xD90, *(short *)(p + 0xB50), *(signed char *)(p + 0xB52), result, p + 0xFA0);
        break;
    }
    return 2;
}
