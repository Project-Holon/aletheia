/*
 * function: func_0207524C
 * address:  0x207524C
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  0x020896AC has no witness outside this range: its only caller is this function
 *
 * Every concrete byte reproduces; the one site is a label-class refusal.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020751F4(int, int, int);
extern void func_020896AC(int, int);

void func_0207524C(int a, int b, int c, int d)
{
    func_020751F4(a, c, d);
    func_020896AC(a, a + b);
}
