/*
 * function: func_021DDC44
 * address: 0x021DDC44
 * packet: pkt_ov121_021DDC44
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * Unlabelled ARM follower of func_021DD9CC, referenced by its ABS32 pool
 * word at +0x25C: sub-screen blend callback writing DB_BLDALPHA
 * (0x04001052) as eva | evb << 8.
 */
typedef unsigned short u16;
void func_021DDC44(int a, int b)
{
    *(volatile u16 *)0x04001052 = a | (b << 8);
}
