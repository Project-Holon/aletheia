/*
 * function: FATFSi_SendToPXI
 * address:  0x027040B4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020862F0  0x020862F0  arm twl a2
 *   func_02088610  0x02088610  arm twl a2
 */

typedef unsigned int u32;

extern void func_020862F0(u32, u32);
extern int func_02088610(u32, u32, u32);

void FATFSi_SendToPXI(u32 a0) {
    func_020862F0(a0, 0x800);
    while (func_02088610(0x14, a0 >> 5, 0) < 0) {
    }
}
