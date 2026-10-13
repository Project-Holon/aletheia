/*
 * function: func_021D48F0
 * address: 0x021D48F0
 * packet: pkt_ov120_021D48F0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   func_02039ACC 0x02039ACC arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4864 0x021D4864 thumb ov120
 */
extern int func_0203CD98(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern int func_02039ACC(void);
extern void func_021D4244(int *p, int v, int a2);
typedef unsigned char  u8;
extern void func_021D4864(u8 *p);
void func_021D48F0(int *a)
{
    if (func_0203CD98() == 0) {
        func_021D4244(a, (int)((void (*)(int))func_021D4864), 0x31d);
        return;
    }
    if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && func_02039ACC() != 0)
        func_021D4244(a, (int)((void (*)(int))func_021D4864), 0x322);
}
