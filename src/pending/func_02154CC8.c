/*
 * function: func_02154CC8
 * address:  0x02154CC8
 * packet:   pkt_02154CA0
 * region:   ov008
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0203133C  0x0203133C  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned char u8;

extern int  func_0200FB24(void);
extern void func_0200FB38(void);
extern void func_0203133C(int x);
extern void func_020315D4(void *p);
extern void func_020306F0(int x);

int func_02154CC8(void *a0, int a1, char *a2, int *a3)
{
    if (*(int *)(a2 + 0x14) == 1) {
        if (func_0200FB24() != 0)
            func_0200FB38();
    }
    func_0203133C(*a3);
    func_020315D4(a0);
    func_020306F0(0x76);
    return 1;
}
