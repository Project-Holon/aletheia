/*
 * function: WIH_SetBeaconGameInfo
 * address:  0x021795D4
 * packet:   pkt_ov014_021795D4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the state word (+0x1E70) of the work block behind
 * g_021797A8 is 4 or 5, forwards the arguments to the arm9 function at
 * 0x02090CD4 with (0, a, b, c, d, 1) and the halfword arguments truncated.
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_02090CD4  0x02090CD4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *g_021797A8;

extern void func_02090CD4(int a, int b, u16 c, int d, u16 e, int f);

void WIH_SetBeaconGameInfo(int a, int b, int c, int d)
{
    if (g_021797A8 != 0 && (unsigned)(*(int *)(g_021797A8 + 0x1E70) - 4) <= 1)
        func_02090CD4(0, a, (u16)b, c, (u16)d, 1);
}
