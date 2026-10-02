/*
 * function: func_021D42D8
 * address: 0x021D42D8
 * packet: pkt_ov120_021D42D8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D593C 0x021D593C thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5980 0x021D5980 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020355D8(int);
extern void func_020061E4(int);
extern void func_021D69F4(u8 *, void *, u32);
extern int func_021D593C(u8 *, int);
extern void func_021D4244(int, void (*)(u8 *), int);
extern void func_021D5980(u8 *);
int func_021D42D8(int n, u8 *p)
{
    *(int *)(p + 0x138) = n;
    func_020355D8(1);
    if (*(int *)(p + 0x184) == 1) {
        func_020061E4(0x551);
        return 1;
    }
    if (n == 0) {
        *(int *)(p + 0x15c) = 0;
        func_021D69F4(*(u8 **)(p + 0x3c), *(void **)(p + 0x34), 0);
        func_021D593C(p, *(int *)(p + 0x15c));
        func_021D4244((int)p, func_021D5980, 0x177);
    } else {
        *(int *)(p + 0x15c) = 1;
        func_021D69F4(*(u8 **)(p + 0x3c), *(void **)(p + 0x34), 1);
        func_021D593C(p, *(int *)(p + 0x15c));
        func_021D4244((int)p, func_021D5980, 0x17e);
    }
    return 1;
}
