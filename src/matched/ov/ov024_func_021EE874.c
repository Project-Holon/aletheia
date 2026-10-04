/*
 * function: func_021EE874
 * address:  0x021EE874
 * packet:   pkt_ov024_021EE874
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EE874  0x021EE874  thumb  ov024
 *   func_021A23E8  0x021A23E8  thumb  ov021
 *   func_021A231C  0x021A231C  thumb  ov021
 *   func_021A23F4  0x021A23F4  thumb  ov021
 *   func_021A2120  0x021A2120  thumb  ov021
 */

typedef unsigned int   u32;
int func_021A23E8(int *p);
void func_021A231C(u32 *p, int x);
int func_021A23F4(int *p);
void func_021A2120(u32 *p, int x);

int func_021EE874(int a0, int a1)
{
    if (func_021A23E8((int *)a0)) {
        func_021A231C((u32 *)a0, a1);
    }
    if (func_021A23F4((int *)a0)) {
        func_021A2120((u32 *)a0, a1);
    }
    return 1;
}
