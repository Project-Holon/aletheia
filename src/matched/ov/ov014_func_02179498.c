/*
 * function: func_02179498
 * address:  0x02179498
 * packet:   pkt_ov014_02179498
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The DWC copy of the NitroSDK demo wh.c's WH_Finalize (DWCi_MOV_WH_*),
 * returning BOOL and reading its state from the work block behind
 * g_021797A8: +0x1E70 system state, +0x1E74 connect mode, +0x1444 the
 * data-sharing info, +0x1E98 an error latch, +0x1EDF a byte flag.
 *
 * symbols:
 *   g_021797A8          0x021797A8  data   ov014  a4
 *   func_0217945C       0x0217945C  thumb  ov014
 *   func_021788FC       0x021788FC  thumb  ov014
 *   func_02178138       0x02178138  thumb  ov014
 *   func_02178C50       0x02178C50  thumb  ov014
 *   func_021784AC       0x021784AC  thumb  ov014
 *   WM_EndDataSharing   0x0209028C  arm
 */

typedef unsigned char u8;
typedef int BOOL;

extern u8 *g_021797A8;

extern void func_0217945C(void);
extern BOOL func_021788FC(void);
extern void func_02178138(int state);
extern BOOL func_02178C50(void);
extern BOOL func_021784AC(void);
extern int WM_EndDataSharing(void *info);

BOOL func_02179498(void)
{
    int state;

    if (g_021797A8 == 0 || (state = *(int *)(g_021797A8 + 0x1E70)) == 1)
        return 1;

    if (*(int *)(g_021797A8 + 0x1E98) != 0) {
        func_0217945C();
        return 1;
    }

    if (state == 3)
        return 0;

    if (state == 2) {
        if (!func_021788FC())
            func_0217945C();
        return 1;
    }

    if (g_021797A8[0x1EDF] != 0)
        return 1;

    if (state != 5 && state != 4) {
        func_02178138(3);
        func_0217945C();
        return 1;
    }

    func_02178138(3);

    switch (*(int *)(g_021797A8 + 0x1E74)) {
    case 5:
        if (WM_EndDataSharing(g_021797A8 + 0x1444) != 0) {
            func_0217945C();
            break;
        }
    case 1:
        if (!func_02178C50())
            func_0217945C();
        break;
    case 2:
    case 3:
        break;
    case 4:
        if (WM_EndDataSharing(g_021797A8 + 0x1444) != 0) {
            func_0217945C();
            break;
        }
    case 0:
        if (!func_021784AC())
            func_0217945C();
        break;
    }
    return 1;
}
