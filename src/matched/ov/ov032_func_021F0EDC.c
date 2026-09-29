/*
 * function: func_021F0EDC
 * address:  0x021F0EDC
 * packet:   pkt_ov032_021F0EDC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0EDC  0x021F0EDC  thumb
 *   func_021F0EA4  0x021F0EA4  thumb  ov032
 *   func_021F0ED0  0x021F0ED0  thumb  ov032
 *   func_02043B5C  0x02043B5C  arm
 *   func_020257D0  0x020257D0  thumb
 *   func_0204581C  0x0204581C  arm
 *   func_02031194  0x02031194  arm
 */

typedef unsigned char u8;

extern void func_021F0EA4(char *p, int a);
extern void func_021F0ED0(char *p, int a);
extern void func_02043B5C(int a, int b);
extern void func_020257D0(int a);
extern void func_0204581C(int a);
extern void func_02031194(int a);

void func_021F0EDC(char *p)
{
    int z = 0;

    func_021F0EA4(p, 0);
    func_021F0ED0(p, 0);
    func_02043B5C(*(int *)(p + 0x1c), 0);
    func_020257D0(*(int *)(p + 0x18));
    func_0204581C(*(int *)(p + 0x24));
    func_0204581C(*(int *)(p + 0x20));
    *(u8 *)(p + 1) = 0xff;
    *(u8 *)(p + 2) = z;
    *(u8 *)(p + 3) = z;
    if (*(int *)(p + 0x2c) != 0) {
        func_02031194(*(int *)(p + 0x2c));
        *(int *)(p + 0x2c) = z;
    }
    if (*(int *)(p + 0x30) != 0) {
        func_02031194(*(int *)(p + 0x30));
        *(int *)(p + 0x30) = 0;
    }
}
