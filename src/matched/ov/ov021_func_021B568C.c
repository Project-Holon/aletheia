/*
 * function: func_021B568C
 * address:  0x021B568C
 * packet:   pkt_ov021_021B568C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021BB990  0x021BB990  thumb  ov021
 *   ov56_id        0x00000038  data  a1
 *   g_021F4344     0x021F4344  data  ov056  a4
 *   g_021F4374     0x021F4374  data  ov056  a4
 *   g_021F438C     0x021F438C  data  ov056  a4
 *   g_021F435C     0x021F435C  data  ov056  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_0201210C();
extern int func_02188D24();
extern int func_02159B10();
extern void func_021BB990();
extern u8 ov56_id[];
extern u32 g_021F4344[];
extern u32 g_021F4374[];
extern u32 g_021F438C[];
extern u32 g_021F435C[];

int func_021B568C(int a0, int a1)
{
    int r4 = func_02188D24(func_0201210C(func_0215A5DC(a1)));

    switch (func_02159B10(a0, a1)) {
    case 0:
        break;
    case 1:
        func_021BB990(ov56_id, r4, g_021F4344);
        break;
    case 2:
        func_021BB990(ov56_id, r4, g_021F4374);
        break;
    case 3:
        func_021BB990(ov56_id, r4, g_021F438C);
        break;
    case 4:
        func_021BB990(ov56_id, r4, g_021F435C);
        break;
    }
    return 0;
}
