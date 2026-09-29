/*
 * function: func_021C5DB4
 * address:  0x021C5DB4
 * packet:   pkt_ov114_021C5DB4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_NdCancelAsync (libdwcnd.TWL.HYB.a dwc_nd.o)
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   func_021C666C  0x021C666C  arm  ov114
 *   g_021D3B84     0x021D3B84  data
 *   g_021D3B68     0x021D3B68  data
 */

typedef struct NdState {
    unsigned char pad0[0x14];
    int f14;
} NdState;

extern int func_02059F38(void);
extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern int func_021C666C(void);
extern char g_021D3B84[];
extern NdState g_021D3B68;

int func_021C5DB4(void)
{
    if (func_02059F38())
        return 0;
    func_02086028(g_021D3B84);
    if (g_021D3B68.f14 != 2) {
        OS_UnlockMutex(g_021D3B84);
        return 0;
    }
    OS_UnlockMutex(g_021D3B84);
    return func_021C666C() != 0;
}
