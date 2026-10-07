/*
 * function: func_021EEA64
 * address:  0x021EEA64
 * packet:   pkt_021EEA64
 * region:   ov028
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A231C  0x021A231C  thumb  ov021
 *   func_021A2120  0x021A2120  thumb  ov021
 */

typedef unsigned int   u32;
void func_021A231C(u32 *p, int x);
void func_021A2120(u32 *p, int x);

int func_021EEA64(int a0, int a1)
{
    func_021A231C((u32 *)a0, a1);
    func_021A2120((u32 *)a0, a1);
    return 1;
}
