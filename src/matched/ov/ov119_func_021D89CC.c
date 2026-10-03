/*
 * function: func_021D89CC
 * address: 0x021D89CC
 * packet: pkt_ov119_021D89CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203C554 0x0203C554 arm
 */
extern void func_0203D7B0(int a0);
extern void func_0203D7BC(int a0);
typedef unsigned int   u32;
extern void func_0203C554(u32 a);

void func_021D89CC(char *p)
{
    func_0203D7B0(0);
    func_0203D7BC(0);
    func_0203C554(0);
    *(int *)(*(char **)(p + 8) + 8) = 3;
}
